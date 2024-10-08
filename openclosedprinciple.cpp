#include <iostream>
#include <vector>
#include <string>

// Базовий клас для всіх повідомлень
class Message {
public:
    virtual std::string getMessage() const = 0; // Чисто віртуальна функція
    virtual ~Message() {}
};

// Конкретний клас для текстового повідомлення
class TextMessage : public Message {
private:
    std::string text;
public:
    TextMessage(const std::string& msg) : text(msg) {}
    
    std::string getMessage() const override {
        return "Text: " + text;
    }
};

// Конкретний клас для повідомлення з зображенням
class ImageMessage : public Message {
private:
    std::string imagePath;
public:
    ImageMessage(const std::string& path) : imagePath(path) {}
    
    std::string getMessage() const override {
        return "Image: " + imagePath;
    }
};

// Клас, що виводить повідомлення
class MessagePrinter {
public:
    void printMessages(const std::vector<Message*>& messages) const {
        for (const auto& message : messages) {
            std::cout << message->getMessage() << std::endl;
        }
    }
};

int main() {
    // Створення текстових та зображеневих повідомлень
    TextMessage textMsg("Hello, World!");
    ImageMessage imageMsg("/path/to/image.png");

    // Зберігаємо повідомлення у вектор
    std::vector<Message*> messages = { &textMsg, &imageMsg };

    // Виводимо всі повідомлення
    MessagePrinter printer;
    printer.printMessages(messages);

    return 0;
}
