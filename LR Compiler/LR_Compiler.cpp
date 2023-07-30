#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const string LINE1 = "====================================\n";
const string LINE2 = "------------------------------------\n";
const string AUTHORS = "Everette & Abraham";

enum RuleType {Sn, Rn, n};

struct language
{
    string name;
    string launchString;
    string table[20][20];
    string terminalsAndNonTerminals[15];
    int lengthOfRules[20];
    string leftOfRules[20];
};

class AllLanguages{
    public: 
        int numberOfLanguages = 2;
        language availableLanguages[2];

    AllLanguages(){
        SetUpLanguages();
    }

    void SetUpLanguages(){
        //TODO: add languages 
        availableLanguages[0].launchString = "1";
        availableLanguages[0].name = "Language 1";

        availableLanguages[0].table[0][0] = "S5";
        availableLanguages[0].table[0][5] = "S4";
        availableLanguages[0].table[0][8] = "1";
        availableLanguages[0].table[0][9] = "2";
        availableLanguages[0].table[0][10] = "3";

        availableLanguages[0].table[1][1] = "S6";
        availableLanguages[0].table[1][2] = "S7";
        availableLanguages[0].table[1][7] = "ACC";

        availableLanguages[0].table[2][1] = "R3";
        availableLanguages[0].table[2][2] = "R3";
        availableLanguages[0].table[2][3] = "S8";
        availableLanguages[0].table[2][4] = "S9";
        availableLanguages[0].table[2][6] = "R3";
        availableLanguages[0].table[2][7] = "R3";

        availableLanguages[0].table[3][1] = "R6";
        availableLanguages[0].table[3][2] = "R6";
        availableLanguages[0].table[3][3] = "R6";
        availableLanguages[0].table[3][4] = "R6";
        availableLanguages[0].table[3][6] = "R6";
        availableLanguages[0].table[3][7] = "R6";

        availableLanguages[0].table[4][0] = "S5";
        availableLanguages[0].table[4][5] = "S4";
        availableLanguages[0].table[4][8] = "10";
        availableLanguages[0].table[4][9] = "2";
        availableLanguages[0].table[4][10] = "3";

        availableLanguages[0].table[5][1] = "R8";
        availableLanguages[0].table[5][2] = "R8";
        availableLanguages[0].table[5][3] = "R8";
        availableLanguages[0].table[5][4] = "R8";
        availableLanguages[0].table[5][6] = "R8";
        availableLanguages[0].table[5][7] = "R8";

        availableLanguages[0].table[6][0] = "S5";
        availableLanguages[0].table[6][5] = "S4";
        availableLanguages[0].table[6][9] = "11";
        availableLanguages[0].table[6][10] = "3";

        availableLanguages[0].table[7][0] = "S5";
        availableLanguages[0].table[7][5] = "S4";
        availableLanguages[0].table[7][9] = "12";
        availableLanguages[0].table[7][10] = "3";

        availableLanguages[0].table[8][0] = "S5";
        availableLanguages[0].table[8][5] = "S4";
        availableLanguages[0].table[8][10] = "13";

        availableLanguages[0].table[9][0] = "S5";
        availableLanguages[0].table[9][5] = "S4";
        availableLanguages[0].table[9][10] = "14";

        availableLanguages[0].table[10][1] = "S6";
        availableLanguages[0].table[10][2] = "S7";
        availableLanguages[0].table[10][6] = "S15";

        availableLanguages[0].table[11][1] = "R1";
        availableLanguages[0].table[11][2] = "R1";
        availableLanguages[0].table[11][3] = "S8";
        availableLanguages[0].table[11][4] = "S9";
        availableLanguages[0].table[11][6] = "R1";
        availableLanguages[0].table[11][7] = "R1";

        availableLanguages[0].table[12][1] = "R2";
        availableLanguages[0].table[12][2] = "R2";
        availableLanguages[0].table[12][3] = "S8";
        availableLanguages[0].table[12][4] = "S9";
        availableLanguages[0].table[12][6] = "R2";
        availableLanguages[0].table[12][7] = "R2";

        availableLanguages[0].table[13][1] = "R4";
        availableLanguages[0].table[13][2] = "R4";
        availableLanguages[0].table[13][3] = "R4";
        availableLanguages[0].table[13][4] = "R4";
        availableLanguages[0].table[13][6] = "R4";
        availableLanguages[0].table[13][7] = "R4";

        availableLanguages[0].table[14][1] = "R5";
        availableLanguages[0].table[14][2] = "R5";
        availableLanguages[0].table[14][3] = "R5";
        availableLanguages[0].table[14][4] = "R5";
        availableLanguages[0].table[14][6] = "R5";
        availableLanguages[0].table[14][7] = "R5";

        availableLanguages[0].table[15][1] = "R7";
        availableLanguages[0].table[15][2] = "R7";
        availableLanguages[0].table[15][3] = "R7";
        availableLanguages[0].table[15][4] = "R7";
        availableLanguages[0].table[15][6] = "R7";
        availableLanguages[0].table[15][7] = "R7";
        

        availableLanguages[0].terminalsAndNonTerminals[0] = "i";
        availableLanguages[0].terminalsAndNonTerminals[1] = "+";
        availableLanguages[0].terminalsAndNonTerminals[2] = "-";
        availableLanguages[0].terminalsAndNonTerminals[3] = "*";
        availableLanguages[0].terminalsAndNonTerminals[4] = "/";
        availableLanguages[0].terminalsAndNonTerminals[5] = "(";
        availableLanguages[0].terminalsAndNonTerminals[6] = ")";
        availableLanguages[0].terminalsAndNonTerminals[7] = "$";
        availableLanguages[0].terminalsAndNonTerminals[8] = "E";
        availableLanguages[0].terminalsAndNonTerminals[9] = "T";
        availableLanguages[0].terminalsAndNonTerminals[10] = "F";

        availableLanguages[0].lengthOfRules[1] = 3;
        availableLanguages[0].lengthOfRules[2] = 3;
        availableLanguages[0].lengthOfRules[3] = 1;
        availableLanguages[0].lengthOfRules[4] = 3;
        availableLanguages[0].lengthOfRules[5] = 3;
        availableLanguages[0].lengthOfRules[6] = 1;
        availableLanguages[0].lengthOfRules[7] = 3;
        availableLanguages[0].lengthOfRules[8] = 1;

        availableLanguages[0].leftOfRules[1] = "E";
        availableLanguages[0].leftOfRules[2] = "E";
        availableLanguages[0].leftOfRules[3] = "E";
        availableLanguages[0].leftOfRules[4] = "T";
        availableLanguages[0].leftOfRules[5] = "T";
        availableLanguages[0].leftOfRules[6] = "T";
        availableLanguages[0].leftOfRules[7] = "F";
        availableLanguages[0].leftOfRules[8] = "F";

        availableLanguages[1].launchString = "2";
        availableLanguages[1].name = "BLANK";
    }
};

