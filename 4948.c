#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

void	add_lst(t_list **head, int n)
{
	t_list	*temp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->num = n;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	let(int n)
{
	int	m;
	m = 2 * n;
	int max = 1;
	while (max < m / max)
		max++;
	char	arr[m + 1];
	if (n < 2)
		n = 2;
	int	i = 0;
	while (i < m + 1)
		arr[i++] = 1;
	i = 2;
	while (i <= max)
	{
		int j = 2;
		while (i * j <= m)
		{
			arr[i * j] = 0;
			j++;
		}
		i++;
		while (arr[i] == 0)
			i++;
	}
	int	total = 0;
	while (++n <= m)
	{
		if (arr[n] == 1)
			total++;
	}
	return (total);
}

int	main(void)
{
	t_list	*head;
	int		temp;

	head = NULL;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == 0)
			break ;
		add_lst(&head, temp);
	}
	while (head)
	{
		if (head->num == 1)
			printf("1\n");
		else
			printf("%d\n", let(head->num));
		head = head->next;
	}
}
