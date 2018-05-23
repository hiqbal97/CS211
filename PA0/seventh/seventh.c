#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 1;
    int length = 0;
    while(i < argc)
    {
        length = strlen(argv[i]);
        printf("%c", argv[i][length-1]);
        i++;
    }
    return 0;
}
