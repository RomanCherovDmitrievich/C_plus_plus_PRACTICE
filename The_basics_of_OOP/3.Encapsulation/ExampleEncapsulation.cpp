#include <iostream>

class Person
{
public:
    void set_name(std::string _name)
    {
        name = _name;
    }
    void set_age(int _age)
    {
        age = _age;
    }
    void set_id(int _id)
    {
        Id = _id;
    }
    void info()
    {
        Name_ID(Id);
        if(!work.empty())
        {
        std::cout << "Имя работника: " << name << ", возраст - " << age << ", должность - " << work << std::endl;
        }
        else
        {
            std::cout << "Не известный человек!" << std::endl;
        }
    }    
    
private:
    std::string name;
    std::string work;
    int age;
    int Id;

    std::string Name_ID(int id)
    {
        if(id >= 1 && id <= 500)
        {
            return work = "Аналитик";
        }
        else if(id >= 500 && id <= 1000)
        {
            return work = "Программист";
        }
        else
        {
            return work = "";
        }
    }
};

int main()
{
    Person person;

    person.set_name("Иван");
    person.set_age(20);
    person.set_id(140);
    person.info();

    person.set_name("Кирилл");
    person.set_age(19);
    person.set_id(670);
    person.info();

    person.set_name("Маша");
    person.set_age(32);
    person.set_id(0);
    person.info();
    //person.Name_ID(); - не видно этого метода
}