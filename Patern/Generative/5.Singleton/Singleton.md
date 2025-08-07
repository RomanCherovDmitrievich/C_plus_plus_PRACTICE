# 5. Одиночка (Singleton)
__Суть:__
Гарантирует, что у класса есть только один экземпляр.

## Пример
```c++
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    void log(const std::string& msg) { std::cout << msg << "\n"; }

private:
    Logger() {} // Приватный конструктор
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
```
## Плюсы:
✅ Контролируемый доступ к единственному экземпляру.

## Минусы:
❌ Усложняет тестирование.
❌ Нарушает принцип единственной ответственности.

## Когда применять?
1. Когда нужен ровно один экземпляр класса (настройки, логгеры).