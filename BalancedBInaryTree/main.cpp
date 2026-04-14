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

int balancedBT(Node* root){
    if(root==NULL) return 0;
    int leftSubTree = balancedBT(root->left);
    int rightSubTree = balancedBT(root->right);
    int diff = abs(leftSubTree - rightSubTree);
    if(diff>1) return -1;
    else return max(leftSubTree, rightSubTree) + 1;
}

bool isBalanced(Node* root){
    return balancedBT(root)!=-1;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes: ";
    queue<Node*>q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        if(root==NULL){
            root = new Node(val);
            q.push(root);
        }
        else {
            Node* temp = q.front();
            if(temp->left == NULL){
                temp->left = new Node(val);
                q.push(temp->left);
            }
            else if(temp->right == NULL){
                temp->right = new Node(val);
                q.push(temp->right);
                }
        }
    }
    if(isBalanced(root)) cout<<"The tree is balanced."<<endl;
    else cout<<"The tree is not balanced."<<endl;
}