#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int key1, int key2)
{
     int x = 0;
     x = array[key2];
     array[key2] = array[key1];
     array[key1] = x;
}

int max(int array[], int key)
{
    int i = 0;
    int index = key;
    for(i = 0; i < key; i++)
    {
        if(array[i] > array[index])
            index = i;
    }
    return index;
}

void sort(int array[], int length)
{
     int i = 0;
     int maxValue = 0;
     for(i = 0; i < length; i++)
     {
         maxValue = max(array, length-i-1);
         swap(array, maxValue, length-i-1);
     }     
}

int main(int argc, char* argv[])
{
    int number;
    int arraySize;
    int i = 0;
    FILE *input = fopen(argv[1], "r");
    fscanf(input, "%d\n", &arraySize);
    if(argc!=2)
    {
        return 0;
    }
    int data[arraySize];
    while(i >= 0)
    {
        data[i] = 0;
        i--;
    } 
    if(input == NULL)
    {
        return 0;
    }
    i = 0;
    while(!feof(input))
    { 
        fscanf(input,"%d\t", &number);
        data[i]= number;
        i++;
    }
    sort(data, arraySize);
    for(i = 0; i < arraySize;i++)
    {
        printf("%d\t", data[i]);
    }
    return 0;
}
