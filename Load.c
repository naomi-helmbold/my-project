//
// Created by antoi on 1/11/2024.
//

#include "Load.h"
#include <stdlib.h>
#include <stdio.h>

void Load(char Level[10][20],int* SnoopyPosX,int* SnoopyPosY,int* SnoopyNextPosX,int* SnoopyNextPosY,int* BallePosX,int* BallePosY,char* SSSnoopy,char* SSBalle,float* Tour,float* Scores0,float* Scores1,float* Scores2,float* Scores3,int* Score)
{
    FILE* Save = NULL;
    Save = fopen("C:\\Users\\antoi\\OneDrive\\Desktop\\test.txt","r");
    for(int i =0;i<10;i++)
    {
        for(int y =0;y<20;y++)
        {
            Level[i][y] = fgetc(Save);
        }
    }
    fscanf(Save,"%d %d %d %d %d %d %c %c %f %f %f %f %f %d",&*SnoopyPosX,&*SnoopyPosY,&*SnoopyNextPosX,&*SnoopyNextPosY,&*BallePosX,&*BallePosY,&*SSSnoopy,&*SSBalle,&*Tour,&*Scores0,&*Scores1,&*Scores2,&*Scores3,&*Score);
}