#include <stdio.h>
#define MAX 100

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int V, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int cost[MAX][MAX];

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    for(i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0, mincost = 0;

    printf("Edges in MST:\n");

    while(edges < V - 1) {
        int min = 9999, a = -1, b = -1;

        // Find minimum edge
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v) {
            printf("%d - %d : %d\n", a, b, min);
            unionSet(u, v);
            mincost += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("Total cost = %d\n", mincost);
    return 0;
}
