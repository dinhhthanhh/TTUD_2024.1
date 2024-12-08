/*There are n jobs 1, 2, . . ., n that must be executed. Job i has the duration d[i]: if job i starts at time-point t, then it finishes at time-point t+d[i]. At any time-point, at most one job can start to execute. Find the schedule (specify the time-point for starting each job) for executing all n given jobs so that completion time T (all jobs finish before or at T) is minimal (starting time-point is 0).

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains n positive integers d[1], d[2], ..., d[n] (1 <= d[i] <= 1000000)

Output
Write T 

Example
Input
5
3 7 4 9 1

Output 
9

Explanation
Job 1 starts at time-point 3 and finishes at time-point 6
Job 2 starts at time-point 1 and finishes at time-point 8
Job 3 starts at time-point 2 and finishes at time-point 6
Job 4 starts at time-point 0 and finishes at time-point 9 
Job 5 starts at time-point 4 and finishes at time-point 5*/
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int duration;
    int index;
};

bool compare(Job a, Job b) {
    return a.duration > b.duration; // Sắp xếp theo thời gian làm việc giảm dần
}

int main() {
    int n;
    cin >> n;
    
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].duration;
        jobs[i].index = i; // Lưu chỉ số công việc gốc
    }
    
    // Sắp xếp công việc theo thời gian làm việc giảm dần
    sort(jobs.begin(), jobs.end(), compare);
    
    vector<int> start_times(n);
    vector<int> finish_times(n); // Thêm vector để lưu thời gian kết thúc của từng công việc
    int current_time = 0;
    
    // Gán thời điểm bắt đầu và kết thúc của công việc
    for (int i = 0; i < n; ++i) {
        start_times[jobs[i].index] = current_time;
        finish_times[jobs[i].index] = current_time + jobs[i].duration;
        current_time++; // Tăng thời điểm bắt đầu cho công việc tiếp theo
    }
    
    // Thời gian kết thúc muộn nhất là giá trị lớn nhất trong finish_times
    int max_completion_time = *max_element(finish_times.begin(), finish_times.end());
    
    cout << max_completion_time << endl;

    
    return 0;
}
