#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24


char **create_board(void) 
{
	int i, j;
	char **new_board = (char**) malloc (BOARD_WIDTH * sizeof( char** ));
	for( i = 0; i < BOARD_WIDTH; ++i) 
	{
		new_board[i] = (char*) malloc (BOARD_HEIGHT * sizeof( char* ));
	}
	//initialize board to blanks at first.
	for( i = 0; i < BOARD_WIDTH; ++i) {
		for( j = 0; j < BOARD_HEIGHT; ++j)
		{
			new_board[i][j] = ' ';
		}
	}
	return new_board;
}

void delete_board(char **board) 
{
	int i;
	for(i = 0; i < BOARD_WIDTH; ++i)
	{
		free(board[i]);
	}
}

char** load_board(char *filename) 
{
	//Create variables at the start of the function as C mandates.
	int file_close_return, i, j;

	char **new_board = create_board();
	FILE *FPboard;

	FPboard = fopen(filename, "r");
	if(FPboard != NULL)
	{
		char line [ BOARD_WIDTH ];
		j = 0;
		while ( fgets ( line, sizeof line, FPboard ) != NULL )
		{
			for( i = 0; i < BOARD_WIDTH; ++i )
			{
				if(line[i] != NULL)
				{
					new_board[i][j] = line[i];
				}
				else
				{
					new_board[i][j] = " ";
				}
			}
			++j; // make sure to increment the height
		}
		file_close_return = fclose(FPboard);
		if(file_close_return) 
		{
			printf("Could not close file : %s", filename);
			perror ( filename );
		}
	}
	else 
	{
		printf("Could not open file : %s", filename);
		perror ( filename );
	}
	return new_board;
}

void add_line(char line[BOARD_WIDTH], char **board) 
{
	
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

int main(int argc, char *argv[]) {
	char *filename = "board.txt";
	char **board = load_board(filename);
	print_board(board);
	return 0;
}

