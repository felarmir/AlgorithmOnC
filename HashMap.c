#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 16

typedef struct node
{
	char *key;
	char *val;
	struct node *next;
	struct node *parent;
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
*add_to_node(node *nd, char *key, char *val) {
	node *tmp = nd->next;
	if (tmp == NULL)
	{
		tmp = (node*)malloc(sizeof(node));
		tmp->key = key;
		tmp->val = val;
		tmp->next = NULL;
		tmp->parent = nd;
	}  else {
		tmp->next = add_to_node(tmp, key, val);
	}

	return tmp;
}

node 
*insert(char *key, char *val) {
	node *nd;
	unsigned hash_value;

	if ((nd = hashlist[get_hash(key)]) == NULL)
	{
		nd = (node*)malloc(sizeof(node));
		if (nd == NULL || (nd->key = strdup(key)) == NULL) {
			return NULL;
		} else {
			hash_value = get_hash(key);
			nd->next = NULL;
			nd->parent = hashlist[hash_value];
			hashlist[hash_value] = nd;
			nd->val = strdup(val);
		}
	} else {
		if (strcmp(key, nd->key) == 0) {
			free((void *) nd->val);
			nd->val = strdup(val);
		} else {
			nd->next = add_to_node(nd, key, val);
		}
		
	}
	return nd;
}

void delete_by_key(char *key) {
	node *nd = find_by_key(key);
	nd->parent->next = nd->next;
	free(nd);
}

char *get_value_by(char *key) {
	node *nd = find_by_key(key);
	if (nd == NULL)
	{
		return "Not found";
	}
	return nd->val;
}

int main(int argc, char const *argv[])
{
	insert("name", "Denis");
	insert("age", "29");
	insert("job", "Developer");
	insert("id", "001");
	insert("project", "Skynet");
	insert("sex", "male");
	insert("kids", "yes");

	delete_by_key("age");

	char *val = get_value_by("age");

	if (val != NULL)
	{
		printf("%s\n", val);
	}

	return 0;
}