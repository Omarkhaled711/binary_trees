#include "binary_trees.h"

/**
* binary_tree_rotate_right - performs a right-rotation on a binary tree
* @tree: a pointer to the root node of the tree to rotate
* Return: the new root, or NULL
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *child, *grand_child;

	if (tree == NULL)
		return (NULL);
	child = tree->left;
	if (child == NULL)
		return (tree);
	grand_child = child->right;

	tree->parent = child;
	tree->left = grand_child;
	child->parent = NULL;
	child->right = tree;
	if (grand_child != NULL)
		grand_child->parent = tree;
	return (child);
}
