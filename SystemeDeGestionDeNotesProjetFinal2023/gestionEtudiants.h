#ifndef GESTIONETUDIANTS_H_INCLUDED
#define GESTIONETUDIANTS_H_INCLUDED
#include "prototypes.h"
#include "Autres.h"
#include "contraintes.h"
#include "gestionEtudiants.h"

////////////////////////////////////////////////////
int menuGestionEtudiant()
{
    int choix = -1;
    system("cls");
    affichageEntete();
    affichage(43, 6);
    printf("========= Menu Gestion %ctudiant =========", 144);
    affichage(43, 8);
    printf("1. Enregistrer %ctudiants", 130);
    affichage(43, 9);
    printf("2. Lister les %ctudiants", 130);
    affichage(43, 10);
    printf("3. Afficher les informations d'un %ctudiant donn%c", 130, 130);
    affichage(43, 11);
    printf("4. Assigner un cours %c un %ctudiant", 133, 130);
    affichage(43, 12);
    printf("5. Afficher la liste des cours d'un %ctudiant", 130);
    affichage(43, 13);
    printf("6. D%csassigner un cours %c un %ctudiant", 130, 133, 130);
    affichage(43, 14);
    printf("0. Retour ou Menu Principal");
    affichage(43, 15);
    printf("------------Fa%ctes votre choix", 140);

    int h = 43, l = 16;
    choix = testChoix(h, l);

    return choix;
}

////////////////////////////////////////////////////
void gestionEtudiants()
{
    int choix;
    do{
        system("cls");
        choix = menuGestionEtudiant();

        switch(choix){
            case 0: {
                principal();
                break;
            }
            case 1: {
                enregistrerEtudiants();
                break;
            }
            case 2: {
                listerEtudiants();
                break;
            }
            case 3: {
                afficherInfoEtudiant();
                break;
            }
            case 4: {
               assignerCoursEtudiants();
                break;
            }
            case 5: {
                afficherListeCoursEtudiants();
                break;
            }
            case 6: {
                desasignerCoursEtudiants();
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

////////////////////////////////////////////////////
void enregistrerEtudiants()
{
    char nom[50], prenom[50], sexe[2], tel[12], area[15] = "+509", id_etud[12], n[5], n1[5];
    char x[5] = "", x1[5] = "", x2[10] = "", x3[5] = "";

    system("cls");
    affichageEntete();

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer %ctudiants ==========", 144);
        affichage(43, 8);
        printf("Entrer le nom de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(nom);
    }while(lenChaine(nom) > 0 || testAlpha(nom) > 0);
    strcpy(etud.nom, nom);

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer %ctudiants ==========", 144);
        affichage(43, 8);
        printf("Entrer le pr%cnom de l'%ctudiant :", 130, 130);
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(prenom);
    }while(lenChaine(prenom) > 0 || testChampVide(prenom) > 0 || testAlpha(prenom) > 0);
    strcpy(etud.prenom, prenom);

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer %ctudiants ==========", 144);
        affichage(43, 8);
        printf("Entrer le sexe de l'%ctudiant (M ou F):", 130);
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(sexe);
    }while(testChampVide(sexe) > 0 || testSexe(sexe) > 0);

    if(strcasecmp(sexe, "F") == 0){
        strcpy(etud.sexe, "F");
    }
    else{
        strcpy(etud.sexe, "M");
    }

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer %ctudiants ==========", 144);
        affichage(43, 8);
        printf("Entrer le num%cro de t%cl%cphone de l'%ctudiant :", 130, 130, 130, 130);
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(tel);
    }while(testTel(tel) > 0 || testChampVide(tel) > 0 || testDigit(tel) > 0);
    strcat(area, tel);
    strcpy(etud.tel, area);

    strcpy(x2, (strcat(strcat(strncpy(x, nom, 3), strncpy(x1, prenom, 3)), "_")));
    strcat(x2, (itoa(aleatoire(), x3, 10)));
    strcpy(id_etud, x2);

    strcpy(etud.idEtud, id_etud);

    do{
        system("cls");
        afficherEnteteEtudiant();
        affichage(1, 4);
        printf("%s", etud.idEtud);
        affichage(15, 4);
        printf("%s", etud.nom);
        affichage(45, 4);
        printf("%s", etud.prenom);
        affichage(65, 4);
        printf("%s", etud.sexe);
        affichage(85, 4);
        printf("%s", etud.tel);
        affichage(40, 14);
        printf("Veuillez confirmer l'enregistrement (1.oui   2.non)");
        affichage(40, 15);
        printf("((             ))");
        affichage(43, 15);
        gets(n);

        if(strlen(n) == 1 && n[0] == '1'){
            // j'ouvre le fichier
            fichEtudiants = fopen(fichierEtudiants, "a+");
            //Verification de l'ouverture du fichier etudiant
            if(!(fichEtudiants)){
                    system("cls");
                    affichage(40, 16);
                    printf("Impossible d'ouvrir le fichier etudiants !!");
                    affichage(40, 17);
                    system("pause");
            }
            if(fichEtudiants){
                fprintf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);
                fclose(fichEtudiants);
                affichage(40, 17);
                printf("Enregistrement fait avec succ%cs !!\n", 137);
                affichage(40, 18);
                system("pause");
                break;
            }
        }
        else if(strlen(n) == 1 && n[0] == '2'){
            system("cls");
            affichage(40, 10);
            printf("Enregistrement annul%c", 130);
            affichage(40, 11);
            system("pause");
            break;
        }
        else{
            affichage(40, 18);
            printf("Mauvais choix, vous devez taper 1 pour (oui) ou 2 pour (non)");
            affichage(40, 19);
            system("pause");
        }
    }while((n[0] != '1' && n[0] != '2') || testChampVide(n) > 0 || strlen(n) != 1);

    system("cls");
    affichage(20, 8);
    printf("voulez-vous enregistrer un autre etudiant ? (Taper 1 pour oui ou une autre touche pour non)");
    affichage(40, 9);
    printf("((         ))");
    affichage(43, 9);
    gets(n1);
    if(n1[0] == '1' && strlen(n1) == 1){
        enregistrerEtudiants();
    }
    else{
        gestionEtudiants();
    }

}

