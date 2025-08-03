#include <iostream>
#include <cassert>

// Базовый класс: Прямоугольник
class Not_Rectangle {
protected:
    int width;
    int height;
public:
    // Установка ширины и высоты
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }

    // Вычисление площади
    int getArea() const { return width * height; }
};

// Производный класс: Квадрат
class Not_Square : public Not_Rectangle {
public:
    // Переопределяем методы, нарушая контракт Rectangle!
    void setWidth(int w) override { 
        width = w;
        height = w; // В квадрате ширина == высота
    }
    void setHeight(int h) override {
        width = h;
        height = h;
    }
};

// Функция, которая работает с Rectangle
void testRectangle(Not_Rectangle& rect) {
    rect.setWidth(5);
    rect.setHeight(4);
    
    // Ожидаем площадь = 20 (5 * 4)
    std::cout << "Ожидаемая площадь: 20, есть: " << rect.getArea() << std::endl;
    assert(rect.getArea() == 20); // Упадёт, если передать Square!
}

void not_true_main() {
    Not_Rectangle rect;
    Not_Square square;

    testRectangle(rect); // OK: площадь = 20
    testRectangle(square); // Ошибка: площадь = 16 (4 * 4) вместо 20!
}

// Абстрактный класс "Фигура"
class Shape {
public:
    virtual int getArea() const = 0;
};

// Прямоугольник
class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() const override { return width * height; }
};

// Квадрат
class Square : public Shape {
private:
    int side;
public:
    Square(int s) : side(s) {}
    int getArea() const override { return side * side; }
};

// Функция работает с любой фигурой
void printArea(const Shape& shape) {
    std::cout << "Площадь: " << shape.getArea() << std::endl;
}

void true_main() 
{
    Rectangle rect(5, 4);
    Square square(4);

    printArea(rect);   // Area: 20
    printArea(square); // Area: 16
}

int main()
{
    not_true_main();
    true_main();

    return 0;
}