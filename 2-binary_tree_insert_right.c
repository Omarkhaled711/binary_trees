#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a new node to the right of parent
*							If the parent already has a right node, then
*							the new node replaces it as the right child,
*							and the old right-child must be set as the
*							right-child of the new node.
*
* @parent: parent of the new node
* @value: value to be stored in the new node
* Return: the address of the new node, or NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->right = parent->right;
	node->left = NULL;
	parent->right = node;
	if (node->right != NULL)
		node->right->parent = node;
	return (node);
}
