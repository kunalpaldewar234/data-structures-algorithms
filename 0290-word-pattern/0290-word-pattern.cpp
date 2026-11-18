class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream input(s);
        string word;

        for (char ch : pattern) {
            if (!(input >> word)) {
                return false;
            }

            auto charMatch = charToWord.find(ch);
            if (charMatch != charToWord.end()) {
                if (charMatch->second != word) {
                    return false;
                }
            } else {
                if (wordToChar.count(word)) {
                    return false;
                }

                charToWord[ch] = word;
                wordToChar[word] = ch;
            }
        }

        return !(input >> word);
    }
};