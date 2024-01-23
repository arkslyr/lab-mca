#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE]; // Global array
int size = 0;      // Global variable to track the number of elements

// Function to display the array elements
void display() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
int insert(int position, int element) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return -1; // Indicates failure
    }

    if (position < 0 || position > size) {
        printf("Invalid position. Cannot insert.\n");
        return -1; // Indicates failure
    }

    // Shift elements to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position] = element;

    // Update the size
    size++;

    return 0; // Indicates success
}

// Function to delete an element at a given position
int deleteByPosition(int position) {
    if (size <= 0 || position < 0 || position >= size) {
        printf("Invalid position. Cannot delete.\n");
        return -1; // Indicates failure
    }

    // Shift elements to remove the element at the given position
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Update the size
    size--;

    return 0; // Indicates success
}

// Function to search for an element
int search(int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the position if found
        }
    }

    return -1; // Return -1 if not found
}

int main() {
    int numElements;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &numElements);

    printf("Enter %d elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        int element;
        scanf("%d", &element);
        if (insert(size, element) == 0) {
            printf("Element %d inserted successfully.\n", element);
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int element, position;
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    printf("Enter the position to insert at: ");
                    scanf("%d", &position);

                    if (insert(position, element) == 0) {
                        printf("Element inserted successfully.\n");
                    }
                }
                break;

            case 2:
                {
                    int position;
                    printf("Enter the position to delete: ");
                    scanf("%d", &position);

                    if (deleteByPosition(position) == 0) {
                        printf("Element deleted successfully.\n");
                    }
                }
                break;

            case 3:
                {
                    int element;
                    printf("Enter the element to search: ");
                    scanf("%d", &element);

                    int position = search(element);
                    if (position != -1) {
                        printf("Element found at position %d.\n", position);
                    } else {
                        printf("Element not found.\n");
                    }
                }
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
