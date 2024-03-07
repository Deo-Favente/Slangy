
#include <stdio.h>
#include "type_ast.h"

void aff_operateur(TypeOperateur op){
	switch (op) {
		case N_PLUS:
			printf("+") ;
			break;
		case N_MOINS:
			printf("-") ;
			break;
		case N_MUL:
			printf("*") ;
			break;
		case N_DIV:
			printf("/") ;
			break;
	} 
}

void afficher_ast(Ast expr) {
	switch (expr->nature) {
               case OPERATION:
                        printf("(");
                        afficher_ast(expr->gauche);
                        aff_operateur(expr->operateur) ;
                        afficher_ast(expr->droite);
                        printf(")");
			break ;
               case VALEUR:
                  	printf("%d", expr->valeur);
			break ;
	}
}

int evaluation(Ast expr) {
		int gauche, droite;
		switch (expr->nature)
		{
		case VALEUR:
			return expr->valeur;
		case OPERATION:
			gauche = evaluation(expr->gauche);
			droite = evaluation(expr->droite);
			switch (expr->operateur)
			{
			case N_PLUS:
				return gauche + droite;
			case N_MOINS:
				return gauche - droite;
			case N_MUL:
				return gauche * droite;
			case N_DIV:
				if (droite == 0)
				{
					printf("Erreur sémantique : La division par 0 est interdite.\n");
					return -1;
				}

				return gauche / droite;
			}
		}
	return -1;
}

