#include <stdio.h>

#define MAX_SIZE 10

int main() {
    
    int arr[MAX_SIZE] = {1, 2, 4, 4, 5};
    int size = 5; 
    int value, position;

    printf("--- Array Operations Demo (Simplified) ---\n");

  
    printf("\n[1] TRAVERSAL: Initial Array\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    value = 3;
    position = 2; 

    printf("\n[2] INSERTION: Insert %d at index %d\n", value, position);
    

    if (size < MAX_SIZE) {
        
        
        for (int i = size - 1; i >= position; i--) {
            arr[i + 1] = arr[i]; 
            
        }
        
   
        arr[position] = value;
        
      
        size++;

    } else {
        printf("ERROR: Array is full. Cannot insert.\n");
    }

  
    printf("   Array after insertion (size=%d): \n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    position = 3;

    printf("\n[3] DELETION: Delete element at index %d\n", position);


    if (position >= 0 && position < size) {

        
        for (int i = position + 1; i < size; i++) {
            arr[i - 1] = arr[i];

        }
        
        
        size--;

    } else {
        printf("ERROR: Invalid position for deletion.\n");
    }

    printf("   Array after deletion (size=%d): \n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}