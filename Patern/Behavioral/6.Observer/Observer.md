# 6. Observer (Наблюдатель)
__Суть:__
Определяет зависимость "один-ко-многим" между объектами: при изменении состояния одного объекта все зависящие от него оповещаются.

## Пример
```c++
#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void detach(Observer* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify(const std::string& message) {
        for (auto obs : observers) obs->update(message);
    }
};

class ConcreteObserver : public Observer {
    std::string name;
public:
    ConcreteObserver(const std::string& n) : name(n) {}
    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver obs1("Observer 1");
    ConcreteObserver obs2("Observer 2");

    subject.attach(&obs1);
    subject.attach(&obs2);

    subject.notify("Hello, observers!");  // Оба получат сообщение

    subject.detach(&obs1);
    subject.notify("Observer 1 detached");  // Только obs2 получит

    return 0;
}
```

## Плюсы:
✅ Гибкая подписка/отписка наблюдателей.
✅ Минимальная связанность между субъектом и наблюдателями.

## Минусы:
❌ Наблюдатели могут получать оповещения в случайном порядке.

## Где применяется?
1. UI (кнопки → обработчики событий).
2. Рассылка уведомлений.
3. Модель MVC (обновление View при изменении Model).