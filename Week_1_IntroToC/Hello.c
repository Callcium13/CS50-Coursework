//To ask users name and print hello, "NAME"
//by Callum Coffey
//16/04/2020

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string answer = get_string("What's your name?\n");
    printf("Hello, %s!\n", answer);

}
