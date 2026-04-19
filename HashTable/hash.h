#ifndef __HASH__H
#define __HASH__H


/*
* Hash
*/

typedef struct hashKV hashKV;

typedef struct Hash Hash;

Hash *hashCreate(size_t size, size_t valueSize);

int hashKey(Hash *h, const char *key);

size_t hashStringPointerLength(const char *strPtr);

void hashInsert(Hash *h, const char *key, void *value);

int hashDeleteKeyValue(Hash *h, char *key);

int hashSearch(Hash *h, char *key, void *value);

void hashRemove(Hash *h);

#endif
