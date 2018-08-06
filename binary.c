#include <stdlib.h>
#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}


int main(int argv, char* argc[])
{
        int i = 23;
        int ui = 3212332;
        float f = 23.45f;
        printBits(sizeof(i), &i);
        printBits(sizeof(ui), &ui);
        printBits(sizeof(f), &f);
        return 0;
}