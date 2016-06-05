#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int line, space, sharp;
    int height;
    
    do
    {
        printf("Enter a non-negative integer < 24: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    for (line = 1; line <= height; line++)
    {
        for (space = height - 1; space >= line ; space--)
        {
            printf(" ");
        }
        for (sharp = 1; sharp <= line; sharp++)
        {
            printf("#");
        }    
        
        printf("  ");
                
        for (sharp = 1; sharp <= line; sharp++)
        {
            printf("#");
        }
            
        printf("\n");
    
    }
    
    return 0;
}    
