// This problem was asked by Spotify.

// You are the technical director of WSPT radio, serving listeners nationwide. 
// For simplicity's sake we can consider each listener to live along a horizontal line stretching from 0 (west) to 1000 (east).

// Given a list of N listeners, and a list of M radio towers, each placed at various locations along this line, 
// determine what the minimum broadcast range would have to be in order for each listener's home to be covered.

// For example, suppose listeners = [1, 5, 11, 20], and towers = [4, 8, 15]. In this case the minimum range would be 5, 
// since that would be required for the tower at position 15 to reach the listener at position 20.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void get_user_input(vector<int> &arr, int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        cout << "location: ";
        cin >> temp;
        arr.push_back(temp);
    }
}

int main() {
    int num_listeners;

    cout << "How many people are listening to the broadcast? ";
    cin >> num_listeners;

    cout << "Following problem statement, where does each listener live?" << endl;

    vector<int> listeners;

    get_user_input(listeners, num_listeners);

    int num_towers;

    cout << "How many radio towers exist in the area? ";
    cin >> num_towers;

    cout << "Where is each tower?" << endl;

    vector<int> towers;

    get_user_input(towers, num_towers);

    vector<vector<int> > distances;

    // Generate 2d vec of distances from tower->listener for each.
    if (listeners.size() > towers.size()) {
        for (int i = 0; i < listeners.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < towers.size(); j++) {
                temp.push_back(abs(listeners[i] - towers[j]));
            }
            distances.push_back(temp);
            temp.clear();
        }
    }

    // Generates single vector of min values for each set of distances
    vector<int> mins;
    int min = INT32_MAX;
    for (int i = 0; i < distances.size(); i++) {
        for (int j = 0; j < distances[i].size(); j++) {
            if (distances[i][j] < min)
                min = distances[i][j];
        }
        mins.push_back(min);
        min = INT32_MAX;
    }

    // Finds the max of the min values to get the minimum broadcast range.
    int max = -1;
    for (int i = 0; i < mins.size(); i++) {
        if (mins[i] > max)
            max = mins[i];
    }
    cout << "Minimum broadcast range: " << max << endl;

    return 0;
}