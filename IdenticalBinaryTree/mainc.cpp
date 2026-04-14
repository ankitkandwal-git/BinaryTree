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

bool identicalBT(Node* root1,Node* root2){
    if(!root1  && !root2) return true;
    if(!root1 && root2) return false;
    if(root1 && !root2) return false;
    if(root1->data != root2->data) return false;
    bool leftSide = identicalBT(root1->left,root2->left);
    bool rightSide = identicalBT(root1->right,root2->right);
    return leftSide && rightSide;

}
int main(){
    int m,n;
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
    bool result = identicalBT(root1,root2);
    cout<< std::boolalpha << result<<endl;
}