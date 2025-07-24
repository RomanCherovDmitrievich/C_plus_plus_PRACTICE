#include <iostream>

class Car
{
public:
    void set_color(std::string _color)
    {
        color = _color;
    }
    void set_speed(int _speed)
    {
        speed = _speed;
    }
    void set_VIN(int _VIN)
    {
        VIN = _VIN;
    }
    void info()
    {
        std::cout << "Цвет машины: " << color << ", её максимальная скорость - " << speed << ", её VIN - " << VIN << std::endl;
    }

protected: // Виден для BMW(наследника)
    int VIN;
private:
    std::string color;
    int speed;
    
};

class BMW : public Car
{
public:
    void set_car_name(std::string _car_name)
    {
        car_name = _car_name;
    }
    void set_car_number(int _car_number)
    {
        car_number = _car_number;
    }

    void BMW_info()
    {
        std::cout << "Модель машины: BMW " << car_name << ", её номер - " << car_number << ", её VIN - " << VIN << std::endl;
    }

private:
    std::string car_name;
    int car_number;

};

int main()
{
    BMW car;
    car.set_car_name("X5");
    car.set_car_number(524);
    car.set_color("Black");
    car.set_speed(200);
    car.set_VIN(12345689);
    car.BMW_info();
    car.info();

    return 0;
}