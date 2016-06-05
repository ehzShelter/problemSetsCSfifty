// cs50, uppercasing the initials
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get name of user
    char* name = GetString();

    if (isalpha(name[0]))
    {
        // print the first character in uppercase
        printf("%c", toupper(*name));
    }

    // loop through the rest
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // check space and end of characters
        if (isspace(name[i]) && name[i + 1] != '\0' && isalpha(name[i + 1]))
        {
            // print the rest of the initials and increment
            printf("%c",toupper(name[i + 1]));
            i++;
        }
    }
    // print a new line after the initials
    printf("\n");

    // free heap allocated memory by GetString
    free(name);
}
