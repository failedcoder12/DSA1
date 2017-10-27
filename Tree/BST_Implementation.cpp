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
    if(root->data>data){

        root->left = Insert_Node(root->left,data);
    }
    else if(root->data<data){
        root->right = Insert_Node(root->right,data);
    }
    return root;
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

// Minimum element in tree

int minelement(struct Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

// Maximun element in tree

int maxelement(struct Node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

// Search a key in tree

int searchin(struct Node* root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    if(root->data>key){
        return searchin(root->left,key);
    }
    if(root->data<key){
        return searchin(root->right,key);
    }
    return 0;
}

// Min element Node

struct Node* minelementnode(struct Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

// Delete a node from BST

struct Node* deletenode(struct Node* root,int data_del){
    if(root == NULL)
        return NULL;
    if(data_del<root->data){
        root->left = deletenode(root->left,data_del);
    } else if(data_del>root->data){
        root->right = deletenode(root->right,data_del);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minelementnode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main(){

    struct Node* root = NULL;
 while(1){
 	int s;
 	printf("\n Enter 1 for inserting \n Enter 2 for deleting \n Enter 3 for Searching \n Enter 4 to find min and max element \n Enter 5 to exit \n");
 	scanf("%d",&s);
 	switch(s){
 		case 1:{
 			int element;
            printf("Enter element to insert ");
 			scanf("%d",&element);
 			if(root==NULL){
 				root = Insert_Node(root,element);
 			}
 			else{
 				Insert_Node(root,element);
 			}
            printf("\n Your Tree Becomes : - ");
			inorder(root);
 			break;
 		}
 		case 2:{
            int element;
            printf("Enter element to delete ");
            scanf("%d",&element);
            if(root==NULL){
                printf("\nELement Not Found\n");
            }
            else{
                deletenode(root,element);
            }
            printf("\n Your Tree Becomes : - ");
            inorder(root);
 			break;
 		}
 		case 3:{
            int key;
            printf("\n Enter key to find :- ");
            scanf("%d",&key);
            if(searchin(root,key))
                printf("Element found\n");
            else
                printf("Element Not Found\n");
 			break;
 		}
 		case 4:{
            printf("\n Maximum element is :- %d \n Minimum element is :- %d\n",maxelement(root),minelement(root));
 			break;
 		}
 		case 5:{
 			return 0;
 		}
 	}
 }
}