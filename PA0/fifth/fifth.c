#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int arraySize = 0;
    int exponent = 0;
    int isMagic = 0;
    int sum = 0;
    int check = 0;
    int i = 0;
    int j = 0;
    int z = 0;
    int nSize = 0;
    FILE *input = fopen(argv[1], "r");
    fscanf(input, "%d\n", &arraySize);
    if(argc!=2)
    {
        return 0;
    }
    i = arraySize-1;
    j = i;
    int data[arraySize][arraySize];
    while(i < arraySize)
    {
        while(j < arraySize)
        {
            data[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    if(input == NULL)
    {
        return 0;
    }
    i = 0;
    j = 0;
    while(i < arraySize)
    {
        while(j < arraySize)
        {
            fscanf(input,"%d", &data[i][j]);
            j++;
        }
        j = 0;
        fscanf(input, "\n");
        i++;
    }
    for(i = 0; i < arraySize; i++)
    {
        for(j = 0; j < arraySize; j++)
        {
            if(i == j)
            {
                sum = sum + data[i][j];
            }
        }
    }
    for (i = 0; i < arraySize; i++)
    {
        check = 0;
        for(j = 0; j < arraySize; j++)
        {
            check = check + data[i][j];
        }
        if(check == sum)
        {
            isMagic = 1;
        }
        else
        {
            isMagic = 0;
            printf("not-magic");
            return 0;
        }
    }
    for(i = 0; i < arraySize; i++)
    {
        check = 0;
        for(j = 0; j < arraySize; j++)
        {
            check = check + data[i][j];
        }
        if(check == sum)
        {
            isMagic = 1;
        }
        else
        {
            isMagic = 0;
            printf("not-magic");
            return 0;
        }
    }
    nSize = arraySize*2;
    int duplicateArray[nSize];
    for(i = 0; i < arraySize; i++)
    {
        for(j = 0; j < arraySize; j++)
        {
            duplicateArray[z] = data[i][j];
            z++;
        }
    }
    for(z = 0; z < nSize; z++)
    {
        for(i = 0; i < nSize; i++)
        {
            if(z != i)
            {
                if(duplicateArray[z] == duplicateArray[i])
                {
                    isMagic = 0;
                    printf("not-magic");
                    return 0;
                }
            }
        }
    }
    if (isMagic == 1)
    {
        printf("magic");
        return 0;
    }
    else
    {
        printf("not-magic");
        return 0;
    }
    return 0;
}
