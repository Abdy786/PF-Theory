#include <stdio.h>

int main() {
    int arr[5], smallest, smallest2, i;

    printf("Please enter 5 numbers:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        
        // Ensure the input is within the valid range
        while(arr[i] >= 9999) {
            printf("That number is too high! Please enter a value under 9999: ");
            scanf("%d", &arr[i]);
        }
    }

    smallest = smallest2 = 9999;
    
    // Find the smallest and second smallest values
    for(i = 0; i < 5; i++) {
        if(arr[i] < smallest) {
            smallest2 = smallest;
            smallest = arr[i];
        } else if(arr[i] < smallest2 && arr[i] != smallest) {
            smallest2 = arr[i];
        }
    }

    if(smallest2 == 9999) {
        printf("\nAll elements in the array are the same; no second smallest element.\n");
    } else {
        printf("\nThe second smallest number in the list is: %d\n", smallest2);
    }

    return 0;
}
