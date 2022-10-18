#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
public:
    void printList(Node* n);
    void push(Node** head_ref, int new_data);
    void insertAfter(Node* prev_node, int new_data);
    void append(Node** head_ref, int new_data);
    void deleteN(Node** head, int position);
    void deleteNode(Node** head_ref, int key);
};
void Node::deleteNode(Node** head_ref, int key)
{

    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key) {

      // Changed head
        *head_ref = temp->next;

      // free old head
        delete temp;
        return;
    }

    // Else Search for the key to be
    // deleted, keep track of the
    // previous node as we need to
    // change 'prev->next'
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        // Free memory
        delete temp;
    }
}
void Node::printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
void Node::push(Node** head_ref, int new_data)
{

    // 1. allocate node
    Node* new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. Move the head to point to
    // the new node
    (*head_ref) = new_node;
}
void Node::insertAfter(Node* prev_node, int new_data)
{

    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. Allocate new node
    Node* new_node = new Node();

    // 3. Put in the data
    new_node->data = new_data;

    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}
void Node::append(Node** head_ref, int new_data)
{
        // 1. allocate node
    Node* new_node = new Node();

    // Used in step 5
    Node *last = *head_ref;

    // 2. Put in the data
    new_node->data = new_data;

    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = NULL;

    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // 6. Change the next of last node
    last->next = new_node;
    return;
}
void Node::deleteN(Node** head, int position)
{
    Node* temp;
    Node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}
int main()
{
    Node obj;//creating object just to use functions
    Node* head = NULL;// Start with the empty list

    cout<<"add a number to insert:";
    int n1;
    cin>>n1;
    obj.append(&head, n1);// Insert n1. So linked list becomes n1->NULL

    cout<<"add a number to insert:";
    int n2;
    cin>>n2;
    obj.push(&head, n2);// Insert 7 at the beginning.So linked list becomes 7->6->NULL

    cout<<"add a number to insert:";
    int n3;
    cin>>n3;
    obj.push(&head, n3);// Insert 1 at the beginning.So linked list becomes 1->7->6->NULL

    cout<<"add a number to insert:";
    int n4;
    cin>>n4;
    obj.append(&head, n4);// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL

    cout<<"add a number to insert:";
    int n5;
    cin>>n5;
    obj.insertAfter(head->next, n5);// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL

    cout<<"Created Linked list is: ";
     obj.printList(head);

     obj.deleteN(&head, 2);//this will remove number at second position
     cout<<"\n Created Linked list after deletion is: ";
     obj.printList(head);

      cout<<"\nadd a number to insert:";
    int n6;
    cin>>n6;
    obj.insertAfter(head->next, n6);

     cout<<"add a number to insert:";
    int n7;
    cin>>n7;
    obj.insertAfter(head->next, n7);

    obj.deleteNode(&head, 1);//this will delete the number 1 from the linked list.
    cout<<"\n Created Linked list after second deletion is: ";
     obj.printList(head);

    return 0;
}
