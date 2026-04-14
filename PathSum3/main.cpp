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

int countPathSum(Node* root,long long countSum){
    long long count = 0;
    if(!root) return 0;
    count += countPathSum(root->left,countSum-root->data);
    count += countPathSum(root->right,countSum-root->data);
    return count;
}

int pathSum(Node* root,int targetSum){
    if(!root) return 0;
    int pathFromRoot = countPathSum(root,targetSum);
    int left = pathSum(root->left,targetSum);
    int right = pathSum(root->right,targetSum);
    return pathFromRoot + left + right;
}

int main(){
    int n,targetSum;
    cin>>n>>targetSum;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(!root) root = new Node(val);
        else{
            Node* temp = root;
            while(temp){
                if(val < temp->data){
                    if(temp->left) temp = temp->left;
                    else{
                        temp->left = new Node(val);
                        break;
                    }
                }
                else{
                    if(temp->right) temp = temp->right;
                    else{
                        temp->right = new Node(val);
                        break;
                    }
                }
            }
        }
    }
    cout<<pathSum(root,targetSum);
}