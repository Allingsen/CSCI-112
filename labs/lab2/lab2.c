#include <stdio.h>

int main(void) {
	int input;
	int hot_day = 0;
	int mid_day = 0;
	int cold_day = 0;
	int total = 0;
	//prints the beginning statement
	printf("Enter a high temp reading (-99 to quit)> ");
	scanf(" %d", &input);

	//Initiates the while loop to keep prompting the user for integers until -99 is inputted
	while (input != -99) {
		if (input >= 85) {
			hot_day++;
			total += input;
		}

		if (input >= 60 && input <= 84) {
			mid_day++;
			total += input;
		}

		if (input <= 59) {
			cold_day++;
			total += input;
		}
		printf("Enter a high temp reading (-99 to quit)> ");
		scanf(" %d", &input);
	}

	//prints hot, pleasant, and medium days represented by stars
	printf("Hot days:	");
	for (int i = 1; i <= hot_day; i++) {
		printf("*");
	}
	printf("\nPleasant days:  ");
        for (int i = 1; i <= mid_day; i++) {
                printf("*");
	}
	printf("\nCold days:      ");
        for (int i = 1; i <= cold_day; i++) {
                printf("*");
	}

	//converts total to doubles and then calculates average
	printf("\n");
	double dub_total = (double) total;
	double average = dub_total / (hot_day + mid_day + cold_day);
	printf("Average temperature: %.1f\n", average);
	
	return(0);
}
