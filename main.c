
#include <stdio.h>
#include <stdlib.h>

#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"
#include "lecture_caracteres.h"
#include "type_ast.h"
#include "ast_parcours.h"

int main(int argc, char *argv[])
{
    Ast A = (Ast) malloc (sizeof(NoeudAst));
    switch (argc)
    {
    case 1:
        // demarre l'analyse lexicale et syntaxique sur stdin
        demarrer("stdin");
        // demarre l'analyse lexicale et syntaxique sur stdin
        analyser("stdin", &A);
        
        //printf("L'arbre syntaxique abstrait est : \n");
        //afficher_ast(A);
        printf("\n");
        break;
    case 2:
        // demarre l'analyse lexicale et syntaxique sur le fichier passe en argument
        //demarrer(argv[1]);
        // demarre l'analyse lexicale et syntaxique sur le fichier passe en argument
        
        analyser(argv[1], &A);

        //printf("L'arbre syntaxique abstrait est : \n");
        //afficher_ast(A);
        printf("\n");
        break;

    default:
        printf("nombre d'arguments incorrects !\n");
        exit(2);
    };
    while (!fin_de_sequence())
    {
        afficher_lex(lexeme_courant());
        avancer();
    };

    arreter(); // termine l'analyse lexicale
    return 0;
}
