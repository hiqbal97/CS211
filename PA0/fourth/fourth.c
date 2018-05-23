#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int arraySize = 0;
    int exponent = 0;
    int i = 0;
    int j = 0;
    int z = 0;
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
    fscanf(input, "%d\n", &exponent);
    int resultantArray[arraySize][arraySize];
    for(i = 0; i < arraySize; i++)
    {
        for(j = 0; j < arraySize; j++)
        {
            resultantArray[i][j] = 0;
        }
    }
    if(exponent >= 2)
    {
        int resultantArray2[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray2[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray2[i][j] += (data[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray2[i][j];
            }
        }
    }
    if(exponent >= 3)
    {
        int resultantArray3[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray3[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray3[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray3[i][j];
            }
        }
    }
    if(exponent >= 4)
    {
        int resultantArray4[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray4[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray4[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray4[i][j];
            }
        }
    }
    if(exponent >= 5)
    {
        int resultantArray5[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray5[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray5[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray5[i][j];
            }
        }
    }
    if(exponent >= 6)
    {
        int resultantArray6[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray6[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray6[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray6[i][j];
            }
        }
    }
    if(exponent >= 7)
    {
        int resultantArray7[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray7[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray7[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray7[i][j];
            }
        }
    }
    if(exponent >= 8)
    {
        int resultantArray8[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray8[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray8[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray8[i][j];
            }
        }
    }
    if(exponent >= 9)
    {
        int resultantArray9[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray9[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray9[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray9[i][j];
            }
        }
    }
    if(exponent >= 10)
    {
        int resultantArray10[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray10[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray10[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray10[i][j];
            }
        }
    }
    if(exponent >= 11)
    {
        int resultantArray11[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray11[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray11[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray11[i][j];
            }
        }
    }
    if(exponent >= 12)
    {
        int resultantArray12[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray12[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray12[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray12[i][j];
            }
        }
    }
    if(exponent >= 13)
    {
        int resultantArray13[arraySize][arraySize];
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray13[i][j] = 0;
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                for(z = 0; z < arraySize; z++)
                {
                    resultantArray13[i][j] += (resultantArray[i][z] * data[z][j]);
                }
            }
        }
        for(i = 0; i < arraySize; i++)
        {
            for(j = 0; j < arraySize; j++)
            {
                resultantArray[i][j] = resultantArray13[i][j];
            }
        }
    }
    i = 0;
    j = 0;
    while(i < arraySize)
    {
        while(j < arraySize)
        {
            printf("%d\t", resultantArray[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }
    return 0;
}
