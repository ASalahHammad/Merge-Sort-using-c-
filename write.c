#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// This  script fills the text file "nums" with one thousand random numbers between 0 and 1000
// Please note that the numbers should be in type "double", even if they're integers, otherwise the script I wrote "mergesort" won't work
int generate_random()
{
    srand(time(NULL));
    FILE *f = fopen("nums.dat","w");
    if(f==NULL)
    {
        printf("Couldn't open file nums.dat\n");
        return 0;
    }
    double r;
    double x;
    double denominator;
    for(int i=0; i<10; i++)
    {
        denominator = (rand()%10) + 1.0; // this is to generate random numbers of two decimals
        r = (((rand()%11))/10.0)/denominator;
        x = (rand()%100) + r; // this is to generate random numbers of two decimals
        fwrite(&x, sizeof(double), 1, f);
    }
    printf("Successfully generated ten random numbers between 0 and 100 in the text file \"nums.dat\"\n");
    fclose(f);
    return 1;
}