#include "../include/raylib.h"
//#include "../include/touch.hpp"
#include "../include/button.hpp"

int main()
{
    InitWindow(0, 0, "");
    ToggleFullscreen(); 
    SetTargetFPS(60);
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();

    int touch_points = 0;

    Button button;
    button.init(screen_width/2 - 80, screen_height/2 - 80, 160, 160, YELLOW);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        

        //updating
        button.pressed();

        //Drawing
        ClearBackground(BLACK);
        
        button.draw();
       
        EndDrawing();
    }

    CloseWindow();

    return 0;
}