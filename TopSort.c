#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;
int V;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void topologicalSort() {
    int i, j, count = 0;

    for (i = 0; i < V; i++)
        indegree[i] = 0;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while (front != -1 && front <= rear) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (j = 0; j < V; j++) {
            if (adj[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    if (count != V) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
