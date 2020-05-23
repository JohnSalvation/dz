#include <iostream>
#include <cassert>
#include <algorithm>
#define nullptr 0

using namespace std;

class ArrayInt {
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr) { }

ArrayInt(int length): m_length(length) {
    assert(length >= 0);

    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;

    cout << "Введите чисела: " << endl;
    for (int i = 0; i < m_length; i++) {
        cin >> m_data[i];
    }
}

int differentNum() {
    sort(m_data, m_data + m_length);
    return unique (m_data, m_data + m_length) - m_data;
}

~ArrayInt() {
    delete[] m_data;
}
};

int main() {
    setlocale(0, "");
    int amount = 0;
    cout << "Введите количество чисел: " << endl;
    cin >> amount;
    ArrayInt arr(amount);
    cout << "Different numbers - " << arr.differentNum() << endl;
return 0;
}
