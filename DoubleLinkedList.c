#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	char *value;
	struct node *parent;
	struct node *child;
} node;


node 
*insert(node *nd, char *value) {
	if (nd == NULL)
	{
		nd = (node*)malloc(sizeof(node));
		nd->value = value;
		nd->parent = NULL;
		nd->child = NULL;
	} else {
		if (strcmp(value, nd->value) != 0)
		{
			nd->child = insert(nd->child, value);
			if(nd->child != NULL) {
				nd->child->parent = nd;
			}
		}
	}
	return nd;
}


void delete_node(node *nd, char *value) {
	if (nd != NULL)
	{
		node *tmp = NULL;
		for(node *n = nd; n != NULL; n = n->child) {
			if (strcmp(value, n->value) == 0)
			{
				tmp = n;
				break;
			}
		}
		tmp->parent->child = tmp->child;
		free(tmp);
	}
}

void
print_list(node *nd) {
	printf("[");
	for (node *n = nd; n != NULL; n = n->child) {
		printf(" %s", n->value);
	}
	printf(" ]\n");
}

int main(int argc, char const *argv[])
{
	node *nd = NULL;
	nd = insert(nd, "Denis");
	nd = insert(nd, "Kristina");
	nd = insert(nd, "Susanna");

	print_list(nd);

	return 0;
}