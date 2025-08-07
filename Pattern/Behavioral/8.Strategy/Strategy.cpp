#include <iostream>

class PaymentStrategy {
public:
    virtual void execute() = 0;
};

class PaymentProcessor {
    PaymentStrategy* strategy;
public:
    void setStrategy(PaymentStrategy* s) 
    {
        strategy = s; 
    }
    void process() 
    {
        strategy->execute(); 
    }
};

class CreditCardStrategy : public PaymentStrategy {
public:
    void execute() override 
    {
        std::cout << "Обработка с помощью кредитной карты" << std::endl; 
    }
};

class PayPalStrategy : public PaymentStrategy {
public:
    void execute() override 
    {
        std::cout << "Обработка через PayPal" << std::endl;; 
    }
};

int main()
{
    // Клиентский код:
    PaymentProcessor processor;
    processor.setStrategy(new CreditCardStrategy());  // Явный выбор
    processor.process();

    processor.setStrategy(new PayPalStrategy());
    processor.process();


    return 0;
}