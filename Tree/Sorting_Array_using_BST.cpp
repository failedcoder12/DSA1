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

// Insert New Node

struct Node* Insert_Node(struct Node* root,int data){
    if(root==NULL){
        return create_Node(data);
    }
    if(root->data>=data){

        root->left = Insert_Node(root->left,data);
    }
    else if(root->data<data){
        root->right = Insert_Node(root->right,data);
    }
    return root;
}

// Storing Sorted Array 

void Storing_sorted(struct Node* root,int *a){
    static int p=0;
    if(root==NULL){
        return;
    }
    Storing_sorted(root->left,a);
    a[p++] = root->data;
    Storing_sorted(root->right,a);
    return;
}



int main(){
    struct Node* root=NULL;
    int a[100];
    int n,i;
    printf("Enter size of array ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    root = Insert_Node(root,a[0]);
    for(i=1;i<n;i++){
        Insert_Node(root,a[i]);
    }
    Storing_sorted(root,a);
    printf("\nSorted array is :- \n");
    for(i=0;i<n;i++){
        printf("%d , ",a[i]);
    }
}