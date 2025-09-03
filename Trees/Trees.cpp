#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};



void Inorder(Node* root){
    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->val<<endl;
    Inorder(root->right);

} 

bool IsIdentical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;

    return (root1->val==root2->val) && 
    IsIdentical(root1->left, root2->left) && 
    IsIdentical(root1->right, root2->right);
}
Node* InvertTree(Node* root){

    if(root==NULL) return NULL;

    swap(root->left, root->right);
    InvertTree(root->left);
    InvertTree(root->right);

    return root;
    /*
    1
   2   3
 4

     1
   3   2
         4

 */
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if(root==NULL || root==p || root==q) return root;
	
	Node* left=lowestCommonAncestor(root->left, p, q);
	Node* right=lowestCommonAncestor(root->right, p,q);
	
	if(left==NULL) return right;

	else if(right==NULL) return left;
    
	else return root;
}
int main() {


   Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

   InvertTree(root);
   Inorder(root);



    
    
    return 0;
}