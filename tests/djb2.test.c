#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libaux.h"
#include "libmyhash.h"

#define HASH h_djb2_str

#define A_SAMPLE_XXX_TEST \
		double	occupancy_ratio;\
		double	target;\
		t_s_mnd	used_addresses;\
		size_t	sample_sz;\
		int		r;\
\
		r = check_dispersion(\
			SAMPLE,\
			SZ,\
			HASH,\
			&occupancy_ratio,\
			&used_addresses,\
			&sample_sz);\
		assert_false(r);\
		print_dispersion(&occupancy_ratio, &used_addresses);\
		target = target_occupancy(SZ, sample_sz);\
		printf("target is: %f\n", target);\
		assert_true(occupancy_ratio > 0.9 * target);

int	declare_tests_and_run(int all_of, char *these[])
{
	#define SAMPLE "a_sample.txt"
	#define SZ 256
	T(a_sample_256,
		A_SAMPLE_XXX_TEST
	)
	#undef SZ
	#define SZ 128
	T(a_sample_128,
		A_SAMPLE_XXX_TEST
	)
	#undef SZ
	#define SZ 64
	T(a_sample_64,
		A_SAMPLE_XXX_TEST
	)
	#undef SZ
	#define SZ 32 
	T(a_sample_32,
		A_SAMPLE_XXX_TEST
	)

	return(run_test_arr(all_of, these));
}
