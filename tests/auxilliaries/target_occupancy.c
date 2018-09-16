#include "inner.h"

double
	target_occupancy(
		size_t ar_sz,
		size_t sample_sz)
{
	double const	ratio = 1.0 - 1.0 / (double)ar_sz;
	double	ret;

	if (!ar_sz)
		return (0);
	ret = 1.0;
	while (--sample_sz)
		ret *= ratio;
	return (ret);
}
