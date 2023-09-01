#include "binary_trees.h"

/**
* binary_tree_rotate_left - performs a left-rotation on a binary tree
* @tree: a pointer to the root node of the tree to rotate
* Return: the new root, or NULL
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *child, *grand_child;

	if (tree == NULL)
		return (NULL);
	child = tree->right;
	if (child == NULL)
		return (tree);
	grand_child = child->left;

	tree->parent = child;
	tree->right = grand_child;
	child->parent = NULL;
	child->left = tree;
	if (grand_child != NULL)
		grand_child->parent = tree;
	return (child);
}
