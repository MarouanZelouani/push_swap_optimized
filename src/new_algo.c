#include "../includes/push_swap.h"

typedef struct  s_sort_param
{
    int *array;
    int mid;
    int offset;
    int start;
    int end;   
} t_param;

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

int *dup_array (t_stack *a)
{
    int *array;
    int i;

    i = 0;
    array = (int *) malloc (sizeof(int) * ft_stack_size(a));
    if (array == NULL)
        return (NULL);
    while (a)
    {
        array[i] = a->data;
        i++;
        a = a->next;
    }
    return (array);
}

int belong_to_the_range (int value, t_param param)
{
    int i;

    i = param.start;
    while (i <= param.end)
    {   
        // printf("%d ", value);
        if (value == param.array[i])
            return (1);
        i++;
    }
    return (0);
}
//1 
//5
//5
//
int return_first_match (t_stack *a, t_param param)
{
    int first_match;

    first_match = a->data;
    if (belong_to_the_range(first_match, param))
        return(first_match);  
    a = a->next;
    while (a)
    {
        if (belong_to_the_range(a->data, param))
            return (a->data);
        a = a->next;
    }
    return (first_match);
}

void push_first_match(t_stack **a, t_stack **b, t_param param)
{
    int first_match;

    first_match = return_first_match(*a, param);
    //exit(0);
    while ((*a)->data != first_match)
    {
        if (get_node(*a, first_match)->index <= ft_stack_size(*a) / 2)
            rotate_a(a, 1);
        else
           reverse_rotate_a(a, 1);
    }
    //if ((*a)->data != first_match)
    push_b(a, b, 1);
}

void fix_stack_b (t_stack **b, t_param param)
{
    if (ft_stack_size(*b) > 1 && (*b)->data < param.array[param.mid])
        rotate_b(b, 0);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort_UwU (t_stack **a, t_stack **b)
{
    t_param param;
    int block_size;

    param.array = dup_array(*a);
    insertionSort(param.array, ft_stack_size(*a));
    printArray(param.array, ft_stack_size(*a));
    printf("=============================\n");
    param.mid = ft_stack_size(*a) / 2 - 1; 
    param.offset = ft_stack_size(*a) / 8;
    param.start = param.mid - param.offset;
    param.end = param.mid + param.offset;
    block_size = param.end - param.start + 1;
    printf("SIZE==%d\n", block_size);
    while (ft_stack_size(*a))
    {
        if (ft_stack_size(*b) == block_size)
        {
            param.start -= param.offset;
            param.end += param.offset;
            block_size = param.end - param.start + 1;
        }
        push_first_match(a, b, param);
        fix_stack_b(b, param);
        set_index_to_node(*a);
    }
}