#ifndef GESTIONSENSEIGNANTS_H_INCLUDED
#define GESTIONSENSEIGNANTS_H_INCLUDED
#include "prototypes.h"
#include "Autres.h"
#include "contraintes.h"
#include "gestionEtudiants.h"
////////////////////////////////////////////////////
int menuGestionEnseignant()
{
    system("cls");
    int h = 44, l = 17;
    int choix = -1;
    affichageEntete();
    affichage(43, 6);
    printf("========= Menu Gestion Enseignants =========");
    affichage(43, 8);
    printf("1. Enregistrer enseignants");
    affichage(43, 9);
    printf("2. Lister les enseignants");
    affichage(43, 10);
    printf("3. Afficher les informations d'un enseignant donn%c", 130);
    affichage(43, 11);
    printf("4. Assign%c un cours %c un enseignant :", 130, 133);
    affichage(43, 12);
    printf("5. Afficher la liste des cours dispens%cs par un enseignant", 130);
    affichage(43, 13);
    printf("6. R%cvoquer un enseignant", 130);
    affichage(43, 14);
    printf("7. Augmenter de 10%% le salaire des enseignants");
    affichage(43, 15);
    printf("0. Retour au menu Principal");
    affichage(43, 16);
    printf("------------Fa%ctes votre choix", 140);
    choix = testChoix(h, l);

    return choix;
}

////////////////////////////////////////////////////
void gestionEnseignants()
{
    int choix;
    do {
        choix = menuGestionEnseignant();
        switch(choix) {

        case 0: {
            principal();
            break;
        }
        case 1: {
            enregistrerEnseignants();
            break;
        }
        case 2: {
            ListerEnseignants();
            break;
        }
        case 3: {
            afficherInfoEnseignant();
            break;
        }

        case 4: {
            assignerCoursEnseignant();
            break;
        }
        case 5: {
            afficherListeCoursEnseignant();
            break;
        }
        case 6: {
            revoquerEnseignants();
            break;
        }
        case 7: {
            augmenterSalaireEnseignant();
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
    } while(choix >= 0 || choix <= 7);
}

////////////////////////////////////////////////////
void enregistrerEnseignants()
{
    char id_ens[12], nom[50], prenom[50], n1[5], n[10], tel[12], area[15]= "+509";
    char x[5] = "", x1[5] = "", x2[10] = "", x3[5] = "", salaire[10];

    system("cls");
    affichageEntete();

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer enseignant ==========");
        affichage(43, 8);
        printf("Entrer le nom de l'enseignant :");
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(nom);
    } while(lenChaine(nom) > 0 || testChampVide(nom) > 0 || testAlpha(nom) > 0);
    strcpy(ens.nom, nom);

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer enseignant ==========");
        affichage(43, 8);
        printf("Entrer le pr%cnom de l'enseignant :", 130);
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(prenom);
    } while(lenChaine(prenom) > 0 || testChampVide(prenom) > 0 || testAlpha(prenom) > 0);
    strcpy(ens.prenom, prenom);

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer enseignant ==========");
        affichage(35, 8);
        printf("Entrer le num%cro de t%cl%cphone de l'enseignant sans l'area code :", 130, 130, 130);
        affichage(43, 9);
        printf("((                                   ))");
        affichage(46, 9);
        gets(tel);
    } while(testTel(tel) > 0 || testChampVide(tel) > 0);
    strcat(area, tel);
    strcpy(ens.tel, area);

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer enseignant ==========");
        affichage(43, 8);
        printf("Entrer le salaire  de l'enseignant :");
        affichage(43, 9);
        printf("((                                      ))");
        affichage(46, 9);
        gets(salaire);
        ens.salaire = strtod(salaire, NULL);
        if( ens.salaire == 0.0 || ens.salaire < 0) {
            system("cls");
            affichage(43, 12);
            printf("Erreur !! Veuillez entrer un salaire valide !!");
            system("pause");
        }
    } while(ens.salaire == 0.0 || testDigitDouble(salaire) > 0 || ens.salaire < 0);

    strcpy(x2, (strcat(strcat(strncpy(x, nom, 3), strncpy(x1, prenom, 3)), "_")));
    strcat(x2, (itoa(aleatoire(), x3, 10)));
    strcpy(id_ens, x2);

    strcpy(ens.id_ens, id_ens);


    do {
        system("cls");
        afficherEnteteEnseignant();
        affichage(1, 4);
        printf("%s", ens.id_ens);
        affichage(15, 4);
        printf("%s", ens.nom);
        affichage(45, 4);
        printf("%s", ens.prenom);
        affichage(65, 4);
        printf("%.2f", ens.salaire);
        affichage(85, 4);
        printf("%s", ens.tel);


        affichage(40, 14);
        printf("Veuillez confirmer l'enregistrement (1.oui   2.non)");
        affichage(40, 15);
        printf("((             ))");
        affichage(43, 15);
        gets(n);

        if(strlen(n) == 1 && n[0] == '1') {
            // j'ouvre le fichier
            fichEnseignant = fopen(fichierEnseignants, "a+");
            //Verification de l'ouverture du fichier enseignant
            if(!(fichEnseignant)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier enseignants !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichEnseignant){
                fprintf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%.2f\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, ens.salaire, ens.tel);
                fclose(fichEnseignant);
                affichage(40, 17);
                printf("Enregistrement fait avec succ%cs !!\n", 137);
                system("pause");
                break;
            }
        }
        else if(strlen(n) == 1 && n[0] == '2') {
            system("cls");
            affichage(40, 10);
            printf("Enregistrement annul%c", 130);
            system("pause");
            break;
        } else{
            affichage(40, 18);
            printf("Mauvais choix, vous devez taper 1 pour (oui) ou 2 pour (non)");
            affichage(40, 19);
            system("pause");
        }
    }while((n[0] != '1' && n[0] != '2') || testChampVide(n) > 0 || strlen(n) != 1);

    system("cls");
    affichage(20, 8);
    printf("voulez-vous enregistrer un autre enseignant ? (Taper 1 pour oui ou une autre touche pour non)");
    affichage(40, 9);
    printf("((         ))");
    affichage(43, 9);
    gets(n1);

    if(n1[0] == '1' && strlen(n1) == 1) {
        enregistrerEnseignants();
    }
    else{
        gestionEnseignants();
    }

}

