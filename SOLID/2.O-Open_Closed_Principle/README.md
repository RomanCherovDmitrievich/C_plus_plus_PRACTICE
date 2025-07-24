# 2. Принцип открытости/закрытости (Open/Closed Principle, OCP)
__Определение:__ Программные сущности должны быть открыты для расширения, но закрыты для модификации.

## Неправильно
Добавление нового типа фигуры требует изменения AreaCalculator.
```c++
class Rectangle {
public:
    double width, height;
};

class Circle {
public:
    double radius;
};

class AreaCalculator {
public:
    double calculate(Rectangle r) { return r.width * r.height; }
    double calculate(Circle c) { return 3.14 * c.radius * c.radius; }
};
```
__Ошибка:__ При добавлении Triangle придётся изменять класс!

## Правильно
Использование абстракции (Shape) и полиморфизма.

```c++
class Shape {
public:
    virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
    double width, height;
    double area() const override { return width * height; }
};

class Circle : public Shape {
public:
    double radius;
    double area() const override { return 3.14 * radius * radius; }
};

class AreaCalculator {
public:
    double calculate(const Shape& shape) {
        return shape.area(); // Работает для любых наследников Shape
    }
};
```
__Плюс:__ Новые фигуры добавляются без изменения AreaCalculator.