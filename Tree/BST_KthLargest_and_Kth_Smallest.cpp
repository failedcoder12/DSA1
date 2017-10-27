#include<bits/stdc++.h>
using namespace std;

int c=0;
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

struct Node* Insert_Node(struct Node* root,int data){
    if(root==NULL){
        return create_Node(data);
    }
    if(root->data>data){

        root->left = Insert_Node(root->left,data);
    }
    else if(root->data<data){
        root->right = Insert_Node(root->right,data);
    }
    return root;
}

// Kth largest element

void kthlargest(struct Node* root,int k){

    if(root==NULL||c>=k){
        return;
    }
    kthlargest(root->right,k);
    c++;
    if(c==k){
        printf("\n %dth Largest Element is %d \n",c,root->data);
    }
    kthlargest(root->left,k);
}

// Kth smallest element

void kthsmallest(struct Node* root,int k){
    if(root==NULL||c>=k){
        return;
    }
    kthlargest(root->left,k);
    c++;
    if(c==k){
        printf("\n %dth Smallest Element is %d \n",c,root->data);
    }
    kthlargest(root->right,k);
}

int main() {
    struct Node *root = NULL;
    while(1){
        int s;
        printf("\n Enter 1 for inserting \n Enter 2 for printing kth largest element\n Enter 3 for printing kth largest element \n Enter 4 to exit \n");
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
                    Insert_Node(root, element);
                    printf("\n Tree Becomes ");
                    inorder(root);
                }
                break;
            }
            case 2: {
                int k;
                c=0;
                printf("Enter K\n");
                scanf("%d",&k);
                kthlargest(root,k);
                break;
            }
            case 3:{

                int k;
                c=0;
                printf("Enter K\n");
                scanf("%d",&k);
                kthsmallest(root,k);
                break;
            }
            case 4:{
                return 0;
            }
        }
    }
}