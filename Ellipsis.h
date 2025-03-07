#ifndef ELLIPSIS_H
#define ELLIPSIS_H

#include <iostream>
#include <cmath>

class Ellipsis {
private:
    double h, k;
    double a, b;
    double c;
    void validaxes();
    void calculatefocaldistance();

public:
    Ellipsis();
    Ellipsis(double a, double b, double h = 0, double k = 0);
    Ellipsis(const Ellipsis& other);
    double getfocaldistance() const;
    void getfoc() const;
    void getvert() const;
    double getarea() const;
    double getperimeter() const;
    bool pointinside(double x, double y) const;
    double secondcoordinate(double x) const;
    void setaxes(double newA, double newB);
    void setcenter(double newH, double newK);

    double getA() const;
    double getB() const;
    double getH() const;
    double getK() const;

    void print() const;
};

#endif // ELLIPSIS_H
