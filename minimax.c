#include<stdio.h>
#include <stdlib.h>
#include<time.h>
void print_board(char arr[]);
char win_check(char arr[]);
int make_move(char arr[],char player);
void ai_move(char board[]);
int minimax(char board[],int depth, int isMaximizing);
int main(){
    srand(time(NULL));
    char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    print_board(board);
    int i=0;
    char player =' ';
    while(1){
        if(i%2==0){
            player = 'X';
        while(!make_move(board,player)){
        printf("Invalid Position Enter again\n ");
        }
       }
        else{
            char ai = 'O';
            ai_move(board);
        }
  
    print_board(board); 
    char result =win_check(board);
    if(result=='X'){
        printf("X wins");
        break;
    }
    else if(result=='O'){
        printf("O wins");
        break;
    }
    else if(result=='D'){
        printf("Its a Draw You Dumbass");
        break;
    }
    i++;
    }


    return 0;
}

void print_board(char arr[]){
    int i;
    for (i=0;i<9;i++){
        printf("%c",arr[i]);
        if((i+1)%3==0 && i!=8){
            printf("\n");
            printf("-----------\n");
        }
        else{
            if(i!=8){
            printf(" | ");
             }
           }

    }
    printf("\n");
}

char win_check(char arr[]){
    int i;
    int j;
    int l;
    for(i=0;i<=6;i+=3){
        if(arr[i]!=' ' && arr[i]==arr[i+1]&&arr[i]==arr[i+2]){
            return arr[i];
        }
    }
    for(j=0;j<3;j++){
        if(arr[j]!=' ' && arr[j]==arr[j+3] && arr[j]==arr[j+6]){
            return arr[j];
        }
    }
     if(arr[0]!=' ' && arr[0]==arr[4] && arr[0]==arr[8]){
        return arr[0];
     }
     else if(arr[2]!=' ' && arr[2]==arr[4] && arr[2]==arr[6]){
        return arr[2];
     }
     for(l=0;l<9;l++){
        if(arr[l]==' '){
            return ' ';
        }

     }
     return 'D';
     
     }

 int make_move(char arr[],char player){
    int pos;
    printf("Enter the position(1-9): ");
    scanf("%d",&pos);
    int i=pos-1;
    if(arr[i]!=' '){
        return 0;
    }
    else{
        arr[i]=player;
        return 1;
        
    }
}
void ai_move(char board[]) {
    int bestScore = -1000;
    int move = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int score = minimax(board, 0, 0);
            board[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                move = i;
            }
        }
    }

    board[move] = 'O';
}


int minimax(char board[], int depth, int isMaximizing) {
    char result = win_check(board);


    if (result == 'O') return 10 - depth;   
    if (result == 'X') return depth - 10;   
    if (result == 'D') return 0;            

    if (isMaximizing) {   
        int bestScore = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'O';
                int score = minimax(board, depth + 1, 0);
                board[i] = ' ';
                if (score > bestScore)
                    bestScore = score;
            }
        }
        return bestScore;
    }
    else {  
        int bestScore = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                int score = minimax(board, depth + 1, 1);
                board[i] = ' ';
                if (score < bestScore)
                    bestScore = score;
            }
        }
        return bestScore;
    }
}
