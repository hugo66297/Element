#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "scene2.hpp"
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 928
#define LARGEUR_BOUTON 92
#define HAUTEUR_BOUTON 58
#define RAYON_BOUTON_RETOUR 41
#define VOLUME 10

using namespace sf;





void sceneSuivante()
{
    int son = 0;
    bool win1= false ;
    bool win2= false ;
    bool win3= false ;
    bool win4= false ;
    bool win5= false ;
    bool win6= false ;

    // Create the main window
    RenderWindow scene2( VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "SFML window");

    // Load a sprite to display

    //arrière plan
    Texture bgNiv;
    if (!bgNiv.loadFromFile("selectionNiveaux.png"))
        printf("exit failure");
    Sprite bgNiveau(bgNiv);

    //case niveau1
    Texture btNiv1;
    if (!btNiv1.loadFromFile("niveaux/BoutonNivo1.png"))
        printf("exit failure");
    Sprite btNivo1(btNiv1);
    btNivo1.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo1.setPosition(-2000,-2000);

    Texture btNiv2;
    if (!btNiv2.loadFromFile("niveaux/BoutonNivo2.png"))
        printf("exit failure");
    Sprite btNivo2(btNiv2);
    btNivo2.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo2.setPosition(-2000,-2000);

    Texture btNiv3;
    if (!btNiv3.loadFromFile("niveaux/BoutonNivo3.png"))
        printf("exit failure");
    Sprite btNivo3(btNiv3);
    btNivo3.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo3.setPosition(-2000,-2000);

    Texture btNiv4;
    if (!btNiv4.loadFromFile("niveaux/BoutonNivo4.png"))
        printf("exit failure");
    Sprite btNivo4(btNiv4);
    btNivo4.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo4.setPosition(-2000,-2000);

    Texture btNiv5;
    if (!btNiv5.loadFromFile("niveaux/BoutonNivo5.png"))
        printf("exit failure");
    Sprite btNivo5(btNiv5);
    btNivo5.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo5.setPosition(-2000,-2000);

    Texture btNiv6;
    if (!btNiv6.loadFromFile("niveaux/BoutonNivo6.png"))
        printf("exit failure");
    Sprite btNivo6(btNiv6);
    btNivo6.setOrigin(LARGEUR_BOUTON,HAUTEUR_BOUTON);
    btNivo6.setPosition(-2000,-2000);


    Texture btRetour;
    if (!btRetour.loadFromFile("boutons/btRetour2.png"))
        printf("exit failure");
    Sprite btRetour2(btRetour);
    btRetour2.setOrigin(RAYON_BOUTON_RETOUR,RAYON_BOUTON_RETOUR);
    btRetour2.setPosition(-2000,-2000);

    Font police;

    if (!police.loadFromFile("theboldfont.ttf"))
    {
        printf("exit failure");
    }


    // indication niveaux


    Text niv1;
    Text niv2;
    Text niv3;
    Text niv4;
    Text niv5;
    Text niv6;




    niv1.setFont(police);
    niv1.setString("Niveau 1");
    niv1.setCharacterSize(24);
    niv1.setPosition(-2000,-2000);

    niv2.setFont(police);
    niv2.setString("Niveau 2");
    niv2.setCharacterSize(24);
    niv2.setPosition(-2000,-2000);

    niv3.setFont(police);
    niv3.setString("Niveau 3");
    niv3.setCharacterSize(24);
    niv3.setPosition(-2000,-2000);

    niv4.setFont(police);
    niv4.setString("Niveau 4");
    niv4.setCharacterSize(24);
    niv4.setPosition(-2000,-2000);

    niv5.setFont(police);
    niv5.setString("Niveau 5");
    niv5.setCharacterSize(24);
    niv5.setPosition(-2000,-2000);

    niv6.setFont(police);
    niv6.setString("Niveau 6");
    niv6.setCharacterSize(24);
    niv6.setPosition(-2000,-2000);

    //initialisation sons

    SoundBuffer buffer,buffer2;

    if (!buffer.loadFromFile("sons/soudMouseEnter.wav"))
        printf("exit failure");

    Sound effetSelec;
    effetSelec.setBuffer(buffer);
    effetSelec.setLoop(false);
    effetSelec.setVolume(VOLUME);



    if (!buffer2.loadFromFile("sons/clic.wav"))
        printf("exit failure");

    Sound effetClic;
    effetClic.setBuffer(buffer2);
    effetClic.setVolume(VOLUME-5);





    // Start the game loop
    while (scene2.isOpen())
    {



        Vector2i position = Mouse::getPosition(scene2);







        if(position.x <= 998 +LARGEUR_BOUTON && position.x >= 998 -LARGEUR_BOUTON && position.y >= 663+HAUTEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON+2 || position.x <= 998 +LARGEUR_BOUTON && position.x >= 998 -LARGEUR_BOUTON && position.y >= 663-HAUTEUR_BOUTON && position.y <= 663-HAUTEUR_BOUTON+2 || position.x <= 998 -LARGEUR_BOUTON +2 && position.x >= 998 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON || position.x <= 998 +LARGEUR_BOUTON +2 && position.x >= 998 +LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }

        if(position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y >= 663+HAUTEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON+2 || position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y >= 663-HAUTEUR_BOUTON && position.y <= 663-HAUTEUR_BOUTON+2 || position.x <= 632 -LARGEUR_BOUTON +2 && position.x >= 632 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON || position.x <= 632 +LARGEUR_BOUTON +2 && position.x >= 632 +LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }

        if(position.x <= 266 +LARGEUR_BOUTON && position.x >= 266 -LARGEUR_BOUTON && position.y >= 663+HAUTEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON+2 || position.x <= 266 +LARGEUR_BOUTON && position.x >= 266 -LARGEUR_BOUTON && position.y >= 663-HAUTEUR_BOUTON && position.y <= 663-HAUTEUR_BOUTON+2 || position.x <= 266 -LARGEUR_BOUTON +2 && position.x >= 266 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON || position.x <= 266 +LARGEUR_BOUTON +2 && position.x >= 266 +LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }

        if(position.x <= 815 +LARGEUR_BOUTON && position.x >= 815 -LARGEUR_BOUTON && position.y >= 426+HAUTEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON+2 || position.x <= 815 +LARGEUR_BOUTON && position.x >= 815 -LARGEUR_BOUTON && position.y >= 426-HAUTEUR_BOUTON && position.y <= 426-HAUTEUR_BOUTON+2 || position.x <= 815 -LARGEUR_BOUTON +2 && position.x >= 815 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON || position.x <= 815 +LARGEUR_BOUTON +2 && position.x >= 815 +LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }

        if(position.x <= 449 +LARGEUR_BOUTON && position.x >= 449 -LARGEUR_BOUTON && position.y >= 426+HAUTEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON+2 || position.x <= 449 +LARGEUR_BOUTON && position.x >= 449 -LARGEUR_BOUTON && position.y >= 426-HAUTEUR_BOUTON && position.y <= 426-HAUTEUR_BOUTON+2 || position.x <= 449 -LARGEUR_BOUTON +2 && position.x >= 449 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON || position.x <= 449 +LARGEUR_BOUTON +2 && position.x >= 449 +LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }

        if(position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y >= 212+HAUTEUR_BOUTON && position.y <= 212+HAUTEUR_BOUTON+2 || position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y >= 212-HAUTEUR_BOUTON && position.y <= 212-HAUTEUR_BOUTON+2 || position.x <= 632 -LARGEUR_BOUTON +2 && position.x >= 632 -LARGEUR_BOUTON && position.y <= 212+HAUTEUR_BOUTON && position.y>= 212-HAUTEUR_BOUTON || position.x <= 632 +LARGEUR_BOUTON +2 && position.x >= 632 +LARGEUR_BOUTON && position.y <= 212+HAUTEUR_BOUTON && position.y>= 212-HAUTEUR_BOUTON  )

        {
            effetSelec.play();
            //printf("zone\n");
        }







        //NIVEAU 1
        if(position.x <= 998 +LARGEUR_BOUTON && position.x >= 998 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON )
        {
            btNivo1.setPosition(998,663);
            niv1.setPosition(950,570);

        }
        else
        {
            niv1.setPosition(-2000,-2000);
            btNivo1.setPosition(-2000,-2000);
        }

        //NIVEAU 2
        if(position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON)
        {
            btNivo2.setPosition(632,663);
            niv2.setPosition(580,570);


        }
        else
        {
            btNivo2.setPosition(-2000,-2000);
            niv2.setPosition(-2000,-2000);
        }

        //NIVEAU 3
        if(position.x <= 266 +LARGEUR_BOUTON && position.x >= 266 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON)
        {
            btNivo3.setPosition(266,663);
            niv3.setPosition(210,570);

        }
        else
        {
            btNivo3.setPosition(-2000,-2000);
            niv3.setPosition(-2000,-2000);
        }

        //NIVEAU 4
        if(position.x <= 815 +LARGEUR_BOUTON && position.x >= 815 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON)
        {
            btNivo4.setPosition(815,426);
            niv4.setPosition(765,335);


        }

        else
        {
            btNivo4.setPosition(-2000,-2000);
            niv4.setPosition(-2000,-2000);
        }

        //NIVEAU 5
        if(position.x <= 449 +LARGEUR_BOUTON && position.x >= 449 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON)
        {
            btNivo5.setPosition(449,426);
            niv5.setPosition(400,335);

        }

        else
        {
            btNivo5.setPosition(-2000,-2000);
            niv5.setPosition(-2000,-2000);
        }

        //NIVEAU 6
        if(position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y <= 212+HAUTEUR_BOUTON && position.y>= 212-HAUTEUR_BOUTON)
        {
            btNivo6.setPosition(632,212);
            niv6.setPosition(580,120);

        }

        else
        {
            btNivo6.setPosition(-2000,-2000);
            niv6.setPosition(-2000,-2000);
        }
        //Boutton rerour
        if(position.x >=87-RAYON_BOUTON_RETOUR && position.x <=  87+RAYON_BOUTON_RETOUR && position.y <= 864 +RAYON_BOUTON_RETOUR && position.y >= 864 - RAYON_BOUTON_RETOUR )
        {
            btRetour2.setPosition(87,864);
        }
        else
        {
            btRetour2.setPosition(-2000,-2000);
        }













        Event event;

        while (scene2.pollEvent(event))
        {

            // Close window : exit
            if (event.type ==  Event::Closed)
                scene2.close();
            //Niveau 1
            if (position.x <= 998 +LARGEUR_BOUTON && position.x >= 998 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                /*app.close();
                sceneSuivante();*/
            }
            //Niveau 2
            if (position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                /*app.close();
                sceneSuivante();*/
            }
            //Niveau 3
            if (position.x <= 266 +LARGEUR_BOUTON && position.x >= 266 -LARGEUR_BOUTON && position.y <= 663+HAUTEUR_BOUTON && position.y>= 663-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                /*app.close();
                sceneSuivante();*/
            }
            //Niveau 4
            if (position.x <= 815 +LARGEUR_BOUTON && position.x >= 815 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                /*app.close();
                sceneSuivante();*/
            }
            //Niveau 5
            if (position.x <= 449 +LARGEUR_BOUTON && position.x >= 449 -LARGEUR_BOUTON && position.y <= 426+HAUTEUR_BOUTON && position.y>= 426-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                scene2.close();
                niveau5(&win5);
            }
            //Niveau 6
            if (position.x <= 632 +LARGEUR_BOUTON && position.x >= 632 -LARGEUR_BOUTON && position.y <= 212+HAUTEUR_BOUTON && position.y>= 212-HAUTEUR_BOUTON && Mouse::isButtonPressed(Mouse::Left))
            {
                printf("go to level\n");
                effetClic.play();
                /*app.close();
                sceneSuivante();*/
            }
            //bouton retour
            if(position.x >=87-RAYON_BOUTON_RETOUR && position.x <=  87+RAYON_BOUTON_RETOUR && position.y <= 864 +RAYON_BOUTON_RETOUR && position.y >= 864 - RAYON_BOUTON_RETOUR && Mouse::isButtonPressed((Mouse::Left)))
            {
                effetClic.play();
                scene2.close();
                main();
            }




        }
        RectangleShape prem1(Vector2f(40,10));
        prem1.setPosition(1121,691);
        prem1.setFillColor(Color::Green);
        prem1.setRotation(45);
        RectangleShape prem2(Vector2f(10,65));
        prem2.setPosition(1150,720);
        prem2.setFillColor(Color::Green);
        prem2.setRotation(-135);

        RectangleShape deus1(Vector2f(40,10));
        deus1.setPosition(751,691);
        deus1.setFillColor(Color::Green);
        deus1.setRotation(45);
        RectangleShape deus2(Vector2f(10,65));
        deus2.setPosition(780,720);
        deus2.setFillColor(Color::Green);
        deus2.setRotation(-135);

        RectangleShape trois1(Vector2f(40,10));
        trois1.setPosition(381,691);
        trois1.setFillColor(Color::Green);
        trois1.setRotation(45);
        RectangleShape trois2(Vector2f(10,65));
        trois2.setPosition(410,720);
        trois2.setFillColor(Color::Green);
        trois2.setRotation(-135);

        RectangleShape qua1(Vector2f(40,10));
        qua1.setPosition(931,451);
        qua1.setFillColor(Color::Green);
        qua1.setRotation(45);
        RectangleShape qua2(Vector2f(10,65));
        qua2.setPosition(960,480);
        qua2.setFillColor(Color::Green);
        qua2.setRotation(-135);

        RectangleShape cin1(Vector2f(40,10));
        cin1.setPosition(561,451);
        cin1.setFillColor(Color::Green);
        cin1.setRotation(45);
        RectangleShape cin2(Vector2f(10,65));
        cin2.setPosition(590,480);
        cin2.setFillColor(Color::Green);
        cin2.setRotation(-135);

        RectangleShape si1(Vector2f(40,10));
        si1.setPosition(761,231);
        si1.setFillColor(Color::Green);
        si1.setRotation(45);
        RectangleShape si2(Vector2f(10,65));
        si2.setPosition(790,260);
        si2.setFillColor(Color::Green);
        si2.setRotation(-135);
        // Clear screen
        scene2.clear();

        // Draw the sprite
        scene2.draw(bgNiveau);
        scene2.draw(btNivo1);
        scene2.draw(btNivo2);
        scene2.draw(btNivo3);
        scene2.draw(btNivo4);
        scene2.draw(btNivo5);
        scene2.draw(btNivo6);
        scene2.draw(niv1);
        scene2.draw(niv2);
        scene2.draw(niv3);
        scene2.draw(niv4);
        scene2.draw(niv5);
        scene2.draw(niv6);
        scene2.draw(btRetour2);
        //valide
        if (win1==true)
        {
            scene2.draw(prem1);
            scene2.draw(prem2);
        }
        if (win2==true)
        {
            scene2.draw(deus1);
            scene2.draw(deus2);
        }
        if (win3==true)
        {
            scene2.draw(trois1);
            scene2.draw(trois2);
        }
        if (win4==true)
        {
            scene2.draw(qua1);
            scene2.draw(qua2);
        }
        if (win5==true)
        {
            scene2.draw(cin1);
            scene2.draw(cin2);
        }
        if (win6==true)
        {
            scene2.draw(si1);
            scene2.draw(si2);
        }

        // Update the window
        scene2.display();
    }






}
