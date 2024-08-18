
#include "touch.hpp"

class Button
{
private:
    int x, y;
    int width, height;
    Color color, r_color, p_color;
    char label;
    bool state, preState;
public:
    Button(){}
    void init(int _x, int _y, int _width, int _height, Color _color/*, char _label*/)
    {
        x = _x;
        y = _y;
        width = _width;
        height = _height;
        color = _color;
        r_color = color;
        p_color = color;
        p_color.r = color.r - 20;
        p_color.g = color.g - 20;
        p_color.b = color.b - 20;
        //label = _label;
    }

    void draw();
    bool pressed();
    bool getState(){return state;}
    bool up_flank()
    {
        if(state && (state != preState))
        {
            preState = state;
            return true;
        }
        preState = state;
        return false;
    }
    bool dn_flank()
    {
        if(!state && (state != preState))
        {
            preState = state;
            return true;
        }
        preState = state;
        return false;
    }
};

void update(){touch.updatePress();}

void Button::draw()
{
    DrawRectangle(x, y, width, height, color);
}


bool Button::pressed()
{
    bool cond;
    //touch.updatePress();
    for(int i = 0; i < MAX_TOUCH; i++)
    {
        int touch_x = touch.pos[i].x;
        int touch_y = touch.pos[i].y;
        cond = (touch_x > x) && (touch_x < x + width) && 
                    (touch_y > y) && (touch_y < y + height);
        if(cond) break;
        
    }

    if(cond)
        {
            color = p_color;
            state = 1;
            return 1;
        }
        color = r_color;
        return 0;
    
}

