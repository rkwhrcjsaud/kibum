#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char			*name;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*new_node(char *name)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->name = strdup(name);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_add(t_list **head, t_list *new)
{
	if (!*head)
		*head = new;
	else
	{
		t_list	*current;
		t_list	*prev;
		current = *head;
		prev = NULL;
		while (current && strcmp(current->name, new->name) > 0)
		{
			prev = current;
			current = current->next;
		}
		if (!current)
		{
			prev->next = new;
			new->prev = prev;
		}
		else if (!prev)
		{
			current->prev = new;
			new->next = current;
			*head = new;
		}
		else
		{
			prev->next = new;
			new->prev = prev;
			current->prev = new;
			new->next = current;
		}
	}
}

void	lst_remove(t_list **head, char *temp)
{
	t_list	*current;

	current = *head;
	while (current && strcmp(current->name, temp))
		current = current->next;
	t_list	*prev = current->prev;
	t_list	*next = current->next;
	if (prev)
		prev->next = next;
	else
		*head = next;
	if (next)
		next->prev = prev;
	free(current);
}

int	main(void)
{
	int	n;
	t_list	*head;

	head = NULL;
	scanf("%d", &n);
	int	i = 0;
	while (i < n)
	{
		char	temp[6];
		char	enter[6];
		scanf("%s %s", temp, enter);
		if (!strcmp(enter, "enter"))
			lst_add(&head, new_node(temp));
		else
			lst_remove(&head, temp);
		i++;
	}
	while (head)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}