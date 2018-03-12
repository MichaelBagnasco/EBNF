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
    
    string number,
    newNumber;
    
    ofstream fout;
    fout.open("output.txt");
    
    while(getline(fin, number))
    {
        if (number.length() > 16)
        {
            cout << "Invalid Number" << endl;
            fout << "Invalid Number" << endl;
            continue;
        }
        
        newNumber = convert(number);
        cout << newNumber << endl;
        fout << newNumber << endl;
    }
    
    //cin >> number;
    return 0;
}

string convert(string number)
{
    int newIndex = 1;
    int index = 0;
    u_long length = number.length();
    
    string newNumber = "(000) 000-0000";
    
    if (length <= 8)
    {
        newIndex = 0;
        newNumber = "000-0000";
    }
    
    if (number[index] == '+')
        index++;
    if (number[index] == '1')
        index++;
    
    
    for (; index < length; index++)
    {
        if (length < 9)
        {
            if (recognize(number[index]))
            {
                newNumber[newIndex] = number[index];
                newIndex++;
                if (newIndex == 3)
                    newIndex = 4;
            }
        }
        else
        {
            if (recognize(number[index]))
            {
            newNumber[newIndex] = number[index];
            newIndex++;
            if (newIndex == 4)
                newIndex = 6;
            else if (newIndex == 9)
                newIndex = 10;
            }
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
