#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1+max(leftHeight,rightHeight);
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL): ";
    queue<Node*>q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1){
            continue;
        }
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
        }
        else{
            Node* parent = q.front();
            if(parent->left==NULL){
                parent->left = newNode;
            }
            else{
                parent->right = newNode;
                q.pop();
            }
        }
        q.push(newNode);
    }
    cout<<"Height of the tree is: "<<height(root)<<endl;
}