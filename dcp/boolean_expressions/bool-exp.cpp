// This problem was asked by Quantcast.

// You are presented with an array representing a Boolean expression. The elements are of two kinds:

// T and F, representing the values True and False.
// &, |, and ^, representing the bitwise operators for AND, OR, and XOR.
// Determine the number of ways to group the array elements using parentheses so that the entire expression evaluates to True.

// For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case, there are two acceptable groupings: (F | T) & T and F | (T & T).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define TRUE 'T'
#define FALSE 'F' 
#define AND '&'
#define OR '|'
#define XOR '^'
#define SIZE 9

// Evaluate chars using logical operations and return corresponding char based on result.
char eval_args(char op1, char oper, char op2) {
    if (oper == AND) {
        if (op1 && op1 == op2)
            return TRUE;
        else
            return FALSE;
    } else if (oper == OR) {
        if (op1 == FALSE && op2 == FALSE)
            return FALSE;
        else    
            return TRUE;    
    } else {
        if (op1 == op2)
            return FALSE;
        else
            return TRUE;
    }

    return FALSE;
}

// Given a vector that contains the indices of valid boolean sequences, find the longest sequence and return it.
vector<int> find_longest_sequence(vector<int> valid_indices) {
    vector<int> temp, longest_sequence;
    int max_size = 0;

    for (int i = 0; i < valid_indices.size(); i++) {
        if (valid_indices[i] != -1) {
            temp.push_back(valid_indices[i]);
        } else {
            if (temp.size() > max_size) {
                longest_sequence = temp;
                max_size = temp.size();
                temp.clear();
            }
        }
    }

    if (longest_sequence.empty()) return valid_indices;

    return longest_sequence;
}

int main() {
    char arr[SIZE] = {'T', '&', 'T', '&', 'F', '|', 'T', '&', 'T'};
    // Evaluate first three terms of array before looping.
    char prev_eval = eval_args(arr[0], arr[1], arr[2]);
    char curr_eval;
    // Vector containing indices of the sequences that are true, a value of -1 indicates the termination of a complete sequence
    vector<int> valid_indices;

    // If the first statement is evaluated as true: add indices of sequence to vector.
    if (prev_eval == TRUE) {
        valid_indices.push_back(0);
        valid_indices.push_back(1);
        valid_indices.push_back(2);
    }

    for (int i = 3; i < SIZE; i+=2) {
        if (prev_eval == FALSE) {
            // Evaluate next valid sequence
            curr_eval = eval_args(arr[i-1], arr[i], arr[i+1]);
            // If the current evaluation is true, add previous index used to vector.
            if (curr_eval == TRUE) valid_indices.push_back(i-1);
        } else {
            curr_eval = eval_args(prev_eval, arr[i], arr[i+1]);
            if (curr_eval == TRUE) valid_indices.push_back(i-1);
        }
        if (curr_eval == FALSE) {
            // If vector contains sequences, terminate the current sequence by adding -1.
            if (!valid_indices.empty()) valid_indices.push_back(-1);
            curr_eval = prev_eval;
        } else {
            valid_indices.push_back(i);
            valid_indices.push_back(i+1);
        }
        
        prev_eval = curr_eval;
    }

    valid_indices.push_back(-1);

    // remove any duplicates
    vector<int>::iterator it;
    it = unique(valid_indices.begin(), valid_indices.end());
    valid_indices.resize(distance(valid_indices.begin(), it));

    if (curr_eval == FALSE) {
        cout << "No true sequence found." << endl;
    } else {
        vector<int> longest_seq = find_longest_sequence(valid_indices);
        cout << "Longest true sequence found: ";
        for (int i = 0; i < longest_seq.size(); i++) {
            cout << arr[longest_seq[i]] << " ";
        }
        cout << endl;
    }
}