#include "StringFilter.h"
#include <iostream>
#include <iomanip>

using namespace std;

StringFilter::StringFilter(){
    uniqueWords = {};
    wordCounts = {};
    totalWordCount = 0;
}

void StringFilter::addWords(vector<string> listOfWords){
    
    for(string i: listOfWords){
        bool newWord = true;
        int jIndex = 0;
        for(string j: uniqueWords){
            if(i == j){
                newWord = false;
                wordCounts.at(jIndex)++;
                break;
            }
            jIndex++;
        }
        if(newWord){
            uniqueWords.push_back(i);
            wordCounts.push_back(1);
        }
    }
}

void StringFilter::printUniqueWordCounts(ostream& myOutput){
    unsigned int maxWordWidth = 0, maxNumberWidth = 0;
    for(size_t i = 0; i < uniqueWords.size(); i++){
        if(uniqueWords.at(i).size() > maxWordWidth){
            maxWordWidth = uniqueWords.at(i).size();
        }
        if(to_string(wordCounts.at(i)).size() > maxNumberWidth){
            maxNumberWidth = to_string(wordCounts.at(i)).size();
        }
    }
    for(size_t i = 0; i < uniqueWords.size(); i++){
        myOutput << left << setw(maxWordWidth+1) << uniqueWords.at(i) << ":" << right << setw(maxNumberWidth+1) << wordCounts.at(i) << endl;
    }
}

void StringFilter::printUniqueWordStats(ostream& myOutput){
    unsigned int maxValue = 0, minValue = 99999;
    int maxIndex = -1, minIndex = -1;
    int sumOfValues = 0;
    int index = 0;
    for(unsigned int i: wordCounts){
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
    myOutput << " Most frequent word: " << uniqueWords.at(maxIndex) << "\t" << maxValue << " (" << setprecision(3) << (double)maxValue / sumOfValues * 100 << "%)" << endl;
    myOutput << "Least frequent word: " << uniqueWords.at(minIndex) << "\t" << minValue << " (" << setprecision(3) << (double)minValue / sumOfValues * 100 << "%)" << endl;
}

vector<string> StringFilter::getUniqueWords(){
    vector<string> sortedWords = {};
    vector<unsigned int> sortedWordCounts = {};
    while(uniqueWords.size() > 0){
        string leastWord = "z";
        unsigned int leastWordCount;
        int leastIndex = -1, currentIndex = 0;
        for(string i: uniqueWords){
            if(i < leastWord){
                leastWord = uniqueWords.at(currentIndex);
                leastWordCount = wordCounts.at(currentIndex);
                leastIndex = currentIndex;
            }

            currentIndex++;
        }
        uniqueWords.erase(uniqueWords.begin()+leastIndex);
        wordCounts.erase(wordCounts.begin()+leastIndex);
        sortedWords.push_back(leastWord);
        sortedWordCounts.push_back(leastWordCount);
    }
    uniqueWords = sortedWords;
    wordCounts = sortedWordCounts;
    return uniqueWords;
}