#include <iostream>

class IAnimal // Интерфейс класса животные
{
public:
    virtual ~IAnimal() = default;
    virtual void info(const std::string& animal) = 0;
    virtual std::string sound() = 0;
    virtual int value() = 0;
};

class Dog : public IAnimal
{
public:
    void info(const std::string& animal) override
    {
        std::cout << "Это животное - " << animal << std::endl;
    }
    std::string sound() override
    {
        return "Gav! Gav!";
    }
    int value() override
    {
        return 12;
    }
};

class Cat : public IAnimal
{
    void info(const std::string& animal) override
    {
        std::cout << "Это животное - " << animal << std::endl;;
    }
    std::string sound() override
    {
        return "Mia! Mia!";
    }
    int value() override
    {
        return 5;
    }
};

int main()
{
    IAnimal* mycat = new Cat();
    IAnimal* mydog = new Dog();

    mycat->info("Кошка");
    std::cout << "Кошка издаёт: " << mycat->sound() << std::endl;
    std::cout << "Количество в магазине: " << mycat->value() << std::endl;

    mydog->info("Собака");
    std::cout << "Собака издаёт: " << mydog->sound() << std::endl;
    std::cout << "Количество в магазине: " << mydog->value() << std::endl;

    return 0;
}