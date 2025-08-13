#include <iostream>

class IArsenal
{
public:
    virtual void create_sword() = 0;
    virtual void create_bow() = 0;
    virtual ~IArsenal() {}
};

class OldBlacksmith : public IArsenal
{
public:
    OldBlacksmith() {}
    void create_sword() override
    {
        std::cout << "Меч сделан" << std::endl;
    }
    void create_bow() override
    {
        std::cout << "Лук сделан" << std::endl;
    }
};

class YoungBlacksmithProxy : public IArsenal
{
private:
    OldBlacksmith* old_blacksmith;

public:
    YoungBlacksmithProxy() : old_blacksmith(nullptr) {}
    void create_sword() override
    {
        if(old_blacksmith == nullptr)
        {
            old_blacksmith = new OldBlacksmith();
        }
        old_blacksmith->create_sword();
    }
    void create_bow() override
    {
        std::cout << "Лук сделан" << std::endl;
    }
};

int main()
{
    IArsenal* arsenal = new YoungBlacksmithProxy();

    arsenal->create_bow();

    arsenal->create_sword();
    std::cout << std::endl;
    arsenal->create_sword();

    return 0;
}