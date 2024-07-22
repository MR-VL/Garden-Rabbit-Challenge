#include <iostream>
#include <iomanip>

using namespace std;
const int ROWS = 8;
const int COLS = 10;
void fillmatrix(int matrix[ROWS][COLS]);
void displaymatrix(int matrix[ROWS][COLS]);
int eatCarrot(int matrix[ROWS][COLS]);

int main() {
    int garden[ROWS][COLS];
    int totalCarrotsAte = 0;
    fillmatrix(garden);
    cout << "Original matrix: " << endl;
    displaymatrix(garden);

    totalCarrotsAte = eatCarrot(garden);

    cout << "\n\nMatrix after eating:" <<endl;
    displaymatrix(garden);

    cout << "\nThe total carrots ate: " << totalCarrotsAte;
    return 0;
}

void fillmatrix(int matrix[ROWS][COLS]){
    int values[ROWS][COLS] ={
            {10, 15, 9, 7, 6, 4, 3, 2, 1, 12},
            {12, 2, 3, 4, 1, 6, 7, 8, 10, 0},
            {0, 1, 7, 6, 2, 5, 3, 6, 0, 23},
            {4, 9, 0, 5, 12, 14, 2, 4, 4, 2},
            {22, 21, 6, 1, 16, 2, 5, 5, 0, 6},
            {9, 8, 5, 3, 7, 6, 12, 6, 12, 3},
            {10, 2, 0, 6, 8, 9, 14, 22, 13, 15},
            {9, 6, 5, 4, 1, 10, 12, 10, 2, 1}
    };

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = values[i][j];
        }
    }
}

void displaymatrix(int matrix[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(4)<< matrix[i][j];
        }
        cout << endl;
    }
}

int eatCarrot(int matrix[ROWS][COLS]){
    int startRow = ROWS / 2;
    int startCol = COLS /2;

    int totalEaten = 0;

    while(true){
        int maxCarrots = 0;

        int nextRow, nextCol;

        //check up
        if(startRow -1 >=0 && matrix[startRow-1][startCol] > maxCarrots){
            maxCarrots = matrix[startRow-1][startCol];
            nextCol = startCol;
            nextRow = startRow-1;
        }

        //check down
        if(startRow+1 < ROWS && matrix[startRow+1][startCol]>maxCarrots){
            maxCarrots = matrix[startRow+1][startCol];
            nextRow = startRow +1;
            nextCol = startCol;
        }

        //check left
        if(startCol -1 >= 0 && matrix[startRow][startCol-1] > maxCarrots){
            maxCarrots = matrix[startRow][startCol-1];
            nextRow = startRow;
            nextCol = startCol -1;
        }

        //check right
        if(startCol+1 < COLS && matrix[startRow][startCol +1] > maxCarrots){
            maxCarrots = matrix[startRow][startCol+1];
            nextRow = startRow;
            nextCol = startCol+1;
        }

        if(maxCarrots==0){
            break;
        }

        totalEaten += matrix[nextRow][nextCol];
        matrix[nextRow][nextCol]= 0;
        startCol = nextCol;
        startRow = nextRow;


    }
    return totalEaten;
}