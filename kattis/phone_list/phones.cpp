// Problem found at: https://open.kattis.com/problems/phonelist

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Print fun for testing purposes.
void print_cases(vector<vector<string> > vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << "phone numbers in case " << i << ": " << endl;
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << endl;
        }
    }
}

void assess_consistency(vector<string> phone_nums) {
    for (int i = 0; i < phone_nums.size(); i++) {
        for (int j = i+1; j < phone_nums.size(); j++) {
            if (phone_nums[i].size() < phone_nums[j].size()) {
                bool matching_prefix = true;
                int max_len;
                phone_nums[i].size() > 10 ? max_len = 10 : max_len = phone_nums[i].size();
                for (int k = 0; k < max_len; k++) {
                    if (phone_nums[i][k] != phone_nums[j][k]) {
                        matching_prefix = false;
                        break;
                    }
                }
                if (matching_prefix) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int num_cases;

    cin >> num_cases;
    cin.clear();

    vector<vector<string> > total_phone_nums;

    int max_cases;
    num_cases > 40 ? max_cases = 40 : max_cases = num_cases;

    for (int i = 0; i < max_cases; i++) {
        int num_phone_nums;
        cin >> num_phone_nums;
        vector<string> case_nums;
        int max_nums;
        num_phone_nums > 10000 ? max_nums = 10000 : max_nums = num_phone_nums;
        for (int j = 0; j < max_nums; j++) {
            string temp;
            cin >> temp;
            case_nums.push_back(temp);
        }
        total_phone_nums.push_back(case_nums);
    }

    for (int i = 0; i < total_phone_nums.size(); i++) {
        assess_consistency(total_phone_nums[i]);
    }

    
}