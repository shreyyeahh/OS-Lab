#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to simulate work-from-office dynamics
int calculate_days_to_rostering(int N, vector<vector<int>>& friends, int K) {
    // Initialize the roster and friendship graph
    vector<vector<int>> adj(N);
    for (const auto& pair : friends) {
        adj[pair[0]].push_back(pair[1]);
        adj[pair[1]].push_back(pair[0]);
    }

    // Initial state: Everyone works from office (Day 1)
    vector<int> current_state(N, 1); // 1 -> WFO, 0 -> WFH
    int rostering_value = N;         // Day 1 all employees work from office
    int days = 1;

    // Continue simulation until rostering value >= K
    while (rostering_value < K) {
        vector<int> next_state(N, 0);
        int daily_count = 0;

        for (int i = 0; i < N; ++i) {
            int wfo_friends = 0;

            // Count the number of friends working from office
            for (int friend_id : adj[i]) {
                if (current_state[friend_id] == 1) {
                    wfo_friends++;
                }
            }

            // Apply rules to decide next state
            if (current_state[i] == 1) {
                next_state[i] = (wfo_friends == 3) ? 1 : 0;
            } else {
                next_state[i] = (wfo_friends < 3) ? 1 : 0;
            }

            // Update daily count of WFO
            daily_count += next_state[i];
        }

        // Update cumulative rostering value and state
        rostering_value += daily_count;
        current_state = next_state;
        days++;
    }

    return days;
}

int main() {
    int N, M, K;
    cin >> N >> M;

    vector<vector<int>> friends(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        friends[i] = {a, b};
    }

    cin >> K;

    // Calculate the number of days required to reach the rostering value
    int result = calculate_days_to_rostering(N, friends, K);
    cout << result << endl;

    return 0;
}