string intToString(int input){
    string output = std::to_string(input);
}

int stringToInt(string input){
    int output = std::stoi(input);
}

RuleType checkRuleType(string input){
    RuleType output;
    if(input[0] == 'S') return output = Sn;
    else if(input[0] == 'R') return output = Rn;
    else return output = n;
}

void pushSymbolToStack(stack<string> *stack, string input){
    stack->push(input);
    std::cout << "Push: " << input << std::endl;
    std::cout << "Top of stack is: " << stack->top() << std::endl;
}

string getSymbolFromStack(stack<string> *stack){
    string output = stack->top();
    stack->pop();
    std::cout << "Pop: " << output << std::endl;
    //std::cout << "Top of stack is: " << stack->top() << std::endl;
    return output;
}

string GoTo(language *_language, int state, string character){
    string output;

    // finds the index of the given character
    auto itr_character = find(_language->terminalsAndNonTerminals, _language->terminalsAndNonTerminals + 15, character);
    int index_character = 0;
    if (itr_character != end(_language->terminalsAndNonTerminals)) index_character = distance(_language->terminalsAndNonTerminals, itr_character);
    else index_character = -1;

    output = _language->table[state][index_character];

    std::cout << "[" << state << "," << character << "] = " << output << std::endl;

    return output;
}

string getN(RuleType type, string input){
    string output;
    switch (type)
    {
    case Sn:
        output = string(input.substr(1));
        break;
    case Rn:
        output = string(input.substr(1));
        break;
    case n:
        output = input;
        break;
    
    default:
        break;
    }
    return output;
}

void caseNOrSN(stack<string> *stack, string currentState, string currentCharacter, string N){
    pushSymbolToStack(stack, currentState);
    pushSymbolToStack(stack, currentCharacter);
    pushSymbolToStack(stack, N);
}

void caseRn(stack<string> *stack, string currentState, string currentCharacter, string N, language *language){
    pushSymbolToStack(stack, currentState);

    int NAsInt = stringToInt(N);
    int amountToPop = language->lengthOfRules[NAsInt] * 2;

    std::cout << "Using rule number: " << N << std::endl;
    std::cout << "2 * length of right of rule " << N << " is " << amountToPop << std::endl;

    for(int i=0; i< amountToPop; ++i) stack->pop();

    string nextState = getSymbolFromStack(stack);
    int nextStateAsInt = stringToInt(nextState);

    string nextCharacter = language->leftOfRules[stringToInt(N)];

    string nextOutput = GoTo(language, nextStateAsInt, nextCharacter);
    caseNOrSN(stack, nextState, nextCharacter, nextOutput);
}

