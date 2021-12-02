#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "scene2.hpp"
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 928
#define LARGEUR_BOUTON 150
#define HAUTEUR_BOUTON 75
#define VOLUME 30
using namespace sf;

int main()
{
    //son clic
    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("sons/clic.wav"))
        printf("exit failure");

    Sound effetClic;
    effetClic.setBuffer(buffer2);
    effetClic.setVolume(VOLUME-5);



    //musique départ
    Music music;
    if (!music.openFromFile("sons/musique menu.wav"))
        printf("exit failure"); // erreur
    music.play();
    music.setVolume(VOLUME);
    music.setLoop(true);





    // Create the main window
    RenderWindow app( VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "SFML window");

    Texture texture;
    if (!texture.loadFromFile("bouttonJouer.png"))
        printf("exit failure");
    Sprite jouer1(texture);

    jouer1.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    jouer1.setPosition(LARGEUR_FENETRE/4,HAUTEUR_FENETRE/1.6);


    Texture texture2;
    if (!texture2.loadFromFile("bouttonJouer2.png"))
        printf("exit failure");
    Sprite jouer2(texture2);

    jouer2.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    jouer2.setPosition(-2000,-2000);

    Texture texture3;
    if (!texture3.loadFromFile("bouttonQuitter.png"))
        printf("exit failure");
    Sprite quitter1(texture3);

    quitter1.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    quitter1.setPosition(LARGEUR_FENETRE/4,HAUTEUR_FENETRE/1.2);

    Texture texture4;
    if (!texture4.loadFromFile("bouttonQuitter2.png"))
        printf("exit failure");
    Sprite quitter2(texture4);

    quitter2.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    quitter2.setPosition(-2000,-2000);

    Texture AP;
    if (!AP.loadFromFile("menuBackground2.png"))
        printf("exit failure");
    Sprite arrierePlan(AP);

    Texture btCmd;
    if (!btCmd.loadFromFile("btcommade.png"))
        printf("exit failure");
    Sprite btCommandes(btCmd);

    btCommandes.setPosition(-2000,-2000);





    // Start the game loop
    while (app.isOpen())
    {
        //éclairage bouton jouer

        Vector2i position = Mouse::getPosition(app);

        if(position.x <= LARGEUR_FENETRE/4+LARGEUR_BOUTON && position.x >= LARGEUR_FENETRE/4-LARGEUR_BOUTON && position.y <= HAUTEUR_FENETRE/1.6+75 && position.y>= HAUTEUR_FENETRE/1.6-75)
            jouer2.setPosition(LARGEUR_FENETRE/4,HAUTEUR_FENETRE/1.6);
        else
            jouer2.setPosition(-500,-500);

        //éclairage boutton quitter

        if(position.x <= LARGEUR_FENETRE/4+LARGEUR_BOUTON && position.x >= LARGEUR_FENETRE/4-LARGEUR_BOUTON && position.y <= HAUTEUR_FENETRE/1.2+75 && position.y>= HAUTEUR_FENETRE/1.2-75)
            quitter2.setPosition(LARGEUR_FENETRE/4,HAUTEUR_FENETRE/1.2);
        else
            quitter2.setPosition(-500,-500);


        if(position.x <= 1260  && position.x >= 1068 && position.y <= 908 && position.y>= 812)
            btCommandes.setPosition(1068,812);
        else
            btCommandes.setPosition(-500,-500);



        // Process events
        Event event;

        while (app.pollEvent(event))
        {

            // Close window : exit
            if (event.type ==  Event::Closed)
                app.close();
            // jouer : aller au menu suivant.
            if (position.x <= LARGEUR_FENETRE/4+LARGEUR_BOUTON && position.x >= LARGEUR_FENETRE/4-LARGEUR_BOUTON && position.y <= HAUTEUR_FENETRE/1.6+75 && position.y>= HAUTEUR_FENETRE/1.6-75 && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                music.stop();
                app.close();
                sceneSuivante();
            }
            if (position.x <= LARGEUR_FENETRE/4+LARGEUR_BOUTON && position.x >= LARGEUR_FENETRE/4-LARGEUR_BOUTON && position.y <= HAUTEUR_FENETRE/1.2+75 && position.y>= HAUTEUR_FENETRE/1.2-75 && Mouse::isButtonPressed(Mouse::Left))
            {
                music.stop();
                effetClic.play();
                printf("quitter\n");
                app.close();
            }
            if(position.x <= 1260  && position.x >= 1068 && position.y <= 908 && position.y>= 812 && Mouse::isButtonPressed(Mouse::Left))
            {

                effetClic.play();
                app.close();
                sceneCommande();
            }



        }



        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(arrierePlan);
        app.draw(jouer1);
        app.draw(jouer2);
        app.draw(quitter1);
        app.draw(quitter2);
        app.draw(btCommandes);


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
