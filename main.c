#include <stdio.h>
#include <stdlib.h>
void setup(int);
void player1(char *arr);
void player2(char *arr);
int main()
{
    //toss for game
    int i,a,b,n;
    time_t t;
    do
    {
        srand((unsigned) time(&t));
        i=rand()%10+1;
        printf("PLAYER * : ENTER ANY NUMBER FROM 1 TO 10 : ");scanf("%d",&a);
        printf("PLAYER 0 : ENTER ANY NUMBER FROM 1 TO 10 : ");scanf("%d",&b);
        printf("%d\n",i);
    }while(abs(a-i)==abs(b-i));

    if(abs(a-i)<abs(b-i))
    {
        printf("PLAYER * WINS THE TOSS \n");
        setup(1);
    }
    else
    {
        printf("PLAYER 0 WINS THE TOSS\n");
        setup(-1);
    }
}
void setup(int x)
{
    char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
    int i,j;
    printf("\nStart :\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf(" %c\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nGeneral rule of game : Both players are requested to enter the index (1 - 6)  where they want to insert * or 0 \n");
    if(x==1)
        player1(&matrix[0][0]);
    if(x==-1)
        player2(&matrix[0][0]);
}
void player1(char *arr)
{
    int x;
    int j,i;
    jump:printf("Player * enter index number where you want to insert * : \n");
    scanf("%d",&x);
    system("cls");
    if(x>=1 && x<=9)
    {
        if((*(arr+(x-1))=='o')||(*(arr+(x-1))=='*'))
        {
            printf("This position is already occupied\n");
            goto jump;
        }
        *(arr+(x-1))='*';
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf(" %c\t",*(arr+i*3+j));
            }
            printf("\n\n");
        }
        if((*(arr)=='*'&&*(arr+1)=='*'&&*(arr+2)=='*')||(*(arr+3)=='*'&&*(arr+4)=='*'&&*(arr+5)=='*')||(*(arr+6)=='*'&&*(arr+7)=='*'&&*(arr+8)=='*')||(*(arr)=='*'&&*(arr+3)=='*'&&*(arr+6)=='*')||(*(arr+1)=='*'&&*(arr+4)=='*'&&*(arr+7)=='*')||(*(arr+2)=='*'&&*(arr+5)=='*'&&*(arr+8)=='*')||(*(arr+3)=='*'&&*(arr+4)=='*'&&*(arr+5)=='*')||(*(arr)=='*'&&*(arr+4)=='*'&&*(arr+8)=='*')||(*(arr+2)=='*'&&*(arr+6)=='*'&&*(arr+4)=='*'))
        {
            printf("\nCONGRATULATIONS!!! Player * has won the game\n");
            exit(0);
        }
        if(*(arr)!='1'&&*(arr+1)!='2'&&*(arr+2)!='3'&&*(arr+3)!='4'&&*(arr+4)!='5'&&*(arr+5)!='6'&&*(arr+6)!='7'&&*(arr+7)!='8'&&*(arr+8)!='9')
        {
            printf("Game is Tied!!");
            exit(0);
        }
        player2(arr);
    }
    else
    {
        printf("Please enter an valid index number!!!\n");
        goto jump;
    }
}

void player2(char *arr)
{
    int x;
    int j,i;
    jump:printf("Player o enter index number where you want to insert o :\n");
    scanf("%d",&x);
    system("cls");
    if(x>=1 && x<=9)
    {
        if((*(arr+(x-1))=='o')||(*(arr+(x-1))=='*'))
        {
            printf("This position is already occupied\n");
            goto jump;
        }
        *(arr+(x-1))='o';
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf(" %c\t",*(arr+i*3+j));
            }
            printf("\n\n");
        }
        if((*(arr)=='o'&&*(arr+1)=='o'&&*(arr+2)=='o')||(*(arr+3)=='o'&&*(arr+4)=='o'&&*(arr+5)=='o')||(*(arr+6)=='o'&&*(arr+7)=='o'&&*(arr+8)=='o')||(*(arr)=='o'&&*(arr+3)=='o'&&*(arr+6)=='o')||(*(arr+1)=='o'&&*(arr+4)=='o'&&*(arr+7)=='o')||(*(arr+2)=='o'&&*(arr+5)=='o'&&*(arr+8)=='o')||(*(arr+3)=='o'&&*(arr+4)=='o'&&*(arr+5)=='o')||(*(arr)=='o'&&*(arr+4)=='o'&&*(arr+8)=='o')||(*(arr+2)=='o'&&*(arr+6)=='o'&&*(arr+4)=='o'))
        {
            printf("\nCONGRATULATIONS!!! Player o has won the game\n");
            exit(0);
        }
        if(*(arr)!='1'&&*(arr+1)!='2'&&*(arr+2)!='3'&&*(arr+3)!='4'&&*(arr+4)!='5'&&*(arr+5)!='6'&&*(arr+6)!='7'&&*(arr+7)!='8'&&*(arr+8)!='9')
        {
            printf("Game is Tied!!");
            exit(0);
        }
        player1(arr);
    }
    else
    {
        printf("Please enter an valid index number!!!\n");
        goto jump;
    }
}
