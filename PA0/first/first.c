#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *insert(struct Node *head, int number)
{
    struct Node *newHead;
    struct Node *ptr;
    struct Node *prev;
    if (head == NULL)
    {
        head = malloc(sizeof(struct Node));
        if(head == NULL)
        {
            return head;
        }
        head->data = number;
        head->next = NULL;
        return head;
    }
    newHead = malloc(sizeof(struct Node));
    if(newHead == NULL)
    {
        return newHead;
    }
    newHead->data = number;
    newHead->next = NULL;
    if (number < head->data)
    {
        newHead->next = head;
        return newHead;
    }
    ptr = head->next;
    prev = head;
    while(ptr != NULL && ptr->data < number)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    newHead->next = ptr;
    prev->next = newHead;
    return head;
}

struct Node *delete(struct Node *head, int number)
{
    struct Node *prev = head;
    struct Node *ptr = head;
    if(head == NULL)
    {
        return head;
    }
    if(head->data == number)
    {
        return head->next;
    }
    while(ptr != NULL)
    {
        if(ptr->data == number)
        {
            prev->next = ptr->next;
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return head;
}

int main(int argc, char* argv[])
{
    struct Node *head;
    struct Node *ptr;
    int number = 0;
    int nodes = 0;
    char letter;
    if (argc != 2)
    {
        return 0;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        return 0;
    }
    while(fscanf(input, "%c\t %d\n", &letter, &number) == 2)
    {
        if(letter == 'i')
        {
            head = insert(head, number);
        }
        else if(letter == 'd')
        {
            head = delete(head, number);
        }
        else
        {
            return 0;
        }
    }
    if(!feof(input))
    {
        return 0;
    }
    ptr = head;
    while (head != NULL)
    {
      nodes = nodes + 1;
      head = head->next;
    }
    printf("%d\n", nodes);
    while (ptr != NULL)
    {
      printf("%d\t", ptr->data);
      ptr = ptr->next;
    }
    fclose(input);
    return 0;    
}
