#include "../include/raylib.h"
#include "../include/touch.h"

int main()
{
    InitWindow(0, 0, "BASS");
    ToggleFullscreen(); 
    SetTargetFPS(60);
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();

    
    //Vector2 touch_pos[8];
    int touch_points = 0;
    //int ids[8];

   

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        

        //updating
        touch.updatePress();

        //Drawing
        ClearBackground(BLACK);
        
        touch_points = touch.num;
        
        for(int i = 0; i < MAX_TOUCH; i++)
        {
            //ids[i] = GetTouchPointId(i);
            //touch_pos[i] = GetTouchPosition(i);

            DrawText(TextFormat("%i", i), i*100, 30, 20, WHITE);  
            DrawText(TextFormat("%i", (int)touch.pos_id[i].x), i*100, 60, 20, WHITE);
            DrawText(TextFormat("%i", (int)touch.pos_id[i].y), i*100, 90, 20, WHITE);
            DrawText(TextFormat("%i", (int)touch.pressed_id[i]), i*100, 120, 20, WHITE);
        }

        DrawText(TextFormat("Touch points: %i", touch.num), 0, 150, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}