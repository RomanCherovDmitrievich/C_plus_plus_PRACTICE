#include <iostream>

class Person
{
public:
    //Методы
    void set_name(std::string _name)
    {
        name = _name;
    }
    void set_age(int _age)
    {
        age = _age;
    }
    
    void print_info()
    {
        std::cout << "Имя - " << name <<", возраст - " << age << ", паспорт - " << passport << ", работает - " << work << std::endl;
    }

    void info_person()
    {
        if(name == "Bob" && age == 25)
        {
            passport = 123456789;
            work = "Builder";
        }
        else if(name == "Park" && age == 32)
        {
            passport = 987654321;
            work = "Musician";
        }
        else
        {
            passport = 0;
            work = "Нет в базе.";
        }

    }

private:
//Поля:
    int passport;
    int age;
    std::string work;
    std::string name;
};

int main()
{
    Person person; // Объект
    person.set_name("Bob");
    person.set_age(25);
    person.info_person();
    person.print_info();

    person.set_name("Park");
    person.set_age(32);
    person.info_person();
    person.print_info();

    person.set_name("Roma");
    person.set_age(19);
    person.info_person();
    person.print_info();


    return 0;
}