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
Node* MiddleOfLL_variation(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
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

Node* Yintersection(Node* head1, Node* head2){
    Node* d1=head1;
    Node* d2=head2;

    while(d1!=d2){
        d1=d1==NULL ? head2: d1->next;
        d2=d2==NULL ? head1: d2->next;
    }
    return d1;
}
Node* getStartingNodeOfLoop(Node* list){
	
	Node* slow=list;
	Node* fast=list;
	
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		
		if(slow==fast){
			slow=list;
			while(slow!=fast){
				slow=slow->next;
				fast=fast->next;
			}
			return slow;
		}
	}

	return NULL;
}
Node* DeleteNthFromLast(Node* head, int N){
    Node* fast=head;
    Node* slow=head;

    for(int i=0; i<N; i++){
        fast=fast->next;
    }
    if(fast==NULL) return head->next;

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;

    return head;
}
class LRUCache {
public:
	class node {
    public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, node*> m;
    node* head;
    node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;

            // Move node to front (most recently used)
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;

            return res;
        }
        return -1;
    }

    void add(int key, int value) {
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            // remove least recently used (just before tail)
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* cache = new LRUCache(capacity);
 * int value = cache->get(key);
 * cache->add(key, value);
 */

int main() {
    Node* head1= new Node(1);
    Node* p2= new Node(2);
    Node* p3= new Node(3);
    Node* p4=new Node(4);

    head1->next=p2;
    p2->next=p3;
    p3->next=p4;
    int N=4;
    head1=DeleteNthFromLast(head1, N);
    printLL(head1);

    
    return 0;
}