#include <iostream>

class Engine {
public:
    void start() { std::cout << "Двигатель работает" << std::endl; }
};

class Car {
private:
    Engine engine; // Композиция
public:
    void startCar() 
    { 
        engine.start(); 
    }
    void info()
    {
        std::cout << "Машина заведена." << std::endl;
    }
};

int main()
{

Car car;
car.info();
car.startCar();

return 0;
}