# include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

// Проблема 1: Если надо будет добавить много продуктов?
// Ответ 1: Просто добавляем реализацию этого орудия к нужному кузнецу, добавляем функцию которая проверяет,
// может ли этот кузнец сделать это орудие, делаем функцию в Client чтоб у него был доступ к новому орудию у кузнецов.
// Вывод: Решение удобное для этого кода, так как не надо сильно менять код. +

// Проблема 2: Если надо будет добавить много кузнецов?
// Ответ 2: Добавляем новый интерфейс и его класс где будут реализованы его функции, добавляем новую фабрику к нашей абстрактной фабрике, 
// в которой указываем ссылку на нужный вам класс
// Вывод: Решение относительно удобное, ведь происходит много копирования, если каждый кузнец будет способен делать только 1  индивидуальный продукт,
// то придётся делать реализацию того, что этот кузнец не может делать другие типы продуктов. -

// Проблема 3: Если определённый кузнец научиться делать тот продукт, который раньше не мог?
// Ответ 3: Просто добавляем функцию в реализацию кузнеца, меняем проверку так, чтоб клиент увидел что кузнец теперь может делать этот продукт.
// Вывод: Решение удобное для этого кода, так как не надо сильно менять код. +

// Проблема 4: Может ли один кузнец создавать продукты другого кузнеца(Например японский кузнец научился делать русский меч)?
// Ответ 4: Добавляем новую функцию в реализацию конкретного кузнеца.
// Вывод: Классы кузнецов не связаны напрямую между собой, а значит пользоваться умениями другого не получиться, придётся добавлять новый продукт в его интерфейс и делать его реализацию

// Пользователь видит только класс клиента, и доступа к другим классам у него нет, мы скрыли реализацию по созданию наших продуктов.


// Product
class IArsenal
{
public:
    virtual ~IArsenal() = default;

    class IRussianArsenal // Абстрактный класс русских кузнецов и что они могут
    {
    public:
        virtual void createArsenal() const = 0;
        virtual ~IRussianArsenal() = default;
    };

    class IJapaneseArsenal // Абстрактный класс японских кузнецов и что они могут
    {
    public:
        virtual void createArsenal() const = 0;
        virtual ~IJapaneseArsenal() = default;
    };

    virtual std::unique_ptr<IRussianArsenal> createRusArsenal(const std::string& type_arsenal) const = 0;
    virtual std::unique_ptr<IJapaneseArsenal> createJapArsenal(const std::string& type_arsenal) const = 0;
    virtual bool can_create_swords(const std::string& type_sword) const = 0;
    virtual bool can_create_armors(const std::string& type_armor) const = 0; 
};

class RussianBlacksmith : public IArsenal // Конкретный класс русского арсенала
{
public:
    class RussianSwords : public IRussianArsenal
    {
    public:
        void createArsenal() const override
        {
            std::cout << "Русский меч создан. ";
        }
    };

    class RussianArmors : public IRussianArsenal
    {
    public:
        void createArsenal() const override
        {
            std::cout << "Русский доспех создан. ";
        }
    };

    std::unique_ptr<IRussianArsenal> createRusArsenal(const std::string& type_arsenal) const override
    {
        if(type_arsenal == "sword")
        {
            return std::make_unique<RussianSwords>();
        }
        else if(type_arsenal == "armor")
        {
            return std::make_unique<RussianArmors>();
        }
        throw std::invalid_argument(type_arsenal + " не существует");
    }

    std::unique_ptr<IJapaneseArsenal> createJapArsenal(const std::string& type_arsenal) const override
    {
        throw std::invalid_argument(type_arsenal + "не может сделать");
    }

    bool can_create_swords(const std::string& type_sword) const override
    {
        return type_sword == "sword";
    }
    bool can_create_armors(const std::string& type_armor) const override
    {
        return type_armor == "armor";
    }
};

class JapaneseBlacksmith : public IArsenal // Конкретный класс японского арсенала
{
public: 
    class JapaneseArmor : public IJapaneseArsenal
    {
    public:
        void createArsenal() const override
        {
            std::cout << "Японский доспех создан. ";
        }
    };

