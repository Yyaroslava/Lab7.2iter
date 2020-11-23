// ћороз ярослава 
// Ћабораторна робота є 7.2iter
// ¬ар≥ант 10 
// ≤терац≥йний спос≥б

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int** M, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** M, const int rowCount, const int colCount);
int GetSumMax(int** M, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));

    int Low = -26;
    int High = 23;

    int rowCount = 7; // к≥льк≥сть р€дк≥в
    int colCount = 5; // к≥льк≥сть стовпчик≥в

    int** M = new int* [rowCount];
    for (int row = 0; row < rowCount; row++) M[row] = new int[rowCount];

    Create(M, rowCount, colCount, Low, High);
    Print(M, rowCount, colCount);

    int sumMax = GetSumMax(M, rowCount, colCount); // sumMax -  сума елемент≥в з макс.значенн€м по непарних стовпц€х
    cout << "sum of max elements of odd columns = " << sumMax << endl;
    
    for (int row = 0; row < rowCount; row++) delete[] M[row];
    delete[] M;

    return 0;
}

void Create(int** M, const int rowCount, const int colCount, const int Low, const int High) {
    for (int row = 0; row < rowCount; row++)
        for (int col = 0; col < colCount; col++) M[row][col] = Low + rand() % (High - Low + 1);
}

void Print(int** M, const int rowCount, const int colCount) {
    cout << endl;
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) cout << setw(4) << M[row][col];
        cout << endl;
    }
    cout << endl;
}

//int** M - посиланн€ на масив посилань на масив ц≥лих чисел
int GetSumMax(int** M, const int rowCount, const int colCount) { 
    int result = 0;                                              // result - м≥стить результат суми макс. елемент≥в по непарних стовпц€х
    for (int col = 0; col < colCount; col++) {
        if (col % 2 == 0) continue;
        int max = M[0][col];                                    // max - поточний максимум за стовпцем 
        for (int row = 1; row < rowCount; row++) {
            if (max < M[row][col]) max = M[row][col];
        }
        result += max;
    }
    return result;
}
