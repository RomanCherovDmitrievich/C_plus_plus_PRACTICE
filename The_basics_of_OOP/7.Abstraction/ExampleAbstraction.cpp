#include <iostream>

// Абстрактный класс (есть чисто виртуальный метод)
class Shape {
public:
    virtual double area() const = 0; // Чисто виртуальная функция
    virtual void draw() const {      // Виртуальная функция с реализацией
        std::cout << "Рисование фигуры..." << std::endl;
    }
};

// Конкретный класс-наследник
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {} // Конструктор класса
    double area() const override { // Обязательная реализация
        return 3.14 * radius * radius;
    }
    void draw() const override {   // Переопределение (не обязательно)
        std::cout << "Рисование окружности с радиусом " << radius << std::endl;
    }
};

int main() {
    Circle circle(5.0);
    std::cout << "Область: " << circle.area() << std::endl; 
    circle.draw();
    return 0;
}