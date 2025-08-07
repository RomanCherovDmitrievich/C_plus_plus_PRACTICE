# 1. Абстрактная фабрика (Abstract Factory)
__Суть:__
Создание семейств связанных объектов без указания их конкретных классов.

Простыми словами, __Абстрактная фабрика__ предоставляет интерфейс для создания семейств взаимосвязанных объектов, но не ___специфицирует конкретных классов__.
Предназначен для создания семейств объектов.
И с фабриками и с продуктами ы работаем на уроне интерфейса.

## пример
```c++
// Абстрактные продукты
class Button {
public:
    virtual void render() = 0;
};

class Checkbox {
public:
    virtual void render() = 0;
};

// Конкретные продукты для Windows
class WinButton : public Button {
    void render() override { std::cout << "Windows Button\n"; }
};

class WinCheckbox : public Checkbox {
    void render() override { std::cout << "Windows Checkbox\n"; }
};

// Абстрактная фабрика
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};

// Конкретная фабрика для Windows
class WinFactory : public GUIFactory {
public:
    Button* createButton() override { return new WinButton(); }
    Checkbox* createCheckbox() override { return new WinCheckbox(); }
};
```
## Плюсы:
✅ Позволяет создавать совместимые объекты.
✅ Изолирует конкретные классы от клиентского кода.

## Минусы:
❌ Сложность добавления новых продуктов (нужно менять все фабрики).

## Когда применять?
1. Когда система должна быть независимой от способа создания объектов.
2. Когда нужно создавать семейства связанных объектов.