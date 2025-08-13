#include <iostream>

class Engine
{
public:
    void start()
    {
        std::cout << "Двигатель включен" << std::endl;
    }
    void stop()
    {
        std::cout << "Двигатель выключен" << std::endl;
    }
};

class Light
{
public:
    void lightOn()
    {
        std::cout << "Свет включен" << std::endl;
    }
    void lightOff()
    {
        std::cout << "Свет выключен" << std::endl;
    }
};

class Enduro
{
private:
    Engine* engine;
    Light* light;

public:
    void startEnduro()
    {
        engine->start();
        light->lightOn();
        std::cout << "Эндуро включён" << std::endl;
    }
    void stopEnduro()
    {
        engine->stop();
        light->lightOff();
        std::cout << "Эндуро выключен" << std::endl;
    }
};

int main()
{
    Enduro* enduro = new Enduro();
    enduro->startEnduro();

    std::cout << std::endl << "Покатушки ..." << std::endl << std::endl;

    enduro->stopEnduro();

    return 0;
}