////////////////////////////////////////////////////
void listerEtudiants()
{
    int k = 4;

    afficherEnteteEtudiant();

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier etudiants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEtudiants){
        while( !(feof(fichEtudiants)) ){
                fscanf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);
                affichage(1, k);
                printf("%s", etud.idEtud);
                affichage(15, k);
                printf("%s", etud.nom);
                affichage(45, k);
                printf("%s", etud.prenom);
                affichage(65, k);
                printf("%s", etud.sexe);
                affichage(85, k);
                printf("%s", etud.tel);
                k++;
        }
        fclose(fichEtudiants);
    }
    affichage(30, k+1);
    system("pause");
}

////////////////////////////////////////////////////
void afficherInfoEtudiant()
{
    char idEtud[12];

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister %ctudiant ==========", 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier etudiants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEtudiants){
        while( !(feof(fichEtudiants)) ){
            fscanf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);

            if( strcasecmp(idEtud, etud.idEtud) == 0){
                system("cls");
                afficherEnteteEtudiant();
                affichage(1, 4);
                printf("%s", etud.idEtud);
                affichage(15, 4);
                printf("%s", etud.nom);
                affichage(45, 4);
                printf("%s", etud.prenom);
                affichage(65, 4);
                printf("%s", etud.sexe);
                affichage(85, 4);
                printf("%s", etud.tel);
                break;
            }
            if(feof(fichEtudiants)){
                affichage(40, 13);
                printf("Ce code n'est pas dans la liste.");
            }
        }
        fclose(fichEtudiants);
        affichage(45, 13);
        system("pause");
    }
}

