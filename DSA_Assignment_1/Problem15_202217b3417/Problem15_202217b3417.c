#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to set a node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key);  // Duplicate the key string
    node->value = strdup(value);  // Duplicate the value string
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

// Initialize HashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;  // Initialize all buckets to NULL
    }
}

// Hash function
int hashFunction(struct hashMap* mp, char* key) {
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = (sum + (key[i] * factor)) % mp->capacity;
        factor = (factor * 31) % __INT16_MAX__;
    }
    return sum % mp->capacity;
}

// Insert function
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    // Collision handling with linked list
    newNode->next = mp->arr[bucketIndex];
    mp->arr[bucketIndex] = newNode;
    mp->numOfElements++;
}

// Delete function
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            // Key found; remove node
            if (prevNode == NULL) {  // Head node
                mp->arr[bucketIndex] = currNode->next;
            } else {  // Middle or last node
                prevNode->next = currNode->next;
            }
            free(currNode->key);  // Free memory for the key
            free(currNode->value);  // Free memory for the value
            free(currNode);  // Free memory for the node
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Search function
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];
    
    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;  // Key found
        }
        bucketHead = bucketHead->next;
    }
    return NULL;  // Key not found
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);
    
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");
    
    printf("%s\n", search(mp, "elite_Programmer")); // Manish
    printf("%s\n", search(mp, "Yogaholic")); // Anjali
    printf("%s\n", search(mp, "pluto14")); // Vartika
    printf("%s\n", search(mp, "decentBoy")); // Mayank
    printf("%s\n", search(mp, "GFG")); // BITS
    printf("%s\n", search(mp, "randomKey") ? search(mp, "randomKey") : "Oops! No data found.\n");

    printf("\nAfter deletion:\n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy") ? search(mp, "decentBoy") : "Oops! No data found.\n");

    // Free memory for HashMap
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* temp = currNode;
            currNode = currNode->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(mp->arr);
    free(mp);
    
    return 0;
}

