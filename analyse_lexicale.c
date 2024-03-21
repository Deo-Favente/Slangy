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
int est_point(char c);
int est_symbole(char c);
int est_lettre(char c);
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

void determiner_instruction()
{
   if (strcmp(lexeme_en_cours.chaine, "yo_wassup") == 0)
   {
      lexeme_en_cours.nature = DEBUT;
      return;
   }
   if (strcmp(lexeme_en_cours.chaine, "bye_bye") == 0)
   {
      lexeme_en_cours.nature = FIN;
      return;
   }
   if (strcmp(lexeme_en_cours.chaine, "bussin") == 0)
   {
      lexeme_en_cours.nature = DEF;
      return;
   }
   if (strcmp(lexeme_en_cours.chaine, "lit") == 0)
   {
      lexeme_en_cours.nature = INPUT;
      return;
   }
   if (strcmp(lexeme_en_cours.chaine, "chill") == 0)
   {
      lexeme_en_cours.nature = OUTPUT;
      return;
   }
   if (strcmp(lexeme_en_cours.chaine, "->") == 0)
   {
      lexeme_en_cours.nature = FLECHE;
      return;
   }
   printf("%s", lexeme_en_cours.chaine);
   printf("Erreur lexicale : instruction inconnue\n");
   exit(0);
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
      E_CHAINE,
      E_ENTIER,
      E_INSTRUCTION,
      E_FIN
   } Etat_Automate;

   Etat_Automate etat = E_INIT;

   lexeme_en_cours.chaine[0] = '\0';

   // on utilise ensuite un automate pour reconnaitre et construire le prochain lexeme

   while (etat != E_FIN)
   {
      
      while (est_separateur(caractere_courant()))
         avancer_car();

      switch (etat)
      {

      case E_INIT: // etat initial
         switch (nature_caractere(caractere_courant()))
         {

         // Si fin de séquence
         case C_FIN_SEQUENCE:
            lexeme_en_cours.nature = FIN_SEQUENCE;
            etat = E_FIN;
            break;

         // Si c'est un chiffre
         case CHIFFRE:
            lexeme_en_cours.nature = ENTIER;
            lexeme_en_cours.ligne = numero_ligne();
            lexeme_en_cours.colonne = numero_colonne();
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            lexeme_en_cours.val = caractere_courant() - '0'; // conversion ascii -> entier
            etat = E_FIN;
            avancer_car();
            break;

         // Si c'est un symbole
         case SYMBOLE:
            lexeme_en_cours.ligne = numero_ligne();
            lexeme_en_cours.colonne = numero_colonne();
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            avancer_car();
            switch (caractere_courant())
            {
            case '"':
               lexeme_en_cours.nature = CHAINE;
               etat = E_CHAINE;
               break;

            default:
               printf("Erreur lexicale : symbole inconnu\n");
               exit(0);
               break;
            }

         // Si c'est une lettre
         case LETTRE:
            lexeme_en_cours.nature = INSTRUCTION_INCONNUE;
            lexeme_en_cours.ligne = numero_ligne();
            lexeme_en_cours.colonne = numero_colonne();

            while (nature_caractere(caractere_courant()) != C_FIN_SEQUENCE && !est_separateur(caractere_courant()) && !est_symbole(caractere_courant()))
            {
               ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
               avancer_car();
            }

            determiner_instruction();
            break;

         // Si c'est un caractère incorrect
         case ERREUR_CAR:
            printf("Erreur lexicale : caractere inconnu : \"%c\"\n", caractere_courant());
            exit(0);
            break;
         }
         break;

      case E_CHAINE:
         switch (nature_caractere(caractere_courant()))
         {
         case C_FIN_SEQUENCE:
            printf("Erreur lexicale : guillemet fermant manquant\n");
            exit(0);
            break;
         default:
            ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
            avancer_car();
            if (caractere_courant() == '"')
            {
               ajouter_caractere(lexeme_en_cours.chaine, caractere_courant());
               avancer_car();
               etat = E_FIN;
            } // Si pas de guillemet fermant, on continue de lire, la chaine n'est pas finie
            break;
         }

      // Etat final
      case E_FIN:
         break;

      // Erreur
      default:
         printf("Erreur lexicale : Lexeme inconnu\n");
         exit(0);
         break;
      } // fin du switch (etat)
   }    // fin du while (etat != E_FIN)
} // fin de reconnaitre_lexeme

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
   if (est_lettre(c))
      return LETTRE;
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
   case '"':
      return 1;

   default:
      return 0;
   }
}

/* --------------------------------------------------------------------- */

// vaut vrai ssi c désigne un caractere qui est une lettre
int est_lettre(char c)
{
   if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
   {
      return 1;
   }
   return 0;
}

/* --------------------------------------------------------------------- */

// renvoie la chaine de caracteres correspondant a la nature du lexeme
char *Nature_vers_Chaine(Nature_Lexeme nature)
{
   switch (nature)
   {
   case DEBUT:
      return "DEBUT";
   case FIN:
      return "FIN";
   case DEF:
      return "DEF";
   case INPUT:
      return "INPUT";
   case OUTPUT:
      return "OUTPUT";
   case FIN_SEQUENCE:
      return "FIN_SEQUENCE";
   case ENTIER:
      return "ENTIER";
   case FLECHE:
      return "FLECHE";
   case CHAINE:
      return "CHAINE";
   default:
      return "ERREUR";
   };
}

/* --------------------------------------------------------------------- */

// affiche a l'ecran le lexeme l
/**/
void afficher_lex(Lexeme l)
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
         printf("valeur = %d", l.val);
         break;
      default:
         break;
      }
      printf("]");
   }
}
