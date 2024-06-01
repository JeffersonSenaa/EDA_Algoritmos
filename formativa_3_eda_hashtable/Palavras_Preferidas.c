#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 65536 

typedef struct Node {
    char palavra[21]; 
    int ocorrencia;
    struct Node* next;
} Node;

unsigned int hashFunction(const char* palavra) {
    unsigned int hash = 0;
    while (*palavra != '\0') {
        hash = (hash * 31) + *palavra++;
    }
    return hash % SIZE;
}
Node* createNode(const char* palavra) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro: Não foi possível alocar memória para o novo nó.");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->palavra, palavra);
    newNode->ocorrencia = 0;
    newNode->next = NULL;
    return newNode;
}
void insertOrUpdate(Node* hashTable[], const char* palavra, int comando) {
    unsigned int index = hashFunction(palavra);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->palavra, palavra) == 0) {

            if (comando == 1) {
                current->ocorrencia++;
            } else if (comando == 3) {
                current->ocorrencia = 0;
            }
            return;
        }
        current = current->next;
    }
    Node* newNode = createNode(palavra);
    if (comando == 1) {
        newNode->ocorrencia++;
    }
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int countOccurrences(Node* hashTable[], const char* palavra) {
    unsigned int index = hashFunction(palavra);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->palavra, palavra) == 0) {
            return current->ocorrencia;
        }
        current = current->next;
    }
    return 0; 
}

int main() {
    Node* hashTable[SIZE] = {NULL};

    int comando;
    char palavra[21];
    while (scanf("%d %s", &comando, palavra) != EOF) {

        if (comando == 1 || comando == 3) {
            insertOrUpdate(hashTable, palavra, comando);
        } else if (comando == 2) {
            int ocorrencias = countOccurrences(hashTable, palavra);
            printf("%d\n", ocorrencias);
        }
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

