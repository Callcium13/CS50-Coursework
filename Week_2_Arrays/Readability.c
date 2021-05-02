//Prints out grade level of any input text
//by Callum Coffey
//19/04/2020

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int value;
int i;
int start = 0;

int main (void)
{
    //asks user to input text
    string text = get_string ("Insert text here: ");
    int length = strlen(text);
    
    //get number of letters
    //count alphanumeric characters (65-90,97-122)
    float letter_count = 0;
    for (i = 0; i<= length; i++)
    {
        value = text[i];
        if ((value > 64 & value < 91) ||( value > 96 & value < 123))
        {
            letter_count++;     
        }
    }

    //get number of words
    //count number of spaces(32) and subtract 1
    float word_count = 1;
    for (i = 0; i<= length; i++)
    {
        value = text[i];
        if (value == 32)
        {
        word_count++;
        }
    }
    
    //get number of sentences
    //count number of periods(46),exclamation points(33) and question marks(63)
    float sentence_count = 0;
    for (i = 0; i<= length; i++)
    {
        value = text[i];
        if ((value == 46)||(value == 33)||(value == 63))
        {
            sentence_count++;     
        }
    }
    
    //get grade
    //use Coleman-Liau index (0.0588 * L - 0.296 * S - 15.8)
    float L = (letter_count/word_count) * 100;
    float S = (sentence_count/word_count) * 100;
    float grade_float = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = roundf(grade_float);

    //Tells user what grade
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n",grade);
    }
    
    //debugging tool
    if (false)
    {
    printf("L = %f\n",L);
    printf("S = %f\n",S);
    printf("grade_float = %f\n",grade_float);
    printf("word_count = %f\n",word_count);
    printf("letter_count = %f\n",letter_count);
    printf("sentence_count = %f\n",sentence_count);    
    }
    
}
