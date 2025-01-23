//
// Created by antoi on 1/11/2024.
//

#include "Sauvegarder.h"
#include <stdio.h>
#include <stdlib.h>

void Sauvegarder(char Level[10][20],int SnoopyPosX,int SnoopyPosY,int SnoopyNextPosX,int SnoopyNextPosY,int BallePosX,int BallePosY,char SSSnoopy,char SSBalle,float Tour,float Scores[4],int Score)
{
    printf("Game Saving");
    FILE* Save = NULL;
    Save = fopen("C:\\Users\\antoi\\OneDrive\\Desktop\\test.txt","w+");
    if(Save != NULL)
    {
        for(int i =0;i<10;i++)
        {
            for(int y =0;y<20;y++) {
                fprintf(Save, "%c", Level[i][y]); // Rien de particulièrement compliqué ici
            }
        }
        fprintf(Save,"%d %d %d %d %d %d %d %d2"
                     " %f %f %f %f %f %d",SnoopyPosX,SnoopyPosY,SnoopyNextPosX,SnoopyNextPosY,BallePosX,BallePosY,SSSnoopy,SSBalle,Tour,Scores[0],Scores[1],Scores[2],Scores[3],Score);
        fclose(Save);
        printf("Game Saved");
    }
}