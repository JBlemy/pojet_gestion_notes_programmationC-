#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//les pointeurs de fichiers
FILE *fichEnseignant, *fichEnseignantBcp, *fichEnseignantRevoquer, *fichEtudiants, *fichEtudiantsBcp;
FILE *fichCours, *fichCoursBcp, *fichAffectationEtudiants, *fichAffectationEtudiantsBcp, *fichEvaluation, *fichNoteEvalAnnuler;
FILE *fichCoursDesassigner, *fichAffectationEnseignant, *fichAffectationEnseignantBcp, *fichCoursEnseignantRevoquer;
FILE *fichEvaluationBcp, *fichEvaluationAnnuler, *fichNote, *fichNoteBcp, *fichNoteFinale, *fichNoteFinaleBcp, *fichNoteFinaleBcp1;

////////////////////////Les Fichiers en .txt avec leurs emplacements////////////////////////////////////
///////////////////////Ex: Donnees//note.tx ==> Folder = Donnees et NomFichier = note.txt////////////////

char fichierEnseignants[]="Donnees//enseignants.txt";
char fichierEnseignantsBcp[]="Backup//enseignantbcp.txt";
char fichierEnseignantRevoquer[]="Donnees//enseignantRevoquer.txt";
char fichierEtudiants[]="Donnees//etudiants.txt";
char fichierEtudiantsBcp[]="Backup//etudiantsBcp.txt";
char fichierCours[]="Donnees//cours.txt";
char fichierCoursBcp[]="Backup//coursBcp.txt";
char fichierAffectationsEtudiants[]="Donnees//affectationCoursEtudiants.txt";
char fichierAffectationsEtudiantsBcp[]="Backup//affectationCoursEtudiantsBcp.txt";
char fichierCoursDesassigner[]="Donnees//coursDesassignerEtudiants.txt";
char fichierAffectationsEnseignant[]="Donnees//affectationCoursEnseignant.txt";
char fichierAffectationsEnseignantBcp[]="Backup//affectionCoursEnseignantBcp.txt";
char fichierCoursEnseignantRevoquer[]="Donnees//coursEnseignantRevoquer.txt";
char fichierEvaluation[]="Donnees//evaluations.txt";
char fichierEvaluationBcp[]="Backup//evaluationBcp.txt";
char fichierEvaluationAnnuler[]="Donnees//evaluationAnnuler.txt";
char fichierNote[]="Donnees//notes.txt";
char fichierNoteBcp[]="Backup//notesBcp.txt";
char fichierNoteFinale[]="Donnees//notesFinales.txt";
char fichierNoteFinaleBcp[]="Backup//notesFinalesBcp.txt";
char fichierNoteFinaleBcps[]="Backup//notesFinalesBcpsss.txt";
char fichierNoteEvalAnnuler[]="Donnees//notesEvaluationAnnuler.txt";

///////////////////////Les différentes structures//////////////////////////////////
typedef struct enseignant
{
    char id_ens[15];
    char nom[50];
    char prenom[50];
    char tel[12];
    double salaire;
}enseignants;
enseignants ens, ens1;

typedef struct etudiants
{
    char idEtud[15];
    char nom[50];
    char prenom[50];
    char sexe[3];
    char tel[12];
}etudiants;
etudiants etud, etud1, etud2;

typedef struct Cours
{
    char id_cours[15];
    char nom[80];
    int cofficient;
}Cours;
Cours cours, cours1;

typedef struct notes
{
    int idNote;
    char id_eval[15];
    char id_cours[15];
    char idEtud[15];
    float note;
}notes;
notes point, point1, point2, point3, point4, point5;

typedef struct evaluations
{
    char id_eval[15];
    char id_cours[15];
    char nom_cours[80];
    char type[8];
    float ponderation;
}evaluations;
evaluations eval, eval1;

typedef struct affectationCoursEtud
{
   char id[15];
   char id_etud[15];
   char id_cour[15];
}affectationCoursEtud;
affectationCoursEtud affEtud, affEtud1;

typedef struct affectationCoursEns
{
    char id[15];
    char id_ens[15];
    char id_cours[15];
}affectationCoursEns;
affectationCoursEns affEns;

////////////////////////Les Fonctions/////////////////////////////////

////////////////////////////Les enseignants////////////////////////////
int menuGestionEnseignant();
void afficherEnteteEnseignant();
void gestionEnseignants();
void enregistrerEnseignants();
void ListerEnseignants();
void afficherInfoEnseignant();
void afficherListeCoursEnseignant();
void revoquerEnseignants();
void augmenterSalaireEnseignant();
void assignerCoursEnseignant();
void afficherListeCoursEnseignant();

////////////////////////////Les etudiants////////////////////////////
int menuGestionEtudiant();
void gestionEtudiants();
void enregistrerEtudiants();
void afficherEnteteEtudiant();
void listerEtudiants();
void afficherInfoEtudiant();
void afficherEtudiantCours();

////////////////////////////Cours////////////////////////////
int menuGestionCours();
void gestionCours();
void afficherEnteteCours();
void enregistrerCours();
void listerCours();
void afficherInfoCours();
void modifierCoefficientCours();
void assignerCoursEtudiants();
void afficherListeCoursEtudiants();
void desasignerCoursEtudiants();

////////////////////////////Evaluations////////////////////////////
void afficherEnteteEvaluation();
int menuGestionEvaluations();
void gestionEvaluation();
void programmerEvaluation();
void listerCours_a_Evaluer();
void listerDetailEvaluation();
void annulerEvaluation();

////////////////////////////Notes////////////////////////////
void afficherEnteteNote();
int menuGestionNotes();
void gestionNotes();
void enregistrerNotes();
void listerNotes();
void listerNoteCours();
void listerNoteEtudiant();
void listerNoteEtudiantCours();
void modifierNoteEtudiant();
void moyenneEtudiant();

////////////////////////////Contraintes////////////////////////////
int testChoix(int h, int l);
int testChampVide(char champ[]);
int testDigit(char entrer[]);
int lenChaine(char chaine[]);
int testAlpha(char chaine[]);
int testTel(char chaine[]);
int testSexe(char sexe[]);
int testDigitDouble(char chaine[]);

////////////////////////////Autres////////////////////////////
void bienvenue();
void principal();
void affichageEntete();
void affichage(int h, int l);
int aleatoire();
int aleatoire2();
int main();
void menuPrincipal();


#endif // PROTOTYPES_H_INCLUDED
