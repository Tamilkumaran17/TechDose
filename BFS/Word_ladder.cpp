#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) 
            return 0; 

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) 
                return steps;

          
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) 
                        continue;

                    word[i] = c;

                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word); 
                    }
                }

                word[i] = originalChar; 
            }
        }

        return 0; 
    }
};

int main() {
    string beginWord, endWord;
    int n;

    cout << "Enter beginWord: ";
    cin >> beginWord;

    cout << "Enter endWord: ";
    cin >> endWord;

    cout << "Enter number of words in wordList: ";
    cin >> n;

    vector<string> wordList(n);
    cout << "Enter words in wordList:\n";
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    Solution sol;
    int result = sol.ladderLength(beginWord, endWord, wordList);

    if (result == 0)
        cout << "No transformation sequence possible.\n";
    else
        cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
