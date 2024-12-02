#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmsaxpy(int n, float* vecx, float* vecy, float* vecz, float a);

int main(void) {
    float scalar = 3.0f;

    int vectorLength = (int)pow(2, 30); //change to test cases (20, 24, 30)

    float* vx = (float*)malloc(vectorLength * sizeof(float));
    float* vy = (float*)malloc(vectorLength * sizeof(float));
	
	int j = 0;
    for (j = 0; j < vectorLength; j++) {
        vx[j] = (float)j+1;
        vy[j] = (float)j+2;
    }

    float* assemblyZ = (float*)malloc(vectorLength*sizeof(float));
    float* cZ = (float*)malloc(vectorLength * sizeof(float));

    double cTime;
    double cTimeAvg = 0;
    double asmTime;
    double asmTimeAvg = 0;

    for (j = 0; j < 30; j++) {
        clock_t start = clock();
        int i = 0;
        for (i = 0; i < vectorLength; i++) {
            cZ[i] = scalar * vx[i] + vy[i];
        }
        clock_t end = clock();
        cTime = (double)(end - start) / CLOCKS_PER_SEC;
        cTimeAvg += cTime;

        start = clock();
        asmsaxpy(vectorLength, vx, vy, assemblyZ, scalar);
        end = clock();

        asmTime = (double)(end - start) / CLOCKS_PER_SEC;
        asmTimeAvg += asmTime;
        printf("Vector Length\tC Time\t\tASM Time\n");
        printf("%d\t%f\t%f\n", vectorLength, cTime, asmTime);    
    }
    asmTimeAvg /= 30;
    cTimeAvg /= 30;

    printf("\nAVERAGE TIME AFTER 30 ITERATIONS:\n");
    printf("Vector Length\tC Time\t\tASM Time\n");
    printf("%d\t\t%f\t%f", vectorLength, cTimeAvg, asmTimeAvg);

    return 0;
}
