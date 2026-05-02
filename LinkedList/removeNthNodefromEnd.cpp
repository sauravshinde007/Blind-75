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

//Method1: Finding position from start and then delete
    Node* removeNthFromEnd(Node* head, int n) {
        int l = 0; //length of linked list
        Node* temp = head;

        while(temp != NULL){
            l++;
            temp = temp->next;
        }

        int k = l - n + 1;

        return removeNthNode(head, k);
    }

//Method2: Locating point directly
    Node* removeNthFromEnd(Node* head, int n){
        Node* dummy = new Node(-1);
        dummy->next = head;

        Node* fast = dummy;
        Node* slow = dummy;

        //move fast pointer n+1 place ahead
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }

        //now move fast and slow simuiltaneousy until fast reaches end
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        //now we are at place behind the node to be deleted
        Node* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        delete nodeToDelete;

        //return new head
        return dummy->next;
    }



int main(){
    


    return 0;
}