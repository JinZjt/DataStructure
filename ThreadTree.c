#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//THreading binary tree's traversal is just like the iteration edition of the normal bianry search tree's traversal.
//Thread tree also makes use of the unused pointer left in the normal BST
typedef struct node{
    char data;
    int ltag;
    int rtag;
    struct node* left;
    struct node* right;
}tree_node;
tree_node* pre;
int count=0;
int count_cre = 0;
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
        tree->ltag = 0;
        tree->rtag = 0;
        tree->left = NULL;
        tree->right = NULL;
        printf("success\n");
        return tree;
    }
}
//create a tree_node
void CreateNode(char e, tree_node* node){
    node->data = e;
    node->ltag = 0;
    node->rtag = 0;
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
void Inorder(tree_node* root){
    if(root==NULL) return;
    else{
        Inorder(root->left);
        printf("%c ", root->data);
        Inorder(root->right);
    }
}
//create the thread binary tree based on the original binary search tree
void CreateThreadTree(tree_node* root, int M){//If you want to connect the head with the last one, you could try the counter to find the last one, and then connect it to the head
    if(root==NULL) return;
    else{
        CreateThreadTree(root->left, M);
        if(!root->left){//recursion to find the previous one 
            root->ltag = 1;
            root->left = pre;
        }
        if(!pre->right){//recursion to find the next one
            pre->rtag = 1;
            pre->right = root;
        }
        count_cre++;// count_cre is used to find the last node
        if(count_cre==M) root->rtag=1;
        pre = root;
        CreateThreadTree(root->right, M);
    }
}
void InThreadingTraversal(tree_node* head, int M){// follow the forward order, from the first one to the last one
    tree_node* p;
    //p = (tree_node*)malloc(sizeof(tree_node));
    p = head->right; // point to the root
    while(count<M){
        while(p->ltag==0) p = p->left;// find the first node, and the first node's previous node is head.Therefore, here is the correct location
        //Actually, the previous step follows the inorder oreder. Go the left child.
        printf("%c ", p->data);
        count++;
        while(p->rtag==1){
            p = p->right;
            printf("%c ", p->data);
            count++;
        }
        p = p->right;//At this time, p->rtag = 0 and the traversal follows the inorder
    }
}
void InThreadingBackwardTraversal(tree_node* head, int M){// follow the backward order, from the last one to the first one
    tree_node* p;
    p = head->right; // point to the root
    while(count<M){
        while(p->rtag==0) 
            {p = p->right;}// find the first node, and the first node's next node is head.Therefore, here is the correct location
        printf("%c ", p->data);
        count++;
        while(p->ltag==1){
            p = p->left;
            printf("%c ", p->data);
            count++;
        }
        p = p->left;//At this time, p->ltag = 0 and the traversal follows the inorder
    }
}
int main(){
    tree_node* root;
    tree_node* head;//head node which is used in the thread tree
    head = (tree_node*)malloc(sizeof(tree_node));
    root = Initialization();
    char* string = "HELLOALICE";
    int length = strlen(string);
    CreateTree(string, root);
    Inorder(root);
    printf("\n");
    CreateNode('\0', head);
    pre = head;
    CreateThreadTree(root, length);
    head->right = root;// add a head node in the front of the root
    //InThreadingTraversal(head, length);
    InThreadingBackwardTraversal(head, length);
    return 0;
}