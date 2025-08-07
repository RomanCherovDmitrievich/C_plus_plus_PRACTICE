#include <iostream>

class State
{
public:
    virtual void work() = 0;
};

class FirstState : public State
{
public:
    void work() override
    {
        std::cout << "Работа выполнена на 10%." << std::endl; 
    }
};

class SecondState : public State
{
    void work() override
        {
            std::cout << "Работа выполнена на 50%." << std::endl; 
        }
};

class ThirdState : public State
{
    void work() override
        {
            std::cout << "Работа выполнена на 100%." << std::endl; 
        }
};

class Employee
{
private:
    State* state;

public:
    Employee(State* s) : state(s) {}
    void setState(State* s)
    {
        state = s;
    }
    void request()
    {
        state->work();
    }
};

int main()
{
    FirstState s1;
    SecondState s2;
    ThirdState s3;

    Employee emp(&s1);
    emp.request();

    emp.setState(&s2);
    emp.request();

    emp.setState(&s3);
    emp.request();

    emp.setState(&s1);
    emp.request();

    return 0;
}