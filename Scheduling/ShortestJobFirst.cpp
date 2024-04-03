#include <iostream>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
};

bool compare(Process a, Process b) {
    return a.bt < b.bt;
}

void findCT(Process proc[], int n, int ct[]) {
    sort(proc, proc + n, compare);
    
    int currentTime = 0; 
    
    for (int i = 0; i < n; i++) {
        if (proc[i].at > currentTime) {
            currentTime = proc[i].at;
        }

        ct[i] = currentTime + proc[i].bt;
        currentTime = ct[i];
    }
}

void findTAT(Process proc[], int n, int ct[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - proc[i].at;
    }
}

void findWT(Process proc[], int n, int tat[], int wt[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - proc[i].bt;
    }
}

void printResult(Process proc[], int n) {
    int ct[n], wt[n], tat[n];
    int total_wt = 0, total_tat = 0;
    
    findCT(proc, n, ct);
    findTAT(proc, n, ct, tat);
    findWT(proc, n, tat, wt);
    
    cout << "Process\tArrival\tBurst\tComplete\tTAT\t\tWaiting" << endl;
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << proc[i].pid << "\t\t" << proc[i].at << "\t\t" << proc[i].bt << "\t\t" << ct[i] << "\t\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    
    cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
    cout << "Average Waiting Time: " << (float)total_wt / n << endl;
}

int main() {
    cout << "Shortest Job First Scheduling\n";
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process proc[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT for Process " << i + 1 << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].pid = i + 1;
    }
    printResult(proc, n);
    return 0;
}