////////////////////////////////////////////////////
void ListerEnseignants()
{
    int k = 4;

    afficherEnteteEnseignant();

    fichEnseignant = fopen(fichierEnseignants, "r");
    if(!(fichEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier etudiants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEnseignant){
        while( !(feof(fichEnseignant)) ) {
            fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);
            affichage(1, k);
            printf("%s", ens.id_ens);
            affichage(15, k);
            printf("%s", ens.nom);
            affichage(45, k);
            printf("%s", ens.prenom);
            affichage(65, k);
            printf("%.2f", ens.salaire);
            affichage(85, k);
            printf("%s", ens.tel);
            k++;
        }
        fclose(fichEnseignant);
        affichage(30, k+1);
        system("pause");
    }

}

////////////////////////////////////////////////////
void afficherInfoEnseignant()
{
    char id_ens[12];

    fichEnseignant = fopen(fichierEnseignants, "r");

    if(!(fichEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier etudiants !!");
        affichage(40, 17);
        system("pause");
    }

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister enseignant ==========");
        affichage(43, 8);
        printf("Entrer l'Id de l'enseignant :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(id_ens);
    } while(testChampVide(id_ens) > 0);

    if(fichEnseignant){
        while( !(feof(fichEnseignant)) ) {
            fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);

            if( strcasecmp(id_ens, ens.id_ens) == 0) {
                system("cls");
                afficherEnteteEnseignant();
                affichage(1, 4);
                printf("%s", ens.id_ens);
                affichage(15, 4);
                printf("%s", ens.nom);
                affichage(45, 4);
                printf("%s", ens.prenom);
                affichage(65, 4);
                printf("%.2f", ens.salaire);
                affichage(85, 4);
                printf("%s", ens.tel);
                break;
            }
            if(feof(fichEnseignant)) {
                affichage(40, 13);
                printf("Ce code n'est pas dans la liste.");
            }
        }
        fclose(fichEnseignant);
        affichage(45, 13);
        system("pause");
    }
}

