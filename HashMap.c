#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 16

typedef struct node
{
	char *key;
	char *val;
	struct node *next;
} node;

static node *hashlist[HASHSIZE];

unsigned
get_hash(char *s) {
	unsigned hash;
	for (hash = 0; *s != '\0'; s++)
	{
		hash = *s + 31 * hash;
	}
	return hash % HASHSIZE;
}

node
*find_by_key(char *key) {
	node *nd;
	for (nd = hashlist[get_hash(key)]; nd != NULL ; nd = nd->next) 
	{
		if (strcmp(key, nd->key) == 0)
		{
			return nd;
		}
	}
	return NULL;
}

node 
*insert(char *key, char *val) {
	node *nd;
	unsigned hash_value;
	if ((nd = find_by_key(key)) == NULL)
	{
		nd = (node*)malloc(sizeof(node));
		if (nd == NULL || (nd->key = strdup(key)) == NULL)
		{
			return NULL;
		} else {
			hash_value = get_hash(key);
			nd->next = hashlist[hash_value];
			hashlist[hash_value] = nd;
			nd->val = strdup(val);
		}
	} else {
		free((void *) nd->val);
		if ((nd->val = strdup(val)) == NULL)
		{
			return NULL;
		}
	}
	return nd;
}

char *get_value_by(char *key) {
	node *nd = find_by_key(key);
	return nd->val;
}

int main(int argc, char const *argv[])
{
	insert("name", "Denis");
	insert("age", "29");
	insert("job", "Developer");

	char *val = get_value_by("job");
	if (val != NULL)
	{
		printf("%s\n", val);
	}

	return 0;
}