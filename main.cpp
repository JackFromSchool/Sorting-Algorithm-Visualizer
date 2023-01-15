#include <array>
#include <random>
#include <algorithm>
#include <iostream>
#include "raylib.h"


int main() {
    InitWindow(1000, 500, "Sorting Algorithms");
    SetTargetFPS(360);
   
    std::array<int, 100> mainArray;

    // Create an array with values 1-100 randomly in an array
    srand(time(NULL));
    int temp;
    bool valid = false;
    for(int i = 0; i < 100; i++) {
        do {
            temp = (rand()%100)+1;
            valid = true;
            for(int i = 0; i < 100; i++) {
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

        BeginDrawing();

        ClearBackground(BLACK);

        if(!sorted) {
        for(int i = 0; i < mainArray.size(); i++) {
            if(step == i || smallestIndex == i) {
                DrawRectangle(i*10, 500-mainArray[i]*5, 9, mainArray[i]*5, RED);
            } else {
                DrawRectangle(i*10, 500-mainArray[i]*5, 9, mainArray[i]*5, WHITE);
            }
        }

        // Check to see if we found a new smallest value
        if(mainArray[step] < mainArray[smallestIndex]) {
            smallestIndex = step;
        }

        step++;

        if(step == 100) {
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
            if(sortedSize == 99) {
                sorted = true;
                step = 0;
            }

        }
        } else {
            for(int i = 0; i < mainArray.size(); i++) {
                if(step == i) {
                    DrawRectangle(i*10, 500-mainArray[i]*5, 9, mainArray[i]*5, RED);
                } else if (step > i) {
                    DrawRectangle(i*10, 500-mainArray[i]*5, 9, mainArray[i]*5, GREEN);
                } else {
                    DrawRectangle(i*10, 500-mainArray[i]*5, 9, mainArray[i]*5, WHITE);
                }
            }

            // Fake checking to see if the array is sorted cause I know it is
            if(step != 99) {
                step++;
            }

        }

        EndDrawing();
    }

    CloseWindow();
}