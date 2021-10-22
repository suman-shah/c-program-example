#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
// COMPUTER PROGRAMMING PROJECT
//SNAKE GAME 
//Made by LUCKY KUMAR (IMT2020-051), RITIK KUMAR (IMT2020-080), PIYUSH YADAV(IMT2020-068), DEVANSHU PATIDAR(IMT2020-026)
int width=40,height=20,gameover;
int x,y,fruitX,fruitY,score,flag,map;
int tailX[100],tailY[100];
int CountTail=0;
void start();
void layout();
void move();
void mechanism();
void Welcome();


int main()
{
    Welcome();              // PRINTS WELCOME MESSAGE
    start();                // ASKS FOR LEVEL AND START THE GAME
    while(!gameover) 
    {
        layout();         // TO DRAW MAP
        move();             // W A S D KEYS FOR MOVEMENT OF SNAKE
        mechanism();
        if(gameover == 1)   //WHEN SNAKE DIES
        {
            printf("\n\n\t\t\t GAME OVER\n\n");
            printf("\t\t\tYOUR SCORE IS %d",score);
            Sleep(2000);    // FREEZE SCREEN FOR 2 SECONDS AFTER GAMEOVER
        }
    }

    return 0;
}

void Welcome()
{
    printf("\n\n\n\t\t\tWelcome to the Snake game.\n\n\nMade by Lucky Kumar (IMT2020-051), Ritik Kumar (IMT2020-080), Piyush Yadav (IMT2020-068), Devanshu Patidar (IMT2020-026)\n\n\n\t\t\t(press any key to continue)\n");
    getch();
    system("cls"); 
    printf("\t\tGame instructions:");
    printf("\n\n-> Use 'W' 'A' 'S' 'D' to move the snake.");
    printf("\n\n-> You will be provided food at the random coordinates of the screen which you have to eat.");
    printf("\n\n-> Everytime you eat a food the length of the snake will be increased by 1 element and thus the score increases by 10.");
    printf("\n\n-> You can press 'X' to end the game while playing");
    
}

