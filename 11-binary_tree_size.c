#include "binary_trees.h"

/**
* binary_tree_size - computes the size of the tree (root size = 0)
*                       If tree is null, returns 0
* @tree: the node to compute the size at
* Return: size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
