# include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

class IArsenal
{
public:
    virtual ~IArsenal() = default;

    class IRussianArsenal // Абстрактный класс русских кузнецов и что они могут
    {
    public:
        virtual void createArsenal() const = 0;
        //virtual void createArmor() const = 0;
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
    virtual bool can_create_sword(const std::string& type_sword) const = 0;
    virtual bool can_create_armor(const std::string& type_armor) const = 0; 
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

    bool can_create_sword(const std::string& type_sword) const override
    {
        return type_sword == "sword";
    }
    bool can_create_armor(const std::string& type_armor) const override
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

    bool can_create_sword(const std::string& type_sword) const override
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
    bool can_create_armor(const std::string& type_armor) const override
    {
        return type_armor == "armor";
    }
};

////////////////
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
            std::cout << "Ещё не существует " << type_blacksmith << " кузнец."; 
            return ;
        }
        auto blacksmith = factory->createBlacksmith(); //RussianBlacksmith

        try
        {
            if(blacksmith->can_create_armor(type_arsenal)) // armor (true)
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
            

            if(blacksmith->can_create_sword(type_arsenal)) // sword (true)
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

            if(!blacksmith->can_create_armor(type_arsenal)  && !blacksmith->can_create_sword(type_arsenal))
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