#ifndef AUXILLIARIES_H
# define AUXILLIARIES_H

# include <stddef.h>

typedef
size_t
	(*t_hasher)(
		char const *val, size_t len);

typedef
size_t
	(*t_strhasher)(
		char const *str);

typedef
struct	s_mean_and_deviation {
	double	mean;
	double	std_dev;
}		t_s_mnd;

int
	check_dispersion(
		char const *in_file, size_t table_sz,
		t_strhasher testee_hash,
		double *occupancy_ratio, t_s_mnd *used_addresses);

void
	print_dispersion(
		double *occupancy, t_s_mnd *used_addresses);

#endif
