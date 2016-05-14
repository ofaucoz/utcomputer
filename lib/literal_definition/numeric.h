//
// Created by orphee on 14/05/16.
//

#ifndef LO21_NUMERIC_H
#define LO21_NUMERIC_H

#include <iostream>
#include <regex>
#include <queue>
#include <stdlib.h>
#include "interface.h"
#include "../literal/numeric.h"


class NumericLiteralDefinition : public LiteralDefinitionInterface{

public:
    string getPattern() const {
        return "([0-9]+/?[0-9]?+\\$?[0-9]?+/?[0-9]?+)";

    }
    /*cut the string into a queue in order to have each number
     *for example if you have 36/9$55/7 it will create this queue
     * 36
     * /
     * 9
     * $
     * 55
     * /
     * 7
     * */
    //this fonction help us creating the numericLiteral instance


    queue<std::string> parsingString (string value) const
    {
        queue<std::string> stringParser;
        std::string input="";
        for(int i=0;i<value.size();i++)
        {

            if(value[i]!='$'&&value[i]!='/')
            {
                input += value[i];
                if(value[i+1]=='\0')
                {
                    stringParser.push(input);
                    input ="";
                }

            }
            else if(value[i]=='/')
            {
                stringParser.push(input);
                input="";
                stringParser.push("/");
            }
            else //value[i]=='$'
            {
                stringParser.push(input);
                stringParser.push("$");
                input="";
            }


        }


        return stringParser;
    }

    LiteralInterface* createInstance(string value) const {
        queue<std::string> parsedString = parsingString(value);
        NumericLiteral * res = new NumericLiteral();
        bool rational = false;
        bool comp = false;
        double realNumerator=0;
        double realDenominator=1;
        double imagNumerator=0;
        double imagDenominator=1;
        int size = parsedString.size();
        for(int i=0;i<size;i++)
        {

           if(parsedString.front()=="/") //then the next number will be a denominator
           {
               rational = true;
               parsedString.pop();
           }
           else if(parsedString.front()=="$") //then the next numbers will be imaginary
           {
               comp = true;
               parsedString.pop();
           }
           else if(rational==false&&comp==false)//not a denominator and not complex ==> real numerator
           {

               realNumerator = stod(parsedString.front());
               parsedString.pop();

           }
           else if(rational==false&&comp==true)
           {
               imagNumerator = stod(parsedString.front());
               parsedString.pop();

           }
           else if(rational==true&&comp==false)
           {
               realDenominator = stod(parsedString.front());
               parsedString.pop();
               rational=false;

           }
           else if(rational==true&&comp==true) //denominator and imaginary ==> imaginary denominator
           {
               imagDenominator = stod(parsedString.front());
               parsedString.pop();
               rational=false;

           }
        }

        return new NumericLiteral(realNumerator,realDenominator,imagNumerator,imagDenominator);
    }
};


#endif //LO21_NUMERIC_H
