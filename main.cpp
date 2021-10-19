/*
 * main.cpp
 *
 *  Created on: 19 Oct 2021
 *      Author: mndx
 *
 *      Solution to hackerrank longest palindrome
 *      substring problem:
 *      https://www.hackerrank.com/contests/security-challenge/challenges/largest-palindromic-substring/submissions/code/1337853598
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void lps(std::string& s) {

    int size_string = s.length();

    //Base cases
    if(size_string == 0) { cout << ""; return; }
    if(size_string == 1) { cout << s; return; }
    if(size_string == 2) {
        if(s[0] == s[1]) { cout << s; return; }
        else { cout << s.substr(0, 1); return; }
    }

    //Detect single character arrays
    char c = s[0];
    bool is_single_char_string = true;
    for(int i = 0; i < size_string; ++i) {
        if(s[i] != c) {
            is_single_char_string = false;
        }
    }

    if(is_single_char_string) { cout << s; return; }

    //Compute max palindrome
    int size_palindrome = 1;
    int left_index = 0;
    int right_index = 0;
    int index = 0;
    do {
        int left_track = index - 1;
        int right_track = index + 1;
        int size_palindrome_loc = 1;

        bool cond1 = left_track >= 0;
        bool cond2 = right_track < size_string;

        bool cond3 = false;
        if(cond1 && cond2) {
            cond3 = s[left_track] == s[right_track];
        }

        //Grow longest palindrome substring
        while(cond1 && cond2 && cond3) {
            size_palindrome_loc = size_palindrome_loc + 2;
            if(size_palindrome_loc > size_palindrome) {
                size_palindrome = size_palindrome_loc;
                left_index = left_track;
                right_index = right_track;
            }
            left_track--;
            right_track++;

            cond1 = left_track >= 0;
            cond2 = right_track < size_string;

            cond3 = false;
            if(cond1 && cond2) {
                cond3 = s[left_track] == s[right_track];
            }
        }

        left_track = index - 0;
        right_track = index + 1;
        size_palindrome_loc = 0;

        cond1 = left_track >= 0;
        cond2 = right_track < size_string;

        cond3 = false;
        if(cond1 && cond2) {
            cond3 = s[left_track] == s[right_track];
        }

        //Grow longest palindrome substring
        while(cond1 && cond2 && cond3) {
            size_palindrome_loc = size_palindrome_loc + 2;
            if(size_palindrome_loc > size_palindrome) {
                size_palindrome = size_palindrome_loc;
                left_index = left_track;
                right_index = right_track;
            }
            left_track--;
            right_track++;

            cond1 = left_track >= 0;
            cond2 = right_track < size_string;

            cond3 = false;
            if(cond1 && cond2) {
                cond3 = s[left_track] == s[right_track];
            }
        }

        //Advance seed index
        index++;

        //Break from loop if longest palindrome substring is already found
        int diff = size_string - index;
        bool cond = (size_palindrome / 2) > (diff + 10);
        if(cond) { index = size_string; }
    } while(index < size_string);

    cout << s.substr(left_index, right_index - left_index + 1);
}

int main() {
    //Get string input from STDIN
    string s;
    cin >> s;

    //Print largest palindrome to STDOUT
    lps(s);

    return 0;
}
