#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node* right;
    struct Node* left;
};

struct Node *delete(struct Node* tree, int number)
{
    if (tree == NULL)
    {
        printf("fail\n");
        return tree;
    }
    if (number < tree->data)
    {
        tree->left = delete(tree->left, number);
    }
    else if (number > tree->data)
    {
        tree->right = delete(tree->right, number);
    }
    else
    {
        if (tree->left == NULL)
        {
            struct Node *ptr = tree->right;
            return ptr;
        }
        else if (tree->right == NULL)
        {
            struct Node *ptr = tree->left;
            return ptr;
        }
        struct Node* ptr = tree->right;
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        tree->data = ptr->data;
        tree->right = delete(tree->right, ptr->data);
    }
    printf("success\n");
    return tree;
}

void *search(struct Node* tree, int number)
{
    while (tree != NULL)
    {
        if (tree->data == number)
        {
            printf("present %d\n", tree->height);
            return;
        }
        else if (tree->data > number)
        {
            tree = tree->left;
        }
        else
        {
            tree = tree->right;
        }
    }
    printf("absent\n");
    return;
}

void *insert(struct Node* tree, int number)
{
    struct Node *ptr = tree;
    struct Node *prev = tree;
    struct Node *node = malloc(sizeof(struct Node));
    int x = 1;
    while(ptr != NULL)
    {
        if (ptr->data == number)
        {
            printf("duplicate\n", ptr->height);
            return;
        }
        
        else if (ptr->data > number)
        {
            prev = ptr;
            ptr = ptr->left;
            x++;
        }
        else
        {
            prev = ptr;
            ptr = ptr->right;
            x++;
        }
    }
    node->data = number;
    node->height = x;
    if (prev->data > number)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }
    printf("inserted %d\n", x);
    return;
}

int main(int argc, char* argv[])
{
    struct Node *tree = malloc(sizeof(struct Node));
    int number = 0;
    char letter;
    if(argc != 2)
    {
        printf("error");
        return 0;
    }
    FILE *input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("error");
        return 0;
    }
    fscanf(input, "%c\t %d\n", &letter, &number);
    while(letter != 'i')
    {
        if(letter == 'd')
        {
            printf("fail\n");
        }
        else
        {
            printf("absent\n");
        }
        fscanf(input, "%c\t %d\n", &letter, &number);
    }
    tree->data = number;
    tree->height = 1;
    tree->left = NULL;
    tree->right = NULL;
    printf("inserted 1\n");
    while(fscanf(input, "%c\t %d\n", &letter, &number) == 2)
    {
        if(letter == 'i')
        {
            insert(tree, number);
        }
        else if(letter == 's')
        {
            search(tree, number);
        }
        else if(letter == 'd')
        {
            tree = delete(tree, number);
        }
        else
        {
            printf("error");
            return 0;
        }
    }
    fclose(input);
    return 0;
}
