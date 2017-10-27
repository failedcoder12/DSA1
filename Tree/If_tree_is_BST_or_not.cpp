#include<bits/stdc++.h>
using namespace std;

// Tree using structure

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a New Node of tree

struct Node *create_Node(int new_data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// Print Inorder Transversal Of Tree

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d , ",root->data);
    inorder(root->right);
    return;
}

// Insert Node in Tree

struct Node* insert_node(struct Node* root,int data){
    if(root==NULL){
        root = create_Node(data);
    }
    else {
        printf("\n Enter 1 for left or 2 for right \n");
        int lr;
        scanf("%d",&lr);
        if(lr==1){
            root->left = insert_node(root->left,data);
        } else {
            root->right=insert_node(root->right,data);
        }
    }
    return root;
}

//Checking BST

int isBST(struct Node* root, struct Node *l, struct Node* r) {
    if(root==NULL){
        return 1;
    }
    if(l!=NULL&&root->data<l->data){
        return 0;
    }
    if(r!=NULL&&root->data>r->data){
        return 0;
    }
    return isBST(root->left,l,root)&&isBST(root->right,root,r);
}


int main() {
    struct Node *root = NULL;
    while(1){
        int s;
        printf("\n Enter 1 for inserting \n Enter 2 for checking whether the tree is BST or not\n Enter 3 to exit \n");
        scanf("%d",&s);
        switch(s) {
            case 1: {
                int element;
                struct Node* present;
                printf("Enter element to insert ");
                scanf("%d",&element);
                if(root==NULL){
                    root=create_Node(element);
                    printf("\n Tree Becomes ");
                    inorder(root);
                }else {
                    insert_node(root, element);
                    printf("\n Tree Becomes ");
                    inorder(root);
                }
                break;
            }
            case 2: {
                if(isBST(root,NULL,NULL)){
                    printf("\nIt is a BST \n");
                } else {
                    printf("\n It is not a BST\n");
                }
                break;
            }
            case 3:{
                return 0;
            }
        }
    }
}