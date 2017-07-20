//
//  List Cyce.cpp
//  Week1ArraysStrings
//
//  Created by Pooja Chowdhary on 7/19/17.
//  Copyright © 2017 Pooja Chowdhary. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode *current = A;
    map<ListNode*, int> list;
    
    while (current !=nullptr) {
        
        if (list.find(current) != list.end()) {
            //found
            return current;
        }
        list[current] = current->val;
        current = current->next;
    }
    
    return nullptr;
}
