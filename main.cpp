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
void add(Node* &, float v); //pass by reference to change head itself
void deletenode(Node*, int e);
void insert(Node*, int e, float v);
void deletelist(Node*);

int main() {
    Node *head = nullptr; //means empty list
    
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
    }
    output(head);

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    cin >> entry;
    deletenode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    cin >> entry;
    insert(head, entry, 10000);
    output(head);

    // deleting the linked list
    deletelist(head);
    output(head);

    return 0;
}

void output(Node * head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void add(Node* head, float value) {
        Node *newVal = new Node; //creates new node with pointer newval touching it
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head or if head does not hold real data
            head = newVal; //if list is empty, head will now point at whatever newval is pointing at
            newVal->next = nullptr; //newval->next is pointing down to nothing, so list ends there
            newVal->value = value; //adding random tmp value into value space in the node
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head; //newval->next now points to whatever head is pointing at (first node)
            newVal->value = value;  //adding random tmp value into value space in the node
            head = newVal; //since newval is pointing to the new node being added, head is pointing to that node now as well
        }
}

void deletenode(Node* head, int entry) {
    // deleting a node
    Node * current = head; //ptr current points to same thing as head
    Node * prev = nullptr;

    // traverse that many times and delete that node
    current = head;
    prev = head; //prev points to same as head, which is also what current is pointing to
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
}
void insert(Node* head, int entry, float value){
    // insert a node
    Node * current = head;
    Node * prev = nullptr;
    int count = 0;

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
}
void deletelist(Node* head){
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}