////////////////////////////////////////////////////
void assignerCoursEnseignant()
{
    char idEns[12], id_cours[15], x[5] = "", x2[10] = "", x3[5] = "", idaff[15], n1[10];
    int r = 0, r1 = 0, r2 = 0;
    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section assignation cours %c un enseignant ==========", 133);
        affichage(43, 8);
        printf("Entrer l'Id de l'enseignant :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEns);
    } while(testChampVide(idEns) > 0);

    fichEnseignant = fopen(fichierEnseignants, "r");
    if(!(fichEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier enseignant !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEnseignant){
        while( !(feof(fichEnseignant)) ) {
            fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);

            if(strcasecmp(ens.id_ens, idEns) == 0) {
                r = 1;
                break;
            }

            if(feof(fichEnseignant)) {
                system("cls");
                affichage(30, 10);
                printf("L'Identifiant de l'enseignant est introuvable !!");
                affichage(30, 11);
                system("pause");
            }
        }
        fclose(fichEnseignant);
    }

    if( r == 1) {
        do {
            system("cls");
            affichage(43, 6);
            printf("=========== Section assignation cours %c un enseignant ==========", 133);
            affichage(43, 8);
            printf("Entrer l'Id cours :");
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(id_cours);
        } while(testChampVide(id_cours) > 0);

        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichCours){
            while( !(feof(fichCours)) ) {
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);

                if(strcasecmp(cours.id_cours, id_cours) == 0) {
                    r1 = 1;
                    break;
                }

                if( feof(fichEtudiants)) {
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

    if( r == 1 && r1 == 1) {
        fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "a+");
        if(!(fichAffectationEnseignant)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier d'affectation !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichAffectationEnseignant){
            while( !(feof(fichAffectationEnseignant))) {
                fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);

                if((strcasecmp(affEns.id_cours, id_cours) == 0)) {
                    affichage(30, 13);
                    printf("Ce cours %c d%cj%c %ct%c assign%c %c un enseignant!!", 133, 130, 133, 130, 130, 130, 133);
                    r2 = 1;
                    affichage(30, 14);
                    system("pause");
                }
            }
            fclose(fichAffectationEnseignant);
        }

        if(r2 != 1) {
            //création de l'Id affectation enseignant
            strcpy(x2, strcat(strncpy(x, "aff", 3), "_"));
            strcat(x2, (itoa(aleatoire(), x3, 5)));
            strcpy(idaff, x2);
            strcpy(affEns.id, idaff);

            strcpy(affEns.id_cours, id_cours);
            strcpy(affEns.id_ens, idEns);


            fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "a+");

            if(!(fichAffectationEnseignant)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations enseignant !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichAffectationEnseignant){
                fprintf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                affichage(30, 13);
                printf("Affectation faite avec succ%cs", 138);
                affichage(30, 14);
                system("pause");
                fclose(fichAffectationEnseignant);
            }

            system("cls");
            affichage(20, 8);
            printf("voulez-vous faire une autre assignation ? (Taper 1 pour oui ou une autre touche pour non)");
            affichage(40, 9);
            printf("((         ))");
            affichage(43, 9);
            gets(n1);

            if(n1[0] == '1' && strlen(n1) == 1) {
                assignerCoursEnseignant();
            }
            else{
                gestionEnseignants();
            }
        }
    }
}

