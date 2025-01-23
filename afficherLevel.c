//
// Created by antoi on 1/11/2024.
//

#include "afficherLevel.h"
#include <stdio.h>

void afficherLevel(char Level[10][20]) // Permet d'afficher le niveau
{
    for(int i =0;i<10;i++)
    {
        for(int y =0;y<20;y++)
        {
            printf("%c ",Level[i][y]); // Rien de particulièrement compliqué ici
        }
        printf("\n");
    }
}
