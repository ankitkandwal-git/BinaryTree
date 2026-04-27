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

vector<int>leftViewOfBT(Node* root){
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    if(root == NULL) return ans;
    while(!q.empty()){
        int size = q.size();
        int temp = 0;
        for(int i=0;i<size;i++){
            Node* cur  = q.front();
            q.pop();
            if(cur->right) q.push(cur->right);
            if(cur->left) q.push(cur->left);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the binary tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes in level order (use -1 for NULL):";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val == -1) continue;
        if(root == NULL){
            root = new Node(val);
        }else{
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* cur = q.front();
                q.pop();
                if(cur->left == NULL){
                    cur->left = new Node(val);
                    break;
                }else{
                    q.push(cur->left);
                }
                if(cur->right == NULL){
                    cur->right = new Node(val);
                    break;
                }else{
                    q.push(cur->right);
                }
            }
        }
    }
    vector<int>leftView = leftViewOfBT(root);
    cout<<"Left view of the binary tree: ";
}