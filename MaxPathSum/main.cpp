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

int maxPathSum(Node* root,int& maxsum){
    if(root ==NULL) return 0;
    int leftSum = maxPathSum(root->left,maxsum);
    int rightSum = maxPathSum(root->right,maxsum);
    maxsum = max(maxsum,leftSum+rightSum+root->data);
    return max(leftSum,rightSum)+ root->data;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(root == NULL){
            root = new Node(val);
        }
        else{
            Node* temp = root;
            while(temp){
                if(val < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new Node(val);
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
    int maxsum = INT_MIN;
    cout<<maxPathSum(root,maxsum)<<endl;
    return 0;
}