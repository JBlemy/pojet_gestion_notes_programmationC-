#ifndef AUTRES_H_INCLUDED
#define AUTRES_H_INCLUDED
#include "prototypes.h"
#include "contraintes.h"

////////////////////////////////////////////////////
void affichage(int h, int l){
	HANDLE affiche;
	COORD position;
	position.X = h;
	position.Y = l;
	affiche = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(affiche, position);
}

////////////////////////////////////////////////////
void affichageEntete(){
	affichage(30, 1);
	printf("	===== PROJET FINAL - SYSTEME DE GESTION DE NOTES DES ETUDIANTS =====\n");
	affichage(43, 2);
	printf("===== ANNEE 2022 - 2023 DEUXIEME SESSION =====");
	affichage(35, 3);
	printf("PREPARE PAR : Albikendy JEAN, Bendy SERVILUS et Blemy JOSEPH");
}

////////////////////////////////////////////////////
void afficherEnteteEnseignant()
{
	system("cls");
	affichage(1, 2);
	printf("Id");
	affichage(15, 2);
	printf("NOM");
	affichage(45, 2);
	printf("PRENOM");
	affichage(65, 2);
	printf("SALAIRE");
	affichage(85, 2);
	printf("TELEPHONE");
}

////////////////////////////////////////////////////
void afficherEnteteEtudiant()
{
	system("cls");
	affichage(1, 2);
	printf("Id");
	affichage(15, 2);
	printf("NOM");
	affichage(45, 2);
	printf("PRENOM");
	affichage(65, 2);
	printf("Sexe");
	affichage(85, 2);
	printf("TELEPHONE");
}

////////////////////////////////////////////////////
void afficherEnteteCours()
{
	system("cls");
	affichage(1, 2);
	printf("ID");
	affichage(40, 2);
	printf("Nom du cours");
	affichage(100, 2);
	printf("Coefficient");
}

////////////////////////////////////////////////////
void afficherEnteteEvaluation()
{
	system("cls");
	affichage(1, 2);
	printf("ID");
	affichage(15, 2);
	printf("ID COURS");
	affichage(45, 2);
	printf("NOM COURS");
	affichage(65, 2);
	printf("TYPE");
	affichage(85, 2);
	printf("PONDERATION");
}

////////////////////////////////////////////////////
void afficherEnteteNote(){
	system("cls");
	affichage(1, 2);
	printf("ID Note");
	affichage(15, 2);
	printf("ID %cvaluation", 144);
	affichage(45, 2);
	printf("ID COURS");
	affichage(65, 2);
	printf("ID %ctudiant", 144);
	affichage(85, 2);
	printf("Note");
	affichage(95, 2);
	printf("Type");
}

////////////////////////////////////////////////////
int aleatoire(){
	srand(time(NULL));
	int a=rand()%(1000-1)+(1);
	int b=rand()%(1000-1)+(1);
	int c=rand()%(1000-1)+(1);
	int d=rand()%(1000-1)+(1);
	int t=a+b+c+d;

	return t;
}

////////////////////////////////////////////////////
int aleatoire2(){
	srand(time(NULL));
	int a=rand()%(33);
	int b=rand()%(33);
	int c=rand()%(33);
	int t=a+b+c;

	return t;
}

////////////////////////////////////////////////////

#endif // AUTRES_H_INCLUDED
