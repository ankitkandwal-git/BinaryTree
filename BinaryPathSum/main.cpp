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

Node* buildTree(vector<int>& arr, int n) {
    if (n < 1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();
        if (i < n) {
            curr->left = new Node(arr[i++]);
            q.push(curr->left);
        }
        if (i < n) {
            curr->right = new Node(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

bool pathSum(Node* root, int sum){
    if(root==NULL) return false;
    if(root->left == NULL && root->right ==NULL){
        return sum == root->data;
    }
    int remainSum = sum - root->data;
    return pathSum(root->left,remainSum) 
       || pathSum(root->right,remainSum);
}

int main(){
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root = buildTree(arr, n);
    cout << (pathSum(root, sum) ? "true" : "false") << endl;
}