//input a credit card number and determine invalid,amex,visa or mastercard
//by Callum Coffey
//18/04/2020

#include <cs50.h>
#include <stdio.h>

int a = 0;
int b = 0;
int n = 0;

int main(void)
{
    long card = get_long("Number: ");
    long card_a = card;
    long card_b = card / 10;
    
    //calculations for every first digit
    while (card_a > 0)
    {   
        a = a + (card_a % 10);
        n = n + 1;
        card_a = card_a / 100;
    }
    
    //calculations for every second digit
    while (card_b > 0)
    {           
        
        b = b + 
        (2 * (card_b % 10)) % 10 +
        ((card_b % 10)/5) % 10;
        n = n + 1;
        card_b = card_b / 100;
    }
    
    //generates checksum
    int check = a + b;
    
    //checks card
    if (check % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    else if ((n==15) && ((card / 10000000000000 == 34) || (card / 10000000000000 == 37)))
    {
        printf("AMEX\n");
    }
    
    else if ((n == 13 & card / 1000000000000 == 4) | ( n== 16 & card / 1000000000000000  == 4 ))
    {
        printf("VISA\n");
    }
    
    else if ((n==16) && (card / 100000000000000 >=51) && (card / 100000000000000 <=55))
    {
        printf("MASTERCARD\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
    
}

