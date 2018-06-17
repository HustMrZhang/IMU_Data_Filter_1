#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FILTER_SIZE 10

double filter_mat[FILTER_SIZE];
double filter_data(double fx);

int main()
{
	int i;
	double data_line[6] = {0.0};
	double f_ax;
	// filter_mat initialization
	for(i=0;i<FILTER_SIZE;i++)
		filter_mat[i] = 0.0;
	// read data from file
	FILE * fp = fopen("data_1min.txt","rt");
	FILE * fp_out = fopen("filter_result.txt","wt");
	
	if (fp == NULL)
       exit(1);
       
	while (!feof(fp))
	{
	      fscanf(fp,"%lf%lf%lf%lf%lf%lf",&data_line[0],&data_line[1],&data_line[2],&data_line[3],&data_line[4],&data_line[5]);
	      f_ax = filter_data(data_line[3]);
	      fprintf(fp_out,"%.8f\n", f_ax);
    } 
	
	return 0;
}

double filter_data(double fx)
{
	int j;
	double temp_data = 0.0;
	for(j=0;j<FILTER_SIZE-1;j++)
	{
		filter_mat[j] = filter_mat[j+1];
		temp_data += filter_mat[j];
	}
	filter_mat[FILTER_SIZE-1] = fx;
	temp_data += filter_mat[FILTER_SIZE-1];
	
	return temp_data/FILTER_SIZE;
}
	
	
	
