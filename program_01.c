#include <stdio.h>
#include <termios.h>

#define SIZE 16

/* 
	Bob Heine - Program 1
	Referenced code can be found at:
	http://man7.org/tlpi/code/online/dist/tty/no_echo.c.html
	http://tldp.org/HOWTO/Serial-Programming-HOWTO/x115.html
*/

int main() {
	/* Turn off echo */	
	struct termios ogTerm, newTerm;
	tcgetattr(1, &ogTerm);
	newTerm = ogTerm;
	newTerm.c_iflag &= ~ECHO;
	tcsetattr(1,1,&newTerm);

	/* Get input and output it */
	char *input;
	input = malloc(SIZE);
	printf("Disabling echo\n");
	printf("Input username: ");
	scanf("%s", input);
	printf("\nGot: %s", input);

	/* Restore terminal */
	tcsetattr(1, 1, &ogTerm);
}
