#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void initRandon()
{
    srand(time(NULL));
}


/* Random number generator  */

int randomUCP(int low, int high)
{
    int number = -1;
    if (low <= high)
    {
        number = (rand() % (high - low + 1)) + low;
        return number;
    }
    return -1;
}
