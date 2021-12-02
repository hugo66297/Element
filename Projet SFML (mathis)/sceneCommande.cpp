#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "scene2.hpp"
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 928
#define VOLUME 10

using namespace sf;

void sceneCommande()
{

    RenderWindow com( VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "SFML window");

    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("sons/clic.wav"))
        printf("exit failure");

    Sound effetClic;
    effetClic.setBuffer(buffer2);
    effetClic.setVolume(VOLUME-5);



    Texture commandes;
    if (!commandes.loadFromFile("commandes.png"))
        printf("exit failure");
    Sprite bgCommandes(commandes);

    Texture btReturn;
    if (!btReturn.loadFromFile("boutons/btRetourCom.png"))
        printf("exit failure");
    Sprite btRtn(btReturn);


    while (com.isOpen())
    {
        Vector2i position = Mouse::getPosition(com);

        if(position.x <= 116  && position.x >= 36 && position.y <= 872 && position.y>= 792)
            btRtn.setPosition(36,792);
        else
            btRtn.setPosition(-500,-500);

        // Process events
        Event event;
        while (com.pollEvent(event))
        {
            if(position.x <= 116  && position.x >= 36 && position.y <= 872 && position.y>= 792 && Mouse::isButtonPressed(Mouse::Left))
            {
                effetClic.play();
                com.close();
                main();
            }

            // Close window : exit
            if (event.type ==  Event::Closed)
                com.close();
        }

        // Clear screen
        com.clear();

        // Draw the sprite

        com.draw(bgCommandes);
        com.draw(btRtn);

        // Update the window
        com.display();
    }


}
