# Определения
__Композиция__ - включение одного объекта в качестве поля другого (отношение "часть-целое").
_Это нужно для построение сложных объектов из простых компонентов. Работает через создание объектов-членов внутри класса._

__Объект__ — это базовая единица объектно-ориентированного программирования, представляющая собой реальные сущности. 
__Сложные объекты__ состоят из более __простых объектов__ или набора объектов. Например, мобильный телефон состоит из различных объектов, таких как камера, аккумулятор, экран, датчики и т. д. Этот процесс создания сложных объектов из более простых называется композицией объектов.

## Синтаксис
```c++
class A
{
 // тело класса
};
class B
{
 A objA;
 public:
 B(список аргументов) : objA(список аргументов1);
};
```
В приведённых выше классах B использует объекты класса A в качестве своих элементов данных. Следовательно, B — это сложный класс, использующий простой класс A.

# Пример
```c++
// Simple class
class A {
public:
    int x;

    // COnstructor initializing
    // the data members
    A() { x = 0; }

    A(int a)
    {
        cout << "Constructor A(int a) is invoked" << endl;
        x = a;
    }
};

// Complex class
class B {
    int data;
    A objA;

public:
    // COnstructor initializing the
    // data members
    B(int a)
        : objA(a)
    {
        data = a;
    }

    // Function to print values
    // of data members in class
    // A and B
    void display()
    {
        cout << "Data in object of class B = " << data
             << endl;
        cout << "Data in member object of "
             << "class A in class B = " << objA.x;
    }
};

// Driver code
int main()
{
    // Creating object of class B
    B objb(25);

    // Invoking display function
    objb.display();
    return 0;
}
```