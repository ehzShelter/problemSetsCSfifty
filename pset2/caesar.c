#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS 26

int main(int argc, char* argv[])
{
  // check for the proper command line arguments

    if ( argc != 2)
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }

    // ensure key is in range [0,+infinity)
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("key must be a non-negative integer!\n");
        return 1;
    }

    // get plaintext message from user; don't accept EOF as valid input
    char* message = argv[1];

    do
    {
        message = GetString();
    }
    while (argv[1] == NULL);

    // encrypt the plaintext message in place
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]))
        {

        // only encrypt letters,not other characters(e. g., digits)
            if (isupper(message[i]))
            {
     // substract 'A' to get message[i] in the appropiate[0,25] range
                message[i] = ((message[i] - 'A' + key) % NUM_LETTERS ) + 'A';
            }

            else if (islower(message[i]))
            {
                message[i] = ((message[i] - 'a' + key) % NUM_LETTERS ) + 'a';
            }
        }
    }
    // printing cipher_text message
    char* chipher = message;
    printf("%s\n",chipher);

    free(chipher);

    return 0;
}
