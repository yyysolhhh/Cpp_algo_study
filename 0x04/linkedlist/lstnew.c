#include "lst.h"

t_lst	*lstnew(void *dat) {
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->dat = dat;
	new->nxt = NULL;
	return (new);
}
