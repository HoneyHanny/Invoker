#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

// this line was committed from vscode web (for learning purposes)

#define CLS "cls"
#define QUAS "Quas"
#define WEX "Wex"
#define EXORT "Exort"
#define COLD_SNAP "Cold Snap"
#define GHOST_WALK "Ghos Walk"
#define ICE_WALL "Ice Wall"
#define EMP "EMP"
#define ALACRITY "Alacrity"
#define TORNADO "Tornado"
#define DEAFENING_BLAST "Deafening Blast"
#define SUN_STRIKE "Sun Strike"
#define CHAOS_METEOR "Chaos Meteor"
#define FORGE_SPIRIT "Forge Spirit"
#define SEPARATOR "-----------------------------------------------"

// global variables
char combo[3] = { '_','_','_' }, temp;
int q, w, e, i;

// function declarations
void enq();
void display();
void showCombinations();

int main() {

	// program loop
	do {
		
		printf("Press \"space\" to view guides.\nPress 'S' to stop.\n\n");
		printf("Invoker training: Manipulate elements and invoke spells\n\n");
		printf("\n\t\t\t\t  \"So, begins a new age of knowledge.\" -Invoker\n");
		printf("\n\nQ:Quas  W:Wex  E:Exort  R:Invoke\nTo use press corresponding letters.");
		printf("\n\n\n\n\t\t\t\t   ");
		display();
		if (q == 3)
			printf("\n\n\t\t\t\t%s", COLD_SNAP);
		else if (q == 2 && w == 1)
			printf("\n\n\t\t\t\t%s", GHOST_WALK);
		else if (q == 2 && e == 1)
			printf("\n\n\t\t\t\t %s", ICE_WALL);
		else if (w == 3)
			printf("\n\n\t\t\t\t    %s", EMP);
		else if (w == 2 && e == 1)
			printf("\n\n\t\t\t\t %s", ALACRITY);
		else if (w == 2 && q == 1)
			printf("\n\n\t\t\t\t  %s", TORNADO);
		else if (q == 1 && w == 1 && e == 1)
			printf("\n\n\t\t\t       %s", DEAFENING_BLAST);
		else if (e == 3)
			printf("\n\n\t\t\t\t%s", SUN_STRIKE);
		else if (e == 2 && w == 1)
			printf("\n\n\t\t\t\t%s", CHAOS_METEOR);
		else if (e == 2 && q == 1)
			printf("\n\n\t\t\t\t%s", FORGE_SPIRIT);
		temp = '\0';
		while (temp != 'Q' && temp != 'W' && temp != 'E' && temp != 'R' && temp != ' ' && temp != 'S')
			temp = toupper(getch());
		if (temp == 'R') {
			q = 0;
			w = 0;
			e = 0;
			for (i = 0; i < 3; i++) {
				if (combo[i] == 'Q')
					q++;
				else if (combo[i] == 'W')
					w++;
				else if (combo[i] == 'E')
					e++;
			}
		} else if (temp == ' ')
			showCombinations();
		else
			enq();
		system(CLS);
	} while (temp != 'S');
	return 0;
}

void enq() {
	combo[0] = combo[1];
	combo[1] = combo[2];
	combo[2] = temp;
	return;
}

void display() {

	for (i = 0; i < 3; i++)
		printf("%c ", combo[i]);

	return;
}

void showCombinations() {

	system(CLS);

	printf("\n\t\tQ = %s\n", QUAS);
	printf("\n\t\tW = %s\n", WEX);
	printf("\n\t\tE = %s\n%s\n", EXORT, SEPARATOR);

	printf("\t>>>\tQ Q Q = %s\n\n", COLD_SNAP);
	printf("\t>>>\tQ Q W = %s\n\n", GHOST_WALK);
	printf("\t>>>\tQ Q E = %s\n\n", ICE_WALL);
	printf("\t>>>\tW W W = %s\n\n", EMP);
	printf("\t>>>\tW W E = %s\n\n", ALACRITY);
	printf("\t>>>\tW W Q = %s\n\n", TORNADO);
	printf("\t>>>\tQ W E = %s\n\n", DEAFENING_BLAST);
	printf("\t>>>\tE E E = %s\n\n", SUN_STRIKE);
	printf("\t>>>\tE E W = %s\n\n", CHAOS_METEOR);
	printf("\t>>>\tE E Q = %s\n\n", FORGE_SPIRIT);

	printf("\npress any key to return");
	getch();

	return;
}