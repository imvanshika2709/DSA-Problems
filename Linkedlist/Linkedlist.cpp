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
bool DetectCycle_brute(Node* head){
    unordered_map<Node*,int> mpp;

    Node* temp=head;

    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()) return true;
        mpp[temp]++;
        temp=temp->next;
    }
    return false;
}
bool DetectCycle_optimal(Node* head){

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;

    }
    return false;
}
Node* MiddleOfLL(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int LengthOfLoop(Node* slow, Node* fast){
    int count=1;
    fast=fast->next;

    while(slow!=fast){
        fast=fast->next;
        count++;
    }
    return count;
}

int FindLength(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return LengthOfLoop(slow, fast);
        }
    }
    return 0;
}

int main() {
    Node* head1=new Node(1);
    Node* first= new Node(2);
    Node* second= new Node(3);
    Node* third= new Node(4);
    Node* fourth= new Node(5);


    head1->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=second;

    int ans=FindLength(head1);
    cout<<ans;
    
    return 0;
}