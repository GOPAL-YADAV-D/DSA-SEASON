#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool constructFromScrambled(const string &guest, const string &host, const string &scrambled) {
    string combined = guest + host;

    // Compairing the length of the Combined and the Scrambled string
    if (combined.length() != scrambled.length()) {
        return false;
    }

    // Sorting the two strings i.e the Combined String and the Scrambled String
    string sortedCombined = combined;
    string sortedScrambled = scrambled;
    sort(sortedCombined.begin(), sortedCombined.end());
    sort(sortedScrambled.begin(), sortedScrambled.end());

    // Checking and returning if the two Strings are equal or not
    return sortedCombined == sortedScrambled;
}

int main() {
    string guest;
    string host;
    string scramble;

    // Taking input of the Strings
    cout << "Enter guest name: ";
    cin >> guest;
    cout << "Enter host name: ";
    cin >> host;
    cout << "Enter scrambled letters: ";
    cin >> scramble;

    // Check if we can construct guest and host names from scrambled letters
    if (constructFromScrambled(guest, host, scramble)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
