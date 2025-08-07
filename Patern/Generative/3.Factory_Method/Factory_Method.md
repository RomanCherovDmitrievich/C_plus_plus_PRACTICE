# 3. Фабричный метод (Factory Method)
__Суть:__
Определяет интерфейс для создания объекта, но оставляет подклассам решение о том, какой класс инстанцировать.

## Пример
```c++
class Document {
public:
    virtual void open() = 0;
};

class TextDocument : public Document {
    void open() override { std::cout << "Opening text document...\n"; }
};

// Абстрактный создатель
class Application {
public:
    virtual Document* createDocument() = 0;
    void openDocument() {
        Document* doc = createDocument();
        doc->open();
    }
};

// Конкретный создатель
class TextEditor : public Application {
    Document* createDocument() override { return new TextDocument(); }
};
```
## Плюсы:
✅ Гибкость в создании объектов.
✅ Избегает жёсткой привязки к конкретным классам.

## Минусы:
❌ Может привести к созданию множества подклассов.

## Когда применять?
1. Когда классу заранее неизвестно, объекты каких классов ему нужно создавать.