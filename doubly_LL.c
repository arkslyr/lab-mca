#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *linked_list = NULL;

struct node *create_node(int);
void insert_at_beginning(int);
void insert_at_position(int, int);
void insert_at_end(int);
int delete_from_end();
int delete_from_beginning();
int delete_from_position(int position);
void print();

void main()
{
    int element, option, position;
    while (1)
    {
        printf("LINKED LIST: ");
        print();
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            insert_at_beginning(element);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &element);
            insert_at_end(element);
            break;
        case 3:
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &position);
            insert_at_position(element, position);
            break;
        case 4:
            element = delete_from_beginning();
            printf("%d deleted from linked list.\n", element);
            break;
        case 5:
            element = delete_from_end();
            printf("%d deleted from linked list.\n", element);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            element = delete_from_position(position);
            printf("%d deleted from linked list.\n", element);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
}

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(int data)
{
    struct node *new_node = create_node(data);
    if (linked_list != NULL)
        linked_list->prev = new_node;
    new_node->next = linked_list;
    linked_list = new_node;
}

void insert_at_position(int data, int position)
{
    struct node *new_node, *current_node = linked_list;
    int current_position = 0;
    while (++current_position < position - 1)
        current_node = current_node->next;
    new_node = create_node(data);
    new_node->next = current_node->next;
    new_node->prev = current_node;
    current_node->next = new_node;
}

void insert_at_end(int data)
{
    struct node *new_node, *currrent_node = linked_list;
    while (currrent_node->next != NULL)
        currrent_node = currrent_node->next;
    new_node = create_node(data);
    new_node->prev = currrent_node;
    currrent_node->next = new_node;
}

int delete_from_end()
{
    int data;
    struct node *current_node = linked_list;
    if (current_node == NULL)
        return -1;
    else if (current_node->next == NULL)
    {
        data = current_node->data;
        free(current_node);
        linked_list = NULL;
        return data;
    }
    while (current_node->next->next != NULL)
        current_node = current_node->next;
    data = current_node->next->data;
    free(current_node->next);
    current_node->next = NULL;
}

int delete_from_beginning()
{
    int data;
    struct node *deleted_node = linked_list;
    if (deleted_node == NULL)
        return -1;
    data = deleted_node->data;
    linked_list = linked_list->next;
    linked_list->prev = NULL;
    free(deleted_node);
}

int delete_from_position(int position)
{
    struct node *deleted_node, *current_node = linked_list;
    int current_position = 0;
    if (current_node == NULL)
        return -1;
    while (++current_position < position - 1)
        current_node = current_node->next;
    deleted_node = current_node->next;
    current_node->next = current_node->next->next;
    current_node->next->next->prev = current_node;
    free(deleted_node);
}

void print()
{
    struct node *current_node = linked_list;
    while (current_node != NULL)
    {
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}