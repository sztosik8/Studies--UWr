#include <stdio.h>
#include <stdbool.h>

// funkcja sprawdzająca, czy plansza jest magiczna
bool is_magic(int board[][n], int n, int S) {
  // przejdź przez każdy wiersz i kolumnę, sprawdzając, czy suma jest równa S
  for (int i = 0; i < n; i++) {
    int row_sum = 0;
    int col_sum = 0;
    for (int j = 0; j < n; j++) {
      row_sum += board[i][j];
      col_sum += board[j][i];
    }
    if (row_sum != S || col_sum != S) {
      return false;
    }
  }
  return true;
}

// funkcja tworząca kwadrat magiczny
void magic_square(int n) {
  // utwórz planszę n x n wypełnioną liczbami od 1 do n^2
  int board[n][n];
  int num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = num;
      num += 1;
    }
  }

  // oblicz sumę S dla każdego wiersza i kolumny
  int S=0;
  int (i=0; i<n*2 +1; i++)
  {
    
  }

  // w pętli przechodź przez każdy wiersz i kolumnę, sprawdzając, czy suma jest równa S
  while (!is_magic(board, n, S)) {
    // jeśli suma dla danego wiersza lub kolumny nie jest równa S,
    // znajdź dwie liczby w wierszu lub kolumnie, których suma jest równa S
    // i zamień je miejscami
  }

  // wyświetl utworzony kwadrat magiczny
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // stwórz kwadrat magiczny rozmiaru 3 x 3
  magic_square(3);

  return 0;
}
