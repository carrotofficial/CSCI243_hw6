/**
 * @file hash.c
 * @brief Integer-to-integer hash table using separate chaining
 * 
 * @author Nathan Pruitt <ncp4023@rit.edu>
 * @course CSCI-243 Homework 6
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

// Node constructor
void node_set(Node *node, int key, int value) {
    (*node).key = key;
    (*node).value = value;
    (*node).next = NULL;
}

typedef struct {
    struct Node **nodeArray;
    int size;
    int max;
} HashTable;

HashTable *ht_create() {
    HashTable ht;
    HashTable *htp = &ht;
    htp -> size = 0;
    htp -> max = 30;
    //htp -> nodeArray = (Node **) malloc(sizeof(Node *) * (htp -> max));
    return htp;
}

int hash(HashTable *ht, int key) {
    return key % (*ht).max;
}

void ht_destroy(HashTable *self) {

}

void ht_put(HashTable *self, int key, int value) {
    int index = hash(self, key);
    //Node *new = (Node *) malloc(sizeof(Node));
    //node_set(new, key, value);

    /*if (self -> nodeArray[index] == NULL) {
        self -> nodeArray[index] = new;
    }
    else {
        new -> next = self -> nodeArray[index];
        self -> nodeArray[index] = new;
    }*/
}

int ht_get(const HashTable *self, int key, int *found) {
    int index = hash(self, key);
    Node *head = self -> nodeArray[index];

    while (head != NULL) {
        if (key == (*head).key) {
            *found = 1;
            return head -> value;
        }
        head = head -> next;
    }

    *found = 0;
}

int ht_contains(const HashTable *self, int key) {
    for (int i=0; i<10/*ht_size()*/; i++) {
        if (i == key) {
            return 1;
        }
    }
    return 0;
}

int ht_remove(HashTable *self, int key) {
    int contains =  ht_contains(self, key);

    int index = hash(self, key);
    Node *prev = NULL;
    Node *current = self -> nodeArray[index];

    while (current != NULL) {
        if (current -> key == key) {
            if (current == self -> nodeArray[index]) {
                self -> nodeArray[index] = current -> next;
            }
            else {
                prev -> next = current -> next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current -> next;
    }

    return contains;
}

size_t ht_size(const HashTable *self) {
    return sizeof(*self);
}


// Will not be compiled for submission
/*#ifdef DEBUG
int main() {
    HashTable *ht = ht_create();
    ht_put(ht, 0, 1);
    return 0;
}
#endif*/