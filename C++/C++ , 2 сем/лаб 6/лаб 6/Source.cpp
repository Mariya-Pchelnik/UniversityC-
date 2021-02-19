
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
static const int HT_PRIME_1 = 151;
static const int HT_PRIME_2 = 163;
struct TableItem {
	char* key;
	char* data;
};
struct HashTable {
	int sizeIndex;
	int size;
	int count;
	struct TableItem** items;
};
void deleteTableItem(struct HashTable* ht, const char* key);
static struct TableItem HT_DELETED_ITEM = { NULL, NULL };
void insertItem(struct HashTable* ht, const char* key, const char* value);
int is_prime(const int x) {
	if (x < 2) { return -1; }
	if (x < 4) { return 1; }
	if ((x % 2) == 0) { return 0; }
	for (int i = 3; i <= floor(sqrt((double)x)); i += 2) {
		if ((x % i) == 0) {
			return 0;
		}
	}
	return 1;
}
int next_prime(int x) {
	while (is_prime(x) != 1) {
		x++;
	}
	return x;
}
struct TableItem* newItem(const char* key, const char* data) {
	struct TableItem* i = (struct TableItem*)malloc(sizeof(struct TableItem));
	i->key =_strdup(key);
	i->data = _strdup(data);
	return i;
}
static struct HashTable* newHashTableSized(const int sizeIndex) {
	struct HashTable* ht = (struct HashTable*) malloc(sizeof(struct HashTable));
	ht->sizeIndex = sizeIndex;
	const int baseSize = 50 << ht->sizeIndex;
	ht->size = next_prime(baseSize);
	ht->count = 0;
	ht->items = (struct TableItem**) calloc((size_t)ht->size, sizeof(struct TableItem*));
	return ht;
}
struct HashTable* newHashTable() {
	return newHashTableSized(0);
}
static void deleteItem(struct TableItem* i) {
	free(i->key);
	free(i->data);
	free(i);
}
void deleteHashTable(struct HashTable* ht) {
	for (int i = 0; i < ht->size; i++) {
		struct TableItem* item = ht->items[i]; {
			if (item != NULL) {
				deleteItem(item);
			}}
	}
	free(ht->items);     free(ht);
}
static int hash(const char* s, const int a, const int m)
{
	long hash = 0;
	const int length = strlen(s);
	for (int i = 0; i < length; i++) {
		hash += (long)pow(a, length - (i + 1)) * s[i];
		hash = hash % m;
	}
	return (int)hash;
}
static int getHash(const char* s, const int numBuckets, const int attempt)
{
	const int hashA = hash(s, HT_PRIME_1, numBuckets);
	const int hashB = hash(s, HT_PRIME_2, numBuckets);
	return(hashA + (attempt * (hashB + 1))) % numBuckets;
}
static void resizeHashTable(struct HashTable* ht, const int baseSize) {
	if (baseSize < 50){
		return;
	}
	struct HashTable* newHt = newHashTableSized(baseSize);
	for (int i = 0; i < ht->size; i++) {
		struct TableItem* item = ht->items[i];
		if (item != NULL && item != &HT_DELETED_ITEM) {
			insertItem(newHt, item->key, item->data);
		}
	}
	ht->sizeIndex = newHt->sizeIndex;
	ht->count = newHt->count;
	const int tmpSize = ht->size;
	ht->size = newHt->size;
	newHt->size = tmpSize;
	struct TableItem** tmpItems = ht->items;
	ht->items = newHt->items;
	newHt->items = tmpItems;
	deleteHashTable(newHt);
}
void insertItem(struct HashTable* ht, const char* key, const char* value)
{
	const int load = ht->count * 100 / ht->size;
	if (load > 70) {
		resizeHashTable(ht, 1);
	}
	struct TableItem* item = newItem(key, value);
	int index = getHash(item->key, ht->size, 0);
	struct TableItem* curItem = ht->items[index];
	int i = 1;
	while (curItem != NULL && curItem != &HT_DELETED_ITEM) {
		if (strcmp(curItem->key, key) == 0) {
			deleteItem(curItem);
			ht->items[index] = item;
			return;
		}
		index = hash(item->key, ht->size, i);
		curItem = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}
char* searchItem(struct HashTable* ht, const char* key)
{
	int index = getHash(key, ht->size, 0);
	struct TableItem* item = ht->items[index];
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM)
		{
			if (strcmp(item->key, key) == 0) {
				return item->data;
			}
		}
		index = getHash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	return NULL;
}
void deleteTableItem(struct HashTable* ht, const char* key) {
	const int load = ht->count * 100 / ht->size;
	if (load < 10) {
		resizeHashTable(ht, -1);
	}
	int index = getHash(key, ht->size, 0);
	struct TableItem* item = ht->items[index];
	int i = 1;
	while (item != NULL) {
		if (item != &HT_DELETED_ITEM) {
			if (strcmp(item->key, key) == 0) {
				deleteItem(item);
				ht->items[index] = &HT_DELETED_ITEM;
			}
		}
		index = getHash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	
	ht->count--;
	
}
int main() {
	struct HashTable* hashTable = newHashTable();
	insertItem(hashTable, "Maria", "Anatolievna");
	printf ("%s", searchItem(hashTable, "Maria"));
	deleteHashTable(hashTable);
	_getch();
}
