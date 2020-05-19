#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Fraction {
    int num;
    int denom;
public:
    Fraction(int n = 1, int d = 1) : num(n), denom(d) {
        if(d == 0) {
            cout << "Denominator is equal to zero\n"; exit(1);
        }
    }

    Fraction operator+(Fraction b) {
        int d = denom * b.denom;
        int n = num * b.denom + b.num * denom;
        Fraction sum(n, d);
        return sum;
    }
    Fraction operator-(Fraction b) {
        int d = denom * b.denom;
        int n = num * b.denom - b.num * denom;
        Fraction minus(n, d);
        return minus;
    }
    Fraction operator*(Fraction b) {
        int n = num * b.num;
        int d = denom * b.denom;
        Fraction mult(n, d);
        return mult;
    }
    Fraction operator/(Fraction b) {
        int temp = b.num;
        b.num = b.denom;
        b.denom = temp;
        int n = num * b.num;
        int d = denom * b.denom;
        Fraction div(n, d);
        return div;
    }
    Fraction operator-() {
        return Fraction(-num, denom);
    }
    bool operator==(Fraction b) {
        return (num == b.num && denom == b.denom);
    }
    bool operator!=(Fraction b) {
        return (num != b.num || denom != b.denom);
    }
    bool operator>(Fraction b) {
        int n = num * b.denom;
        int nb = b.num * denom;
        return (n > nb);
    }
    bool operator>=(Fraction b) {
        int n = num * b.denom;
        int nb = b.num * denom;
        return (n >= nb);
    }
    bool operator<(Fraction b) {
        int n = num * b.denom;
        int nb = b.num * denom;
        return !(n > nb);
    }
    bool operator<=(Fraction b) {
        int n = num * b.denom;
        int nb = b.num * denom;
        return !(n >= nb);
    }
    void print() {
        cout << num << '/' << denom << endl;
}

};

int main() {
    Fraction fr12(1, 2);
    Fraction fr13(1, 3);
    Fraction fs, fminus, fmult, fdiv, funo;
    fs = fr12 + fr13;
    fminus = fr12 - fr13;
    fmult = fr12 * fr13;
    fdiv = fr12 / fr13;
    funo = -fr12;
    cout << "1/2 + 1/3 = "; fs.print();
    cout << "1/2 - 1/3 = "; fminus.print();
    cout << "1/2 * 1/3 = "; fmult.print();
    cout << "1/2 / 1/3 = "; fdiv.print();
    cout << "1/2 * -1 = ";funo.print();
    if (fr12 == fr13)
    cout << "1/2 == 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 == 1/3 - " << "No" << endl;
    if (fr12 != fr13)
    cout << "1/2 != 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 != 1/3 - " << "No" << endl;
    if (fr12 > fr13)
    cout << "1/2 > 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 > 1/3 - " << "No" << endl;
    if (fr12 >= fr13)
    cout << "1/2 >= 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 >= 1/3 - " << "No" << endl;
    if (fr12 < fr13)
    cout << "1/2 < 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 < 1/3 - " << "No" << endl;
    if (fr12 <= fr13)
    cout << "1/2 <= 1/3 - " << "Yes" << endl;
    else
    cout << "1/2 <= 1/3 - " << "No" << endl;
return 0;
}
