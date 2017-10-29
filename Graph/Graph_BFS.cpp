#include<bits/stdc++.h>
using namespace std;
#define MAX 9999

// Node's Name

char a[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

//Queue's Node Structure

struct QNode
{
    int key;
    struct QNode *next;
};

//Queue Structure

struct Queue
{
    struct QNode *front, *rear;
};

// New QNode

struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

//Creating a Queue

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

//Enqueue Operation

void enQueue(struct Queue *q, int k)
{
    struct QNode *temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

//Dequeue Operation

struct QNode *deQueue(struct Queue *q)
{
    if (q->front == NULL)
        return NULL;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

// Checking Queue is Empty or Not

int isEmpty(struct Queue *q){
    if(q->front==NULL){
        return 1;
    }
    return 0;
}

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

//Breadth First Search Assuming We can Travel to all Nodes from Starting Node

void BFS(char aa, struct Graph *G){
    struct Queue *q = createQueue();
    int v = (int)(aa-'A');
    int d[G->V],i;
    char color[G->V];
    struct AdjListNode *pi[G->V];
    for(i=0;i<G->V;i++){
        d[i] = MAX;
        color[i] = 'w';
        pi[i] = NULL;
    }
    d[v] = 0;
    pi[v] = NULL;
    color[v] = 'g';
    enQueue(q,v);
    while(!isEmpty(q)){;
        int u = deQueue(q)->key;
        struct AdjListNode *uu = G->array[u].head;
        int j;
        struct AdjListNode *h = G->array[u].head;
        while(h){
            if(color[h->dest] == 'w'){
                color[h->dest] = 'g';
                d[h->dest] = d[u]+1;
                pi[h->dest] = uu;
                enQueue(q,h->dest);
            }
            h=h->next;
        }
        color[u] = 'b';
    }
    int p;
    char o;
    printf("\n Node || Distance from %c || Parent \n",a[v]);
    for(p=0;p<G->V;p++)
    {       o = '!';
        if(pi[p]!=NULL)
           o = a[pi[p]->dest];
        printf("  %c   ||        %d        ||    %c     \n",a[p],d[p],o);
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
        printf("\n Enter 1 for insertion \n 2 to print Breadth First Search \n 3 to exit ");
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
                char p;
                printf("\n Enter Starting Node for BFS \n");
                scanf("%c",&p);
                scanf("%c",&p);
                BFS(p,G);
                break;
            }
            case 3:{
                return 0;
            }
        }
    }

}