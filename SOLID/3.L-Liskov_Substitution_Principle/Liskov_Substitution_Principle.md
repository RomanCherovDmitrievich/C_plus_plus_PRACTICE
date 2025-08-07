# 3. Принцип подстановки Барбары Лисков (Liskov Substitution Principle, LSP)
__Суть:__ 
Подклассы должны быть заменяемыми на свои базовые классы без изменения корректности программы.

# Неправильно:
```c++
class Bird {
public:
    virtual void fly() {
        std::cout << "Flying!" << std::endl;
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Penguins can't fly!");
    }
};
```
__Проблема:__ ```Penguin``` нарушает контракт ```Bird```, так как не может летать.

# Правильно:
```c++
class Bird {
public:
    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    virtual void fly() {
        std::cout << "Flying!" << std::endl;
    }
};

class Penguin : public Bird {
    // У пингвинов нет метода fly(), и это корректно
};
```

__Исправление:__ Разделили птиц на летающих и нелетающих, соблюдая LSP.


