// Needs more testing - might still be incomplete.

// This problem was asked by Snapchat.

// You are given an array of length N, where each element i represents the number of ways we can produce i units of change. 
// For example, [1, 0, 1, 1, 2] would indicate that there is only one way to make 0, 2, or 3 units, and two ways of making 4 units.

// Given such an array, determine the denominations that must be in use. 
// In the case above, for example, there must be coins with value 2, 3, and 4.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define N 5

bool input_error = false;

// Will run into the case where there are more known multiples than ways of making that number of units
// Will need to find the number of multiples for each unit in 

void insert_unique(vector<int> &vec, int value) {
    bool element_found = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value)
            element_found = true;
    }

    if (!element_found)
        vec.push_back(value);
}

void get_each_denom(vector<int> &denom, int value) {
    denom.push_back(value);
    for (int i = 1; i < value; i++) {
        for (int j = 1; j < value; j++) {
            if (i + j == value) {
                insert_unique(denom, i);
                insert_unique(denom, j);
            }
        }
    }
}

// Take ex: units: 4, num_ways: 2
// There are two multiples of 4: 2, 2
void find_denom(vector<int> &coins, int units, int num_ways) {
    vector<int> denom;

    if (num_ways == 0)
        return;

    get_each_denom(denom, units);

    double ways_found = ceil(denom.size() / 2.0);

    if (num_ways > ways_found) {
        cout << "Found an input error while calc denom for: " << units << endl;
        cout << "Expected to find " << num_ways << " ways to break down change." << endl;
        cout << "We found " << ways_found << " ways: ";
        for (int i = 0; i < denom.size(); i++) {
            cout << denom[i] << " ";
        }
        cout << endl;
        input_error = true;
    }

    if (ways_found > num_ways) {
        insert_unique(coins, denom[0]);
    } else {
        for (int i = 0; i < denom.size(); i++) {
            insert_unique(coins, denom[i]);
        }
    }
}

int main() {
    int arr[N] = {1, 0, 0, 2, 1};

    vector<int> coins;

    for (int i = 1; i < N; i++) {
        find_denom(coins, i, arr[i]);
        if (input_error)
            return 0;
    }

    cout << "Coins that must be used: ";
    for (int i = 0; i < coins.size(); i++) {
        cout << coins[i] << " ";
    }
    cout << endl;

    return 0;
}