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

//Delete a node in linked list given head as reference and first occurence of key in the list
void deleteNode(Node** headRef, int key)
{
    Node* delRef = *headRef;  //Store head node
    Node* prev = NULL;

    //If head has the key to be deleted
    if (delRef != NULL && delRef->data == key)
    {
        *headRef = delRef->next;
        delete delRef;
        return;
    }

    //Else search for the key
    else 
    {
        while (delRef != NULL && delRef->data != key)
        {
            prev = delRef;
            delRef = delRef->next;
        }

        if (delRef == NULL) //Key was not found in list
            return;

        prev->next = delRef->next;  //Unlink node from the linked list
        delete delRef;
    }
}

//Deletes the node of a list recursively
void deleteNode(Node*& head, int key)
{
    if (head == NULL)
        return;

    if (head->data == key)
    {
        Node* t = head;
        head = head->next;
        delete(t);
        return;
    }

    deleteNode(head->next, key);

}

//Delete at position
void deleteNode(Node** head_ref, int position)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {

        // Change head
        *head_ref = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
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

