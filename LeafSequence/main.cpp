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

void leafSequence(Node* root,vector<int>&leaves){
    if(!root) return;
    if(!root->left && !root->right){
        leaves.push_back(root->data);
        return;
    }
    leafSequence(root->left,leaves);
    leafSequence(root->right,leaves);
}

bool leafSimilar(Node* root1,Node* root2){
    vector<int>leaves1;
    vector<int>leaves2;
    leafSequence(root1,leaves1);
    leafSequence(root2,leaves2);
    return leaves1 == leaves2;
}
int main(){
    int m ,  n;
    cin>>m>>n;
    Node* root1 = NULL;
    Node* root2 = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root1 == NULL){
            root1 = new Node(x);
        }
        else{
            Node* temp = root1;
            while(temp){
                if(x < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(x);
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new Node(x);
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }

        }
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(root2 == NULL){
            root2 = new Node(x);
        }
        else{
            Node* temp = root2;
            while(temp){
                if(x < temp->data){
                    if(temp->left == NULL){
                        temp->left = new Node(x);
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new Node(x);
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }

        }
    }
    if(leafSimilar(root1,root2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}