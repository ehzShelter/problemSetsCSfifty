#include <cs50.h>
#include <stdio.h>

#define MAXHEIGHT 23

int main(void)
{
    int row, space, hash;
    
    // half-pyramid’s height
    
    int Height; 
		
    do
    {
        printf("enter positive integer( <= %d ) for height: ",MAXHEIGHT);
        Height = GetInt(); 
	}
	while (Height < 0 || Height > MAXHEIGHT);
    
    // loop for buliding half-pyramid blocks
    
    for (row = 1; row <= Height; row++)
    {
        for (space = row; space <= Height - 1; space++)
        {   
            // print sapces
            printf(" ");
        }
        for (hash = 0; hash <= row ; hash++)
        {
            // print hashes
            printf("#");
        }
        
        // print newline
        printf("\n");
    }      
}    
