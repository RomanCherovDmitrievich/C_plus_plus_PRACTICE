# 7. State (Состояние)
__Суть:__
Позволяет объекту изменять поведение при изменении его внутреннего состояния.

## Пример
```c++
#include <iostream>

class State {
public:
    virtual void handle() = 0;
};

class ConcreteStateA : public State {
public:
    void handle() override { std::cout << "State A\n"; }
};

class ConcreteStateB : public State {
public:
    void handle() override { std::cout << "State B\n"; }
};

class Context {
    State* state;
public:
    Context(State* s) : state(s) {}
    void setState(State* s) { state = s; }
    void request() { state->handle(); }
};

int main() {
    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context(&stateA);
    context.request();  // State A

    context.setState(&stateB);
    context.request();  // State B

    return 0;
}
```
## Плюсы:
✅ Избавляет от множества if-else в коде.
✅ Упрощает добавление новых состояний.

## Минусы:
❌ Может усложнить код при малом числе состояний.

## де применяется?
1. Документы (черновик → модерация → опубликован).
2. Игровые персонажи (бег → прыжок → атака).