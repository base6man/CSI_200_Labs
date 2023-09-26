#include <iostream>
#include <list>
#include <ctime>

using namespace std;

void enlightenTest(list<bool> clickPattern);
list<bool> convertToLightPattern(list<bool> clickPattern);
bool switchBool(bool thingToSwitch);

list<bool> solutionPattern = 
{
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

int main(){
    int startTime = time(0);
    
    list<bool> startList = {};
    enlightenTest(startList);

    int endTime = time(0);
    cout << endl << endTime - startTime << endl;

    return 0;
}

void enlightenTest(list<bool> clickPattern){
    if(clickPattern.size() == solutionPattern.size()){
        if(convertToLightPattern(clickPattern) == solutionPattern){
            
            int index = 0;
            for(bool i: clickPattern){
                cout << i << " ";
                index++;
                if(index % 5 == 0) cout << endl;
            }
            cout << endl;
            
        }
    }
    else{
        list<bool> firstCopy, secondCopy;
        firstCopy.assign(clickPattern.begin(), clickPattern.end());
        secondCopy.assign(clickPattern.begin(), clickPattern.end());
        firstCopy.push_back(0);
        secondCopy.push_back(1);
        enlightenTest(firstCopy);
        enlightenTest(secondCopy);
    }
}

list<bool> convertToLightPattern(list<bool> clickPattern){
    list<bool> lightPattern(solutionPattern.size(), 0);
    unsigned int index = 0;
    for(bool i: clickPattern){
        if(i){
            if(index >= 5) {
                auto lightPatternItem = lightPattern.begin();
                advance(lightPatternItem, index - 5);
                *lightPatternItem = switchBool(*lightPatternItem);
            }
            if(index % 5 != 0) {
                auto lightPatternItem = lightPattern.begin();
                advance(lightPatternItem, index - 1);
                *lightPatternItem = switchBool(*lightPatternItem);
            }
            if(true) {
                auto lightPatternItem = lightPattern.begin();
                advance(lightPatternItem, index);
                *lightPatternItem = switchBool(*lightPatternItem);
            }
            if(index % 5 != 4) {
                auto lightPatternItem = lightPattern.begin();
                advance(lightPatternItem, index + 1);
                *lightPatternItem = switchBool(*lightPatternItem);
            }
            if(index < solutionPattern.size() - 5) {
                auto lightPatternItem = lightPattern.begin();
                advance(lightPatternItem, index + 5);
                *lightPatternItem = switchBool(*lightPatternItem);
            }
        }
        index++;
    }
    /*
    for(bool i: lightPattern){
        cout << i;
    }
    cout << endl;
    */

    return lightPattern;
}

bool switchBool(bool thingToSwitch){
    if(thingToSwitch) return false;
    return true;
}