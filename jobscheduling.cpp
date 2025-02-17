#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(vector<Job> jobs, int n) {
    sort(jobs.begin(), jobs.end(), comparison);

    vector<int> result(n, -1);
    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job sequence: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = jobs.size();
    printJobScheduling(jobs, n);
    return 0;
}
