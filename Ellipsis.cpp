#include "Ellipsis.h"

using namespace std;

// Проверка на правильность полуосей
void Ellipsis::validaxes() {
    if (a <= b) {
        throw invalid_argument("Большая полуось (a) должна быть больше малой полуоси (b).");
    }
}

// Вычисление гиперпараметра
void Ellipsis::calculatefocaldistance() {
    c = sqrt(a * a - b * b);
}

// Конструктор по умолчанию
Ellipsis::Ellipsis() {
    validateaxes();
    calculatefocaldistance();
}

// Конструктор с параметрами
Ellipsis::Ellipsis(double a, double b, double h, double k) {
    if (a <= b) {
        swap(this->a, this->b);  // Если a меньше b, меняем местами
    }
    validaxes();
    calculatefocaldistance();
}

// Метод для вычисления гиперпараметра
double Ellipse::getfocaldistance() const {
    return c;
}

// Метод для вычисления координат фокусов
void Ellipse::getfoc() const {
    cout << "F1(" << h - c << ", " << k << "), F2(" << h + c << ", " << k << ")\n";
}

// Метод для вычисления координат вершин
void Ellipse::getvert() const {
    cout << "V1(" << h - a << ", " << k << "), V2(" << h + a << ", " << k << ")\n";
}

// Метод для вычисления площади эллипса
double Ellipse::getarea() const {
    return M_PI * a * b;
}

// Метод для вычисления периметра эллипса (приближенная формула)
double Ellipse::getperimeter() const {
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

// Метод для проверки, находится ли точка внутри эллипса
bool Ellipse::pointinside(double x, double y) const {
    double result = pow((x - h) / a, 2) + pow((y - k) / b, 2);
    return result <= 1;  // Если результат меньше или равен 1, точка внутри эллипса
}

// Метод для вычисления второй координаты по уравнению эллипса
double Ellipse::secondcoordinate(double x) const {
    return k + b * sqrt(1 - pow((x - h) / a, 2));  // Из уравнения эллипса
}

// Методы set и get
void Ellipse::setaxes(double newA, double newB) {
    a = newA;
    b = newB;
    validaxes();
    calculatefocaldistance();
}

void Ellipse::setcenter(double newH, double newK) {
    h = newH;
    k = newK;
}

double Ellipse::getA() const { return a; }
double Ellipse::getB() const { return b; }
double Ellipse::getH() const { return h; }
double Ellipse::getK() const { return k; }

// Печать уравнения эллипса
void Ellipse::print() const {
    cout << "Уравнение эллипса: ((x - " << h << ")^2 / " << a * a << ") + ((y - " << k << ")^2 / " << b * b << ") = 1\n";
}