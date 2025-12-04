#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

// PROC9
void AddLeftDigit(int D, int& K) {
    int mult = 1;
    int temp = K;

    while (temp > 0) {
        mult *= 10;
        temp /= 10;
    }

    K = D * mult + K;
}

// PROC48
bool IsRightTriangle(double a, double b, double c) {
    double x = a, y = b, z = c;

    if (x > y) swap(x, y);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);

    return fabs(x * x + y * y - z * z) < 1e-9;
}

// INTEGER9 — 3 функції

int InputThreeDigit() {
    int n;
    do {
        cout << "Введiть тризначне число (100–999): ";
        cin >> n;
        if (n < 100 || n > 999) {
            cout << "Помилка! Число повинно бути тризначним.\n";
        }
    } while (n < 100 || n > 999);
    return n;
}

int GetHundreds(int n) {
    return n / 100;
}

void OutputHundreds(int h) {
    cout << "Перша цифра (сотнi): " << h << endl;
}

int main() {
    setlocale(LC_ALL, "ukr");

    // Proc9
    cout << "Proc9\n";
    int K, D1, D2;

    cout << "Введiть число K (0 < K < 1000): ";
    cin >> K;
    cout << "Введiть цифру D1 (1–9): ";
    cin >> D1;
    cout << "Введiть цифру D2 (1–9): ";
    cin >> D2;

    AddLeftDigit(D1, K);
    cout << "Пiсля додавання D1: " << K << endl;

    AddLeftDigit(D2, K);
    cout << "Пiсля додавання D2: " << K << endl;

    // Proc48
    cout << "\nProc48\n";
    for (int i = 1; i < 4; i++) {
        double a, b, c;
        cout << "Введiть сторону a трикутника #" << i << ": ";
        cin >> a;
        cout << "Введiть сторону b трикутника #" << i << ": ";
        cin >> b;
        cout << "Введiть сторону c трикутника #" << i << ": ";
        cin >> c;

        if (IsRightTriangle(a, b, c))
            cout << "Це прямокутний трикутник.\n";
        else
            cout << "Це НЕ прямокутний трикутник.\n";
    }

    // Integer9
    cout << "\nInteger9\n";
    int n = InputThreeDigit();
    int h = GetHundreds(n);
    OutputHundreds(h);

    system("pause");
    return 0;
}