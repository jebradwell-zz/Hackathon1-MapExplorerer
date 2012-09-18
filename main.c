#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24

#define UP 72 // ascii code for UP ARROW
#define DOWN 80 // ascii code for DOWN ARROW
#define RIGHT 77 // ascii code for RIGHT ARROW
#define LEFT 75 // ascii code for LEFT ARROW
#define ENTER 13 // ascii code for ENTER key
#define SPACEBAR 32 // ascii code for SPACE BAR key


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
			//printf("line %d: %s", sizeof line, line); 
			for( i = 0; i < BOARD_WIDTH; ++i )
			{
				if(line[i] != NULL && (int)line[i] != 10 )
				{
					new_board[i][j] = line[i];
				}
				else
				{
					new_board[i][j] = ' ';
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
	char key_pressed = '\0';
	print_board(board);
	//Process arrow key's, enter and spacebar input.
	//ENTER will escape the input loop.
	while(key_pressed != ENTER)
	{
		if(_kbhit())
		{
			system("cls");
			print_board(board);
			key_pressed = _getch();
			//arrow keys and special keys like home, end, page up, page down, etc have
			//an ascii character of alpha or -32 that gets caught in the _getch() buffer.
			//This if statement catches that and then the switch figures out what arrow
			//key was pressed.
			if(key_pressed == -32){
				key_pressed = _getch();
				switch(key_pressed)
				{
				case DOWN :
					printf("down\n");
					break;
				case UP :
					printf("up\n");
					break;
				case LEFT :
					printf("left\n");
					break;
				case RIGHT :
					printf("right\n");
					break;
				default:
					printf("no input option for this key\n");
					break;
				}
			}
			else
			{
				//In all other non-special key cases we just process the standard singlely
				//return ascii value from _getch()
				switch(key_pressed)
				{
				case ENTER:
					printf("enter\n");
					break;
				case SPACEBAR:
					printf("spacebar\n");
					break;
				default:
					printf("no input option for this key\n");
					break;
				}
			}
		}
	}
	
	return 0;
}