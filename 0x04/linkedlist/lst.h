#ifndef LST_H
# define LST_H

# include <stdlib.h>

typedef struct s_lst {
	void			*dat;
	struct s_lst	*nxt;
}	t_lst;

t_lst	*lstnew(void *dat);
void	lstadd_front(t_lst **lst, t_lst *new);
int		*lstlast(t_lst *lst);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstdelone(t_lst *lst, void (*del)(void *));
void	lstclear(t_lst *lst, void (*f)(void *));
void	lstiter(t_lst *lst, void (*f)(void *));
t_lst	*lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));

#endif
