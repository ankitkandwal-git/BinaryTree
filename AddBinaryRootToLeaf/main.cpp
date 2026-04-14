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
int addBinaryRootToLeaf(Node* root,int sum){
    if(root==NULL) return 0;
    int leftSum = addBinaryRootToLeaf(root->left,sum*2+root->data);
    int rightSum = addBinaryRootToLeaf(root->right,sum*2+root->data);
    if(root->left ==NULL && root->right == NULL) return sum*2+root->data;
    return leftSum+rightSum;
}
int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root==NULL) root = new Node(x);
        else{
            Node* temp = root;
            while(temp){
                if(x<temp->data){
                    if(temp->left==NULL){
                        temp->left = new Node(x);
                        break;
                    }
                    else temp = temp->left;
                }
                else{
                    if(temp->right==NULL){
                        temp->right = new Node(x);
                        break;
                    }
                    else temp = temp->right;
                }
            }
        }
    }
    cout<<addBinaryRootToLeaf(root,0)<<endl;
    return 0;
}