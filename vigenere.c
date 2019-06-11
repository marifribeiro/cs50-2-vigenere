#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checks if argument is valid.
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }
    
    // give a name to argv[1]
    string keyWord = argv[1];
    // create an array with length as the size of argv[1]
    int keyNum[strlen(keyWord)];

    // convert the keyword to an array of keys numbers
    for (int i = 0, n = strlen(keyWord); i < n; i++)
    {
        if (isalpha(keyWord[i]) && isupper(keyWord[i]))
        {
            keyNum[i] = (keyWord[i] - 'A');
        }
        else if (isalpha(keyWord[i]) && islower(keyWord[i]))
        {
            keyNum[i] = (keyWord[i] - 'a');
        }
        else
        {
            keyNum[i] = keyWord[i];
        }
    }
    
    // get plaintext from user
    string plaintext = get_string("Plaintext: ");
    // set a counter to loop the keyword if it's shorter than plaintext
    int keyCounter = 0;
    // print ciphertext
    printf("Ciphertext: ");
    
    // iterates over plaintext, adding the key value to each letter to calculate the ciphertext 
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {   
        // result of ciphertext
        int ciphertext = plaintext[i] + keyNum[keyCounter];
        
        // if char is uppercased, keep uppercased
        if (isupper(plaintext[i]) && ciphertext > 90)
        {
            ciphertext = ciphertext - 26;
        }
        //  if char is lowercased, keep lowercased
        else if (islower(plaintext[i]) && ciphertext > 122)
        {
            ciphertext = ciphertext - 26;
        }
        // if char is not alpha, keep as it is and decrease counter so it doesn't go until next char
        else if (!isalpha(plaintext[i]))
        {
            ciphertext = plaintext[i];
            if (keyCounter != 0)
            {
                keyCounter--;
            }
            else
            {
                keyCounter = 0;
            }
        }
        // when the counter equals the last index of the keyNum array, reset
        if (keyCounter == (sizeof(keyNum) / 4) - 1) 
        {
            keyCounter = 0;
        }
        // if counter doesn't reach the max length of the array, increase by 1
        else
        {
            keyCounter++;
        }
        // print ciphertext
        printf("%c", ciphertext);
    }
    printf("\n");
}
