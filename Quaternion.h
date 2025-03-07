#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>

class Quaternion {
private:
    double a, b, c, d;  // Компоненты кватерниона (a + bi + cj + dk)

public:
    Quaternion();

    // Конструктор с параметрами
    Quaternion(double a, double b, double c, double d);


    void setA(double newA);
    void setB(double newB);
    void setC(double newC);
    void setD(double newD);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // Печать кватерниона
    void print() const;

    // Норма кватерниона
    double norm() const;

    // Сопряжение кватерниона
    Quaternion conjugate() const;

    // Нормализация кватерниона
    Quaternion normalize() const;

    // Инверсия кватерниона
    Quaternion inverse() const;

    // Расстояние между двумя кватернионами
    static double distance(const Quaternion& q1, const Quaternion& q2);

    // Норма Чебышева между двумя кватернионами
    static double chebyshevNorm(const Quaternion& q1, const Quaternion& q2);

    // Операции с кватернионами
    Quaternion operator + (const Quaternion& q2) const;
    Quaternion operator - (const Quaternion& q2) const;
    Quaternion operator * (const Quaternion& q2) const;
    Quaternion operator / (const Quaternion& q2) const;

    // Скалярное произведение
    double operator * (const Quaternion& q2) const;
};

#endif // QUATERNION_H