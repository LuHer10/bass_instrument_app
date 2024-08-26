#include "raylib.h"
#include "note.h"
#include "samplefiles.h"

class Synth
{
public:

    Note samps[NUM_S];

    double attack, sustain, release;

    //double vol[NUM_S];

    void init();
    void set_envelope(double a, double s, double r);
    void envelope()
    {
        for(int i = 0; i < NUM_S; i++)
        {
            samps[i].envelope();
        }
    }
    void play();
    void stop();
};

void Synth::init()
{
    for(int i = 0; i < NUM_S; i++)
    {
        samps[i].init(files[i]);
    }
}

void Synth::set_envelope(double a, double s, double r)
{
    attack = a;
    sustain = s;
    release = r;
    for(int i = 0; i < NUM_S; i++)
    {
        samps[i].setEnvelope(attack, sustain, release);
    }
}

void Synth::play()
{
    
}

void Synth::stop()
{
    
}