////////////////////////////////////////////////////
void afficherListeCoursEnseignant()
{
    char idEns[12];
    int r = 0, k = 8, ind = 1;

    do {
        system("cls");
        affichage(43, 6);
        printf("=========== Section afficher liste cours enseignant ==========");
        affichage(43, 8);
        printf("Entrer l'Id de l'enseignant :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEns);
    } while(testChampVide(idEns) > 0);

    fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
    if(!(fichAffectationEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier Affectations cours enseignant !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichAffectationEnseignant) {
        while(!(feof(fichAffectationEnseignant))) {
            fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
            if(strcasecmp(affEns.id_ens, idEns) == 0) {
                r = 1;
                break;
            }
            if(feof(fichAffectationEnseignant)) {
                system("cls");
                affichage(40, 16);
                printf("Cet Id ne se trouve pas dans le fichier Affectations cours Enseignant !!");
                affichage(40, 17);
                system("pause");
            }
        }
        fclose(fichAffectationEnseignant);
    }


    if( r == 1) {
        fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
        if(!(fichAffectationEnseignant)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier Affectations cours Enseignant !!");
            affichage(40, 17);
            system("pause");
        }

        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        system("cls");
        if(fichCours && fichAffectationEnseignant) {
            while(!(feof(fichAffectationEnseignant))) {
                fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                if(strcasecmp(affEns.id_ens, idEns) == 0) {
                    while( !(feof(fichCours)) ) {
                        fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                        if(strcasecmp(affEns.id_cours, cours.id_cours) == 0) {
                            affichage(30, 6);
                            printf("La liste des cours de %s est/sont :", affEns.id_ens);
                            affichage(30, k);
                            printf("%d. %s\n", ind, cours.nom);
                            k++;
                            ind++;
                        }
                    }
                    fseek(fichCours, 0, SEEK_SET);
                }
            }
            affichage(30, k+1);
            system("pause");
            fclose(fichAffectationEnseignant);
            fclose(fichCours);
        }
    }
}

////////////////////////////////////////////////////
void revoquerEnseignants()
{
    char id_ens[15], c[5];
    int r = 0, r1 = 0;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section r%cvoquer enseignant ==========", 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'enseignant que vous voulez r%cvoquer:", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(id_ens);
    } while(testChampVide(id_ens) > 0);

    fichEnseignant = fopen(fichierEnseignants, "r");
    //Verification de l'ouverture du fichier enseignant
    if(!(fichEnseignant)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier enseignants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEnseignant){
        while(!(feof(fichEnseignant))) {
            fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);

            if(strcasecmp(id_ens, ens.id_ens) == 0) {
                strcpy(ens1.id_ens, id_ens);
                strcpy(ens1.prenom, ens.prenom);
                strcpy(ens1.nom, ens.nom);
                strcpy(ens1.tel, ens.tel);
                ens1.salaire = ens.salaire;

                system("cls");
                afficherEnteteEnseignant();
                affichage(1, 4);
                printf("%s", ens.id_ens);
                affichage(15, 4);
                printf("%s", ens.nom);
                affichage(45, 4);
                printf("%s", ens.prenom);
                affichage(65, 4);
                printf("%.2f", ens.salaire);
                affichage(85, 4);
                printf("%s\n", ens.tel);
                affichage(45, 6);
                system("pause");

                do {
                    system("cls");
                    affichage(30, 7);
                    printf("Veuillez confirmer que vous voulez r%cvoquer : %s %s (1. Oui  2. annul%c)", 130, ens.prenom, ens.nom, 130);
                    affichage(45, 8);
                    printf("((         ))");
                    affichage(47, 8);
                    gets(c);
                    if((c[0] != '1' && c[0] != '2') || strlen(c) != 1) {
                        affichage(45, 9);
                        printf("Mauvais choix (1. oui  2. annul%c)", 130);
                        affichage(45, 10);
                        system("pause");

                    }
                }while(testChampVide(c) > 0 || (c[0] != '1' && c[0] != '2' && strlen(c) != 1));

                if( c[0] == '1') {//confirmation de la révocation
                    r = 1;
                    break;
                } else {
                    system("cls");
                    affichage(40, 10);
                    printf("Le processus de r%cvocation est annul%c", 130, 130);
                    affichage(40, 11);
                    system("pause");
                    break;
                }
            }
            if(feof(fichEnseignant)) {
                affichage(40, 10);
                printf("Ce code n'est pas dans la liste des enseignant.");
                system("pause");
            }
        }
        fclose(fichEnseignant);
    }

    if(r == 1){ //Cela implique c[0] = 1, i-e l'User à confirmer la révocation
        fichEnseignantBcp = fopen(fichierEnseignantsBcp, "w");
        if(!(fichEnseignantBcp)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }

        fichEnseignant = fopen(fichierEnseignants, "r");
        if(!(fichEnseignant)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier enseignants !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichEnseignant && fichEnseignantBcp){
            while( !(feof(fichEnseignant))) {
                fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);

                if(strcasecmp(ens.id_ens, id_ens) != 0) {
                    fprintf(fichEnseignantBcp,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, ens.salaire, ens.tel);
                }
            }
            fclose(fichEnseignant);
            fclose(fichEnseignantBcp);
        }

        fichEnseignant = fopen(fichierEnseignants, "w");
        if(!(fichEnseignant)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier enseignants !!");
            affichage(40, 17);
            system("pause");
        }

        fichEnseignantBcp = fopen(fichierEnseignantsBcp, "r");
        if(!(fichEnseignantBcp)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichEnseignantBcp && fichEnseignant){
            while( !(feof(fichEnseignantBcp))) {
                fscanf(fichEnseignantBcp,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);
                fprintf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, ens.salaire, ens.tel);
            }
            fclose(fichEnseignant);
            fclose(fichEnseignantBcp);
        }

        fichEnseignantRevoquer = fopen(fichierEnseignantRevoquer, "a+");
        //un fichier comme archive en mode a+(ajouter)
        if(!(fichEnseignantRevoquer)) {
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichCoursEnseignantRevoquer){//on mettre les enseignants révoqués dé-dans
            fprintf(fichEnseignantRevoquer,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens1.id_ens, ens1.nom, ens1.prenom, ens1.salaire, ens1.tel);
            fclose(fichEnseignantRevoquer);
        }

        fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
        //on ne test pas l'ouverture du fichier affectation enseignant,
        //il se peut qu'il n'est pas encore été créé, nous voulons seulement vérifié
        if(fichAffectationEnseignant){
            while(!(feof(fichAffectationEnseignant))) {
                fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                if(strcasecmp(affEns.id_ens, id_ens) == 0) {
                    r1 = 1;//Cela di que  l'enseignant a au moins un cours à lui.
                    break;
                }
            }
            fclose(fichAffectationEnseignant);
        }

        if(r1 == 1){ //maintenant nous pouvons être sûr que le fichier affectation enseignant existe déjà

            fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
            if(!(fichAffectationEnseignant)){ //on test son ouverture
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours enseignant !!");
                affichage(40, 17);
                system("pause");
            }

            fichCoursEnseignantRevoquer = fopen(fichierCoursEnseignantRevoquer, "a+");
            //un fichier comme archive en mode a+
            if(!(fichCoursEnseignantRevoquer)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier cours enseignant r%cvoquer!!", 130);
                affichage(40, 17);
                system("pause");
            }

            if(fichCoursEnseignantRevoquer && fichAffectationEnseignant){
                while(!(feof(fichAffectationEnseignant))) {
                    fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                    if(strcasecmp(affEns.id_ens, id_ens) == 0) {
                        fprintf(fichCoursEnseignantRevoquer, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                    }
                }
                fclose(fichAffectationEnseignant);
                fclose(fichCoursEnseignantRevoquer);
            }

            fichAffectationEnseignantBcp = fopen(fichierAffectationsEnseignantBcp, "w");
            if(!(fichAffectationEnseignantBcp)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours enseignant Backup!!");
                affichage(40, 17);
                system("pause");
            }

            fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
            if(!(fichAffectationEnseignant)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours enseignant !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichAffectationEnseignant && fichAffectationEnseignantBcp){
                while(!(feof(fichAffectationEnseignant))) {
                    fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                    if(strcasecmp(affEns.id_ens, id_ens) != 0) {
                        fprintf(fichAffectationEnseignantBcp, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                    }
                }
                fclose(fichAffectationEnseignantBcp);
                fclose(fichAffectationEnseignant);
            }

            fichAffectationEnseignantBcp = fopen(fichierAffectationsEnseignantBcp, "r");
            if(!(fichAffectationEnseignantBcp)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours enseignant Backup!!");
                affichage(40, 17);
                system("pause");
            }

            fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "w");
            if(!(fichAffectationEnseignant)) {
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier Affectations cours enseignant !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichAffectationEnseignantBcp && fichAffectationEnseignant){
                while(!(feof(fichAffectationEnseignantBcp))) {
                    fscanf(fichAffectationEnseignantBcp, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                    fprintf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);
                }
                fclose(fichAffectationEnseignantBcp);
                fclose(fichAffectationEnseignant);
            }
        }

        system("cls");
        affichage(30, 10);
        printf("R%cvocaquion faite avec succ%cs", 130, 138);
        affichage(30, 11);
        system("pause");
    }

    else{ //cela dit que r != 1 et que c[0] = 2, la révocation est annulée
        affichage(30, 11);
        printf("Vous venez d'annuler votre processus de r%cvocation !!", 130);
        affichage(30, 12);
        system("cls");
    }

}

