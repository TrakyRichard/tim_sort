

#ifndef TIM_SORT
#define TIM_SORT

#ifndef RUN
#define RUN 64
#endif

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    int chunk;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack_bdle
{
    t_node *head;
    t_node *tail;
    int size;
} t_stack_bdle;

typedef struct s_tim_sort
{
    int i;
    t_stack_bdle new_chunk;
    t_stack_bdle sorted_stack;
    t_stack_bdle result;
} t_tim_sort;

typedef struct s_merge_sort
{
    t_stack_bdle left;
    t_stack_bdle right;
    t_stack_bdle result;
    t_stack_bdle sorted_stack;
} t_merge_sort;

typedef struct s_middle
{
    int size;
    int value;
} t_middle;

/* init */
void ft_init_stack_bdle(t_stack_bdle *stack);

/* Split */
t_middle *ft_midpoint(t_stack_bdle stack, t_middle *actual_middle);
void ft_split_n_element(t_stack_bdle *stack, t_stack_bdle *new_chunk, int n);
void ft_split_to_get_chunk(t_stack_bdle *stack_ref_bdle, t_stack_bdle *new_chunk, int n);

/* Stack ops */
void ft_push(t_stack_bdle *stack, int data, int chunk);
void ft_bind_two_stacks(t_stack_bdle *stack_one, t_node *stack_two);
t_stack_bdle ft_duplicate_stack(t_stack_bdle *stack);
void ft_insert_all_node(t_stack_bdle *stack, t_stack_bdle *stack_to_insert);
int ft_shift(t_stack_bdle *stack);

/* richard_sort */
void ft_sorted_insertion(t_node **tail, t_node *new_node);
void ft_insertion_sort(t_node **tail);
t_stack_bdle ft_merge(t_stack_bdle *left, t_stack_bdle *right);
t_stack_bdle ft_iterativeMergeSort(t_stack_bdle *stack);
t_stack_bdle ft_tim_sort(t_stack_bdle stack);
void init_tim_sort(t_tim_sort *r_sort);

/* Utils */
void ft_error();
void ft_display_stack(t_node *tail);

#endif