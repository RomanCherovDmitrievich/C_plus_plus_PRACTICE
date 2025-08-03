#include <iostream>

class NotMySQLDataBase
{
public:
    void save_order(const std::string& order)
    {
        std::cout << "Неверный вариант: Сохранено в MySQL: " << order << std::endl;
    }
};

class NotOrderService
{
private:
    NotMySQLDataBase notdb;

public:
    void create_order(const std::string& order)
    {
        notdb.save_order(order);
    }
};

void not_true_main()
{
    NotOrderService ns;
    ns.create_order("Order1");
}

class IDataBase
{
public:
    virtual void save_order(const std::string& order) = 0;
    virtual ~IDataBase() = default;
};

// Конкретная реализация для MySQL
class MySQLDataBase : public IDataBase
{
    void save_order(const std::string& order) override
    {
        std::cout << "Верный вариант: Запись была сохранена в MySQL: " << order << std::endl;
    }
};
// Конкретная реализация для PostgreSQL
class PostgreSQLDataBase : public IDataBase
{
    void save_order(const std::string& order) override
    {
        std::cout << "Верный вариант: Запись была сохранена в PostgreSQL: " << order << std::endl;
    }
};
// Класс бизнес-логики, зависящий от абстракции
class OrderService
{
private:
    IDataBase* db; // Зависимость от интерфейса, а не от конкретного класса

public:
    OrderService(IDataBase* database) : db(database) {}  // Внедрение зависимости (DI)
    void createOrder(const std::string& orderData) {
        db->save_order(orderData);
    }
};

void true_main()
{
    MySQLDataBase mysqldb;
    PostgreSQLDataBase psqldb;

    OrderService OrderServiceMySQL(&mysqldb);
    OrderServiceMySQL.createOrder("Order1");

    OrderService OrderServicePostgreSQL(&psqldb);
    OrderServicePostgreSQL.createOrder("Order2");
}

int main()
{
    not_true_main();
    true_main();

    return 0;
}