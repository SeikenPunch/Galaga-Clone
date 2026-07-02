#include "Screen.hpp"


void Screen::makeButton(Vector2 position, std::string text, Color textColor, float fontSize){

}

void Screen::update(){
   checkMouse();
}

void Screen::checkMouse(){
   for(auto & button : buttons){
      button.update();
   }
}