#include <stdio.h>
#include <stdlib.h>

#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"
#include "type_ast.h"
#include "ast_construction.h"

void rec_facteur(Ast *A)
{
    Lexeme lexeme_en_cours;
    lexeme_en_cours = lexeme_courant();
    switch (lexeme_en_cours.nature)
    {
    case ENTIER:
        avancer();
        *A = creer_valeur(lexeme_en_cours.valeur);
        break;
    case PARO:
        avancer();
        rec_eag(A);
        lexeme_en_cours = lexeme_courant();
        if (lexeme_en_cours.nature != PARF)
        {
            printf("Erreur syntaxique : ')' attendu.\n");
            exit(0);
        }
        avancer();
        break;
    default:
        printf("Erreur syntaxique : un opérateur en suit un autre.\n");
        exit(0);
        break;
    }
}

void rec_suite_seq_facteur(Ast *Ag, Ast *A)
{
    Lexeme lexeme_en_cours;
    lexeme_en_cours = lexeme_courant();
    Ast Ad, A1;
    TypeOperateur op;

    switch (lexeme_en_cours.nature)
    {
    case MUL:
    case DIV:
        rec_op2(&op);
        rec_terme(&Ad);
        A1 = creer_operation(op, *Ag, Ad);
        rec_suite_seq_terme(&A1, A);
        break;
    default:
        *A = *Ag;
        break;
    }
}

void rec_seq_facteur(Ast *A)
{
    Ast A1;
    rec_facteur(&A1);
    rec_suite_seq_facteur(&A1, A);
}

void rec_terme(Ast *A)
{
    rec_seq_facteur(A);
}

void rec_suite_seq_terme(Ast *Ag, Ast *A)
{
    Ast Ad, A1;
    TypeOperateur op;

    Lexeme lexeme_en_cours;
    lexeme_en_cours = lexeme_courant();
    switch (lexeme_en_cours.nature)
    {
    case PLUS:
    case MOINS:
        rec_op1(&op);
        rec_terme(&Ad);
        A1 = creer_operation(op, *Ag, Ad);
        rec_suite_seq_terme(&A1, A);
        break;
    default:
        *A = *Ag;
        break;
    }
}

void rec_op1(TypeOperateur *op)
{
    Lexeme lexeme_en_cours;
    lexeme_en_cours = lexeme_courant();

    switch (lexeme_en_cours.nature)
    {
    case PLUS:
        *op = N_PLUS;
        avancer();
        break;
    case MOINS:
        *op = N_MOINS;
        avancer();
        break;
    default:
        exit(0);
        break;
    }
}

void rec_op2(TypeOperateur *op)
{
    Lexeme lexeme_en_cours;
    lexeme_en_cours = lexeme_courant();

    switch (lexeme_en_cours.nature)
    {
    case MUL:
        *op = N_MUL;
        avancer();
        break;
    case DIV:
        *op = N_DIV;
        avancer();
        break;
    default:
        printf("Erreur syntaxique : un opérateur * ou / est attendu.\n");
        exit(0);
        break;
    }
}

void rec_seq_terme(Ast *A)
{
    Ast A1;
    rec_terme(&A1);
    rec_suite_seq_terme(&A1, A);
}

void rec_eag(Ast *A)
{
    rec_seq_terme(A);
}

void analyser(char *nom_fichier, Ast *A)
{
    demarrer(nom_fichier); // Analyse lexicale

    rec_eag(A);
    Lexeme lexeme_en_cours;
    // Vérification de fin de séquence
    lexeme_en_cours = lexeme_courant();
    if (lexeme_en_cours.nature != FIN_SEQUENCE)
    {
        printf("Erreur syntaxique : le calcul est incomplet.\n");
        exit(0);
    }
}
