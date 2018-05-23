#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int attributes = 0;
    int lines = 0;
    int i = 0;
    int j = 0;
    FILE *training = fopen(argv[1], "r");
    fscanf(training, "%d\n", &attributes);
    fscanf(training, "%d\n", &lines);
    attributes = attributes + 1;
    double* prices;
    prices = (double*)malloc(lines*sizeof(double));
    i = 0;
    j = 0;
    while(i < lines)
    {
        prices[i] = 0;
        i++;
    }
    double** data;
    data = (double**)malloc(lines*sizeof(double*));
    i = 0;
    j = 0;
    while(i < lines)
    {
        while(j < attributes)
        {
            data[i] = (double*)malloc(attributes*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < lines)
    {
        while(j < attributes)
        {
            data[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < lines)
    {
        prices[i] = 0;
        i++;
    }
    if(training == NULL)
    {
        return 0;
    }
    i = 0;
    j = 0;
    int k = 0;
    while(i < lines)
    {
        while(j < attributes)
        {
            if(j == 0)
            {
                data[i][j] = 1;
            }
            else
            {
                fscanf(training,"%lf%*c", &data[i][j]);
            }
            if(j == (attributes - 1))
            {
                fscanf(training,"%lf", &prices[i]);
            }
            j++;
        }
        j = 0;
        i++;
    }
    fclose(training);
    i = 0;
    double** transpose;
    transpose = (double**)malloc(attributes*sizeof(double*));
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < lines)
        {
            transpose[i] = (double*)malloc(lines*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < lines)
        {
            transpose[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    for(i = 0; i < attributes; i++)
    {
        for (j = 0; j < lines; j++)
        {
            transpose[i][j] = data[j][i];
        }
    }
    double** multiplied;
    multiplied = (double**)malloc(attributes*sizeof(double*));
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes)
        {
            multiplied[i] = (double*)malloc(attributes*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    k = 0;
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes)
        {
            multiplied[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    for(i = 0; i < attributes; i++)
    {
        for(j = 0; j < attributes; j++)
        {
            for(k = 0; k < lines; k++)
            {
                multiplied[i][j] += data[k][j]*transpose[i][k];
            }
        }
    }
    double** augmented;
    augmented = (double**)malloc(attributes*sizeof(double*));
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes*2)
        {
            augmented[i] = (double*)malloc((attributes*2)*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    double** inverse;
    inverse = (double**)malloc(attributes*sizeof(double*));
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes)
        {
            inverse[i] = (double*)malloc(attributes*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes)
        {
            inverse[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < attributes)
    {
        while(j < attributes)
        {
            augmented[i][j] = multiplied[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    for(i = 0; i < attributes; i++)
    {
        for(j = attributes; j < 2*attributes; j++)
        {
            if(i == j%attributes)
            {
                augmented[i][j]=1;
            }
            else
            {
                augmented[i][j]=0;
            }
        }
    }
    int x = 0;
    double stored = 0;
    double inv = 0;
    for(j = 0; j < attributes; j++)
    {
        x = j;
        for(i = j + 1; i < attributes; i++)
        {
            if(augmented[i][j] > augmented[x][j])
            {
                x = i;
            }
        }
        if(x != j)
        {
            for(k = 0; k < 2*attributes; k++)
            {
                stored = augmented[j][k];
                augmented[j][k] = augmented[x][k];
                augmented[x][k] = stored;
            }
        }
        for(i = 0; i < attributes; i++)
        {
            if(i != j)
            {
                inv = augmented[i][j];
                for(k = 0; k < 2*attributes; k++)
                {
                    augmented[i][k] -= (augmented[j][k]/augmented[j][j])*inv;
                }
            }
            else
            {
                inv = augmented[i][j];
                for(k = 0; k < 2*attributes; k++)
                {
                    augmented[i][k] /= inv;
                }
            }
        }
    }
    i = 0;
    j = attributes;
    k = 0;
    while(i < attributes)
    {
        while(j < attributes*2)
        {
            inverse[i][k] = augmented[i][j];
            k++;
            j++;
        }
        k = 0;
        j = attributes;
        i++;
    }
    double* m;
    m = (double*)malloc(attributes*sizeof(double));
    i = 0;
    while(i < attributes)
    {
        m[i] = 0;
        i++;
    }
    for(i = 0; i < attributes; i++)
    {
        for(j = 0; j < 1; j++)
        {
            for(k = 0; k < lines; k++)
            {
                m[i] += transpose[i][k]*prices[k];
            }
        }
    }
    double* weights;
    weights = (double*)malloc(attributes*sizeof(double));
    i = 0;
    j = 0;
    while(i < attributes)
    {
        weights[i] = 0;
        i++;
    }
    for(i = 0; i < attributes; i++)
    {
        for(j = 0; j < 1; j++)
        {
            for(k = 0; k < attributes; k++)
            {
                weights[i] += inverse[i][k]*m[k];
            }
        }
    }
    int line = 0;
    FILE *test = fopen(argv[2], "r");
    fscanf(test, "%d\n", &line);
    double** testData;
    testData = (double**)malloc(line*sizeof(double*));
    i = 0;
    j = 0;
    while(i < line)
    {
        while(j < attributes)
        {
            testData[i] = (double*)malloc(attributes*sizeof(double));
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < line)
    {
        while(j < attributes)
        {
            testData[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    while(i < line)
    {
        while(j < attributes)
        {
            if(j == 0)
            {
                testData[i][j] = 1;
            }
            else
            {
                fscanf(test,"%lf%*c", &testData[i][j]);
            }
            j++;
        }
        j = 0;
        i++;
    }
    double* final;
    final = (double*)malloc(line*sizeof(double));
    i = 0;
    while(i < line)
    {
        final[i] = 0;
        i++;
    }
    for(i = 0; i < line; i++)
    {
        for(j = 0; j < 1; j++)
        {
            for(k = 0; k < attributes; k++)
            {
                final[i] += testData[i][k]*weights[k];
            }
        }
    }
    i = 0;
    while(i < line)
    {
        printf("%0.0lf\n", final[i]);
        i++;
    }
    fclose(test);
    return 0;
}
