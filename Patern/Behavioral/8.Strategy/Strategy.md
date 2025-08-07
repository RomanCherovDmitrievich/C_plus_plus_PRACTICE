# 8. Strategy (Стратегия)
__Суть:__
Определяет семейство алгоритмов, инкапсулирует каждый из них и делает их взаимозаменяемыми.

## Пример
```c++
#include <iostream>

class Strategy {
public:
    virtual void execute() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() override { std::cout << "Strategy A\n"; }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override { std::cout << "Strategy B\n"; }
};

class Context {
    Strategy* strategy;
public:
    Context(Strategy* s) : strategy(s) {}
    void setStrategy(Strategy* s) { strategy = s; }
    void executeStrategy() { strategy->execute(); }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);
    context.executeStrategy();  // Strategy A

    context.setStrategy(&strategyB);
    context.executeStrategy();  // Strategy B

    return 0;
}
```
## Плюсы:
✅ Легко добавлять новые алгоритмы.
✅ Избавляет от условных операторов.

## Минусы:
❌ Клиент должен знать о разных стратегиях.

## Где применяется?
1. Сортировка (QuickSort, MergeSort).
2. Оплата (CreditCard, PayPal).