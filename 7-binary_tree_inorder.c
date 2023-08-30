#include "binary_trees.h"

/**
* binary_tree_inorder - preforms inorder traversal
* @tree: the tree to preform inorder traversal on
* @func: a function pointer, apply the function on the values
*       stored inside tree nodes when traversing them
* Return: void
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
