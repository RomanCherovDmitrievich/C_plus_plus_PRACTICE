# 1. Принцип единственной ответственности (Single Responsibility Principle, SRP)

Определение: Класс должен иметь только одну причину для изменения, т.е. выполнять одну ответственность.

## Неправильно 
Класс User управляет и данными пользователя, и логированием.
```c++
class User {
private:
    string name;
    string email;
public:
    void saveToDatabase() {
        // Сохранение в БД
    }
    void logActivity(string action) {
        // Логирование действий
        ofstream log("activity.log");
        log << action << endl;
    }
};
```
__Проблема:__ Если изменится способ логирования или сохранения, придётся менять класс User.

## Правильно
Разделение на два класса:
```c++
class User {
private:
    string name;
    string email;
public:
    void saveToDatabase() {
        // Только сохранение
    }
};

class ActivityLogger {
public:
    void log(string action) {
        ofstream log("activity.log");
        log << action << endl;
    }
};
```
__Плюс:__ Логика логирования и сохранения изолирована.