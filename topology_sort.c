#include <stdio.h>
#include <stdlib.h>

int removedVerticesCount = 0; // Counter for removed vertices

void topologicalSort(int numberOfNodes, int adjacencyMatrix[numberOfNodes][numberOfNodes], int visited[numberOfNodes]) {
    for (int i = 0; i < numberOfNodes; i++) {
        removedVerticesCount = 0;
        if (visited[i] == 0) {
            for (int j = 0; j < numberOfNodes; j++) {
                if (adjacencyMatrix[j][i] != 0) {
                    removedVerticesCount = 1;
                    break;
                }
            }
            if (removedVerticesCount == 0) {
                visited[i] = 1;
                printf("%d ", i);
                for (int j = 0; j < numberOfNodes; j++)
                    adjacencyMatrix[i][j] = 0; // Remove all edges from the deleted vertex
                 // If one vertex is removed then start the loop again (from i=0)
            }
        }
    }
}

int main() {
    int numberOfNodes;

    printf("Enter number of nodes: ");
    scanf("%d", &numberOfNodes);

    int adjacencyMatrix[numberOfNodes][numberOfNodes], visited[numberOfNodes];

    printf("Enter adjacency matrix for a directed acyclic graph:\n");
    for (int i = 0; i < numberOfNodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < numberOfNodes; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }

    printf("\nTopological Sorting:\n");
    topologicalSort(numberOfNodes, adjacencyMatrix, visited);

    return 0;
}
 