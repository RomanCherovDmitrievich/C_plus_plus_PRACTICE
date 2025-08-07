#include <iostream>

class Answer
{
protected:
    Answer* answer_next;

public:
    Answer() : answer_next(nullptr) {}
    void serNext(Answer* next)
    {
        answer_next = next;
    }
    virtual void write_answer(const std::string& answer_question) = 0;
};

class AnswerA : public Answer
{
public:
    void write_answer(const std::string& answer_question) override
    {
        if(answer_question == "A")
        {
            std::cout << "Ответ от пользователя A: " << answer_question << std::endl;
        }
        else if(answer_next)
        {
            answer_next->write_answer(answer_question);
        }
    }
};

class AnswerB : public Answer
{
public:
    void write_answer(const std::string& answer_question) override
    {
        if(answer_question == "B")
        {
            std::cout << "Ответ от пользователя B: " << answer_question << std::endl;
        }
        else if(answer_next)
        {
            answer_next->write_answer(answer_question);
        }
    }
};

int main()
{
    AnswerA anA;
    AnswerB anB;
    anA.serNext(&anB);

    std::cout << "Вопрос для пользователя A?" << std::endl;
    anA.write_answer("A");


    std::cout << "Вопрос для пользователя B?" << std::endl;
    anA.write_answer("B");

    std::cout << "Вопрос для пользователя C?" << std::endl;
    anA.write_answer("C");

    return 0;
}