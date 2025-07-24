#include <iostream>

class NBike 
{
public:
    int tire;
};

class NCar 
{
public:
    int tire;
};

class Not_true_Info 
{
public:
    void info(NBike& b) 
    { 
        std::cout << "Из неверного варианта: У мотоцикла " << b.tire << " колеса" << std::endl;
    }
    void info(NCar& c) 
    { 
        std::cout << "Из неверного варианта: У машины " << c.tire << " колеса" << std::endl;
    }
};

void not_true_main()
{
    Not_true_Info nti;
    NBike nb;
    NCar nc;

    nb.tire = 2;
    nc.tire = 4;

    nti.info(nb);
    nti.info(nc);

}


class Transport
{
public:
    virtual void info() = 0;
};

class Bike : public Transport
{
public:
    int tire;
    void info() override
    {
        std::cout << "Из верного варианта: У мотоцикла " << tire << " колеса" << std::endl;
    }
};

class Car : public Transport
{
public:
    int tire;
    void info() override
    {
        std::cout << "Из верного варианта: У машины " << tire << " колеса" << std::endl;
    }
};

class True_Info
{
public:
    void info(Transport& tr)
    {
        tr.info();
    }
};

void true_main()
{
    Bike b;
    Car c;
    True_Info ti;

    b.tire = 2;
    c.tire = 4;

    ti.info(b);
    ti.info(c);
}

int main()
{
    not_true_main();
    true_main();

    return 0;
}