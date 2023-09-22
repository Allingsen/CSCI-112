#include <stdio.h>

void compute_charge(double h,double *t, double *a) {
	double num;
	
	//Computes the total charge, with $2.40 being charged up to 6 HCF then $3.31 being charged after
	if (h <= 6.0) {
		*t = h * 2.4;
	}
	else {
		num = h - 6.0;
		*t = 14.4 + (num * 3.31);	
	}

	//Calculates the average cost per HCF
	*a = *t/h;


}

int main(void) {
	FILE *inp, *outp;
	int month, year, id;
	double hcf_used;
	double total, average;
	
	//Creates the input and output files
	inp = fopen("/public/labs/lab4/usage.txt", "r");
	outp = fopen("charges.txt", "w");

	//Gets the month and year and prints them to the file
	fscanf(inp, "%d %d", &month, &year);
	fprintf(outp, "Charges for %d/%d\n\n", month, year);

	fprintf(outp, "Customer\tTotal Cost\tAverage HCF Cost\n");	

	//Scans for IDs and prints ID, Total Cost, and Average Cost
	while((fscanf(inp, "%d", &id)) == 1) {
		fscanf(inp, "%lf", &hcf_used);
		//TODO current_charge (STOP PRINTING hcf_used)
		compute_charge(hcf_used, &total, &average);
		fprintf(outp, "%d\t\t%.2lf\t\t%.2lf\n", id, total, average);

	}

	//Closes the files
	fclose(inp);
	fclose(outp);

	return(0);
}
