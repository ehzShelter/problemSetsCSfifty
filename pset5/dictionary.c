// dictionary.c

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// primeNumber has chosen for good Hash Function
#define HT_SIZE 1987

char word[LENGTH + 1];

typedef struct node
{
    char* word;
    struct node* next;
}
node;

// hash table contains pointers to the start of linked lists
node* hashtable[HT_SIZE];

// global counter variable to keep track the dictionary word size
int counter;

static unsigned int hash(const char* word)
{
    unsigned int hashing = 0;

    if (word == NULL)
    {
        return -1;
    }

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hashing += word[i];
    }

    return hashing % HT_SIZE;
}

bool check(const char* word)
{
    char buf[LENGTH + 1];

    // still, spell-checker needs to be case-insensitive!
    // load the text word and make them lower case

    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        buf[i] = (char) tolower(word[i]);
    }
    buf[n] = '\0';

    // do not need to search entire hash table for word
    // only need to search linked list starting at hash(buf)
    // linked list to traverse starts at hashtable[hash(buf)]

    node* bucket = hashtable[hash(buf)];

    for (node* entry = bucket; entry != NULL; entry = entry->next)
    {
        // compare word to input with dictionary's word
        // if strings are equal, word is spelled correctly
        if (strcasecmp(entry->word, buf) == 0)
        {
            return true;
        }
    }

    // if end of linked list is reached,
    // word is not spelled correctly
    return false;
}

bool load(const char* dictionary)
{
    FILE* fp = fopen(dictionary, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "couldn't open %s !!\n", dictionary);
        return false;
    }

    // need to iterate over each word in dictionary text file
    // each word must be individually inserted into the hashtable

    while (!feof(fp))
    {
        // Insert word into a node
        node* new = malloc(sizeof(node));

        // use fscanf to read string from file
        // reads one word from dictionary at a time
        fscanf(fp, "%s\n", word);

        size_t n = strlen(word) + 1;

        new->word = malloc(n);

        // loading into memory so-called, copying string into memory
        strncpy(new->word, word, n);

        // index so-called hash value
        int index = hash(word);

        assert((index > HT_SIZE) == 0);

        counter++;

        // no linked list exists yet

        if (hashtable[index] == NULL)
        {
            hashtable[index] = new;
	        new->next = NULL;
        }

        // linked list exists already,
        // so add to the beginning of it
        else
        {
	        new->next = hashtable[index];
	        hashtable[index] = new;
        }
    }

    fclose(fp);

    return true;
}

unsigned int size(void)
{
    return counter;
}

bool unload(void)
{
    // for each element in hashtable
    // for each element in linked list
    // keep track and free element
    // move to next element

    for (int i = 0; i < HT_SIZE; i++)
    {
        node* first = hashtable[i];

        while (first != NULL)
        {
	        node* cursor = first->next;

	        free(first->word);
	        free(first);

            first = cursor;
        }

        hashtable[i] = NULL;
    }

    return true;
}



