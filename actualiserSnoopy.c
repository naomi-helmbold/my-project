//
// Created by antoi on 1/11/2024.
//

#include "actualiserSnoopy.h"

void actualiserSnoopy(char *SSSnoopy,char Level[10][20],int *PosX,int *PosY,int NextPosX,int NextPosY,int *Score) // Permet d'actualiser les mouvements du joueur
{
    if(*PosX != NextPosX || *PosY != NextPosY) // Si Snoppy change de position
    {
        Level[*PosX][*PosY] = *SSSnoopy; // On remet la tuile qui était sous Snoopy
        *SSSnoopy = Level[NextPosX][NextPosY]; // La tuile à la prochaine position de Snoopy est stockée
        if(*SSSnoopy == 'C') // S'il y a un oiseau sous Snoopy
        {
            *SSSnoopy = 32; // L'oiseau est enlevé de la carte
            *Score += 1; // Augmentation du Score
        }
        *PosX = NextPosX; // On actualise la position en X de Snoopy
        *PosY = NextPosY; // On actualise la position en Y de Snoopy
        Level[*PosX][*PosY] = 'P'; // On affiche Snoopy
    }
    else{ // Si Snoopy reste à sa position
        Level[*PosX][*PosY] = 'P'; // On affiche Snoopy
    }

}