# 4. Декоратор (Decorator)
Суть: Динамически добавляет объекту новые обязанности.

Шаблон проектирования «Декоратор» — это структурный шаблон проектирования в разработке программного обеспечения, который позволяет динамически добавлять новые функции или обязанности к отдельным объектам без изменения их базовой структуры. Это достигается за счёт создания набора классов-декораторов, которые используются для обёртывания конкретных компонентов, представляющих основную функциональность.

## Особенности узора «Декоратор»
* Декораторы соответствуют тому же интерфейсу, что и компоненты, которые они украшают, что позволяет использовать их взаимозаменяемо.
* Этот шаблон способствует повышению гибкости и расширяемости программных систем, позволяя разработчикам создавать объекты с различными комбинациями функций во время выполнения.
* Он соответствует принципу открытости/закрытости, поскольку новые декораторы можно добавлять без изменения существующего кода, что делает его мощным инструментом для создания модульных и настраиваемых программных компонентов.
* Шаблон проектирования «Декоратор» обычно используется в тех случаях, когда к объектам необходимо гибко и многократно добавлять различные дополнительные функции или возможности, например при форматировании текста, создании графических пользовательских интерфейсов или персонализации таких продуктов, как кофе или мороженое.

## Ключевые компоненты паттерна Декоратор
1. __Интерфейс компонента__
Это абстрактный класс или интерфейс, который определяет общий интерфейс как для конкретных компонентов, так и для декораторов. Он определяет операции, которые можно выполнять с объектами.
2. __Бетонный компонент__
Это базовые объекты или классы, реализующие интерфейс Component. Это объекты, к которым мы хотим добавить новое поведение или обязанности.
3. __Декоратор__
Это абстрактный класс, который также реализует интерфейс Component и содержит ссылку на объект Component. Декораторы отвечают за добавление новых функций к обернутому объекту Component.
4. __Бетонный декоратор__
Это конкретные классы, расширяющие класс Decorator . Они добавляют Компоненту определенное поведение или обязанности. Каждый конкретный декоратор может добавить одно или несколько поведений к Компоненту.

## Пример 1
```c++
#include <iostream>
#include <string>

using namespace std;

class IceCream {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

class VanillaIceCream : public IceCream {
public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }

    double cost() const override { return 160.0; }
};

class IceCreamDecorator : public IceCream {
protected:
    IceCream* iceCream;

public:
    IceCreamDecorator(IceCream* ic) : iceCream(ic) {}

    string getDescription() const override
    {
        return iceCream->getDescription();
    }

    double cost() const override
    {
        return iceCream->cost();
    }
};

class ChocolateDecorator : public IceCreamDecorator {
public:
    ChocolateDecorator(IceCream* ic) : IceCreamDecorator(ic) {}

    string getDescription() const override
    {
        return iceCream->getDescription()
               + " with Chocolate";
    }

    double cost() const override
    {
        return iceCream->cost() + 100.0;
    }
};

class CaramelDecorator : public IceCreamDecorator {
public:
    CaramelDecorator(IceCream* ic) : IceCreamDecorator(ic) {}

    string getDescription() const override
    {
        return iceCream->getDescription() + " with Caramel";
    }

    double cost() const override
    {
        return iceCream->cost() + 150.0;
    }
};

int main()
{
    IceCream* vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription() << ", Cost: Rs." << vanillaIceCream->cost() << endl;

    IceCream* chocolateIceCream = new ChocolateDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription() << ", Cost: Rs." << chocolateIceCream->cost() << endl;

    IceCream* caramelIceCream = new CaramelDecorator(chocolateIceCream);
    cout << "Order: " << caramelIceCream->getDescription() << ", Cost: Rs." << caramelIceCream->cost() << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete caramelIceCream;

    return 0;
}
```
### Диаграмма паттерна Декоратор(по примеру кода 1 )
<figure>
    <img src ="/assets/images/Diagram_Decorator1.png" alt = "Decorator1">
</figure>

