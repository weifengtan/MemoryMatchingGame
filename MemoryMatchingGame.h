#ifndef MEMORYMATCHINGGAME_H
#define MEMORYMATCHINGGAME_H
#include <iostream>
#include <string>
using namespace std; 

class MemoryMatchGame
{
    public:
        void start(); 
        void swap (string *a, string *b);
        void shuffle (string arr[], int n);
        void easyLevel(string arr[50], string theme, int l);
        void moderateLevel(string arr[50], string theme, int l);
        void difficultLevel(string arr[50], string theme, int l);
        string easyChoose(int x, int y, string easyGrid[4][4]);
        string moderateChoose(int x, int y, string moderateGrid[6][6]);
        string difficultChoose(int x, int y, string difficultGrid[8][8]);
        void easySwap (int x, int y, string answer[4][4], string theme[4][4]);
        void moderateSwap (int x, int y, string answer[6][6], string theme[6][6]);
        void difficultSwap (int x, int y, string answer[8][8], string theme[8][8]);
        void easySetBackTheme (int x, int y, string theme, string answer[4][4]);
        void moderateSetBackTheme (int x, int y, string theme, string answer[6][6]);
        void difficultSetBackTheme (int x, int y, string theme, string answer[8][8]);
        bool compare(string one, string two);
        string easyWinConditionCheck (string winner[4][4]);
        string moderateWinConditionCheck (string winner[6][6]);
        string difficultWinConditionCheck (string winner[8][8]);
        void easyCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[4][4]);
        void moderateCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[6][6]);
        void difficultCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[8][8]);
        bool easyBoxChecker(int x, int y, string checker[4][4]);
        bool moderateBoxChecker(int x, int y, string checker[6][6]);
        bool difficultBoxChecker(int x, int y, string checker[8][8]);
    private:
        string level; 
        string theme;  
        string file; 
        string aLine;
};
#endif