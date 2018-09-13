#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libaux.h"
#include "libmyhash.h"

#define HASH h_djb2_str

int	declare_tests_and_run(int all_of, char *these[])
{
	#define SAMPLE "a_sample.txt"
	#define SZ 256
	T(a_sample_256,
		double	occupancy_ratio;
		t_s_mnd	used_addresses;
		int		r;

		r = check_dispersion(
			SAMPLE,
			SZ,
			HASH,
			&occupancy_ratio,
			&used_addresses);
		assert_false(r);
		print_res(&occupancy_ratio, &used_addresses);
		assert_true(occupancy_ratio > 0.9);
	)

	#define SZ 128
	T(a_sample_128,
		double	occupancy_ratio;
		t_s_mnd	used_addresses;
		int		r;

		r = check_dispersion(
			SAMPLE,
			SZ,
			HASH,
			&occupancy_ratio,
			&used_addresses);
		assert_false(r);
		print_res(&occupancy_ratio, &used_addresses);
		assert_true(occupancy_ratio > 0.9);
	)

	#define SZ 64
	T(a_sample_64,
		double	occupancy_ratio;
		t_s_mnd	used_addresses;
		int		r;

		r = check_dispersion(
			SAMPLE,
			SZ,
			HASH,
			&occupancy_ratio,
			&used_addresses);
		assert_false(r);
		print_res(&occupancy_ratio, &used_addresses);
		assert_true(occupancy_ratio > 0.9);
	)

	#define SZ 32 
	T(a_sample_32,
		double	occupancy_ratio;
		t_s_mnd	used_addresses;
		int		r;

		r = check_dispersion(
			SAMPLE,
			SZ,
			HASH,
			&occupancy_ratio,
			&used_addresses);
		assert_false(r);
		print_res(&occupancy_ratio, &used_addresses);
		assert_true(occupancy_ratio > 0.9);
	)

	return(run_test_arr(all_of, these));
}
