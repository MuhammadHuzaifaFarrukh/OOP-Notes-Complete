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
Design Patterns: Patterns like Factory, Adapter, Observer, and Strategy are specifically engineered to decouple components.
*/

// Example :
/*
You go to a fast-food counter and order a "Cheeseburger". You don't care how the kitchen grills the beef, toasts the bun, or slices the cheese—you just want the completed burger handed to you.
The Problem Without a Factory (High Coupling)
If the customer (main()) has to manually assemble the burger using new, the customer is tightly coupled to every single burger recipe.
Low Coupling : Instead, you delegate object creation to a dedicated Factory. You ask for what you want, and the Factory handles the creation logic.
*/

// 1. Common Product Interface
class Burger
{
public:
    virtual ~Burger() = default;
    virtual void prepare() = 0;
};

// 2. Concrete Products
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

// 3. THE FACTORY
class BurgerFactory
{
public:
    // Returns a pointer to the abstract interface 'Burger'
    static Burger *createBurger(const string &type)
    {
        if (type == "cheese")
        {
            return new Cheeseburger();
        }
        else if (type == "veggie")
        {
            return new VeggieBurger();
        }
        return nullptr;
    }
};

// 4. Client Code
int main()
{
    Burger *order1 = BurgerFactory::createBurger("cheese");
    if (order1 != nullptr)
    {
        order1->prepare();
        delete order1;
    }

    Burger *order2 = BurgerFactory::createBurger("veggie");
    if (order2 != nullptr)
    {
        order2->prepare();
        delete order2;
    }

    return 0;
}