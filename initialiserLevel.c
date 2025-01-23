//
// Created by antoi on 1/11/2024.
//

#include "initialiserLevel.h"
#include <stdio.h>

void initialiserLevel(char Level[10][20],int Current,int* mdp){ //Initialise le Niveau 0

    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 20; y++) {
            if (i == 0 || i == 9 || y == 0 || y == 19) {
                Level[i][y] = -37; // Initialisation des murs
            } else {
                Level[i][y] = 32; // Initialisation du sol
            }
        }
        printf("\n"); // Retour à la ligne pour un affichage rectangulaire
    }
    switch (Current) {
        case 0:
            Level[1][1] = 'C'; // Oiseau Supérieur Gauche
            Level[1][18] = 'C'; // Oiseau Supérieur Droit
            Level[8][18] = 'C'; // Oiseau Inférieur Gauche
            Level[8][1] = 'C'; // Oiseau Inférieur Droit
            *mdp = 6385;
            break;
        case 1:
            Level[1][1] = 'C'; // Oiseau Supérieur Gauche
            Level[1][18] = 'C'; // Oiseau Supérieur Droit
            Level[8][18] = 'C'; // Oiseau Inférieur Gauche
            Level[8][1] = 'C'; // Oiseau Inférieur Droit
            Level [4][11] = '8'; //Position du pièges
            Level [3][11] = '8'; //Position du pièges
            Level [2][11] = '8'; //Position du pièges
            Level [1][11] = '8'; //Position du pièges
            Level [6][11] = '8'; //Position du pièges
            Level [5][11] = '8'; //Position du pièges
            Level [6][10] = '8'; //Position du pièges
            Level [6][11] ='8'; //Position du pièges
            Level [4][10] ='8'; //Position du pièges
            Level [2][1] = '8'; //Position du pièges
            Level [2][2] = '8'; //Position du pièges
            Level [2][3] = '8'; //Position du pièges
            *mdp = 9867;
            break;
        case 2:
            Level[1][1] = 'C'; // Oiseau Supérieur Gauche
            Level[1][18] = 'C'; // Oiseau Supérieur Droit
            Level[8][18] = 'C'; // Oiseau Inférieur Gauche
            Level[8][1] = 'C'; // Oiseau Inférieur Droit
            Level[5][10] = 'P'; // Position initiale de Snoopy
            Level[6][11] = 'o';
            Level[5][11] = '*';
            Level[7][11] = '*';
            Level[1][2] = '*';
            Level[2][1] = '*';
            Level[1][17] = '*';
            Level[2][18] = '*';
            Level[7][1] = '*';
            Level[8][2] = '*';
            Level[7][18] = '*';
            Level[8][17] = '*';
            Level[6][10] = 'X';
            Level[4][12] = 'X';
            Level[4][12] = 'X';
            Level[4][11] = 'X';
            Level[4][10] = 'X';
            Level[4][9] = 'X';
            Level[4][8] = 'X';
            Level[5][8] = 'X';
            Level[6][8] = 'X';
            Level[7][8] = 'X';
            Level[8][8] = 'X';
            Level[8][9] = 'X';
            Level[8][10] = 'X';
            Level[8][11] = 'X';
            Level[8][12] = 'X';
            Level[5][12] = 'X';
            Level[7][12] = 'X';
            Level[2][3] = 'X';
            Level[3][2] = 'X';
            Level[2][2] = 'X';
            Level[2][16] = 'X';
            Level[3][17] = 'X';
            Level[2][17] = 'X';
            Level[6][2] = 'X';
            Level[7][3] = 'X';
            Level[7][2] = 'X';
            Level[6][17] = 'X';
            Level[7][17] = 'X';
            Level[7][16] = 'X';
            Level[3][1] = '8';
            Level[1][3] = 'B';
            Level[1][16] = '8';
            Level[3][18] = 'B';
            Level[6][1] = '8';
            Level[8][3] = 'B';
            Level[6][18] = '8';
            Level[8][16] = 'B';
            *mdp = 4586;
            break;
        default:
            break;
    }
}

