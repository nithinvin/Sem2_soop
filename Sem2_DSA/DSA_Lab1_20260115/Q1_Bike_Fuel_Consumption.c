#include <stdio.h>

int main() {
	int distance;
	float fuel, average;

	printf("Input total distance in km: ");
	scanf("%d", &distance);

	printf("Input total fuel spent in liters: ");
	scanf("%f", &fuel);

	average = distance / fuel;
	printf("Average consumption (km/lt) %.2f\n", average);

	return 0;
}
