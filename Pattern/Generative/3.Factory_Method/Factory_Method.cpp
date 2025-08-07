#include <iostream>

// Абстрактный класс продукта 
class IArsenal
{
public:
    virtual void create() const = 0;
    virtual ~IArsenal() = default;
};

class Sword : public IArsenal
{
public:
    void create() const override
    {
        std::cout << "Меч создан." << std::endl;
    }
    ~Sword() {}
};

class Bow : public IArsenal
{
    void create() const override
    {
        std::cout << "Лук создан." << std::endl;
    }
    ~Bow() {}
};

class ArsenalFactory
{
public:
    virtual IArsenal* createArsenal() = 0;
    virtual ~ArsenalFactory() = default;
};

class SwordFactory : public ArsenalFactory
{
public:
    IArsenal* createArsenal() override
    {
        return new Sword;
    }
    ~SwordFactory() {}
};

class BowFactory : public ArsenalFactory
{
    IArsenal* createArsenal() override
    {
        return new Bow;
    }
    ~BowFactory() {}
};

int main()
{
    ArsenalFactory* swordFactory = new SwordFactory();
    ArsenalFactory* bowFactory = new BowFactory();

    IArsenal* sword = swordFactory->createArsenal();
    IArsenal* bow = bowFactory->createArsenal();

    sword->create();
    bow->create();

    delete swordFactory;
    delete bowFactory;
    delete sword;
    delete bow;

    return 0;
}

