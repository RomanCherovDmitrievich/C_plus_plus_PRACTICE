# 4. Принцип разделения интерфейса (Interface Segregation Principle, ISP)
__Суть:__
Клиенты не должны зависеть от интерфейсов, которые они не используют.
# Неправильно:
```c++
class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : public IWorker {
public:
    void work() override {
        std::cout << "Working 24/7!" << std::endl;
    }
    void eat() override {
        throw std::runtime_error("Robots don't eat!");
    }
};
```
__Проблема:__ ```Robot``` вынужден реализовывать ненужный метод ```eat()```.

# Правильно:
```c++
class IWorkable {
public:
    virtual void work() = 0;
};

class IEatable {
public:
    virtual void eat() = 0;
};

class Human : public IWorkable, public IEatable {
public:
    void work() override { /* ... */ }
    void eat() override { /* ... */ }
};

class Robot : public IWorkable {
public:
    void work() override { /* ... */ }
};
```
__Исправление:__ Разделили интерфейсы, чтобы классы реализовывали только нужное.