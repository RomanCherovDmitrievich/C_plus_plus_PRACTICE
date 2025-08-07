#include <iostream>

class Steps
{
public:
    void steps()
    {
        step1();
        step2();
        step3();
        step4();
        step5();
        step6();
    }
    virtual ~Steps() = default;
protected:
    virtual void step6() = 0;
    virtual void step4() = 0;
    virtual void step2() = 0;
    void step1()
    {
        std::cout << "Вы продвинулись на 1 клетку" << std::endl;
    }
    void step3()
    {
        std::cout << "Вы продвинулись на 3 клетки" << std::endl;
    }
    void step5()
    {
        std::cout << "Вы продвинулись на 5 клеток" << std::endl;
    }
};

class LuckyStep : public Steps
{
protected:
    void step2() override 
    {
        std::cout << "Удача! Вы продвинулись на 4 клетки" << std::endl;
    }
    void step4() override 
    {
        std::cout << "Удача! Вы продвинулись на 8 клеток" << std::endl;
    }
    void step6() override 
    {
        std::cout << "Удача! Вы продвинулись на 12 клеток" << std::endl;
    }
};

int main()
{
    LuckyStep ls;
    ls.steps();

    return 0;
}