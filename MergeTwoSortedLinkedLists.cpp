#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode * newHead;
    if (head1->data >= head2->data){
        newHead = new SinglyLinkedListNode(head2->data);
        head2 = head2->next;
    }
    else {
        newHead = new SinglyLinkedListNode(head1->data);
        head1 = head1->next;
    }
        
    SinglyLinkedListNode * temp = newHead;  
    
    // while both new head aren't NULL
    // compare them then make temp = to the smaller one accordingly
    // handle the case where theyre equal
    while (head1 != NULL && head2 != NULL){ 
        if (head1->data < head2->data){
            temp->next = new SinglyLinkedListNode(head1->data);
            head1 = head1->next;
        } else if (head1->data > head2->data){
            temp->next = new SinglyLinkedListNode(head2->data);
            head2 = head2->next;
        } else {
            temp->next = new SinglyLinkedListNode(head2->data);
            head2 = head2->next;
            temp = temp->next;
            temp->next = new SinglyLinkedListNode(head1->data);
            head1 = head1->next;
        }
        
        temp = temp->next;
    }
    
    if (head1 != NULL || head2 != NULL){
        if (head1 == NULL)
            temp->next = head2;
        else 
            temp->next = head1;
    }
    return newHead;
}
