#include <stdio.h>
#include <stdlib.h>

#define ROWSIZE 40 
#define ITER 1000

// returns a random value between 0 and 1
float myrand() {
	return (rand() % ROWSIZE) / (float)ROWSIZE;
}

// plants new trees
int planttrees(float growthprob, char forest[]) {
	int i, count = 0;

	for(i = 0; i < ROWSIZE; i++) {
		if(forest[i] == 0 && myrand() <= growthprob)
			forest[i] = 1;
		if(forest[i])
			count++;
	}

	return count;
}

// destroys trees in a fire
int forestfire(float fireprob, char forest[]) {
	int i, j, count = 0;

	for(i = 0; i < ROWSIZE; i++) {
		if(forest[i] && myrand() <= fireprob) {
			forest[i] = 0;
			for(j = i + 1; j < ROWSIZE; j++) {
				if(forest[j])
					forest[j] = 0;
				else
					break;
			}
			for(j = i - 1; j >= 0; j--) {
				if(forest[j])
					forest[j] = 0;
				else
					break;
			}
		}
		if(forest[i])
			count++;
	}

	return count;
}

void displayforest(char prefix, char forest[]) {
	int i;

	printf("%c: ", prefix);
	for(i = 0; i < ROWSIZE; i++) {
		if(forest[i])
			printf("*");
		else 
			printf(" ");
	}
	printf("\n");
}

void resetforest(char forest[]) {
	int i;

	for(i = 0; i < ROWSIZE; i++)
		forest[i] = 0;
}

void main() {
	char arr[ROWSIZE];
	float g, f;
	int i, iter;
	int stats, currtrees, sumtrees;

	scanf("%f", &f);

	for(g = 0.05; g < 1.0; g+=0.05) {
		resetforest(arr);
		sumtrees = 0;
		stats = 0;

		// start iterations, print row by row
		for(iter = 0; iter < ITER; iter++) {
			planttrees(g, arr);
//			displayforest('G', arr);

			currtrees = forestfire(f, arr);
//			displayforest('F', arr);

			if(iter > ROWSIZE * 2) {
				stats++;
				sumtrees += currtrees;
			}
		}

		printf("%.2f %.2f %.2f\n", f, g, sumtrees / (float)stats);
	}
}
