/*Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300*/
#include <bits/stdc++.h>

using namespace std;

// Cấu trúc lưu trữ thông tin của công việc
struct Job {
    int deadline;
    int profit;
};

// Hàm so sánh để sắp xếp công việc theo lợi nhuận giảm dần
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n; // Số lượng công việc
    cin >> n;
    
    vector<Job> jobs(n);
    int maxDeadline = 0; // Biến để theo dõi deadline lớn nhất
    
    // Nhập thông tin công việc
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline; // Cập nhật deadline lớn nhất
        }
    }
    
    // Sắp xếp công việc theo lợi nhuận giảm dần
    sort(jobs.begin(), jobs.end(), compare);
    
    // Mảng để đánh dấu thời điểm đã sử dụng
    vector<int> timeSlot(maxDeadline + 1, -1); // -1 biểu thị chưa sử dụng
    
    int totalProfit = 0;
    
    // Duyệt qua các công việc
    for (int i = 0; i < n; i++) {
        // Tìm thời điểm trống để thực hiện công việc này
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (timeSlot[j] == -1) { // Nếu thời gian này chưa được sử dụng
                timeSlot[j] = i; // Đánh dấu thời điểm này đã sử dụng
                totalProfit += jobs[i].profit; // Cộng lợi nhuận của công việc
                break;
            }
        }
    }
    
    // Xuất tổng lợi nhuận tối đa
    cout << totalProfit << endl;
    
    return 0;
}
