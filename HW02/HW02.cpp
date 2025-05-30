#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class Animal
{
public:
    virtual void makeSound() = 0;

    virtual ~Animal()
    {
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "멍멍" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "야옹" << std::endl;
    }
};

class Cow : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "음머" << std::endl;
    }
};

class Zoo
{
private:
    std::vector<Animal*> animals;

public:
    void addAnimal(Animal* animal)
    {
        if (animal != nullptr)
            animals.push_back(animal);
    }

    void performActions()
    {
        for (auto animal : animals)
            if (animal != nullptr)
                animal->makeSound();
    }

    ~Zoo()
    {
        for (auto animal : animals)
            delete animal;
    }
};

Animal* createRandomAnimal()
{
    int random = rand() % 3;
    switch (random)
    {
    case 0:
        return new Dog();
    case 1:
        return new Cat();
    case 2:
        return new Cow();
    default:
        return nullptr;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Zoo zoo;
    for (int i = 0; i < 10; ++i)
        zoo.addAnimal(createRandomAnimal());
    zoo.performActions();
    return 0;
}
