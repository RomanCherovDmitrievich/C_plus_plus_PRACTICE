# 2. Строитель (Builder)
__Суть:__
Пошаговое создание сложного объекта с помощью одного и того же процесса.

## Пример
```c++
class Pizza {
public:
    void setDough(const std::string& dough) { this->dough = dough; }
    void setSauce(const std::string& sauce) { this->sauce = sauce; }
    void show() const { std::cout << "Pizza with " << dough << " and " << sauce << "\n"; }

private:
    std::string dough;
    std::string sauce;
};

class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual Pizza* getPizza() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() { pizza = new Pizza(); }
    void buildDough() override { pizza->setDough("cross"); }
    void buildSauce() override { pizza->setSauce("mild"); }
    Pizza* getPizza() override { return pizza; }

private:
    Pizza* pizza;
};

// Директор управляет процессом сборки
class Cook {
public:
    void makePizza(PizzaBuilder* builder) {
        builder->buildDough();
        builder->buildSauce();
    }
};
```
## Плюсы:
✅ Позволяет создавать объекты пошагово.
✅ Изолирует сложную логику сборки.

## Минусы:
❌ Усложняет код из-за дополнительных классов.

## Когда применять?
1. Когда объект требует сложной инициализации.
2. Когда нужно собирать объекты с разными конфигурациями.