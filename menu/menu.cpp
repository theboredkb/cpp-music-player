#include <iostream>
#include "menu.h"

using namespace std;

void Menu::displayMenu() {
    cout << "--------------------------" << endl;
    cout << "|          Menu          |" << endl;
    cout << "| (a) Add to Music List  |" << endl;
    cout << "| (b) Sort By Song       |" << endl;
    cout << "| (c) Sort By Genre      |" << endl;
    cout << "| (d) Sort By Album      |" << endl;
    cout << "| (e) List Current Order |" << endl;
    cout << "| (f) Exit               |" << endl;
    cout << "--------------------------" << endl;
}

void Menu::selectOption(char option){
    switch (option) {
        case 'a':
            //Add to Music List
            break;
        case 'b':
            //Sort By Song   
            break;
        case 'c':
            //Sort By Genre 
            break;
        case 'd':
            //Sort By Album  
            break;
        case 'e':
            //List Current Order
            break;
        case 'f':
            cout << "Exited." << endl;
            break;
        default:
            cout << "Invalid option - please try again." << endl;
    }
}