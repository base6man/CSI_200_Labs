#include "string_functions.h"

#include <iostream>


unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    result += RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR.substr(0, IDX);
    result += TO_INSERT;
    result += STR.substr(IDX);

    return result;
}

size_t string_find(const string STR, const char C)  {
    size_t result = 0;
    result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    int IDX = STR.find(TEXT_TO_REPLACE);
    if(IDX < 0) return STR;

    string result = STR.substr(0, IDX);
    result += REPLACE_WITH;
    result += STR.substr(IDX + TEXT_TO_REPLACE.length());
    return result;
}

string string_first_word(const string STR)  {
    int index = STR.find(" ");
    if(index == -1) return STR;
    string result = STR.substr(0, index);
    return result;
}

string string_remove_first_word(const string STR)  {
    int index = STR.find(" ");
    if(index == -1) return "";
    string result = STR.substr(index);
    result = result.substr(1);
    return result;
}

string string_second_word(const string STR)  {
    string result = string_nth_word(STR, 2);
    // TODO 09: set result to be the second word from the string
    std::cout << "TODO: implement string_second_word(\"" << STR << "\")" << std::endl;
    return result;
}

string string_third_word(const string STR)  {
    string result = string_nth_word(STR, 3);
    // TODO 10: set result to be the third word from the string
    std::cout << "TODO: implement string_third_word(\"" << STR << "\")" << std::endl;
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    for(int i = 0; i < N-1; i++){
        int index = result.find(" ");
        if(index == -1) return "";
        result = result.substr(index + 1);
    }
    int index = result.find(" ");
    result = result.substr(0, index);
    return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    string strRemaining = STR;
    while(true){
        int index = strRemaining.find(DELIMINATOR);
        if(index == -1) {
            result.push_back(strRemaining);
            break;
        }
        result.push_back(strRemaining.substr(0, index));
        strRemaining = strRemaining.substr(index + 1);
    }
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = "";
    vector<string> tokenizedString = string_tokenize(STR, TARGET);
    bool isFirstLoop = true;
    for(string i: tokenizedString){
        if(isFirstLoop) isFirstLoop = false;
        else{
            result += REPLACEMENT;
        }
        result += i;
    }
    return result;
}

string string_to_lower(const string STR) {
    string result = "";
    for(char i: STR){
        if(i >= 65 && i <= 90) result += (char)(i + 32);
        else{
            result += i;
        }
    }
    // TODO 14: convert all characters to lower case
    std::cout << "TODO: implement string_to_lower(\"" << STR << "\")" << std::endl;
    return result;
}

string string_to_upper(const string STR) {
    string result = "";
    for(char i: STR){
        if(i >= 97 && i <= 122) result += (char)(i - 32);
        else{
            result += i;
        }
    }
    // TODO 15: convert all characters to upper case
    std::cout << "TODO: implement string_to_upper(\"" << STR << "\")" << std::endl;
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    if(LHS > RHS) result = 1;
    if(RHS > LHS) result = -1;
    // TODO 16: compare LHS and RHS
    std::cout << "TODO: implement string_compare(\"" << LHS << "\", \"" << RHS << "\")" << std::endl;
    return result;
}