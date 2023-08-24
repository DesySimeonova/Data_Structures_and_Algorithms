
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next=nullptr) {
        this->data = data;
        this->next = next;
    }
};

class List {
private:
    Node* head;
    Node* tail;
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void pushBack(int num) {
        if (head == nullptr) {
            head = new Node(num);
            tail = head;
        }
        else {
            tail->next = new Node(num);
            tail = tail->next;
        }
    }

    void pushFront(int num) {
        Node* newHead = new Node(num);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void print(){
        Node* n = head;
        while (n != nullptr) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << "\n";
    }

    void addNode(int num, int pos) {
        if (pos == 0) {
            pushFront(num);
            return;
        }
        else if(head==nullptr){
            throw logic_error("Invalid index! List is empty!");
        }
        Node* curr=head;
        Node* prev=nullptr;
        for (int i = 0; i < pos; i++) {
            if (curr != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            else {
                throw logic_error("Invalid position!");
            }
            prev->next = new Node(num);
            prev->next->next = curr;
            if (tail == prev) {
                tail = prev->next;
            }
        }
    }

    void deleteFirst() {
        if (head != nullptr) {
            if (head == tail){
                tail = nullptr;
            }
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
        else {
            throw logic_error("List is empty!");
        }
    }

    void deleteLast() {
        if (tail != nullptr) {
            if (head == tail) {
                deleteFirst();
            }
            Node* curr;
            Node* prev;
            while (curr != tail) {
                prev = curr;
                curr = curr->next;
            }
            tail = prev;
            prev->next = nullptr;
            delete curr;
        }
    }

    void deleteNode(int pos) {
        if (pos == 0) {
            deleteFirst();
        }
        else if (head == nullptr) {
            throw logic_error("List is empty!");
        }
        Node* prev = nullptr;
        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr = tail) {
            tail = prev;
        }
        delete curr;
    }
    
    bool search(int x) {
        if (head == nullptr) {
            throw logic_error("List is empty!");
        }
        Node* iter = head;
        while (iter != nullptr) {
            if (iter->data == x) {
                return true;
            }
            iter = iter->next;
        }
        return false;
    }

    void reverse() {
        if (head = nullptr) {
            throw logic_error("List is empty!");
        }
        if (head == tail) {
            return;
        }
        Node* curr = head;
        Node* next=head->next;
        Node* prev=nullptr;
        while (curr != tail) {
            prev = curr;
            curr = next;
            next = curr->next;
            curr->next = prev;
        }
        tail = head;
        head = curr;
        tail->next = nullptr;
    }

};


int main()
{
    
}


