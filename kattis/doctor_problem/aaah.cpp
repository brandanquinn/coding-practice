// Problem from: https://open.kattis.com/problems/aaah

#include <iostream>

#include <string>

using namespace std;

void assess_input(string jons_req, string docs_req) {
    if (jons_req.length() >= docs_req.length())
        cout << "go" << endl;
    else
        cout << "no" << endl;
}

int main() {
    string jons_req, docs_req;

    // cout << "Enter jon's req, followed by doc's req: ";
    cin >> jons_req >> docs_req;

    assess_input(jons_req, docs_req);
}