#include "binary_trees.h"

/**
* bst_insert - inserts an element in bst
* @tree: a pointer to the tree nodes
* @value: the value to insert
* Return: the inserted node, or NULL
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if ((*tree) == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		tree = &((*tree)->left);
		return (bst_insert(tree, value));
	}
	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		tree = &((*tree)->right);
		return (bst_insert(tree, value));
	}
	return (NULL);
}