////////////////////////////////////////////////////
void augmenterSalaireEnseignant()
{
/////////////////////////////
    fichEnseignantBcp = fopen(fichierEnseignantsBcp, "w");
    if(!(fichEnseignantBcp)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier !!");
        affichage(40, 17);
        system("pause");
    }

    fichEnseignant = fopen(fichierEnseignants, "r");
    if(!(fichEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier enseignants !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEnseignant && fichEnseignantBcp){
        while( !(feof(fichEnseignant))) {
            fscanf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens.salaire, ens.tel);
            ens1.salaire = ens.salaire + (ens.salaire*0.10);
            fprintf(fichEnseignantBcp,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, ens1.salaire, ens.tel);
        }
        fclose(fichEnseignantBcp);
        fclose(fichEnseignant);
    }

    fichEnseignant = fopen(fichierEnseignants, "w");
    if(!(fichEnseignant)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier enseignants !!");
        affichage(40, 17);
        system("pause");
    }

    fichEnseignantBcp = fopen(fichierEnseignantsBcp, "r");
    if(!(fichEnseignantBcp)) {
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichEnseignant && fichEnseignantBcp){
        while( !(feof(fichEnseignantBcp))) {
            fscanf(fichEnseignantBcp,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, &ens1.salaire, ens.tel);
            fprintf(fichEnseignant,"%s\t\t\t%s\t\t\t%s\t\t\t%lf\t\t\t%s\n", ens.id_ens, ens.nom, ens.prenom, ens1.salaire, ens.tel);
        }
        fclose(fichEnseignant);
        fclose(fichEnseignantBcp);
    }
/////////////////////////////////////////////
    system("cls");
    affichage(30, 10);
    printf("Augmentation de salaire r%cussi !!", 130);
    affichage(30, 11);
    system("pause");
}

////////////////////////////////////////////////////

#endif // GESTIONSENSEIGNANTS_H_INCLUDED
