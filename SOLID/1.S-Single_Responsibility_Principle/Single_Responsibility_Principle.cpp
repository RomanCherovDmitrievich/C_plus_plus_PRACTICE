#include <iostream>
#include <fstream>


class Not_true_Lesson
{
private:
    std::string lesson;
    std::string sport;
    std::string file;
public:
    void set_sport(std::string _sport)
    {
        sport = _sport;
    }
    void set_lessons(std::string _lesson)
    {
        lesson = _lesson;
    }
    void sport_section(std::string student)
    {
        file = "Not_true_" + sport + ".txt";
        std::ofstream section_list(file);
        section_list << "Ученик " << student << " добавлен в секцию " << sport;
    }

    void lessons_student(std::string student)
    {
        std::cout << "Расписание ученика " << student << " на день: " << std::endl;
        std::cout << "Сегодня у ученика " << lesson << std::endl;
    }

};

void not_true_main()
{
    Not_true_Lesson ntl;
    ntl.set_sport("Football");
    ntl.set_lessons("Математика");
    ntl.sport_section("Ivan");
    ntl.lessons_student("Ivan");
}

class true_Lesson
{
private:
    std::string lesson;
public:
    void set_lessons(std::string _lesson)
    {
        lesson = _lesson;
    }
    void lessons_student(std::string student)
    {
        std::cout << "Расписание ученика " << student << " на день: " << std::endl;
        std::cout << "Сегодня у ученика " << lesson << std::endl;
    }

};

class Sport
{
private:
    std::string sport;
    std::string file;
public:
    void set_sport(std::string _sport)
    {
        sport = _sport;
    }
    void sport_section(std::string student)
    {
        file = "True_" + sport + ".txt";
        std::ofstream section_list(file);
        section_list << "Ученик " << student << " добавлен в секцию " << sport;
    }
};

void true_main()
{
    true_Lesson tl;
    Sport s;

    tl.set_lessons("Математика");
    tl.lessons_student("Ivan");

    s.set_sport("Football");
    s.sport_section("Ivan");
}


int main()
{
    not_true_main();
    true_main();

    return 0;
}