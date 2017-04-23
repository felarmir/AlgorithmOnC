#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_list {
	char *value;
	struct tree_list *left;
	struct tree_list *right;
} tree_list;

tree_list *balance_tree(tree_list *tree);

unsigned
get_mass(char *s) {
	unsigned mass;
	for (mass = 0; *s != '\0'; s++)
	{
		mass = *s + mass;
	}
	return mass;
}

tree_list
*insert(tree_list *leaf, char *value) {
	if (leaf == NULL) {
		leaf = (tree_list*)malloc(sizeof(tree_list));
		leaf->value = value;
		leaf->left = NULL;
		leaf->right = NULL;
	} else {
		if(strcmp(value, leaf->value) != 0) {
			if (get_mass(leaf->value) > get_mass(value))
			{
				leaf->left = insert(leaf->left, value);
			} else {
				leaf->right = insert(leaf->right, value);
			}
		}
	}
	return leaf;
}

int 
calculate_side_leafs(tree_list *tree) {
	int summ = 0;
	if (tree != NULL)
	{
		summ ++;
		summ += calculate_side_leafs(tree->left);
		summ += calculate_side_leafs(tree->right);
	}
	return summ;
}

tree_list 
*balance_tree(tree_list *tree) {
	if(tree != NULL) {
		tree_list *root = NULL;
		if (calculate_side_leafs(tree->left) < calculate_side_leafs(tree->right)) {
			root = tree->right;
			tree->right = root->left;
			root->left = tree;
			tree = root;
		} else if (calculate_side_leafs(tree->left) > calculate_side_leafs(tree->right)) {
			root = tree->left;
			tree->left = root->right;
			root->right = tree;
			tree = root;
		}
	}
	return tree;
}

int main(int argc, char const *argv[])
{
	tree_list *lst = NULL;
	lst = insert(lst, "dog");
	insert(lst, "crow");
	insert(lst, "mause");
	insert(lst, "cat");
	insert(lst, "fish");
	insert(lst, "snake");
	insert(lst, "lisard");

	lst = balance_tree(lst);
	printf("%s\n", lst->left->value);


	return 0;
}