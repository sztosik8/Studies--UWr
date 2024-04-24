#include <stdio.h>

#define N 8

int board[N][N]; // chessboard

// check if the queen placed at board[row][col] is attacking any other queens
int is_attacking(int row, int col)
{
    // check all rows and columns for attacking queens
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] || board[i][col])
        {
            return 1;
        }
    }

    // check diagonal directions for attacking queens
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j == row + col || i - j == row - col) && board[i][j])
            {
                return 1;
            }
        }
    }

    // no attacking queens found
    return 0;
}

// recursive function to place N queens on the chessboard
// so that no two queens are attacking each other
int place_queens(int n)
{
    // if all queens are placed, return 1
    if (n == 0)
    {
        return 1;
    }

    // try all positions for the current queen
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // if the current position is safe, place the queen
            if (!is_attacking(i, j))
            {
                board[i][j] = 1;

                // if placing the queen on the current position leads to
                // a solution, return 1
                if (place_queens(n - 1))
                {
                    return 1;
                }

                // otherwise, backtrack and try the next position
                board[i][j] = 0;
            }
        }
    }

    // no solution found
    return 0;
}

// print the N queens placement on the chessboard
void print_board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // initialize the chessboard
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    // place the queens on the chessboard
    int queens_placed = place_queens(N);

    // print the placement of queens on the chessboard
    if (queens_placed)
    {
        print_board();
    }
    else
    {
        printf("No solution found");
    }

    return 0;
}
