#include <stdio.h>/*include information about standard library*/

#define DIM 3
#define SPACE ' ' /*Game Free Space*/

void inic(char s[][DIM]);
void show(char s[DIM][DIM]);
int win(char g[DIM][DIM],char ch);
int line(char v[],char c);
int column(char g[DIM][DIM], int col,char ch);
int diagonal(char g[DIM][DIM], char ch);

int main(){
	char game[DIM][DIM];
	int posx, posy;
	char ch = '0'; 
	int n_moves = 0;
	inic(game);
	while (1){
		/* Infinite Cycle */
		show(game);
		printf("\nMake your move");
		printf("\ninsert a line number between[1-%d] : ", DIM);
		scanf("%d", &posx);
		printf("insert a column number between[1-%d] : ", DIM);
		scanf("%d", &posy);
		if(posx> DIM || posy>DIM){
			printf("\n\n**** Invalid Values ****\n\n");
			continue;
		}
		posx--;posy--; /* Because the vector indices start at ZERO */
		if(game[posx][posy] == SPACE){
			game[posx][posy] = ch = (ch == '0') ? 'X' : '0';
			n_moves++;
			if(win(game, ch)){
				printf("\n\n**** Player %c won ****\n\n", ch);
				break;
			}
		}
		else
			printf("\n\tAlready occupied position\n\tPlay Again!!!\n");
		if(n_moves==DIM*DIM){ 
			printf("\n\n**** It's a draw, try a rematch ***\n\n");
			break;
		}
	}
   show(game);
   return 0;
}

/* Init board game */
void inic(char s[][DIM]){
	int i,j;
	for(i=0;i<DIM;i++)
		for(j=0;j<DIM;j++)
			s[i][j]=SPACE;
}

/* Display current board game */
void show(char s[DIM][DIM]){ 
	int i,j;
	for (i=0;i<DIM;i++){
			for (j=0;j<DIM;j++)
				printf("%c %c",s[i][j],j==DIM-1?' ':'|');
			if(i!=DIM-1) 
				printf("\n--------");
			putchar('\n');
	}
}

/*Checks if the n-th line is all filled with the character c */
int line(char v[],char c){
	return v[0]==v[1] && v[1]==v[2] && v[0]==c;
}

/* Checks if column col is filled with char ch */
int	column(char g[DIM][DIM], int col, char ch){
	return g[0][col]==g[1][col] && g[1][col]==g[2][col] && g[0][col]==ch;
}

/*Check if any of the diagonals are completely filled with char ch */ 
int diagonal(char g[DIM][DIM], char ch){
	return ( ( (g[0][0]==g[1][1]) && (g[2][2]==g[1][1]) && (g[0][0]== ch) ) || ((g[0][2]==g[1][1]) && (g[2][0]==g[1][1]) && (g[0][2]== ch) ) );
}

/*Check if the player with character ch won the game */
int win(char g[DIM][DIM], char ch){
	if (line(g[0],ch) || line(g[1],ch) || line(g[2],ch))
		return 1;
	if (column(g,0,ch) || column(g,1,ch) || column(g,2,ch))
		return 1;
	if (diagonal(g,ch))
		return 1;
	return 0; /* Return if not won*/
}
