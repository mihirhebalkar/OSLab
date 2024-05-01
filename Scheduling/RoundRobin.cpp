#include <stdio.h>


#define MAXP 10
#define TS 4


struct Process {
   int id;
   int bt;
   int rt; //remaining time
   int at;
};


void roundRobin(struct Process processes[], int n) {
   int current_time = 0;
   int sequence[MAXP * 2];
   int sequence_index = 0;
   int completed_processes = 0;


   while (completed_processes < n) {
       for (int i = 0; i < n; i++) {
           if (processes[i].rt > 0 && processes[i].at <= current_time) {
               int execution_time;


               if (processes[i].rt < TS) {
                   execution_time = processes[i].rt;
               } else {
                   execution_time = TS;
               }
              
               current_time += execution_time;
               processes[i].rt -= execution_time;


               printf("P%d %d-%d\n", processes[i].id, current_time - execution_time, current_time);
              
               sequence[sequence_index++] = processes[i].id;
               sequence[sequence_index++] = current_time;


               if (processes[i].rt <= 0) {
                   completed_processes++;
               }
           }
       }
   }


   printf("\nExecution Sequence: ");
   for (int i = 0; i < sequence_index; i += 2) {
       printf("P%d ", sequence[i]);
   }
   printf("\n");
}


int main() {
   int n;
   printf("Enter the number of processes: ");
   scanf("%d", &n);


   struct Process processes[MAXP];


   printf("Enter burst time and arrival time:\n");
   for (int i = 0; i < n; i++) {
       printf("Process %d burst time: ", i+1);
       scanf("%d", &processes[i].bt);
       processes[i].rt = processes[i].bt;
       processes[i].id = i + 1;


       printf("Process %d arrival time: ", i+1);
       scanf("%d", &processes[i].at);
   }


   printf("\nRound Robin Scheduling:\n");
   roundRobin(processes, n);


   return 0;
}
