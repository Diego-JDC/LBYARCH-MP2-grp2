#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmsaxpy(int n, float* vecx, float* vecy, float* vecz, float a);

int main(void) {
    float scalar = 3.0f;

    int vectorLength = (int)pow(2, 24); //change to test cases (20, 24, 30)

    float* vx = (float*)malloc(vectorLength * sizeof(float));
    float* vy = (float*)malloc(vectorLength * sizeof(float));
	
	int j = 0;
    for (j = 0; j < vectorLength; j++) {
        vx[j] = (float)j+1;
        vy[j] = (float)j+2;
    }

    float* assemblyZ = (float*)malloc(vectorLength*sizeof(float));
    float* cZ = (float*)malloc(vectorLength * sizeof(float));

	clock_t start = clock();
	int i = 0;
	for (i = 0; i < vectorLength; i++) {
        cZ[i] = scalar * vx[i] + vy[i];
    }
	clock_t end = clock();
	double cTime = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
    asmsaxpy(vectorLength, vx, vy, assemblyZ, scalar);
	end = clock();

	double asmTime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Vector Length\tC Time\t\tASM Time\n");
    printf("%d\t%f\t%f\n", vectorLength, cTime, asmTime);    

    return 0;
}
