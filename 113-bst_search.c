#include "binary_trees.h"

/**
* bst_search - searches for a value in bst
* @tree: the tree to search in
* @value: the value to search for
* Return: the node that contains the value, or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
