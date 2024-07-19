#ifndef GESTIONSCOURS_H_INCLUDED
#define GESTIONSCOURS_H_INCLUDED

////////////////////////////////////////////////////
int menuGestionCours()
{
    int choix = -1;
    system("cls");
    affichageEntete();
    affichage(43, 6);
    printf("========= Menu Gestion Cours =========");
    affichage(43, 8);
    printf("1. Enregistrer les cours");
    affichage(43, 9);
    printf("2. Lister les cours");
    affichage(43, 10);
    printf("3. Afficher les informations d'un cours donn%c", 130);
    affichage(43, 11);
    printf("4. Afficher les %ctudiants d'un cours donn%c", 130, 130);
    affichage(43, 12);
    printf("5. Modifier le coefficient d'un cours");
    affichage(43, 13);
    printf("0. Retour au Menu Principal");
    affichage(43, 14);
    printf("------------Fa%ctes votre choix", 140);

    int h = 43, l = 15;
    choix = testChoix(h, l);

    return choix;
}

////////////////////////////////////////////////////
void gestionCours()
{
    int choix;
    do{
        system("cls");
        choix = menuGestionCours();

        switch(choix){
            case 0: {
                principal();
                break;
            }
            case 1: {
                enregistrerCours();
                break;
            }
            case 2: {
                listerCours();
                break;
            }
            case 3: {
                afficherInfoCours();
                break;
            }
            case 4: {
                afficherEtudiantCours();
                break;
            }
            case 5: {
                modifierCoefficientCours();
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
    }while(choix >= 0 || choix <= 5);
}

////////////////////////////////////////////////////
void enregistrerCours()
{
    char id_cours[12], nom[80], coeffi[12], n[5], n1[5];
    char x[5] = "", x2[10] = "", x3[5] = "";
    int coeff, r = 0;

    system("cls");
    affichageEntete();

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer cours ==========");
        affichage(43, 8);
        printf("Entrer le nom du cours:");
        affichage(43, 9);
        printf("((                                   ))");
        affichage(46, 9);
        gets(nom);
    }while(lenChaine(nom) > 0 || testChampVide(nom) > 0 || testAlpha(nom) > 0);

    // j'ouvre le fichier
    fichCours = fopen(fichierCours, "r");
    //Nous devons verifier si le cours n'a pas déjà été enregistré
    if(fichCours){
        while(!(feof(fichCours))){
            fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);

            if(strcasecmp(cours.nom, nom) == 0){
                r = 1;
                break;
            }
        }
        fclose(fichCours);
    }

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer cours ==========");
        affichage(43, 8);
        printf("Entrer le coefficient du cours:");
        affichage(43, 9);
        printf("((                           ))");
        affichage(46, 9);
        gets(coeffi);
        coeff = atoi(coeffi);

        if( atoi(coeffi) == 0 || coeff < 2 || coeff > 5){
            printf("Le coefficient doit %ctre un entier et compris entre 2 et 5\n", 136);
            system("pause");
        }
    }while(testDigit(coeffi) > 0 || atoi(coeffi) == 0 || coeff > 5 || coeff < 2);
    cours.cofficient = coeff;


    // création de l'Id_cours
    strcpy(x2, strcat(strncpy(x, nom, 3), "_"));
    strcat(x2, (itoa(aleatoire2(), x3, 5)));
    strcpy(id_cours, x2);
    strcpy(cours.id_cours, id_cours);

    do{
        system("cls");
        afficherEnteteCours();
        affichage(1, 4);
        printf("%s", cours.id_cours);
        affichage(40, 4);
        printf("%s", nom);
        affichage(100, 4);
        printf("%d", cours.cofficient);
        affichage(30, 14);
        printf("Veuillez confirmer l'enregistrement du cours (1.oui   2.non)");
        affichage(40, 15);
        printf("((             ))");
        affichage(43, 15);
        gets(n);

        if(strlen(n) == 1 && n[0] == '1' && r != 1){

            fichCours = fopen(fichierCours, "a+");
            //Verification de l'ouverture du fichier cours
            if(!(fichCours)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier cours !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichCours){
                strcpy(cours.nom, nom);
                system("cls");
                fprintf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, cours.cofficient);
                fclose(fichCours);
                affichage(40, 17);
                printf("Enregistrement fait avec succ%cs !!\n", 137);
                system("pause");
                break;
            }
        }
        else if(r == 1){
            system("cls");
            affichage(40, 10);
            printf("Enregistrement annul%c car ce cours %c d%cj%c %ct%c enregistr%c", 130, 133, 130, 133, 130, 130, 130);
            affichage(40, 11);
            system("pause");
            break;
        }

        else if(strlen(n) == 1 && n[0] == '2'){
            system("cls");
            affichage(40, 10);
            printf("Vous venez d'annuler l'enregistrement");
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
    printf("voulez-vous enregistrer un autre cours ? (Taper 1 pour oui ou une autre touche pour non)");
    affichage(40, 9);
    printf("((         ))");
    affichage(43, 9);
    gets(n1);
    if(n1[0] == '1' && strlen(n1) == 1){
        enregistrerCours();
    }
    else{
        gestionCours();
    }
}

////////////////////////////////////////////////////
void listerCours()
{
    int k = 4;

    afficherEnteteCours();

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
            fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
            affichage(1, k);
            printf("%s", cours.id_cours);
            affichage(40, k);
            printf("%s", cours.nom);
            affichage(100, k);
            printf("%d", cours.cofficient);
            k++;
        }
        fclose(fichCours);
        affichage(30, k+1);
        system("pause");
    }
}

