#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include "char_stack.h"

using namespace std;

int main(){

    char_stack opensymbol_stack; // opening parentheses
    char_stack location_stack; // Location 
    char_stack linenumber_stack; // Linenumber
    char_stack closesymbol_stack;// closing parentheses

    char mystr[250]; // array variable
    char pop_symbol, close_symbol;
    int line_number = 0;
    int length,firstline,blankspace,secondline,tab,tabprint,line_length,i,j,p;

    while (cin.peek() != EOF){ // Check if there exist a character at the EOF

        cin.getline(mystr,250); // Place current line file into mystr variable

        if (cin.gcount() == 0){ // If the length of the line is zero, exit out of for loop
            break;}

        i=0, p=0;
        line_length = cin.gcount();
        line_number = line_number+1;
        linenumber_stack.push(line_number);
        length=cin.gcount()-1;
        tab=0;

        while (line_length-1 >= 0 ){
           
            if (mystr[i] == '{'|| mystr[i] == '(' || mystr[i] == '['){ // Checking opening parentheses

                if (mystr[i] == '{'){
                close_symbol = '}';}

                if (mystr[i] == '['){
                close_symbol = ']';}

                if (mystr[i] == '('){
                close_symbol = ')';}

                closesymbol_stack.push(close_symbol); // Push closing parentheses into stack
                opensymbol_stack.push(mystr[i]); // Push open parentheses into stack
                location_stack.push(i); // Push location of the current character into stack
            }
                if (mystr[i] == '\t'){
                 tab++;}

            else if (mystr[i] == '}' || mystr[i] == ')' || mystr[i] == ']'){

                    if (opensymbol_stack.empty()){

                    cout << "Error in line " << line_number << " : Too many " << mystr[i] << "\n";

                    for (firstline=0; firstline <= i; firstline++){ // Outputs the string up to error [including error]
                        cout << mystr[firstline] ;}

                    cout << "\n";

                    for (tabprint=0; tabprint<tab;tabprint++){ // Outputs the number of tabs
                        cout << '\t';}

                    for (blankspace=0; blankspace <= (i-tab);blankspace++){ // Outputs the number of spaces till the first line
                        cout << " ";}

                    for (secondline=i+1; secondline<length;secondline++){ // Outputs the rest of the line after the error
                        cout << mystr[secondline];}

                    cout << "\n";
                    return 0;
                    }

                pop_symbol = opensymbol_stack.pop();
                close_symbol = closesymbol_stack.pop();
                location_stack.pop();
                
                if (close_symbol != mystr[i]){
        
                    cout << "Error in line: " << line_number << " Read " << mystr[i] << ", expected " << close_symbol << "\n";

                    for (firstline=0; firstline <= i; firstline++){
                        cout << mystr[firstline] ;}

                    cout << "\n";

                    for (tabprint=0; tabprint<tab;tabprint++){
                        cout << '\t';}

                    for (blankspace=0; blankspace <=(i-tab);blankspace++){
                        cout << " ";}

                    for (secondline=i+1; secondline<length;secondline++){
                        cout << mystr[secondline];}
                    
                    cout << "\n";
                    return 0;
                }
            }
            i = i + 1; // Iterations for next char in mystr
            line_length = line_length -1; // Decrese length of the string by -1
        }
    }

        if (!opensymbol_stack.empty()){ 

            char pop_symbol = opensymbol_stack.pop();
            int pop_number = linenumber_stack.pop();

            cout << "Error in line " << pop_number; 
            cout << ": Too many " << pop_symbol << "\n";

            for (firstline=0; firstline <= i; firstline++){
                cout << mystr[firstline];}

            cout << "\n";

            for (tabprint=0; tabprint<tab;tabprint++){
                cout << '\t';}

            for (blankspace=0; blankspace <(i-tab);blankspace++){
                cout << " ";}

            for (secondline=i+1; secondline<length;secondline++){
                cout << mystr[secondline];}
                    
            cout << "\n";
            return 0;   
        }

    cout << "Report: No Error Found" << "\n";
    return 0;
}



   