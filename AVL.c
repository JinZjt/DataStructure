#include<stdio.h>
#include<stdlib.h>
//函数还是尽量写成void形式
//https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
typedef struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
}tree_node;
tree_node* CreateNewNode(int key){
    tree_node* p;
    p = (tree_node*)malloc(sizeof(tree_node));
    if(!p){
        printf("Error\n");
        return NULL;
    }
    else{
        p->key = key;
        p->height = 1;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
}
int Height(tree_node* root){
    if(root==NULL)
        return 0;
    else return root->height;
}
int GetBalance(tree_node* root){
    if(root==NULL) return 0;
    else return(Height(root->left)-Height(root->right));
}
int GetMax(int a, int b){
    if(a>=b) return a;
    else return b;
}
tree_node* R_rotate(tree_node* y){
    tree_node* x;
    tree_node* t2;
    x = y->left;
    t2 = x->right;
    y->left = t2;
    x->right = y;
    y->height = GetMax(Height(y->left), Height(y->right))+1;
    x->height = GetMax(Height(x->left), Height(x->right))+1;
    return x;
}
tree_node* L_rotate(tree_node* x){
    tree_node* y;
    tree_node* t2;
    y = x->right;
    t2 = y->left;
    x->right = t2;
    y->left = x;
    x->height = GetMax(Height(x->left), Height(x->right))+1;
    y->height = GetMax(Height(y->left), Height(y->right))+1;
    return y;
}
tree_node* Insert(tree_node* root, int key){
    //Perform the normal insertion
    if(root==NULL) 
        return(CreateNewNode(key));
    else if(key<=root->key) root->left = Insert(root->left, key);
    else if(key>root->key) root->right = Insert(root->right, key);
    //get the balance and put the question into different situations
    root->height = 1+GetMax(Height(root->left), Height(root->right));
    int balance = GetBalance(root);
    //left left case
    if(balance>1&&key<=root->left->key){
        return(R_rotate(root));
    }
    //Left Right Case
    else if(balance>1&&key>root->left->key){
        root->left = L_rotate(root->left);
        return(R_rotate(root));
    }
    //right right case
    else if(balance<-1&&key>root->right->key){
        return(L_rotate(root));
    }
    //right left case
    else if(balance<-1&&key<root->right->key){
        root->right = R_rotate(root->right);
        return(L_rotate(root)); 
    }
    return root;
}
void Preorder(tree_node* root){
    if(root==NULL) return;
    else{
        printf("%d ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}
int main(){
    tree_node* tree=NULL;
    tree = Insert(tree, 10);
    tree = Insert(tree, 20);
    tree = Insert(tree, 30);
    tree = Insert(tree, 40);
    tree = Insert(tree, 50);
    tree = Insert(tree, 25);
    Preorder(tree);
    return 0;
}