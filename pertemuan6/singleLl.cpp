#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int angka;
    node *next;
};

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->angka = 1;
    head->next = second;
    second->angka = 2;
    second->next = third;
    third->angka = 3;
    third->next = NULL;

    cout << head->angka << endl;
    cout << second->angka << endl;
    cout << third->angka << endl;
    
    return 0;
}