////////////////////////////////////////////////////
void assignerCoursEtudiants()
{
    char idEtud[12], id_cours[15], x[5] = "", x2[10] = "", x3[5] = "", idaff[15], n1[10];
    int r = 0, r1 = 0, r2 = 0;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section assignation cours %c un %ctudiant ==========", 133, 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier etudiants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEtudiants){
        while( !(feof(fichEtudiants)) ){
            fscanf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);

            if(strcasecmp(etud.idEtud, idEtud) == 0){
                r = 1;
                break;
            }

            if(feof(fichEtudiants)){
                system("cls");
                affichage(30, 10);
                printf("L'Identifiant de l'etudiant est introuvable !!");
                affichage(30, 11);
                system("pause");
            }
        }
        fclose(fichEtudiants);
    }

    if( r == 1){
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section assignation cours %c un %ctudiant ==========", 133, 130);
            affichage(43, 8);
            printf("Entrer l'Id cours :");
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(id_cours);
        }while(testChampVide(id_cours) > 0);

        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichCours){
            while( !(feof(fichCours)) ){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);

                if(strcasecmp(cours.id_cours, id_cours) == 0){
                    r1 = 1;
                    break;
                }

                if( feof(fichCours)){
                    system("cls");
                    affichage(30, 10);
                    printf("L'Identifiant du cours est introuvable !!");
                    affichage(30, 11);
                    system("pause");
                }
            }
            fclose(fichCours);
        }
    }

    if( r == 1 && r1 == 1){//r1 = 1 <==> r = 1
        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
        if(fichAffectationEtudiants){
            while( !(feof(fichAffectationEtudiants))){
                fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                if((strcasecmp(affEtud.id_etud, idEtud) == 0) && (strcasecmp(affEtud.id_cour, id_cours) == 0)){
                    r2 = 1;
                }
            }
            fclose(fichAffectationEtudiants);
        }

        if(r2 != 1){
            //création de l'Id aff
            strcpy(x2, strcat(strncpy(x, "aff", 3), "_"));
            strcat(x2, (itoa(aleatoire(), x3, 5)));
            strcpy(idaff, x2);
            strcpy(affEtud.id, idaff);

            strcpy(affEtud.id_cour, cours.id_cours);
            strcpy(affEtud.id_etud, etud.idEtud);

            fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "a+");

            if(!(fichAffectationEtudiants)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours %ctudiants !!", 130);
                affichage(40, 17);
                system("pause");
            }

            if(fichAffectationEtudiants){
                fprintf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                affichage(30, 13);
                printf("Affectation faite avec succ%cs", 138);
                affichage(30, 14);
                system("pause");
                fclose(fichAffectationEtudiants);
            }
        }
        else{
            affichage(30, 13);
            printf("Ce cours %c d%cj%c %ct%c assign%c %c l'%ctudiant!!", 133, 130, 133, 130, 130, 130, 133, 130);
            affichage(30, 14);
            system("pause");
        }
        system("cls");
        affichage(20, 8);
        printf("voulez-vous faire une autre assignation ? (Taper 1 pour oui ou une autre touche pour non)");
        affichage(40, 9);
        printf("((         ))");
        affichage(43, 9);
        gets(n1);
        if(n1[0] == '1' && strlen(n1) == 1){
            assignerCoursEtudiants();
        }
        else{
            gestionEtudiants();
        }

    }
}

