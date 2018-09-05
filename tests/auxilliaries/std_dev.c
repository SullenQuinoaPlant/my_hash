#include "inner.h"

double
	std_dev(
		int *ar, size_t sz,
		double mean)
{
	int		* const ar_lim = ar + sz;
	size_t	count;
	double	ret;
	double	tmp;

	ret = 0;
	count = 0;
	while (ar < ar_lim)
	{
		if (*ar)
		{
			count++;
			tmp = *ar - mean;
			ret += tmp * tmp;
		}
		ar++;
	}
	ret /= count;
	ret = sqrt(ret);
	return (ret)
}
