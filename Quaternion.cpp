#include "Quaternion.h"

using namespace std;

Quaternion::Quaternion(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

void Quaternion::setA(double newA) { a = newA; }
void Quaternion::setB(double newB) { b = newB; }
void Quaternion::setC(double newC) { c = newC; }
void Quaternion::setD(double newD) { d = newD; }

double Quaternion::getA() const { return a; }
double Quaternion::getB() const { return b; }
double Quaternion::getC() const { return c; }
double Quaternion::getD() const { return d; }

void Quaternion::print() const {
    cout << a << " + " << b << "i + " << c << "j + " << d << "k\n";
}

// Норма кватерниона
double Quaternion::norm() const {
    return sqrt(a * a + b * b + c * c + d * d);
}

// Сопряжение кватерниона
Quaternion Quaternion::conjugate() const {
    return Quaternion(a, -b, -c, -d);
}

// Нормализация кватерниона
Quaternion Quaternion::normalize() const {
    double n = norm();
    if (n == 0) throw runtime_error("нельзя нормализовать.");
    return Quaternion(a / n, b / n, c / n, d / n);
}

// Инверсия кватерниона
Quaternion Quaternion::inverse() const {
    double n2 = norm() * norm();
    if (n2 == 0) throw runtime_error("нельзя нормализовать.");
    Quaternion conj = conjugate();
    return Quaternion(conj.getA() / n2, conj.getB() / n2, conj.getC() / n2, conj.getD() / n2);
}

// Расстояние между двумя кватернионами
double Quaternion::distance(const Quaternion& q1, const Quaternion& q2) {
    return sqrt(pow(q1.a - q2.a, 2) + pow(q1.b - q2.b, 2) + pow(q1.c - q2.c, 2) + pow(q1.d - q2.d, 2));
}

// Норма Чебышева между двумя кватернионами
double Quaternion::chebyshevNorm(const Quaternion& q1, const Quaternion& q2) {
    return max({fabs(q1.a - q2.a), fabs(q1.b - q2.b), fabs(q1.c - q2.c), fabs(q1.d - q2.d)});
}

// Операции с кватернионами
Quaternion Quaternion::operator + (const Quaternion& q2) const {
    return Quaternion(a + q2.a, b + q2.b, c + q2.c, d + q2.d);
}

Quaternion Quaternion::operator - (const Quaternion& q2) const {
    return Quaternion(a - q2.a, b - q2.b, c - q2.c, d - q2.d);
}

Quaternion Quaternion::operator * (const Quaternion& q2) const {
    return Quaternion(
        a * q2.a - b * q2.b - c * q2.c - d * q2.d,
        a * q2.b + b * q2.a + c * q2.d - d * q2.c,
        a * q2.c - b * q2.d + c * q2.a + d * q2.b,
        a * q2.d + b * q2.c - c * q2.b + d * q2.a
    );
}

Quaternion Quaternion::operator / (const Quaternion& q2) const {
    return *this * q2.inverse();
}

// Скалярное произведение
double Quaternion::operator * (const Quaternion& q2) const {
    return a * q2.a + b * q2.b + c * q2.c + d * q2.d;
}