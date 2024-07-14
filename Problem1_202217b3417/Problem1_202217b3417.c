#include <stdio.h>
#include <conio.h>
#define MAX 20

// Step 1: Define all global variables and functions.
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, p, e, i, pos;

void main() {
    // clrscr();
    int ch;
    char g = 'y';
    
    // Step 2: Get the option from user and execute switch statement.
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    } while(g == 'y' || g == 'Y');
    getch();
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if(n == 0) {
        printf("\nThe list is empty.");
        return;
    }
    
    printf("\nEnter the position you want to delete (1-based index): ");
    scanf("%d", &pos);
    if(pos < 1 || pos > n) {
        printf("\nInvalid location.");
    } else {
        for(i = pos - 1; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    printf("\nThe elements after deletion: ");
    for(i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    int searchChoice;
    printf("\nSearch by:\n1. Element\n2. Position\nEnter your choice: ");
    scanf("%d", &searchChoice);

    if(searchChoice == 1) {
        int found = 0;
        printf("\nEnter the element to be searched: ");
        scanf("%d", &e);
        for(i = 0; i < n; i++) {
            if(b[i] == e) {
                printf("Value %d is in position %d\n", e, i + 1);
                found = 1;
                break; // Exit loop once the element is found
            }
        }
        if (!found) {
            printf("Value %d is not in the list.\n", e);
        }
    } else if(searchChoice == 2) {
        printf("\nEnter the position to fetch (1-based index): ");
        scanf("%d", &pos);
        if(pos < 1 || pos > n) {
            printf("\nInvalid position.\n");
        } else {
            printf("Value at position %d is %d\n", pos, b[pos - 1]);
        }
    } else {
        printf("Invalid search choice.\n");
    }
}

void insert() {
    printf("\nEnter the position where you need to insert (1-based index): ");
    scanf("%d", &pos);
    if(pos < 1 || pos > n + 1) {
        printf("\nInvalid location.");
    } else if(n == MAX) {
        printf("\nThe list is full.");
    } else {
        for(i = n; i >= pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos - 1] = p;
        n++;
    }
    printf("\nThe list after insertion: ");
    display();
}

void display() {
    printf("\nThe elements of the list are: ");
    for(i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}
