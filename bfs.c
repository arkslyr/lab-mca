#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int rear = -1, front = -1;
int queue[MAX_SIZE];

void Enqueue(int element) {
    if (rear == MAX_SIZE - 1)
        return;

    if (rear == -1)
        front = 0;

    rear++;
    queue[rear] = element;
}

int Dequeue() {
    if (front == -1)
        return -1;

    int value = queue[front];
    front++;

    return value;
}

int main() {
    int numberOfNodes, startingNode;

    printf("Enter number of nodes: ");
    scanf("%d", &numberOfNodes);

    int adjacencyMatrix[numberOfNodes][numberOfNodes], visited[numberOfNodes];

    printf("Enter Adjacency matrix for the graph:\n");
    for (int i = 0; i < numberOfNodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < numberOfNodes; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }

    printf("Enter starting node (0-%d): ", (numberOfNodes - 1));
    scanf("%d", &startingNode);
 
    printf("\nBFS Traversal: ");
    Enqueue(startingNode);
    visited[startingNode] = 1;

    while (front <= rear) {
        startingNode = Dequeue();
        printf("%d ", startingNode);

        for (int i = 0; i < numberOfNodes; i++)
            if (adjacencyMatrix[startingNode][i] == 1 && visited[i] == 0) {
                Enqueue(i);
                visited[i] = 1;
            }
    }

    return 0;
}
