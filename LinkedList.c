#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char *value;
	struct node *next;
} node;

node
*insert_value(char *value, node *nd) {
	if (nd == NULL)
	{
		nd = (node*)malloc(sizeof(node));
		nd->value = value;
		nd->next = NULL;
	} else {
		if(nd->value != value) {
			nd->next = insert_value(value, nd->next);
		} else {
			printf("Value is exist!\n");
		}
	}
	return nd;
}

node
*delete_value(char *value, node *nd) {
	if (nd->value == value)
	{
		node *tmp = nd;
		nd = nd->next;
		free(tmp);
	} else if (nd->next->value == value)
	{
		node *tmp = nd->next;
		nd->next = tmp->next;
		free(tmp);
	} else {
		nd->next = delete_value(value, nd->next);
	}
	return nd;
}


void printer(node *nod) {
	if(nod != NULL) {
		printf("%s\n", nod->value);
		printer(nod->next);
	} 
}

int main(int argc, char const *argv[])
{
	node *nd = NULL;
	nd = insert_value("a", nd);
	nd = insert_value("b", nd);
	nd = insert_value("c", nd);
	nd = insert_value("d", nd);
	nd = insert_value("e", nd);
	printer(nd);
	printf("=========\n");
	nd = delete_value("d", nd);
	printer(nd);

	return 0;
}