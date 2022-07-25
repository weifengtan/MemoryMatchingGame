#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <thread> 


using namespace std;

class MemoryMatchGame
{
    public:
        // ARRAY OF WORDS FOR THE THEME
        void start()
        {
            ifstream fin; 
            string list[50];
            string user; 
            int speed; 
            int counter = 0;
            int n = 50;

            // ASK USER FOR A THEME
            cout << "Enter a Theme (Technology, Food, Music): " << endl; 
            cin >> file; 
            string toupper(file);   // changes to uppercase
            fin.open(file);         // open file 

            while (!fin.eof()){
                getline(fin, aLine);
                list[counter] = aLine;
                counter++;  
            }

            shuffle(list, n); 

            // ASK USER FOR DIFFICULTY
            cout << "Enter a Difficulty (Easy, Moderate, Difficult): " << endl;
            cin >> user; 
            cout << "Enter flipping speed (2, 4, 6)" << endl; 
            cin >> speed; 

            if (user == "Easy"){
            easyLevel(list, file, speed);
            }
            else if (user == "Moderate"){
                moderateLevel(list, file, speed);
            }
            else if (user == "Difficult"){
                difficultLevel(list, file, speed);
            }

        }
        
        // USE Fisher-Yates shuffle method. from internent 
        void swap (string *a, string *b){
            string temp = *a;
            *a = *b; 
            *b = temp; 
        }
        void shuffle (string arr[], int n){
            srand (time(0));

            for (int i = n -1; i > 0; i--){
                int j = rand() % (i + 1);
                swap(&arr[i], &arr[j]);
            }
        }

