#include "StringCounter.h"
#include <iostream>
#include <iomanip>

using namespace std;

StringCounter::StringCounter(){
    totalLetterCount = 0;
    allWords = {};
    for(int i = 0; i < 26; i++){
        letterCounts.push_back(0);
    }
}

void StringCounter::readAllWords(istream& myInput, string punctuation){
    string nextWord;
    string a = punctuation;
    while(myInput >> nextWord){
        for(size_t i = 0; i < nextWord.size(); i++){
            /*
            for(char j: punctuation){
                if(nextWord.at(i) == j){
                    nextWord.erase(i, 1);
                    i--;
                    break;
                }
            }
            */
            if(!((nextWord.at(i) >= 'a' && nextWord.at(i) <= 'z') || (nextWord.at(i) >= 'A' && nextWord.at(i) <= 'Z'))){
                nextWord.erase(i, 1);
                i--;
                continue;
            }
            if(nextWord.at(i) >= 'a' && nextWord.at(i) <= 'z') nextWord.at(i) = (char)(nextWord.at(i) - 32);
            letterCounts.at(nextWord.at(i) - 'A')++;
        }
        allWords.push_back(nextWord);
    }
}

void StringCounter::printLetterCounts(ostream& myOutput){
    unsigned int maxNumberWidth = 0;
    for(size_t i = 0; i < 26; i++){
        if(to_string(letterCounts.at(i)).size() > maxNumberWidth){
            maxNumberWidth = to_string(letterCounts.at(i)).size();
        }
    }
    for(int i = 'A'; i <= 'Z'; i++){
        myOutput << left << setw(2) << (char)i << ":" << right << setw(maxNumberWidth+1) << letterCounts.at(i - 'A') << endl;
    }
}

void StringCounter::printLetterStats(ostream& myOutput){
    unsigned int maxValue = 0, minValue = 99999;
    int maxIndex = -1, minIndex = -1;
    int sumOfValues = 0;
    int index = 0;
    for(unsigned int i: letterCounts){
        if(i > maxValue){
            maxValue = i;
            maxIndex = index;
        }
        if(i < minValue){
            minValue = i;
            minIndex = index;
        }

        sumOfValues += i;
        index++;
    }
    myOutput << " Most frequent letter: " << (char)(maxIndex + 'A') << " " << maxValue << " (" << setprecision(3) << (double)maxValue / sumOfValues * 100 << "%)" << endl;
    myOutput << "Least frequent letter: " << (char)(minIndex + 'A') << " " << minValue << " (" << setprecision(3) << (double)minValue / sumOfValues * 100 << "%)" << endl;
}

vector<string> StringCounter::getAllWords(){
    return allWords;
}