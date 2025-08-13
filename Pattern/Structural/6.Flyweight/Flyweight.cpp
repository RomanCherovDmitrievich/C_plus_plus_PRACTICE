#include <iostream>
#include <map>

class SavePlace
{
private:
    std::string place;
public:
    SavePlace(std::string p) : place(p) {}

    void set_place(int position)
    {
        std::cout << "Зона " << place << " это зона отдыха, установлена на позиции: " << position << std::endl;
    }
};

class FightPlace
{
private:
    std::string place;
public:
    FightPlace(std::string p) : place(p) {}

    void set_place(int position)
    {
        std::cout << "Зона " << place << " это зона боевых действий, установлена на позиции: " << position << std::endl;
    }
};

class MapFactory
{
private:
    std::map<std::string, SavePlace*> save_map;
    std::map<std::string, FightPlace*> fight_map;

public:
    SavePlace* getSavePlace(std::string key)
    {
        if(save_map.find(key) == save_map.end())
        {
            save_map[key] = new SavePlace(key);
        }
        return save_map[key];
    }
    FightPlace* getFightPlace(std::string key)
    {
        if(fight_map.find(key) == fight_map.end())
        {
            fight_map[key] = new FightPlace(key);
        }
        return fight_map[key];
    }
};

int main()
{
    MapFactory map;
    int position = 0;
    map.getSavePlace("A")->set_place(position++);
    map.getFightPlace("B")->set_place(position++);
    map.getSavePlace("C")->set_place(position++);

    

    return 0;
}