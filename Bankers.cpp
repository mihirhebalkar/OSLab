#include<iostream>
using namespace std;


const int P = 5;
const int R = 4;


void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R]) {
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}


bool isSafe(int processes[], int avail[], int maxm[][R], int allot[][R]) {
    int need[P][R];


    calculateNeed(need, maxm, allot);


    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];


    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;


                if (j == R) {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];


                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false) {
            cout << "System is not in safe state";
            return false;
        }
    }
    cout << "System is in safe state.\nSafe sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << "P"<<safeSeq[i] << "->";


    cout<<"End";
    return true;
}


int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {1, 5, 2, 0};
    int maxm[][R] = {{0, 0, 1, 2},
                     {1, 7, 5, 0},
                     {2, 3, 5, 6},
                     {0, 6, 5, 2},
                     {0, 6, 5, 6}};
                     
    int allot[][R] = {{0, 0, 1, 2},
                      {1, 0, 0, 0},
                      {1, 3, 5, 4},
                      {0, 6, 3, 2},
                      {0, 0, 1, 4}};
    int need[P][R];
    calculateNeed(need, maxm,allot);
                     
    cout<<"Process\t\tAllocated\tMax\t\tNeed";
    for(int i=0;i<P;i++) {
        cout<<"\n";
        cout<<processes[i]<<" ";
       
        cout<<"\t\t";
        for(int j=0;j<R;j++) {
            cout<<allot[i][j]<<" ";
        }
        cout<<"\t";
       
        for(int j=0;j<R;j++) {
            cout<<maxm[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<R;j++) {
            cout<<need[i][j]<<" ";
        }
 }
    cout<<"\n\n";
    isSafe(processes, avail, maxm, allot);


    return 0;
}
