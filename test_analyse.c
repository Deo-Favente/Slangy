
/* Exemple d'utilisation de l'analyse lexicale :
    Affichage d'une sequence de lexemes            */

#include <stdio.h>
#include <stdlib.h>

#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"
#include "lecture_caracteres.h"

int main(int argc, char *argv[])
{
    //int* resultat = 0;
    switch (argc)
    {
    case 1:
        // demarre l'analyse lexicale et syntaxique sur stdin
        analyser(argv[1]);
        break;
    case 2:
        // demarre l'analyse lexicale et syntaxique sur le fichier transmis en argument
        analyser(argv[1]);
        break;
    default:
        printf("nombre d'arguments incorrects !\n");
        exit(1);
    };

    while (!fin_de_sequence())
    {
        // afficher(lexeme_courant());
        //printf("\n");
        avancer();
    };
    arreter(); // termine l'analyse lexicale
    return 0;
}
