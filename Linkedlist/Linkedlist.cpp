#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* ReverseLL(Node* head){
    Node* prev=NULL; Node* temp=head;

    while(temp!=NULL){
        Node* front=temp->next; //1->2->3->4
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
    return head;

}

Node* Add1toLL(Node* head){
    head=ReverseLL(head);

    Node* temp=head;
    int carry=1;

    while(temp!=nullptr){
        temp->data+=carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newnode= new Node(1);
        newnode->next=head;
        return newnode;
    }
    head=ReverseLL(head);
    return head;

}

int main() {
    Node*head= new Node(1);
    head->next=new Node(9);
    head->next->next=new Node(9);

    Node * ans=Add1toLL(head);
    Node* temp=ans;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    
    return 0;
}