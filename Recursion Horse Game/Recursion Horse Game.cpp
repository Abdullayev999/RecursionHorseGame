#include <iostream>
#include <windows.h>
using namespace std;

int indent = 0;

void print_indent() {
    for (int i = 0; i < indent; i++) {
        cout << ' ';
    }
}


int factorial_demo(int n) {
    Sleep(1000);
    print_indent();
    indent++;
    cout << "factorial(" << n << ");\n";
    if (n == 0) {
        return 1;
    }

    int result = n * factorial_demo(n - 1);

    print_indent();
    Sleep(1000);
    cout << result << "\n";
    indent--;
    return result;
}

int factorial(unsigned int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

void set_cursor(short x, short y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

bool check_coord(int row, int col, int size)
{
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

int x[8] = { 1,2,3,1,-1,-2,-2,-1 };
int y[8] = { -2,-1,1,2,2,1,-1,-2 };

void print(int** arr, int size)
{
    for (int k = 1; k <= 64; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (arr[i][j] == k)
                {
                    Sleep(200);
                    set_cursor(j * 3, i);
                    cout << k;
                    break;
                }
            }
        }
    }
}

bool movie(int** arr, int size, int row, int col, int step = 1)
{
    arr[row][col] = step;
    if (step == size * size)
    {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int next_row = row + y[i];
        int next_col = col + x[i];

        if (check_coord(next_row, next_col, size))
        {
            if (arr[next_row][next_col] == 0)
            {
                if (movie(arr, size, next_row, next_col, step + 1))
                {
                    return true;
                }
            }
        }
    }
    arr[row][col] = 0;
    return false;
}




int main() {
    const int SIZE = 8;
    int** arr = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = new int[SIZE]();
    }

    int row, col;
    cout << "Enter initial row and col: \n";
    cin >> row >> col; // 5-3 OR 1-1 OR ...

    movie(arr, SIZE, row, col);
    system("cls");
    print(arr, SIZE);
}