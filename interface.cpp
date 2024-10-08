#include <iostream>

// Інтерфейс для пристроїв, які можуть друкувати
class IPrinter {
public:
    virtual void print(const std::string& document) = 0;
    virtual ~IPrinter() {}
};

// Інтерфейс для пристроїв, які можуть сканувати
class IScanner {
public:
    virtual void scan(const std::string& document) = 0;
    virtual ~IScanner() {}
};

// Клас для багатофункціонального пристрою, який реалізує обидва інтерфейси
class MultiFunctionPrinter : public IPrinter, public IScanner {
public:
    void print(const std::string& document) override {
        std::cout << "Printing: " << document << std::endl;
    }

    void scan(const std::string& document) override {
        std::cout << "Scanning: " << document << std::endl;
    }
};

// Клас для простого принтера, який реалізує тільки інтерфейс принтера
class SimplePrinter : public IPrinter {
public:
    void print(const std::string& document) override {
        std::cout << "Simple Printer: Printing: " << document << std::endl;
    }
};

int main() {
    MultiFunctionPrinter mfp;
    mfp.print("Multi-function document");
    mfp.scan("Multi-function document");

    SimplePrinter sp;
    sp.print("Simple document");

    return 0;
}
