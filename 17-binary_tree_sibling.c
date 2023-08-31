#include "binary_trees.h"

/**
* binary_tree_sibling - a function that finds the sibling of a node
* @node: the node to find the sibling of
* Return: the sibling node, or NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if (node == parent->left)
		return (parent->right);
	return (parent->left);
}
