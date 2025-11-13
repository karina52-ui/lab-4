#include <iostream>
#include <cmath>
using namespace std;

// ===== Integer9 =====
// Дано тризначне число. Використовуючи одну операцію цілочисельного ділення,
// вивести першу цифру (сотні).
void Integer9() {
    int number;
    cout << "Введіть тризначне число: ";
    cin >> number;
    cout << "Перша цифра (сотні): " << number / 100 << endl;
}

// ===== Proc9 =====
// Процедура AddLeftDigit(D, K): додає цифру D зліва до числа K
void AddLeftDigit(int D, int &K) {
    int temp = K;
    int multiplier = 1;
    while (temp > 0) {
        multiplier *= 10;
        temp /= 10;
    }
    K = D * multiplier + K;
}

void Proc9() {
    int D1, D2, K;
    cout << "Введіть початкове число K (0 < K < 1000): ";
    cin >> K;
    cout << "Введіть цифру D1 (1-9): ";
    cin >> D1;
    AddLeftDigit(D1, K);
    cout << "Після додавання D1: " << K << endl;
    cout << "Введіть цифру D2 (1-9): ";
    cin >> D2;
    AddLeftDigit(D2, K);
    cout << "Після додавання D2: " << K << endl;
}

// Proc48
// Функція IsRightTriangle(a, b, c): перевіряє, чи трикутник прямокутний
bool IsRightTriangle(double a, double b, double c) {
    double maxSide = max(a, max(b, c));
    if (maxSide == a)
        return fabs(a * a - (b * b + c * c)) < 1e-9;
    else if (maxSide == b)
        return fabs(b * b - (a * a + c * c)) < 1e-9;
    else
        return fabs(c * c - (a * a + b * b)) < 1e-9;
}

void Proc48() {
    cout << "Перевірка трьох наборів сторін трикутників:\n";
    for (int i = 1; i <= 3; i++) {
        double a, b, c;
        cout << "Набір #" << i << " (введіть a b c): ";
        cin >> a >> b >> c;
        if (IsRightTriangle(a, b, c))
            cout << " -> Прямокутний трикутник " << endl;
        else
            cout << " -> НЕ прямокутний " << endl;
    }
}

// ===== Основна програма =====
int main() {
    int choice;
    do {
        cout << "\n=== Меню ===\n";
        cout << "1. Integer9 (перша цифра тризначного числа)\n";
        cout << "2. Proc9 (додавання цифр зліва)\n";
        cout << "3. Proc48 (перевірка прямокутних трикутників)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: Integer9(); break;
            case 2: Proc9(); break;
            case 3: Proc48(); break;
            case 0: cout << "Вихід з програми...\n"; break;
            default: cout << "Невірний вибір, спробуйте ще раз.\n"; break;
        }
    } while (choice != 0);

    return 0;
}