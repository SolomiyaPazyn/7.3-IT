#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int SumColumnsWithoutNegative(int** a, const int rowCount, const int colCount);
void MinSumOfParallelDiagonals(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 14;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    
    Input(a, rowCount, colCount); 
    Print(a, rowCount, colCount);

    int sum = SumColumnsWithoutNegative(a, rowCount, colCount);
    cout << "Sum of elements in columns without negative elements = " << sum << endl;

    MinSumOfParallelDiagonals(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumColumnsWithoutNegative(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) {
            for (int i = 0; i < rowCount; i++)
                sum += a[i][j];
        }
    }
    return sum;
}

void MinSumOfParallelDiagonals(int** a, const int rowCount, const int colCount) {
    int minSum = INT_MAX;
    // Проходимо по всіх можливих паралельних діагоналях
    for (int d = -rowCount + 1; d < colCount; d++) {
        int absSum = 0;
        for (int i = 0; i < rowCount; i++) {
            int j = d + i; 
            // Перевіряємо чи елемент входить в межі матриці
            if (j >= 0 && j < colCount) {
                absSum += abs(a[i][j]);
            }
        }
        if (absSum < minSum) {
            minSum = absSum;
        }
    }
    cout << "Minimum sum of absolute values on diagonals parallel to the secondary diagonal = " << minSum << endl;
}