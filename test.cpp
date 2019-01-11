#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

unordered_map<string, int> generate_roman_pairs() {
        unordered_map<string, int> map({
                {"IV", 4},
                {"IX", 9},
                {"XL", 40},
                {"XC", 90},
                {"CD", 400},
                {"CM", 900}
        });

        return map;
}

unordered_map<char, int> generate_roman_singles() {
        unordered_map<char, int> map({
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        });

        return map;
}

int romanToInt(string s) {
        int sum = 0;
        unordered_map<string, int> roman_pairs = generate_roman_pairs();
        unordered_map<char, int> roman_singles = generate_roman_singles();

        int count = 0;
        while(count < s.size()) {
                ostringstream oss;
                oss << s[count] << s[count+1];
                string test_pair = oss.str();
                cout << "Test pair found:" << test_pair << endl;
                if (roman_pairs.count(test_pair) == 1) {
                        sum += roman_pairs[test_pair];
                        count+=2;
                } else {
                        sum += roman_singles[s[count]];
                        count++;
                }
                
        }

        return sum;
}

int main() {
       cout << romanToInt("IV") << endl; 
}

