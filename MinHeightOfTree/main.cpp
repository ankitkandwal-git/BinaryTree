#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int minHeight(Node* root){
    if(root==NULL) return 0;
    if(root->left ==NULL && root->right==NULL) return 1;
    int leftHeight = INT_MAX, rightHeight = INT_MAX;
    if(root->left) leftHeight = minHeight(root->left);
    if(root->right) rightHeight = minHeight(root->right);
    return  min(leftHeight, rightHeight)+1;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root =NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL): ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val == -1) continue;
        Node* newNode = new Node(val);
        if(root == NULL){
            root = newNode;
            q.push(root);
        }else{
            Node* parent = q.front();
            if(parent->left == NULL){
                parent->left = newNode;
                q.push(newNode);
            }else if(parent->right == NULL){
                parent->right = newNode;
                q.push(newNode);
                q.pop();
        }
    }
    }
    cout<<"Minimum height of the tree is: "<<minHeight(root)<<endl;
}