#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->next = NULL;
    return node;
}

void insert(int key, Node** hashTable, int tableSize) {
    int index = key % tableSize;
    Node* new_node = newNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = new_node;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void printHashTable(Node** hashTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        printf("%d -> ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\\\n");
    }
}

int main() {
    int N; 
    scanf("%d", &N);

    while (N--) {
        int M, C; 
        scanf("%d %d", &M, &C);

        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        if (hashTable == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            insert(key, hashTable, M);
        }

        printHashTable(hashTable, M);
        printf("\n");

        for (int i = 0; i < M; i++) {
            Node* temp = hashTable[i];
            while (temp != NULL) {
                Node* next = temp->next;
                free(temp);
                temp = next;
            }
        }
        free(hashTable);
    }

    return 0;
}
