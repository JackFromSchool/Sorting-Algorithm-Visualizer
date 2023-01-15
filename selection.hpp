#include "raylib.h"
#include <array>

void selectionSort(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, std::array<int, 320>& mainArray) {
   int step = 0;
   int smallestIndex = 0;
   int sortedSize = 0;
   bool sorted = false;

   const int BAR_WIDTH = WINDOW_WIDTH/mainArray.size();
   const int BAR_HEIGHT = WINDOW_HEIGHT/mainArray.size();

   while(!WindowShouldClose()) {

   BeginDrawing();

   ClearBackground(BLACK);

   if(!sorted) {
   for(int i = 0; i < mainArray.size(); i++) {
      if(step == i || smallestIndex == i) {
            DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, RED);
      } else {
            DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, WHITE);
      }
   }

   // Check to see if we found a new smallest value
   if(mainArray[step] < mainArray[smallestIndex]) {
      smallestIndex = step;
   }

   step++;

   if(step == mainArray.size()) {
      // Swap the smallest with the current
      int swap;
      swap = mainArray[smallestIndex];
      mainArray[smallestIndex] = mainArray[sortedSize];
      mainArray[sortedSize] = swap;

      // Prepare step for the next run throught the array
      sortedSize++;
      step = sortedSize;
      smallestIndex = step;
      // See if we've made it through the array
      if(sortedSize == mainArray.size()-1) {
            sorted = true;
            step = 0;
      }

   }
   } else {
      for(int i = 0; i < mainArray.size(); i++) {
            if(step == i) {
               DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, RED);
            } else if (step > i) {
               DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, GREEN);
            } else {
               DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, WHITE);
            }
      }

      // Fake checking to see if the array is sorted cause I know it is
      if(step != mainArray.size()-1) {
            step++;
      }

   }

   EndDrawing();

   }
}