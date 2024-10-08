#include <iostream>
#include <vector>
#include <string>

// Базовий клас для фігур
class Shape {
public:
    virtual double area() const = 0; // Чисто віртуальна функція для обчислення площі
    virtual ~Shape() {}
};

// Клас для прямокутника
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height; // Площа прямокутника
    }
};

// Клас для квадрата, який є підкласом прямокутника
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {} // Викликаємо конструктор прямокутника
};

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl; // Виводимо площу фігури
}

int main() {
    Rectangle rectangle(4.0, 5.0);
    Square square(3.0);

    // Використовуємо об'єкти базового класу і підкласу
    printArea(rectangle); // Виведе: Area: 20
    printArea(square);    // Виведе: Area: 9

    return 0;
}