    std::unique_ptr<IRussianArsenal> createRusArsenal(const std::string& type_arsenal) const override
    {
        throw std::invalid_argument(type_arsenal + " не существует");
    }
    std::unique_ptr<IJapaneseArsenal> createJapArsenal(const std::string& type_arsenal) const override
    {
        if(type_arsenal == "armor")
        {
            return std::make_unique<JapaneseArmor>();
        }
        throw std::invalid_argument(type_arsenal + " не существует");
        
    }

    bool can_create_swords(const std::string& type_sword) const override 
    {
        if(type_sword == "sword")
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    bool can_create_armors(const std::string& type_armor) const override
    {
        return type_armor == "armor";
    }
};

// Factory
class AbstractionFactoryBlacksmiths
{
public:
    virtual std::unique_ptr<IArsenal> createBlacksmith() const = 0;
    virtual ~AbstractionFactoryBlacksmiths() = default;
};

class FactoryRussianBlacksmith : public AbstractionFactoryBlacksmiths
{
public:
    std::unique_ptr<IArsenal> createBlacksmith() const override
    {
        return std::make_unique<RussianBlacksmith>();
    }
};

class FactoryJapaneseBlacksmith : public AbstractionFactoryBlacksmiths
{
public:
    std::unique_ptr<IArsenal> createBlacksmith() const override
    {
        return std::make_unique<JapaneseBlacksmith>();
    }
};

class Client
{
private:
    std::unique_ptr<AbstractionFactoryBlacksmiths> createFactory(const std::string& type_blacksmith) const
    {
        if(type_blacksmith == "russian")
        {
            return std::make_unique<FactoryRussianBlacksmith>();
        }
        else if(type_blacksmith == "japanese")
        {
            return std::make_unique<FactoryJapaneseBlacksmith>();
        }
        else
        {
            return nullptr;
        }
    }

public:
    void orderArsenal(const std::string& type_blacksmith, const std::string& type_arsenal) // russian, armor
    {
        std::unique_ptr<AbstractionFactoryBlacksmiths> factory = createFactory(type_blacksmith); // FactoryRussianBlacksmith
        if(!factory)
        {
            std::cout << "Ещё не существует " << type_blacksmith << " кузнеца."; 
            return ;
        }
        auto blacksmith = factory->createBlacksmith(); //RussianBlacksmith

        try
        {
            if(blacksmith->can_create_armors(type_arsenal)) // armor (true)
            {
                if(type_blacksmith == "japanese")
                {
                    auto armor = blacksmith->createJapArsenal(type_arsenal); // invalid_argument
                    armor->createArsenal(); //вывод
                }
                else if(type_blacksmith == "russian")
                {
                    auto armor = blacksmith->createRusArsenal(type_arsenal); // RussianArmor
                    armor->createArsenal(); // вывод
                }
            }
            

            if(blacksmith->can_create_swords(type_arsenal)) // sword (true)
            {
                if(type_blacksmith == "japanese")
                {
                    auto sword = blacksmith->createJapArsenal(type_arsenal);
                }
                else if(type_blacksmith == "russian")
                {
                    auto sword = blacksmith->createRusArsenal(type_arsenal); // RussianSword
                    sword->createArsenal(); // вывод
                }
            }

            if(!blacksmith->can_create_armors(type_arsenal)  && !blacksmith->can_create_swords(type_arsenal))
            {
               std::cout << type_blacksmith << " кузнец"  << " не может сделать " << type_arsenal;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error" << e.what() << '\n';
        }
        
    }    
};

int main()
{
    Client client;
    client.orderArsenal("russian", "sword");
    std::cout << std::endl << std::endl;

    client.orderArsenal("japanese", "armor");
    std::cout << std::endl << std::endl;

    client.orderArsenal("russian", "armor");
    std::cout << std::endl << std::endl;

    client.orderArsenal("japanese", "bow");
    std::cout << std::endl << std::endl;

    client.orderArsenal("russian", "bow");
    std::cout << std::endl << std::endl;


    client.orderArsenal("polish", "sword");
    std::cout << std::endl << std::endl;

    return 0;
}