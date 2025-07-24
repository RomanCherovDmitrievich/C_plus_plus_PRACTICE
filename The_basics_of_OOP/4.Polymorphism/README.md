# Определения
## О полиморфизме
__Полиморфизм__ -  возможность объектов с одинаковым интерфейсом выполнять разные реализации.
_Он нужен для гибкости кода, работы с разными типами через единый интерфейс. Работает через виртуальные функции (__virtual__) и переопределение методов (__override__)._

__Полиморфизм__ в C++ реализуется через таблицу виртуальных функций (vtable). Когда класс содержит хотя бы одну virtual-функцию:
1. Компилятор создает для класса скрытую vtable — массив указателей на виртуальные функции.
2. Каждый объект такого класса получает скрытый указатель (vptr) на свою vtable.
3. При вызове виртуальной функции происходит динамическое связывание: программа ищет нужную реализацию через vptr во время выполнения.

```c++
class Base {
public:
    virtual void foo() {} // vtable[0]
    virtual void bar() {} // vtable[1]
};

class Derived : public Base {
public:
    void foo() override {} // Переопределение vtable[0]
};
```
>У Base будет vtable с адресами Base::foo и Base::bar.
>У Derived — vtable с адресами Derived::foo и Base::bar.

## Зачем нужны virtual и override
### Ключевое слово virtual

Без __virtual__: Вызов метода определяется на этапе компиляции (статическое связывание).
```c++
Base* obj = new Derived();
obj->foo(); // Вызовется Base::foo(), если foo() не virtual
```
С __virtual__: Вызов определяется во время выполнения (динамическое связывание).
```c++
Base* obj = new Derived();
obj->foo(); // Вызовется Derived::foo()
```
### Ключевое слово override
_Позволяет явно указать, что метод переопределяет виртуальную функцию базового класса._
Без __override__: Если вы опечатаетесь в сигнатуре, создастся новый метод, а не переопределение.
С __override__: Компилятор проверит, что такая виртуальная функция есть в базовом классе.

```c++
class Derived : public Base {
public:
    void Foo() {} // Опечатка: foo() != Foo(). Без override это НЕ ошибка!
};
```
# Пример 
```c++
class Shape {
public:
    virtual void draw() = 0; // Чистая виртуальная функция
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a circle" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing a square" << endl; }
};

// Использование:
Shape* shapes[] = {new Circle(), new Square()};
for (auto shape : shapes) {
    shape->draw(); // Полиморфный вызов
}
// Вывод:
// Drawing a circle
// Drawing a square
```

# Виды полиморфизма
## Динамический полиморфизм (Runtime Polymorphism)
### Определения
Выбор метода происходит во время выполнения программы.
_Работает через виртуальные функции (virtual) и механизм vtable (таблица виртуальных методов)._

### Пример
```c++
class Phones {
public:
    virtual void info() { std::cout << "Привет, я телефон." << std::endl; }
};

class Samsung : public Phones {
public:
    void info() override { std::cout << "Привет, я Samsung." << std::endl; }
};

class Apple : public Phones {
public:
    void info() override { std::cout << "Привет, я Apple." << std::endl; }
};

int main() {
    Phones* phone1 = new Samsung();
    Phones* phone2 = new Apple();

    phone1->info(); // Вывод: "Привет, я Samsung." (решение в runtime)
    phone2->info(); // Вывод: "Привет, я Apple." (решение в runtime)
}
```
## Статический полиморфизм
### Определения 
Выбор метода происходит на этапе компиляции.
_Работает через шаблоны (templates) и перегрузку функций._
Подтипы:
1. Параметрический полиморфизм (Generics / Templates) → Один код для разных типов.
2. Ad-hoc полиморфизм (перегрузка функций, операторов) → Разные реализации для разных типов.
3. Полиморфизм подтипов (через CRTP - Curiously Recurring Template Pattern)

