#include<iostream>
#include"node.h"
using namespace std;


int main(){
    Node n1 = Node{1};
    Node n2 = Node{2};
    n1.next = &n2;
    Node n3 = Node{3};
    n2.next = &n3;
    Node n4 = Node{4};
    n3.next = &n4;
    Node n5 = Node{5};
    n4.next = &n5;

    Node * n_ptr = &n1;

    cout << n1.data << endl;
    cout << n1.next << endl;

    while (n_ptr != NULL){
        cout << (*n_ptr).data << ' ';
        n_ptr = (*n_ptr).next;
    }
    cout <<endl;


    Node * tail_ptr = &n1;
    Node * head_ptr = tail_ptr->next;
    Node * next_ptr = head_ptr->next;
    
    tail_ptr->next = nullptr;
    while (true){
       head_ptr->next = tail_ptr;
       if (next_ptr == NULL){
            break;
       }
       tail_ptr = head_ptr;
       head_ptr = next_ptr;
       next_ptr = next_ptr->next;
    }

    while (head_ptr != NULL){
        cout << head_ptr->data << ' ';
        head_ptr = head_ptr->next;
    }
    cout <<endl;

    return 0;
}