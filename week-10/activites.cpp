#include <iostream>
using namespace std;
struct Activity {
    int start;
    int finish;
};

int main() {
    
    int N;
    cout<<"Enter the No. of Activities: ";
    cin >> N;
    Activity* activities = new Activity[N];
    cout<<"Enter the Start time: ";
    for (int i = 0; i < N; i++) {
        cin >> activities[i].start;
    }
    cout<<"Enter the Finish Time: ";
    for (int i = 0; i < N; i++) {
        cin >> activities[i].finish;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (activities[i].finish > activities[j].finish) {
                Activity temp = activities[i];
                activities[i] = activities[j];
                activities[j] = temp;
            }
        }
    }
    int maxActivities = 1;
    int* selectedActivities = new int[N];
    selectedActivities[0] = 0;
    int lastFinishTime = activities[0].finish;
    int selectedCount = 1;

    for (int i = 1; i < N; i++) {
        if (activities[i].start >= lastFinishTime) {
            selectedActivities[selectedCount] = i;
            selectedCount++;
            maxActivities++;
            lastFinishTime = activities[i].finish;
        }
    }

    cout << "\nNo. of non-conflicting activities: " << maxActivities << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < selectedCount; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << selectedActivities[i] + 1;
    }
    cout << endl;
    return 0;
}