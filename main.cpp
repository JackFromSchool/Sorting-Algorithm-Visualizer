#include <array>
#include <random>
#include <algorithm>
#include <iostream>
#include "raylib.h"


int main() {

    const int WINDOW_HEIGHT = 1080;
    const int WINDOW_WIDTH = 1920;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sorting Algorithms");
    ToggleFullscreen();
    SetTargetFPS(1000);
   
    std::array<int, 320> mainArray;

    // Create an array with values 1-100 randomly in an array
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

    int step = 0;
    int smallestIndex = 0;
    int sortedSize = 0;
    bool sorted = false;

    while(!WindowShouldClose()) {
        const int BAR_WIDTH = WINDOW_WIDTH/mainArray.size();
        const int BAR_HEIGHT = WINDOW_HEIGHT/mainArray.size();

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

    CloseWindow();
}