#include <iostream>
#include <string>

// Абстракція для сервісу повідомлень
class IMessageService {
public:
    virtual void sendMessage(const std::string& message) = 0;
    virtual ~IMessageService() {}
};

// Реалізація сервісу повідомлень через електронну пошту
class EmailService : public IMessageService {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

// Реалізація сервісу повідомлень через SMS
class SMSService : public IMessageService {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

// Клас, що використовує сервіс повідомлень
class Notification {
private:
    IMessageService* messageService; // Залежність від абстракції
public:
    Notification(IMessageService* service) : messageService(service) {}
    
    void notify(const std::string& message) {
        messageService->sendMessage(message); // Використання абстракції
    }
};

int main() {
    EmailService emailService;
    SMSService smsService;

    // Використання електронної пошти для повідомлень
    Notification emailNotification(&emailService);
    emailNotification.notify("Hello via Email!");

    // Використання SMS для повідомлень
    Notification smsNotification(&smsService);
    smsNotification.notify("Hello via SMS!");

    return 0;
}
