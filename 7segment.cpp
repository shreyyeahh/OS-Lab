#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to parse a 3x3 matrix into a string representation
string parse_digit(const vector<string>& matrix, int start_col) {
    string digit = "";
    for (int i = 0; i < 3; ++i) {
        digit += matrix[i].substr(start_col, 3);
    }
    return digit;
}

// Function to find candidates by toggling at most one LED
vector<int> find_candidates(const string& input_digit, const vector<string>& digits) {
    vector<int> candidates;
    for (int idx = 0; idx < digits.size(); ++idx) {
        int mismatch_count = 0;
        for (int i = 0; i < 9; ++i) {
            if (input_digit[i] != digits[idx][i]) {
                mismatch_count++;
            }
            if (mismatch_count > 1) break;
        }
        if (mismatch_count <= 1) {
            candidates.push_back(idx);
        }
    }
    return candidates;
}

// Recursive function to generate all possible numbers and calculate the sum
void generate_numbers(const vector<vector<int>>& all_candidates, int pos, long long current_number, long long& total_sum) {
    if (pos == all_candidates.size()) {
        total_sum += current_number;
        return;
    }
    for (int candidate : all_candidates[pos]) {
        generate_numbers(all_candidates, pos + 1, current_number * 10 + candidate, total_sum);
    }
}

int main() {
    vector<string> digits_matrix(3);
    vector<string> input_number_matrix(3);

    // Input for the digits from 0 to 9
    for (int i = 0; i < 3; ++i) {
        cin >> digits_matrix[i];
    }

    // Input for the provided number
    for (int i = 0; i < 3; ++i) {
        cin >> input_number_matrix[i];
    }

    // Parse the 3x3 matrices for digits 0-9
    vector<string> digits;
    for (int i = 0; i < 30; i += 3) {
        digits.push_back(parse_digit(digits_matrix, i));
    }

    // Parse the 3x3 matrices for the input number
    vector<string> input_digits;
    int num_digits = input_number_matrix[0].size() / 3;
    for (int i = 0; i < num_digits; ++i) {
        input_digits.push_back(parse_digit(input_number_matrix, i * 3));
    }

    // Validate and find candidates for each digit
    vector<vector<int>> all_candidates;
    for (const string& digit : input_digits) {
        vector<int> candidates = find_candidates(digit, digits);
        if (candidates.empty()) {
            cout << "Invalid" << endl;
            return 0;
        }
        all_candidates.push_back(candidates);
    }

    // Calculate the sum of all possible numbers
    long long total_sum = 0;
    generate_numbers(all_candidates, 0, 0, total_sum);

    // Output the result
    cout << total_sum << endl;
    return 0;
}

