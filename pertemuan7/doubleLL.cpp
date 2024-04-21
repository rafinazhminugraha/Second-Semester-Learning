#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main(int argc, char const *argv[])
{
    node *head;
    node *one = NULL;
    node *two = NULL;
    node *third = NULL;
    node *current = NULL;

    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    one->data = 1;
    two->data = 2;
    third->data = 3;

    one->next = two;
    one->prev = NULL;
    
    two->next = third;
    two->prev = NULL;
    
    third->next = NULL;
    third->prev = two;

    head = one;

    current = head;
    cout << current->data << endl;

    while (current ->next != NULL)
    {
        current = current->next;
        cout << current->data << endl;
    }
    

    return 0;
}
