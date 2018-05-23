#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int length;
    int length2 = strlen(argv[1]);
    char letter[100];
    char *final = (char *)malloc(sizeof(char)*((length2 * 2) + 1));
    int i = 0;
    int j = 0;
    int z = 0;
    if(argc != 2)
    {
        printf("error");
        return 0;
    }
    for(i = 0; i < length2; i++)
    {
        if(argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            printf("error");
            return 0;
        }
        final[j++] = argv[1][i];
        length = 1;     
        while(i + 1 < length2 && argv[1][i] == argv[1][i+1])
        {
            length++;
            i++;
        }
        sprintf(letter, "%d", length);
        for(z = 0; *(letter+z); z++, j++)
        { 
            final[j] = letter[z]; 
        } 
    }

    if(strlen(argv[1]) < strlen(final))
    {
        printf("%s", argv[1]);
        return 0;
    }
    printf("%s", final);
    return 0;
}

