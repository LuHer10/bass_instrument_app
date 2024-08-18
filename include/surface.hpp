#include "button.hpp"

class Surface
{
public:
    Button sustain_l, sustain_r;
    Button sust_switch_l, sust_switch_r;
    Button repeat_l, repeat_r;
    Button rep2_l, rep2_r;
    Button mute_l, mute_r;

    bool sustain_l_state, sustain_r_state;
    bool sust_switch_l_state, sust_switch_r_state;
    bool repeat_l_state, repeat_r_state;
    bool rep2_l_state, rep2_r_state;
    bool mute_l_state, mute_r_state;

    bool sustain_on;
    bool mute_on;

    int rows, cols;

public:
    void init(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols + 2;
        int width = GetScreenWidth();
        int height = GetScreenHeight();
        //left side
        sustain_l.init(0, 4*height/5, width/cols, height/5, RED);
        sust_switch_l.init(0, 3 *height/5, width/cols, height/5, ORANGE);
        mute_l.init(0, 2*height/5, width/cols, height/5, BROWN);
        repeat_l.init(0, height/5, width/cols, height/5, YELLOW);
        rep2_l.init(0, 0, width/cols, height/5, GRAY);

        //right side
        sustain_r.init(width - width/cols, 4*height/5, width/cols, height/5, RED);
        sust_switch_r.init(width - width/cols, 3 *height/5, width/cols, height/5, ORANGE);
        mute_r.init(width - width/cols, 2*height/5, width/cols, height/5, BROWN);
        repeat_r.init(width - width/cols, height/5, width/cols, height/5, YELLOW);
        rep2_r.init(width - width/cols, 0, width/cols, height/5, GRAY);
    }

    void draw()
    {

        //left side
        sustain_l.draw();
        sust_switch_l.draw();
        mute_l.draw();
        repeat_l.draw();
        rep2_l.draw();

        //right side
        sustain_r.draw();
        sust_switch_r.draw();
        mute_r.draw();
        repeat_r.draw();
        rep2_r.draw();

    }

    void pressed()
    {
        update();
        //left side
        sustain_l.pressed();
        sust_switch_l.pressed();
        mute_l.pressed();
        repeat_l.pressed();
        rep2_l.pressed();

        //right side
        sustain_r.pressed();
        sust_switch_r.pressed();
        mute_r.pressed();
        repeat_r.pressed();
        rep2_r.pressed();
    }

    void up_flanks()
    {

    }
};