void start()
{
    printf("\n\nEnter Map (1 or 2 or 3 or 4):"); // ENTER LEVEL OF MAP
    scanf("%d",&map);
    gameover=0;
    x=width/2;
    y=height/2;
    label1:     // TO GENERATE FOOD WITHIN THE BOUNDARIES IN MAP 1
    fruitX=rand()%40;
    if (fruitX==0 )
        goto label1;
    label2:
    fruitY=rand()%20;
    if(fruitY==0)
        goto label2;
    if(map==2) // TO GENERATE FOOD WITHIN THE BOUNDARIES IN MAP 2
    {
        if((fruitY==9 && fruitX<15) || (fruitY==11 && fruitX>25) || (fruitX==14 && 9>fruitY && fruitY>4) || (fruitX==26 && 11<fruitY && fruitY<16))
            goto label1;
    }          
    if(map==3) // TO GENERATE FOOD WITHIN THE BOUNDARIES IN MAP 3
    {
        if((fruitY==7 && fruitX>5 && fruitX<35) || (fruitY==14 && fruitX>5 && fruitX<35) )
            goto label1;
    }
     if(map==4) // TO GENERATE FOOD WITHIN THE BOUNDARIES IN MAP 4
    {
        if((fruitY==7 && fruitX>5 && fruitX<35) || (fruitY==14 && fruitX>5 && fruitX<35)||(fruitY==9 && fruitX<15) || (fruitY==11 && fruitX>25) || (fruitX==14 && 9>fruitY && fruitY>4) || (fruitX==26 && 11<fruitY && fruitY<16) )
            goto label1;
    }

}
void layout()
{
    int i,j,k;
    system("cls");
    for(j=0;j<=height;j++)
    {
        for(i=0;i<=width;i++)
        {
            if(i==0 || j==0 || i==width || j==height)//MAP 1
            {
                printf("+");
            }
            else if(map==2 && ( (j==9 && i<15) || (j==11 && i>25) || (i==14 && 9>j && j>4) || (i==26 && 11<j && j<16)))// MAP 2
            {
                printf("+");
            }
            else if(map==3 && ((j==7 && i>5 && i<35) || (j==14 && i>5 && i<35))) // MAP 3
            {
                printf("+");
            }
             else if(map==4 && ((j==7 && i>5 && i<35) || (j==14 && i>5 && i<35)||(j==9 && i<15) || (j==11 && i>25) || (i==14 && 9>j && j>4) || (i==26 && 11<j && j<16))) // MAP 4
            {
                printf("+");
            }
            else // TO DRAW SNAKE AND FOOD
            {
                if(i==x && y==j)
                printf("0");
                else if(i==fruitX && j==fruitY )
                printf("*");
                else
                {
                    int ch=0;
                    for(k=0;k<CountTail;k++)
                    {
                        if(i==tailX[k] && j==tailY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch == 0)
                    {
                        printf(" ");
                    }
                }
            }


        }

        printf("\n");
    }
    printf("SCORE=%d",score); // SCORE MESSAGE
}
void move()         // TO MOVE SNAKE
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
            flag=1;
            break;

            case 's':
            flag=2;
            break;

            case 'w':
            flag=3;
            break;

            case 'd':
            flag=4;
            break;

            case 'x':
            gameover=1;
            break;
        }
    }
}
void mechanism() // TO INCREASE THE SIZE OF SNAKE WHENEVER IT EATS FOOD
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;

    for(i=1;i<CountTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    switch(flag) // MOVE SNAKE IN COORDINATION WITH SNAKE HEAD
    {
       case 1:  x--;
                break;

       case 2:  y++;
                break;

       case 3:  y--;
                break;

       case 4:  x++;
                break;
    }

   if(x<=0 || y<=0 || x>=width || y>=height )//map1 death
        gameover=1;
   if(map==2 && ( (y==9 && x<15) || (y==11 && x>25) || (x==14 && 9>y && y>4) || (x==26 && 11<y && y<16)))//map2 death
        gameover=1;
   if(map==3 && ((y==7 && x>5 && x<35) || (y==14 && x>5 && x<35)))// map3 death
        gameover=1;
   if(map==4 && ((y==7 && x>5 && x<35) || (y==14 && x>5 && x<35)||(y==9 && x<15) || (y==11 && x>25) || (x==14 && 9>y && y>4) || (x==26 && 11<y && y<16)))
        gameover=1;//map4 death
        


    for(i=0;i<CountTail;i++)
    {
        if(x==tailX[i] && y==tailY[i]) // WHEN SNAKE TOUCHES ITS OWN BODY THEN GAMEOVER
            gameover=1;

    }
   if(x==fruitX && y==fruitY) // TO GENERATE FOOD REGULARLY AT NEW POSITION ON THE SCREEN
   {
       label3:
       fruitX=rand()%40;
       if (fruitX==0)
       goto label3;
       label4:
       fruitY=rand()%20;
       if(fruitY==0)
       goto label4;
       if(map==2)
       {
            if((fruitY==9 && fruitX<15) || (fruitY==11 && fruitX>25) || (fruitX==14 && 9>fruitY && fruitY>4) || (fruitX==26 && 11<fruitY && fruitY<16))
            {
                 goto label3;
            } 
       }    
       if(map==3)
       {
           if((fruitY==7 && fruitX>5 && fruitX<35) || (fruitY==14 && fruitX>5 && fruitX<35))
            {
                goto label3;
            }
       }
        if(map==4)
       {
           if((fruitY==9 && fruitX<15) || (fruitY==11 && fruitX>25) || (fruitX==14 && 9>fruitY && fruitY>4) || (fruitX==26 && 11<fruitY && fruitY<16)||(fruitY==7 && fruitX>5 && fruitX<35) || (fruitY==14 && fruitX>5 && fruitX<35))
            {
                goto label3;
            }
       }
       score+=10;
       CountTail++;
   }

}
