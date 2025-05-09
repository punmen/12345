/*Design and implement C/C++ Program for N Queen's problem using Backtracking.*/
#include <stdio.h>
#define N 4

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
}

int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return 0;
    return 1;
}

int solveNQueens(int board[N][N], int col) {
    if (col >= N) return 1;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1)) return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[N][N] = {0};
    if (solveNQueens(board, 0))
        printBoard(board);
    else
        printf("Solution does not exist\n");
    return 0;
}