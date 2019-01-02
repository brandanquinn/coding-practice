/*
INCOMPLETE
*/

// Write a program which, given an integer n as input, will produce a mathematical expression whose solution is n. 
// The solution is restricted to using exactly four 4’s and exactly three of the binary operations selected from the set {∗,+,−,/}. 
// The number 4 is the ONLY number you can use. You are not allowed to concatenate fours to generate other numbers, such as 44 or 444.

// For example given n=0, a solution is 4∗4−4∗4=0. Given n=7, a solution is 4+4−4 / 4=7. 
// Division is considered truncating integer division, so that 1/4 is 0 (instead of 0.25). 
// Assume the usual precedence of operations so that 4+4∗4=20, not 32. 
// Not all integer inputs have solutions using four 4’s with the aforementioned restrictions (consider n=11).

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void print_equation(vector<char> operators, int total) {
    cout << 4 << " ";

    for (int i = 0; i < 3; i++) {
        cout << operators[i] << " 4 ";
    }
    cout << "= " << total << endl;
}

int find_op1(char equation[7], int idx_of_op) {
    cout << "array when finding op1: ";
    for (int i = 0; i < 7; i++) {
        cout << equation[i] << " ";
    }
    cout << endl;
    for (int i = idx_of_op-1; i >= 0; i--) {
        if (equation[i] != '_') {
            int op1 = equation[i] - '0';
            return op1;
        }
    }
}

int find_op2(char equation[7], int idx_of_op) {
    cout << "array when finding op2: ";
    for (int i = 0; i < 7; i++) {
        cout << equation[i] << " ";
    }
    cout << endl;
    for (int i = idx_of_op+1; i < 7; i++) {
        if (equation[i] != '_') {
            int op2 = equation[i] - '0';
            return op2;
        }
    }
}

int get_subtotal(char equation[7], int idx_of_op) {
    int op1 = find_op1(equation, idx_of_op);
    int op2 = find_op2(equation, idx_of_op);

    cout << "Evaluating: " << op1 << equation[idx_of_op] << op2 << endl;

    if (equation[idx_of_op] == '*')
        return op1 * op2;
    else if (equation[idx_of_op] == '/')
        return op1 / op2;
    else if (equation[idx_of_op] == '+')
        return op1 + op2;
    else if (equation[idx_of_op] == '-')
        return op1 - op2;
}

int eval_equation(char equation[7]) {
    char test_arr[7];
    int length = 7;
    // Need to evaluate order of operations correctly.
    // for (int i = 1; i < 7; i+=2) {
    //     if (equation[i] == '+')
    //         total += 4;
    //     else if (equation[i] == '-')
    //         total -= 4;
    //     else if (equation[i] == '*')
    //         total *= 4;
    //     else if (equation[i] == '/')
    //         total /= 4;
    // }
    cout << "Equation being evaluated: ";
    for (int i = 0; i < 7; i++) {
        test_arr[i] = equation[i];
        cout << equation[i] << " ";
    }
    cout << endl;

    // 4 + 4 - 4 * 4 = 16
    // idx: 5 (*)
    // op1: 4
    // op2: 4
    // subtotal = 16
    // arr: 4 + 4 - 16 _ _
    // idx: 1 (+)
    // op1: 4
    // op2: 4
    // subtotal = 8
    // arr: 8 _ _ - 16 _ _
    // idx: 3 (-)
    // op1: 8
    // op2: 16
    // subtotal = -8
    // arr: _ _ -8 _ _ _ _

    

    int subtotal = 0;

    // char c = '5';
    // int x = c - '0';

    while (length > 1) {
        for (int i = 1; i < 7; i+=2) {
            if (test_arr[i] == '*') {
                subtotal = get_subtotal(test_arr, i);
                cout << "Subtotal calculated for *: " << subtotal << endl;
                char sub_to_char = subtotal;
                cout << "Subtotal casted to char: " << sub_to_char <<
                test_arr[i-1] = sub_to_char;
                test_arr[i] = '_';
                test_arr[i+1] = '_';
                length -= 2;
            } else if (test_arr[i] == '/') {
                subtotal = get_subtotal(test_arr, i);
                cout << "Subtotal calculated for /: " << subtotal << endl;
                char sub_to_char = subtotal;
                test_arr[i-1] = sub_to_char;
                test_arr[i] = '_';
                test_arr[i+1] = '_';
                length -= 2;
            }
        }
        for (int i = 1; i < 7; i+=2) {
            if (test_arr[i] == '+') {
                subtotal = get_subtotal(test_arr, i);
                cout << "Subtotal calculated for +: " << subtotal << endl;
                char sub_to_char = subtotal;
                test_arr[i-1] = sub_to_char;
                test_arr[i] = '_';
                test_arr[i+1] = '_';
                length -= 2;
            } else if (test_arr[i] == '-') {
                subtotal = get_subtotal(test_arr, i);
                cout << "Subtotal calculated for -: " << subtotal << endl;
                char sub_to_char = subtotal;
                test_arr[i-1] = sub_to_char;
                test_arr[i] = '_';
                test_arr[i+1] = '_';
                length -= 2;
            }
        }
    }
    cout << "Array after evaluation: ";
    for (int i = 0; i < 7; i++) {
        cout << test_arr[i] << " ";
    }
    cout << endl;

    cout << "Equation eval: " << test_arr[0] << endl;
    return test_arr[0];
}

void generate_equation(int total) {
    int four_thought = 4;
    char equation[7] = {'4', '_', '4', '_', '4', '_', '4'};
    char base_operators[4] = {'+', '-', '*', '/'};
    vector<vector<char> > operators;

    
    // operands filled in at indices: 1, 3, 5

    // Can only use 4 4s
    // Brute force it
    do {
        vector<char> temp;
        temp.push_back(base_operators[0]);
        temp.push_back(base_operators[1]);
        temp.push_back(base_operators[2]);
        temp.push_back(base_operators[3]);
        operators.push_back(temp);
    } while (next_permutation(base_operators, base_operators+4));

    for (int i = 0; i < operators.size(); i++) {
        for (int j = 0; j < 3; j++) {
            equation[j*2+1] = operators[i][j];
        }
        four_thought = eval_equation(equation);
        
        if (four_thought == total) {
            print_equation(operators[i], total);
            return;
        }
    }

    cout << "no solution" << endl;
}

int main() {
    int num_tests;

    cin >> num_tests;

    int arr[num_tests];
    for (int i = 0; i < num_tests; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < num_tests; i++) {
        generate_equation(arr[i]);
    }

    return 0;
}