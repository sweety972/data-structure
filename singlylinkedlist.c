#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void displayLinkedList(struct Node* ptr)
{
    struct Node* temp;
    temp = ptr;

    while(temp != NULL)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void insertAtBeginning(int value)
{
    struct Node* newNode = createNode(value);
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node* temp;
    temp = head;
    struct Node* newNode = createNode(value);
    
    if(temp == NULL)
    {
        head = newNode;
    }
    else
    {
        while(temp -> next != 0)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void insertAtMiddle(int position, int value)
{
    struct Node* temp;
    temp = head;
    int i;
    i = 1;
    struct Node* newNode = createNode(value);

    /*if(position == 0)
    {
        head = newNode;
        return;
    }*/

    while(/*temp != NULL || */i < position - 1)
    {
        temp = temp -> next;
        i++;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

    /*if(temp == NULL)
    {
        printf("Linked list is too short...\n");
        return;
    }*/
}

void deleteFromBeginning()
{
    head = head -> next;
}

void deleteFromEnd()
{
    struct Node* temp;
    struct Node* prev;
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
}

int main()
{
    /*int choice;
    int position;
    int value;
    do
    {
        printf("1.Enter a node in the beginning...\n");
        printf("2.Enter a node at the end....\n");
        printf("3.Enter a node at a specific position..\n");
        printf("4.Display linked list...\n");
        printf("5.Exit...\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : 
                printf("Enter the number : ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2 : 
                printf("Enter the number : ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3 : 
                printf("Enter the number : ");
                scanf("%d", &value);
                printf("Insert position : ");
                scanf("%d", &position);
                insertAtMiddle(position, value);
                break;

            case 4 :
                displayLinkedList(head);
                break;

            case 5 :
                break;

            default :
                printf("Invalid choice please try again....\n\n\n");
                break;
        }
    }while(choice != 5);*/
    insertAtBeginning(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);
    insertAtEnd(80);
    displayLinkedList(head);
    insertAtMiddle(3, 99);
    insertAtMiddle(4, 111);
    displayLinkedList(head);
    deleteFromBeginning();
    displayLinkedList(head);
    deleteFromEnd();
    displayLinkedList(head);
}