#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_MULTIPLIER 31
#define HASH_TABLE_SIZE 2


typedef struct hashKV{
    char *key;
    void *value;
    struct hashKV *next;
} hashKV;

typedef struct {
    void *hash;
    size_t valueSize, size;
}Hash;


//Creates hashtable of given size, datatype of value and returns pointer of the hashtable
Hash *hashCreate(size_t size, size_t valueSize){
    Hash *h = malloc(sizeof(Hash));
    h->size = HASH_TABLE_SIZE;
    h->valueSize = valueSize;
    h->hash = calloc(size, sizeof(hashKV));
    return h;
}

//Frees the memory of a hashtable
void hashRemove(Hash *h){
    hashKV *hkv = (hashKV *)h->hash;
    for(int i = 0; i < h->size; i++){
        // printf("\n%d\n",*(int *)((hkv + i)->value));
        free(hkv + i);
    }
    free(h->hash);
    free(h);
}

//Creates hash from given key(only string with ascii character)
int hashKey(const char *key){
    int hash = 0;
    while(*key){//becomes false when reached '\0'
        hash = (*key * HASH_MULTIPLIER + hash) % HASH_TABLE_SIZE;
        key++;
    }
    return hash;//less than hash table size
}

//Returns the length of string where pointer is pointing
size_t stringPointerLength(const char *strPtr){
    size_t length = 0;
    while(*strPtr){
        strPtr++;
        length++;
    }
    return length;
}

// key will always be string even if it is number
void hashInsert(Hash *h, const char *key, void *value){
    int hashIndex = hashKey(key);

    hashKV *currentHashKV = (hashKV *)h->hash + hashIndex;

    if (currentHashKV->key == NULL) {
        //allocate memory for key, copy key to allocated memroy and makes pointer of key in linked list point to it
        currentHashKV->key = malloc(stringPointerLength(key) + 1);
        strcpy(currentHashKV->key, key);

        //allocate memory for value, copy value to allocated memroy and makes pointer of value in linked list point to it
        currentHashKV->value = malloc(h->valueSize);
        memcpy(currentHashKV->value, value, h->valueSize);

        currentHashKV->next = NULL;
        return;
    }

    while (currentHashKV->next != NULL){
        // if keys are same replace old value with new one
        if (currentHashKV->key && strcmp(currentHashKV->key, key) == 0){
            memcpy(currentHashKV->value, value, h->valueSize);
            return;
        }
        currentHashKV = currentHashKV->next;
    }
    
    hashKV *nextHashKV = malloc(sizeof(hashKV));
    
    nextHashKV->key = malloc(stringPointerLength(key) + 1);
    strcpy(nextHashKV->key, key);
    
    nextHashKV->value = malloc(h->valueSize);
    memcpy(nextHashKV->value, value, h->valueSize);
    
    nextHashKV->next = NULL;
    currentHashKV->next = nextHashKV;   
}

int hashDeleteKeyValue(Hash *h, char *key){
    int hashIndex = hashKey(key);
    hashKV *currentHashKV = (hashKV *)h->hash + hashIndex;

    while (currentHashKV->next != NULL){
        if(strcmp(currentHashKV->key, key) == 0){
            free(currentHashKV->key);
            free(currentHashKV->value);
            currentHashKV->key = NULL;
            currentHashKV->value = NULL;
        }
        currentHashKV = currentHashKV->next;
    }

    if(strcmp(currentHashKV->key, key) == 0 && currentHashKV->next == NULL){
        free(currentHashKV->key);
        free(currentHashKV->value);
        currentHashKV->key = NULL;
        currentHashKV->value = NULL;
    }
}


//copy contants of value of given key if key is found and returns 0 else not found 1
int hashSearch(Hash *h, char *key, void *value){
    int hashIndex = hashKey(key);
    hashKV *currentHashKV = (hashKV *)h->hash + hashIndex;
    if(currentHashKV->value){
        memcpy(value, currentHashKV->value, h->valueSize);
        return 0;
    }
    return 1;
}


int main(){
    Hash *h = hashCreate(HASH_TABLE_SIZE, sizeof(int)); 

    char pet[][10] = {"cat", "dog", "parrot", "sparrow", "hamster", "horse", "goat"};
    int number = 10;
    hashInsert(h, pet[0], &number);

    number = 20;
    hashInsert(h, pet[1], &number);
    hashKV *hkv = (hashKV *)h->hash;

    // number = *(int *)hkv[0].value;
    // printf("%d", number);

    // number = *(int *)hkv[0].next->value;
    // printf("%d", number);


    // hashSearch(h, pet[0], &number);
    // printf("%d",number);

    hashDeleteKeyValue(h, pet[0]);

    hashSearch(h,pet[1], &number);
    printf("%d",number);


    hashRemove(h);

    return 0;
}