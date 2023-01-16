#include "raylib.h"

class Button {
   int x, y;
   int height, width;
   const char* text;   

   public:
   Button(int x, int y, int height, const char* text) {
      this->x = x;
      this->y = y;
      this->height = height;
      this->text = text;
   }

   bool isPressed() {
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
         if((GetMouseX() > x && GetMouseX() < x+MeasureText(text, height)) && (GetMouseY() > y && GetMouseY()  < y+height)) 
            return true;
      }
      return false;
   }

   void drawButton() {
      if((GetMouseX() > x && GetMouseX() < x+MeasureText(text, height)) && (GetMouseY() > y && GetMouseY() < y+height))
         DrawText(text, x, y, height, ORANGE);
      else

         DrawText(text, x, y, height, GRAY);

   }
};