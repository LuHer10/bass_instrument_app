#include "raylib.h"
#include <math.h>

class Note
{
public:
    Sound sound;

    double volume = 0;
    bool noteOn = 0;
    bool preOn = 0;

    double attack, sustain, release;

    void init(const char * path)
    {
        sound = LoadSound(path);
    }

    void play(float semis);
    void stop();

    float semisToSpeed(float semis)
    {
        return pow(2, semis/12);
    }

    void setEnvelope(double _attack, double _sustain, double _release);

    void envelope(){
        float dt = GetFrameTime();
        if(noteOn && (noteOn != preOn))
        {
            volume = 0;
            PlaySound(sound);
        }
        if(noteOn)
        {
            volume += (dt)*sustain/attack;
            if(volume > 1.0f) volume = 1.0;
            SetSoundVolume(sound, volume);
            preOn = noteOn;
            return;
        }
        const double maxVol = volume;
        volume -= (dt)*maxVol/release;
        if(volume < 0){
            volume = 0;
            if(IsSoundPlaying(sound))
            {
                StopSound(sound);
            }
        }
        SetSoundVolume(sound, volume);
        preOn = noteOn;
        
    }
};

void Note::setEnvelope(double _attack, double _sustain, double _release)
{
    attack = _attack;
    sustain = _sustain;
    release = _release;
}

void Note::play(float semis)
{

    SetSoundPitch(sound, semisToSpeed(semis));
    noteOn = 1;
}

void Note::stop()
{
    noteOn = 0;
}