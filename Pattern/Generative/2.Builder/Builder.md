# 2. Строитель (Builder)
__Суть:__
Пошаговое создание сложного объекта с помощью одного и того же процесса.

## Ключевые компоненты шаблона проектирования «Строитель» в C++
* __Директор:__ Директор — это основной компонент шаблона проектирования «Строитель». Он отвечает за процесс создания программы. Он работает с «Строителем» над созданием объекта. Директор знает, какие шаги необходимо предпринять для создания объекта, но не знает подробностей реализации каждого шага.
* __Конструктор:__ Конструктор — это основной интерфейс или абстрактный класс, определяющий этапы создания объекта.
* __Concrete Builder:__ По сути, это классы, реализующие интерфейс Builder. Каждый Concrete Builder отвечает за создание конкретного варианта объекта.
* __Продукт:__ Продукт — это сложный объект, который мы хотим создать. В классе Product могут быть методы для доступа к этим компонентам или управления ими. Часто он состоит из нескольких частей или компонентов, которые создаются с помощью конструктора.

## Диаграмма паттерна Строителя
<figure>
    <img src ="/assets/images/Diagram_Builder.png" alt = "Builder">
</figure>

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