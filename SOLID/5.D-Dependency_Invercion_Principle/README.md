# 5. Принцип инверсии зависимостей (Dependency Inversion Principle, DIP)
__Суть:__
Зависимости должны строиться на абстракциях, а не на конкретных реализациях.

1. Модули верхнего уровня не должны зависеть от модулей нижнего уровня. Оба должны зависеть от абстракций.
2. Абстракции не должны зависеть от деталей. Детали должны зависеть от абстракций.
__Простыми словами:__
>Высокоуровневый код (бизнес-логика) не должен напрямую зависеть от низкоуровневого кода (конкретных реализаций, например, работы с базой данных, файловой системой или API).
>Вместо этого оба слоя должны зависеть от интерфейсов (абстракций).

# Неправильно:
```c++
class LightBulb {
public:
    void turnOn() {
        std::cout << "LightBulb: ON" << std::endl;
    }
};

class Switch {
private:
    LightBulb bulb;
public:
    void operate() {
        bulb.turnOn();
    }
};
```
__Проблема:__
```Switch``` жёстко зависит от ```LightBulb```. Если нужно управлять другим устройством, придётся менять класс.

# Правильно:
```c++
class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual ~ISwitchable() = default;
};

class LightBulb : public ISwitchable {
public:
    void turnOn() override {
        std::cout << "LightBulb: ON" << std::endl;
    }
};

class Switch {
private:
    ISwitchable& device;
public:
    Switch(ISwitchable& dev) : device(dev) {}
    void operate() {
        device.turnOn();
    }
};
```
__Исправление:__
Switch зависит от абстракции (ISwitchable), а не от конкретного устройства.