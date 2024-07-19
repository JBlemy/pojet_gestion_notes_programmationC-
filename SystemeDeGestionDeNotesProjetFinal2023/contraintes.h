#ifndef CONTRAINTES_H_INCLUDED
#define CONTRAINTES_H_INCLUDED
#include "prototypes.h"
#include "Autres.h"
#include "gestionEtudiants.h"
#include "gestionsEnseignants.h"

////////////////////////////////////////////////////
int testChoix(int h, int l)
{
    char choix[5];        //pour stocker la valeur saisir par l'user
    int choix1;          //pour appeler la fonction testDigit sur cette valeur
    int conversion = -1;// pour convertir la valeur de l'User en int
    affichage(h, l);
    printf("((               ))");
    affichage(h+3, l);
    gets(choix);
    choix1 = testDigit(choix);     //regarder si ce sont des chiffres
    if(choix1 == 0){
        conversion = atoi(choix);// de toute façon si ce sont pas uniquement des chiffres
    }                           // la fonction testDigit devrait la bloquer, la conversion reussira
    return conversion;
}

////////////////////////////////////////////////////
int testDigit(char entrer[])
{
    int n = testChampVide(entrer), i; //tester si le champ est vide
    if(n == 0){
        for(i = 0; i < strlen(entrer); i++){
            if(!(isdigit(entrer[i]))){
                n++;
            }
        }
        if(n > 0){
            system("cls");
            affichage(10, 17);
            printf("Ce champ peut prendre que des chiffres!!!\n\n");
            system("pause");
        }
    }
    return n;
}

////////////////////////////////////////////////////
int testAlpha(char chaine[])
{
    int n = 0, i;
    for(i = 1; i <= strlen(chaine)-1; i++)
    {
        if((!(isalpha(chaine[i])) && chaine[i] != '-' && chaine[i] != ' ' && chaine[i] != '\'') || !(isalpha(chaine[0])))
        {
            system("cls");
            printf("Ce champ doit contenir que des lettres !!\n");
            system("pause");
            n++;
            break;
        }
    }
    return n;
}

////////////////////////////////////////////////////
int testChampVide(char a[])
{
    int n=0;
    if(strcasecmp(a,"") == 0 || strlen(a) == 0 || a[0] == '\0'){
        system("cls");
        printf("Ce champ ne doit pas %ctre vide !!!\n", 137);
        system("pause");
        n++;
    }
    return n;
}

////////////////////////////////////////////////////
int lenChaine(char chaine[])
{
    int n = 0;
    if ( strlen(chaine) < 3)
    {
        n++;
        system("cls");
        printf("La chaine est trop courte !!\n");
        system("pause");
    }
    return n;
}

////////////////////////////////////////////////////
int testTel(char chaine[]){
    int n = 0;
    if( (chaine[0] != '2' && chaine[0] != '3' && chaine[0] != '4' && chaine[0] != '5') || strlen(chaine) != 8){
        n++;
        system("cls");
        affichage(30, 10);
        printf("Ce num%cro de t%cl%cphone n'est pas valide. Veuillez r%cessayez !!", 130, 130, 130, 130);
        affichage(30, 11);
        system("pause");
    }
    return n;
}

////////////////////////////////////////////////////
int testSexe(char sexe[]){
    int n = 0;
    if( (toupper(sexe[0]) != 'F' && toupper(sexe[0]) != 'M') || strlen(sexe) != 1){
        system("cls");
        affichage(30, 10);
        printf("Mauvais choix, le sexe d'un %ctudiant doit %ctre M ou F", 130, 136);
        affichage(30, 11);
        system("pause");
        n++;
    }
    return n;
}

////////////////////////////////////////////////////
int testDigitDouble(char chaine[])//pour tester si le salaire n'est pas un double
{
    int n = testChampVide(chaine), i; //tester si le champ est vide
    if(n == 0){
        for(i = 1; i < strlen(chaine); i++){
            if((!(isdigit(chaine[i])) && chaine[i] != '.') || chaine[0] == '.' || !(isdigit(chaine[0]))){
                n++;
            }
        }
        if(n > 0){
            system("cls");
            affichage(10, 17);
            printf("Ce champ peut prendre que des chiffres avec ou sans point '.' !!!\n\n");
            system("pause");
        }
    }
    return n;
}

////////////////////////////////////////////////////


#endif // CONTRAINTES_H_INCLUDED
