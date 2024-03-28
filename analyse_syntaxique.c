
#include <stdio.h>
#include <stdlib.h>

#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"
#include "type_ast.h"
#include "ast_construction.h"

void analyser(char *fichier, Ast *A)
{
    demarrer(fichier);
    rec_pgm(A);
}

void rec_pgm(Ast *A)
{
    if (lexeme_courant().nature != DEBUT)
    {
        printf("Erreur syntaxique : yo_wassup attendu.\n");
        exit(1);
    }
    avancer();
    rec_instructions(A);
    //if (lexeme_courant().nature != FIN)
    //{
    //    printf("Erreur syntaxique : bye_bye attendu.\n");
    //    exit(1);
    //}
    avancer();
    if (!fin_de_sequence())
    {
        printf("Erreur syntaxique : il reste des lexemes non reconnus.\n");
        exit(1);
    }
}

void rec_instructions(Ast *A)
{
    if (lexeme_courant().nature != FIN)
    {
        rec_instruction(A);
        rec_instructions(A);
    }
}

void rec_instruction(Ast *A)
{
    switch (lexeme_courant().nature)
    {
    case DEF:
        avancer();
        rec_variable(A);
        if (lexeme_courant().nature != FLECHE)
        {
            printf("Erreur syntaxique : fleche attendue.\n");
            exit(1);
        }
        avancer();
        rec_expression(A);
        break;
    case INPUT:
        avancer();
        rec_variable(A);
        break;
    case OUTPUT:
        avancer();
        switch (lexeme_courant().nature)
        {
        case ENTIER:
        case CHAINE:
            rec_expression(A);
            break;
        case VARIABLE:
            rec_variable(A);
            break;
        default:
            printf("Erreur syntaxique : entier, chaine ou variable attendu.\n");
            exit(1);
        }

        break;
    case COMMENTAIRE:
        avancer();
        break;
    case FIN_SEQUENCE:
        printf("Erreur syntaxique : bye_bye attendu.\n");
        exit(1);
        break;
    default:
        printf("Erreur syntaxique : instruction attendue.\n");
        exit(1);
        break; // epsilon
    }
}

void rec_expression(Ast *A)
{
    switch (lexeme_courant().nature)
    {
    case ENTIER:
        avancer();
        break;
    case CHAINE:
        avancer();
        break;
    default:
        printf("Erreur syntaxique : entier ou chaine attendu.\n");
        exit(1);
    }
}
void rec_variable(Ast *A)
{
    if (lexeme_courant().nature != VARIABLE)
    {
        printf("Erreur syntaxique : Variable attendue.\n");
        exit(1);
    }
    avancer();
}
