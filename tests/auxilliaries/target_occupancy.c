#include "inner.h"

double
	target_occupancy(
		size_t ar_sz,
		size_t sample_sz)
{
	double const	ratio = 1.0 - 1.0 / (double)ar_sz;
	double	ret;

	ret = (double)ar_sz;
	while (sample_sz--)
		ret *= ratio;
	ret = ((double)ar_sz - ret) / (double)ar_sz;
	return (ret);
}
