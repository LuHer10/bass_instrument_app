#pragma once
#include"raylib.h"
#define MAX_TOUCH 8

class Touch
{
public:
    int ids[MAX_TOUCH]; //touch id arrays
    int num; //number of touch points
    Vector2 pos[MAX_TOUCH]; //positions (non-sorted)
    int pressed[MAX_TOUCH]; 
    Vector2 pos_id[MAX_TOUCH]; //positoons (sorted)
    int pressed_id[MAX_TOUCH]; //is pressed?

    void updatePress()
    {
        int count = GetTouchPointCount();

        //set active touches 
        for(int i = 0; i < count; i++)
        {
            ids[i] = GetTouchPointId(i);
            pos[i] = GetTouchPosition(i);
            pressed[i] = 1;
        }

        //reset non active touches
        for(int i = count; i < MAX_TOUCH; i++)
        {
            ids[i] = -1;
            pos[i] = {-1000.0f, -1000.0f};
            pressed[i] = 0;
        }
        
        //sort_id();
    }

    void sort_id()
    {
        int curr_id = 0;
        num = 0;
        for(int i = 0; i < MAX_TOUCH; i++)
        {
            pressed_id[i] = 0;
            pos_id[i] = {-1000.0f, -1000.0f};
            if(ids[i] != -1) num++;
            
        }
        for(int i = 0; i < num; i++)
        {
            curr_id = ids[i];
            pressed_id[curr_id] = 1;
            pos_id[curr_id] = pos[i];
        }
    }
}touch;