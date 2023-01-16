#include "raylib.h"
#include <array>

void bubbleSort(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, std::array<int, 100>& mainArray) {
   int step = 1;
   int sortedSize = 0;
   bool sorted = false;

   const int BAR_WIDTH = WINDOW_WIDTH/mainArray.size();
   const int BAR_HEIGHT = WINDOW_HEIGHT/mainArray.size();

   while(!WindowShouldClose()) {

   BeginDrawing();

   ClearBackground(BLACK);

   if(!sorted) {
   for(int i = 0; i < mainArray.size(); i++) {
      if(step == i) {
            DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, RED);
      } else {
            DrawRectangle(i*BAR_WIDTH, WINDOW_HEIGHT-mainArray[i]*BAR_HEIGHT, BAR_WIDTH-1, mainArray[i]*BAR_HEIGHT, WHITE);
      }
   }

   // Swap if the value before step is bigger than step
   if(mainArray[step-1] > mainArray[step]) {
      int swap;
      swap = mainArray[step-1];
      mainArray[step-1] = mainArray[step];
      mainArray[step] = swap;
   }

   step++;

   if(step == mainArray.size()-sortedSize) {
      // Return to the start and increase our known sorted area
      sortedSize++;
      step = 1;

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

   mainArray.fill(0);
   srand(time(NULL));
   int temp;
   bool valid = false;
   for(int i = 0; i < mainArray.size(); i++) {
      do {
         temp = (rand()%mainArray.size())+1;
         valid = true;
         for(int i = 0; i < mainArray.size(); i++) {
            if(temp == mainArray[i]) {
               valid = false;
            }
         }
      } while(!valid);
      mainArray[i] = temp;
      valid = false;
   }
}