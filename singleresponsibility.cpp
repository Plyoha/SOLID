#include <iostream>
#include <string>

// Клас для обробки даних користувача (логіка роботи з користувачем)
class User {
private:
    std::string name;
public:
    User(const std::string& userName) : name(userName) {}
    
    std::string getName() const {
        return name;
    }
};

// Клас для роботи з базою даних (логіка збереження даних)
class UserRepository {
public:
    void saveUser(const User& user) {
        // Емуляція збереження користувача в базу даних
        std::cout << "Saving user " << user.getName() << " to database." << std::endl;
    }
};

// Клас для логування (логіка запису в лог)
class Logger {
public:
    void log(const std::string& message) {
        // Емуляція запису повідомлення в лог
        std::cout << "Log: " << message << std::endl;
    }
};

int main() {
    User user("John Doe");
    UserRepository userRepository;
    Logger logger;

    // Використання класів згідно з їхньою відповідальністю
    userRepository.saveUser(user);
    logger.log("User " + user.getName() + " has been saved.");

    return 0;
}
