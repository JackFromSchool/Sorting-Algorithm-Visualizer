#include <array>
#include <random>
#include <iostream>
#include "raylib.h"

#include "selection.hpp"

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

    selectionSort(WINDOW_WIDTH, WINDOW_HEIGHT, mainArray);

    CloseWindow();
}