#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS 26

int main(int argc, char* argv[])
{
  // check for the proper command line arguments
    char* ptext;
    if ( argc != 2)
    {
        printf("Usage: ./vigenere <Keyword>\n");
        return 1;  
    }  
   
    // ensure keyword is a string
    
    char* keyword = argv[1];
    int keyword_len = strlen(keyword);

    // check if there are the right number of arguments
    for (int i = 0; i < keyword_len; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }     
     }
    // get plaintext message from user; don't accept EOF as valid input
    
    
    do
    {
        ptext = GetString();
    }
    while (ptext == NULL);
   
    // encrypt the plaintext message in place,tracking the seen letters
    int keywordLetters = 0;
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (isalpha(ptext[i]))
        {
            // turn our keyword letter into an integer key in range [0, 25]
            int k;
            // keyword wrap around
            int index = keywordLetters % keyword_len;
            
            if (isupper(keyword[index]))
            {
               // substracting to wrap back to zeroth index 
                k = keyword[index] - 'A';    
            }
            else if (islower(keyword[index]))
            {
                k = keyword[index] - 'a'; 
            }
            
            // enchipher the ptext
            if (isupper(ptext[i]))
            {
     // substract 'A' to get message[i] in the appropiate[0,25] range
                ptext[i] = ((ptext[i] - 'A' + k) % NUM_LETTERS ) + 'A';
            }
            
            else if (islower(ptext[i]))
            {
                ptext[i] = ((ptext[i] - 'a' + k) % NUM_LETTERS ) + 'a';
            }   
            
            keywordLetters++;    
        }
    }
    char* chiphertext = ptext;
    printf("%s\n",chiphertext);
    
    free(chiphertext);
    
    return 0;
}
