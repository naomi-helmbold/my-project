cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c
        actualiserBalle.c
        actualiserBalle.h
        afficher_regles.c
        afficher_regles.h
        actualiserSnoopy.c
        actualiserSnoopy.h
        initialiserLevel.c
        initialiserLevel.h
        initialiserLevel.c
        CheckNextPos.c
        CheckNextPos.h
        afficherLevel.c
        afficherLevel.h
        reset.c
        reset.h
        Menu.c
        Menu.h
        Sauvegarder.c
        Sauvegarder.h
        Load.c
        Load.h
        main.h
        afficher_regles.c)
