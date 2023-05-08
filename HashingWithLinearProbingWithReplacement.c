#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node {
    int data;
    struct node *next;
};

struct node *hashTable[MAX];
int itemCount = 0;

int hashFunction(int key) {
    return key % MAX;
}

void insert(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    int index = hashFunction(data);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct node *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    itemCount++;
}

void delete(int data) {
    int index = hashFunction(data);

    if (hashTable[index] == NULL) {
        printf("Element %d not found in hash table\n", data);
    } else {
        struct node *current = hashTable[index];
        struct node *prev = NULL;
        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Element %d not found in hash table\n", data);
        } else {
            if (prev == NULL) {
                hashTable[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            itemCount--;
            printf("Element %d deleted from hash table\n", data);
        }
    }
}

void display() {
    int i;
    for (i = 0; i < MAX; i++) {
        struct node *current = hashTable[i];
        printf("hashTable[%d]: ", i);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Insert element into the table\n");
        printf("2. Delete element from the table\n");
        printf("3. Display the contents of the table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}
