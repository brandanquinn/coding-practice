// Problem found at: https://open.kattis.com/problems/aboveaverage

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

void parse_input(string input, vector<double> &averages) {
    istringstream parser(input);
    vector<int> grades;

    int iter = 0, num_students, grade;
    while (!parser.eof()) {
        if (iter == 0)
            parser >> num_students;
        else {
            parser >> grade;
            grades.push_back(grade);
        }
        iter++;
    }

    // cout << "Computing average" << endl;
    int sum = 0;
    // Have vec of grades - need to compute average
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    int average = sum / num_students;

    int num_above_average = 0;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > average) {
            num_above_average++;
        }
    }

    double percent_above_average = ((double)num_above_average / (double)num_students) * 100.0;
    averages.push_back(percent_above_average);
}

int main() {
    int num_inputs = 0;

    while (num_inputs <= 0) {
        // cout << "How many inputs will we receive?" << endl;
        cin >> num_inputs;
    }
    cin.clear();

    vector<double> averages;

    string line;
    for (int i = 0; i < num_inputs; i++) {
        // cout << "Enter grades: ";
        getline(cin >> ws, line, '\n');
        parse_input(line, averages);
    }

    for (int i = 0; i < averages.size(); i++) {
        cout.setf(ios::fixed, ios::floatfield);
        cout << setprecision(3) << averages[i] << "%" << endl;
    }

    return 0;
}