# Определения 

__Инкапсуляция__ - принцип объединения данных и методов в единую структуру (класс) и ограничения прямого доступа к внутренним данным.
_Защита внутреннего состояния объекта от некорректного использования._

Работает через модификаторы доступа:
>public
>protected
>private

# Пример

```c++
class BankAccount {
private:
    double balance; // Скрытое поле

public:
    void deposit(double amount) {
        if (amount > 0) balance += amount; // Контроль условий
    }

    double getBalance() { return balance; } // Геттер
};

// Использование:
BankAccount acc;
acc.deposit(1000); // Прямой доступ к balance невозможен
```