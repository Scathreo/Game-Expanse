#include <iostream>
#include <string>

#include "model.h"
#include "mainframe.h"
#include "mountain.h"

using namespace std;

int main(int argc, char *argv[]) {
  
  Model model         = Model();
  MainFrame mainframe = MainFrame(& model);
  
  int exec = mainframe.runWindow();
  
  return exec;
}

