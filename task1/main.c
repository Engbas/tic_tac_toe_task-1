#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 3
static int m =0;
void printBoard(char board[n][n]) { // we also can pass row size and colum size
	//system("cls");
	for (int rows = 0; rows < 3; rows++) {
		for (int coloum = 0; coloum < 3; coloum++) {
			printf("%c  ", board[rows][coloum]);
		}
		printf("\n");
	}
}
bool checkWsit2(char board [n][n],int row, int column){
    int i,j,count;
    //printBoard(board);
    for (j=0;j<n;j++){
        if (board[row][j]=='O'){
            count++;
            }
    }
    printBoard(board);
    printf ("%d\n",count);

    if (count==3){
        return true;
    }
    count=0;
  /*  printBoard(board);
    printf ("%d\n",count);
*/
    for (i=row,j=column;i<n&&j<n;i++,j++){
         if ('O'==board[i][j]){
            count++;
        }
    }
    count--;
   // printBoard(board);
    // printf ("%d\n",count);
     for (i=row,j=column;i>=0&&j>=0;i--,j--){
         if ('O'==board[i][j]){
            count++;
        }
    }
    /*printBoard(board);
    printf ("%d\n",count);
*/
    if (count==3){
        return true;
    }
    count=0;
    //printBoard(board);
    for (i=row,j=column;i<n&&j>=0;i++,j--){
         if ('O'==board[i][j]){
            count++;
        }
    }
  /*  printBoard(board);
    printf ("%d\n",count);
    */count--;
     for (i=row,j=column;i>=0&&j<n;i--,j++){
         if ('O'==board[i][j]){
            count++;
        }
    }
    if (count==3){
        return true;
    }
    //printBoard(board);
    return false;
}
 bool checkWsit(char board [n][n],int row, int column){
    int i,j,count;
    //printBoard(board);
    for (j=0;j<n;j++){
        if (board[row][j]=='X'){
            count++;
            }
    }
   /*printBoard(board);
    printf ("%d\n",count);
*/
    if (count==3){
        return true;
    }
    count=0;
  /*  printBoard(board);
    printf ("%d\n",count);
*/
    for (i=row,j=column;i<n&&j<n;i++,j++){
         if ('X'==board[i][j]){
            count++;
        }
    }
    count--;
   /* printBoard(board);
    printf ("%d\n",count);
     */for (i=row,j=column;i>=0&&j>=0;i--,j--){
         if ('X'==board[i][j]){
            count++;
        }
    }
    /*printBoard(board);
    printf ("%d\n",count);
*/
    if (count==3){
        return true;
    }
    count=0;
    //printBoard(board);
    for (i=row,j=column;i<n&&j>=0;i++,j--){
         if ('X'==board[i][j]){
            count++;
        }
    }
    /*printBoard(board);
    printf ("%d\n",count);
    */count--;
     for (i=row,j=column;i>=0&&j<n;i--,j++){
         if ('X'==board[i][j]){
            count++;
        }
    }
    if (count==3){
        return true;
    }
    printBoard(board);
    return false;
}
void player2_selec(char board[n][n]){
    int i,j;
    printf("enter cordinates player O\n ");
    printf("enter row \n ");
     scanf("%d", &i);
    printf("enter column \n ");
     scanf("%d", &j);
     if (board[i][j]=='0'){
        board[i][j]='O';
       if  (checkWsit2(board,i,j)){
        printf("player O wins \n");
        printBoard(board);

       }
       else{
            m++;
        player1_selec(board);
       }

     }
     else {
        printf("this position is occupied\n");
        player2_selec(board);

     }

}
 void player1_selec(char board [n][n]){
   int i,j;
    printf("enter cordinates player X \n ");
    printf("enter row \n ");
     scanf("%d", &i);
    printf("enter column \n ");
     scanf("%d", &j);

     if (board[i][j]=='0'){
        board[i][j]='X';
        //printBoard(board);
       if  (checkWsit(board,i,j)==true){
        printf("player x wins \n");
       // printBoard(board);

       }
       else{

        player2_selec(board);
       }
     }
     else {
        printf("this position is occupied\n");
        player1_selec(board);

     }



 }
 void start (){
  char board [n][n]= { { '0', '0', '0' },
                       { '0', '0', '0' },
                       { '0', '0', '0' }};
    player1_selec(board);

 }
int main()
{
    printf("Hello world!\n");
    start();
    return 0;
}
