#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int countFamilyMember(Node* root){
    if(root == NULL) return 0;
    int left = countFamilyMember(root->left);
    int right = countFamilyMember(root->right);
    return 1+(left+right);
}
int main(){
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the values of the nodes: ";
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
    int count = countFamilyMember(root);
    cout<<"The number of family members in the binary tree is: "<<count<<endl;
}