//
// Created by antoi on 1/11/2024.
//

#include "CheckNextPos.h"
#include <stdio.h>
#include "actualiserBalle.h"

int CheckNextPos(char Level[10][20],int NextPosX,int NextPosY, int PosX, int PosY, int* PBallePosX, int* PBallePosY, int DirectionBalle, char SSBalle, float* Tour) {

    if (Level[NextPosX][NextPosY] == -37 || Level[NextPosX][NextPosY] == 'X')
    {
        return 1;
    }
    else if (Level[NextPosX][NextPosY] == 'o')
    {
        if (NextPosX != PosX)
        {
            if (NextPosX > PosX)
            {
                if (Level[NextPosX + 1][NextPosY] == 32)
                {
                    Level[NextPosX][NextPosY] = 32;
                    Level[NextPosX + 1][NextPosY] = 'o';
                    return 0;
                }
            }
            else if (NextPosX < PosX)
            {
                if (Level[NextPosX - 1][NextPosY] == 32)
                {
                    Level[NextPosX][NextPosY] = 32;
                    Level[NextPosX - 1][NextPosY] = 'o';
                    return 0;
                }
            }
        }
        else if (NextPosY != PosY)
        {
            if (NextPosY > PosY)
            {
                if (Level[NextPosX][NextPosY + 1] == 32)
                {
                    Level[NextPosX][NextPosY] = 32;
                    Level[NextPosX][NextPosY + 1] = 'o';
                    return 0;
                }
            } else if (NextPosY < PosY) {
                if (Level[NextPosX][NextPosY - 1] == 32)
                {
                    Level[NextPosX][NextPosY] = 32;
                    Level[NextPosX][NextPosY - 1] = 'o';
                    return 0;
                }
            }

        }
        return 1;
    }
    else if (Level[NextPosX][NextPosY] == '*')
    {
        Level[NextPosX][NextPosY] = 32;
        Level[NextPosX][NextPosY] = '*';
        printf("Voulez-vous casser le bloc en face de vous ? Oui: 1, Non: 0.\n");
        int choix;
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                Level[NextPosX][NextPosY] = 32;
                break;
            case 0:
                Level[NextPosX][NextPosY] = '*';
                break;
            default:
                printf("Mauvais Input"); // Informe l'utilisateur d'une mauvaise manipulation
                break;
        }
        return 1;
    }
    else if (Level[NextPosX][NextPosY] == '8')
    {
        printf("Vous etes gele pendant 3 tours.\n");
        actualiserBalle(Level, PBallePosX, PBallePosY, &DirectionBalle, &SSBalle);
        actualiserBalle(Level, PBallePosX, PBallePosY, &DirectionBalle, &SSBalle);
        actualiserBalle(Level, PBallePosX, PBallePosY, &DirectionBalle, &SSBalle);
        *Tour += 3;
        return 0;

    }
    else
    {
        return 0; // Retourne 1 sinon
    }
}