#include "Button.hpp"
#include <iostream>

Button::Button(){
};

void Button::start(){
   buttonText = "default";
   position = {0,0};
   textColor = WHITE;
   buttonColor = GRAY;
   currentColor = GRAY;
   buttonHoverColor = GREEN;
   clickColor = WHITE;
   rotation = 0;
   isClicked = false;
   fontSize = 5;
   spacing = 5;
   buttonSize = {0,0};
   font = GetFontDefault();
   setOriginCenter();
}

void Button::setPosition(Vector2 position){
   this->position = position;
   setOriginCenter();
}

void Button::setPosition(float x, float y){
   Vector2 newPos = {x, y};
   position = newPos;
   setOriginCenter();
}

void Button::setText(std::string text){
   buttonText = text;
   setOriginCenter();
}

void Button::setButtonColor(Color color){
   buttonColor = color;
}

void Button::setRotation(float rotation){
   this->rotation = rotation;
}

void Button::setFontSize(float size){
   fontSize = size;
   setOriginCenter();
}

void Button::setTexture(std::string path){
   //texture = LoadTexture(path.c_str());
}

void Button::setTextSpacing(float spacing){
   this->spacing = spacing;
   setOriginCenter();
}

Vector2 Button::getPosition(){
   return position;
}

void Button::setBoundary(){
   bounds.top = position.y + (buttonSize.y / 2);
   bounds.bottom = position.y - (buttonSize.y / 2);
   bounds.left = position.x - (buttonSize.x / 2);
   bounds.right = position.x + (buttonSize.x / 2);
}

void Button::setButtonSize(Vector2 size){
   buttonSize = size;
   buttonSize.x += buffer;
   buttonSize.y += buffer;
}

void Button::draw(){
   Vector2 rectSize = MeasureTextEx(font, buttonText.c_str(), fontSize, spacing);
   setButtonSize(rectSize);
   setBoundary();
   Rectangle rect = {
      position.x,
      position.y,
      buttonSize.x,
      buttonSize.y
   };
   Vector2 rectOrigin = {(buttonSize.x) / 2, (buttonSize.y) / 2};
   DrawRectanglePro(rect, rectOrigin,0, currentColor); // TODO: Change to texture; 0 is rotation
   DrawTextPro(
      font,
      buttonText.c_str(),
      position,
      origin,
      rotation,
      fontSize,
      spacing,
      textColor
   );
}

bool Button::mouseInside(Vector2 mousePos){
   if(mousePos.y < bounds.top && mousePos.y > bounds.bottom &&
      mousePos.x < bounds.right && mousePos.x > bounds.left){
         return true;
      }

   return false;
}

void Button::update(){
   Vector2 mousePos = GetMousePosition();
   std::cout << mousePos.x << " " << mousePos.y << "  " << bounds.top << " " << bounds.bottom << "    " << bounds.left << "  " << bounds.right << "  " << mouseInside(mousePos) << '\n';
   if(mouseInside(mousePos)){
      currentColor = buttonHoverColor;
   }
   else{
      currentColor = buttonColor;
   }
}

void Button::setOriginCenter(){
   Vector2 size = MeasureTextEx(font, buttonText.c_str(), fontSize, spacing);
   origin = {size.x / 2, size.y / 2};
}
