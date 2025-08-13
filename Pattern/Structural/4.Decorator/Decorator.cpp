#include <iostream>

class IArsenal
{
public:
    virtual std::string create() const = 0;
    virtual double coast() const  = 0;
};

class Sword : public IArsenal
{
public:
    std::string create() const override
    {
        return "Обычный меч";
    }
    double coast() const override
    {
        return 15.9;
    }
};

class Bow : public IArsenal
{
public:
    std::string create() const override
    {
        return "Обычный лук";
    }
    double coast() const override
    {
        return 10.2;
    }
};

class IEnchantment : public IArsenal
{
protected:
    IArsenal* arsenal;

public:
    IEnchantment(IArsenal* arsenal) : arsenal(arsenal) {}
    std::string create() const override
    {
        return arsenal->create();
    } 
    double coast() const override
    {
        return arsenal->coast();
    }
};

class StrangeEnchantment : public IEnchantment
{
public:
    StrangeEnchantment(IArsenal* arsenal) : IEnchantment(arsenal) {}
    std::string create() const override
    {
        return arsenal->create() + ", зачарован на силу";
    }
    double coast() const override
    {
        return arsenal->coast() + 20.03;
    }
};

class LightnessEnchantment : public IEnchantment
{
    public:
    LightnessEnchantment(IArsenal* arsenal) : IEnchantment(arsenal) {}
    std::string create() const override
    {
        return arsenal->create() + ", зачарован на лёгкость";
    }
    double coast() const override
    {
        return arsenal->coast() + 43.03;
    }
};

int main()
{
    IArsenal* arsenal = new Sword();
    std::cout << "1-е орудие: " <<  arsenal->create() << " стоит " << arsenal->coast() << std::endl; 

    arsenal = new Bow();
    std::cout << "2-е орудие: " <<  arsenal->create() << " стоит " << arsenal->coast() << std::endl; 

    arsenal = new Sword();
    arsenal = new StrangeEnchantment(arsenal);
    std::cout << "3-е орудие: " <<  arsenal->create() << " стоит " << arsenal->coast() << std::endl; 

    arsenal = new Bow();
    arsenal = new LightnessEnchantment(arsenal);
    std::cout << "4-е орудие: " <<  arsenal->create() << " стоит " << arsenal->coast() << std::endl; 

    return 0;
}
