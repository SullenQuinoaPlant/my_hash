#include "inner.h"

static
size_t
	count_blanks(
		int *ar, size_t ar_sz)
{
	size_t	count;

	count = 0;
	while (ar_sz--)
		if (!*ar++)
			count++;
	return (count);
}

int
	check_dispersion(
		char const *in_file, size_t table_sz,
		t_strhasher testee_hash,
		double *occupancy_ratio, t_s_mnd *used_addresses,
		size_t *sample_sz)
{
	int		in_fd;
	int		r;
	char	*line;
	int		*ar;

	if ((in_fd = open(in_file, O_RDONLY)) == -1 ||
		!(ar = calloc(table_sz, sizeof(int))))
		return (-1);
	*sample_sz = 0;
	while ((r = get_next_line(in_fd, &line)) == 1)
	{
		ar[(*testee_hash)(line) % table_sz]++;
		free(line);
		*sample_sz = *sample_sz + 1;
	}
	if (r == 0)
	{
		*occupancy_ratio = 1.0;
		*occupancy_ratio -=
			(double)count_blanks(ar, table_sz) /
			(double)table_sz;
		used_addresses->mean = mean(ar, table_sz);
		used_addresses->std_dev = std_dev(ar, table_sz,
			used_addresses->mean);
	}
	if (in_fd != -1)
		close(in_fd);
	if (ar)
		free(ar);
	return (0);
}
