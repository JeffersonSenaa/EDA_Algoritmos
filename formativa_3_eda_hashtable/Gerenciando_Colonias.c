#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 11 
#define SIZE 292399 

long int duplicateKeys[SIZE * 20]; 
int duplicateIndex = 0; 

unsigned int hashFunction(long int key) {
    const double A = 0.6180339887;
    double temp = key * A;
    temp -= (unsigned int)temp; 
    return (unsigned int)(SIZE * temp); 
}

typedef struct Node {
    long int key;
    char strings[15][MAX_STR_LENGTH];
    struct Node* next;
} Node;

Node* createNode(long int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro: Não foi possível alocar memória para o novo nó.");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    for (int i = 0; i < 15; i++) {
        newNode->strings[i][0] = '\0'; 
    }
    newNode->next = NULL;
    return newNode;
}

void insert(Node* hashTable[], long int key, const char* string) {
    unsigned int index = hashFunction(key);

    Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            for (int i = 0; i < 15; i++) {
                if (strcmp(current->strings[i], string) == 0) {
                    duplicateKeys[duplicateIndex++] = key;
                    return;
                }
            }
            for (int i = 0; i < 15; i++) {
                if (current->strings[i][0] == '\0') {
                    strcpy(current->strings[i], string);
                    return;
                }
            }
            fprintf(stderr, "Erro: Não há espaço suficiente para inserir mais strings.\n");
            return;
        }
        current = current->next;
    }

    Node* newNode = createNode(key);
    strcpy(newNode->strings[0], string);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int main() {
    Node* hashTable[SIZE] = {NULL};

    long int key;
    char string[MAX_STR_LENGTH];
    while (scanf("%ld %s", &key, string) != EOF) {
        insert(hashTable, key, string);
    }

    for (int i = 0; i < duplicateIndex; i++) {
        printf("%ld\n", duplicateKeys[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}
