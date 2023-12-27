#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include <windows.h> 

using namespace std;
void index2() {
    string phrase;
    cout << "Введите фразу: ";
    cin.ignore();
    getline(cin, phrase);

    vector<char> digits;
    for (char c : phrase) {
        if (isdigit(c)) {
            digits.push_back(c);
        }
    }

    if (!digits.empty()) {
        int start_index, end_index;
        cout << "Введите начальный индекс: ";
        cin >> start_index;
        cout << "Введите конечный индекс: ";
        cin >> end_index;

        if (start_index <= end_index && end_index <= digits.size()) {
            vector<char> digit_range(digits.begin() + start_index - 1, digits.begin() + end_index);
            cout << "Диапазон цифр с индекса " << start_index << " по индекс " << end_index << ": ";
            for (char c : digit_range) {
                cout << c;
            }
            cout << endl;
        }
        else {
            cout << "Некорректный диапазон индексов." << endl;
        }
    }
    else {
        cout << "В указанной фразе нет цифр." << endl;
    }
    return;
}

void index1() {
    string phrase;
    cout << "Введите фразу: ";
    cin.ignore();
    getline(cin, phrase);

    string digits;
    for (char c : phrase) {
        if (isdigit(c)) {
            digits += c;
        }
    }

    int numDigits = digits.size();
    if (numDigits == 0) {
        cout << "Во введенной фразе нет цифр." << endl;
        return ;
    }

    int index;
    cout << "Введите номер цифры, которую требуется вывести: ";
    cin >> index;

    if (index < 1 || index > numDigits) {
        cout << "Некорректный номер цифры." << endl;
        return ;
    }

    cout << "Цифрой номер " << index << " является " << digits[index - 1] << "." << endl;

    return ;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int o;
    cout << "конкретный номер индекса - то нажмите 1; областью - то нажмите 2 ";
    cin >> o;
    if (o == 1) {
        index1();
    }
    else if (o == 2) {
        index2();
    }
    else {
        cout << "Ошибка! цифра должна быть равна 1 или 2"; 
    }
    return 0;
}