// Problem found at: https://open.kattis.com/problems/different

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void parse_input(string input, long long int &num1, long long int &num2) {
    istringstream parser(input);

    bool num1_checked = false;
    while (!parser.eof()) {
        if (!num1_checked) {
            parser >> num1;
            num1_checked = true;
        }
        else
            parser >> num2;
    }
}

int main() {
    string input;
    vector<long long int> differences;
    long long int num1, num2;

    while (true) {
        getline(cin, input, '\n');
        if (input.empty()) break;
        parse_input(input, num1, num2);
        if (num1 > num2) {
            differences.push_back(num1-num2);
        } else {
            differences.push_back(num2-num1);
        }
    }

    for (int i = 0; i < differences.size(); i++) {
        cout << differences[i] << endl;
    }

    return 0;
}