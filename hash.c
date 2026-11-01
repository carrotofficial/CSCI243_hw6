/**
 * @file hash.c
 * @brief Integer-to-integer hash table using separate chaining
 * 
 * @author Nathan Pruitt <ncp4023@rit.edu>
 * @course CSCI-243 Homework 6
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
    Node *next;
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
    HashTable *ht;
    ht -> size = 0;
    ht -> max = 30;
    ht -> nodeArray = (Node **) malloc(sizeof(Node *) * (ht -> max));
    return ht;
}

int hash(HashTable *ht, int key) {
    return key % (*ht).max;
}

void ht_destroy(HashTable *self) {

}

void ht_put(HashTable *self, int key, int value) {
    int index = hash(self, key);
    Node *new = (Node *) malloc(sizeof(Node));
    node_set(new, key, value);

    if (self -> nodeArray[index] == NULL) {
        self -> nodeArray[index] = new;
    }
    else {
        new -> next = self -> nodeArray[index];
        self -> nodeArray[index] = new;
    }
}

int ht_get(const HashTable *self, int key) {
    
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
    
}

size_t ht_size(const HashTable *self) {
    return sizeof(*self);
}