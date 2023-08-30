#include "binary_trees.h"

/**
* binary_tree_preorder - preforms preorder traversal
* @tree: the tree to preform preorder traversal on
* @func: a function pointer, apply the function on the values
*       stored inside tree nodes when traversing them
* Return: void
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
