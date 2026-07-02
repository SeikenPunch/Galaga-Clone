#pragma once

#include <raylib.h>
#include <vector>
#include "Button.hpp"

class Screen {
   public: 
      void makeButton(Vector2 position, std::string text, Color textColor, float fontSize);
      void update();
   private:
      void checkMouse();
      std::vector<Button> buttons;
      Color backgroundColor;


};