////////////////////////////////////////////////////
void afficherListeCoursEtudiants()
{
    char idEtud[12];
    int k = 8, ind = 1;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section afficher liste cours %ctudiant ==========", 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

    fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
    if(!(fichAffectationEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier Affectations cours %ctudiants !!", 130);
        affichage(40, 17);
        system("pause");
    }

    fichCours = fopen(fichierCours, "r");
    if(!(fichCours)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier cours !!");
        affichage(40, 17);
        system("pause");
    }

    system("cls");
    if(fichAffectationEtudiants && fichCours){
        while(!(feof(fichAffectationEtudiants))){
            fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
            if(strcasecmp(affEtud.id_etud, idEtud) == 0){
                while(!(feof(fichCours))){
                    fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                    if(strcasecmp(affEtud.id_cour, cours.id_cours) == 0){
                        affichage(30, 6);
                        printf("La liste des cours de %s est/sont :", affEtud.id_etud);
                        affichage(30, k);
                        printf("%d. %s\n", ind, cours.nom);
                        k++;
                        ind++;
                    }
                }
                fseek(fichCours, 0, SEEK_SET);
            }
        }
        fclose(fichAffectationEtudiants);
        fclose(fichCours);

        if(k == 8){
            system("cls");
            affichage(30, k+1);
            printf("Cet %ctudiant n'a pas de cours qui lui est associ%c !!", 130, 130);
        }
        affichage(30, k+2);
        system("pause");
    }
}

////////////////////////////////////////////////////
void desasignerCoursEtudiants()
{
    char idEtud[15], id_cours[15];
    int r = 0, r1 = 0;
    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section D%csassign%c un cours %c un %ctudiant ==========", 130, 130, 133, 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

    fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
    if(!(fichAffectationEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichAffectationEtudiants){
        while( !(feof(fichAffectationEtudiants))){
            fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
            if(strcasecmp(affEtud.id_etud, idEtud) == 0){
                r = 1;
            }
        }
        fclose(fichAffectationEtudiants);
    }

    if( r == 1){
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section Section D%csassign%c un cours %c un %ctudiant ==========", 130, 130, 133, 130);
            affichage(43, 8);
            printf("Entrer l'Id du cours que vous voulez d%csassigner %c l'%ctudiant:", 130, 133, 130);
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(id_cours);
        }while(testChampVide(id_cours) > 0);

        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichAffectationEtudiants){
            while( !(feof(fichAffectationEtudiants))){
                fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                if(strcasecmp(affEtud.id_etud, idEtud) == 0 && strcasecmp(affEtud.id_cour, id_cours) == 0){
                    strcpy(affEtud1.id, affEtud.id);
                    strcpy(affEtud1.id_etud, affEtud.id_etud);
                    strcpy(affEtud1.id_cour, affEtud.id_cour);
                    r1 = 1;
                }
            }
            fclose(fichAffectationEtudiants);
        }
    }

    if(r == 1 && r1 == 1){
        fichAffectationEtudiantsBcp = fopen(fichierAffectationsEtudiantsBcp, "w");
        if(!(fichAffectationEtudiantsBcp)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier backup !!");
            affichage(40, 17);
            system("pause");
        }

        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichAffectationEtudiants && fichAffectationEtudiantsBcp){
            while( !(feof(fichAffectationEtudiants))){
                fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);

                if(!(strcasecmp(affEtud.id_etud, idEtud) == 0 && strcasecmp(affEtud.id_cour, id_cours) == 0)){
                    fprintf(fichAffectationEtudiantsBcp, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                }
            }
            fclose(fichAffectationEtudiantsBcp);
            fclose(fichAffectationEtudiants);
        }

        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "w");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }

        fichAffectationEtudiantsBcp = fopen(fichierAffectationsEtudiantsBcp, "r");
        if(!(fichAffectationEtudiantsBcp)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier backup !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichAffectationEtudiants && fichAffectationEtudiantsBcp){
            while( !(feof(fichAffectationEtudiantsBcp))){
                fscanf(fichAffectationEtudiantsBcp, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                fprintf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
            }
            fclose(fichAffectationEtudiants);
            fclose(fichAffectationEtudiantsBcp);

            system("cls");
            affichage(30, 10);
            printf("D%csassignation r%cusssi !!", 130, 130);
            affichage(30, 11);
            system("pause");
        }

        fichCoursDesassigner = fopen(fichierCoursDesassigner, "a+");
        if(!(fichCoursDesassigner)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours D%csassigner !!", 130);
            affichage(40, 17);
            system("pause");
        }
        if(fichCoursDesassigner){
            fprintf(fichCoursDesassigner, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud1.id, affEtud1.id_etud, affEtud1.id_cour);
            fclose(fichCoursDesassigner);
        }
    }

    if(r != 1){
        system("cls");
        affichage(40, 16);
        printf("Cet id n'est pas dans la liste des affectations");
        affichage(40, 17);
        system("pause");
    }
    if((r = 1 && r1 != 1)){
        system("cls");
        affichage(40, 16);
        printf("Ce cours n'est pas affect%c %c cet Id %ctudiant ! !", 130, 133, 130);
        affichage(40, 17);
        system("pause");
    }

}

////////////////////////////////////////////////////


#endif // GESTIONETUDIANTS_H_INCLUDED
