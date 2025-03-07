#include <iostream>
#include "Quaternion.h"

using namespace std;

int main() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    cout << "q1: "; q1.print();
    cout << "q2: "; q2.print();

    Quaternion q3 = q1 + q2;
    cout << "q1 + q2: "; q3.print();

    Quaternion q4 = q1 - q2;
    cout << "q1 - q2: "; q4.print();

    Quaternion q5 = q1 * q2;
    cout << "q1 * q2: "; q5.print();

    Quaternion q6 = q1 / q2;
    cout << "q1 / q2: "; q6.print();

    cout << "Norm q1: " << q1.norm() << endl;
    cout << "спряжение q1: "; q1.conjugate().print();

    Quaternion q7 = q1.normalize();
    cout << "Norm q1: "; q7.print();

    cout << "дистанция между q1 и q2: " << Quaternion::distance(q1, q2) << endl;
    cout << "норма Чевыша между q1 и q2: " << Quaternion::chebyshevNorm(q1, q2) << endl;

    return 0;
}