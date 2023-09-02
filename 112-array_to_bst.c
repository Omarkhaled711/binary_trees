#include "binary_trees.h"

/**
* array_to_bst - converts an array to bst
* @array: a pointer to the first element in the array
* @size: the size of the array
* Return: a pointer to the root
*/
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
