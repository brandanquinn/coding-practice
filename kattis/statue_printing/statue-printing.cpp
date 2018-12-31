// You have a single 3D printer, and would like to use it to produce n statues. 
// However, printing the statues one by one on the 3D printer takes a long time, 
// so it may be more time-efficient to first use the 3D printer to print a new printer. 
// That new printer may then in turn be used to print statues or even more printers. 
// Print jobs take a full day, and every day you can choose for each printer in your possession
// to have it print a statue, or to have it 3D print a new printer (which becomes available for use the next day).

// What is the minimum possible number of days needed to print at least n statues?

// 1 - 3, Print 1 statue per day
// 4+, if N is even, print printers until printers = n / 2
// if N is odd, until printers = n / 2 - 1

#include <iostream>

using namespace std;

int statues_requested;

// Decide whether or not a printer should print a statue or another printer each day
void print(int &num_printers, int &num_statues) {
    int x_p = num_printers, x_s = num_statues;
    
    if (num_printers < statues_requested / 2 && statues_requested > 3) {
        int half_printers = statues_requested / 2;
        int max_printers = num_printers;
        for (int i = 0; i < max_printers; i++) {
            if (i < half_printers) {
                num_printers++;
            } else {
                num_statues++;
            }
        }
    } else {
        for (int i = 0; i < num_printers; i++) {
            num_statues++;
        }
    }
}

int main() {
    cout << "Enter the number of statues that need to be printed: ";
    cin >> statues_requested;

    int num_printers = 1;
    int num_statues = 0;
    int days = 0;

    while (num_statues < statues_requested) {
        print(num_printers, num_statues);
        days++;
    }

    cout << "It will take: " << days << " days to print: " << statues_requested << " statues." << endl;
}

