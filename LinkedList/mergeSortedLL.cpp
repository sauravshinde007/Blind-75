#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

Node* mergeTwoSortedLL(Node* head1, Node* head2){
    Node* left = head1;
    Node* right = head2;

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(head1 != NULL && head2 != NULL){
        if(left->data < right->data){
            temp->next = left; //point temp to smallest pointer
            left = left->next; 
        }else{
            temp->next = right;
            right = right->next;
        }

        temp = temp ->next;
    }

    //if left portion remains
    if(left != NULL) temp->next = left;

    //if right portion remains
    if(right != NULL) temp->next = right;

    return dummyNode->next;
}



int main(){
    


    return 0;
}