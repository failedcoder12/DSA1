#include<bits/stdc++.h>
using namespace std;
#define MAX 9999

// Node's Name

char a[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

//Adjancy Node Structure

struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

// Head of Nodes to one Adjancy Linked List

struct AdjList {
    struct AdjListNode *head;
};

//Graph Structure

struct Graph{
    int V;
    struct AdjList *array;
};

//Creating Adjancy Linked List

struct AdjListNode *createAdjListNode(int dest) {
    struct AdjListNode* new_node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

//Creating Graph

struct Graph* createGraph(int V){
    struct Graph* new_Graph = (struct Graph*)malloc(sizeof(struct Graph));
    new_Graph->V = V;
    new_Graph->array = (struct AdjList*)malloc(sizeof(struct Graph)*V);
    int i;
    for(i=0;i<V;i++){
        new_Graph->array[i].head = NULL;
    }
    return new_Graph;
}

//Adding Node to Graph

void addNode(struct Graph *G,int src,int dest,int direction){
    struct AdjListNode *new_n = createAdjListNode(dest);
    new_n->next = G->array[src].head;
    G->array[src].head = new_n;

    if(direction != 1){
        new_n = createAdjListNode(src);
        new_n->next = G->array[dest].head;
        G->array[dest].head = new_n;
    }
}

// Printing Graph

void Print_Graph(struct Graph *G){
    int i;
    for(i=0;i<G->V;i++){
        struct AdjListNode *start = G->array[i].head;
        printf("HEAD(%c) -> ",a[i]);
        while(start){
            printf(" %c , ",a[start->dest]);
            start = start->next;
        }
        printf("\n");
    }
}

//Printing Node while Inserting in it

void Print_Node(struct Graph *G,int V){
    struct AdjListNode *start = G->array[V].head;
    printf("HEAD(%c) -> ",a[V]);
    while(start){
        printf(" %c , ",a[start->dest]);
        start = start->next;
    }
    printf("\n");
}

//Main Depth First Search Function with time of entering and exit

void DFS_VISIT(char *color, struct AdjListNode **P,int *d1,int *d2,int *time, struct Graph* G,int i){
    if(color[i] == 'w'){
        struct AdjListNode *B = G->array[i].head;
        color[i]='g';
        d1[i] = ++(*time);
        while(B){
            if(color[B->dest]=='w'){
                DFS_VISIT(color,P,d1,d2,time,G,B->dest);
            }
            B=B->next;
        }
    }   color[i] = 'b';
    d2[i] = ++(*time);

}

//DFS Utility Function to mark even unvisited Nodes

void DFS(struct Graph* G){
    char color[G->V];
    struct AdjListNode *pi[G->V];
    int d1[G->V],d2[G->V],i;
    int time = 0;
    for(i=0;i<G->V;i++)
    {
        color[i] = 'w';
        pi[i] = NULL;
        d1[i] = 9999;
        d2[i] = 9999;
    }
    for(i=0;i<G->V;i++){
        if(color[i] == 'w')
            DFS_VISIT(color,pi,d1,d2,&time,G,i);
    }
    int p;
    printf("\n Node || Initial Time || Final Time \n");
    for(p=0;p<G->V;p++)
    {
        printf("  %c   ||        %d        ||    %d     \n",a[p],d1[p],d2[p]);
    }
}

int main(){
    int v;
    printf("\n Enter Number of Nodes in a graph\n");
    scanf("%d",&v);
    int d;
    printf("\n Enter 1 for directed and 0 for undirected\n");
    scanf("%d",&d);
    struct Graph *G = createGraph(v);
    while(1){
        int s;
        printf("\n Enter 1 for insertion \n 2 to print Depth First Search \n 3 to exit ");
        scanf("%d",&s);
        switch (s){
            case 1:{
                int src,dest,key;char srcc,destc;
                printf("Enter Source Node\n");
                scanf("%c",&srcc);
                scanf("%c",&srcc);
                printf("\n Enter 1 to add Link for %c source \n 2 to stop adding link \n",srcc);
                scanf("%d",&key);
                while(key==1){
                    printf("\nEnter Destination\n");
                    scanf("%c",&destc);
                    scanf("%c",&destc);
                    addNode(G,(int)(srcc-'A'),(int)(destc-'A'),d);
                    printf("\n Your Node Becomes : ");
                    Print_Node(G,(int)(srcc-'A'));
                    printf("\n Enter 1 to add Link for %c source \n 2 to stop adding link \n",srcc);
                    scanf("%d",&key);
                }
                printf("\n Your Graph Becomes : \n");
                Print_Graph(G);
                break;
            }case 2:{
                DFS(G);
                break;
            }
            case 3:{
                return 0;
            }
        }
    }

}