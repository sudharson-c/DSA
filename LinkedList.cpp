#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

struct Node* insertAtLast(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == nullptr)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node* insertAtBeg(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == nullptr)
        head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node* insertAfterVal(struct Node* head, int target, int data) {
    struct Node* newNode = createNode(data);

    struct Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node* delAtBeg(struct Node* head) {
    if (head == nullptr)
        cout << "No elements";
    else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node* delAtLast(struct Node* head) {
    if (head == nullptr)
        cout << "No elements";
    else if (head->next == nullptr) {
        free(head);
        head = nullptr;
    } else {
        struct Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        free(temp->next);
        temp->next = nullptr;
    }
    return head;
}

bool search(int data, struct Node* temp) {
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    struct Node* head = nullptr;
    bool condition = true;

    while (condition) {
        cout << "Linked List Operations:" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Delete Last" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Insert After Value" << endl;
        cout << "7. Search" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                head = insertAtBeg(head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to insert at the end: ";
                cin >> data;
                head = insertAtLast(head, data);
                break;
            }
            case 3: {
                head = delAtBeg(head);
                break;
            }
            case 4: {
                head = delAtLast(head);
                break;
            }
            case 5: {
                cout << "Linked List: ";
                printList(head);
                break;
            }
            case 6: {
                int data, value;
                cout << "Enter value to search after: ";
                cin >> value;
                cout << "Enter data to insert: ";
                cin >> data;
                head = insertAfterVal(head, value, data);
                break;
            }
            case 7: {
                int data;
                cout << "Enter data to search for: ";
                cin >> data;
                bool found = search(data, head);
                if (found) {
                    cout << "Element found in the list." << endl;
                } else {
                    cout << "Element not found in the list." << endl;
                }
                break;
            }
            case 0: {
                cout << "Quitting..." << endl;
                // Free memory here if needed
                condition = false;
                break;
            }
            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }

    return 0;
}
