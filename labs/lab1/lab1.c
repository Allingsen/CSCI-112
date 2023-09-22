#include <stdio.h>
#DEFINE 
int within_x_percent(int, int, int);

int main(void) {
	
 	// Asks user for boiling point and asks if they want an error percent
	int input;

	printf("Observed boiling point (in deg. C)? ");
	scanf("%d", &input);

	double decimal_input = (double) input;
	printf("You entered %.2f\n", decimal_input);
	
	char y_n;
	printf("Custom error percent? n for no (5%% default), y for yes: "); 
	scanf(" %c", &y_n);


	// Checks if the user enters Y/y for yes, N/n for no, or anything else
	if (y_n == 'Y' || y_n == 'y') {
		int error_percent;
		
		printf("Enter error percent: ");
		scanf(" %d", &error_percent);
		
		double error_percent_final = (double) error_percent;
		printf("You entered %.2f percent\n", error_percent_final);
		
		within_x_percent(100, input, error_percent);
		within_x_percent(100, input, error_percent);
		within_x_percent(100, input, error_percent);
		within_x_percent(100, input, error_percent);
		within_x_percent(100, input, error_percent);
		
		if (within_x_percent(100, input, error_percent) == 1) {
				printf("Substance is water\n");
			}
		
			else if (within_x_percent(357, input, error_percent) == 1) {
                                printf("Substance is mercury\n");
                        }
		
			else if (within_x_percent(1187, input, error_percent) == 1) {
                                printf("Substance is copper\n");
                        }

		
			else if (within_x_percent(2193, input, error_percent) == 1) {
                                printf("Substance is silver\n");
                        }
		
	
			else if (within_x_percent(2660, input, error_percent) == 1) {
                                printf("Substance is gold\n");
                        }
		 if ((within_x_percent(100,input, error_percent) == 0) && (within_x_percent(357,input, error_percent) == 0) && (within_x_percent(1187,input, error_percent) == 0)&& (within_x_percent(2193,input, error_percent) == 0) && (within_x_percent(2660,input, error_percent) == 0)) {
                                printf("Substance is unknown\n");
                        }
	}

	else if (y_n == 'N' || y_n == 'n') {

		within_x_percent(100, input, 5);
			if (within_x_percent(100, input, 5) == 1) {
                                printf("Substance is water\n");
                        }
		within_x_percent(357, input, 5);
			if (within_x_percent(357, input, 5) == 1) {
                                printf("Substance is mercury\n");
                        }		
		within_x_percent(1187, input, 5);
			if (within_x_percent(1187, input, 5) == 1) {
                                printf("Substance is copper\n");
                        }

		within_x_percent(2193, input, 5);
			if (within_x_percent(2193, input, 5) == 1) {
                                printf("Substance is silver\n");
                        }
		
		within_x_percent(2660, input, 5);
			if (within_x_percent(2660, input, 5) == 1) {
                                printf("Substance is gold\n");
                        }
		if ((within_x_percent(100,input, 5) == 0) && (within_x_percent(357,input, 5) == 0) && (within_x_percent(1187,input, 5) == 0)&& (within_x_percent(2193,input, 5) == 0) && (within_x_percent(2660,input, 5) == 0)) {
				printf("Substance is unknown\n");
			}


	}

	//Quits the program if anything else then Y/y/N/n is entered
	else {
		printf("Error: Bad input\n");
		return(0);
	}
	
	

	return(0);
}

int within_x_percent(int ref, int data, int x) {
	
	double percent_x = (double) x * .01;
	if (ref -  percent_x *ref <= data && ref + percent_x * ref >= data) {
	       return(1);
	}
	else {
		return(0);
	}	
	return(0);
}
