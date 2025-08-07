# 4. Mediator (Посредник)
__Суть:__
Уменьшает связанность множества классов, перенося логику взаимодействия в отдельный класс-посредник.

## Пример
```c++
#include <iostream>
#include <string>

class Mediator;

class Colleague {
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* m) : mediator(m) {}
};

class Mediator {
public:
    virtual void notify(Colleague* sender, const std::string& event) = 0;
};

class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* m) : Colleague(m) {}
    void doSomething() {
        std::cout << "ColleagueA triggers event.\n";
        mediator->notify(this, "A");
    }
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* m) : Colleague(m) {}
    void react() { std::cout << "ColleagueB reacts.\n"; }
};

class ConcreteMediator : public Mediator {
    ConcreteColleagueA* colleagueA;
    ConcreteColleagueB* colleagueB;
public:
    void setColleagues(ConcreteColleagueA* a, ConcreteColleagueB* b) {
        colleagueA = a;
        colleagueB = b;
    }
    void notify(Colleague* sender, const std::string& event) override {
        if (event == "A") colleagueB->react();
    }
};

int main() {
    ConcreteMediator mediator;
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);
    mediator.setColleagues(&colleagueA, &colleagueB);

    colleagueA.doSomething();  // ColleagueB reacts.
    return 0;
}
```

## Плюсы:
✅ Уменьшает связанность компонентов.
✅ Упрощает взаимодействие множества объектов.

## Минусы:
❌ Посредник может превратиться в "божественный объект".

## де применяется?
1. Чат-боты (обработка сообщений).
2. UI-фреймворки (взаимодействие виджетов).