// Problem found at: https://open.kattis.com/problems/classy

#include <iostream>
#include <vector>

using namespace std;

// upper - +2 score
// middle - +1 score
// lower - +0 score

// input is in format: person: upper-upper-lower class
// currently misses first class
void parse_input(string input, vector<pair<string, string> > &vec) {
    pair<string, string> person;

    string score = "";
    string name = "";
    bool is_calculating = false, mid_class = false;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ':')
            is_calculating = true;

        if (!is_calculating) {
            // getting persons name
            name += input[i];
        }

        if (is_calculating && !mid_class) {
            // assess persons class value
            if (input[i] == 'u') {
                score+='0';
                mid_class = true;
            } else if (input[i] == 'l') {
                score+='2';
                mid_class = true;
            } else if (input[i] == 'm') {
                score+='1';
                mid_class = true;
            }
        }
        if (is_calculating && mid_class) {
            // if score has already been increased and waiting to find next class label
            if (input[i] == '-') {
                mid_class = false;
            }
        }
    }
    person.first = name;
    person.second = score;
    vec.push_back(person);
}

// Sort based on persons class score, if they have same score - precedence is given to person with earlier name alphabetically
void sort_vec(vector<pair<string, string> > &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[i].second > vec[j].second)
                swap(vec[i], vec[j]);
            else if (vec[i].second == vec[j].second) {
                if (vec[i].first > vec[j].first)
                    swap(vec[i], vec[j]);
            }
        }
    }
}

int main() {
    int num_cases = 0, num_people = 0;

    cin >> num_cases;

    cin.clear();

    vector<vector<pair<string, string> > > container;

    string line;
    for (int i = 0; i < num_cases; i++) {
        cin >> num_people;
        cin.clear();
        vector<pair<string, string> > case_holder;
        for (int j = 0; j < num_people; j++) {
            getline(cin >> ws, line, '\n');
            parse_input(line, case_holder);
        }
        sort_vec(case_holder);
        container.push_back(case_holder);
    }

    for (int i = 0; i < container.size(); i++) {
        for (int j = 0; j < container[i].size(); j++) {
            cout << container[i][j].first << endl;
        }
        cout << "==============================" << endl;
    }
}