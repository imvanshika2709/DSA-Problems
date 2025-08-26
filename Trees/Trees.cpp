#include <bits/stdc++.h>
using namespace std;

class Node{
public: 
    Node* left;
    Node* right;
    int val;

    Node(int val1){
        int val=val1;
        left=nullptr;
        right=nullptr; 
    }
};

void helper(Node* root, vector<int>& ans){

    if(root==NULL) return;
    Inorder(root->left);
    ans.push_back(root->val);
    Inorder(root->right);
}

vector<int> Inorder(Node* root){
    vector<int> ans;

    helper(root, ans);
    return ans;
} 

int main() {

    
    
    return 0;
}