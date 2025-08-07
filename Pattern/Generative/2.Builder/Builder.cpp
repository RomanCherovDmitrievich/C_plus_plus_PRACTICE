#include <iostream>

class Computer // Product class
{
private:
    std::string cpu;
    std::string memory;
    std::string os;

public:
    void setCPU(const std::string _cpu)
    {
        cpu = _cpu;
    }
    void setMemory(const std::string _memory)
    {
        memory = _memory;
    }
    void setOS(const std::string _os)
    {
        os = _os;
    }
    void info()
    {
        std::cout << "CPU: " << cpu << std::endl << "Memory: " << memory << std::endl << "OS: " << os << std::endl;
    }
};

class IComputerWizard // Builder interface
{
public:
    virtual void buildCPU(const std::string& cpu) = 0;
    virtual void buildMemory(const std::string& memory) = 0;
    virtual void buildOS(const std::string& storage) = 0;
    virtual Computer getResult() = 0;
};

class ComputerWizard : public IComputerWizard // Concrete Builder
{
private:
    Computer computer;

public:
    ComputerWizard() {
        computer = Computer();
    }

    void buildCPU(const std::string& cpu) override {
        computer.setCPU(cpu);
    }

    void buildMemory(const std::string& memory) override {
        computer.setMemory(memory);
    }

    void buildOS(const std::string& storage) override {
        computer.setOS(storage);
    }

    Computer getResult() override {
        return computer;
    }
};

class ComputerAssembler // Director
{
public:
    Computer assembleComputer(ComputerWizard& builder)
    {
        builder.buildCPU("Intel i7");
        builder.buildMemory("1024 GB");
        builder.buildOS("Mac OS");
        return builder.getResult();
    }
};

int main()
{
    ComputerWizard computer;
    ComputerAssembler assembler;

    Computer info = assembler.assembleComputer(computer);

    std::cout << "Характеристики компьютера: " << std::endl;
    info.info();
}
