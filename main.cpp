//Avleen Gill - 210 Lab 17
//modularize linked list

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void add(Node*, float v);
void deletenode(Node*, float v);

int main() {
    Node *head = nullptr; //means empty list
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    /*for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node; //creates new node with pointer newval touching it
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head or if head does not hold real data
            head = newVal; //if list is empty, head will now point at whatever newval is pointing at
            newVal->next = nullptr; //newval->next is pointing down to nothing, so list ends there
            newVal->value = tmp_val; //adding random tmp value into value space in the node
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head; //newval->next now points to whatever head is pointing at (first node)
            newVal->value = tmp_val;  //adding random tmp value into value space in the node
            head = newVal; //since newval is pointing to the new node being added, head is pointing to that node now as well
        }
    }
    output(head); */

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void output(Node* head, float value) {
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node; //creates new node with pointer newval touching it
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head or if head does not hold real data
            head = newVal; //if list is empty, head will now point at whatever newval is pointing at
            newVal->next = nullptr; //newval->next is pointing down to nothing, so list ends there
            newVal->value = tmp_val; //adding random tmp value into value space in the node
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head; //newval->next now points to whatever head is pointing at (first node)
            newVal->value = tmp_val;  //adding random tmp value into value space in the node
            head = newVal; //since newval is pointing to the new node being added, head is pointing to that node now as well
        }
    }
    output(head);
}
void deletenode(Node* head, float value) {
    
}