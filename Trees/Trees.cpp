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
vector<vector<int>> LevelOrder(Node* root){
    vector<vector<int>> ans; 
    if (root == nullptr) {
        // If the tree is empty,
        // return an empty vector
        return ans; 
    }
    
    // Create a queue to store nodes
    // for level-order traversal
    queue<Node*> q; 
    // Push the root node to the queue
    q.push(root); 

    while (!q.empty()) {
        // Get the size of the current level
        int size = q.size(); 
        // Create a vector to store
        // nodes at the current level
        vector<int> level; 

        for (int i = 0; i < size; i++) {
            // Get the front node in the queue
            Node* node = q.front(); 
            // Remove the front node from the queue
            q.pop(); 
            // Store the node value
            // in the current level vector
            level.push_back(node->val); 

            // Enqueue the child nodes if they exist
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        // Store the current level
        // in the answer vector
        ans.push_back(level); 
    }
    // Return the level-order
    // traversal of the tree
    return ans;
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