#include <iostream>

class IBlacksmith
{
public:
    virtual void create() = 0;
};

class BlacksmithOfSword : public IBlacksmith
{
public:
    void create() override
    {
        std::cout << "Добавляем палку и железо" << std::endl;
    }
};

class BlacksmithOfBow : public IBlacksmith
{
public:
    void create() override
    {
        std::cout << "Добавляем палку и нить" << std::endl;
    }
};

class IArsenal
{
public:
    virtual void give_arsenal() = 0;
};

class Sword : public IArsenal
{
private:
    IBlacksmith& blacksmith;
public:
    Sword (IBlacksmith& b) : blacksmith(b) {}
    void give_arsenal()
    {
        blacksmith.create();
        std::cout << "Меч готов. " << std::endl;
    }
};

class Bow : public IArsenal
{
private:
    IBlacksmith& blacksmith;
public:
    Bow(IBlacksmith& b) : blacksmith(b) {}
    void give_arsenal()
    {
        blacksmith.create();
        std::cout << "Лук готов. " << std::endl;
    }
};

int main()
{
    BlacksmithOfBow blacksmith_of_bow;
    BlacksmithOfSword blacksmith_of_sword;

    Sword sword(blacksmith_of_sword);
    Bow bow(blacksmith_of_bow);

    sword.give_arsenal();
    std::cout << std::endl;
    bow.give_arsenal();
}