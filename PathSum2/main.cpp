//Given the root of a binary tree and an integer targetSum, 
// return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
// Each path should be returned as a list of the node values, not node references.

//A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

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

void solve(Node* root, int targetSum,vector<int>&path,vector<vector<int>>&ans){
    if(root==NULL) return;
    path.push_back(root->data);
    if(root->left == NULL && root->right ==NULL && targetSum == root->data){
        ans.push_back(path);
    }
    solve(root->left,targetSum-root->data,path,ans);
    solve(root->right,targetSum-root->data,path,ans);
    path.pop_back();
}
vector<vector<int>>pathSum(Node* root,int targetSum){
    vector<vector<int>>ans;
    vector<int>path;
    solve(root,targetSum,path,ans);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    int targetSum;
    cout<<"Enter the target sum: ";
    cin>>targetSum;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL): ";
    queue<Node*> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val==-1) continue;
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
            q.push(root);
        }
        else{
            Node* parent = q.front();
            if(parent->left==NULL){
                parent->left = newNode;
                q.push(newNode);
            }
            else{
                parent->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }
    vector<vector<int>> result = pathSum(root,targetSum);
    cout<<"Root-to-leaf paths with sum equal to "<<targetSum<<": "<<endl;
    for(const auto& path : result){
        for(int val : path){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}