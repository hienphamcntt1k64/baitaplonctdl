#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};


class LinkedListStack {
private:
    Node* head;

public:
    LinkedListStack() : head(nullptr) {}

    ~LinkedListStack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }


    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }


    int top() {
        if (head == nullptr) return -1;
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    int T;
    cin >> T;

    LinkedListStack stack;

    while (T--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int n;
            cin >> n;
            stack.push(n);
        }
        else if (query_type == 2) {
            stack.pop();
        }
        else if (query_type == 3) {
            if (!stack.isEmpty()) {
                cout << stack.top() << endl;
            } else {
                cout << "Empty!" << endl;
            }
        }
    }

    return 0;
}
