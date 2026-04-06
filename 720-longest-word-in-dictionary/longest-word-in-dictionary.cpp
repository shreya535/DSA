#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end()); // lexicographic sort
        
        unordered_set<string> built;
        string result = "";
        
        for (string word : words) {
            // check if word can be built
            if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
                built.insert(word);
                
                // update result
                if (word.size() > result.size()) {
                    result = word;
                }
            }
        }
        
        return result;
    }
};