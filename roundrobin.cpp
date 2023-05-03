#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int pid; // process id
    int arrival_time; // arrival time
    int burst_time; // burst time
    int remaining_time; // remaining burst time
    int completion_time; // completion time
    int turnaround_time; // turnaround time
    int waiting_time; // waiting time
};

void roundRobin(vector<Process>& processes, int quantum) {
    queue<Process*> q;
    int n = processes.size();
    int time = 0;
    int completed = 0;
    int i = 0;

    while (completed < n) {
        while (i < n && processes[i].arrival_time <= time) {
            q.push(&processes[i]);
            i++;
        }

        if (q.empty()) {
            time = processes[i].arrival_time;
            continue;
        }

        Process* p = q.front();
        q.pop();

        if (p->remaining_time > quantum) {
            p->remaining_time -= quantum;
            time += quantum;
        } else {
            time += p->remaining_time;
            p->remaining_time = 0;
            p->completion_time = time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            completed++;
        }

        while (i < n && processes[i].arrival_time <= time) {
            q.push(&processes[i]);
            i++;
        }

        if (p->remaining_time > 0) {
            q.push(p);
        }
    }
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> quantum;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobin(processes, quantum);

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (auto p : processes) {
        cout << p.pid << "\t\t" << p.arrival_time << "\t\t" << p.burst_time << "\t\t" << p.completion_time << "\t\t" << p.turnaround_time << "\t\t" << p.waiting_time << endl;
    }
     float awt=0;
     float atat=0;
     for(int i=0;i<n;i++){
      awt+=(processes[i].arrival_time);
      atat+=(processes[i].turnaround_time);
     }
     cout<<"Average waiting time "<<(awt/n)<<" average turnaround time "<<(atat/n)<<endl;
    return 0;
}