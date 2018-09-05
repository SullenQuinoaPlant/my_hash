void
	print_res(
		double *occ, t_s_mnd *use)
{
	printf("occupancy ration is : %d\n", *occ);
	printf("mean hit per addr is : %d\n", use->mean);
	printf("std_dev around mean is : %d\n", use->std_dev);
}
