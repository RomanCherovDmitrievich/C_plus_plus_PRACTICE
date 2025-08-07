# 9. Template Method (Шаблонный метод)
__Суть:__
Определяет скелет алгоритма, позволяя подклассам переопределять некоторые шаги без изменения структуры.

## Пример
```c++
#include <iostream>

class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
        step3();
    }
    virtual ~AbstractClass() = default;
protected:
    virtual void step2() = 0;
    void step1() { std::cout << "Step 1 (fixed)\n"; }
    void step3() { std::cout << "Step 3 (fixed)\n"; }
};

class ConcreteClass : public AbstractClass {
protected:
    void step2() override { std::cout << "Step 2 (custom)\n"; }
};

int main() {
    ConcreteClass obj;
    obj.templateMethod();  // Step 1 → Step 2 (custom) → Step 3
    return 0;
}
```
## Плюсы:
✅ Переиспользование кода.
✅ Контроль над структурой алгоритма.

## Минусы:
❌ Ограниченная гибкость (шаги фиксированы).

## Где применяется?
1. Фреймворки (инициализация → выполнение → очистка).
2. Обработка файлов (открыть → прочитать → закрыть).