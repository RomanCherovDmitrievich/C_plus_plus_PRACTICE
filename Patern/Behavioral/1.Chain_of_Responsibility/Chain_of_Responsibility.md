# 1. Chain of Responsibility (Цепочка обязанностей)
__Суть:__
Позволяет передавать запросы последовательно по цепочке обработчиков. Каждый обработчик решает, обработать запрос или передать дальше.

## Пример
```c++
#include <iostream>
#include <string>

class Handler {
protected:
    Handler* next;
public:
    Handler() : next(nullptr) {}
    void setNext(Handler* handler) { next = handler; }
    virtual void handleRequest(const std::string& request) = 0;
};

class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "Handler A: Processing request '" << request << "'\n";
        } else if (next) {
            next->handleRequest(request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "Handler B: Processing request '" << request << "'\n";
        } else if (next) {
            next->handleRequest(request);
        }
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;
    handlerA.setNext(&handlerB);

    handlerA.handleRequest("A");  // Обработает HandlerA
    handlerA.handleRequest("B");  // Обработает HandlerB
    handlerA.handleRequest("C");  // Не обработает никто
    return 0;
}
```
## Плюсы:
✅ Уменьшает зависимость между отправителем и получателем.
✅ Позволяет динамически менять цепочку.

## Минусы:
❌ Запрос может остаться необработанным.
❌ Сложность отладки из-за множества обработчиков.

## Где применяется?
1. Логирование (разные уровни логов).
2. Обработка событий в GUI (например, кнопка → диалог → главное окно).
3. Фильтрация запросов (например, аутентификация → авторизация → валидация).