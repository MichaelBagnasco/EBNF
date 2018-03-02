//
//  main.cpp
//  EBNF
//
//  Created by Mikey on 3/1/18.
//  Copyright © 2018 Michael Bagnasco. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool recognize(char);
string convert(string);

int main() {
    ifstream fin;
    fin.open("input.txt");
    
    ofstream fout;
    fout.open("output.txt");
    
    for (; ; <#increment#>) {
        <#statements#>
    }
    
    return 0;
}

string convert(string number)
{
    string newNumber = "(000) 000-000";
    
    if (number[0] == '+')
        for (int i = 0; i < number.length(); i++)
            number[i] = number[i+1];
    if (number[0] == '1')
        for (int i = 0; i < number.length(); i++)
            number[i] = number[i+1];
    
    for (int i = 0; i < number.length(); i++) {
        int j = 1;
        if (recognize(number[i])) {
            newNumber[j] = number[i];
            j++;
            if (j == 4)
                j = 6;
            else if (j == 9)
                j = 10;
        }
    }
    
    return newNumber;
}


bool recognize(char number)
{
    if (number == '0' ||
        number == '1' ||
        number == '2' ||
        number == '3' ||
        number == '4' ||
        number == '5' ||
        number == '6' ||
        number == '7' ||
        number == '8' ||
        number == '9') {
        return true;
    }
    else
        return false;
}
