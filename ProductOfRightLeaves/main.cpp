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

int productOfRightLeaves(Node* root){
    if(root == NULL) return 1;
    if(root->right == NULL && root->left == NULL) return 1;
    int product = 1;
    if(root->right != NULL && root->right->left == NULL && root->right->right==NULL){
        product*= root->right->data;
    }
    return product * productOfRightLeaves(root->left) * productOfRightLeaves(root->right);
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the nodes values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root==NULL){
            root = new Node(val);
        }
        else {
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp->left == NULL){
                    temp->left = new Node(val);
                    break;
                }
                else{
                    q.push(temp->left);
                }
                if(temp->right == NULL){
                    temp->right = new Node(val);
                    break;
                }
                else{
                    q.push(temp->right);
                }
            }
        }
    }
    cout<<"Product of right leaves: "<<productOfRightLeaves(root)<<endl;
    return 0;
}