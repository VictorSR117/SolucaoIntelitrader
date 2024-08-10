#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to find the shortest distance between elements of two arrays
int findTheMinimumDistance(int array1[], int sizeOfArray1, int array2[], int sizeOfArray2) {
    int minDistance = abs(array1[0] - array2[0]);

    for (int array1Iterator = 0; array1Iterator < sizeOfArray1; array1Iterator++) {
        for (int array2Iterator = 0; array2Iterator < sizeOfArray2; array2Iterator++) {
            int currentDistance = abs(array1[array1Iterator] - array2[array2Iterator]);
            if (currentDistance < minDistance) minDistance = currentDistance;
        }
    }

    return minDistance;
}

void main() {
    const int SIZEOFARRAY1 = 10;
    const int SIZEOFARRAY2 = 10;

    int arrayOne[SIZEOFARRAY1];
    int arrayTwo[SIZEOFARRAY2];

    // Initialize the random number generator with the current time
    srand(time(NULL));
    // Fill arrays with random numbers
    for (int iterator = 0; iterator < SIZEOFARRAY1; iterator++) arrayOne[iterator] = rand() % 200 + 1; // Generates random numbers between 0 and 200
    for (int iterator = 0; iterator < SIZEOFARRAY2; iterator++) arrayTwo[iterator] = rand() % 200 + 1; // Generates random numbers between 0 and 200
    // Test values
    // int arrayOne[] = {1, 5, 10, 20, 40, 80, 100, 120, 140, 160};
    // int arrayTwo[] = {6, 15, 25, 35, 45, 55, 65, 75, 85, 95};

    // Shows the generated numbers
    printf("Array 1: ");
    for (int iterator = 0; iterator < SIZEOFARRAY1; iterator++) printf("%d ", arrayOne[iterator]);
    
    printf("\nArray 2: ");
    for (int iterator = 0; iterator < SIZEOFARRAY2; iterator++) printf("%d ", arrayTwo[iterator]);
    
    // Finds and shows the shortest distance
    int minimumDistance = findTheMinimumDistance(arrayOne, SIZEOFARRAY1, arrayTwo, SIZEOFARRAY2);
    printf("\n\nA menor distância entre dois números, dos dois arrays informados é: %d\n", minimumDistance);
}