bool LRCompiler(language _language){

    std::cout << "Enter the string you want to compile followed by a '$'\n" << std::endl;

    string input = "";
    std::cin >> input;

    int currentCharacterIndex = -1; 

    string currentCharacter;
    string currentState = "0";
    
    bool shouldReadNextCharacter = true;

    stack<string> mainStack;
    stack<string> *ptr_stack = &mainStack;

    language *ptr_language = &_language;

    bool compilerIsGoing = true;

    int currentStep = 1;

    std::cout << LINE2 << std::endl;
    std::cout << currentStep << "." <<std::endl;
    currentStep++;

    // Pushing currentState to Stack
    pushSymbolToStack(ptr_stack, currentState);

    while (compilerIsGoing){

        std::cout << LINE2 << std::endl;
        std::cout << currentStep << "." <<std::endl;
        currentStep++;

        // Getting top value from mainStack
        currentState = getSymbolFromStack(ptr_stack);

        // Reading Next Character from Input String
        if(shouldReadNextCharacter){
            currentCharacterIndex++;
            currentCharacter = string(1, input[currentCharacterIndex]);
            std::cout << "Read: " << currentCharacter << std::endl;

            shouldReadNextCharacter = false;
        }

        int currentStateIndex = stringToInt(currentState);
        string output = GoTo(ptr_language, currentStateIndex, currentCharacter);
        if(output == "") return false;
        else if (output == "ACC") return true;
        RuleType outputType = checkRuleType(output);
        string N = getN(outputType, output);

        switch (outputType)
        {
        case Sn:
            caseNOrSN(ptr_stack, currentState, currentCharacter, N);
            shouldReadNextCharacter = true;
            break;

        case Rn:
            caseRn(ptr_stack, currentState, currentCharacter, N, ptr_language);
            break;

        case n:
            caseNOrSN(ptr_stack, currentState, currentCharacter, N);
            break;
    
        default:
            break;
        }
    }

    

    return true;
}


bool userWantsToExit(string exitMessage){
    while( 1 > 0){
        string input = "";
        std::cout << exitMessage << "(y/n): ";
        std::cin >> input;

        if (input == "N"||input == "n") return false;
        else if(input == "Y"||input == "y") return true;

        std::cout << "I'm sorry I did not recognize that input\nPlease try again" << std::endl;
    }
}

void welcomeMessage(){
    system("CLS");
    std::cout << LINE1 << "This is a compiler using the LR method\n" << "Designed by: " << AUTHORS << "\n" << LINE1 << flush;
    system("PAUSE");
}

void goodByeMessage(){
    system("CLS");
    std::cout << "Good Bye :)" << std::endl << flush;
    system("PAUSE");
    system("CLS");
}

int mainMenu(AllLanguages *_allLanguages){
    bool isGoing = true;

    while(isGoing){
        system("CLS");
        std::cout << "Please chose a language\n" << std::endl;
        for (int i = 0; i < _allLanguages->numberOfLanguages; ++i){
            string _launchString = _allLanguages->availableLanguages[i].launchString;
            string _name = _allLanguages->availableLanguages[i].name;
            std::cout << _launchString << " : " << _name << std::endl;
        }
        std::cout << "9 : EXIT" << std::endl;
        std::cout << "\n\n" << std::endl;

        string input = "";
        std::cin >> input;
        if(input == "9") return 9;
        for (int i = 0; i < _allLanguages->numberOfLanguages; ++i){
            string _launchString = _allLanguages->availableLanguages[i].launchString;
            if(input == _launchString){
                return i;
            }
        }

        system("CLS");
        std::cout << "I'm Sorry I don't recognize that input\nPlease try again" << std::endl << flush;
        system("PAUSE");
    }
}
  
// Driver Code
int main()
{
    bool isGoing = true;
    AllLanguages allLanguages;
    AllLanguages* allLanguagesPtr = &allLanguages;

    welcomeMessage();

    while(isGoing){
        int input = mainMenu(allLanguagesPtr);

        if(input == 9){
            goodByeMessage();
            isGoing = false;
        }
        else {
            system("CLS");
            if (LRCompiler(allLanguages.availableLanguages[input])) std::cout << "Your string compiled!" << std::endl << flush;
            else std::cout << "Your string was rejected" << std::endl << flush;
            system("PAUSE");
        }
    }

    return 0;
}