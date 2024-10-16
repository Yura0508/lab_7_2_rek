// lab_7_2_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i);
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min);
void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int Low = 1;
    int High = 100;
    int rows, cols;

    cout << "Enter number of rows (k): ";
    cin >> rows;
    cout << "Enter number of columns (n): ";
    cin >> cols;


    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    // Create the matrix
    Create(a, rows, cols, Low, High, 0, 0);
    cout << "Generated Matrix:" << endl;
    Print(a, rows, cols, 0);


    int max;
    MaxMinRows(a, rows, cols, 0, max);
    cout << "Largest of the minimum elements from each row = " << max << endl;


    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;
    cin.get();
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i) {
    if (i < rowCount) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
        Print(a, rowCount, colCount, i + 1);
    }
}

void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min)
{
    if (a[rowNo][colNo] < min)
        min = a[rowNo][colNo];
    if (colNo < colCount - 1)
        MinRow(a, rowNo, colCount, colNo + 1, min);
}

void MaxMinRows(int** a, const int rowCount, const int colCount, int rowNo, int& max) {
    int min = a[rowNo][0];
    MinRow(a, rowNo, colCount, 1, min);
    if (rowNo == 0)
        max = min;
    if (min > max)
        max = min;
    if (rowNo < rowCount - 1)
        MaxMinRows(a, rowCount, colCount, rowNo + 1, max);
}
