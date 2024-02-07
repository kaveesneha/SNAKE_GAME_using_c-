#include "Food.h"
#include<ctime>
#include<stdlib.h>
#define WIDTH 50   //macro definition
#define HEIGHT 30

Food::Food()
{
    srand(time(NULL));
    genFood();
}
void Food::genFood()
{
     foodPos.X= rand()%WIDTH+1; //1 - 50
     foodPos.Y= rand()%HEIGHT+1; //1 - 30

}
COORD Food::getFoodPos()
{
    return foodPos;
}

