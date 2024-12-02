#include <stdio.h>
#include <stdlib.h>

extern void asmsaxpy(int n, float* vecx, float* vecy, float* vecz, float a);

int main(void) {
    float scalar = 3.0f;

    int vectorLength = 5;

    float* vx = (float*)malloc(vectorLength * sizeof(float));
    float* vy = (float*)malloc(vectorLength * sizeof(float));

    int i;
    for (i = 0; i < vectorLength; i++) {
        vx[i] = (float)i+1;
        vy[i] = (float)i+2;
    }

    float* assemblyZ = (float*)malloc(vectorLength*sizeof(float));
    float* cZ = (float*)malloc(vectorLength * sizeof(float));
	
	for (i = 0; i < vectorLength; i++) {
        cZ[i] = scalar * vx[i] + vy[i];
    }

    asmsaxpy(vectorLength, vx, vy, assemblyZ, scalar);

    printf("C\t\tASM\n");
    for (i = 0; i < vectorLength; i++) {
        printf("%f\t%f\n", cZ[i], assemblyZ[i]);
    }

    return 0;
}
