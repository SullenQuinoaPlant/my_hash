#include "inner.h"

double
	std_dev(
		int *ar, size_t sz,
		double mean)
{
	int		* const ar_lim = ar + sz;
	double	ret;
	double	tmp;

	ret = 0;
	while (ar < ar_lim)
	{
		tmp = *ar++ - mean;
		ret += tmp * tmp;
	}
	ret /= sz;
	ret = sqrt(ret);
	return (ret)
}
