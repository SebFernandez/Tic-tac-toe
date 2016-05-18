#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void SHOW (int M [3][3], char N [3][3]);

int main () {
	int K, U, p, i, j;
	int flag = 0, PLAYER = 1, TATETI [3][3] = {{0}};
	char MIAU [3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
	
	SHOW (TATETI, MIAU);
	
	for (K = 0; K < 9 && flag == 0; K++) {
		switch (K){
			case 0:	
			case 2:
			case 4:
			case 6:
			case 8:
				
			printf ("\nTurn %d", K+1);				
			printf ("\nPlayer 1 ---> O\n\n");
			
			do {
				printf ("Position: ");
				scanf ("%d", &p);
			
				i = --p/3;
				j = p%3;
				
			} while (p < -1 || p > 10 || TATETI [i][j] == 1 || TATETI [i][j] == -1 );
			
			printf ("\n");
			TATETI [i][j] = 1;
			SHOW (TATETI, MIAU);
			
			for (i = 0; i < 3; i++) {
				if (TATETI [i][0] + TATETI [i][1] + TATETI [i][2] == 3) {
					flag = 1;
				}
			}
		
			for (j = 0; j < 3; j++){
				if (TATETI [0][j] + TATETI [1][j] + TATETI [2][j] == 3) {
					flag = 1;
				}
			}
		
			if (TATETI [0][0] + TATETI [1][1] + TATETI [2][2] == 3) {
				flag = 1;
			}
			else if (TATETI [2][0] + TATETI [1][1] + TATETI [0][2] == 3) {
				flag = 1;
			}
			break;
			
			case 1:
			case 3:
			case 5:
			case 7:
			case 9: 
					
			printf ("\nTurn %d", K+1);
			printf ("\nPlayer 2 ---> X\n\n");
			
			do {
				printf ("Position: ");
				scanf ("%d", &p);
			
				i = --p/3;
				j = p%3;
				
			} while (p < -1 || p > 10 || TATETI [i][j] == 1 || TATETI [i][j] == -1 );
			
			printf ("\n");
			TATETI [i][j] = -1;
			SHOW (TATETI, MIAU);

			for (i = 0; i < 3; i++) {
				if (TATETI [i][0] + TATETI [i][1] + TATETI [i][2] == -3) {
					flag = 2;
				}
			}
		
			for (j = 0; j < 3; j++){
				if (TATETI [0][j] + TATETI [1][j] + TATETI [2][j]== -3) {
					flag = 2;
				}
			}
		
			if (TATETI [0][0] + TATETI [1][1] + TATETI [2][2] == -3) {
				flag = 2;
			}
			else if (TATETI [2][0] + TATETI [1][1] + TATETI [0][2] == -3) {
				flag = 2;
			}
			break;
}
}
	system ("cls");
	if (flag == 0){
		printf ("Boooooooooooooooooooooooooring. It's a draw.\n");
	} else if ( flag == 1) {
		printf ("Congratulations Player 1! You win. :)\n");
	} else if ( flag == 2) {
		printf ("Congratulations Player 2! You win. :)\n");
	}

	SHOW (TATETI, MIAU);
	
	printf ("\n\n");
	system ("pause");

}

void SHOW (int M [3][3], char N [3][3]) {
	int U, P;
	
	for (U=0; U < 3; U++){
		for (P=0; P < 3; P++){
			if (M [U][P] == -1) {
				N [U][P] = 'X';
			}
			if (M [U][P] == 1) {
				N[U][P] = 'O';
			}
		}
	}
	
      printf(" %c | %c | %c\n", N[0][0], N[0][1], N[0][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", N[1][0], N[1][1], N[1][2]);
      printf("---+---+---\n");
      printf(" %c | %c | %c\n", N[2][0], N[2][1], N[2][2]);
	}
