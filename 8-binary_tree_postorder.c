#include "binary_trees.h"

/**
* binary_tree_postorder - preforms postorder traversal
* @tree: the tree to preform postorder traversal on
* @func: a function pointer, apply the function on the values
*       stored inside tree nodes when traversing them
* Return: void
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
