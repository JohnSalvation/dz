#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

class Converter{
private:
    vector<int> a;
    vector<int> c;
    vector<int> sum;
    int iriginal;
    int iriginal2;
    int iriginal3;
    int baseResult;
public:
    Converter(string str, string str2, int original, int original2, int b_result) {
        this->iriginal = original;
        for (int i = 0; i < str.length(); i++) {
            this->a.push_back(charToInt(str[i]));
        }
        this->iriginal2 = original2;
        for (int j = 0; j < str2.length(); j++) {
            this->c.push_back(charToInt(str2[j]));
        }
        this->iriginal3 = 10;
        this->baseResult = b_result;
    }

int charToInt(char c) {
    if (c >= '0' && c <= '9' && (c - '0') < this->iriginal) {
        return c - '0';
    } else {
        if (c >= 'A' && c <= 'Z' && (c - 'A') < this->iriginal) {
            return c - 'A' + 10;
        } else {
	    cout << "Error! False number!" << endl;
            exit(1);
        }
    }
}

char intToChar(int c) {
    if (c >= 0 && c <= 9) {
        return c + '0';
    } else {
        return c + 'A' - 10;
    }
}

int nextNumber(int final, char v) {
    int temp = 0;
    if (v == 'a') {	
    for (int i = 0; i < this->a.size(); i++) {
        temp = temp *this->iriginal + this->a[i];
        a[i] = temp / final;
        temp = temp % final;
    }
    return temp;
}
    if (v == 'c') {
    for (int i = 0; i < this->c.size(); i++) {
    temp = temp *this->iriginal2 + this->c[i];
    c[i] = temp / final;
    temp = temp % final;
    }
    return temp;
}
    if (v == 's') {
    for (int i = 0; i < this->sum.size(); i++) {
    temp = temp *this->iriginal3 + this->sum[i];
    sum[i] = temp / final;
    temp = temp % final;
    }
    return temp;
}
}

bool zero(char v) {
    if (v == 'a') {	
    for (int i = 0; i < this->a.size(); i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}
    if (v == 'c') {
    for (int i = 0; i < this->c.size(); i++) {
        if (c[i] != 0) {
            return false;
        }
    }
    return true;
}
    if (v == 's') {
    for (int i = 0; i < this->sum.size(); i++) {
        if (sum[i] != 0) {
            return false;
        }
    }
    return true;
}
}

string convert() {
    int final = 10;
    vector<int> b;
    vector<int> d;
    vector<int> sum;
    int size = 0;
    int size2 = 0;
    int size_sum = 0;
    int rez = 0;
    do {
        b.push_back(this->nextNumber(final, 'a'));
        size++;
    } while(!this->zero('a'));

    int decimal = 1;
    int total = 0;
    for (int i = 0; i < b.size(); ++i) {
    total += i * decimal;
    decimal *= 10;
    }

    do {
        d.push_back(this->nextNumber(final, 'c'));
        size2++;
    } while(!this->zero('c'));
    int dec = 1;
    int total2 = 0;
    for (int i = 0; i < d.size(); ++i) {
    total2 += i * dec;
    dec *= 10;
    }

    rez = total + total2;

    stringstream ss;
    ss << rez;
    string str = ss.str();
    for (int i = 0; i < str.size(); i++) {
        this->sum.push_back(charToInt(str[i]));
    }

    do {
        sum.push_back(this->nextNumber(baseResult, 's'));
        size_sum++;
    } while(!this->zero('s'));

    string sTemp="";
    for (int i = sum.size()-1; i >= 0; i--) {
        sTemp += intToChar(sum[i]);
    }
    return sTemp;
}
};

int main() {
    Converter num1("HELLO", "FF", 36, 16, 2);
    cout << endl;
    cout << num1.convert() << endl;
    Converter num2("10", "10", 10, 10, 10);
    cout << num2.convert() << endl;
return 0;
}

