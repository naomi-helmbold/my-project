//
// Created by antoi on 1/11/2024.
//

#include "Menu.h"
#include <stdio.h>

int Menu()
{
    int choix;
    printf("\n\n\n\n\n\n\n\n\n\n\n         O_      __)(\n"
           "       ,'  `.   (_\".`.\n"
           "      :      :    /|`\n"
           "      |      |   ((|_  ,-.\n"
           "      ; -   /:  ,'  `:(( -\\\n"
           "     /    -'  `: ____ \\\\\\-:\n"
           "    _\\__   ____|___  \\____|_                                        SNOOPY'S MAGIC SHOW\n"
           "   ;    |:|        '-`      :                                             C version\n"
           "  :_____|:|__________________:\n"
           "  ;     |:|                  :                                               MENU\n"
           " :      |:|                   :                                       1 - Regles du jeu\n"
           " ;______ `'___________________:                                       2 - Nouvelle Partie\n"
           ":                              :                                      3 - Charger une partie\n"
           "|______________________________|                                      4 - Niveaux\n"
           " `---.--------------------.---'                                       5 - Scores\n"
           "     |____________________|                                           6 - Quitter\n"
           "     |                    |\n"
           "     |____________________|\n"
           "     |                    |\n"
           "   _\\|_\\|_\\/(__\\__)\\__\\//_|(_");

    scanf("%d",&choix);
    return choix;
}