// COMSC-210 | Lab 21 | Jeremy Laudencia

// Here, <iostream> is included for couts and stuff, "Goat.cpp" for
// goat objects, and then <cstdlib> and <ctime> for random generation.

// Most of this stuff is just the code from the demo but changed, so
// I don't think I will have much to comment on.
#include <iostream>
#include "Goat.cpp"
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        // Here, I changed the data from int to Goat.
        Goat goat;
        Node* prev;
        Node* next;
        // Same thing here, used to be an int data type, now is Goat.
        Node(Goat given, Node* p = nullptr, Node* n = nullptr) {
            goat = given; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        // Once again, I changed the int data type to Goat.
        // I did the same thing for the push_front() function.
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) {
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

    void delete_node(Goat value) {
        if (!head) return; // Empty list

        Node* temp = head;
        // Here, I had to edit the conditions of the while loop. Before,
        // temp compared an int to an int for easy comparison if value and
        // temp were the same, so instead of an int to int comparison,
        // I made some getters in the Goat class to compare the name, age
        // and color of the goats to make sure they weren't the same, so that
        // the function could search for the right Goat object to delete.
        while (temp && (temp->goat.getAge() != value.getAge() ||
                temp->goat.getColor() != value.getColor() ||
                temp->goat.getName() != value.getName()))
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

    void print() {
        Node* current = head;
        // Here, I added a statement to tell the user that the list is empty
        // like the instructions in the lab asked for. It is the same for 
        // print_reverse().
        if (!current){
            cout << "List is empty. Fill the list with objects, then rerun" <<
            " the program." << endl;
            return;
        };
        while (current) {
            // Here and for print_reverse(), I made a print function in the
            // Goat class, since this function was handling integers before,
            // so that made it easier to just use a cout to print. I couldn't
            // do that with my Goat objects, so this is what I did.
            current->goat.print();
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current){
            cout << "List is empty. Fill the list with objects, then rerun" <<
            " the program." << endl;
            return;
        };
        while (current) {
            current->goat.print();
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
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i){
        Goat g;
        list.push_back(g);
    }
    cout << "List forward: " << endl;
    list.print();

    cout << "List backward: " << endl;
    list.print_reverse();

    // In the original demo code, the below used a destructor to show an empty
    // list, but since
    DoublyLinkedList emptyList;
    cout << "Empty list test: ";
    emptyList.print();

    return 0;
}
