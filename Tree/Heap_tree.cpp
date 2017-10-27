#include<bits/stdc++.h>
using namespace std;

// Tree Struct

struct tree {
    int *array;
    int capacity;
    int heapsize;
};

// Define Heap

struct tree* define_heap(int capacity){
    struct tree* new_tree = (struct tree*)malloc(sizeof(tree));
    new_tree->capacity = capacity;
    new_tree->array = (int *)malloc(sizeof(int)*capacity);
    int k;
    new_tree->heapsize = 0;
    for(k=0;k<capacity;k++){
        new_tree->array[k] = 9999;
    }
    return new_tree;
}

// Swap

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

//Parent

int parent_(int i){
    return (i-1)/2;
}

//Left

int left(int i){
    return 2*i+1;
}

//Right

int right(int i){
    return 2*i+2;
}

// insert

void insert_node(struct tree* t,int data){
    if(t->heapsize==t->capacity){
        printf("\nTree Full\n");
        return;
    }
    t->heapsize++;
    t->array[t->heapsize-1]=data;
    int y=t->heapsize-1;
    while(y!=0&&t->array[parent_(y)]>t->array[y]){
        swap(&t->array[parent_(y)],&t->array[y]);
        y = parent_(y);
    }
}

//Print

void print_(struct tree* t){
    int i=0;
    printf("\n Tree is: - ");
    while(i<t->capacity){
       if(t->array[i]!=9999)
        printf("%d , ",t->array[i]);
        i++;
    }
}

// Heapify a subtree with root at given index and other nodes already heapified

void Heapify(int i, struct tree* t) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<t->heapsize&&t->array[l]<t->array[i]){
        smallest = l;
    }
    if(r<t->heapsize&&t->array[r]<t->array[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        swap(&t->array[smallest],&t->array[i]);
        Heapify(smallest,t);
    }
}

// Delete and return Smallest Element

int MinELement(struct tree* t){
    if(t->heapsize<=0)
        return 9999;
    if(t->heapsize==1){
        t->heapsize--;
        return t->array[0];
    }
    int data = t->array[0];
    t->array[0] = 9999;
    t->heapsize--;
    Heapify(0,t);
    return data;
}

// Decrease Key

void decrease_key(struct tree* t,int i){
    t->array[i] = -999;
    while(i!=0&&t->array[parent_(i)]>t->array[i]){
        swap(&t->array[parent_(i)],&t->array[i]);
        i = parent_(i);
    }
}

//Delete Node

void delete_node(int key, struct tree* t){
    decrease_key(t,key);
    MinELement(t);
}

int main() {
    struct tree *root = define_heap(20);
    while (1) {
        int s;
        printf("\n Enter 1 for inserting \n Enter 2 for deleting with key \n Enter 3 for deleting Minimum Element  \n Enter 4 to exit \n");
        scanf("%d", &s);
        switch (s) {
            case 1: {
                int element;
                printf("\nEnter Element to insert");
                scanf("%d",&element);
                insert_node(root,element);
                printf("\nYour heap becomes : ");
                print_(root);
                break;
            }
            case 2:{
                int key;
                printf("\nEnter Key");
                scanf("%d",&key);
                delete_node(key,root);
                printf("\nYour heap becomes : ");
                print_(root);
                break;
            }
            case 3:{
                printf("Mininum element deleted is :- %d\n",MinELement(root));
                print_(root);
                break;
            }
            case 4:{
            return 0;
            }
        }
    }
}