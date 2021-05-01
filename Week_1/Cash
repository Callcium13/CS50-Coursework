//To calculate minimum number of coins needed to give back change
//by Callum Coffey
//19/04/2020

#include <stdio.h>
#include <cs50.h>
#include <math.h>

//declarations
float change_float = -1;
int change;
int remain;
int coins = 0;

//name coins for ease of use
int q = 25;
int d = 10;
int n = 5;
int p = 1;

int main (void)
{
    //checks that answer is not negative
    do
    {
    //ask how much change is owed and convert to float
    change_float = get_float("Change owed: ");        
    } while (change_float <0);
    
    
    //convert to integer and round to reduce miscalculations
    change = roundf(change_float * 100);

    //calculate coins needed
    coins = coins + (change / q);
    change = change - (change / q)*q;
    
    coins = coins + (change / d);
    change = change - (change / d)*d;

    coins = coins + (change / n);
    change = change - (change / n)*n;
    
    coins = coins + (change / p);
    change = change - (change / p)*p;
    
    printf("%i\n",coins);

    
}
