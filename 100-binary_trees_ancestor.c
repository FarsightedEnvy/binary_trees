#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    const binary_tree_t *a, *b;

    if (first == NULL || second == NULL)
    {
        return (NULL);
    }
    if (first == second)
    {
        return ((binary_tree_t *)first);
    }

    a = first;
    b = second;

    while (a != NULL)
    {
        b = second;
        while (b != NULL)
        {
            if (a == b)
            {
                return ((binary_tree_t *)a);
            }
            b = b->parent;
        }
        a = a->parent;
    }

    return (NULL);
}