        // EASY LEVEL THEME GRID
        void easyThemeGrid(string t){ 
            theme = t; 
             
            string lines ((theme.length()+4)*4, '-');

            string grid[4][4];
            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++){
                    grid[i][j] = theme;
                } 
            } 

            cout << lines << endl; 
            for (int i = 0; i < 4; i++) {
                cout << "~| "; 
                for(int j = 0; j < 4; j++){
                    cout << grid[i][j] << " | "; 
                    if (j == 3) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }   

        }

        // MODERATE LEVEL THEME GRID
        void moderateThemeGrid(string t){ 
            theme = t; 
             
            string lines ((theme.length()+4)*6, '-');

            string grid[6][6];
            for (int i = 0; i < 6; i++) {
                for(int j = 0; j < 6; j++){
                    grid[i][j] = theme;
                } 
            }    
            
            cout << lines << endl; 
            for (int i = 0; i < 6; i++) {
                cout << "~| "; 
                for(int j = 0; j < 6; j++){
                    cout << grid[i][j] << " | "; 
                    if (j == 5) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }   

        }

        // DIFFICULT LEVEL THEME GRID
        void difficultThemeGrid(string t){ 
            theme = t; 
             
            string lines ((theme.length()+4)*8, '-');

            string grid[8][8];
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++){
                    grid[i][j] = theme;
                } 
            }    
            
            cout << lines << endl; 
            for (int i = 0; i < 8; i++) {
                cout << "~| "; 
                for(int j = 0; j < 8; j++){
                    cout << grid[i][j] << " | "; 
                    if (j == 7) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }   

        }

        // EASY LEVEL 
        void easyLevel(string arr[50], string theme, int l) {
            int rowInputOne, columnInputOne, rowInputTwo, columnInputTwo;
            int seconds = l * 1000;
            bool notDone = true; 
            bool notValid = true; 
            bool gameWinner = true; 
            string winner;
            string choiceOne; 
            string choiceTwo; 
            theme = theme; 
            string lines ((theme.length()+4)*4, '-');
            int count = 0;

            string easyList[16]; 
            for (int i = 0; i < 8; i++){
                easyList[i] = arr[i]; 
            }

            // COPY ELEMNTS INTO LIST AGAIN
            for (int i = 8; i < 16; i++){
                easyList[i] = easyList[count];
                count++;
            }
            
            // SHUFFLE THE LIST
            shuffle(easyList, 16);
            
            // MAKE 2D ARRAY FOR ANSWERS 
            count = 0; 
            string grid[4][4];
            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++){
                    grid[i][j] = easyList[count];
                    count++; 
                } 
            }

            // MAKE 2D ARRAY FOR answerCHECK 
            string check[4][4];
            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++){
                    grid[i][j] = theme;
                    count++; 
                } 
            }

            // 2D ARRAY FOR THEME
            string themeGrid[4][4];
            for (int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++){
                    themeGrid[i][j] = theme;
                } 
            }
            
            // PRINT THEME GRID FOR THE START 
            cout << lines << endl; 
            for (int i = 0; i < 4; i++) {
                cout << "~| "; 
                for(int j = 0; j < 4; j++){
                    cout << themeGrid[i][j] << " | "; 
                    if (j == 3) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }
            // LOOP UNTILL GAME IS FINSIHED 
            while (notDone){
                // RESETTING ANSWER GRID
                winner = easyWinConditionCheck(check);
                if (winner == "END"){
                    notValid = false;
                    gameWinner = false;
                    notDone = false;
                }
                while(gameWinner){
                count = 0; 
                string grid[4][4];
                for (int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++){
                        grid[i][j] = easyList[count];
                        count++; 
                    } 
                }
                // CHECK IF GAME IS DONE
                winner = easyWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                while (notValid){
                    // ASK USER FIRST INPUT  
                    cout << "Please choose FIRST coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputOne;
                    cout << "COLUMN: "; 
                    cin >> columnInputOne;
                    // CHECK IF VALID CHOICE 
                    if (easyBoxChecker(rowInputOne, columnInputOne, check)){
                        choiceOne = easyChoose(rowInputOne,columnInputOne, grid);
                        easySwap(rowInputOne,columnInputOne,grid,themeGrid);
                        notValid = false; 
                    }
                    else{
                        cout << "Wrong input try again please!" << endl;
                    }
                }

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 4; i++) {
                    cout << "~| "; 
                    for(int j = 0; j < 4; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 3) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                 
                winner = easyWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                    else {
                        notValid = true; 
                    }
                // ASK USER SECOND INPUT AND CHECK IF VALID 
                while (notValid){
                    cout << "Please choose SECOND coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputTwo;
                    cout << "COLUMN: "; 
                    cin >> columnInputTwo;
                    // CHECK IF VALID CHOICE 
                    if ((rowInputTwo == rowInputOne)  && (columnInputOne == columnInputTwo)){
                        cout << "Wrong input, can't select same box as first box" << endl;
                    }
                    else{
                        if (easyBoxChecker(rowInputTwo, columnInputTwo, check)){
                            choiceTwo = easyChoose(rowInputTwo,columnInputTwo, grid);
                            easySwap(rowInputTwo,columnInputTwo,grid,themeGrid);
                            notValid = false; 
                        }
                        else{
                            cout << "Wrong input try again please!" << endl;
                        }
                    }
                }
                notValid = true;    // Setting condition back 

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 4; i++) {
                    cout << "~| ";
                    for(int j = 0; j < 4; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 3) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                // COMPARE THE TWO CHOICES, AND SWAPS INTO CHECKER BOARD
                if (compare(choiceOne, choiceTwo)){
                    cout << "Great Job! You found a match!" << endl;
                    easyCheckSwap(rowInputOne,columnInputOne,rowInputTwo,columnInputTwo, check);
                    
                }
                else{
                    // WAIT 2 SECONDS THEN TURN BACK TO THEME GRID
                    __libcpp_thread_sleep_for(chrono::milliseconds(seconds));
                    // SWAP BACK IF NO MATCH
                    cout << rowInputOne << columnInputOne << endl; 
                    easySetBackTheme(rowInputOne,columnInputOne,theme,themeGrid);
                    easySetBackTheme(rowInputTwo,columnInputTwo,theme,themeGrid);

                    
                    // PRINT THEME GRID
                    cout << lines << endl; 
                    for (int i = 0; i < 4; i++) {
                        cout << "~| "; 
                        for(int j = 0; j < 4; j++){
                            cout << themeGrid[i][j] << " | "; 
                            if (j == 3) {
                                cout << "~";
                                cout << "\n"; 
                                cout << lines << endl;
                            }
                        }
                    }
                }
            }
            cout << "Congrats You Won!" << endl;
        }
        }

        void moderateLevel(string arr[50], string theme, int l) {
            int rowInputOne, columnInputOne, rowInputTwo, columnInputTwo;
            int seconds = l * 1000;
            bool notDone = true; 
            bool notValid = true; 
            bool gameWinner = true; 
            string winner;
            string choiceOne; 
            string choiceTwo; 
            theme = theme; 
            string lines ((theme.length()+4)*6, '-');
            int count = 0;

            string moderateList[36]; 
            for (int i = 0; i < 18; i++){
                moderateList[i] = arr[i]; 
            }

            // COPY ELEMNTS INTO LIST AGAIN
            for (int i = 18; i < 36; i++){
                moderateList[i] = moderateList[count];
                count++;
            }
            
            // SHUFFLE THE LIST
            shuffle(moderateList, 36);
            
            // MAKE 2D ARRAY FOR ANSWERS 
            count = 0; 
            string grid[6][6];
            for (int i = 0; i < 6; i++) {
                for(int j = 0; j < 6; j++){
                    grid[i][j] = moderateList[count];
                    count++; 
                } 
            }

            // MAKE 2D ARRAY FOR answerCHECK 
            string check[6][6];
            for (int i = 0; i < 6; i++) {
                for(int j = 0; j < 6; j++){
                    grid[i][j] = theme;
                    count++; 
                } 
            }

            // 2D ARRAY FOR THEME
            string themeGrid[6][6];
            for (int i = 0; i < 6; i++) {
                for(int j = 0; j < 6; j++){
                    themeGrid[i][j] = theme;
                } 
            }
            
            // PRINT THEME GRID FOR THE START 
            cout << lines << endl; 
            for (int i = 0; i < 6; i++) {
                cout << "~| "; 
                for(int j = 0; j < 6; j++){
                    cout << themeGrid[i][j] << " | "; 
                    if (j == 5) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }
            // LOOP UNTILL GAME IS FINSIHED 
            while (notDone){
                // RESETTING ANSWER GRID
                winner = moderateWinConditionCheck(check);
                if (winner == "END"){
                    notValid = false;
                    gameWinner = false;
                    notDone = false;
                }
                while(gameWinner){
                count = 0; 
                string grid[6][6];
                for (int i = 0; i < 6; i++) {
                    for(int j = 0; j < 6; j++){
                        grid[i][j] = moderateList[count];
                        count++; 
                    } 
                }
                // CHECK IF GAME IS DONE
                winner = moderateWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                while (notValid){
                    // ASK USER FIRST INPUT  
                    cout << "Please choose FIRST coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputOne;
                    cout << "COLUMN: "; 
                    cin >> columnInputOne;
                    // CHECK IF VALID CHOICE 
                    if (moderateBoxChecker(rowInputOne, columnInputOne, check)){
                        choiceOne = moderateChoose(rowInputOne,columnInputOne, grid);
                        moderateSwap(rowInputOne,columnInputOne,grid,themeGrid);
                        notValid = false; 
                    }
                    else{
                        cout << "Wrong input try again please!" << endl;
                    }
                }

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 6; i++) {
                    cout << "~| "; 
                    for(int j = 0; j < 6; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 5) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                 
                winner = moderateWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                    else {
                        notValid = true; 
                    }
                // ASK USER SECOND INPUT AND CHECK IF VALID 
                while (notValid){
                    cout << "Please choose SECOND coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputTwo;
                    cout << "COLUMN: "; 
                    cin >> columnInputTwo;
                    // CHECK IF VALID CHOICE 
                    if ((rowInputTwo == rowInputOne)  && (columnInputOne == columnInputTwo)){
                        cout << "Wrong input, can't select same box as first box" << endl;
                    }
                    else{
                        if (moderateBoxChecker(rowInputTwo, columnInputTwo, check)){
                            choiceTwo = moderateChoose(rowInputTwo,columnInputTwo, grid);
                            moderateSwap(rowInputTwo,columnInputTwo,grid,themeGrid);
                            notValid = false; 
                        }
                        else{
                            cout << "Wrong input try again please!" << endl;
                        }
                    }
                }
                notValid = true;    // Setting condition back 

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 6; i++) {
                    cout << "~| ";
                    for(int j = 0; j < 6; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 5) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                // COMPARE THE TWO CHOICES, AND SWAPS INTO CHECKER BOARD
                if (compare(choiceOne, choiceTwo)){
                    cout << "Great Job! You found a match!" << endl;
                    moderateCheckSwap(rowInputOne,columnInputOne,rowInputTwo,columnInputTwo, check);
                    
                }
                else{
                    // WAIT 2 SECONDS THEN TURN BACK TO THEME GRID
                    __libcpp_thread_sleep_for(chrono::milliseconds(seconds));
                    // SWAP BACK IF NO MATCH
                    cout << rowInputOne << columnInputOne << endl; 
                    moderateSetBackTheme(rowInputOne,columnInputOne,theme,themeGrid);
                    moderateSetBackTheme(rowInputTwo,columnInputTwo,theme,themeGrid);

                    
                    // PRINT THEME GRID
                    cout << lines << endl; 
                    for (int i = 0; i < 6; i++) {
                        cout << "~| "; 
                        for(int j = 0; j < 6; j++){
                            cout << themeGrid[i][j] << " | "; 
                            if (j == 5) {
                                cout << "~";
                                cout << "\n"; 
                                cout << lines << endl;
                            }
                        }
                    }
                }
            }
            cout << "Congrats You Won!" << endl;
        }
        }

        void difficultLevel(string arr[50], string theme, int l) {
            int rowInputOne, columnInputOne, rowInputTwo, columnInputTwo;
            int seconds = l * 1000;
            bool notDone = true; 
            bool notValid = true; 
            bool gameWinner = true; 
            string winner;
            string choiceOne; 
            string choiceTwo; 
            theme = theme; 
            string lines ((theme.length()+4)*8, '-');
            int count = 0;

            string difficultList[64]; 
            for (int i = 0; i < 32; i++){
                difficultList[i] = arr[i]; 
            }

            // COPY ELEMNTS INTO LIST AGAIN
            for (int i = 32; i < 64; i++){
                difficultList[i] = difficultList[count];
                count++;
            }
            
            // SHUFFLE THE LIST
            shuffle(difficultList, 64);
            
            // MAKE 2D ARRAY FOR ANSWERS 
            count = 0; 
            string grid[8][8];
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++){
                    grid[i][j] = difficultList[count];
                    count++; 
                } 
            }

            // MAKE 2D ARRAY FOR answerCHECK 
            string check[8][8];
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++){
                    grid[i][j] = theme;
                    count++; 
                } 
            }

            // 2D ARRAY FOR THEME
            string themeGrid[8][8];
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++){
                    themeGrid[i][j] = theme;
                } 
            }
            
            // PRINT THEME GRID FOR THE START 
            cout << lines << endl; 
            for (int i = 0; i < 8; i++) {
                cout << "~| "; 
                for(int j = 0; j < 8; j++){
                    cout << themeGrid[i][j] << " | "; 
                    if (j == 7) {
                        cout << "~";
                        cout << "\n"; 
                        cout << lines << endl;
                    }
                }
            }
            // LOOP UNTILL GAME IS FINSIHED 
            while (notDone){
                // RESETTING ANSWER GRID
                winner = difficultWinConditionCheck(check);
                if (winner == "END"){
                    notValid = false;
                    gameWinner = false;
                    notDone = false;
                }
                while(gameWinner){
                count = 0; 
                string grid[8][8];
                for (int i = 0; i < 8; i++) {
                    for(int j = 0; j < 8; j++){
                        grid[i][j] = difficultList[count];
                        count++; 
                    } 
                }
                // CHECK IF GAME IS DONE
                winner = difficultWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                while (notValid){
                    // ASK USER FIRST INPUT  
                    cout << "Please choose FIRST coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputOne;
                    cout << "COLUMN: "; 
                    cin >> columnInputOne;
                    // CHECK IF VALID CHOICE 
                    if (difficultBoxChecker(rowInputOne, columnInputOne, check)){
                        choiceOne = difficultChoose(rowInputOne,columnInputOne, grid);
                        difficultSwap(rowInputOne,columnInputOne,grid,themeGrid);
                        notValid = false; 
                    }
                    else{
                        cout << "Wrong input try again please!" << endl;
                    }
                }

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 8; i++) {
                    cout << "~| "; 
                    for(int j = 0; j < 8; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 7) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                 
                winner = difficultWinConditionCheck(check);
                    if (winner == "END"){
                        notValid = false;
                        gameWinner = false;
                        notDone = false;
                    }
                    else {
                        notValid = true; 
                    }
                // ASK USER SECOND INPUT AND CHECK IF VALID 
                while (notValid){
                    cout << "Please choose SECOND coordinates for your box " << endl;
                    cout << "ROW: "; 
                    cin >> rowInputTwo;
                    cout << "COLUMN: "; 
                    cin >> columnInputTwo;
                    // CHECK IF VALID CHOICE 
                    if ((rowInputTwo == rowInputOne)  && (columnInputOne == columnInputTwo)){
                        cout << "Wrong input, can't select same box as first box" << endl;
                    }
                    else{
                        if (difficultBoxChecker(rowInputTwo, columnInputTwo, check)){
                            choiceTwo = difficultChoose(rowInputTwo,columnInputTwo, grid);
                            difficultSwap(rowInputTwo,columnInputTwo,grid,themeGrid);
                            notValid = false; 
                        }
                        else{
                            cout << "Wrong input try again please!" << endl;
                        }
                    }
                }
                notValid = true;    // Setting condition back 

                // PRINT THEME WITH SWAPPED 
                cout << lines << endl; 
                for (int i = 0; i < 8; i++) {
                    cout << "~| ";
                    for(int j = 0; j < 8; j++){
                        cout << themeGrid[i][j] << " | "; 
                        if (j == 7) {
                            cout << "~";
                            cout << "\n"; 
                            cout << lines << endl;
                        }
                    }
                }
                // COMPARE THE TWO CHOICES, AND SWAPS INTO CHECKER BOARD
                if (compare(choiceOne, choiceTwo)){
                    cout << "Great Job! You found a match!" << endl;
                    difficultCheckSwap(rowInputOne,columnInputOne,rowInputTwo,columnInputTwo, check);
                    
                }
                else{
                    // WAIT 2 SECONDS THEN TURN BACK TO THEME GRID
                    __libcpp_thread_sleep_for(chrono::milliseconds(seconds));
                    // SWAP BACK IF NO MATCH
                    cout << rowInputOne << columnInputOne << endl; 
                    difficultSetBackTheme(rowInputOne,columnInputOne,theme,themeGrid);
                    difficultSetBackTheme(rowInputTwo,columnInputTwo,theme,themeGrid);

                    
                    // PRINT THEME GRID
                    cout << lines << endl; 
                    for (int i = 0; i < 8; i++) {
                        cout << "~| "; 
                        for(int j = 0; j < 8; j++){
                            cout << themeGrid[i][j] << " | "; 
                            if (j == 7) {
                                cout << "~";
                                cout << "\n"; 
                                cout << lines << endl;
                            }
                        }
                    }
                }
            }
            cout << "Congrats You Won!" << endl;
        }
        }

        // RETURNS THE BOX THAT THE USER CHOSE GETTER FUNCTION 
        string easyChoose(int x, int y, string easyGrid[4][4]){
            cout << easyGrid[x][y] << endl;
            return easyGrid[x][y];
        }

         // RETURNS THE BOX THAT THE USER CHOSE GETTER FUNCTION 
        string moderateChoose(int x, int y, string moderateGrid[6][6]){
            cout << moderateGrid[x][y] << endl;
            return moderateGrid[x][y];
        }

         // RETURNS THE BOX THAT THE USER CHOSE GETTER FUNCTION 
        string difficultChoose(int x, int y, string difficultGrid[8][8]){
            cout << difficultGrid[x][y] << endl;
            return difficultGrid[x][y];
        }

        void easySwap (int x, int y, string answer[4][4], string theme[4][4]){
            theme[x][y] = answer[x][y];
        }

        void moderateSwap (int x, int y, string answer[6][6], string theme[6][6]){
            theme[x][y] = answer[x][y];
        }

        void difficultSwap (int x, int y, string answer[8][8], string theme[8][8]){
            theme[x][y] = answer[x][y];
        }

        void easySetBackTheme (int x, int y, string theme, string answer[4][4]){
            answer[x][y] = theme; 
        }

        void moderateSetBackTheme (int x, int y, string theme, string answer[6][6]){
            answer[x][y] = theme; 
        }

        void difficultSetBackTheme (int x, int y, string theme, string answer[8][8]){
            answer[x][y] = theme; 
        }

        bool compare(string one, string two){
            if (one == two){
                return true; 
            }
            else {
                return false; 
            }
        }

        string easyWinConditionCheck (string winner[4][4]){
            string var; 
            string allMatches [16];
            int count = 0;

            // FOR LOOP TO ITERATE WINNER 2D ARRAY TO FIND ALL MATCHES 
            for (int i = 0; i < 4; i ++){
                for (int j = 0; j < 4; j ++){
                    allMatches[count] = winner[i][j];
                    count++;
                }
            }

            count = 0;
            // FOR LOOP TO COUTN HOW MANY MATCHES THERE ARE
            for (int i = 0; i < 16; i++){
                if (allMatches[i] == "matched"){
                    count++;
                }
            }

            // END GAME IF ALL SPACES WERE MATCHED
            if (count == 16){
                var = "END";
                return var;
            }

            var = "GO";
            return var;
        }

        string moderateWinConditionCheck (string winner[6][6]){
            string var; 
            string allMatches [36];
            int count = 0;

            // FOR LOOP TO ITERATE WINNER 2D ARRAY TO FIND ALL MATCHES 
            for (int i = 0; i < 6; i ++){
                for (int j = 0; j < 6; j ++){
                    allMatches[count] = winner[i][j];
                    count++;
                }
            }

            count = 0;
            // FOR LOOP TO COUTN HOW MANY MATCHES THERE ARE
            for (int i = 0; i < 36; i++){
                if (allMatches[i] == "matched"){
                    count++;
                }
            }

            // END GAME IF ALL SPACES WERE MATCHED
            if (count == 36){
                var = "END";
                return var;
            }

            var = "GO";
            return var;
        }

        string difficultWinConditionCheck (string winner[8][8]){
            string var; 
            string allMatches [64];
            int count = 0;

            // FOR LOOP TO ITERATE WINNER 2D ARRAY TO FIND ALL MATCHES 
            for (int i = 0; i < 8; i ++){
                for (int j = 0; j < 8; j ++){
                    allMatches[count] = winner[i][j];
                    count++;
                }
            }

            count = 0;
            // FOR LOOP TO COUTN HOW MANY MATCHES THERE ARE
            for (int i = 0; i < 64; i++){
                if (allMatches[i] == "matched"){
                    count++;
                }
            }

            // END GAME IF ALL SPACES WERE MATCHED
            if (count == 64){
                var = "END";
                return var;
            }

            var = "GO";
            return var;
        }

        void easyCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[4][4]){
            winner[rowOne][columnOne] = "matched"; 
            winner[rowTwo][columnTwo] = "matched";
        }

        void moderateCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[6][6]){
            winner[rowOne][columnOne] = "matched"; 
            winner[rowTwo][columnTwo] = "matched";
        }

        void difficultCheckSwap(int rowOne, int columnOne, int rowTwo, int columnTwo, string winner[8][8]){
            winner[rowOne][columnOne] = "matched"; 
            winner[rowTwo][columnTwo] = "matched";
        }

        bool easyBoxChecker(int x, int y, string checker[4][4]){
            if (checker[x][y] == "matched"){
                return false;
            }
            else {
                return true; 
            }
        }

        bool moderateBoxChecker(int x, int y, string checker[6][6]){
            if (checker[x][y] == "matched"){
                return false;
            }
            else {
                return true; 
            }
        }

        bool difficultBoxChecker(int x, int y, string checker[8][8]){
            if (checker[x][y] == "matched"){
                return false;
            }
            else {
                return true; 
            }
        }

    private:
        string level; 
        string theme;  
        string file; 
        string aLine;

};

int main () {
    MemoryMatchGame Game1;
    Game1.start();
}