#include <bits/stdc++.h>
using namespace std;


struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k){
        key = k;
        left = right = NULL;
    }
};


bool doesExist(Node *root , int ele){
    if(root==NULL){return 0;}
    else{
        if(root->key == ele){return 1;}
        else if( root->key < ele){ return doesExist(root->right,ele);}
        else if ( root->key > ele){ return doesExist(root->left, ele);}
    }
}


Node  *Insert( Node *root, int ele){
    if(root == NULL){ root = new Node(ele) ; return root;}

    else if ( root->key >ele){
        root->left = Insert(root->left,ele);
    }
    else if( root->key < ele){
        root->right = Insert(root->right,ele);
    }
    return root;
}

int Height(Node *root){
    if(root==NULL)
        {return 0;}
    else
        {int maxm =max(Height(root->left),Height(root->right)) ;
        return 1 + maxm;}
}
void NodeAtk(Node *root,int k){
    if(root==NULL){return;}
    
    if(k==0){cout<<root->key<<" ";}
    else{
    NodeAtk(root->left,k-1);
    NodeAtk(root->right,k-1);
    }
}

void LevelOrder( Node *root){
    int height = Height(root);
    for(int i =0 ;i<height; i++){
      NodeAtk(root,i);
      cout << endl;
    }
}



Node *del_get_Succ( Node *root){
    if(root == NULL) return root;
    else{
        if(root->left != NULL)
         return del_get_Succ(root->left);
        
        else { return root;}
    }
}

Node *Delete(Node *root , int ele){
    if(root ==NULL) {return root;}
    else if ( root->key > ele){
        root->left = Delete(root->left,ele);
    }
    else if ( root->key  < ele){
        root->right = Delete(root->right,ele);
    }
    else {
        //case1: left node absent
        if(root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
                Node *temp = del_get_Succ(root->right);
                root->key = temp->key;
                root->right = Delete(root->right,temp->key);
                
        }
        return root;
    }

}



Node *floor_BST(Node *root , int ele){
    Node *floor = NULL;
    Node *temp = root;
    while(1){
        if(temp->key > ele){ if(temp->left != NULL){ temp = temp->left;} 
            else break;
         }
        else if( temp->key == ele){ floor = temp ; break;}
        else if ( temp->key < ele){floor = temp;
        if(temp->right != NULL){ temp = temp->right;}
        else{break;}
        }
    }
    return floor;
}



int main(){


Node *root = NULL;

root = new Node(60);
root->left = new Node(40);
root->right = new Node(70); 
root->right->right = new Node(80);
root->left->left = new Node(30);
root->left->right = new Node(45);
root->left->right->left = new Node(42);
root->left->right->right = new Node(48);
root->left->right->right->right = new Node(50);
root->left->right->right->right->right = new Node(55);




Node *floor = floor_BST(root,98);

cout<< floor->key << endl;

}