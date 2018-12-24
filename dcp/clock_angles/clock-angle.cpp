// Given a clock time in hh:mm format, determine, to the nearest degree, the angle between the hour and the minute hands.
// Bonus: When, during the course of a day, will the angle be zero?

#include <string.h>

#include <iostream>
#include <unordered_map>

using namespace std;


// Each hour represents a 360/12 slice (30 degree angles)
// Example: 12:30 (12, 6) = 180 degrees
int get_clock_angle(int hour_num, int minute_num) {
    if (hour_num > minute_num) {
        return (hour_num - minute_num) * 30;
    } else {
        return (minute_num - hour_num) * 30;
    }

    return 0;
}

// If minutes % 10 == 0 || minutes % 5 == 0 -> return as is
// Else if minutes % 10 > 5; add 10-minutes % 10 to minutes
// Else subtract minutes%10 from minutes
string convert_minutes(int minutes_as_int) {
    int old_minutes = minutes_as_int;

    if (minutes_as_int % 10 == 0 || minutes_as_int % 5 == 0) {
        // No changes to minutes
    } else if (minutes_as_int % 10 > 5) {
        minutes_as_int += 10 - (minutes_as_int % 10);
    } else {
        minutes_as_int -= minutes_as_int % 10;
    }

    return to_string(minutes_as_int);
}

unordered_map<string, int> get_map() {
    // Map to convert number of minutes to its corresponding hour number on the clock face.
    return {
        {"00", 12},
        {"05", 1},
        {"10", 2},
        {"15", 3},
        {"20", 4},
        {"25", 5},
        {"30", 6},
        {"35", 7},
        {"40", 8},
        {"45", 9},
        {"50", 10},
        {"55", 11}
    };
}


int main() {
    string time_str;
    cout << "Enter a valid time string (hh:mm): ";
    cin >> time_str;
    
    if (time_str.size() != 5) {
        cout << "Invalid time entered. Try again." << endl;
        return 0;
    }

    string hour;
    string minutes;

    unordered_map<string, int> minutes_map = get_map();

    // Split the time string into separate strings for parsing
    for (int i = 0; i < time_str.size(); i++) {
        if (i < 2) {
            hour += time_str[i];
        } else if (i > 2) {
            minutes += time_str[i];
        }
    }

    // Parse hour to int
    int hour_num = stoi(hour);
    int minutes_as_int = stoi(minutes);

    // Convert minutes to one of the options.
    int angle = get_clock_angle(hour_num, minutes_map[convert_minutes(minutes_as_int)]);

    cout << "Angle from given time string: " << angle << " degrees." << endl;
}