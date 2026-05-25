#include <stdio.h>
#include <stdlib.h>

// Directions
#define LEFT  -1
#define RIGHT  1

// Structure to store number and its direction
typedef struct {
    int value;
    int dir;
} Element;

// Function to print current permutation
void printPermutation(Element arr[], int n) {
    // Print arrows (directions)
    for (int i = 0; i < n; i++) {
        if (arr[i].dir == LEFT)
            printf("<- ");
        else
            printf("-> ");
    }
    printf("\n");

    // Print values
    for (int i = 0; i < n; i++) {
        printf("%2d ", arr[i].value);
    }
    printf("\n\n");
}

// Find the largest mobile element
int getMobile(Element arr[], int n) {
    int mobile_index = -1;
    int mobile_value = 0;

    for (int i = 0; i < n; i++) {
        int next = i + arr[i].dir;

        if (next >= 0 && next < n) {
            if (arr[i].value > arr[next].value && arr[i].value > mobile_value) {
                mobile_value = arr[i].value;
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

// Reverse direction of elements greater than given value
void reverseDirection(Element arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i].value > value) {
            arr[i].dir *= -1;
        }
    }
}

// Johnson-Trotter function
void johnsonTrotter(int n) {
    Element *arr = (Element *)malloc(n * sizeof(Element));

    // Initialize elements
    for (int i = 0; i < n; i++) {
        arr[i].value = i + 1;
        arr[i].dir = LEFT;
    }

    printPermutation(arr, n);

    while (1) {
        int mobile_index = getMobile(arr, n);

        if (mobile_index == -1)
            break;

        int swap_index = mobile_index + arr[mobile_index].dir;

        // Swap
        Element temp = arr[mobile_index];
        arr[mobile_index] = arr[swap_index];
        arr[swap_index] = temp;

        // Reverse directions
        reverseDirection(arr, n, arr[swap_index].value);

        printPermutation(arr, n);
    }

    free(arr);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
