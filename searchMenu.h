#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include "basemenu.h"

class SearchMenu : public BaseMenu {
public:
    void displayMenu() override;
    void selectOption(char option) override;
    void displayBar() override;
};

#endif 