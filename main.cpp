#include <iostream>
#include "menu.h"
using namespace std;

int main(){

    Menu newUser;

    bool isActive = true;
    char userInput;

    newUser.displayOpening();
    newUser.displayBar();

    while(isActive){
        newUser.displayMenu();

        cin >> userInput;
        userInput = tolower(userInput);
        newUser.selectOption(userInput);

        if(userInput == 'h'){
            
        }

        if(userInput == 'q'){
            isActive = false;
        }
    }

    exit(0);

    return 0;

    
}