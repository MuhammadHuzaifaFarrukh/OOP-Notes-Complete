#include <iostream>
#include <string>

using namespace std;

// FACTORY METHOD :
//  A Factory Method is a design pattern that focuses on decoupling the process of object creation from the code that uses the object.
//  It provides an interface (usually a class) for creating an object, but allows subclasses to decide which class to instantiate.
//  The goal is to let a class defer the instantiation logic to its children.

/*
Factory Pattern (Creational LLD Pattern)
LLD Focus: Used when designing class structures (e.g., designing a Parking Lot system where a VehicleFactory creates Car, Bike, or Truck objects based on input).
Goal: Ensures open-closed principle (adding a new vehicle type doesn't break existing creation code).
Relies on Dynamic Polymorphism.
Design Patterns: Patterns like Factory, Adapter, Observer, and Strategy are specifically engineered to decouple components.
*/

// Here we use the Factory Method Design , via the virutal function instead of static method.
// Contrast :
/*
In Static Methods :
Fewer classes: We don't need to create a whole class hierarchy of creators (Restaurant, CheeseBurgerRestaurant, VeggieBurgerRestaurant). We just write one class with one static function.
No object instantiations: We call BurgerFactory::createBurger("cheese") directly without needing to new a factory instance first.

In Virtual Functions:
Our static method breaks down when our creation logic needs to be customized or swapped at runtime without changing our core ordering process.
Imagine our burger franchise where different restaurant branches specialize in making different types of burgers, but every branch follows our exact same 3-step order workflow (Make->Prepare->Cleanup) .
Instead of writing a static factory with hardcoded string checks, we create specialized restaurant subclasses:
CheeseBurgerRestaurant: Specializes in making Cheeseburgers (Beef Patty + Cheese).
VeggieBurgerRestaurant: Specializes in making VeggieBurgers (Beans Patty + Lettuce).
When we call orderBurger(), our base Restaurant doesn't care which specific burger is being cooked—polymorphism automatically triggers the correct creation method for that restaurant:
Restaurant* cheeseStore = new CheeseBurgerRestaurant();
Restaurant* veggieStore = new VeggieBurgerRestaurant();
cheeseStore->orderBurger(); // Automatically creates & prepares a Cheeseburger!
veggieStore->orderBurger(); // Automatically creates & prepares a VeggieBurger!
We can even put here the customized things like adding lettuce , tomatoes , specific sauces in these burgers or not right in the createBurger() function instead of doing so much in a messy if-else code.

With the static factory, we end up with messy nested if-else blocks.
With the GoF Factory Method (non-static), we keep it clean using polymorphism.
Static functions are hardwired i.e we cannot easily mock or override a static method during unit testing.
With virtual functions, we can pass a MockRestaurant into our tests to inspect object creation.

*/

// Abstract Interface => Concrete Interface (Products here ) => Abstract Factory => Concrete Factory
class Burger
{
public:
    virtual ~Burger() = default;
    virtual void prepare() = 0;
};

class Cheeseburger : public Burger
{
public:
    void prepare() override
    {
        cout << "Adding Beef Patty, Cheese, and Buns!\n";
    }
};

class VeggieBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Adding Beans Patty, Lettuce, and Buns!\n";
    }
};

// Abstract Factory
class Restaurant
{
public:
    virtual ~Restaurant() = default;

    // The Factory Method (VIRTUAL, NOT STATIC)
    virtual Burger *createBurger() = 0;

    void orderBurger()
    {
        Burger *burger = createBurger();

        if (burger != nullptr)
        {
            burger->prepare();

            delete burger;
            burger = nullptr;
        }
    }
};

// Concrete Creator A   (Concrete Factory)
class CheeseBurgerRestaurant : public Restaurant
{
public:
    Burger *createBurger() override
    {
        // Add any customized logic or things (patty/sauces etc) right here while making the burger.
        // You can decide to add how much cheese quantity or anything else.
        // Doing in if-else may confuse others when seeing so much code.
        return new Cheeseburger();
    }
};

// Concrete Creator B
class VeggieBurgerRestaurant : public Restaurant
{
public:
    Burger *createBurger() override
    {
        // Add any customized logic or things (patty/sauces etc) right here while making the burger.
        // You can decide to add how much cheese quantity or anything else.
        // Doing in if-else may confuse others when seeing so much code.
        return new VeggieBurger();
    }
};

/*
In Static Factory, we must open the BurgerFactory class and modify the existing if-else block.
If 10 developers are adding 10 different meals, they are all modifying the exact same file, causing merge conflicts and risking bugs in already-working code.

Here we just create a new ChickenBurgerRestaurant class in a brand new file.
We never touch, recompile, or risk breaking the existing Restaurant or CheeseBurgerRestaurant classes.
Existing code is completely safe.
*/

int main()
{
    // 1. Create restaurant objects
    Restaurant *cheeseRest = new CheeseBurgerRestaurant();
    Restaurant *veggieRest = new VeggieBurgerRestaurant();

    // 2. Order burgers (orderBurger internally handles creating & deleting the Burger*)
    cheeseRest->orderBurger();
    veggieRest->orderBurger();

    delete cheeseRest;
    delete veggieRest;

    return 0;
}