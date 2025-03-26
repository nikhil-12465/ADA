#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
    double profit;
};

bool compareByEnd(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

bool compareByStart(Activity a1, Activity a2) {
    return a1.start < a2.start;
}

bool compareByProfitPerHour(Activity a1, Activity a2) {
    double profit1 = a1.profit / (a1.end - a1.start);
    double profit2 = a2.profit / (a2.end - a2.start);
    return profit1 > profit2;
}

void selectMaxActivities(vector<Activity>& activities, string sortingMethod) {
    if (activities.empty()) return;

    int count = 0;
    int lastEndTime = -1;

    cout << "\n" << sortingMethod << ":\n";
    cout << "Selected activities: \n";

    for (const auto& act : activities) {
        if (act.start >= lastEndTime) {
            cout << "(" << act.start << ", " << act.end << ", Profit: " << act.profit << ")\n";
            lastEndTime = act.end;
            count++;
        }
    }

    cout << "Maximum number of non-overlapping activities: " << count << endl;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start time, end time, and profit of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end >> activities[i].profit;
    }

    vector<Activity> activitiesEnd = activities;
    sort(activitiesEnd.begin(), activitiesEnd.end(), compareByEnd);
    selectMaxActivities(activitiesEnd, "Sorted by Ending Time (Standard Greedy)");

    vector<Activity> activitiesStart = activities;
    sort(activitiesStart.begin(), activitiesStart.end(), compareByStart);
    selectMaxActivities(activitiesStart, "Sorted by Starting Time");

    vector<Activity> activitiesProfit = activities;
    sort(activitiesProfit.begin(), activitiesProfit.end(), compareByProfitPerHour);
    selectMaxActivities(activitiesProfit, "Sorted by Profit Per Hour");

    return 0;
}
