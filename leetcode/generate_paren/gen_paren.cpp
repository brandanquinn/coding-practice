// Problem found at: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> paren_vec;
        char paren[n*2];
        // vector<char> paren;
        
        for (int i = 0; i < n*2; i++) {
            if (i % 2 == 0)
                paren[i] = '(';
            else
                paren[i] = ')';
        }
        
        do {
            string str = "";
            for (int i = 0; i < n*2; i++) {
                // cout << paren[i];
                str += paren[i];
            }
            // cout << endl;
            // cout << str << endl;
            add_valid_order(paren_vec, str);
            flip_str(str);
            add_valid_order(paren_vec, str);
            
        } while(next_permutation(paren, paren + (n*2)));
        
        vector<string>::iterator ip;
        ip = unique(paren_vec.begin(), paren_vec.end());
        paren_vec.resize(distance(paren_vec.begin(), ip));
        
        return paren_vec;
    }
    
    void add_valid_order(vector<string> &paren_vec, string paren_str) {
        stack<char> open_paren;
        
        for (int i = 0; i < paren_str.size(); i++) {
            if (paren_str[i] == '(')
                open_paren.push(paren_str[i]);
            else {
                if (open_paren.empty())
                    return;
                else
                    open_paren.pop();
            }
        }
        
        if (open_paren.empty())
            paren_vec.push_back(paren_str);
    }
    
    void flip_str(string &paren_str) {
        for (int i = 0; i < paren_str.size(); i++) {
            if (paren_str[i] == '(')
                paren_str[i] = ')';
            else
                paren_str[i] = '(';
        }
    }
};