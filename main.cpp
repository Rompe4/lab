#include <iostream>
#include "Ellipsis.h"

int main() {
        Ellipsis ellipse(5.0, 3.0);
        Ellipsis.print();
        Ellipsis.getfoc();
        Ellipsis.getvert();
        cout << "Площадь эллипса: " << Ellipsis.getarea() << endl;
        cout << "Периметр эллипса: " << Ellipsis.getperimeter() << endl;

        double x = 3.0, y = 4.0;
        cout << "Точка (" << x << ", " << y << ") " << (Ellipsis.pointinside(x, y) ? "внутри" : "снаружи") << " эллипса.\n";

        cout << "Вторая координата при x = " << x << ": y = " << Ellipsis.secondcoordinate(x) << "\n";
}