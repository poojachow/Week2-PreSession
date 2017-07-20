//
//  main.cpp
//  Week2PreSession
//
//  Created by Pooja Chowdhary on 7/19/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string A) {
    
    unordered_map<char, int> repeat;
    int count = 0;
    int value = 0;
    if (A.length() == 1) {
        return 1;
    }
    unordered_map<char, int>::const_iterator finder;
    
    for(string::iterator it = A.begin(); it != A.end(); it++) {
        finder = repeat.find(*it);
        if(finder == repeat.end()) {
            value += 1;
            repeat[*it] = value;
        }
        else {
            int tempCount = 0;
            int compareVal = finder->second;
            
            for (auto itt = repeat.begin(); itt != repeat.end();) {
                if(itt->second <= compareVal) {
                    
                    repeat.erase(itt++);
                }
                else {
                    ++itt;
                }
                tempCount = tempCount + 1;
            }
            
            value += 1;
            repeat[*it] = value;
            
            count = tempCount > count ? tempCount : count;
        }
    }
    int tempCount = 0;
    for (auto itt = repeat.begin(); itt != repeat.end(); ++itt) {
        tempCount = tempCount + 1;
    }
    count = tempCount > count ? tempCount : count;
    return count;
}




int main(int argc, const char * argv[]) {
    
    cout << lengthOfLongestSubstring("dadbc") << endl;
    return 0;
}
