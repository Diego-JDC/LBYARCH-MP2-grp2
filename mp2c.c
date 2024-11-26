#include <stdio.h>

extern void asmsaxpy(int n, float* vecx, float* vecy, float* vecz, float a);

int main(void) {
	int vectorLength = 3;
	float scalar = 3.0;
	float vx[] = {1.0, 2.0, 3.0};
	float vy[] = {11.0, 12.0, 13.0};
	float* vz = (float*)malloc(vectorLength*sizeof(float));
	
	asmsaxpy(vectorLength, vx, vy, vz, scalar);
	
	//print out input parameters
	printf("length:\t%d  \nscalar:\t%2f \n", vectorLength, scalar);
	printf("vector x: ");
	int i;
	for(i=0; i<vectorLength; i++) {
		printf("\t%2f", vx[i]);
	}
	printf("\nvector y: ");
	for(i=0; i<vectorLength; i++) {
		printf("\t%2f", vy[i]);
	}
	
	//print output
	printf("\nvector z: ");
	for(i=0; i<vectorLength; i++) {
		printf("\t%2f", vz[i]);
	}
	return 0;
}
