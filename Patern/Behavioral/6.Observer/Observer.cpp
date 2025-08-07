#include <iostream>
#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update(const std::string& action) = 0;
};

class Action
{
private:
    std::vector<Observer*> observes;

public:
    void attach(Observer* obs)
    {
        observes.push_back(obs);
    }
    void detach(Observer* obs)
    {
        observes.erase(std::remove(observes.begin(), observes.end(), obs), observes.end());
    }
    void notify(const std::string action)
    {
        for(auto obs : observes)
            obs->update(action);
    }
};

class Human : public Observer
{
private:
    std::string name;

public:
    Human(const std::string& act) : name(act) {}
    void update(const std::string& action) override
    {
        std::cout << name << " получил: " << action << std::endl;
    }
};

int main()
{
    Action a;
    Human h1("1-й наблюдатель");
    Human h2("2-й наблюдатель");

    a.attach(&h1);
    a.attach(&h2);

    a.notify("Привет, наблюдатель");

    a.detach(&h1);
    a.notify("1-го наблюдателя отключили");

    return 0;
}