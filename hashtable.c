#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdbool.h>

// structs
struct Item{
    int key;
    int frequency;
    struct Item* next;
};

struct Bucket{
    struct Item * items;
};

struct HashTable{
    int a, b, countBucket;
    struct Bucket * buckets;
};

// function declarations
struct HashTable* init_hash_table(int a, int b, int countBucket); // initialize hashtable with countBucket buckets and hash function as (a + b*key)%countBucket

struct HashTable* insert(struct HashTable* T, int key); // insert key into T

bool search(struct HashTable* T, int key); //true if exists in table

struct HashTable* Delete(struct HashTable* T, int key); // delete key from hastable

void print_table(struct HashTable* T); // a function to print the hashtable

// function definitions

struct HashTable* init_hash_table(int a, int b, int countBucket){

    struct HashTable* new_ht = (struct HashTable*) malloc(sizeof(struct HashTable));

    assert(new_ht!=NULL);

    new_ht->a = a;
    new_ht->b = b;
    new_ht->countBucket = countBucket;
    new_ht->buckets = (struct Bucket*) malloc(countBucket * sizeof(struct Bucket));
    assert(new_ht->buckets!=NULL);

    for (int i = 0; i<countBucket; i++){
        new_ht->buckets[i].items = (struct Item*) malloc(sizeof(struct Item));
        assert(new_ht->buckets->items!=NULL);

        new_ht->buckets[i].items->frequency = -1;
        new_ht->buckets[i].items->key = -1;
        new_ht->buckets[i].items->next = NULL;
    }

    return new_ht;
}

struct HashTable* insert(struct HashTable* T, int key){

    int bucket_num = (T->a * key + T->b)%T->countBucket;

    struct Item* cur_node = T->buckets[bucket_num].items->next;

    while(cur_node!=NULL){

        if (cur_node->key == key){

            cur_node->frequency++;
            return T;

        }

        cur_node = cur_node->next;

    }

    struct Item* new_item = (struct Item*) malloc(sizeof(struct Item));
    new_item->key = key;
    new_item->frequency = 1;
    new_item->next = T->buckets[bucket_num].items->next;

    T->buckets[bucket_num].items->next =new_item;
    return T;
}

bool search(struct HashTable* T, int key){

    int bucket_num = (T->a * key + T->b)%T->countBucket;
    struct Item* cur_node = T->buckets[bucket_num].items->next;

    while(cur_node!=NULL){

        if (cur_node->key == key && cur_node->frequency>0){
            return 1;
        }

        cur_node = cur_node->next;

    }

    return 0;

}

struct HashTable* Delete(struct HashTable* T, int key){

    int bucket_num = (T->a * key + T->b)%T->countBucket;
    struct Item* cur_node = T->buckets[bucket_num].items;

    while(cur_node->next!=NULL){

        if (cur_node->next->key == key){

            if (cur_node->next->frequency>1){

                cur_node->next->frequency--;

            }else{

                struct Item* temp_node = cur_node->next;
                cur_node->next = cur_node->next->next;
                free(temp_node);

            }

            break;
        }

        cur_node = cur_node->next;
    }

    return T;

}

void print_table(struct HashTable* T){

    for (int i = 0; i<T->countBucket; i++){

        struct Item* cur_node = T->buckets[i].items->next;
        while(cur_node!=NULL){

            printf("%d %d ", cur_node->key, cur_node->frequency);
            cur_node = cur_node->next;

        }
        printf("\n");

    }

}

// driver code
int main(){

    // creating a hashtable for 1,2,3,4,...20

    int a = 1;
    int b = 0;
    int countBucket = 10;

    struct HashTable* hashtable=init_hash_table(a,b,countBucket);

    printf("\n\nAfter inserting 1, 2, ... 20\n");
    for (int i = 1; i<=20; i++){
        insert(hashtable, i);
    }

    print_table(hashtable);

    // delete all even numbers
    for (int i = 2; i<=20; i+=2){
        Delete(hashtable, i);
    }

    printf("\n\nAfter deleting 2, 4, ... 20\n");
    print_table(hashtable);

    return 0;
}