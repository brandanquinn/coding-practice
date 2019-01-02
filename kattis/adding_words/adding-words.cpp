// Problem found: https://open.kattis.com/problems/addingwords

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void parse_line(string line, string &command, string &statement) {
    istringstream parser(line);
    string temp;

    while (!parser.eof()) {
        if (command.empty())
            parser >> command;
        else {
            parser >> temp;
            if (statement.empty()) {
                statement += temp;
            } else {
                statement += (" " + temp);
            }
        }
    }
}

void parse_statement(string statement, string &word, int &value) {
    istringstream parser(statement);
    for (int i = statement.size(); i >= 0; i--) {
        if (statement[i] == ' ') {
            statement.erase(statement.begin()+i);
        }
    }

    while (!parser.eof()) {
        if (word.empty()) {
            parser >> word;
        } else {
            parser >> value;
        }
    }
}

// Add definition to map of known words.
void add_definition(unordered_map<string, int> &definitions, string statement) {
    // Statement will be of form: word value
    string word;
    int value;

    unordered_map<string, int>::iterator it = definitions.begin();
    // cout << "Iterating through map: " << endl;
    while (it != definitions.end()) {
        if (it->second == value) {
            it = definitions.erase(it);
        }
        
        it++;
    }

    parse_statement(statement, word, value);

    definitions[word] = value;
}

void generate_equation(string statement, vector<string> &equation) {
    // cout << "Statement being parsed for equation: " << statement << endl;

    istringstream parser(statement);

    while (!parser.eof()) {
        string temp;
        parser >> temp;
        equation.push_back(temp);
    }
}

void make_calculation(unordered_map<string, int> definitions, string statement) {
    // Statement will end with term: '='

    vector<string> equation;
    string op1, op2;

    generate_equation(statement, equation);

    if (equation[equation.size()-1] != "=")
        return;

    int accum = 0;
    bool unknown_flag = false;

    if (equation.size() == 2) {
        // If input is of form: calc var =
        accum = definitions[equation[0]];
    } else {
        for (int i = 1; i < equation.size(); i+=2) {
            if (equation[i] == "+") {
                op1 = equation[i-1];
                op2 = equation[i+1];
                if (definitions.count(op1) == 0 || definitions.count(op2) == 0) {
                    unknown_flag = true;
                } else {
                    if (accum == 0) {
                        accum = definitions[op1] + definitions[op2];
                    } else {
                        accum += definitions[op2];
                    }
                }
            } else if (equation[i] == "-") {
                op1 = equation[i-1];
                op2 = equation[i+1];
                if (definitions.count(op1) == 0 || definitions.count(op2) == 0) {
                    // cout << op1 << " - " << op2 << " = unknown" << endl;
                    unknown_flag = true;  
                } else {
                    if (accum == 0) {
                        accum = definitions[op1] - definitions[op2];
                    } else {
                        accum -= definitions[op2];
                    }
                }
            }
        }
    }

    // cout << "size of equation: " << equation.size() << endl;
    for (int i = 0; i < equation.size(); i++) {
        cout << equation[i] << " ";
    }

    if (!unknown_flag) {
        unordered_map<string, int>::iterator it = definitions.begin();
        // cout << "Iterating through map: " << endl;
        while (it != definitions.end()) {
            if (it->second == accum) {
                cout << it->first << endl;
                return;
            }

            // cout << "Word: " << it->first << " Value: " << it->second << endl;
            
            it++;
        }
    }
    cout << "unknown" << endl;
}



int main() {
    string input, command, statement;
    unordered_map<string, int> definitions;
    vector<string> inputs;

    while (true) {
        getline(cin, input, '\n');
        if (input.empty()) {
            break;
        } else {
            inputs.push_back(input);
        }
        command.clear();
        statement.clear();

        if (inputs.size() >= 2000) {
            break;
        }
    }

    for (int i = 0; i < inputs.size(); i++) {
        parse_line(inputs[i], command, statement);
        // cout << "Command: " << command << " Statement: " << statement << endl;
        if (command == "def") {
            add_definition(definitions, statement);
        } else if (command == "calc") {
            make_calculation(definitions, statement);
        } else if (command == "clear") {
            definitions.clear();
        }

        command.clear();
        statement.clear();
    }

    return 0;
}