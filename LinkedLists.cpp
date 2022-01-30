using namespace std; 
#include <iostream>

class Node	//Node of linked list
{

	public: 
		int data;
		Node* next;
};

//Given a reference of the head of a list and data, insert a new node at the head of the list
void insertAtHead(Node** headRef, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;

    *headRef = newNode;
}

//Given a reference of a previous node and data, insert a new node after the previous one
void insertAfter(Node* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        cout << "The previous node cannot be null!";
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//Given a reference of the head of a list and data, insert a new node at the tail of the list
void insertAtTail(Node** headRef, int newData)
{
    Node* newNode = new Node();
    Node* last = *headRef;  //store headRef pointer

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    return;
}

// This function prints contents of
// linked list starting from head
void printLinkList(Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

/* Driver code*/
int main()
{
    Node* head = NULL;

    insertAtTail(&head, 3); //Insert 3 at end of list
    

    insertAtHead(&head, 4); //Insert 4 at the head of list
    insertAtHead(&head, 1); //Insert 1 at the head of list

    insertAtTail(&head, 5); //Insert 3 at end of list

    insertAfter(head, 8); //Insert 8 after second entry of list

    cout << "Created Linked list is: ";
    printLinkList(head);

    return 0;
}

