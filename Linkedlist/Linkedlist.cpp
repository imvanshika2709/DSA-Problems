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
Node* AddTwoLL(Node* list1, Node* list2){
    Node* dummy=new Node(0);
    Node* temp=dummy;
    int carry=0;

    while(list1!=NULL || list2!=NULL || carry){
        int sum=0;
        if(list1!=NULL){
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2!=NULL ){
            sum+=list2->data;
            list2=list2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newnode= new Node(sum%10);
        temp->next=newnode;
        temp=temp->next;
    }
    return dummy->next;
}

int main() {
    Node*head1= new Node(1);
    head1->next=new Node(9);
    head1->next->next=new Node(9);

    Node* head2= new Node(2);
    head2->next= new Node(3);

    Node * ans=AddTwoLL(head1, head2);
    Node* temp=ans;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    
    return 0;
}