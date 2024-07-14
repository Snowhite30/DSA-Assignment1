#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the console screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;
    clock_t start_time, end_time;
    double execution_time;
    int return_value = 41;

    // Start time
    start_time = clock();

    // Clear screen
    clear_screen();

    // Initialize arrays
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    // Read number of processes
    printf("enter the number of process: ");
    scanf("%d", &n);

    // Read burst times
    printf("enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Read arrival times
    printf("\nenter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate Gantt chart
    g[0] = 0;
    for (i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }

    // Calculate waiting time and turn-around time
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    }

    // Calculate average waiting time and turn-around time
    awt = awt / n;
    att = att / n;

    // Print the results
    printf("\n\tprocess\twaiting time\tturn arround time\n");
    for (i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    printf("the average waiting time is %f\n", awt);
    printf("the average turn around time is %f\n", att);

    // End time
    end_time = clock();
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print execution time and return value
    printf("\nProcess exited after %.2f seconds with return value %d\n", execution_time, return_value);
    printf("Press any key to continue . . .\n");
    getchar(); // To consume the newline character left by previous scanf
    getchar(); // To wait for an actual key press

    return return_value;
}
