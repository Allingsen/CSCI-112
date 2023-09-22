#include <stdio.h>

int student_answers(const char a[10], int q, int wrongs[], int next_id) {
	//Gets the students IDs, their guesses, and the wrong answers
	char guesses[10];
	int wrong_answers[q];
	int n_id;

	// Scans for the next ID in the series
	scanf("%d", &n_id);

	//creates an array filled with 0s that holds if the student got the question worng(Which changes it to a 1) or right
	for (int i = 0; i <= q; i++) {
		wrong_answers[i] = 0;
	}

	//Searches for guesses
	for (int i = 0; i <= q; i++) {
		scanf("%c", &guesses[i]);
	}
	
	//Prints the ID and the percentage if the ID and next ID are not the same
	if (n_id != next_id) {
		//Checks if the answer is right or wrong and adds to values depending on which it is
        	int count = 0;
        	for (int i = 1; i <= q; i++) {
                	if (guesses[i] == a[i]) {
                        	count++;
                	}
                	else {
                        	wrong_answers[i-1]++;
               			}
        		}
			//Calculates and prints the percent along with the corresponding ID number	
			double dub_cou = (double) count;
        		double dub_q = (double) q;
        		double percent = (dub_cou/dub_q) * 100;

			printf("\n%d	%.2f", n_id, percent);
		

		//Adds the wrong answers to the total wrong answer array
		for (int i = 0; i <= q; i++) {
			wrongs[i] = wrongs[i] + wrong_answers[i];	
		}
	}
		
	return(n_id);	
}


int main(void) {
	//Finds the number of questions and the answers as an int and array respectively
	int questions;
	char answers[11];
	int wrongs[11];
	int id;

	scanf("%d", &questions);
	for (int i = 0; i <= questions; i++) {
		scanf("%c", &answers[i]);
	}

	for (int i = 0; i <= questions; i++) {
		wrongs[i] = 0;
	}
	
	//Prints out the number of Questions and what the answers are
	printf("Question	1 ");
	for (int a = 2; a <= questions; a++) {
		printf("%d ", a);
	}
	printf("\nAnswer	      ");
	for (int i = 0; i <= questions; i++) {
		printf("%c ", answers[i]);
	}
	printf("\n");

	//Prints out all the students IDs and Percentages
	printf("\nID	Grade(%%)");
	
	for (int i = 0; i <= 20; i++) {
		id = student_answers(answers, questions, wrongs, id);
	}

	//Prints out the question number and how many got it wrong
	printf("\n");
	printf("\nQuestion        1 ");
        for (int a = 2; a <= questions; a++) {
                printf("%d ", a);
        }

	printf("\nMissed By	");
	for (int i = 0; i < questions; i++) {
		printf("%d ", wrongs[i]);
	}
	printf("\n");

	return(0);
}
