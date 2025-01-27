
#include <stdio.h>
#include <stdlib.h>

void drawBoard(char board[10][10])
 {
    int i, j;
    for (i = 0; i < 10; i++)
     {
	for (j = 0; j < 10; j++)
	 {
	    printf(" %c ", board[i][j]);
	    if (j < 9) printf("|");
	}
	printf("\n");
	if (i < 9) {
	    for (j = 0; j < 29; j++) printf("-");
	    printf("\n");
	}
    }
}

int checkWin(char board[10][10], char player)
 {
    int i, j, k;
    // Check rows
    for (i = 0; i < 10; i++)
     {
	for (j = 0; j < 7; j++)
	 {
	    if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player)
		return 1;
	}
    }
    // Check columns
    for (i = 0; i < 7; i++)
     {
	for (j = 0; j < 10; j++)
	 {
	    if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player)
		return 1;
	}
    }
    // Check diagonals
    for (i = 0; i < 7; i++)
     {
	for (j = 0; j < 7; j++)
	{
	    if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player)
		return 1;
	    if (board[i+2][j] == player && board[i+1][j+1] == player && board[i][j+2] == player)
		return 1;
	}
    }
    return 0;
}

int checkDraw(char board[10][10])
 {
    int i, j;
    for (i = 0; i < 10; i++)
     {
	for (j = 0; j < 10; j++)
	 {
	    if (board[i][j] == ' ')
		return 0;
	}
    }
    return 1;
}

int main()
 {
    char board[10][10];
    int i, j;
    char player = 'X';
    int row, col;
    for (i = 0; i < 10; i++)
     {
	for (j = 0; j < 10; j++)
	 {
	    board[i][j] = ' ';
	}
    }

    printf("Tic-Tac-Toe Game\n");
    printf("-----------------\n");

    while (1)
     {
	drawBoard(board);
	printf("Player %c's turn. Enter row (1-10) and column (1-10): ", player);
	scanf("%d %d", &row, &col);

	if (row < 1 || row > 10 || col < 1 || col > 10)
	 {
	    printf("Invalid input. Try again.\n");
	    continue;
	}

	if (board[row-1][col-1] != ' ')
	 {
	    printf("Space occupied. Try again.\n");
	    continue;
	}

	board[row-1][col-1] = player;

	if (checkWin(board, player))
	 {
	    drawBoard(board);
	    printf("Player %c wins! Congratulations!\n", player);
	    break;
	}

	if (checkDraw(board))
	 {
	    drawBoard(board);
	    printf("It's a draw!\n");
	    break;
	}

	player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

