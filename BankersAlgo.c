#include <stdio.h>
#define MAX 100
void ApproveResources() {
	int r, p, i, j,ProcessCount, temp = 0,Avail=0;
	setbuf(stdout,NULL);
	printf("Enter Total Number of Resources types:");
	scanf("%d", &r);
	printf("Enter Total Number of Processes:");
	scanf("%d", &p);
	ProcessCount = p;
	int maxAlloc[MAX][MAX], available[MAX], currAlloc[MAX][MAX], finished[MAX],
			needRes[MAX][MAX];
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			printf(
					"Enter MAX Number of Resources can be Allocated to P%d Process R%d resource:",
					i, j);
			scanf("%d", &maxAlloc[i][j]);
		}
	}
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			printf(
					"Enter Number of Resources Allocated to P%d Process R%d resource:",
					i, j);
			scanf("%d", &currAlloc[i][j]);
		}
	}
	for (i = 0; i < r; i++) {
		printf("Enter Available System Resources of type R%d:", i);
		scanf("%d", &available[i]);
	}
	for (i = 0; i < p; i++) {
		finished[i] = 0;
	}
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			needRes[i][j] = maxAlloc[i][j] - currAlloc[i][j];
		}
	}
	while (ProcessCount != 0) {
		Avail=0;
		for (i = 0; i < p; i++) {
			if (!finished[i]) {
				temp = 0;
				for (j = 0; j < r; j++) {
					if (available[j]-needRes[i][j] >= 0) {
						temp++;
					}
				}
				if (temp == r) {
					Avail=1;
					for (j = 0; j < r; j++) {
						available[j]=available[j]-needRes[i][j];
						}
						printf("\nBanker is Safe until\n");
						printf("Process P%d is Executing",i);
						finished[i] = 1;
						ProcessCount--;
						for (j = 0; j < r; j++) {
							available[j]=available[j]+maxAlloc[i][j];
						}
					}
				}
			}
		if(!Avail){
			printf("\n\nBanker is NOT safe\n\n");
			break;
		}
		}
	}
int main() {
	ApproveResources();
	return 0;
}


