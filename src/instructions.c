#include "push_swap.h"

void ft_free_node(t_list *node)
{
    free(node->next);
    free(node);
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (NULL);
	while (head && head->next)
		head = head -> next;
	return (head);
}

void ft_swap_stack(t_list **stack)
{
    t_list  *tmp;
    t_list  *netmp;

    netmp = (*stack)->next->next;
    tmp = *stack;
    *stack = (*stack)->next;
    (*stack)->next = tmp;
    tmp->next = netmp;
}

void ft_swap_stacks(t_list **stack_a, t_list **stack_b)
{
    ft_swap_stack(stack_a);
    ft_swap_stack(stack_b);
}

void ft_push(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    t_list *tmp_next;

    if(!*stack_b)
    {
        *stack_b = ft_addnew((*stack_a)->data);
        tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        // ft_free_node(tmp);
        return ;
    }
    else
    {
        tmp = *stack_b;
        *stack_b = ft_addnew((*stack_a)->data);
        (*stack_b)->next = tmp;
        tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        // ft_free_node(tmp);
    }
}

void ft_rotate(t_list **stack)
{
    t_list *tmp = *stack;
    t_list *lst = ft_lstlast(*stack);
    *stack = (*stack)->next;
    lst->next = tmp;
    tmp->next = NULL;
}

void ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
}

void ft_reverse_rotate(t_list **stack)
{
    t_list *last = *stack;
    t_list *cur = NULL;

    while(last->next)
    {
        cur = last;
        last = last->next;
    }
    cur->next = NULL;
    last->next = *stack;
    *stack = last;
}

void ft_reverse_all(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
}
