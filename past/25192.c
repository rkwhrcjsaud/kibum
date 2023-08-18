#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char			*name;
	char			is_gom;
	struct s_list	*next;
}	t_list;

int	lst_add(t_list **head, char *name)
{
	t_list	*temp;
	temp = *head;
	while (temp)
	{
		if (!strcmp(temp->name, name))
		{
			if (temp->is_gom == 1)
				return (0);
			temp->is_gom = 1;
			return (1);
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	t_list	*new;
	new = (t_list *)malloc(sizeof(t_list));
	new->name = strdup(name);
	new->next = NULL;
	new->is_gom = 1;
	if (!*head)
		*head = new;
	else
		temp->next = new;
	return (1);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	t_list	*head;
	t_list	*temp;
	int	total = 0;
	head = NULL;
	int i = 0;
	while (i < n)
	{
		char	s[21];
		scanf("%s", s);
		if (!strcmp(s, "ENTER"))
		{
			temp = head;
			while (temp)
			{
				temp->is_gom = 0;
				temp = temp->next;
			}
		}
		else
		{
			if (lst_add(&head, s))
				total++;
		}
		i++;
	}
	printf("%d\n", total);
}