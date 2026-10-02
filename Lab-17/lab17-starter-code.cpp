// COMSC-210 | Lab 17 | Jeremy Laudencia

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// These are my protoypes for the functions used. For all of them,
// I passed by reference because I thought it looked cleaner, and
// I felt better being able to make my functions void and what not
// compared to having them return an actual node.
void output(Node *);
void createLinkedList(int SIZE, Node *&head);
void deleteNode(Node *&head);
void insertNodeAfter(Node *&head);
int deleteLinkedList(Node *&head);
void prependNode(Node *&head, float val);
void appendNode(Node *&head, float val);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    createLinkedList(SIZE, head);

    // prepend a node, put the num at the front(head) of the list
    prependNode(head, 9999);

    // append a node, put the num at the end(tail)of the list
    appendNode(head, 12345);

    // deleting a node
    deleteNode(head);

    // insert a node
    insertNodeAfter(head);

    // deleting the linked list
    deleteLinkedList(head);
    
}

// This was already written, so I don't have much to say.

// output() prints all the values of the list.
// arguments: Node *hd, the head node
// returns: nothing
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// createdLinkedList() makes a list of size SIZE and fills it with
// random values from 0-99.
// arguments:
void createLinkedList(int SIZE, Node *&head){
    for (int i = 0; i < SIZE; i++) {
            int tmp_val = rand() % 100;
            Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
}

void deleteNode(Node *&head){
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);
}

void insertNodeAfter(Node *&head){
    int count, entry;
    Node *current = head;
    Node *prev = nullptr;

    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
        while (current) {
            cout << "[" << count++ << "] " << current->value << endl;
            current = current->next;
        }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

}


int deleteLinkedList(Node *&head){
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

// Comment below since there wasnt any code for it
void prependNode(Node *&head, float val){
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = head;
    head = newVal;
    output(head);
}

void appendNode(Node *&head, float val){
    Node *newVal = new Node;
    newVal->value = val;
    newVal->next = nullptr;
    Node *current = head;
    if(!head){
        head = newVal;
    }
    else {
        while(current->next != nullptr){
        current = current->next;
        }
        current->next = newVal;
    }
    output(head);
}
