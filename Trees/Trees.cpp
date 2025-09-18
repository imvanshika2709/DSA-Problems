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
    cout<<root->val<<" ";
    Inorder(root->right);

} 
void Postorder(Node* root){
    if(root==NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->val<<" ";
    
} 
int HeightofBT(Node* root){
        
        if(root == NULL){
            return 0;
        }
           
        int lh = HeightofBT(root->left);
        int rh = HeightofBT(root->right);
        
        return 1 + max(lh, rh);
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
        
        return ans; 
    }
    
    
    queue<Node*> q; 
    q.push(root); 

    while (!q.empty()) {
        
        int size = q.size(); 
        
        vector<int> level; 

        for (int i = 0; i < size; i++) {
            
            Node* node = q.front(); 
            
            level.push_back(node->val); 
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
       
        ans.push_back(level); 
    }
    return ans;
}
int PathSum(Node* root, int& maxsum) {
    if (root == NULL) return 0;

    // if path goes negative, ignore it (take 0 instead)
    int leftsum = max(0, PathSum(root->left, maxsum));
    int rightsum = max(0, PathSum(root->right, maxsum));

    // best path including both children
    maxsum = max(maxsum, leftsum + rightsum + root->val);

    // return best downward path (only one side allowed)
    return max(leftsum, rightsum) + root->val;
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    PathSum(root, maxi);
    return maxi;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if(root==NULL || root==p || root==q) return root;
	
	Node* left=lowestCommonAncestor(root->left, p, q);
	Node* right=lowestCommonAncestor(root->right, p,q);
	
	if(left==NULL) return right;

	else if(right==NULL) return left;
    
	else return root;
}
void KthSmallest_util(Node* root, int& counter, int k, int& ksmallest){
    if(root== NULL || counter>=k) return ;

    KthSmallest_util(root->left, counter, k, ksmallest);

    counter++;
    if(counter==k){
        ksmallest=root->val;
        return;
    }

    KthSmallest_util(root->right, counter, k, ksmallest);

}
int KthSmallest(Node* root, int k){
    int counter=0;
    int ksmallest=INT_MIN;

    KthSmallest_util(root, counter, k, ksmallest);
    return ksmallest;

}
void KthLargestBST_util(Node* root, int& counter, int k, int& klargest){
    if(root== NULL || counter>=k) return ;

    KthLargestBST_util(root->right, counter, k, klargest);

    counter++;
    if(counter==k){
        klargest=root->val;
        return;
    }

    KthLargestBST_util(root->left, counter, k, klargest);

}
int KthLargestBST(Node* root, int k){
    int counter=0;
    int klargest=INT_MAX;

    KthLargestBST_util(root, counter, k, klargest);
    return klargest;

}
vector<int> leftView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();  // number of nodes in current level

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            // first node at this level → add to left view
            if (i == 0) ans.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}

int main() {


    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    Postorder(root);




    
    
    return 0;
}