#include <stdio.h>

#include "actualiserBalle.h"
#include "afficher_regles.h"
#include "actualiserSnoopy.h"
#include "initialiserLevel.h"
#include "afficherLevel.h"
#include "CheckNextPos.h"
#include "reset.h"
#include "Menu.h"
#include "Sauvegarder.h"
#include "Load.h"

typedef struct{
    char Map[10][20];
    int mdp;
}Level;


int main() { // Programme principal
    char SSSnoopy=32,SSBalle=32; // Initialisation de variables
    int Vies = 3,MenuChoix=0,choix=1,SnoopyPosX=5,SnoopyPosY=10,SnoopyNextPosX=5,SnoopyNextPosY=10,BallePosX=4,BallePosY=4,DirectionBalle=1,Score=0; // Initialisation de variables
    int LancerPartie = 0,Current = 0,*PBallePosX = &BallePosX, *PBallePosY = &BallePosY; // Initialisation de variables
    Level LevelList[4];
    float Scores[4] = {0}, Tour = 0;

    for(int i = 0 ; i < 3 ; i++)
    {
        initialiserLevel(LevelList[i].Map, i,&LevelList[i].mdp); // Initialisation du niveau
    }

    while(MenuChoix != 6) {
        while(LancerPartie == 0) {
            MenuChoix = Menu();
            switch (MenuChoix) {
                int x, mdp;
                case 1:
                    affiche_regles();
                    MenuChoix = 0;
                    break;
                case 2:
                    choix = 1;
                    Current = 0;
                    LancerPartie = 1;
                    break;
                case 3:
                    Load(LevelList[Current].Map,&SnoopyPosX,&SnoopyPosY,&SnoopyNextPosX,&SnoopyNextPosY,&BallePosX,&BallePosY,&SSSnoopy,&SSBalle,&Tour,&Scores[0],&Scores[1],&Scores[2],&Scores[3],&Score);
                    LancerPartie = 1;
                    break;
                case 4:
                    printf("A quel Niveau voulez vous acceder ?"
                           "\n"
                           "1 - Niveau 1"
                           "\n"
                           "2 - Niveau 2"
                           "\n"
                           "3 - Niveau 3");
                    scanf("%d", &x);
                    printf("Quel est le mot de passe ?");
                    scanf("%d", &mdp);
                    switch (x) {
                        case 1:
                            if (mdp == LevelList[0].mdp) {
                                choix = 1;
                                Current = 0;
                                LancerPartie = 1;
                            } else {
                                printf("Mauvais MDP");
                            }
                            break;
                        case 2:
                            if (mdp == LevelList[1].mdp) {
                                choix = 1;
                                Current = 1;
                                LancerPartie = 1;
                            } else {
                                printf("Mauvais MDP");
                            }
                            break;
                        case 3:
                            if (mdp == LevelList[2].mdp) {
                                choix = 1;
                                Current = 2;
                                LancerPartie = 1;
                            } else {
                                printf("Mauvais MDP");
                            }
                            break;
                    }
                    break;
                case 5:
                    Scores[0] = Scores[1] + Scores[2] + Scores[3];
                    printf("\n\n\n\n\n\n\n\n\n\n\nScores :\n\nNiveau 1 : %.0f\n\nNiveau 2 : %.0f\n\nNiveau 3 : %.0f\n\nTotal : %.0f\n\nEntrez n'importe quel chiffre pour sortir",Scores[1],Scores[2],Scores[3],Scores[0]);
                    scanf("%d",&x);
                    break;
                case 6:
                    return 0;
                default:
                    break;
            }
        }

        actualiserSnoopy(&SSSnoopy, LevelList[Current].Map, &SnoopyPosX, &SnoopyPosY, SnoopyNextPosX, SnoopyNextPosY,&Score); // Premiere actualisation de Snoopy
        actualiserBalle(LevelList[Current].Map, PBallePosX, PBallePosY, &DirectionBalle,&SSBalle); // Premiere actualisation de la Balle
        afficherLevel(LevelList[Current].Map); // Affichage du niveau

        while (choix != 0) // Tant que le joueur ne décide pas de quitter ou qu'il ne finis pas la partie
        {
            printf("Tour %.0f, %d/4 Oiseaux, %d/3 Vies restantes\n 4 = Gauche : 6 = Droite : 2 = Bas : 8 = Haut \n 0 = Quitter",
                   Tour, Score, Vies);
            scanf("%d", &choix); // Choix de l'action suivante
            switch (choix) { // Si le choix correspond à ...
                case 6:
                    SnoopyNextPosY++; // Snoopy avance vers la Droite
                    SnoopyNextPosY -= CheckNextPos(LevelList[Current].Map, SnoopyNextPosX, SnoopyNextPosY,SnoopyPosX,SnoopyPosY, PBallePosX,PBallePosY, DirectionBalle, SSBalle,&Tour); //Mouvement annulé s'il y a un mur
                    Tour++;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
                case 4:
                    SnoopyNextPosY--; // Snoopy avance vers la Gauche
                    SnoopyNextPosY += CheckNextPos(LevelList[Current].Map, SnoopyNextPosX, SnoopyNextPosY,SnoopyPosX,SnoopyPosY, PBallePosX,PBallePosY, DirectionBalle, SSBalle,&Tour); //Mouvement annulé s'il y a un mur
                    Tour++;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
                case 8:
                    SnoopyNextPosX--; // Snoopy avance vers le Haut
                    SnoopyNextPosX += CheckNextPos(LevelList[Current].Map, SnoopyNextPosX, SnoopyNextPosY,SnoopyPosX,SnoopyPosY, PBallePosX,PBallePosY, DirectionBalle, SSBalle,&Tour); //Mouvement annulé s'il y a un mur
                    Tour++;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
                case 2:
                    SnoopyNextPosX++; // Snoopy avance vers le Bas
                    SnoopyNextPosX -= CheckNextPos(LevelList[Current].Map, SnoopyNextPosX, SnoopyNextPosY,SnoopyPosX,SnoopyPosY, PBallePosX,PBallePosY, DirectionBalle, SSBalle,&Tour); //Mouvement annulé s'il y a un mur
                    Tour++;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
                case 0:
                    choix = 0;
                    LancerPartie = 0;
                    Sauvegarder(LevelList[Current].Map,SnoopyPosX,SnoopyPosX,SnoopyNextPosX,SnoopyNextPosY,BallePosX,BallePosY,SSSnoopy,SSBalle,Tour,Scores,Score);
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
                default:
                    printf("Mauvais Input"); // Informe l'utilisateur d'une mauvaise manipulation
                    Tour++;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    break;
            }

            actualiserSnoopy(&SSSnoopy, LevelList[Current].Map, &SnoopyPosX, &SnoopyPosY, SnoopyNextPosX,SnoopyNextPosY, &Score); // Actualisation de Snoopy
            actualiserBalle(LevelList[Current].Map, PBallePosX, PBallePosY, &DirectionBalle,&SSBalle); // Actualisation de la Balle
            afficherLevel(LevelList[Current].Map); // Affichage du niveau

            if (LevelList[Current].Map[SnoopyPosX][SnoopyPosY] == 'O') // Si Snoopy rencontre la Balle
            {
                if (Vies == 1) {
                    choix = 0;
                    printf("Vous avez perdu !\n");
                    SSBalle = 32;
                    }
                else {
                    SnoopyPosX = 5;
                    SnoopyPosY = 10;
                    SnoopyNextPosX = 5;
                    SnoopyNextPosY = 10;
                    actualiserSnoopy(&SSSnoopy, LevelList[Current].Map, &SnoopyPosX, &SnoopyPosY, SnoopyNextPosX,SnoopyNextPosY, &Score); // Actualisation de Snoopy
                    afficherLevel(LevelList[Current].Map); // Affichage du niveau
                    Vies--;
                }
            }
            if (Score == 4) // Si tout les oiseaux ont étés attrapés
            {
                Scores[Current+1] = (1.0f/Tour)*10000.0f;
                printf("\n\n\n\n\n\n%dVous Avez Gagne ! \nScore : %.0f\n\n\n\n\n",Current,Scores[Current+1]);
                Current++;
                if(Current == 3) {
                    LancerPartie = 0;
                    choix = 0;
                }
                else{
                    reset(&Score, &Tour, &SnoopyPosX, &SnoopyPosY, &SnoopyNextPosY, &SnoopyNextPosY, &BallePosX,&BallePosY, &DirectionBalle, &Vies);
                    actualiserBalle(LevelList[Current].Map, PBallePosX, PBallePosY, &DirectionBalle,&SSBalle); // Premiere actualisation de la Balle
                    SnoopyPosX = 5;
                    SnoopyPosY = 10;
                    SnoopyNextPosX = 5;
                    SnoopyNextPosY = 10;
                    actualiserSnoopy(&SSSnoopy, LevelList[Current].Map, &SnoopyPosX, &SnoopyPosY, SnoopyNextPosX,SnoopyNextPosY, &Score); // Premiere actualisation de Snoopy
                    afficherLevel(LevelList[Current].Map); // Affichage du niveau
                }
            }
        }
    }
}