#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Ітераційне формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Ітераційне виведення масиву
void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// 1. Звичайна функція (пошук найменшого непарного елемента)
int MinOddElement(const int* a, const int size) {
    int minOdd = INT_MAX;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) { // Перевірка на непарність
            if (a[i] < minOdd) {
                minOdd = a[i];
                found = true;
            }
        }
    }

    return found ? minOdd : 0; // Повертаємо 0, якщо непарних немає
}

// 2. Шаблонна функція (універсальний алгоритм)
template <typename T>
T MinOddElement(const T* a, const int size) {
    T minOdd = INT_MAX;
    bool found = false;

    for (int i = 0; i < size; i++) {
        // Приведення до long long для безпечної перевірки остачі від ділення на 2
        if (static_cast<long long>(a[i]) % 2 != 0) {
            if (a[i] < minOdd) {
                minOdd = a[i];
                found = true;
            }
        }
    }

    return found ? minOdd : 0;
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 10;
    const int LOW = -20;
    const int HIGH = 50;

    int a[SIZE];

    Create(a, SIZE, LOW, HIGH);

    cout << "Initial array:" << endl;
    Print(a, SIZE);

    // Виклик звичайної функції
    int minOdd1 = MinOddElement(a, SIZE);

    // Виклик шаблонної функції
    int minOdd2 = MinOddElement<int>(a, SIZE);

    cout << endl;
    if (minOdd1 != 0) {
        cout << "Min odd element (ordinary function): " << minOdd1 << endl;
        cout << "Min odd element (template function): " << minOdd2 << endl;
    }
    else {
        cout << "There are no odd elements in the array." << endl;
    }

    return 0;
}