# 4. Прототип (Prototype)
__Суть:__
Создание новых объектов путём копирования существующих (клонов).

## Пример
```c++
class Shape {
public:
    virtual Shape* clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    Circle(int r) : radius(r) {}
    Shape* clone() const override { return new Circle(*this); }
    void draw() const override { std::cout << "Drawing Circle (r=" << radius << ")\n"; }

private:
    int radius;
};
```
## Плюсы:
✅ Уменьшает количество подклассов.
✅ Ускоряет создание объектов.

## Минусы:
❌ Сложно клонировать объекты с циклическими ссылками.

## Когда применять?
1. Когда создание объекта дороже, чем копирование.