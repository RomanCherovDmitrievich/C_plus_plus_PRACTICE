#include <iostream>

class SingletonArsenal
{
private:
    SingletonArsenal()
    {
        std::cout << "Создан экземпляр Singleton - арсенал." << std::endl;
    }
    ~SingletonArsenal()
    {
        std::cout << "Уничтожен экземпляр Singleton - арсенал" << std::endl;
    }
    static SingletonArsenal* arsenal;

public:
    static SingletonArsenal& getArsenal()
    {
        if(!arsenal)
        {
            arsenal = new SingletonArsenal();
        }
        return *arsenal;
    }
    void create()
    {
        std::cout << "Комплект арсенала создан и выдан бойцу." << std::endl;
    }

    SingletonArsenal(const SingletonArsenal&) = delete;
    SingletonArsenal& operator=(const SingletonArsenal&) = delete;
};

SingletonArsenal* SingletonArsenal::arsenal = nullptr;

int main()
{
    SingletonArsenal& arsenal = SingletonArsenal::getArsenal();

    arsenal.create();

    return 0;
}
