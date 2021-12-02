#include <SFML/Graphics.hpp>
using namespace sf;
#define BLOC 32
#define NB_BLOC_LARGEUR 40
#define NB_BLOC_HAUTEUR 30
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 960
#define VITESSE 8
#define FPS 60
#define VITESSESAUT 4
typedef struct
{
    int x;
    int y;
} Position;

int main()
{
    int textureFeu=0, spriteFeu=0, textureEau=0, spriteEau=0, textureTerre=0, spriteTerre=0, textureAir=0, spriteAir=0 ;
    int mooveFeu=0, mooveEau=0, mooveTerre=0, poopFeu=0, poopEau=0, poopTerre=0 ;
    float temps ;
    Clock clock;
    Time time;

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
    //on créé la fenêtre
    RenderWindow fenetre(VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "Niveau 1");
    fenetre.setFramerateLimit(FPS);

    //on créé notre map
    int carte[NB_BLOC_HAUTEUR][NB_BLOC_LARGEUR] =
    {
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  4,  4, 4, 4, 4, 1},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 25,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 27,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 15, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  17,  17, 17, 17, 16, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 2, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 1, 1, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 1, 1, 1, 2, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 4, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 1, 1, 1, 1, 1, 2, 12, 0, 0, 0, 0, 0, 0, 14, 8, 8, 8, 8, 8, 8, 8, 8, 8, 14, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 18, 8, 8, 8, 8, 8, 8, 8, 8, 8, 18, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 17, 17, 17, 17, 17, 17, 4, 17, 17, 17, 17, 17, 17, 17, 17, 17, 4, 17, 17, 17, 17, 17, 16, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 9, 2, 12, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 5, 1, 3, 5},
        {3, 17, 17, 17, 17, 16, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 5, 1, 3, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 17, 17, 17, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 5, 1, 3, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 5, 1, 3, 5},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 5, 1, 3, 5},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,  2,  2, 2, 2, 2, 1}
    };

    //on passe le tableau à deux dimensions en un tableau à une seule dimension
    int dessin[NB_BLOC_HAUTEUR*NB_BLOC_LARGEUR];
    int numeroBloc=0;
    for (int i=0; i<NB_BLOC_HAUTEUR; i++)
    {
        for(int j=0; j<NB_BLOC_LARGEUR; j++)
        {
            dessin[numeroBloc] = carte[i][j];
            numeroBloc++;
        }
    }

    //on définit le numéro du bloc dans notre image tileset.png puis on créée le bloc image
    int positionXduBlocImage = 0;

    //on applique une texture
    Texture tileset[NB_BLOC_HAUTEUR][NB_BLOC_LARGEUR];
    if (!tileset[0][0].loadFromFile("tileset.png",IntRect(positionXduBlocImage, 0, BLOC, BLOC))) //positionBlocImage représente le bloc que l'on veut dans l'image
        printf("Erreur de chargement de l'image tileset");

    Sprite blocTileset[NB_BLOC_HAUTEUR][NB_BLOC_LARGEUR];
    for (int y=0; y<NB_BLOC_HAUTEUR; y++)
    {
        for (int x=0; x<NB_BLOC_LARGEUR; x++)
        {
            numeroBloc = (y*NB_BLOC_LARGEUR + x);
            positionXduBlocImage = dessin[numeroBloc] * BLOC;
            tileset[y][x].loadFromFile("tileset.png",IntRect(positionXduBlocImage, 0, BLOC, BLOC));
            blocTileset[y][x].setTexture(tileset[y][x]);
            blocTileset[y][x].setPosition(x*BLOC, y*BLOC);
        }
    }

    //on créé les personnage
    Position posPerso;
    posPerso.x = BLOC;
    posPerso.y = HAUTEUR_FENETRE - 3*BLOC + 4;
    RectangleShape perso(Vector2f(BLOC,2*BLOC-6));
    perso.setFillColor(Color::Blue);

    Position pFeu ;
    Position pEau ;
    Position pTerre ;
    Position pAir ;

    pFeu.x= 3*BLOC;
    pFeu.y= HAUTEUR_FENETRE-4*BLOC+5;

    pEau.x= 3*BLOC;
    pEau.y= HAUTEUR_FENETRE-6*BLOC - 5;

    pTerre.x= 5*BLOC;
    pTerre.y= HAUTEUR_FENETRE-4*BLOC;

    pAir.x= 5*BLOC;
    pAir.y= HAUTEUR_FENETRE-7*BLOC;


    //on dessine les éléments exterieurs
    RectangleShape bloc1(Vector2f(2*BLOC, 3*BLOC));
    bloc1.setFillColor(Color(207,207,207));
    bloc1.setPosition(BLOC*26, BLOC*26);


    //on dessine les portes
    RectangleShape rect1(Vector2f(BLOC, 3*BLOC));
    rect1.setFillColor(Color::Red);
    RectangleShape rect2(Vector2f(BLOC, 4*BLOC));
    rect2.setFillColor(Color(163,73,164));
    RectangleShape rect3(Vector2f(BLOC, 4*BLOC));
    rect3.setFillColor(Color::Yellow);

    //on dessine les boutons
    RectangleShape bouton1(Vector2f(BLOC, BLOC));
    bouton1.setFillColor(Color::Red);
    bouton1.setPosition(19*BLOC, 26*BLOC);
    RectangleShape bouton2(Vector2f(BLOC, BLOC));
    bouton2.setFillColor(Color(163,73,164));
    bouton2.setPosition(13*BLOC, 19*BLOC);
    RectangleShape bouton3(Vector2f(BLOC, BLOC));
    bouton3.setFillColor(Color::Yellow);
    bouton3.setPosition(23*BLOC, 8*BLOC);

    Position avant;
    Position avantFeu;
    Position avantEau;
    Position avantTerre;
    Position avantAir;

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

    //début du jeu
    while (fenetre.isOpen())
    {

        Position porte1;
        porte1.x = 14*BLOC;
        porte1.y = 26 * BLOC;
        Position porte2;
        porte2.x = 21*BLOC;
        porte2.y = 11*BLOC;
        Position porte3;
        porte3.x = 19*BLOC;
        porte3.y =6*BLOC;

        Event event;
        while (fenetre.pollEvent(event))
        {

            //fermer la fenetre
            switch (event.type)
            {
            case Event::Closed:
                fenetre.close();
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                fenetre.close();

        }
            //ancienne position
            avant.x = posPerso.x;
            avant.y = posPerso.y;
            avantFeu.x = pFeu.x;
            avantFeu.y = pFeu.y;
            avantEau.x = pEau.x;
            avantEau.y = pEau.y;
            avantTerre.x = pTerre.x;
            avantTerre.y = pTerre.y;
            avantAir.x = pAir.x;
            avantAir.y = pAir.y;

            //deplacement
            //feu
            if (Keyboard::isKeyPressed(Keyboard::Left)) // Fleche gauche appuyee
            {
                pFeu.x -= VITESSE;
                textureFeu=1;
                if (pFeu.x==(porte1.x+BLOC) && (pFeu.y+2*BLOC)>porte1.y )
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
                if (pFeu.x==(porte2.x+BLOC) && (pFeu.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pFeu.y)>porte2.y )
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
                if (pFeu.x==(porte3.x+BLOC) && (pFeu.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pFeu.y)>porte3.y )
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
            }

            else if (Keyboard::isKeyPressed(Keyboard::Right)) // Fleche droite appuyee
            {
                pFeu.x+= VITESSE;
                textureFeu=2;
                if ((pFeu.x+BLOC)==porte1.x && (pFeu.y+2*BLOC)>=porte1.y+5)
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
                if ((pFeu.x+BLOC)==porte2.x && (pFeu.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pFeu.y)>porte2.y )
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
                if ((pFeu.x+BLOC)==porte3.x && (pFeu.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pFeu.y)>porte3.y )
                {
                    pFeu.x = avantFeu.x;
                    pFeu.y = avantFeu.y;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up))//Fleche haut appuyee
                gravFeu=true;

            if (Keyboard::isKeyPressed(Keyboard::Q)) // touche Q appuyee
            {
                pEau.x-=VITESSE;
                textureEau=1;
                if (pEau.x==(porte1.x+BLOC) && (pEau.y+2*BLOC)>porte1.y )
                    break;
                if (pEau.x==(porte2.x+BLOC) && (pEau.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pEau.y)>porte2.y )
                    break;
                if (pEau.x==(porte3.x+BLOC) && (pEau.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pEau.y)>porte3.y )
                    break;
            }

            else if (Keyboard::isKeyPressed(Keyboard::D)) // touche D appuyee
            {
                pEau.x+=VITESSE;
                textureEau=2;
                if ((pEau.x+BLOC)==porte1.x && (pEau.y+2*BLOC)>=porte1.y+5)
                    break;
                if ((pEau.x+BLOC)==porte2.x && (pEau.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pEau.y)>porte2.y )
                    break;
                if ((pEau.x+BLOC)==porte3.x && (pEau.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pEau.y)>porte3.y )
                    break;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Z))//touche Z appuyee
                gravEau=true ;


            if (Keyboard::isKeyPressed(Keyboard::J)) // touche J appuyee
            {
                pTerre.x-=VITESSE;
                textureTerre=1;
                if (pTerre.x==(porte1.x+BLOC) && (pTerre.y+2*BLOC)>porte1.y )
                    break;
                if (pTerre.x==(porte2.x+BLOC) && (pTerre.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pTerre.y)>porte2.y )
                    break;
                if (pTerre.x==(porte3.x+BLOC) && (pTerre.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pTerre.y)>porte3.y )
                    break;
            }

            else if (Keyboard::isKeyPressed(Keyboard::L)) // touche L appuyee
            {
                pTerre.x+=VITESSE;
                textureTerre=2;
                if ((pTerre.x+BLOC)==porte1.x && (pTerre.y+2*BLOC)>=porte1.y+5)
                    break;
                if ((pTerre.x+BLOC)==porte2.x && (pTerre.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pTerre.y)>porte2.y )
                    break;
                if ((pTerre.x+BLOC)==porte3.x && (pTerre.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pTerre.y)>porte3.y )
                    break;
            }
            else if (Keyboard::isKeyPressed(Keyboard::I))//touche I appuyee
                gravTerre=true ;


            if (Keyboard::isKeyPressed(Keyboard::Num4)) // touche 4 appuyee
            {
                pAir.x-=VITESSE;
                textureAir=1;
                if (pAir.x==(porte1.x+BLOC) && (pAir.y+2*BLOC)>porte1.y )
                    break;
                if (pAir.x==(porte2.x+BLOC) && (pAir.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pAir.y)>porte2.y )
                    break;
                if (pAir.x==(porte3.x+BLOC) && (pAir.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pAir.y)>porte3.y )
                    break;
            }

            else if (Keyboard::isKeyPressed(Keyboard::Num6)) // touche 6 appuyee
            {
                pAir.x+= VITESSE;
                textureAir=2;
                if ((pAir.x+BLOC)==porte1.x && (pAir.y+2*BLOC)>=porte1.y+5)
                    break;
                if ((pAir.x+BLOC)==porte2.x && (pAir.y+2*BLOC)<(porte2.y+4*BLOC +5) && (pAir.y)>porte2.y )
                    break;
                if ((pAir.x+BLOC)==porte3.x && (pAir.y+2*BLOC)<(porte3.y+4*BLOC +5) && (pAir.y)>porte3.y )
                    break;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num8))//touche 8 appuyee
                gravAir=true;

            if (Keyboard::isKeyPressed(Keyboard::Num5))//double saut
                gravAir2=true;
            //fin deplacement

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

            //colision

            for (int b=0; b<NB_BLOC_HAUTEUR; b++)
            {
                for (int a=0; a<NB_BLOC_LARGEUR; a++)
                {
                    //feu
                    int topFeu = b*BLOC- BLOC - BLOC/2 - 10 ;
                    int bottomFeu = b*BLOC+BLOC;
                    int leftFeu = a * BLOC;
                    int rightFeu = a * BLOC + BLOC;

                    //eau
                    int topEau = b*BLOC - 10;
                    int bottomEau = b*BLOC+BLOC;
                    int leftEau = a * BLOC;
                    int rightEau = a * BLOC + BLOC;

                    //terre
                    int topTerre = b*BLOC-BLOC/2 - BLOC/6;
                    int bottomTerre = b*BLOC+BLOC;
                    int leftTerre = a * BLOC;
                    int rightTerre = a * BLOC + BLOC;

                    //air
                    int topAir = b*BLOC-BLOC/2 - BLOC/6;
                    int bottomAir = b*BLOC+BLOC;
                    int leftAir = a * BLOC;
                    int rightAir = a * BLOC + BLOC;

                    for(int numerocase = 1; numerocase < 27; numerocase++)
                    {
                        if (numerocase==6)
                            numerocase+=3;
                        if (numerocase==7)
                            numerocase+=2;
                        if (numerocase==8)
                            numerocase++;

                        if (carte[b][a] == numerocase && pFeu.x + BLOC >= leftFeu && pFeu.x <= rightFeu && pFeu.y + BLOC >= topFeu && pFeu.y<=bottomFeu)
                        {
                            pFeu.x = avantFeu.x;
                            pFeu.y = avantFeu.y;
                        }
                        if (carte[b][a] == numerocase && pEau.x + BLOC >= leftEau && pEau.x <= rightEau && pEau.y + BLOC >= topEau && pEau.y<=bottomEau)
                        {
                            pEau.x = avantEau.x;
                            pEau.y = avantEau.y;
                        }
                        if (carte[b][a] == numerocase && pTerre.x + BLOC >= leftTerre && pTerre.x <= rightTerre && pTerre.y + BLOC >= topTerre && pTerre.y<=bottomTerre)
                        {
                            pTerre.x = avantTerre.x;
                            pTerre.y = avantTerre.y;
                        }
                        if (carte[b][a] == numerocase && pAir.x + BLOC >= leftAir && pAir.x <= rightAir && pAir.y + BLOC >= topAir && pAir.y<=bottomAir)
                        {
                            pAir.x = avantAir.x;
                            pAir.y = avantAir.y;
                        }



                    }
                }
            }

        //on dessine la map
        for (int k=0; k<NB_BLOC_HAUTEUR; k++)
        {
            for (int l=0; l<NB_BLOC_LARGEUR; l++)
            {
                fenetre.draw(blocTileset[k][l]);
            }
        }

        FloatRect boxFeu = feudefacev1.getGlobalBounds();
        FloatRect boxEau = eaudefacev1.getGlobalBounds();
        FloatRect boxTerre = terredefacev1.getGlobalBounds();
        FloatRect boxAir = airdefacev1.getGlobalBounds();



        //bouton
        FloatRect boxbutton1 = bouton1.getGlobalBounds();
        FloatRect boxbutton2 = bouton2.getGlobalBounds();
        FloatRect boxbutton3 = bouton3.getGlobalBounds();

        if (boxFeu.intersects(boxbutton1) || boxEau.intersects(boxbutton1) || boxTerre.intersects(boxbutton1) || boxAir.intersects(boxbutton1) )
            porte1.y = porte1.y - 2* BLOC;
        if (boxFeu.intersects(boxbutton2) || boxEau.intersects(boxbutton2) || boxTerre.intersects(boxbutton2) || boxAir.intersects(boxbutton2) )
            porte2.y = porte2.y + 4* BLOC;
        if (boxFeu.intersects(boxbutton3) || boxEau.intersects(boxbutton3) || boxTerre.intersects(boxbutton3) || boxAir.intersects(boxbutton3) )
            porte3.y = porte3.y - 4* BLOC;

        //position des texture
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


        //on place et on dessine le perso
        perso.setPosition(posPerso.x,posPerso.y);
        //fenetre.draw(perso);

        rect1.setPosition(porte1.x, porte1.y);
        rect2.setPosition(porte2.x, porte2.y);
        rect3.setPosition(porte3.x, porte3.y);
        fenetre.draw(bloc1);
        fenetre.draw(rect1);
        fenetre.draw(rect2);
        fenetre.draw(rect3);
        fenetre.draw(bouton1);
        fenetre.draw(bouton2);
        fenetre.draw(bouton3);
        //LE draw

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

