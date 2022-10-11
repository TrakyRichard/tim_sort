#include "../tim_sort.h"


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = 6;
    t_stack_bdle stack;
    t_stack_bdle result;
    ft_init_stack_bdle(&result);
    ft_init_stack_bdle(&stack);

    while (arr_size > 0)
    {
        ft_push(&stack, arr[arr_size - 1], 0);
        arr_size--;
    }

    result = ft_tim_sort(stack);
    ft_display_stack(result.tail);
    return (0);
}