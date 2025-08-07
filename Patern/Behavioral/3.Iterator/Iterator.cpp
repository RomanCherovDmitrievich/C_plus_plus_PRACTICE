#include <iostream>
#include <vector>

template<typename T>
class Iterator
{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() = default;
};

template<typename T>
class Storehouse : public Iterator<T>
{
private:
    std::vector<T> data;
    size_t index = 0;
public:
    Storehouse(const std::vector<T>& vec) : data(vec) {}
    T next() override
    {
        return data[index++];
    }
    bool hasNext() override
    {
        return index < data.size();
    }
    ~Storehouse() {}
};

int main()
{
    std::vector<std::string> toy = {"Ниндзя", "Танк", "Лодка", "Кукла", "Пушка"};
    Storehouse<std::string> it(toy);    

    std::cout << "Все игрушки на складе: " << std::endl;
    while(it.hasNext())
    {
        std::cout << it.next() << std::endl;
    }
    
    return 0;
}
