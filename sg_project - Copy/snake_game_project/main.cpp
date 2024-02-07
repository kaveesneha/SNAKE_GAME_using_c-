#include <iostream>
#include <windows.h>
#include <Snake.h>
#include <Food.h>
#include <conio.h>
#include <vector>

using namespace std;
#define WIDTH 50   //macro definition
#define HEIGHT 30
#define UP_KEY 72
#define DOWN_KEY 80
#define RIGHT_KEY 77
#define LEFT_KEY 75


Snake snake({WIDTH/2,HEIGHT/2});//create object foor classs with cooridination usingg {.}.
Food food;
void board()
{
    vector<COORD> snakeBody = snake.getSnakeBody();
    for(int i=0;i<=HEIGHT+1;i++)
    {
        cout<<"\t\t";

        for(int j=0;j<=WIDTH+1;j++)
        {
            if(i==0 || i==HEIGHT+1 || j==0 || j==WIDTH+1)
                cout<<"#";

            else if(i==food.getFoodPos().Y && j==food.getFoodPos().X)
                cout<<"*";
            else
            {
                bool snake_Pos = false;
                for(int k=0;k<snakeBody.size();k++)
                {
                    if(i == snakeBody[k].Y && j==snakeBody[k].X)
                    {
                        cout<<"o";
                        snake_Pos=true;
                        break;
                    }
                }
                if(!snake_Pos)
                    cout<<' ';
            }
        }
        cout<<endl;
    }
}

int main()
{
    while(true)
    {
        Sleep(150);
    board();

    // to set the cursor position to origin stating point
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        if(kbhit())//kbhit means keyboard hit
        {
            switch(getch())
            {
            case UP_KEY: snake.setDir('u');break;
            case DOWN_KEY: snake.setDir('d');break;
            case RIGHT_KEY: snake.setDir('r');break;
            case LEFT_KEY: snake.setDir('l');break;
            }

        }
        snake.moveSnake();
        if(snake.collided())
        {
            cout<<"GAME OVER";
            break;
        }
        if(snake.eaten(food))
        {
            snake.grow();
            food.genFood();
        }
    }
    return 0;
}
