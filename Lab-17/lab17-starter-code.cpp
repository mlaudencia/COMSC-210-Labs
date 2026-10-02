// COMSC-210 | Lab 17 | Jeremy Laudencia

#include <iostream>
using namespace std;

const int SIZE = 7;  
const int NUMBER_RANGE = 100;
const int TEST_VALUE = 10000;
const int IGNORE_NUM_CHARACTERS = 10000;

struct Node {
    float value;
    Node *next;
};

// These are my protoypes for the functions used. For all of them,
// I passed by reference because I thought it looked cleaner, and
// I felt better being able to make my functions void and what not
// compared to having them return an actual node, or its pointer.
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
// arguments: int SIZE, Node *&head
// returns: nothing
void createLinkedList(int SIZE, Node *&head){
    for (int i = 0; i < SIZE; i++) {
            int tmp_val = rand() % NUMBER_RANGE;
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

// deleteNode() lets the user pick an index of the list and deletes
// the node found at that index.
// arguments: Node *&head
// returns: nothing
void deleteNode(Node *&head){
    if(head == nullptr){
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion
    int entry;

    bool isValid = false; // The below basically validates the user's input.
    while(!isValid){
        cout << "Which node to delete? " << endl;
        output(head);
        cout << "Choice --> ";
        cin >> entry;

        // The below happens when the user inputs something like a word,
        // since it isn't the same data type as entry. If that happens,
        // we clear the "fail state" from the wrong input, and then use
        // cin.ignore() to ignore the old invalid input.
        if(cin.fail()){
            cout << "Invalid input, please enter a different number." << endl;
            cin.clear();
            cin.ignore(IGNORE_NUM_CHARACTERS, '\n');
        }
        // If the user input is a number, we check if it is in range.
        // Right here, we check if it is greater than 1 since you can't
        // delete the node before the head node.
        else if(entry < 1){
            cout << "Out of range, please choose an index shown." << endl;
        }
        // If the user input is greater than 1, then we check if it is in
        // range for numbers more than the size of the list. The below just
        // makes a count, listSize, for all the nodes in the list that aren't
        // the tail. Once the tail is reached, we compare the listSize calculated
        // to the user input. If it is greater than the listSize, then we ask the
        // user to input something again that's valid.
        else{
            int listSize = 0;
            Node *temp = head;
            while(temp != nullptr){
                listSize++;
                temp = temp->next;
            }
            if(entry > listSize){
            cout << "Out of range, please choose an index shown." << endl;
            } else{
                isValid = true;
            }
        }
    }
    
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

// insertNodeAfter() lets the user input an index and inserts a 
// new node after that index, the new node having value 10000.
// arguments: Node *&head
// returns: nothing
void insertNodeAfter(Node *&head){
    int count, entry;
    Node *current = head;
    Node *prev = nullptr;

    cout << "After which node to insert " << TEST_VALUE << "?" << endl;
    count = 1;
    current = head;
        while (current) {
            cout << "[" << count++ << "] " << current->value << endl;
            current = current->next;
        }
    // Like the previous function, we check for valid inputs from the user.
    // The below basically does the same as the validation in deleteNode(),
    // seeing if the input is less than 1 or larger than the size of the list.
    bool isValid = false;
    while(!isValid){
        cout << "Choice --> ";
        cin >> entry;
        if(cin.fail()){
            cout << "Invalid input, please enter a different number." << endl;
            cin.clear();
            cin.ignore(IGNORE_NUM_CHARACTERS, '\n');
        }
        else if(entry < 1 || entry >= count){
            cout << "Out of range, please choose an index shown." << endl;
        }
        else{
            isValid = true;
        }
    }
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

// deleteLinkedList() goes through each node in the list and deletes
// them until the list is empty.
// arguments: Node *&head
// returns: 0
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

// prependNode() takes in a value and makes a new node to be
// the head of the list.
// arguments: Node *&head, float val
// returns: nothing
void prependNode(Node *&head, float val){
    Node *newVal = new Node;
    newVal->value = val; // Make newVal, the new node, value to val.
    newVal->next = head; // Make the next node point to head.
    head = newVal; // Make the new node the new head.
    output(head);
}

// appendNode() takes in a value and makes a new node to be
// the tail of the list.
// arguments: Node *&head, float val
// returns: nothing
void appendNode(Node *&head, float val){
    Node *newVal = new Node;
    newVal->value = val; // Like above, make newVal's value to val.
    newVal->next = nullptr; // Make it's next node point to a nullptr.
    Node *current = head; // Since head is nullptr, basically make current
                          // the head of the list.
    if(!head){  // If head is null, the list is empty, and just make 
                // head = newVal, since its the head and tail of the list.
        head = newVal;
    }
    // The below is basically if the head isn't null, as long as the current
    // node has a node after it, make it the new current, looping until the
    // current-> next is nullptr, which means the current is the tail of the
    // list. After that, just make the tail point to our new node.
    else {
        while(current->next != nullptr){ 
        current = current->next;
        }
        current->next = newVal;
    }
    output(head);
}
