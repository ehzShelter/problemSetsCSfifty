/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
   int low = 0, high = n-1;
   while(low <= high)
   {
       int mid = (low+high)/2;
       if(value == values[mid])
       {
         return true; //Found value,return(exit)
       }
       else if(value < values[mid])
       {
           high = mid-1; //value lies before mid
       }
       else
       {
           low = mid +1; //value lies after mid
       }
   }
   return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
     int i,min,j,temp;
     for(i=0; i < n-1; i++)
     {
         min = i;
         for(j=i+1; j < n; j++)
         {
            if(values[j] < values[min])
            min = j;           //finding minimum index in array
         }
         
         if(min != i)
         {
            temp = values[i];
            values[i] = values[min];
            values[min] = temp;
         }
     }              
    return;
}
