//
// Created by antoi on 1/11/2024.
//

#include "reset.h"

void reset(int* Score,float* Tour,int* SnoopyPosX,int* SnoopyPosY,int* SnoopyNextPosX,int* SnoopyNextPosY,int* BallePosX,int* BallePosY,int* DirectionBalle,int* Vies)
{
    *Tour = 0;
    *SnoopyPosX=5;
    *SnoopyPosY=10;
    *SnoopyNextPosX=5;
    *SnoopyNextPosY=10;
    *BallePosX=4;
    *BallePosY=4;
    *DirectionBalle=1;
    *Score = 0;
    *Vies = 3;
}
