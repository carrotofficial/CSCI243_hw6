/**
 * @file hash.c
 * @brief Integer-to-integer hash table using separate chaining
 * 
 * @author Nathan Pruitt <ncp4023@rit.edu>
 * @course CSCI-243 Homework 6
 */

typedef struct {

} HashTable;

HashTable ht_create() {
    HashTable ht = {};
    return ht;
}

void ht_destroy(HashTable *self) {

}

void ht_put(HashTable *self, int key, int value) {

}

int ht_get(const HashTable *self, int key) {
    
}

int ht_contains(const HashTable *self, int key) {
    //for (int i=0; i<ht_size(); i++) {
    int i = 0;
        if (i == key) {
            return 1;
        }
    }
    return 0;
}

int ht_remove(HashTable *self, int key) {
    
}

//size_t ht_size(const HashTable *self) {

//}