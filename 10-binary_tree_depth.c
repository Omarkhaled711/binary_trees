#include "binary_trees.h"

/**
* binary_tree_depth - computes the depth of the tree (root depth = 0)
*                       If tree is null, returns 0
* @tree: the node to compute the depth at
* Return: depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
