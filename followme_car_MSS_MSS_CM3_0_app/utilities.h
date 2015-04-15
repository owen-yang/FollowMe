#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <float.h>
#include <math.h>

int minIdxArrayFloat(float *arr, int size);
int maxIdxArrayFloat(float *arr, int size);

/**
 * Positively shifts the index of each element by one
 */
void shiftUpArrayInt(int *arr, int size) {
	int i;
	for (i = size-1; i > 0; --i) {
		arr[i] = arr[i-1];
	}
}

/**
 * Positively shifts the index of each element by one
 */
void shiftUpArrayFloat(float *arr, int size) {
	int i;
	for (i = size-1; i > 0; --i) {
		arr[i] = arr[i-1];
	}
}

/**
 * Returns the average of an integer array
 */
int avgArrayInt(int *arr, int size) {
	int i;
	long long sum = 0;
	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}

/**
 * Returns the average of a float array
 */
float avgArrayFloat(float *arr, int size) {
	int i;
	double sum = 0;
	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum / size;
}

double sumArrayFloat(float *arr, int size) {
	int i;
	double sum = 0;
	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

/**
 * Returns the average of the middle 80% of a float array (discards the top and bottom 10%)
 */
float avg80ArrayFloat(float *arr, int size) {
	int i;
	double sum = 0;

	int discardsSize = size * 0.10;
	int discardsCapacity = sizeof(float) * discardsSize;
	float *discardsTop = malloc(discardsCapacity);
	float *discardsBottom = malloc(discardsCapacity);

	for (i = 0; i < discardsSize; ++i) {
		discardsTop[i] = FLT_MIN;
		discardsBottom[i] = FLT_MAX;
	}

	for (i = 0; i < size; ++i) {
		int bottomMaxIdx = maxIdxArrayFloat(discardsBottom, discardsSize);
		int topMinIdx = minIdxArrayFloat(discardsTop, discardsSize);

		if (arr[i] > discardsTop[topMinIdx]) {
			discardsTop[topMinIdx] = arr[i];
		}
		if (arr[i] < discardsBottom[bottomMaxIdx]) {
			discardsBottom[bottomMaxIdx] = arr[i];
		}
	}

	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}

	sum -= sumArrayFloat(discardsTop, discardsSize);
	sum -= sumArrayFloat(discardsBottom, discardsSize);

	free(discardsTop);
	free(discardsBottom);
	return sum / (size - 2*discardsSize);
}

int minIdxArrayFloat(float *arr, int size) {
	int idx = 0;
	int i;
	for (i = 0; i < size; ++i) {
		if (arr[i] < arr[idx]) {
			idx = i;
		}
	}
	return idx;
}

int maxIdxArrayFloat(float *arr, int size) {
	int idx = 0;
	int i;
	for (i = 0; i < size; ++i) {
		if (arr[i] > arr[idx]) {
			idx = i;
		}
	}
	return idx;
}

/**
 * Low-pass filters the values, returning the newest filtered value
 */
void lpfArrayFloat(float *arr, int size, float newVal) {
	const float alpha = 0.8; // alpha between 0 and 1 (0 = no smoothing, 1 = no change)

	int i;
	for (i = size-2; i >= 0; --i) {
		arr[i] = alpha * arr[i+1] + (1-alpha)*newVal;
	}
}

#endif /* UTILITIES_H_ */
