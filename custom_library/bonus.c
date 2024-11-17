// #include "../includes/libft.h"
#include "../includes/libft.h"

// leaks detection
// sudo apt-get install valgrind
// gcc -g -o linked_list linked_list.c
// valgrind --leak-check=full ./linked_list

t_list *ft_lstnew(void *content)
{
    // malloc returns a void pointer but it works 
    // without casting in C but not in C++
    t_list *head = (t_list *)malloc(sizeof(t_list)); 
    head->content = content;
    head->next = NULL;
    return head;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *head = *lst;
    new->next = head;
    *lst = new;
}

int ft_lstsize(t_list *lst)
{
    int size = 1;
    t_list *current = lst;
    if (current == NULL)
        return 0;
    while (current->next != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

t_list *ft_lstlast(t_list *lst)
{
    t_list *current = lst;
    while (current->next != NULL)
    {
        current = current->next;
    }
    return current;
}

t_list *ft_lstget_nth(t_list *lst, int n)
{
    t_list *result = lst;
    int length = ft_lstsize(lst);
    if (n > length - 1)
        return NULL;
    while (n > 0)
    {
        result = result->next;
        n--;
    }
    return result;
}

void ft_lstadd_back(t_list **lst, t_list *new) // i need to understand why **lst
{
    t_list *head = *lst;
    t_list *last = ft_lstlast(head);
    last->next = new;
}

void del(void *ptr)
{
    free(ptr);
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    void *content;
    if (lst == NULL)
        return;
    content = lst->content;
    if (content) // NULL check
        del(content);
    free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current = *lst;
    t_list *next; 

    while (current != NULL)
    {
        next = current->next;
        ft_lstdelone(current, del);
        current = next;
    } 
    *lst = NULL;
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *current = lst;

    if (!lst)
        return;
    while (current != NULL)
    {
        f(current->content);
        current = current->next;
    }
}

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
    
// }

#include <stdio.h>
void display_list(t_list *head) 
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    t_list *current = head;
    int val = *(int *)current->content;
    printf("%d ", val);
    current = current->next;
    while (current != NULL) {
        printf("-> ");
        val = *(int *)current->content;
        printf("%d ", val);
        current = current->next;
    }
    printf("\n");
}

void power_two(void *content)
{
    int *n = (int *)content;
    *n = *n * *n;
}

// int main()
// {
//     t_list **lst = malloc(sizeof(t_list *));
//     for (int i = 10; i > 0; i--)
//     {
//         int *n = malloc(sizeof(int));
//         *n = i;
//         t_list *new_node = ft_lstnew(n);
//         ft_lstadd_front(lst, new_node);
//     }
//     display_list(*lst);
//     printf("Size of list: %d\n", ft_lstsize(*lst));

//     //check if last is correct
//     t_list *last = ft_lstlast(*lst);
//     printf("Last element: %d\n", *(int *)last->content);

//     //add new element to the end
//     int *n = malloc(sizeof(int));
//     *n = 11;
//     t_list *new_node = ft_lstnew(n);
//     ft_lstadd_back(lst, new_node);
//     display_list(*lst);

//     // test ft_lstiter the function that uses f to iterate over lst
//     ft_lstiter(*lst, power_two);
//     display_list(*lst);

//     //test delete one node
//     // t_list *node = ft_lstget_nth(*lst, 3);
//     ft_lstclear(lst, del);
//     display_list(*lst);

//     free(lst);
// }