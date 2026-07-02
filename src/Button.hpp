#pragma once

#include <raylib.h>
#include <string>

typedef struct Boundary{
   float top = 0;
   float bottom = 0;
   float left = 0;
   float right = 0;
};

class Button{
   public:
      Button();
      void start();
      void setPosition(Vector2 newPosition);
      void setPosition(float x, float y);
      void setText(std::string text);
      void setButtonColor(Color color);
      void setRotation(float rot);
      void setFontSize(float size);
      void setTextSpacing(float spacing);
      void setTexture(std::string path);
      Vector2 getPosition();
      void draw();

      void update();

   private:
      void setOriginCenter();
      void setBoundary();
      void setButtonSize(Vector2 size);
      bool mouseInside(Vector2 mousePos);
      Boundary bounds;
      float buffer = 30.f;
      Vector2 buttonSize;
      Font font;
      std::string buttonText;
      Vector2 position;
      Vector2 origin;
      Color currentColor;
      Color textColor;
      Color buttonColor;
      Color buttonHoverColor;
      Color clickColor;
      float rotation = 0;
      float fontSize;
      float spacing;
      //Texture texture;
      bool isClicked = false;

   // Draw variables
   // font, text, position, origin, rotation, fontSize, spaceing, color
};