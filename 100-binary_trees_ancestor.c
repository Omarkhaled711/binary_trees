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

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: the first node
* @second: the second node
* Return: the lowest common ancestor of two nodes or NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));
	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));
	return (binary_trees_ancestor(first->parent, second->parent));
}
