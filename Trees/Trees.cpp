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

void helper(Node* root, vector<int>& ans){

    if(root==NULL) return;
    helper(root->left,ans);
    ans.push_back(root->val);
    helper(root->right,ans);
}

vector<int> Inorder(Node* root){
    vector<int> ans;

    helper(root, ans);
    return ans;
} 

bool IsIdentical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;

    return (root1->val==root2->val) && 
    IsIdentical(root1->left, root2->left) && 
    IsIdentical(root1->right, root2->right);
}
int main() {

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    //root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout << (IsIdentical(root1, root2) ? "Identical" : "Not Identical") << endl;

    
    
    return 0;
}