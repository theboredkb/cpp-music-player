#ifndef OPENINGMENU_H
#define OPENINGMENU_H

#include "basemenu.h"

class OpeningMenu : public BaseMenu {
public:
    void displayMenu() override;
    void selectOption(char option) override;
    void displayBar() override;
};

#endif 