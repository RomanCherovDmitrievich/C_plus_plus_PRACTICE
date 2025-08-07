#include <iostream>

class Human
{
private:
    std::string save;

public:
    void setSave(const std::string& s)
    {
        save = s;
    }
    std::string getSave() const
    {
        return save;
    }

    class Conservation
    {
    private:
        std::string state;
        friend class Human;
        Conservation(const std::string& s): state(s) {}
    public:
        std::string getState() const
        {
            return state;
        }
    };

    Conservation createConservation() const
    {
        return Conservation(save);
    }
    void restoreFromSave(const Conservation& c)
    {
        save = c.getState();
    }
};

class Saves
{
private:
    std::vector<Human::Conservation> save;

public:
    void push(const Human::Conservation& s)
    {
        save.push_back(s);
    }
    Human::Conservation pop()
    {
        if(save.empty()) throw std::runtime_error("No mementos");
        auto s = save.back();
        save.pop_back();
        return s;
    }

};

int main()
{
    Human h;
    Saves s;

    h.setSave("Сейф на 1 уровне");
    s.push(h.createConservation());

    h.setSave("Сейф на 2 уровне");
    s.push(h.createConservation());

    h.setSave("Сейф на 3 уровне");
    std::cout << "Текущий сейф: " << h.getSave() << std::endl;

    h.restoreFromSave(s.pop());
    std::cout << "Восстановленный сейф: " << h.getSave() << std::endl;
    h.restoreFromSave(s.pop());
    std::cout << "Восстановленный сейф: " << h.getSave() << std::endl;

    return 0;
}