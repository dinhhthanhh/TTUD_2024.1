#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Structure to store information about a call
struct Call {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

// Utility function to check if a phone number is valid
bool is_valid_phone_number(const string &phone_number) {
    if (phone_number.size() != 10) return false;
    for (char c : phone_number) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Utility function to calculate time duration in seconds between two time points
int time_difference_in_seconds(const string &from_time, const string &end_time) {
    int from_h, from_m, from_s, end_h, end_m, end_s;
    sscanf(from_time.c_str(), "%d:%d:%d", &from_h, &from_m, &from_s);
    sscanf(end_time.c_str(), "%d:%d:%d", &end_h, &end_m, &end_s);

    int from_total_seconds = from_h * 3600 + from_m * 60 + from_s;
    int end_total_seconds = end_h * 3600 + end_m * 60 + end_s;

    return end_total_seconds - from_total_seconds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<Call> calls;  // To store all call records
    unordered_map<string, int> call_count;  // To store the number of calls from each phone number
    unordered_map<string, int> call_duration;  // To store the total duration of calls from each phone number

    string line;
    bool all_phone_numbers_valid = true;  // To track if all phone numbers are valid
    int total_calls = 0;

    vector<string> results;  // To store results and print them later

    // Reading the first block of call data
    while (getline(cin, line)) {
        if (line == "#") break;
        stringstream ss(line);
        string cmd, from_number, to_number, date, from_time, end_time;
        ss >> cmd >> from_number >> to_number >> date >> from_time >> end_time;

        // Process the call record
        if (cmd == "call") {
            // Validate the phone numbers
            if (!is_valid_phone_number(from_number) || !is_valid_phone_number(to_number)) {
                all_phone_numbers_valid = false;
            }

            // Store the call record
            calls.push_back({from_number, to_number, date, from_time, end_time});
            call_count[from_number]++;
            call_duration[from_number] += time_difference_in_seconds(from_time, end_time);
            total_calls++;
        }
    }

    // Reading the second block of queries
    while (getline(cin, line)) {
        if (line == "#") break;
        stringstream ss(line);
        string query, phone_number;
        ss >> query;

        if (query == "?check_phone_number") {
            results.push_back(to_string(all_phone_numbers_valid ? 1 : 0));
        } else if (query == "?number_calls_from") {
            ss >> phone_number;
            results.push_back(to_string(call_count[phone_number]));
        } else if (query == "?number_total_calls") {
            results.push_back(to_string(total_calls));
        } else if (query == "?count_time_calls_from") {
            ss >> phone_number;
            results.push_back(to_string(call_duration[phone_number]));
        }
    }

    // Output results after second block finishes
    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
