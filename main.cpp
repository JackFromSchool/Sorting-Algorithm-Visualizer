#include <array>
#include <random>
#include <iostream>
#include "raylib.h"

#include "button.hpp"
#include "selection.hpp"
#include "bubble.hpp"

int main() {

    const int WINDOW_HEIGHT = 1080;
    const int WINDOW_WIDTH = 1920;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sorting Algorithms");
    ToggleFullscreen();
    SetTargetFPS(144);
   
    std::array<int, 100> mainArray;

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

    Button bubble(10, 10, 100, "Bubble Sort");
    Button selection(10, 120, 100, "Selection Sort");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        bubble.drawButton();
        selection.drawButton();
        EndDrawing();

        if(bubble.isPressed()) bubbleSort(WINDOW_WIDTH, WINDOW_HEIGHT, mainArray);
        if(selection.isPressed()) selectionSort(WINDOW_WIDTH, WINDOW_HEIGHT, mainArray);
    }

    CloseWindow();
}