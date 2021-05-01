//When supplied with cypher will produce encoded message of plain text
//by Callum Coffey
//19/04/2020

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check for valid key_____________________________________________________________________________________________________________________
    //check that key is included
    if (argc != 2)
    {
        printf("Must include key");
        return 1; 
    }

    //check that key is 26 characters in length
    string cipher_string = argv[1];
    if (strlen(cipher_string) != 26)
    {
        printf("Key must be 26 characters in length");
        return 1;        
    }

    //put key into right case
    for (int i = 0; i < 26; i++)
    {
        if(cipher_string[i] > 96 & cipher_string[i] < 123)
        {
            cipher_string[i] = cipher_string[i] - 32;
        }
    }
    
    //check that key is only letters
    for (int i = 0; i < 26; i++)
    {
        if (cipher_string[i] < 65 | cipher_string[i] > 90)
        {
            printf("Must be only letters");
            return 1; 
        }
    }
    
    //check for duplicates in key
    for(int j = 0; j < 26; j++)
    {
        for(int k = 0; k < 26; k++)
        {        
            if ((cipher_string[j] == cipher_string[k]) & (k != j))
            {
                printf("No duplicate letters in key");
                return 1;               
            }
        }
    }
    
    //put key into right case
    for (int i = 0; i < 26; i++)
    {
        if(cipher_string[i] > 96 & cipher_string[i] < 123)
        {
            cipher_string[i] = cipher_string[i] - 32;
        }
    }
    
    //put cipher into array___________________________________________________________________________________________________________________
    //put cipher uppercase into array
    int CIPHER_int [26];

    
    for (int i = 0; i < 26; i++)
    {
        CIPHER_int[i] = cipher_string[i];
    }
    
    //put cipher lowercase into array
    int cipher_int [26];
    for (int i = 0; i < 26; i++)
    {
        cipher_int[i] = CIPHER_int[i] + 32;
    }
    
    //make letters array_____________________________________________________________________________________________________________________
    //make an array with a-z
    int letters_int [26];
    for (int i = 0; i < 26; i++)
    {
        letters_int[i] = 97 + i;
    }

    //make an array with A-Z    
    int LETTERS_int [26];
    for (int i = 0; i < 26; i++)
    {
        LETTERS_int[i] = 65 + i;
    }

    //make an array with 0-9    
    int num_int [10];
    for (int i = 0; i < 10; i++)
    {
        num_int[i] = 48 + i;
    }    
    
    //get plain string and its length________________________________________________________________________________________________________
    //get plain_string
    string plain_string = get_string("plaintext: ");
    //get string length
    int length = strlen(plain_string);
    
    //begin encryption_______________________________________________________________________________________________________________________
    //encrypt plain, check first letter in plain for match in letters, then assign the cipher value in the same place to encrypt_int
    
    //create array encrypt_int with same length as plain_string
    int encrypt_int[length];
    
    //insert upper case letters into encrypt_int
    for(int j = 0; j < length; j++)
    {    
        for(int k = 0; k < 26; k++)
        { 
            if (plain_string[j] == LETTERS_int[k])
            {
                encrypt_int[j] = CIPHER_int[k];
            }        
        }
    }
    
    //insert lower case letters into encrypt_int
    for(int j = 0; j < length; j++)
    {
        for(int k = 0; k < 26; k++)
        {            
            if (plain_string[j] == letters_int[k])
            {
                encrypt_int[j] = cipher_int[k];                
            }
        }
    }
    
    //insert numbers into encrypt_int
    for(int j = 0; j < length; j++)
    {
        for(int k = 0; k < 10; k++)
        {        
            if (plain_string[j] == num_int[k])
            {
                encrypt_int[j] = num_int[k];                
            }
        }
    }
    
    //insert spaces into encrypt_int
    for(int j = 0; j < length; j++)
    {
        if (plain_string[j] == 32)
        {
            encrypt_int[j] = 32;
        }
    }
        
    
    //display all______________________________________________________________________________________________________________________________
    printf("ciphertext:");    
    for (int i=0; i<length; i++)
    {
        printf("%c",encrypt_int[i]);
    }   
    
    //debugging tools
    if (false)
    {
        for (int i=0; i<26; i++)
        {
            printf("%c",letters_int[i]);
            printf("%c",cipher_int[i]);
        }
        
        for (int i=0; i<26; i++)
        {
            printf("%c",LETTERS_int[i]);
            printf("%c",CIPHER_int[i]);
        }
    }
    printf("\n");
    return 0;
}
