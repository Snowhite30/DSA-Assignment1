#include <stdio.h>

#define MAX 100  // Fixed stack size

int stack[MAX], choice, top, x, i;

void push(void);
void pop(void);
void display(void);

int main() {
    top = -1;

    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. DISPLAY\n\t4. EXIT");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT");
                break;
            default:
                printf("\n\tPlease enter a valid choice (1/2/3/4)");
        }
    } while (choice != 4);
    return 0; 
}

void push() {
    if (top >= MAX - 1) {
        display();  // Display the current elements in the stack
        return;     // Exit the function
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top <= -1) {
        printf("\n\tSTACK is underflow");
    } else {
        printf("\n\tThe popped element is %d", stack[top]);
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in STACK:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
        printf("Press Next Choice");
    } else {
        printf("\nThe STACK is empty");
    }
}
