#include <iostream>
#include <vector>

class ActionCommands
{
public:
    virtual void execute() = 0;
};

class Action
{
public:
    void step_forward()
    {
        std::cout << "Сделал шаг вперёд!" << std::endl;
    }
    void step_back()
    {
        std::cout << "Сделал шаг назад!" << std::endl;
    }
};

class GoAhead : public ActionCommands
{
    Action& act;
public:
    GoAhead(Action& a) : act(a) {}
    void execute() override
    {
        act.step_forward();
    }
};

class GoBack : public ActionCommands
{
    Action& act;
public:
    GoBack(Action& a) : act(a) {}
    void execute() override
    {
        act.step_back();
    }
};

class ControlRobot
{
private:
    std::vector<ActionCommands*> commands;
    
    void robotOn()
    {
        std::cout << "Робот включён" << std::endl;
    }
    void robotOff()
    {
        std::cout << "Робот выключен" << std::endl;
    }
public:
    ControlRobot() {robotOn();}
    void addCommand(ActionCommands* cmd)
    {
        commands.push_back(cmd);
    }
    void pressButton(unsigned long slot)
    {
        if(slot < commands.size())
        {
            commands[slot]->execute();
        }
    }
    ~ControlRobot() {robotOff();}
};

int main()
{
    Action act;
    GoAhead go(act);
    GoBack back(act);

    ControlRobot action;
    action.addCommand(&go);
    action.addCommand(&go);
    action.addCommand(&back);

    action.pressButton(0);
    action.pressButton(1);
    action.pressButton(2);

    return 0;
}