## Пример 2
```c++
#include <iostream>
#include <string>

using namespace std;

class Cake {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

class PlainCake : public Cake {
public:
    string getDescription() const override
    {
        return "Plain Cake";
    }

    double cost() const override { return 300.0; }
};

class CakeDecorator : public Cake {
protected:
    Cake* cake;

public:
    CakeDecorator(Cake* c)
        : cake(c)
    {
    }

    string getDescription() const override
    {
        return cake->getDescription();
    }

    double cost() const override { return cake->cost(); }
};

class ChocolateDecorator : public CakeDecorator {
public:
    ChocolateDecorator(Cake* c)
        : CakeDecorator(c)
    {
    }

    string getDescription() const override
    {
        return cake->getDescription() + " with Chocolate";
    }

    double cost() const override
    {
        return cake->cost() + 200.0;
    }
};

class FruitDecorator : public CakeDecorator {
public:
    FruitDecorator(Cake* c)
        : CakeDecorator(c)
    {
    }

    string getDescription() const override
    {
        return cake->getDescription() + " with Fruits";
    }

    double cost() const override
    {
        return cake->cost() + 150.0;
    }
};

int main()
{
    Cake* plainCake = new PlainCake();
    cout << "Plain Cake:" << plainCake->getDescription() << "\nCost:Rs." << plainCake->cost() << endl;

    Cake* chocolateCake = new ChocolateDecorator(plainCake);
    cout << "\nChocolate Cake:" << chocolateCake->getDescription() << "\nCost:Rs." << chocolateCake->cost() << endl;

    Cake* fruitCake1 = new FruitDecorator(chocolateCake);
    cout << "\nFruit Cake:" << fruitCake1->getDescription() << "\nCost:Rs." << fruitCake1->cost() << endl;

    delete chocolateCake;
    delete fruitCake1;

    Cake* fruitCake2 = new FruitDecorator(plainCake);
    cout << "\nFruit Cake:" << fruitCake2->getDescription() << "\nCost:Rs." << fruitCake2->cost() << endl;

    delete plainCake;
    delete fruitCake2;

    return 0;
}
```
### Диаграмма паттерна Декоратор(по примеру кода 2 )
<figure>
    <img src ="/assets/images/Diagram_Decorator2.png" alt = "Decorator2">
</figure>

## Преимущества шаблона проектирования Декоратор
✅ __Принцип открытости-закрытости:__ Шаблон проектирования «Декоратор» основан на принципе открытости/закрытости, который гласит, что классы должны быть открыты для расширения, но закрыты для модификации. Это означает, что вы можете добавить новые функции в существующий класс, не изменяя его исходный код.

✅ __Гибкость:__ Это позволяет добавлять или удалять обязанности (то есть модели поведения) у объектов во время выполнения. Благодаря такой гибкости можно легко создавать сложные структуры объектов с различными комбинациями моделей поведения.

✅ __Код многократного использования:__ Декораторы — это компоненты многократного использования. Вы можете создать библиотеку классов-декораторов и применять их к различным объектам и классам по мере необходимости, сокращая дублирование кода.

✅ __Композиция важнее наследования:__ В отличие от традиционного наследования, которое может привести к созданию глубокой и негибкой иерархии классов, в шаблоне проектирования «Декоратор» используется композиция. Вы можете комбинировать объекты с различными декораторами для достижения желаемой функциональности, избегая недостатков наследования, таких как жёсткая привязка и строгая иерархия.

✅ __Динамическая модификация поведения:__ Декораторы можно применять или удалять во время выполнения программы, что позволяет динамически изменять поведение объектов. Это особенно полезно, когда нужно адаптировать поведение объекта в соответствии с меняющимися требованиями или предпочтениями пользователя.

✅ __Понятная структура кода:__ Шаблон проектирования «Декоратор» способствует созданию чёткого и структурированного дизайна, благодаря чему разработчикам проще понять, как к объектам добавляются различные функции и обязанности.

## Недостатки шаблона проектирования Декоратор
❌ __Сложность:__ Чем больше декораторов вы добавляете к объекту, тем сложнее становится код и тем труднее его понять. Из-за вложенности декораторов в кодовой базе может быть сложно ориентироваться и отлаживать код, особенно если декораторов много.

❌ __Увеличение количества занятий:__ При использовании шаблона проектирования «Декоратор» часто получается большое количество небольших специализированных классов-декораторов. Это может привести к увеличению количества классов в вашей кодовой базе, что, в свою очередь, может увеличить трудозатраты на поддержку.

❌ __Порядок награждения:__ Порядок применения декораторов может повлиять на итоговое поведение объекта. Если декораторы применяются в неправильном порядке, это может привести к неожиданным результатам. Управлять порядком применения декораторов может быть непросто, особенно в сложных сценариях.

❌ __Возможность чрезмерного использования:__ Поскольку к объектам легко добавлять декораторы, существует риск чрезмерного использования паттерна «Декоратор», что приведёт к неоправданному усложнению кодовой базы. Важно использовать декораторы с умом и только в тех случаях, когда они действительно повышают ценность дизайна.

❌ __Подходит не для каждой ситуации:__ Шаблон проектирования «Декоратор» лучше всего подходит для ситуаций, когда необходимо динамически добавлять обязанности к объектам. В случаях, когда структура объекта относительно стабильна и изменения происходят редко, использование других шаблонов проектирования или методов может быть более эффективным и простым.

❌ __Ограниченная поддержка на некоторых языках:__ Некоторые языки программирования могут не обеспечивать удобную поддержку для реализации декораторов. Реализация этого шаблона на таких языках может быть более громоздкой и менее интуитивной.

## Где использовать?
1. Добавление функций в виджеты графического интерфейса
2. Форматирование текста
3. Ввод/вывод потоков
4. Настройка кофе или блюд