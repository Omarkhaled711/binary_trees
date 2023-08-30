#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a new node to the left of parent
*							If the parent already has a left node, then
*							the new node replaces it as the left child,
*							and the old left-child must be set as the
*							left-child of the new node.
*
* @parent: parent of the new node
* @value: value to be stored in the new node
* Return: the address of the new node, or NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = parent->left;
	node->right = NULL;
	parent->left = node;
	if (node->left != NULL)
		node->left->parent = node;
	return (node);
}
