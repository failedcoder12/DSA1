#include<bits/stdc++.h>
using namespace std;

//Nodes of Adjancy Linked List

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
        printf("HEAD(%d) -> ",i);
        while(start){
            printf(" %d , ",start->dest);
            start = start->next;
        }
        printf("\n");
    }
}

//Printing Node while Inserting in it

void Print_Node(struct Graph *G,int V){
    struct AdjListNode *start = G->array[V].head;
    printf("HEAD(%d) -> ",V);
    while(start){
        printf(" %d , ",start->dest);
        start = start->next;
    }
    printf("\n");
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
        printf("\n Enter 1 for insertion \n 2 to print \n 3 to exit ");
        scanf("%d",&s);
        switch (s){
            case 1:{
                int src,dest,key;
                printf("Enter Source Node\n");
                scanf("%d",&src);
                printf("\n Enter 1 to add Link for %d source \n 2 to stop adding link \n",src);
                scanf("%d",&key);
                while(key==1){
                    printf("\nEnter Destination\n");
                    scanf("%d",&dest);
                    addNode(G,src,dest,d);
                    printf("\n Your Node Becomes : ");
                    Print_Node(G,src);
                    printf("\n Enter 1 to add Link for %d source \n 2 to stop adding link \n",src);
                    scanf("%d",&key);
                }
                printf("\n Your Graph Becomes : \n");
                Print_Graph(G);
                break;
            }case 2:{
                printf("\n Your Graph Becomes : \n");
                Print_Graph(G);
                break;
            }
            case 3:{
                return 0;
            }
        }
    }

}