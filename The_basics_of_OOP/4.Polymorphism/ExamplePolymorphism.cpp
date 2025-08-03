/*#include <iostream>
#include <string>

// Динамический полиморфизм (Runtime Polymorphism)
class Phones
{
public:
    Phones(std::string phone) : phone(phone){}
    virtual void info()
    {
        std::cout << "Привет, я телефон." << std::endl;
    }
protected:
    std::string phone;
};

class Samsung : public Phones
{
public:
    Samsung(std::string phone) : Phones(phone){}
    void info() override
    {
        std::cout << "Привет, я " << this->phone << "." << std::endl;
    }
};

class Apple : public Phones
{
public:
    Apple(std::string phone) : Phones(phone){}
    void info() override
    {
        std::cout << "Привет, я " << this->phone << "." << std::endl;
    }
};

class Xiaomi : public Phones
{
public:
    Xiaomi(std::string phone) : Phones(phone){}
    void info() override
    {
        std::cout << "Привет, я " << this->phone << "." << std::endl;
    }
};

//Статический полиморфизм (Compile-Time Polymorphism)
//Подтип: Параметрический полиморфизм

class Car
{
public:
    virtual ~Car() = default;
    virtual std::string get_Model() const = 0;
};

class BMW : public Car
{
public:
    std::string get_Model() const override
    {
        return "BMW";
    }
};

class Audi : public Car
{
public:
    std::string get_Model() const override
    {
        return "Audi";
    }
};

template <typename T>
class CarInfo
{
public:
    void info(const T& model)
    {
        std::cout << "Модель машины - " << model.get_Model() << std::endl;
    }
};

//Статический полиморфизм (Compile-Time Polymorphism)
//Подтип: Ad-hoc полиморфизм (перегрузка функций)

class Meet
{
public:
    std::string get_Eats() const
    {
        return "Стейк";
    }
};

class Rice
{
public:
    std::string get_Eats() const
    {
        return "Рис";
    }
};

void printInfo(const Meet& eat)
{
    std::cout << "Сегодня на ужин " << eat.get_Eats() << std::endl;
}
void printInfo(const Rice& eat)
{
    std::cout << "Сегодня на ужин " << eat.get_Eats() << std::endl;
}

//Статический полиморфизм (Compile-Time Polymorphism)
//Подтип: Полиморфизм подтипов (через CRTP - Curiously Recurring Template Pattern)

// Шаблон базового класса (CRTP)
template<typename T>
class Sport
{
public:
    void print()
    {
        static_cast<T*>(this)->printInfo();
    }
};

class Football : public Sport<Football>
{
public:
    void printInfo()
    {
        std::cout << "Футбол, лучшая игра с мячом" << std::endl;
    }
};

class Basketball : public Sport<Basketball>
{
public:
    void printInfo()
        {
            std::cout << "Баскетбол, лучшая игра с мячом" << std::endl;
        }
};

template<typename T>
void INFO(Sport<T>& info)
{
    info.print();
}

int main()
{
    // Динамический полиморфизм

    Phones* phone[3];
    phone[0] = new Samsung("Samsung");
    phone[1] = new Apple("Apple");
    phone[2] = new Xiaomi("Xiaomi");

    phone[0]->info();
    phone[1]->info();
    phone[2]->info();

    // Статический полиморфизм
    // Подтип: Параметрический полиморфизм

    const BMW car_bmw;
    Audi car_audi;

    CarInfo<BMW> info_bmw;
    CarInfo<Audi> info_audi;

    info_bmw.info(car_bmw);
    info_audi.info(car_audi);

    //Статический полиморфизм (Compile-Time Polymorphism)
    //Подтип: Ad-hoc полиморфизм (перегрузка функций)

    Meet eat_meet;
    Rice eat_rice;

    printInfo(eat_meet);
    printInfo(eat_rice);

    //Статический полиморфизм (Compile-Time Polymorphism)
    //Подтип: Полиморфизм подтипов (через CRTP - Curiously Recurring Template Pattern)

    Football football;
    Basketball basketball;

    INFO(football);
    INFO(basketball);

    return 0;
}
    */
#include <iostream>

class I1
{
public:
  I1()
  {
    foo1;
  }
  virtual ~I1(){}

public:
  virtual void foo1() const = 0;
  virtual void foo2() const = 0;
};

class A: public I1
{
public:
  A()
  {
    foo1();
  }
  virtual ~A()
  {
    foo2();
  }

public:
  void foo1() const
  {
    std::cout << "A1::foo1" << std::endl;
  }
  void foo2() const
  {
    std::cout << "A1::foo2" << std::endl;
  }
};

class B: public A
{
public:
  B()
    : A()
  {
    foo1();
  }
  virtual ~B()
  {
    foo2();
  }

public:
  void foo1() const
  {
    std::cout << "B1::foo1" << std::endl;
  }
  void foo2() const
  {
    std::cout << "B1::foo2" << std::endl;
  }
};

void foo(const I1* i)
{
  i->foo1();
  i->foo2();
}

int main()
{
  //I1* i = new A();
  //foo(i);
  //delete i; // 
  I1* i = new B();
  //foo(i);
  delete i;

  return 0;
}