# 2. Command (Команда)
__Суть:__
Инкапсулирует запрос в виде объекта, позволяя параметризовать клиенты с разными запросами, ставить их в очередь или поддерживать отмену операций.

## Пример
```c++
#include <iostream>
#include <vector>

class Command {
public:
    virtual void execute() = 0;
};

class Light {
public:
    void on() { std::cout << "Light is ON\n"; }
    void off() { std::cout << "Light is OFF\n"; }
};

class LightOnCommand : public Command {
    Light& light;
public:
    LightOnCommand(Light& l) : light(l) {}
    void execute() override { light.on(); }
};

class LightOffCommand : public Command {
    Light& light;
public:
    LightOffCommand(Light& l) : light(l) {}
    void execute() override { light.off(); }
};

class RemoteControl {
    std::vector<Command*> commands;
public:
    void addCommand(Command* cmd) { commands.push_back(cmd); }
    void pressButton(int slot) {
        if (slot < commands.size()) commands[slot]->execute();
    }
};

int main() {
    Light light;
    LightOnCommand onCmd(light);
    LightOffCommand offCmd(light);

    RemoteControl remote;
    remote.addCommand(&onCmd);
    remote.addCommand(&offCmd);

    remote.pressButton(0);  // Включает свет
    remote.pressButton(1);  // Выключает свет
    return 0;
}
```
## Плюсы:
✅ Отделяет отправителя команды от её исполнителя.
✅ Позволяет реализовать отмену (undo) и повтор (redo).

## Минусы:
❌ Усложняет код из-за множества классов команд.

## Где применяется?
1. GUI (кнопки, меню).
2. Очереди задач (например, в многопоточных приложениях).
3. Транзакции (откат изменений).

