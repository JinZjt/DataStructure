#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}tree_node;
//initialization
tree_node* Initialization(){
    tree_node* tree;
    tree = (tree_node*)malloc(sizeof(tree_node));
    if(!tree){
        printf("Error in initialization\n");
        return NULL;
    }
    else{
        tree->data = '\0';
        tree->left = NULL;
        tree->right = NULL;
        printf("success\n");
        return tree;
    }
}
//create a tree_node
void CreateNode(char e, tree_node* node){
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    return;
}
//insert the element into the tree
void TreeInsert(char e, tree_node* root){
    tree_node* temp;
    tree_node* parent;
    temp = (tree_node*)malloc(sizeof(tree_node));
    parent = (tree_node*)malloc(sizeof(tree_node));
    parent = root;
    CreateNode(e, temp);
    if(!parent->data){
        parent->data = e;
        return;
    }
    else{
        while(1){//use the function of iteration to insert the tree node. Or you could use recursion to insert tree node.
            if(temp->data<=parent->data&&parent->left!=NULL) parent = parent->left;
            else if(temp->data>parent->data&&parent->right!=NULL) parent = parent->right;
            else if(temp->data<=parent->data&&parent->left==NULL){
                parent->left = temp;
                return;
            }
            else if(temp->data>parent->data&&parent->right==NULL){
                parent->right = temp;
                return;
            }
        }
    }
}
//put the string into a tree
void CreateTree(char* string, tree_node* root){
    int length = strlen(string);
    int i;
    char temp;
    printf("The string is ");
    for(i = 0;i<length;i++){
        temp = string[i];
        printf("%c ", temp);
        TreeInsert(temp, root);
    }
    printf("\n");
    return;
}
//tree search
void TreeSearch(char e, tree_node* root){
    if(root==NULL){
        printf("%c is not in the tree\n", e);
        return;
    }
    if(root->data==e){
        printf("%c is in the tree\n", e);
        return;
    }
    else if(e<root->data) TreeSearch(e, root->left);
    else if(e>root->data) TreeSearch(e, root->right);
}
//preorder Traversal which can be regarded as a sorting method for a tree
void Preorder(tree_node* root){
    if(root==NULL) return;
    else{
        printf("%c ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
//Inorder Traversal
void Inorder(tree_node* root){
    if(root==NULL) return;
    else{
        Inorder(root->left);
        if(root->data!='\0')
            printf("%c ", root->data);
        Inorder(root->right);
    }
}
//Postorder Traversal which can be regarded as a deleting method for a tree, bacause, it first traverse the child nodes
void Postorder(tree_node* root){
    if(root==NULL) return;
    else{
        Postorder(root->left);
        Postorder(root->right);
        printf("%c ", root->data);
    }
}
void PreOrder(tree_node* root){
    Preorder(root);
    printf("\n");
    return;
}
void InOrder(tree_node* root){
    Inorder(root);
    printf("\n");
    return;
}
void PostOrder(tree_node* root){
    Postorder(root);
    printf("\n");
    return;
}
void DeleteTree(tree_node* root){
    if(root==NULL) return;
    else{
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
}
void Delete(tree_node* root){
    tree_node* p;
    if(root->left==NULL&&root->right!=NULL){
        p = root;
        root = root->right;
        free(p);
    }
    else if(root->left!=NULL&&root->right==NULL){
        p = root;
        root=root->left;
        free(p);
    }
    else if(root->left!=NULL&&root->right!=NULL){
        p = root;
        root = root->left;
        while(root->right!=NULL){
            root = root->right;
        }
        free(p);
    }
    else if(root->left==NULL&&root->right==NULL){
        free(root);
    }
}
void DeleteOneNode(char e, tree_node* root){
    if(root==NULL){
        printf("Not Found\n");
        return;
    }
    else if(e==root->data) Delete(root);
    else if(e>root->data) DeleteOneNode(e, root->right);
    else if(e<=root->data) DeleteOneNode(e, root->left); 
}
int main(){
    tree_node* root;
    root = Initialization();
    char* string = "HELLOBLICEAYZMN";
    CreateTree(string, root);
    TreeSearch('C', root);
    TreeSearch('Z', root);
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
    DeleteOneNode('O',root);
    InOrder(root);
    //DeleteTree(root);
    return 0;
}