//
// Created by antoi on 1/11/2024.
//

#include "actualiserBalle.h"
void actualiserBalle(char Level[10][20],int* PosX,int* PosY,int* Direction,char *SSBalle)// permet d'actualiser les mouvements de la balle
{
    Level[*PosX][*PosY] = 32; //pour ne pas afficher les précédentes positions de la balle
    if(*Direction == 1)// 1 correspond à Supérieur droit
    {
        if(Level[*PosX-1][*PosY+1] == -37) //Vérifie s'il y a un mur dans le coin Supérieur Droit de la Balle
        {
            if(Level[*PosX-1][*PosY-1] == -37 && Level[*PosX+1][*PosY+1] != -37)  //Vérifie s'il y a aussi un mur dans le coin Supérieur Gauche de la balle pour calculer la direction suivante
            {
                *Direction = 2; // Changement de direction (2 = Inférieur Droit)
            }
            else if(Level[*PosX+1][*PosY+1] == -37 && Level[*PosX-1][*PosY-1] != -37) // Vérifie s'il y a aussi un mur dans le coin Inférieur Droit de la balle
            {
                *Direction = 4; // Changement de direction (4 = Supérieur Gauche)
            }
            else
            {
                *Direction = 3; // S'il n'y a aucun mur, la balle est dans un coin, alors on inverse sa direction
            }
        }
    }
    else if(*Direction == 2)// 2 correspond à Inférieur Droit
    {
        if(Level[*PosX+1][*PosY+1] ==-37) //Vérifie s'il y a un mur dans le coin Inférieur Droit de la Balle
        {
            if(Level[*PosX-1][*PosY+1] == -37 && Level[*PosX+1][*PosY-1] != -37) //Vérifie s'il y a aussi un mur dans le coin Inférieur Gauche de la Balle
            {
                *Direction = 3;// Changement de direction
            }
            else if(Level[*PosX+1][*PosY-1] == -37 && Level[*PosX-1][*PosY+1] != -37) //Vérifie s'il y a aussi un mur dans le coin Supérieur Droit de la Balle
            {
                *Direction = 1; // Changement de direction
            }
            else
            {
                *Direction = 4; // S'il n'y a aucun mur, alors la balle est dans un coin, donc on inverse sa direction
            }
        }
    }
    else if(*Direction == 3) // 3 correspond à Inférieur Gauche
    {
        if(Level[*PosX+1][*PosY-1] == -37) //Vérifie s'il y a un mur dans le coin Inférieur Gauche de la Balle
        {
            if(Level[*PosX+1][*PosY+1] == -37 && Level[*PosX-1][*PosY-1] != -37)   // Vérifie s'il y a aussi un mur dans le coin Inférieur Droit de la balle
            {
                *Direction = 4; //Changement de direction
            }
            else if(Level[*PosX-1][*PosY-1] == -37 && Level[*PosX+1][*PosY+1] != -37) // Vérifie s'il y a aussi un mur dans le coin Supérieur Gauche de la Balle
            {
                *Direction = 2; // Changement de direction
            }
            else
            {
                *Direction = 1; // S'il n'y a aucun mur, alors la balle est dans un coin, on inverse donc sa direction
            }
        }
    }
    else if(*Direction == 4) // 4 correspond à Supérieur Gauche
    {
        if(Level[*PosX-1][*PosY-1] == -37) // Vérifie s'il y a un mur dans le coin Supérieur Gauche de la Balle
        {
            if(Level[*PosX+1][*PosY-1] == -37 && Level[*PosX-1][*PosY+1] != -37) // Vérifie s'il y a aussi un mur dans le coin Inférieur Gauche de la Balle
            {
                *Direction = 1; // Changement de direction
            }
            else if(Level[*PosX-1][*PosY+1] == -37 && Level[*PosX+1][*PosY-1] != -37) // Vérifie s'il y a aussi un mur dans le coin Supérieur Droit de la Balle
            {
                *Direction = 3; // Changement de direction
            }
            else
            {
                *Direction = 2; // S'il n'y a aucun mur, alors la balle est dans un coin, on inverse donc sa direction
            }
        }
    }


    switch (*Direction) { // Condition en fonction de la direction de la balle
        case 1: // Si la direction correspond au coin Supérieur Droit
            Level[*PosX][*PosY] = *SSBalle; // On remet la tuile qui était sous la Balle
            *PosX -= 1; // Avance la Balle vers le Haut
            *PosY += 1; // Avance la Balle vers la Droite
            *SSBalle = Level[*PosX][*PosY]; // La tuile à la prochaine position de la Balle est stockée
            break;

        case 2: // Si la direction corrrespond au coin Inférieur Droit
            Level[*PosX][*PosY] = *SSBalle; // On remet la tuile qui était sous la Balle
            *PosX += 1; // Avance la Balle vers le Bas
            *PosY += 1; // Avance la Balle vers la Droite
            *SSBalle = Level[*PosX][*PosY]; // La tuile à la prochaine position de la Balle est stockée
            break;

        case 3: // Si la direction correspond au coin Inférieur Gauche
            Level[*PosX][*PosY] = *SSBalle; // On remet la tuile qui était sous la Balle
            *PosX += 1; // Avance la Balle vers le Bas
            *PosY -= 1; // Avance la Balle vers la Gauche
            *SSBalle = Level[*PosX][*PosY]; // La tuile à la prochaine position de la Balle est stockée
            break;

        case 4: // Si la direction correspond au coin Supérieur Gauche
            Level[*PosX][*PosY] = *SSBalle; // On remet la tuile qui était sous la Balle
            *PosX -= 1; // Avance la Balle vers le Haut
            *PosY -= 1; // Avance la Balle vers la Gauche
            *SSBalle = Level[*PosX][*PosY]; // La tuile à la prochaine position de la Balle est stockée
            break;
    }

    if(*SSBalle == 'P')
    {
        *SSBalle = 32;
    }
    Level[*PosX][*PosY] = 'O'; // Affiche la Balle

}
