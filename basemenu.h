#ifndef BASEMENU_H
#define BASEMENU_H
class BaseMenu {
 public:
  virtual void displayMenu() = 0;
  virtual void selectOption(char option) = 0;
  virtual void displayBar() = 0;
};

#endif
