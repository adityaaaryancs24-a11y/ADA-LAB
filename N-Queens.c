#include <stdio.h>

#define MAX 10

int board[MAX][MAX];
int n;

void printBoard() {
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i, j;

    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }

    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    for(i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

int solveNQueens(int row) {
    int col;

    if(row == n) {
        printBoard();
        return 1;
    }

    for(col = 0; col < n; col++) {

        if(isSafe(row, col)) {

            board[row][col] = 1;

            solveNQueens(row + 1);

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &n);

    solveNQueens(0);

    return 0;
}
