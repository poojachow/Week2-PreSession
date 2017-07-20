//
//  Diffk.cpp
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

int diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_multimap<int, int> diffk;
    for(int i = 0; i < A.size(); i++) {
        pair<int, int> myPair (A[i], i);
        diffk.insert(myPair);
    }
    unordered_multimap<int, int>::const_iterator finder;
    
    for(auto it = diffk.begin(); it != diffk.end(); ++it) {
        int temp = it->first - B;
        finder = diffk.find(temp);
        
        if(finder != diffk.end()) {
            if (finder->second != it->second) {
                return 1;
            }
        }
    }
    return 0;
}
