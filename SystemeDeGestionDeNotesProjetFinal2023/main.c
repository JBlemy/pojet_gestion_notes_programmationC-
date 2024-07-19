#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Autres.h"
#include "gestionsEnseignants.h"
#include "gestionEtudiants.h"
#include "gestionsCours.h"
#include "gestionEvaluations.h"
#include "consultationsNotes.h"

//////////////////////////Bienvenue////////////////////////

void bienvenue()
{
	system("cls");
	affichage(45, 2);
	printf("CAMPUS HENRY CHRISTOPHE DE LIMONADE (CHC-L)");
	affichage(48, 3);
	printf("Facult%c des Sciences et de G%cnie (FSG)", 130, 130);
	affichage(30, 4);
	printf("----------------------------------------------------------------------");
	affichage(43, 5.5);
	printf("Bienvenue au Programme de Gestion des Notes");
	affichage(20, 7);
	printf("Pr%cpar%c par : ", 130, 130);
	affichage(28, 9);
	printf("1. Albikendy          JEAN");
	affichage(28, 10);
	printf("2. Bendy              SERVILUS");
	affichage(28, 11);
	printf("3. Blemy              JOSEPH");
	affichage(20, 13);
	printf("Soumis au professeur :");
	affichage(28, 15);
	printf("James Yvrosito Karly              BIRON");
	affichage(65, 25);
	printf("Date de remise :   02 Octobre 2023");
	affichage(20, 30);
	system("pause");

}

///////////////////////////////Menu Principal/////////////////////////////

void menuPrincipal()
{
	system("cls");
	affichageEntete();
	affichage(48, 5);
	printf("-----------Menu Principal");
	affichage(42, 7);
	printf("1. Gestions des cours");
	affichage(42, 8);
	printf("2. Gestions des %ctudiants", 130);
	affichage(42, 9);
	printf("3. Gestions des enseignants");
	affichage(42, 10);
	printf("4. Gestions des %cvaluations", 130);
	affichage(42, 11);
	printf("5. Gestions des notes");
	affichage(42, 12);
	printf("6. Voir la page de bienvenue !");
	affichage(42, 13);
	printf("0. Quitter le programme");
	affichage(42, 14);
	printf("-----------Fa%ctes votre choix", 140);
}

void principal(){
	int choix;
	do{
		menuPrincipal();
		choix = testChoix(43, 15);
		switch(choix)
		{
			case 0: {
				exit(0);
			}
			case 1: {
				gestionCours();
				break;
			}
			case 2: {
				gestionEtudiants();
				break;
			}
			case 3: {
				gestionEnseignants();
			break;
			}
			case 4: {
				gestionEvaluation();
				break;
			}
			case 5: {
				gestionNotes();
				break;
			}
			case 6: {
				main();
				break;
			}
			default: {
				system("cls");
				affichage(30, 9);
				printf("Mauvais choix, Veuillez r%cessayez !!", 130);
				affichage(30,10);
				system("pause");
			}
		}
	}while(choix >= 0 || choix <= 6);
}

int main()
{
	bienvenue();
	principal();
	return 0;
}


