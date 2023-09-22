#include <stdio.h>
#include <string.h>

void winners_to_array(FILE *input, char all[46][150]) {
	
	char names[150];	


	for (int i = 0; i < 46; i++) {
		char *first, *last, *year, *univ; 
		char line[150] = "";

		//Gets the names and finds the needed variables
		fgets(names, 150, input);
		
		first = strtok(names, ",");
		last = strtok(NULL, ", ");
		strtok(NULL, ",");
		year = strtok(NULL, ",");
		strtok(NULL, ",");
		univ = strtok(NULL, ",");
		
		//Concetanates the string into the correct format	
		strcat(line, first);
		strcat(line, " ");
		strcat(line, last);
		strcat(line, " of ");
		strcat(line, univ);
		strcat(line, " won in ");
	        strcat(line, year);	

		//Copys the line into the array of strings
		strcpy(all[i], line);


		//Resets the line string
		strcpy(line, "");
	}
}

void array_sort(char all[46][150], FILE *output) {
	
	char temp[150] = "";

	//Iterates through the loop and compares
	for (int i = 0; i < 45; i++) {
		int min_i = i;	
		for (int j = i+1; j < 46; j++) {
			
			//Compares the first letter of the min value and the one currently on
			if (all[j][0] < all[min_i][0]) {
				min_i = j;
			}
		}

		//Sorts the list by first letter
		strcpy(temp, all[i]);
		strcpy(all[i], all[min_i]);
		strcpy(all[min_i], temp);

	}
//TODO ADD WRITING TO THE OUTPUT FILE
	for (int k = 0; k < 46; k++) {
		fprintf(output, "%s\n", all[k]);
	}
}


int main(void) {
	
	FILE *inp;
        FILE *outp;
	char winners[150];
	char all_winners[46][150];

	//Opens the files and reads/discards the first line
        inp = fopen("/public/programs/program1/nobel.csv", "r");
        outp = fopen("winners.txt", "w");
	fgets(winners, 150, inp);

	//Converts all the winners into an array of strings
	winners_to_array(inp, all_winners);

	//Organizes the array
	array_sort(all_winners, outp);
	
	//Closes the files
	fclose(inp);
	fclose(outp);
	return(0);
}
