#include <iostream>
#include <vector>

class ChatRoom;

class User
{
private:
    std::string name;
    ChatRoom* room;

public:
    User(const std::string& name, ChatRoom* room) : name(name), room(room) {}
    void sendMessage(const std::string& message);
    std::string getName() const 
    {
        return name;
    }
};

class ChatRoom
{
private:
    std::vector<User*> users;

public:
    void addUser(User* user)
    {
        users.push_back(user);
    }
    void broadcast(const std::string& sender, const std::string& message)
    {
        for(User* user : users)
        {
            if(user->getName() != sender)
            {
                std::cout << "[ " << sender << " -> " << user->getName() << " ]: " << message << std::endl;  
            }
        }
    }
};

void User::sendMessage(const std::string& message)
{
    room->broadcast(name, message);
}

int main()
{
    ChatRoom chatroom;
    User alice("Алиса", &chatroom);
    User piter("Питер", &chatroom);
    User bob("Боб", &chatroom);
    User tod("Тод", &chatroom);

    chatroom.addUser(&alice);
    chatroom.addUser(&piter);
    chatroom.addUser(&bob);
    chatroom.addUser(&tod);

    alice.sendMessage("Привет, как дела?");
    piter.sendMessage("Привет, всё супер, как у вас?");
    bob.sendMessage("Добрый день, у меня всё хорошо.");

    return 0;
}