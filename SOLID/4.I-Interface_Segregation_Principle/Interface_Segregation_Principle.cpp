#include <iostream>

class NIDrive
{
public:
    virtual void drive() = 0;
    virtual void fly() = 0;
};

class NCar : public NIDrive
{
public:
    void drive() override
    {
        std::cout << "Неверный вариант: Машина всегда едет!" << std::endl;
    }
    void fly() override
    {
        std::cout << "Неверный вариант: Машина никогда не летает!" << std::endl;
    }
};

void not_true_main()
{
    NCar nc;
    nc.drive();
    nc.fly();
}

class IDrive
{
public:
    virtual void drive() = 0;
};

class IFly
{
public:
    virtual void fly() = 0;
};

class Plane : public IFly, public IDrive
{
public:
    void drive() override
    {
        std::cout << "Верный вариант: Самолёт может ехать при взлёте" << std::endl;
    }
    void fly() override
    {
        std::cout << "Верный вариант: Самолёт может летать в небе" << std::endl;
    }
};

class Car : public IDrive
{
public:
    void drive() override
    {
        std::cout << "Верный вариант: Машина может ехать" << std::endl;
    } 
};

void true_main()
{
    Plane p;
    Car c;

    p.drive();
    p.fly();

    c.drive();
}

int main()
{
    not_true_main();
    true_main();

    return 0;
}