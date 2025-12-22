
#include <iostream>


//Runtime Polymorphism :

class Animal
{
public:
    virtual void makeSound() = 0;  // Pure virtual
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();



    // Runtime decision - compiler doesn't know which makeSound() will be called
    animal1->makeSound();  // Calls Dog::makeSound()
    animal2->makeSound();  // Calls Cat::makeSound()

        //In Simple Terms : (Above two lines)
        // Could be Dog, Cat, etc.
        // ❓ Compiler: "I don't know what this will do!"
        // ✅ Runtime: "Ah, it's a Dog - call Woof!"

    // Even with same pointer type, different behaviors
    Animal* ptr;
    ptr = new Dog();
    ptr->makeSound();  // Woof

    ptr = new Cat();
    ptr->makeSound();  // Meow - SAME pointer, DIFFERENT behavior!

    delete animal1;
    delete animal2;
    delete ptr;

    return 0;
}


/*
//Compile Time :
(NOT COMPILE TIME POLYMORPHISM , JUST DIFFERENCE)

#include <iostream>

enum class AnimalType
{
    DOG, CAT
};

void makeSound(AnimalType type)
{
    switch(type)
    {
    case AnimalType::DOG:
        std::cout << "Woof! Woof!" << std::endl;
        break;
    case AnimalType::CAT:
        std::cout << "Meow! Meow!" << std::endl;
        break;
    }
}

int main()
{
    AnimalType type1 = AnimalType::DOG;
    AnimalType type2 = AnimalType::CAT;

    // Compile-time decision - compiler knows exactly which code will run
    makeSound(type1);  // Compiler knows this will print "Woof!"
    makeSound(type2);  // Compiler knows this will print "Meow!"

    //In Simple Terms :
    // ✅ Compiler: "I know this will call Woof!"
    // ✅ Runtime: "Just executing what compiler said"

    // Same variable, but behavior fixed at compile time
    AnimalType current;

    current = AnimalType::DOG;
    makeSound(current);  // Woof - compiler knows this

    current = AnimalType::CAT;
    makeSound(current);  // Meow - compiler knows this

    return 0;
}
*/

//Virtual: Decision happens when program runs (runtime)
//Enum: Decision happens when code compiles (compile-time)

//Virtual = "Wait until runtime to decide"
//Enum = "Decide everything at compile time"




