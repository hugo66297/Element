#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "scene2.hpp"
using namespace sf;

void son()
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("sons/soudMouseEnter.wav"))
        printf("exit failure");

    Sound effetSelec;
    effetSelec.setBuffer(buffer);

    for(int i=0; i<2;i++)
    {
        effetSelec.play();
        printf("test");
    }
    effetSelec.pause();

}
