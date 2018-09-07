void
	print_res(
		double *occ, t_s_mnd *use)
{
	printf("occupancy ration is : %f\n", *occ);
	printf("mean hit per addr is : %f\n", use->mean);
	printf("std_dev around mean is : %f\n", use->std_dev);
}
