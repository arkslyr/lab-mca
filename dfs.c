#include<stdio.h>
#include<stdlib.h>

void depthFirstSearch(int start, int num, int adjacencyMatrix[num][num], int visited[]) {
    if (visited[start] != 1) {
        printf("%d ", start);
        visited[start] = 1;
        for (int i = 0; i < num; i++) {
            if (adjacencyMatrix[start][i] == 1 && visited[i] == 0)
                depthFirstSearch(i, num, adjacencyMatrix, visited);
        }
    }
}

int main() { 
    int num, start;
    
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    
    int adjacencyMatrix[num][num], visited[num];
    
    printf("Enter Adjacency matrix for the graph:\n");
    for (int i = 0; i < num; i++) {    
        visited[i] = 0;
        for (int j = 0; j < num; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }
    
    printf("Enter starting node (0-%d): ", (num - 1));
    scanf("%d", &start);
    
    printf("\nDFS Traversal: ");
    depthFirstSearch(start, num, adjacencyMatrix, visited);

    return 0;
}
