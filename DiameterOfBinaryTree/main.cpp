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

int diameterofBT(Node* root, vector<int>&diameter){
    if(root==NULL) return 0;
    int left = diameterofBT(root->left, diameter);
    int right = diameterofBT(root->right, diameter);
    diameter[0] = max(diameter[0], left+right);
    return 1 + max(left, right);
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0; i<n; i++){
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
    vector<int> diameter(1, 0);
    diameterofBT(root, diameter);
    cout<<diameter[0]<<endl;
    return 0;
}