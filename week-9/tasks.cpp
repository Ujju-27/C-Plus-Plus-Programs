#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortTasks(int n, int times[], int deadlines[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (deadlines[j] > deadlines[j + 1]) {
                swap(times[j], times[j + 1]);
                swap(deadlines[j], deadlines[j + 1]);
            }
        }
    }
}

int findMaxTasks(int n, int times[], int deadlines[], int selectedTasks[]) {
    sortTasks(n, times, deadlines);

    int tasksCompleted = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + times[i] <= deadlines[i]) {
            tasksCompleted++;
            currentTime += times[i];
            selectedTasks[tasksCompleted - 1] = i + 1; // Increment task number by 1
        }
    }

    return tasksCompleted;
}

int main() {
    int n;
    cout << "Enter the total number of tasks: ";
    cin >> n;

    int times[n];
    int deadlines[n];

    cout << "Enter the time taken for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    cout << "Enter the deadlines for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> deadlines[i];
    }

    int selectedTasks[n];
    int maxTasks = findMaxTasks(n, times, deadlines, selectedTasks);

    cout << "Maximum number of tasks that can be completed: " << maxTasks << endl;
    cout << "Selected task numbers: ";
    for (int i = 0; i < maxTasks; i++) {
        cout << selectedTasks[i];
        if (i < maxTasks - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
