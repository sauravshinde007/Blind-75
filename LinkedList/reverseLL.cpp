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
}

//Method 1: Reverse Links of each node
Node* reverseLL(Node* head){
    //Use 3 pointers
    Node* curr = head; //points head
    Node* Next; //points to curr's next
    Node* Prev = nullptr;

    //Now in each iteration 
    while(curr != nullptr){
        // 1. store Next of curr
        Next = curr->next;

        // 2. point next of curr to prev
        curr->next = Prev;

        // 3. move prev to curr
        Prev = curr;

        // 4. move curr to Next
        curr = Next;
    }

    return Prev;
}



int main(){
    


    return 0;
}