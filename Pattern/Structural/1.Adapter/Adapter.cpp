#include <iostream>

class EuropeanOutlet
{
public:
    void give_power(const std::string& gadget)
    {
        std::cout << "На " << gadget << " подано электричество ";
    }
};

class IConnector
{
public:
    virtual void take_power(const int& vat) = 0;
};

class USBConnector : public IConnector
{
public:
    void take_power(const int& vat) override
    {
        std::cout << "через USB: " << vat << " ват." << std::endl;
    }
};

class MicroUSBConnector : public IConnector
{
public:
    void take_power(const int& vat) override
    {
        std::cout << "через Micro USB: " << vat << " ват." << std::endl;
    }
};

class Adapter
{
private:
    IConnector *connector;
public:
    Adapter(IConnector *gadget)
    {
        connector = gadget;
    }
    void command(const int& vat)
    {
        connector->take_power(vat);
    }
};

int main()
{
    EuropeanOutlet* outlet = new EuropeanOutlet();

    USBConnector* usb_connector = new USBConnector();
    outlet->give_power("ноутбук");
    Adapter *adapter = new Adapter(usb_connector);
    adapter->command(20);
    delete adapter;

    MicroUSBConnector* micro_usb_connector = new MicroUSBConnector();
    outlet->give_power("телефон");
    adapter = new Adapter(micro_usb_connector);
    adapter->command(5);
    delete adapter;

    return 0;
}




