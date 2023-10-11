#ifndef STRING_FILTER_H
#define STRING_FILTER_H

#include <string>
#include <vector>

class StringFilter{
    private:
        std::vector<std::string> uniqueWords;
        std::vector<unsigned int> wordCounts;
        unsigned int totalWordCount;
    public:
        StringFilter();
        void addWords(std::vector<std::string>);
        void printUniqueWordCounts(std::ostream&);
        void printUniqueWordStats(std::ostream&);
        std::vector<std::string> getUniqueWords();
};

#endif