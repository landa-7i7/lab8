#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

struct WordCount {
    string word;
    int maxCount;
};

int maxSameLettersCount(const string& word) {
    unordered_map<char, int> letterCount;
    for (char ch : word) {
        letterCount[ch]++;
    }

    int maxCount = 0;
    for (const auto& i : letterCount) {
        maxCount = max(maxCount, i.second);
    }

    return maxCount;
}

vector<WordCount> Bogo(const vector<WordCount>& a, const vector<WordCount>& b){
    vector<WordCount> Bogoa;
    int index1 = 0, index2 = 0;

    while (index1 < a.size() && index2 < b.size()){
        if(a[index1].maxCount > b[index2].maxCount){
            Bogoa.push_back(a[index1]);
            ++index1;
        } else {
            Bogoa.push_back(b[index2]);
            ++index2;
        }
    }

    while (index1 < a.size()) {
        Bogoa.push_back(a[index1]);
        ++index1;
    }

    while (index2 < b.size()) {
        Bogoa.push_back(b[index2]);
        ++index2;
    }

    return Bogoa;
}


vector<WordCount> BogoSort(const vector<WordCount>& a){
    if (a.size() <= 1) return a;
    int mid = a.size() / 2;

    vector<WordCount> l = BogoSort(vector<WordCount>(a.begin(), a.begin() + mid));
    vector<WordCount> r = BogoSort(vector<WordCount>(a.begin() + mid, a.end()));

    return Bogo(l,r);
}

//lab 8.2
bool is_palindrome(const string &word) {
    int n = word.length();
    for (int i = 0; i < n / 2; ++i) {
        if (tolower(word[i]) != tolower(word[n - i - 1])) {
            return false;
        }
    }
    return n > 1;
}

int count_consonants(const string &word) {
    int count = 0;
    for (char ch : word) {
        if (isalpha(ch) && !strchr("aeiouAEIOU", ch)) {
            count++;
        }
    }
    return count;
}

string duplicate_vowels(const string &word) {
    string result;
    for (char ch : word) {
        result += ch;
        if (strchr("aeiouAEIOU", ch)) {
            result += ch;
        }
    }
    return result;
}


int main(){
    ifstream FileA("File.txt");
    
    // lab 8.1
    // vector<WordCount> words;

    // string word;
    // while (FileA >> word) {
    //     int count = maxSameLettersCount(word);
    //     if (count > 1) {
    //         words.push_back({ word, count });
    //     }
    // }
    // FileA.close();

    // auto result = BogoSort(words);

    // ofstream outputFile("resultFile.txt");

    // for ( auto word : result ) {
    //     outputFile << word.word << ':' << word.maxCount << endl;
    //     cout << word.word << ':' << word.maxCount << ' ';
    // }
    // outputFile.close();


    // lab 8.2
    // vector<string> words;
    // string word;
    // while(FileA >> word) words.push_back(word);

    // bool palindromeflag = false;
    // for (const string &w : words) {
    //     if (is_palindrome(w)) {
    //         palindromeflag = true;
    //         break;
    //     }
    // }

    // if (!palindromeflag) {
    //     sort(words.begin(), words.end(), [](const string &a, const string &b) {
    //         return count_consonants(a) > count_consonants(b);
    //     });
    // } else {
    //     for (string &w : words) {
    //         w = duplicate_vowels(w);
    //     }
    //     sort(words.rbegin(), words.rend());
    // }

    // ofstream outputFile("resultFile.txt");

    // for ( auto word : words ) {
    //     outputFile << word << ':' << word << endl;
    //     cout << word << ' ';
    // }
    // outputFile.close();

    // lab 8.3
    vector<string> words;
    unordered_map<char, int> letterCount;
    string w;
    while(FileA >> w) {
        for(char ch: w) letterCount[ch]++;
    }
    for(auto a : letterCount) cout << a.first << ' ';




    return 0;
}