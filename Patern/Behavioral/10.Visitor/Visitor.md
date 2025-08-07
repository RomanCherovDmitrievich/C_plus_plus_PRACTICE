# 10. Visitor (Посетитель)
__Суть:__
Позволяет добавлять новые операции к объектам без изменения их классов.

## Пример
```c++
#include <iostream>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual void visit(ConcreteElementA* el) = 0;
    virtual void visit(ConcreteElementB* el) = 0;
};

class Element {
public:
    virtual void accept(Visitor* v) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor* v) override { v->visit(this); }
    std::string featureA() { return "Element A"; }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor* v) override { v->visit(this); }
    std::string featureB() { return "Element B"; }
};

class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA* el) override {
        std::cout << "Visitor processes " << el->featureA() << std::endl;
    }
    void visit(ConcreteElementB* el) override {
        std::cout << "Visitor processes " << el->featureB() << std::endl;
    }
};

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;
    ConcreteVisitor visitor;

    elementA.accept(&visitor);  
    elementB.accept(&visitor);  

    return 0;
}
```
## Плюсы:
✅ Добавляет операции без изменения классов.
✅ Объединяет родственные операции в одном классе.

## Минусы:
❌ Усложняет добавление новых классов элементов.

## Где применяется?
1. Компиляторы (анализ AST).
2. Сериализация/десериализация.