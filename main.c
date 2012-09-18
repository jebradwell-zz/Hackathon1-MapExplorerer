#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24

int main(int argc, char *argv[])
{
	
	return 0;
}

char **create_board(void) {
	int i, j;
	for( j = 0; j < BOARD_HEIGHT; ++j) {
		for( i = 0; i <  BOARD_WIDTH; ++i) {

		}
	}
	new_board = (char*) malloc (i+1);
}

void delete_board(char **board) {

}

char** load_board(char *filename) {
	//Create variables at the start of the function as C mandates.
	int file_close_return;
	const char *filename = "board.txt";
	char **new_board = create_board();
	FILE *FPboard;

	FPboard = fopen(filename, "r");

	file_close_return = fclose(FPboard);
	if(file_close_return) {
		
		printf("Could not close file properly. Filename : %s", filename);
		return ;
	}
}

void print_board(char **board)
{
	int i, j;
	for( j = 0; j < BOARD_HEIGHT; ++j)
	{
		for( i = 0; i < BOARD_WIDTH; ++i)
		{
			printf("%c", board[i][j]);
		}
	}
}