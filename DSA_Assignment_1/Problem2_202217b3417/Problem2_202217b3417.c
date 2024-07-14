#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
struct poly {
    int coeff;
    int expo;
};

// Function prototypes
int readPoly(struct poly **p);
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void displayPoly(struct poly p[], int term);

int main() {
    int t1, t2, t3;

    // Read and display first polynomial
    struct poly *p1 = NULL;
    t1 = readPoly(&p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);

    // Read and display second polynomial
    struct poly *p2 = NULL;
    t2 = readPoly(&p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);

    // Add two polynomials and display resultant polynomial
    struct poly *p3 = (struct poly *)malloc((t1 + t2) * sizeof(struct poly)); // Allocate enough memory
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);

    // Free allocated memory
    free(p1);
    free(p2);
    free(p3);

    printf("\n");
    return 0;
}

// Function to read a polynomial from the user
int readPoly(struct poly **p) {
    int t1, i;
    printf("\nEnter the number of terms in the polynomial: ");
    scanf("%d", &t1);
    
    *p = (struct poly *)malloc(t1 * sizeof(struct poly)); // Allocate memory
    
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("Enter Coefficient(%d): ", i + 1);
        scanf("%d", &(*p)[i].coeff);
        printf("Enter Exponent(%d): ", i + 1);
        scanf("%d", &(*p)[i].expo);
    }
    return t1;
}

// Function to add two polynomials
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // For remaining terms of polynomial 1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // For remaining terms of polynomial 2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    return k; // k is number of terms in resultant polynomial
}

// Function to display a polynomial
void displayPoly(struct poly p[], int term) {
    for (int k = 0; k < term - 1; k++) {
        printf("%d(x^%d)+", p[k].coeff, p[k].expo);
    }
    printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].expo);
}
