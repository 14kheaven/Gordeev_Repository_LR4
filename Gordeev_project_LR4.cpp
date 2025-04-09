#include <iostream>
#include <cmath>
#include <map>
#include <functional>
#include <string>
using namespace std;

int side1, side2;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
catch (...)
{ return false; }
return true;
}

void enterNumber(int& varLink, string label) {
    string str_input;
    cout << label << " = ";
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " = ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}

void enterSide1() {
cout << "Введите положительное число A: ";
cin >> side1;
cout << endl;
if (side1 <= 0) {
    cout << "Введите положительное число." << endl;
    return enterSide1();
}
cout << "Введеное число A: " << side1 << endl;
}

void enterSide2() {

}

void calcS() {

}

void calcP() {

}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод 1-й стороны прямоугольника", enterSide1}},
        {2, {"Ввод 2-й стороны прямоугольника", enterSide2}},
        {3, {"Площадь прямоугольника", calcS}},
        {4, {"Периметр прямоугольника", calcP}},
    };
int choice = 0;

while (true) {
    cout << "Меню:" << endl;
    for (const auto& item : menu) {
        cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Выход" << endl;
    enterNumber(choice, "Input number of menu: ");
    if (choice == 0) {
        cout << "© 2025 Ilya Gordeev" << endl;
        break;
    }
    cout << endl;
    if (menu.find(choice) != menu.end()) {
        menu[choice].action();
    } else {
        cout << "Некорректный ввод.";
    }
    cout << endl;
}
    return 0;
}