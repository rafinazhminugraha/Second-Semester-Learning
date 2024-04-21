#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
    node* fourth = NULL;
    node* tail = NULL;

    head = new node();
    second = new node();
    third = new node();
    fourth = new node();
    tail = new node();

    head->data = 2;
    head->next = second;
    
    second->data = 4;
    second->next = third;
    
    third->data = 6;
    third->next = fourth;
    
    fourth->data = 8;
    fourth->next = tail;
    
    tail->data = 10;
    tail->next = NULL;

    node* n = head;

    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    

}
