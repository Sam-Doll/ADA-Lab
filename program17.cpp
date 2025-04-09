#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start;  // start time of activity
    int end;    // end time of activity
};

// Comparison function to sort activities by their end time
bool compare(Activity a, Activity b) {
    return a.end < b.end; // sort the activities in increasing order of their end times
}

// Function to find the maximum number of activities that can be performed
int maxActivities(int n, int s[], int e[]) {
    vector<Activity> activity;
    for(int i = 0; i < n; i++) {
        activity.push_back({s[i], e[i]});
    }

    // Sort the activities according to their end times
    sort(activity.begin(), activity.end(), compare);

    int cnt = 0; // to count the number of selected activities
    int last = activity[0].end; // end time of the first activity

    cout << "Selected activities:\n";
    cout << activity[0].start << " " << activity[0].end << endl;
    cnt++;

    for(int i = 1; i < n; i++) {
        if(activity[i].start >= last) { // if the activity starts after the last selected activity ends
            cout << activity[i].start << " " << activity[i].end << endl;
            last = activity[i].end; // update the last activity end time
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    int s[n], e[n];
    cout << "Enter start and end times of each activity:\n";
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }

    int maxAct = maxActivities(n, s, e);
    cout << "Maximum number of activities: " << maxAct << endl;
    return 0;
}
