#ifndef INNER_H
# define INNER_H

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libgetnextline.h"

double
	mean(
		int *ar, size_t sz

double
	std_dev(
		int *ar, size_t sz,
		double mean);

#endif