### Пример
__Пример 1: Параметрический полиморфизм (шаблоны)__
```c++
#include <iostream>
#include <string>

// Базовый класс документа
class Document {
public:
    virtual ~Document() = default;
    virtual std::string getType() const = 0;
};

// Конкретные реализации документов
class TextDocument : public Document {
public:
    std::string getType() const override { return "Text Document"; }
};

class SpreadsheetDocument : public Document {
public:
    std::string getType() const override { return "Spreadsheet Document"; }
};

class PresentationDocument : public Document {
public:
    std::string getType() const override { return "Presentation Document"; }
};

// Шаблонный обработчик документов (параметрический полиморфизм)
template <typename T>
class DocumentProcessor {
public:
    void process(const T& doc) {
        std::cout << "Processing " << doc.getType() << std::endl;
        // Здесь может быть специализированная обработка для каждого типа
    }
};

int main() {
    TextDocument textDoc;
    SpreadsheetDocument spreadsheetDoc;
    PresentationDocument presentationDoc;

    DocumentProcessor<TextDocument> textProcessor;
    DocumentProcessor<SpreadsheetDocument> spreadsheetProcessor;
    DocumentProcessor<PresentationDocument> presentationProcessor;

    textProcessor.process(textDoc);
    spreadsheetProcessor.process(spreadsheetDoc);
    presentationProcessor.process(presentationDoc);

    return 0;
}
```
__Что происходит:__
>Компилятор генерирует три разные версии класса DocumentProcessor для каждого типа документа
>Все типы разрешаются на этапе компиляции
>Нет накладных расходов на виртуальные вызовы

__Пример 2: Ad-hoc полиморфизм (перегрузка функций)__
```c++
#include <iostream>
#include <string>

class TextDocument {
public:
    std::string getContent() const { return "Text content"; }
};

class SpreadsheetDocument {
public:
    std::string getData() const { return "Spreadsheet data"; }
};

class PresentationDocument {
public:
    std::string getSlides() const { return "Presentation slides"; }
};

// Перегруженные функции для разных типов документов
void printDocument(const TextDocument& doc) {
    std::cout << "Printing text: " << doc.getContent() << std::endl;
}

void printDocument(const SpreadsheetDocument& doc) {
    std::cout << "Printing spreadsheet: " << doc.getData() << std::endl;
}

void printDocument(const PresentationDocument& doc) {
    std::cout << "Printing presentation: " << doc.getSlides() << std::endl;
}

int main() {
    TextDocument textDoc;
    SpreadsheetDocument spreadsheetDoc;
    PresentationDocument presentationDoc;

    printDocument(textDoc);
    printDocument(spreadsheetDoc);
    printDocument(presentationDoc);

    return 0;
}
```
__Что происходит:__
>Для каждого типа документа существует своя версия функции printDocument
>Компилятор выбирает нужную версию на этапе компиляции
>Можно работать с классами, не имеющими общего интерфейса

__3. Полиморфизм подтипов (через CRTP - Curiously Recurring Template Pattern)__
```c++
#include <iostream>
#include <string>

// Шаблон базового класса (CRTP)
template <typename T>
class Document {
public:
    void print() {
        static_cast<T*>(this)->printImpl();
    }
};

// Конкретные реализации документов
class TextDocument : public Document<TextDocument> {
public:
    void printImpl() {
        std::cout << "Printing text document" << std::endl;
    }
};

class SpreadsheetDocument : public Document<SpreadsheetDocument> {
public:
    void printImpl() {
        std::cout << "Printing spreadsheet document" << std::endl;
    }
};

class PresentationDocument : public Document<PresentationDocument> {
public:
    void printImpl() {
        std::cout << "Printing presentation document" << std::endl;
    }
};

// Функция для обработки любых документов
template <typename T>
void processDocument(Document<T>& doc) {
    doc.print();
}

int main() {
    TextDocument textDoc;
    SpreadsheetDocument spreadsheetDoc;
    PresentationDocument presentationDoc;

    processDocument(textDoc);
    processDocument(spreadsheetDoc);
    processDocument(presentationDoc);

    return 0;
}
```

__Что происходит:__
>Каждый документ наследуется от шаблонного базового класса с указанием себя как параметра шаблона
>Вызовы методов разрешаются на этапе компиляции через статическое приведение типов
>Нет накладных расходов на виртуальные таблицы
>Сохраняется полиморфное поведение, но без runtime-накладных расходов

### Сравнение подходов

| Характеристика | Параметрический | Ad-hoc | CRTP |
| :------------- | :-------------: | :----: | :--: |
| Общий интерфейс | Не требуется | Не требуется | Не требуется |
| Решение на этапе | Компиляции | Компиляции | Компиляции |
| Накладные расходы | Нет | Нет | Нет |
| Гибкость | Высокая | Ограниченная | Высокая |
| Совместимость с STL | Полная | Частичная | Полная |


# Сравнение видов полиморфизма

| Критерий | Динамический (Runtime) | Статический (Compile-Time) | 
| :------------- | :-------------: | :----: |
| Когда разрешается | Во время выполнения | На этапе компиляции | 
| Механизм | Виртуальные функции (virtual) | Шаблоны (template), перегрузка | 
| Накладные расходы | Да (vtable, динамический вызов) | Нет | 
| Гибкость | Высокая (можно менять поведение) | Ограничена (фиксируется при компиляции) | 
