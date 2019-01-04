// Problem found at: https://open.kattis.com/problems/akcija

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_price_of_group(int b1, int b2, int b3) {
    int sum = 0;
    if (b1 > b2)
        sum += b1;
    else
        sum += b2;

    if (b1 > b3)
        sum += b1;
    else
        sum += b3;

    if (b2 > b3)
        sum += b2;
    else
        sum += b3;

    return sum;
}

void group_books(int *arr, int size) {
    // for (int i = 0; i < size; i++) {

    // }
    cout << "Permutations: " << endl;
    vector<int> price_of_books;
    do {
        // cout << arr[0] << arr[1] << arr[2] << endl;
        price_of_books.push_back(get_price_of_group(arr[0], arr[1], arr[2]));
    } while(next_permutation(arr, arr+size));

    for (int i = 0; i < price_of_books.size(); i++) {
        
    }
}

int main() {
    int num_inputs;

    cin >> num_inputs;

    int arr[num_inputs];

    for (int i = 0; i < num_inputs; i++) {
        cin >> arr[i];
    }

    cout << "Books entered: ";
    for (int i = 0; i < num_inputs; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    group_books(arr, num_inputs);

    return 0;
}