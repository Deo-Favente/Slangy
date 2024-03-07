/* ------------------------------------------------------------------------
-- paquetage analyse_lexicale
--
-- analyse lexicale d'une expression arithmetique
--
-- J-P. Peyrin, G. Serasset (version initiale) : janvier 1999
-- P.Habraken - 18/01/2010
--
-- 10 juin 2006 - PH :
-- remplacement record a champs variants par record "plat"
-- remplacement traitement iteratif par automate
--
-- Aout 2016 - LM : version C
------------------------------------------------------------------------ */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lecture_caracteres.h"
#include "analyse_lexicale.h"

/* --------------------------------------------------------------------- */

/* Les variables et fonctions locales au module */

Lexeme lexeme_en_cours; /* le lexeme courant */

void ajouter_caractere(char *s, char c);
Nature_Caractere nature_caractere(char c);
int est_separateur(char c);
int est_chiffre(char c);
int est_symbole(char c);
void reconnaitre_lexeme();

/* --------------------------------------------------------------------- */

void demarrer(char *nom_fichier)
{
   demarrer_car(nom_fichier);
   avancer();
}

/* --------------------------------------------------------------------- */

void avancer()
{
   reconnaitre_lexeme();
}

/* --------------------------------------------------------------------- */

Lexeme lexeme_courant()
{
   return lexeme_en_cours;
}

/* --------------------------------------------------------------------- */

int fin_de_sequence()
{
   return lexeme_en_cours.nature == FIN_SEQUENCE;
}

/* --------------------------------------------------------------------- */

void arreter()
{
   arreter_car();
}

/* --------------------------------------------------------------------- */

// reconnaissance d'un nouveau lexeme
// etat initial : le caractere courant est soit separateur
//                soit le 1er caractere d'un lexeme
// etat final :
//       - un nouveau lexeme est reconnu dans lexeme_en_cours
//       - le caractere courant est soit la fin de fichier,
//		soit un separateur,  soit le 1er caractere d'un lexeme

void reconnaitre_lexeme()
{
   typedef enum
   {
      E_INIT,
      E_ENTIER,
      E_FIN
   } Etat_Automate;
   Etat_Automate etat = E_INIT;

   // on commence par lire et ignorer les separateurs
   while (est_separateur(caractere_courant()))
   {
      avancer_car();
   };

   lexeme_en_cours.chaine[0] = '\0';

   // on utilise ensuite un automate pour reconnaitre et construire le prochain lexeme

   while (etat != E_FIN)
   {
      // afficher(lexeme_en_cours);

      switch (etat)
      {

      case E_INIT: // etat initial

         switch (nature_caractere(caractere_courant()))
         {

         case C_FIN_SEQUENCE:
            lexeme_en_cours.nature = FIN_SEQUENCE;
            etat = E_FIN;
            break;

         case CHIFFRE:
            lexeme_en_cours.nature = ENTIER;
            lexeme_en_cours.ligne = numero_ligne();
            lexeme_en_cours.colonne = numero_colonne();
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            lexeme_en_cours.valeur = caractere_courant() - '0';
            etat = E_ENTIER;
            avancer_car();
            break;

         case SYMBOLE:
            lexeme_en_cours.ligne = numero_ligne();
            lexeme_en_cours.colonne = numero_colonne();
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            switch (caractere_courant())
            {
            case '+':
               lexeme_en_cours.nature = PLUS;
               etat = E_FIN;
               break;
            case '-':
               lexeme_en_cours.nature = MOINS;
               etat = E_FIN;
               break;
            case '*':
               lexeme_en_cours.nature = MUL;
               etat = E_FIN;
               break;
            case '/':
               lexeme_en_cours.nature = DIV;
               etat = E_FIN;
               break;
            case '(':
               lexeme_en_cours.nature = PARO;
               etat = E_FIN;
               break;
            case ')':
               lexeme_en_cours.nature = PARF;
               etat = E_FIN;
               break;
            default:
               printf("Erreur_Lexicale\n");
               exit(0);
            };
            avancer_car();
            break;

         default:
            printf("Erreur_Lexicale\n");
            exit(0);
         };
         break;

      case E_ENTIER: // reconnaissance d'un entier
         switch (nature_caractere(caractere_courant()))
         {
         case CHIFFRE:
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            lexeme_en_cours.valeur = lexeme_en_cours.valeur * 10 + caractere_courant() - '0';
            etat = E_ENTIER;
            avancer_car();
            break;

         default:
            etat = E_FIN;
         };

      case E_FIN: // etat final
         break;

      }; // fin du switch(etat)
   };    // fin du while (etat != fin)
}

/* --------------------------------------------------------------------- */

// cette fonction ajoute le caractere c a la fin de la chaine s
// (la chaine s est donc modifiee)

void ajouter_caractere(char *s, char c)
{
   int l;

   l = strlen(s);
   s[l] = c;
   s[l + 1] = '\0';
};

/* --------------------------------------------------------------------- */

Nature_Caractere nature_caractere(char c)
{
   if (fin_de_sequence_car(c))
      return C_FIN_SEQUENCE;
   if (est_chiffre(c))
      return CHIFFRE;
   if (est_symbole(c))
      return SYMBOLE;
   return ERREUR_CAR;
}
/* --------------------------------------------------------------------- */

// vaut vrai ssi c designe un caractere separateur
int est_separateur(char c)
{
   return c == ' ' || c == '\t' || c == '\n';
}

/* --------------------------------------------------------------------- */

// vaut vrai ssi c designe un caractere chiffre
int est_chiffre(char c)
{
   return c >= '0' && c <= '9';
}

/* --------------------------------------------------------------------- */

// vaut vrai ssi c designe un caractere correspondant a un symbole arithmetique
int est_symbole(char c)
{
   switch (c)
   {
   case '+':
   case '-':
   case '*':
   case '/':
   case '(':
   case ')':
      return 1;

   default:
      return 0;
   }
}

/* --------------------------------------------------------------------- */

// renvoie la chaine de caracteres correspondant a la nature du lexeme
char *Nature_vers_Chaine(Nature_Lexeme nature)
{
   switch (nature)
   {
   case ENTIER:
      return "ENTIER";
   case PLUS:
      return "PLUS";
   case MOINS:
      return "MOINS";
   case MUL:
      return "MUL";
   case DIV:
      return "DIV";
   case FIN_SEQUENCE:
      return "FIN_SEQUENCE";
   case PARO:
      return "PARO";
   case PARF:
      return "PARF";
   default:
      return "ERREUR";
   };
}

/* --------------------------------------------------------------------- */

// affiche a l'ecran le lexeme l
void afficher(Lexeme l)
{

   switch (l.nature)
   {
   case FIN_SEQUENCE:
      break;
   default:
      printf("(ligne %d, ", l.ligne);
      printf("colonne %d) : ", l.colonne);
      printf("[");
      printf("nature = %s", Nature_vers_Chaine(l.nature));
      printf(", chaine = %s, ", l.chaine);
      switch (l.nature)
      {
      case ENTIER:
         printf("valeur = %d", l.valeur);
      default:
         break;
      };
      printf("]");
   };
}

/* --------------------------------------------------------------------- */