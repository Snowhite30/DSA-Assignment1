#include <stdio.h>
#include <stdlib.h>
#define n 5  // Size of the queue

void main() {
    int queue[n], ch = 1, front = 0, rear = 0, j = 1;

    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    
    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:  // Insertion
                if (rear == n) {  // Queue is full
                    printf("\nQueue is Full");
                } else {
                    printf("\n Enter number %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:  // Deletion
                if (front == rear) {  // Queue is empty
                    printf("\nQueue is Empty");
                } else { 
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;
            case 3:  // Display
                printf("\nQueue Elements are:\n");
                if (front == rear) {  // Queue is empty
                    printf("\nQueue is Empty");
                } else {
                    for (int i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;
            case 4:  // Exit
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
        }
    }
}
