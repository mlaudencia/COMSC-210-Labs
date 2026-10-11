#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void delete_pos(int pos){
        if(!head) return; // Empty list

        Node* current = head;
        if(pos == 0){  // If deleting head of the list
            head = head->next;
            if(head) // If head->next exists, make its prev nullptr
                head->prev = nullptr;
            else  // If it doesn't exist, that means head is null and the list
                  // is empty, so make the tail nullptr as well.
                tail = nullptr;
            delete current;
            return;
        }

        for(int i = 0; i < pos; i++){ // Go through the list until at pos
            current = current->next;
            if(!current) return; // If current is null at any time, then
                                 // pos was bigger than the list length.
        }

        if(current->next){ // If current is not the tail, then assign the
                           // next of the previous node to the node after
                           // current, and the prev of the next node to the
                           // node before current.
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        else{ // If current is the tail, make the previous node's next null,
              // and then make it the new tail.
            current->prev->next = nullptr;
            tail = current->prev;
        }

        delete current; // Finally, just delete current.
    }

    void pop_front(){
        if(!head) return; // This is basically the same code as in the
                          // (pos == 0) in delete_pos(), check if head exists,
                          // if not, list is empty, so just return.

        Node* temp = head; // Make temp head, and make the new head the
        head = head->next; // node after head.

        if(head) // If it still exists, head's previous node is nullptr,
            head->prev = nullptr;
        else     // If it doesn't exist, the list is empty, so make tail null
            tail = nullptr;

        delete temp; // Finally, delete temp just like the function above
    }

    void pop_back(){
        if(!tail) return; // If tail doesn't exist, list is empty, so return

        Node* temp = tail; // Make the new tail the node before tail
        tail = tail->prev;

        if(tail) // If it exists, that means the list is not empty, so
                 // make the new tail->next nullptr.
            tail->next = nullptr;
        else     // If the tail no longer exists, that means the list is
                 // empty, so make head nullptr as well.
            head = nullptr;

        delete temp; // Then just delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
