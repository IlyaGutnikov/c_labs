/*
 * CS 11, C Track, lab 7
 *
 * FILE: hash_table.c
 *
 *       Implementation of the hash table functionality.
 *
 */

/*
 * Include the declaration of the hash table data structures
 * and the function prototypes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "memcheck.h"


/*** Hash function. ***/

int hash(char *s)
{
    int hash;
    hash = 0;

    while (*s != '\0') {

        hash += (int)*s;

        s++;
    }
    hash = hash % NSLOTS;
    
    return hash;
}


/*** Linked list utilities. ***/

/* Create a single node. */
node *create_node(char *key, int value)
{
    node * newNode = calloc(1, sizeof(node));

    if (newNode == NULL) {
        fprintf(stderr, "Calloc error");
        exit(1);
    }
    newNode->key = key;
    newNode->next = NULL;
    newNode->value = value;
    
    return newNode;
}


/* Free all the nodes of a linked list. */
void free_list(node *list)
{
    node *nextNode;
    nextNode = list;

    while (nextNode != NULL)
    {
        list = nextNode;

        nextNode = list->next;

        free(list->key);

        free(list);
    }
}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table()
{
    hash_table * table = (hash_table *)calloc(1, sizeof(hash_table));

    table->slot = (node**)calloc(NSLOTS, sizeof(node *));
    
    if ((table == NULL) || (table->slot == NULL)) {
        fprintf(stderr, "Calloc error");
        free_hash_table(table);
        exit(1);
    }
    return table;
}


/* Free a hash table. */
void free_hash_table(hash_table *ht)
{
    int i;

    for (i = 0; i < NSLOTS; i++) {
        free_list(ht->slot[i]);
    }
    free(ht->slot);
    free(ht);
}


/*
 * Look for a key in the hash table.  Return 0 if not found.
 * If it is found return the associated value.
 */
int get_value(hash_table *ht, char *key)
{
    int hashOfKey = hash(key);
    node * bufferNode = ht->slot[hashOfKey];
    
    while (bufferNode != NULL) {
        /* check, is that key is already presented? */
        if (!strcmp(key, bufferNode->key)) {
            return bufferNode->value;
        }
        bufferNode = bufferNode->next;
    }
    return 0;
}


/*
 * Set the value stored at a key.  If the key is not in the table,
 * create a new node and set the value to 'value'.  Note that this
 * function alters the hash table that was passed to it.
 */
void set_value(hash_table *ht, char *key, int value)
{
    int notEmpty;
    int hashOfKey;

    notEmpty = 0;
    hashOfKey = hash(key);

    node * bufferNode; 
    bufferNode = ht->slot[hashOfKey];
    
    while (bufferNode != NULL) {
        notEmpty = 1;
        if (!strcmp(key, bufferNode->key)) {
            bufferNode->value = value;

            free(key);
            return;
        }
        bufferNode = bufferNode->next;
    }
    
    /* creating new node */
    bufferNode = create_node(key, value);


    if (notEmpty)
        bufferNode->next = ht->slot[hashOfKey];
    else
        bufferNode->next = NULL;
    
    ht->slot[hashOfKey] = bufferNode;
}


/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht)
{
    int i;
    i = 0;
    node * currentNode;
    node * firstNode;

    for (i = 0; i < NSLOTS; i++)
    {
        firstNode = ht->slot[i];
        for (currentNode = firstNode; currentNode != NULL;
            currentNode = currentNode->next)
        {
            printf("%s %d\n", currentNode->key, currentNode->value);
        }
    }
}


