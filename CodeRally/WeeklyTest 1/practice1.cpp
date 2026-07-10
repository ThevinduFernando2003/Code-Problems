#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int nodeData) {
        this->data = nodeData;
        this->next = NULL;
    }
};

void printLinkedList(SinglyLinkedListNode* head) {
    if (head == NULL){
        return;
    }
    SinglyLinkedListNode* current = head;
    while(current != NULL) {
        cout << current->data << "\n";
        current = current->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    if (!(cin >> n)) return 0;

    SinglyLinkedListNode* head = NULL;
    SinglyLinkedListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int nodeData;
        cin >> nodeData;

        SinglyLinkedListNode* node = new SinglyLinkedListNode(nodeData);

        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }    

    printLinkedList(head);
    return 0;
}
