#include"raylib.h"
#define MAX_TOUCH 8

class Touch
{
public:
    int ids[MAX_TOUCH];
    int num;
    Vector2 pos[MAX_TOUCH];
    //int pressed[MAX_TOUCH];
    Vector2 pos_id[MAX_TOUCH];
    int pressed_id[MAX_TOUCH];

    void updatePress()
    {
        int count = GetTouchPointCount();
        for(int i = 0; i < count; i++)
        {
            ids[i] = GetTouchPointId(i);
            pos[i] = GetTouchPosition(i);
        }
        for(int i = count; i < MAX_TOUCH; i++)
        {
            ids[i] = -1;
            pos[i] = {-1000.0f, -1000.0f};
        }
        
        sort_id();
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