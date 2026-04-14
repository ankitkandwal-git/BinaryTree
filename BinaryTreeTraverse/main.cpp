#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
       int data;
       Node* left;
       Node* right;
       Node(int val){
        data = val;
        left = NULL;
        right = NULL;
       }
};

class BinaryTree{
    public:
         Node* builtTree(vector<int>& arr,int n){
            if(n<1){
                return NULL;
            }
             Node* root = new Node(arr[0]);
            if(n > 1) root->left = new Node(arr[1]);
            if(n > 2) root->right = new Node(arr[2]);
            if(n > 3) root->left->left = new Node(arr[3]);
            if(n > 4) root->left->right = new Node(arr[4]);
            if(n > 5) root->right->left = new Node(arr[5]);
            if(n > 6) root->right->right = new Node(arr[6]);
            if(n > 7) root->left->left->left = new Node(arr[7]);
            if(n > 8) root->left->left->right = new Node(arr[8]);
            return root;
        }
        ~BinaryTree(){
            deleteTree(root);
        }
        void inorder(Node* node){
            if(node == NULL) return;
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
        
        private:
           Node* root;
           void deleteTree(Node* node){
            if(node == NULL){
                return;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
           }
};

int main(){
    BinaryTree bt;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root = bt.builtTree(arr,n);
    if(root!=NULL){
        cout<<"Inorder Traversal: ";
        bt.inorder(root);
        cout<<endl;
    } else {
        cout<<"Tree is empty or invalid input"<<endl;
    }
    return 0;
}