// Problem from: https://open.kattis.com/problems/acm

#include <iostream>
#include <vector>

using namespace std;

struct log_entry {
        char question_id;
        int time;
        int penalties;
        bool is_correct;
};

void check_logs(vector<log_entry> logs) {
    int problems_solved = 0;
    int total_time = 0;

    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].is_correct) {
            problems_solved++;
            total_time += (logs[i].time + (logs[i].penalties * 20));
        }
        
        
    }

    cout << problems_solved << " " << total_time << endl;
}

void print_logs(vector<log_entry> logs) {
    cout << "Logs found: ";
    for (int i = 0; i < logs.size(); i++) {
        cout << logs[i].question_id << " " << logs[i].time << " " << logs[i].is_correct << endl;
    }
}

int main() {
    string input;
    int time_in;
    char id_in;
    string answer_in;
    bool log_found = false;

    vector<log_entry> logs;

    while (time_in != -1) {
        cin >> time_in >> id_in >> answer_in;
        if (time_in == -1) break;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i].question_id == id_in) {
                logs[i].time = time_in;
                if (answer_in == "right") {
                    logs[i].is_correct = true;
                } else {
                    logs[i].is_correct = false;
                    logs[i].penalties++;
                }
                log_found = true;
            }
        }
        if (!log_found) {
            log_entry log;
            log.penalties = 0;
            log.question_id = id_in;
            log.time = time_in;
            if (answer_in == "right") {
                log.is_correct = true;
            } else {
                log.is_correct = false;
                log.penalties++;
            }
            logs.push_back(log);
        }
        log_found = false;
    }

    // print_logs(logs);
    check_logs(logs);
}