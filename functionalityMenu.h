#ifndef FUNCTIONALITYMENU_H
#define FUNCTIONALITYMENU_H

#include "basemenu.h"

class functionalityMenu : public BaseMenu {
public:
    void displayMenu() override;
    void selectOption(char option) override;
    void displayBar() override;
};

#endif 