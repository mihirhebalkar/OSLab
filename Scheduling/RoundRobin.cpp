#include <stdio.h>

// Function to calculate maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // Read the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], arrival_time[n], waiting_time[n], turnaround_time[n], completion_time[n];

    // Read burst time for each process
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Read arrival time for each process
    printf("Enter arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Calculate completion time, waiting time, and turnaround time
    completion_time[0] = burst_time[0] + arrival_time[0];
    turnaround_time[0] = completion_time[0] - arrival_time[0];
    waiting_time[0] = 0;

    for (i = 1; i < n; i++) {
        completion_time[i] = max(completion_time[i - 1], arrival_time[i]) + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = max(0, completion_time[i - 1] - arrival_time[i]);
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Display process details
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i],
               waiting_time[i], turnaround_time[i], completion_time[i]);
    }

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
