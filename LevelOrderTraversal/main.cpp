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

vector<int>levelOrder(Node* root){
    vector<int>ans;
    queue<Node*>q;
    if(root == NULL) return ans;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            ans.push_back(temp->data);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root == NULL) root = new Node(x);
        else{
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp->left == NULL){
                    temp->left = new Node(x);
                    break;
                }
                else q.push(temp->left);
                if(temp->right == NULL){
                    temp->right = new Node(x);
                    break;
                }
                else q.push(temp->right);
            }
        }
    }
    vector<int>ans = levelOrder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}