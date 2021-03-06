#include "inner.h"

double
	mean(
		int *ar, size_t sz)
{
	int		* const ar_lim = ar + sz;
	size_t	count;
	double	ret;

	ret = 0;
	count = 0;
	while (ar < ar_lim)
	{
		if (*ar)
		{
			ret += *ar;
			count++;
		}
		ar++;
	}
	ret /= (double)count;
	return (ret);
}