////////////////////////////////////////////////////
void afficherInfoCours()
{
    char idcours[12];

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister Cours ==========");
        affichage(43, 8);
        printf("Entrer l'Id du cours :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idcours);
    }while(testChampVide(idcours) > 0);

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
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);

            if( strcasecmp(idcours, cours.id_cours) == 0){
                system("cls");
                afficherEnteteCours();
                affichage(1, 4);
                printf("%s", cours.id_cours);
                affichage(40, 4);
                printf("%s", cours.nom);
                affichage(100, 4);
                printf("%d", cours.cofficient);
                break;
            }
            if(feof(fichCours)){
                affichage(40, 13);
                printf("Ce code n'est pas dans la liste.");
            }
        }
        fclose(fichCours);
        affichage(45, 13);
        system("pause");
    }
}

////////////////////////////////////////////////////
void afficherEtudiantCours()
{
    char id_cours[15];
    int ind = 1, k = 8;
    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section Afficher les %ctudiant d'un cours ==========", 130);
        affichage(43, 8);
        printf("Entrer l'Id du cours");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(id_cours);
    }while(testChampVide(id_cours) > 0);

    fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
    if(!(fichAffectationEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier Affectations cours %ctudiants !!", 130);
        affichage(40, 17);
        system("pause");
    }

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichAffectationEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %ctudiants !!", 130);
        affichage(40, 17);
        system("pause");
    }

    system("cls");
    if(fichAffectationEtudiants && fichEtudiants){
        while(!(feof(fichAffectationEtudiants))){
            fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
            if(strcasecmp(affEtud.id_cour, id_cours) == 0){
                while( !(feof(fichEtudiants)) ){
                    fscanf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);
                    if(strcasecmp(affEtud.id_etud, etud.idEtud) == 0){
                        affichage(30, 6);
                        printf("La liste des %ctudiants du cours %s :", 130, id_cours);
                        affichage(30, k);
                        printf("%d. %s %s\n", ind, etud.prenom, etud.nom);
                        k++;
                        ind++;
                    }
                }
                fseek(fichEtudiants, 0, SEEK_SET);
            }
        }
        fclose(fichAffectationEtudiants);
    }

    if(k == 8){
        affichage(30, 10);
        printf("Ce cours n'a pas encore d'%ctudiant qui lui est affect%c", 130, 130);
    }
   affichage(30, k+3);
   system("pause");
}

////////////////////////////////////////////////////
void modifierCoefficientCours()
{
    char id_cours[15], coeffi[12];
    int r = 0, coeff;
    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section modifier coefficient d'un cours ==========");
        affichage(43, 8);
        printf("Entrer l'Id du cours que vous voulez modifier son coefficient :");
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
        while( !(feof(fichCours))){
            fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
            if( strcasecmp(cours.id_cours, id_cours) == 0){
                strcpy(cours1.id_cours, id_cours);
                strcpy(cours1.nom, cours.nom);
                cours1.cofficient = cours.cofficient;

                system("cls");
                afficherEnteteCours();
                affichage(1, 4);
                printf("%s", cours.id_cours);
                affichage(40, 4);
                printf("%s", cours.nom);
                affichage(100, 4);
                printf("%d", cours.cofficient);
                affichage(30, 5);
                system("pause");
                r = 1;
                break;
            }
            if( feof(fichCours) ){
                system("cls");
                affichage(30, 10);
                printf("L'Id est introuvable.");
                affichage(30, 11);
                system("pause");
            }
        }
        fclose(fichCours);
    }

    if( r == 1){
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section modifier le cofficient d'un cours ==========");
            affichage(43, 8);
            printf("Entrer le nouveau coefficient du cours:");
            affichage(43, 9);
            printf("((                           ))");
            affichage(46, 9);
            gets(coeffi);
            coeff = atoi(coeffi);
            if( coeff > 5 || coeff < 2){
                printf("Le coefficient doit %ctre un entier et compris entre 2 et 5 au sens large", 136);
                system("pause");
            }
        }while(testDigit(coeffi) > 0 || coeff > 5 || coeff < 2);
        cours1.cofficient = coeff;

        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        fichCoursBcp = fopen(fichierCoursBcp, "w");
        if(!(fichCoursBcp)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours backup!!");
            affichage(40, 17);
            system("pause");
        }

        if(fichCours && fichCoursBcp){
            while(!(feof(fichCours))){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                if(strcasecmp(cours.id_cours, id_cours) != 0){
                    fprintf(fichCoursBcp,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, cours.cofficient);
                }
            }
            fclose(fichCours);
            fclose(fichCoursBcp);
        }

        fichCours = fopen(fichierCours, "w");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        fichCoursBcp = fopen(fichierCoursBcp, "r");
        if(!(fichCoursBcp)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours backup!!");
            affichage(40, 17);
            system("pause");
        }

        if(fichCours && fichCoursBcp){
            while(!(feof(fichCoursBcp))){
                fscanf(fichCoursBcp,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                fprintf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, cours.cofficient);
            }
            fclose(fichCours);
            fclose(fichCoursBcp);
        }

        fichCours = fopen(fichierCours, "a+");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichCours){
            fprintf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours1.id_cours, cours1.nom, cours1.cofficient);
            fclose(fichCours);
        }

        system("cls");
        affichage(30, 10);
        printf("C'est fait !!");
        affichage(30,11);
        system("pause");
    }
}

////////////////////////////////////////////////////



#endif // GESTIONSCOURS_H_INCLUDED
