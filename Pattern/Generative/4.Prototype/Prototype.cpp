#include <iostream>

class Arsenal
{
public:
    virtual Arsenal* info() const = 0;
    virtual void create() const = 0;
    ~Arsenal() = default;
};

class Sword : public Arsenal
{
private:
    const std::string type_sword;
public:
    Sword(const std::string _type_sword) : type_sword(_type_sword) {}
    Arsenal* info() const override
    {
        return new Sword(*this);
    }
    void create() const override
    {
        std::cout << type_sword << " меч создан." << std::endl;
    }
    ~Sword() {}
};

class Bow : public Arsenal
{
private:
    std::string type_bow;
public:
    Bow(std::string _type_bow) : type_bow(_type_bow) {}
    Arsenal* info() const override
    {
        return new Bow(*this);
    }
    void create() const override
    {
        std::cout << type_bow << " меч создан." << std::endl;
    }
    ~Bow() {}
};

int main()
{
    const std::string type_sword = "Русский";
    Sword swordPrototype(type_sword);

    const std::string type_bow = "Японский";
    Bow bowPrototype(type_bow);

    Arsenal* sword = swordPrototype.info();
    Arsenal* bow = bowPrototype.info();

    sword->create();
    bow->create();

    return 0;
}