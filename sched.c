#include<iostream> 
using namespace std; 
  
// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, int burstTime[], int waitTime[], int time_quantum) 
{ 
    // Make a copy of burst times burstTime[] to store remaining 
    // burst times. 
    int remaining_burst[n]; 
    for (int i = 0 ; i < n ; i++) 
        remaining_burst[i] =  burstTime[i]; 
  
    int t = 0; // Current time 
  
    // Keep traversing processes in round robin manner 
    // until all of them are not done. 
    while (1) 
    { 
        bool done = true; 
  
        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < n; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (remaining_burst[i] > 0) 
            { 
                done = false; // There is a pending process 
  
                if (remaining_burst[i] > time_quantum) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += time_quantum; 
  
                    // Decrease the burst_time of current process 
                    // by time_quantum 
                    remaining_burst[i] -= time_quantum; 
                } 
  
                // If burst time is smaller than or equal to 
                // time_quantum. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + remaining_burst[i]; 
  
                    // Waiting time is current time minus time 
                    // used by this process 
                    waitTime[i] = t - burstTime[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    remaining_burst[i] = 0; 
                } 
            } 
        } 
  
        // If all processes are done 
        if (done == true) 
          break; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, int burstTime[], int waitTime[], int turnAroundTime[]) 
{ 
    // calculating turnaround time by adding 
    // burstTime[i] + waitTime[i] 
    for (int i = 0; i < n ; i++) 
        turnAroundTime[i] = burstTime[i] + waitTime[i]; 
} 
  
// Function to calculate average time 
void findavgTime(int processes[], int n, int burstTime[], 
                                     int time_quantum) 
{ 
    int waitTime[n], turnAroundTime[n], total_waitTime = 0, total_turnAroundTime = 0; 
  
    // Function to find waiting time of all processes 
    findWaitingTime(processes, n, burstTime, waitTime, time_quantum); 
  
    // Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, burstTime, waitTime, turnAroundTime); 
  
    // Display processes along with all details 
    cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int i=0; i<n; i++) 
    { 
        total_waitTime = total_waitTime + waitTime[i]; 
        total_turnAroundTime = total_turnAroundTime + turnAroundTime[i]; 
        cout << " " << i+1 << "\t\t" << burstTime[i] <<"\t "<< waitTime[i] <<"\t\t " << turnAroundTime[i] <<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)total_waitTime / (float)n; 
    cout << "\nAverage turn around time = " << (float)total_turnAroundTime / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    // process id's 
    int processes[] = { 1, 2, 3, 4}; 
    int n = sizeof processes / sizeof processes[0]; 
  
    // Burst time of all processes 
    int burst_time[] = {53, 8, 68, 24}; 
  
    // Time time_quantum 
    int time_quantum = 20; 
    findavgTime(processes, n, burst_time, time_quantum); 
    return 0; 
}
