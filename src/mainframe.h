#ifndef HEADER_FILE_MAINFRAME
#define HEADER_FILE_MAINFRAME

#include <iostream>
#include <string>

#include <gtkmm/main.h>
#include <gtkmm/window.h>

#include "model.h"
#include "drawingAreaNew.h"

using namespace std;

class MainFrame {
  private: 
    Model * _model;
    
    Gtk::Main _main;
    
    Gtk::Window _window;
    
    DrawingAreaNew _drawing_area;
    
  public:
    MainFrame(Model *);
    int runWindow();
};
  
MainFrame::MainFrame(Model * model) {
  _model = model;

  _main = Gtk::Main();
  _window = Gtk::Window();   
  _window.set_title("DrawingArea");
  _window.set_default_size(1024, 720);
  
  _drawing_area = DrawingAreaNew(_model);
  _window.add(_drawing_area);
  _drawing_area.show();
  
}

int MainFrame::runWindow() {
  Gtk::Main::run(_window);
  return 0;
}

#endif
