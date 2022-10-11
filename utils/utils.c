#include "../tim_sort.h"

/* Split to get new chunk */
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int n)
{
    if (stack_ref_bdle->size > 0)
        ft_split_n_element(stack_ref_bdle, new_chunk, n);
    return;
}

/* Split the stack to retrieve the first N elements */
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n)
{
    int i;
    int chunk_nbrs;
    t_stack_bdle *current;
    current = stack;
    i = 0;
    while (i < n && current->size > 0)
    {
        chunk_nbrs = current->tail->chunk;
        int data = ft_shift(current);
        ft_push(new_chunk, data, chunk_nbrs);
        i++;
    }
    return;
}

/* Function that just write error followed by a new line */
void ft_error()
{
    write(1, "Error \n", 7);
    exit(1);
}

/* Display the informations into stack a */
void ft_display_stack(t_node *tail)
{
    t_node *tmp;

    tmp = tail;
    while (tmp != NULL && tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    if (tmp != NULL)
    {
        printf("%d ", tmp->data);
    }
}