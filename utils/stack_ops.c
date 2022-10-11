#include "../tim_sort.h"

/* initialize stack bundle */
void ft_init_stack_bdle(t_stack_bdle *stack)
{
    stack->tail = NULL;
    stack->head = NULL;
    stack->size = 0;
}

/* Merge two stacks linked list */
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_node *stack_two)
{
    t_stack_bdle *tmp_stack;
    t_node *current;

    current = stack_two;

    if (current == NULL)
        return;
    while (current != NULL && current->next != NULL)
    {
        ft_push(stack_one, current->data, current->chunk);
        current = current->next;
    }
    ft_push(stack_one, current->data, current->chunk);
    return;
}

/* Add a new node into existing double link list */
void ft_push(t_stack_bdle *stack, int data, int chunk)
{
    t_node *new_node;
    t_node *tmp;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
        ft_error();
    new_node->data = data;
    new_node->chunk = chunk;
    if (stack->head == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        stack->head = new_node;
        stack->tail = new_node;
    }
    else
    {
        new_node->next = NULL;
        new_node->prev = stack->head;
        stack->head->next = new_node;
        stack->head = new_node;
    }
    stack->size++;
    return;
}

/* Function that duplicate a stack bundle */
t_stack_bdle ft_duplicate_stack(t_stack_bdle *stack)
{
    t_stack_bdle new_stack;
    t_node *current;

    new_stack.tail = NULL;
    new_stack.head = NULL;
    new_stack.size = 0;
    current = stack->tail;
    if (current == NULL)
        return (new_stack);
    while (current != NULL && current->next != NULL)
    {
        ft_push(&new_stack, current->data, current->chunk);
        current = current->next;
    }
    ft_push(&new_stack, current->data, current->chunk);
    return (new_stack);
}

/* function to insert all element for one list to another */
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert)
{
    t_node *current;

    current = stack_to_insert->tail;
    if (current == NULL)
        return;
    while (current != NULL && current->next != NULL)
    {
        ft_push(stack, current->data, current->chunk);
        current = current->next;
    }
    ft_push(stack, current->data, current->chunk);
}

/* shift removes the first item into the stack  */
int ft_shift(t_stack_bdle *stack)
{
    int data;
    t_node *tmp;

    if (stack->tail == NULL)
        ft_error();
    data = stack->tail->data;
    tmp = stack->tail;
    stack->tail = stack->tail->next;
    if (stack->tail != NULL)
        stack->tail->prev = NULL;
    stack->size--;
    free(tmp);
    return (data);
}
