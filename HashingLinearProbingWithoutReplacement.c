//Implement Hashing with Linear Probing with Chaining without Replacement
//By
//Anshuman Giramkar
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int key;
    struct ListNode* next;
} ListNode;

typedef struct HashTable {
    ListNode* head;
    int count;
} HashTable;

int hash(int key, int table_size) {
    return key % table_size;
}

void initialize(HashTable* ht, int table_size) {
    ht->head = (ListNode*)malloc(sizeof(ListNode) * table_size);
    ht->count = 0;
    for (int i = 0; i < table_size; i++) {
        ht->head[i].key = -1;
        ht->head[i].next = NULL;
    }
}

int search(HashTable* ht, int key, int table_size) {
    int h = hash(key, table_size);
    ListNode* p = ht->head[h].next;
    while (p != NULL && p->key != key) {
        p = p->next;
    }
    if (p == NULL) {
        return -1; // Key not found
    } else {
        return h; // Key found at index h
    }
}

void insert(HashTable* ht, int key, int table_size) {
    int h = hash(key, table_size);
    ListNode* p = ht->head[h].next;
    while (p != NULL && p->key != key) {
        p = p->next;
    }
    if (p == NULL) {
        // Key not found, insert new node at beginning of list
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->key = key;
        new_node->next = ht->head[h].next;
        ht->head[h].next = new_node;
        ht->count++;
    }
}

int main() {
    HashTable ht;
    int table_size = 10;
    initialize(&ht, table_size);

    insert(&ht, 42, table_size);
    insert(&ht, 13, table_size);
    insert(&ht, 54, table_size);
    insert(&ht, 28, table_size);
    insert(&ht, 59, table_size);
    insert(&ht, 64, table_size);
    insert(&ht, 73, table_size);
    insert(&ht, 85, table_size);
    insert(&ht, 97, table_size);

    int key_to_find = 13;
    int index = search(&ht, key_to_find, table_size);
    if (index == -1) {
        printf("Key %d not found\n", key_to_find);
    } else {
        printf("Key %d found at index %d\n", key_to_find, index);
    }
    int key_to_find1 = 90;
    int index1 = search(&ht, key_to_find1, table_size);
    if (index1 != -1) {
        printf("Key %d found at index %d\n", key_to_find1, index1);
    } 
    else {
        printf("Key %d not found\n", key_to_find1);
    }

    return 0;
}
