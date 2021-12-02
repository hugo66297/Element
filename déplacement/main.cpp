#include <SFML/Graphics.hpp>
#include "deplacement.h"
#define VITESSE 125
#define FPS 60
#define LARGEUR_FEN 1280
#define HAUTEUR_FEN 928
#define SLEEP 50
#define VITESSESAUT 4
using namespace sf ;

typedef struct
{
    int x;
    int y;

} Position ;


int main()
{
    int textureFeu=0, spriteFeu=0, textureEau=0, spriteEau=0, textureTerre=0, spriteTerre=0, textureAir=0, spriteAir=0 ;
    int mooveFeu=0, mooveEau=0, mooveTerre=0, poopFeu=0, poopEau=0, poopTerre=0 ;
    float temps ;
    Clock clock;
    Time time;

    Position pFeu ;
    Position pEau ;
    Position pTerre ;
    Position pAir ;

    pFeu.x= 100;
    pFeu.y= 400;

    pEau.x= 100+60;
    pEau.y= 400+60;

    pTerre.x= 100+30;
    pTerre.y= 400+30;

    pAir.x= 100+30;
    pAir.y= 400+30;
    //FEU
    Texture feudeface1;
    feudeface1.loadFromFile("M. Feu face1.png");
    Sprite feudefacev1;
    feudefacev1.setTexture(feudeface1);

    Texture feudeface2;
    feudeface2.loadFromFile("M. Feu face2.png");
    Sprite feudefacev2;
    feudefacev2.setTexture(feudeface2);

    Texture feudeprofildroite1;
    feudeprofildroite1.loadFromFile("M. Feu droite1.png");
    Sprite feudeprofildroitev1;
    feudeprofildroitev1.setTexture(feudeprofildroite1);

    Texture feudeprofildroite2;
    feudeprofildroite2.loadFromFile("M. Feu droite2.png");
    Sprite feudeprofildroitev2;
    feudeprofildroitev2.setTexture(feudeprofildroite2);

    Texture feudeprofildroite3;
    feudeprofildroite3.loadFromFile("M. Feu droite3.png");
    Sprite feudeprofildroitev3;
    feudeprofildroitev3.setTexture(feudeprofildroite3);

    Texture feudeprofilgauche1;
    feudeprofilgauche1.loadFromFile("M. Feu gauche1.png");
    Sprite feudeprofilgauchev1;
    feudeprofilgauchev1.setTexture(feudeprofilgauche1);

    Texture feudeprofilgauche2;
    feudeprofilgauche2.loadFromFile("M. Feu gauche2.png");
    Sprite feudeprofilgauchev2;
    feudeprofilgauchev2.setTexture(feudeprofilgauche2);

    Texture feudeprofilgauche3;
    feudeprofilgauche3.loadFromFile("M. Feu gauche3.png");
    Sprite feudeprofilgauchev3;
    feudeprofilgauchev3.setTexture(feudeprofilgauche3);
    //EAU
    Texture eaudeface1;
    eaudeface1.loadFromFile("M. Eau face1.png");
    Sprite eaudefacev1;
    eaudefacev1.setTexture(eaudeface1);

    Texture eaudeface2;
    eaudeface2.loadFromFile("M. Eau face2.png");
    Sprite eaudefacev2;
    eaudefacev2.setTexture(eaudeface2);

    Texture eaudeprofildroite1;
    eaudeprofildroite1.loadFromFile("M. Eau droite1.png");
    Sprite eaudeprofildroitev1;
    eaudeprofildroitev1.setTexture(eaudeprofildroite1);

    Texture eaudeprofildroite2;
    eaudeprofildroite2.loadFromFile("M. Eau droite2.png");
    Sprite eaudeprofildroitev2;
    eaudeprofildroitev2.setTexture(eaudeprofildroite2);

    Texture eaudeprofildroite3;
    eaudeprofildroite3.loadFromFile("M. Eau droite3.png");
    Sprite eaudeprofildroitev3;
    eaudeprofildroitev3.setTexture(eaudeprofildroite3);

    Texture eaudeprofilgauche1;
    eaudeprofilgauche1.loadFromFile("M. Eau gauche1.png");
    Sprite eaudeprofilgauchev1;
    eaudeprofilgauchev1.setTexture(eaudeprofilgauche1);

    Texture eaudeprofilgauche2;
    eaudeprofilgauche2.loadFromFile("M. Eau gauche2.png");
    Sprite eaudeprofilgauchev2;
    eaudeprofilgauchev2.setTexture(eaudeprofilgauche2);

    Texture eaudeprofilgauche3;
    eaudeprofilgauche3.loadFromFile("M. Eau gauche3.png");
    Sprite eaudeprofilgauchev3;
    eaudeprofilgauchev3.setTexture(eaudeprofilgauche3);
    //TERRE
    Texture terredeface1;
    terredeface1.loadFromFile("M. Terre face1.png");
    Sprite terredefacev1;
    terredefacev1.setTexture(terredeface1);

    Texture terredeface2;
    terredeface2.loadFromFile("M. Terre face2.png");
    Sprite terredefacev2;
    terredefacev2.setTexture(terredeface2);

    Texture terredeprofildroite1;
    terredeprofildroite1.loadFromFile("M. Terre droite1.png");
    Sprite terredeprofildroitev1;
    terredeprofildroitev1.setTexture(terredeprofildroite1);

    Texture terredeprofildroite2;
    terredeprofildroite2.loadFromFile("M. Terre droite2.png");
    Sprite terredeprofildroitev2;
    terredeprofildroitev2.setTexture(terredeprofildroite2);

    Texture terredeprofildroite3;
    terredeprofildroite3.loadFromFile("M. Terre droite3.png");
    Sprite terredeprofildroitev3;
    terredeprofildroitev3.setTexture(terredeprofildroite3);

    Texture terredeprofilgauche1;
    terredeprofilgauche1.loadFromFile("M. Terre gauche1.png");
    Sprite terredeprofilgauchev1;
    terredeprofilgauchev1.setTexture(terredeprofilgauche1);

    Texture terredeprofilgauche2;
    terredeprofilgauche2.loadFromFile("M. Terre gauche2.png");
    Sprite terredeprofilgauchev2;
    terredeprofilgauchev2.setTexture(terredeprofilgauche2);

    Texture terredeprofilgauche3;
    terredeprofilgauche3.loadFromFile("M. Terre gauche3.png");
    Sprite terredeprofilgauchev3;
    terredeprofilgauchev3.setTexture(terredeprofilgauche3);
    //AIR
    Texture airdeface1;
    airdeface1.loadFromFile("M. Air face1.png");
    Sprite airdefacev1;
    airdefacev1.setTexture(airdeface1);

    Texture airdeface2;
    airdeface2.loadFromFile("M. Air face2.png");
    Sprite airdefacev2;
    airdefacev2.setTexture(airdeface2);

    Texture airdeprofildroite1;
    airdeprofildroite1.loadFromFile("M. Air droite1.png");
    Sprite airdeprofildroitev1;
    airdeprofildroitev1.setTexture(airdeprofildroite1);

    Texture airdeprofilgauche1;
    airdeprofilgauche1.loadFromFile("M. Air gauche1.png");
    Sprite airdeprofilgauchev1;
    airdeprofilgauchev1.setTexture(airdeprofilgauche1);
    //FIN
    RenderWindow fenetre(VideoMode(LARGEUR_FEN, HAUTEUR_FEN), "deplacement");
    fenetre.setFramerateLimit(FPS);
    fenetre.clear(Color::White);

    //pour le saut
    bool gravFeu = false ;
    bool gravEau = false ;
    bool gravTerre = false;
    bool gravAir = false ;
    bool gravAir2 = false ;
    bool descenteFeu =false;
    bool descenteEau =false;
    bool descenteTerre =false;
    bool descenteAir =false;
    bool descenteAir2 =false;
    int graviteFeu=0 ;
    int graviteEau=0 ;
    int graviteTerre=0 ;
    int graviteAir=0 ;
    int graviteAir2 =1;


    while (fenetre.isOpen())
    {
        Event event ;
        while (fenetre.pollEvent(event))
        {
            if (event.type == Event::Closed)
                fenetre.close();

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                fenetre.close();

        }//here
        if (Keyboard::isKeyPressed(Keyboard::Left)) // Fleche gauche appuyee
        {
            pFeu.x -= (VITESSE+FPS)*temps;
            textureFeu=1;

        }

        else if (Keyboard::isKeyPressed(Keyboard::Right)) // Fleche droite appuyee
        {
            pFeu.x+= (VITESSE+FPS)*temps;
            textureFeu=2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))//Fleche haut appuyee
            gravFeu=true;
        if (Keyboard::isKeyPressed(Keyboard::Q)) // touche Q appuyee
        {
            pEau.x-=(VITESSE+FPS)*temps;
            textureEau=1;
        }

        else if (Keyboard::isKeyPressed(Keyboard::D)) // touche D appuyee
        {
            pEau.x+=(VITESSE+FPS)*temps;
            textureEau=2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Z))//touche Z appuyee
            gravEau=true ;
        if (Keyboard::isKeyPressed(Keyboard::J)) // touche J appuyee
        {
            pTerre.x-=(VITESSE+FPS)*temps;
            textureTerre=1;
        }

        else if (Keyboard::isKeyPressed(Keyboard::L)) // touche L appuyee
        {
            pTerre.x+=(VITESSE+FPS)*temps;
            textureTerre=2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))//touche I appuyee
            gravTerre=true ;
        if (Keyboard::isKeyPressed(Keyboard::Num4)) // touche 4 appuyee
        {
            pAir.x-=(VITESSE+FPS)*temps;
            textureAir=1;
        }

        else if (Keyboard::isKeyPressed(Keyboard::Num6)) // touche 6 appuyee
        {
            pAir.x+= (VITESSE+FPS)*temps;
            textureAir=2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num8))//touche 8 appuyee
            gravAir=true;

        if (Keyboard::isKeyPressed(Keyboard::Num5))//double saut
            gravAir2=true;

        if (gravFeu==true)
        {
            pFeu.y-=VITESSESAUT;
            graviteFeu+=1;
        }
        if (graviteFeu==25)
        {
            descenteFeu=true;
            gravFeu=false;
        }
        if (descenteFeu==true)
        {
            pFeu.y+=VITESSESAUT;
            gravFeu=false;
            graviteFeu-=1;
        }
        if (graviteFeu==0)
            descenteFeu=false;

        if (gravEau==true)
        {
            pEau.y-=VITESSESAUT;
            graviteEau+=1;
        }
        if (graviteEau==25)
        {
            descenteEau=true;
            gravEau=false;
        }
        if (descenteEau==true)
        {
            pEau.y+=VITESSESAUT;
            gravEau=false;
            graviteEau-=1;
        }
        if (graviteEau==0)
            descenteEau=false;

        if (gravTerre==true)
        {
            pTerre.y-=VITESSESAUT;
            graviteTerre+=1;
        }
        if (graviteTerre==25)
        {
            descenteTerre=true;
            gravTerre=false;
        }
        if (descenteTerre==true)
        {
            pTerre.y+=VITESSESAUT;
            gravTerre=false;
            graviteTerre-=1;
        }
        if (graviteTerre==0)
            descenteTerre=false;

        if (gravAir==true)
        {
            pAir.y-=VITESSESAUT;
            graviteAir+=1;
        }
        if (graviteAir==25)
        {
            descenteAir=true;
            gravAir=false;
        }
        if (descenteAir==true)
        {
            pAir.y+=VITESSESAUT;
            gravAir=false;
            graviteAir-=1;
        }
        if (graviteAir==0)
            descenteAir=false;
            //chacal
        if (gravAir2==true)
        {
            pAir.y-=VITESSESAUT;
            graviteAir2+=1;
        }
        if (graviteAir2==50)
        {
            descenteAir2=true;
            gravAir2=false;
        }
        if (descenteAir2==true)
        {
            pAir.y+=VITESSESAUT;
            gravAir2=false;
            graviteAir2-=1;
        }
        if (graviteAir2==0)
            descenteAir2=false;


        time = clock.restart();
        temps = time.asSeconds();


        feudefacev1.setPosition(pFeu.x, pFeu.y);
        feudefacev2.setPosition(pFeu.x, pFeu.y);
        feudeprofildroitev1.setPosition(pFeu.x, pFeu.y);
        feudeprofildroitev2.setPosition(pFeu.x, pFeu.y);
        feudeprofildroitev3.setPosition(pFeu.x, pFeu.y);
        feudeprofilgauchev1.setPosition(pFeu.x, pFeu.y);
        feudeprofilgauchev2.setPosition(pFeu.x, pFeu.y);
        feudeprofilgauchev3.setPosition(pFeu.x, pFeu.y);

        eaudefacev1.setPosition(pEau.x, pEau.y);
        eaudefacev2.setPosition(pEau.x, pEau.y);
        eaudeprofildroitev1.setPosition(pEau.x, pEau.y);
        eaudeprofildroitev2.setPosition(pEau.x, pEau.y);
        eaudeprofildroitev3.setPosition(pEau.x, pEau.y);
        eaudeprofilgauchev1.setPosition(pEau.x, pEau.y);
        eaudeprofilgauchev2.setPosition(pEau.x, pEau.y);
        eaudeprofilgauchev3.setPosition(pEau.x, pEau.y);

        terredefacev1.setPosition(pTerre.x, pTerre.y);
        terredefacev2.setPosition(pTerre.x, pTerre.y);
        terredeprofildroitev1.setPosition(pTerre.x, pTerre.y);
        terredeprofildroitev2.setPosition(pTerre.x, pTerre.y);
        terredeprofildroitev3.setPosition(pTerre.x, pTerre.y);
        terredeprofilgauchev1.setPosition(pTerre.x, pTerre.y);
        terredeprofilgauchev2.setPosition(pTerre.x, pTerre.y);
        terredeprofilgauchev3.setPosition(pTerre.x, pTerre.y);

        airdefacev1.setPosition(pAir.x, pAir.y);
        airdefacev2.setPosition(pAir.x, pAir.y);
        airdeprofildroitev1.setPosition(pAir.x, pAir.y);
        airdeprofilgauchev1.setPosition(pAir.x, pAir.y);

        fenetre.clear(Color::White);

        if (textureFeu==0&&spriteFeu<6)//arret1 feu
        {
            fenetre.draw(feudefacev1);
            spriteFeu+=1;
        }
        else if (textureFeu==0&&spriteFeu==6)//arret2 feu
        {
            fenetre.draw(feudefacev2);
            spriteFeu=0;
        }

        else if (textureFeu==1&&mooveFeu==0)//gauche1 feu
        {
            fenetre.draw(feudeprofilgauchev1);
            textureFeu=0;
            mooveFeu=1;
            poopFeu=1;
        }
        else if (textureFeu==1&&mooveFeu==1)//gauche2 feu
        {
            fenetre.draw(feudeprofilgauchev2);
            if (poopFeu==1)
                mooveFeu=2;
            else
                mooveFeu=0;
            textureFeu=0;
        }
        else if (textureFeu==1&&mooveFeu==2)//gauche3 feu
        {
            fenetre.draw(feudeprofilgauchev3);
            textureFeu=0;
            mooveFeu=1;
            poopFeu=2;
        }
        else if (textureFeu==2&&mooveFeu==0)//droite1 feu
        {
            fenetre.draw(feudeprofildroitev1);
            textureFeu=0;
            mooveFeu=1;
            poopFeu=1;
        }
        else if (textureFeu==2&&mooveFeu==1)//droite2 feu
        {
            fenetre.draw(feudeprofildroitev2);
            if (poopFeu==1)
                mooveFeu=2;
            else
                mooveFeu=0;
            textureFeu=0;
        }
        else if (textureFeu==2&&mooveFeu==2)//droite3 feu
        {
            fenetre.draw(feudeprofildroitev3);
            textureFeu=0;
            mooveFeu=1;
            poopFeu=2;
        }
        if (textureTerre==0&&spriteTerre<6)//arret1 terre
        {
            fenetre.draw(terredefacev1);
            spriteTerre+=1;
        }
        else if (textureTerre==0&&spriteTerre==6)//arret2 terre
        {
            fenetre.draw(terredefacev2);
            spriteTerre=0;
        }
        else if (textureTerre==1&&mooveTerre==0)//gauche1 terre
        {
            fenetre.draw(terredeprofilgauchev1);
            textureTerre=0;
            mooveTerre=1;
            poopTerre=1;
        }
        else if (textureTerre==1&&mooveTerre==1)//gauche2 terre
        {
            fenetre.draw(terredeprofilgauchev2);
            if (poopTerre==1)
                mooveTerre=2;
            else
                mooveTerre=0;
            textureTerre=0;
        }
        else if (textureTerre==1&&mooveTerre==2)//gauche3 terre
        {
            fenetre.draw(terredeprofilgauchev3);
            textureTerre=0;
            mooveTerre=1;
            poopTerre=2;
        }
        else if (textureTerre==2&&mooveTerre==0)//droite1 terre
        {
            fenetre.draw(terredeprofildroitev1);
            textureTerre=0;
            mooveTerre=1;
            poopTerre=1;
        }
        else if (textureTerre==2&&mooveTerre==1)//droite2 terre
        {
            fenetre.draw(terredeprofildroitev2);
            if (poopTerre==1)
                mooveTerre=2;
            else
                mooveTerre=0;
            textureTerre=0;
        }
        else if (textureTerre==2&&mooveTerre==2)//droite3 terre
        {
            fenetre.draw(terredeprofildroitev3);
            textureTerre=0;
            mooveTerre=1;
            poopTerre=2;
        }

        if (textureAir==0&&spriteAir<6)//arret1 air
        {
            fenetre.draw(airdefacev1);
            spriteAir+=1;
        }
        else if (textureAir==0&&spriteAir==6)//arret2 air
        {
            fenetre.draw(airdefacev2);
            spriteAir=0;
        }
        else if (textureAir==1)//gauche air
        {
            fenetre.draw(airdeprofilgauchev1);
            textureAir=0;
        }
        else if (textureAir==2)//droite air
        {
            fenetre.draw(airdeprofildroitev1);
            textureAir=0;
        }

        if (textureEau==0&&spriteEau<6)//arret1 eau
        {
            fenetre.draw(eaudefacev1);
            spriteEau+=1;
        }
        else if (textureEau==0&&spriteEau==6)//arret2 eau
        {
            fenetre.draw(eaudefacev2);
            spriteEau=0;
        }
        else if (textureEau==1&&mooveEau==0)//gauche1 eau
        {
            fenetre.draw(eaudeprofilgauchev1);
            textureEau=0;
            mooveEau=1;
            poopEau=1;
        }
        else if (textureEau==1&&mooveEau==1)//gauche2 eau
        {
            fenetre.draw(eaudeprofilgauchev2);
            if (poopEau==1)
                mooveEau=2;
            else
                mooveEau=0;
            textureEau=0;
        }
        else if (textureEau==1&&mooveEau==2)//gauche3 eau
        {
            fenetre.draw(eaudeprofilgauchev3);
            textureEau=0;
            mooveEau=1;
            poopEau=2;
        }
        else if (textureEau==2&&mooveEau==0)//droite1 eau
        {
            fenetre.draw(eaudeprofildroitev1);
            textureEau=0;
            mooveEau=1;
            poopEau=2;
        }
        else if (textureEau==2&&mooveEau==1)//droite2 eau
        {
            fenetre.draw(eaudeprofildroitev2);
            if (poopEau==1)
                mooveEau=2;
            else
                mooveEau=0;
            textureEau=0;
        }
        else if (textureEau==2&&mooveEau==2)//droite3 eau
        {
            fenetre.draw(eaudeprofildroitev3);
            textureEau=0;
            mooveEau=1;
            poopEau=2;
        }
        fenetre.display();
    }
    return 0;
}
