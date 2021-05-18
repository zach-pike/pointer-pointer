#include "raylib.h"
#include "math.h"
#include "pointer.h"
#include <stdio.h>
#include <stdlib.h>

//max ammount of pointers allowed on screen
const int maxPointers = 75;


//don't touch part
//pointer pointer array
Pointer* pointers;
bool showtriag = false;
int pointercounter = 0;

//allocate memory and store pointer
void alloc() {
    pointers = malloc(maxPointers * sizeof(Pointer));
}

int main(void) {
    //get first time pointer array
    alloc();

    //init window and fullscreen
    InitWindow(0, 0, "Pointer Pointer");
    ToggleFullscreen();

    //get arrow texture
    Image arrowimg = LoadImage("rotated.png");
    ImageResize(&arrowimg, arrowimg.width / 8, arrowimg.height / 8);
    Texture2D arrow = LoadTextureFromImage(arrowimg);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        //set backgound color
        ClearBackground(GRAY);

        //show triange toggle
        if (IsKeyPressed(KEY_T)) showtriag = !showtriag;

        //reset key
        if (IsKeyPressed(KEY_R)) {
            //free poiu
            free(pointers);
            pointercounter = 0;
            alloc();
        }

        //add key
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (pointercounter < maxPointers) {
                pointers[pointercounter] = PointerHelper(GetMousePosition(), arrow);
                pointercounter++;
            }
        }

        //render pointers
        for (int i=0; i < pointercounter; i++) {
            PointTo(&pointers[i], GetMousePosition(), showtriag);
        }

        //draw text
        DrawText(FormatText("Currently displaying: %d pointers", pointercounter), 0, 0, 30, DARKBLUE);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}