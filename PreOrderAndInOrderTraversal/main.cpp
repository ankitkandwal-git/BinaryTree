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

Node* build(vector<int>& preOrder, int preStart, int preEnd,
               vector<int>& inOrder, int inStart, int inEnd,
               map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    Node* root = new Node(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = build(preOrder, preStart + 1, preStart + numsLeft,
                          inOrder, inStart, inRoot - 1, inMap);
    root->right = build(preOrder, preStart + numsLeft + 1, preEnd,
                           inOrder, inRoot + 1, inEnd, inMap);

    return root;
}

Node* constructTree(vector<int>& preOrder, vector<int>& inOrder) {
    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++) {
        inMap[inOrder[i]] = i;
    }
    return build(preOrder, 0, preOrder.size() - 1,
                     inOrder, 0, inOrder.size() - 1, inMap);
}

void orderTraversal(vector<int>&preOrder,vector<int>&inOrder,Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    orderTraversal(preOrder,inOrder,root->left);
    orderTraversal(preOrder,inOrder,root->right);
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    vector<int>preOrder(n);
    vector<int>inOrder(n);
    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }
    orderTraversal(preOrder,inOrder,root);
    cout<<endl;
    return 0;
}