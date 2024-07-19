#ifndef GESTIONEVALUATIONS_H_INCLUDED
#define GESTIONEVALUATIONS_H_INCLUDED

////////////////////////////////////////////////////
int menuGestionEvaluations()
{
    int choix = -1;
    int h = 43, l = 14;
    system("cls");
    affichageEntete();
    affichage(43, 6);
    printf("========= Menu Gestion des %cvaluations =========", 144);
    affichage(43, 8);
    printf("1. Programmer une %cvaluation pour un cours donn%c", 130, 130);
    affichage(43, 9);
    printf("2. Lister les cours %c %cvaluer", 133, 130);
    affichage(43, 10);
    printf("3. Lister les d%ctails d'%cvaluation d'un cours donn%c", 130, 130, 130);
    affichage(43, 11);
    printf("4. Annuler une %cvaluation", 130);
    affichage(43, 12);
    printf("0. Retour au menu principal");
    affichage(43, 13);
    printf("------------Fa%ctes votre choix", 140);

    choix = testChoix(h, l);
    return choix;
}

////////////////////////////////////////////////////
void gestionEvaluation()
{
    int choix;
    do{
        system("cls");
        choix = menuGestionEvaluations();

        switch(choix){
            case 0: {
                principal();
                break;
            }
            case 1: {
                programmerEvaluation();
                break;
            }
            case 2: {
                listerCours_a_Evaluer();
                break;
            }
            case 3: {
                listerDetailEvaluation();
                break;
            }
            case 4: {
               annulerEvaluation();
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
    }while(choix >= 0 || choix <= 4);
 }

////////////////////////////////////////////////////
void programmerEvaluation()
{
    char type1[10], type[10], idCours[15], idEval[15], x[5] = "", x2[10] = "", x3[5] = "", n1[5];
    int r = 0, r1 = 0, rc = 0, rEns = 0;

    system("cls");
    affichageEntete();

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section programmer %cvaluation ==========", 130);
        affichage(43, 8);
        printf("Entrer le type de l'%cvaluation (Intra ou Final): ", 130);
        affichage(43, 10);
        printf("((                               ))");
        affichage(46, 10);
        gets(type1);
        strcpy(type, type1);

        if(strcasecmp(type, "Intra") != 0 && strcasecmp(type, "Final") != 0){
            system("cls");
            affichage(30, 6);
            printf("Vous devez taper ""Intra"" ou ""Final"")");
            affichage(30, 7);
            system("pause");
        }
    }while(strcasecmp(type, "Intra") != 0 && strcasecmp(type, "Final") != 0);

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section programmer %cvaluation ==========", 130);
        affichage(43, 8);
        printf("Entrer l'identifiant du cours %c %cvaluer : ", 133, 130);
        affichage(43, 9);
        printf("((                                   ))");
        affichage(46, 9);
        gets(idCours);

        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichCours){
            while(!(feof(fichCours))){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                if( strcasecmp(idCours, cours.id_cours) == 0){
                    rc = 1;// nous pouvons tout simplement copier dans la structure evaluation l'Id cours
                    break;//nous n'allons pas le faire pour eviter les problemes de verification dans le fichier
                }
                if(feof(fichCours)){
                    system("cls");
                    affichage(40, 16);
                    printf("Ce cours n'existe pas!!");
                    affichage(40, 17);
                    system("pause");
                }
            }
            fclose(fichCours);
        }

        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier affectation cours etudiant !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichAffectationEtudiants){
            while(!(feof(fichAffectationEtudiants))){
                fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);

                if( strcasecmp(idCours, affEtud.id_cour) == 0){
                    r = 1;
                    break;
                }
                if(feof(fichAffectationEtudiants)){
                    system("cls");
                    affichage(40, 13);
                    printf("Id introuvable dans la liste affectations, veuillez r%cessayez.", 130);
                    affichage(45, 14);
                    system("pause");
                }
            }
            fclose(fichAffectationEtudiants);
        }

        fichAffectationEnseignant = fopen(fichierAffectationsEnseignant, "r");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier affectation cours enseignant !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichAffectationEnseignant){
            while(!(feof(fichAffectationEnseignant))){
                fscanf(fichAffectationEnseignant, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEns.id, affEns.id_ens, affEns.id_cours);

                if( strcasecmp(idCours, affEns.id_cours) == 0){
                    rEns = 1;
                    break;
                }
                if(feof(fichAffectationEnseignant)){
                    system("cls");
                    affichage(40, 13);
                    printf("Id introuvable dans la liste affectations enseignants, veuillez r%cessayez.", 130);
                    affichage(45, 14);
                    system("pause");
                }
            }
            fclose(fichAffectationEnseignant);
        }

    }while(testChampVide(idCours) > 0 || r != 1 || rEns != 1);

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(fichEvaluation){
        while(!(feof(fichEvaluation))){
            fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
            if(strcasecmp(eval.id_cours, idCours) == 0 && strcasecmp(eval.type, type1) == 0){
                r1 = 1;
            }
        }
        fclose(fichEvaluation);
    }


    if(r1 != 1 && rc == 1 && rEns == 1){//de toute façon r1 = 1 ==> rc = 1
        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichCours){
            while(!(feof(fichCours))){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                if( strcasecmp(idCours, cours.id_cours) == 0){
                    strcpy(eval.id_cours, idCours);//nous pouvons, maintenant, recuperer les donnees necessaires
                    strcpy(eval.nom_cours, cours.nom);
                    break;
                }
            }
        }

        //Création de l'Id Evaluation
        strcpy(x2, strcat(strncpy(x, "eval", 4), "_"));
        strcat(x2, (itoa(aleatoire2(), x3, 5)));
        strcpy(idEval, x2);
        strcpy(eval.id_eval, idEval);

        fichEvaluation = fopen(fichierEvaluation, "a+");
        if(!(fichEvaluation)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
            affichage(40, 17);
            system("pause");
        }
        if(fichEvaluation){

            if(strcmp(type, "Intra") == 0){
                strcpy(eval1.type, "Intra");
                eval1.ponderation = 0.40;
            }

            else{
                strcpy(eval1.type, "Final");
                eval1.ponderation = 0.60;
            }

            fprintf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%.2f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval1.type, eval1.ponderation);
            fclose(fichEvaluation);
        }

        system("cls");
        affichage(30, 10);
        printf("Programmation r%cussie", 130);
        affichage(30, 11);
        system("pause");
    }
    else{
        system("cls");
        affichage(30, 10);
        printf("Ce cours %c %ct%c programm%c pour le m%cme type", 133, 130, 130, 130, 136);
        affichage(30, 11);
        system("pause");
    }

    system("cls");
    affichage(20, 8);
    printf("voulez-vous faire une autre programmation ? (Taper 1 pour oui ou une autre touche pour non)");
    affichage(40, 9);
    printf("((         ))");
    affichage(43, 9);
    gets(n1);
    if(n1[0] == '1' && strlen(n1) == 1){
        programmerEvaluation();
    }
    else{
        gestionEvaluation();
    }
}

////////////////////////////////////////////////////
void listerCours_a_Evaluer()
{
    afficherEnteteEvaluation();

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    int k = 4;
    if(fichEvaluation){
        while( !(feof(fichEvaluation)) ){
            fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
            affichage(1, k);
            printf("%s", eval.id_eval);
            affichage(15, k);
            printf("%s", eval.id_cours);
            affichage(45, k);
            printf("%s", eval.nom_cours);
            affichage(65, k);
            printf("%s", eval.type);
            affichage(85, k);
            printf("%.2f", eval.ponderation);
            k++;
        }
    }
    fclose(fichEvaluation);
    affichage(30, k+1);
    system("pause");
}

////////////////////////////////////////////////////
void listerDetailEvaluation()
{
    char idEvalCours[15];
    int i = 4;
    fichEvaluation = fopen(fichierEvaluation, "r");

    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister d%ctail %cvaluation ==========", 130, 144);
        affichage(43, 8);
        printf("Entrer l'Id du cours:");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEvalCours);
    }while(testChampVide(idEvalCours) > 0);

    afficherEnteteEvaluation();
    if(fichEvaluation){
        while( !(feof(fichEvaluation)) ){
            fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
            if(strcasecmp(eval.id_cours, idEvalCours) == 0){
                affichage(1, i);
                printf("%s", eval.id_eval);
                affichage(15, i);
                printf("%s", eval.id_cours);
                affichage(45, i);
                printf("%s", eval.nom_cours);
                affichage(65, i);
                printf("%s", eval.type);
                affichage(85, i);
                printf("%.2f", eval.ponderation);
                i++;
            }
        }
    }
    fclose(fichEvaluation);
    affichage(45, 8);
    system("pause");

    if(i == 4){
        system("cls");
        affichage(40, 7);
        printf("Ce code n'est pas dans la liste des cours %c %cvaluer.", 133, 130);
        affichage(40, 8);
        system("pause");
    }
}

////////////////////////////////////////////////////
void annulerEvaluation()
{
    char idEval[15], rep[5];
    int r = 0;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section Annuler %cvaluation ==========", 144);
        affichage(43, 8);
        printf("Entrer l'Id de l'%cvaluation :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEval);
    }while(testChampVide(idEval) > 0);

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    if(fichEvaluation){
        while( !(feof(fichEvaluation)) ){
            fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
            if( strcasecmp(idEval, eval.id_eval) == 0){
                strcpy(eval1.id_eval, eval.id_eval);//on copie les infos pour l'archive
                strcpy(eval1.id_cours, eval.id_cours);
                strcpy(eval1.nom_cours, eval.nom_cours);
                strcpy(eval1.type, eval.type);
                eval1.ponderation = eval.ponderation;

                afficherEnteteEvaluation();
                affichage(1, 4);
                printf("%s", eval.id_eval);
                affichage(15, 4);
                printf("%s", eval.id_cours);
                affichage(45, 4);
                printf("%s", eval.nom_cours);
                affichage(65, 4);
                printf("%s", eval.type);
                affichage(85, 4);
                printf("%.2f", eval.ponderation);
                r = 1;
                break;
            }
            if(feof(fichEvaluation)){
                affichage(40, 13);
                printf("Ce code n'est pas dans la liste des cours %c %cvaluer.", 133, 130);
            }
        }
        fclose(fichEvaluation);
        affichage(45, 14);
        system("pause");
    }

    if(r == 1){
        system("cls");
        affichage(30, 10);
        printf("Taper 1 pour confirmer l'annulation de l'%cvaluation un autre touche pour dire non", 130);
        affichage(30, 11);
        gets(rep);

        if(rep[0] == '1' && strlen(rep) == 1){
            fichEvaluation = fopen(fichierEvaluation, "r");
            if(!(fichEvaluation)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
                affichage(40, 17);
                system("pause");
            }

            fichEvaluationBcp = fopen(fichierEvaluationBcp, "w");
            if(!(fichEvaluationBcp)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier %cvaluation backup!!", 130);
                affichage(40, 17);
                system("pause");
            }

            if(fichEvaluation && fichEvaluationBcp){
                while( !(feof(fichEvaluation)) ){
                    fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                    if(strcasecmp(idEval, eval.id_eval) != 0){
                        fprintf(fichEvaluationBcp, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%.2f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, eval.ponderation);
                    }
                }
                fclose(fichEvaluation);
                fclose(fichEvaluationBcp);
            }

            fichEvaluation = fopen(fichierEvaluation, "w");
            if(!(fichEvaluation)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
                affichage(40, 17);
                system("pause");
            }

            fichEvaluationBcp = fopen(fichierEvaluationBcp, "r");
            if(!(fichEvaluationBcp)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier %cvaluation backup!!", 130);
                affichage(40, 17);
                system("pause");
            }

            if(fichEvaluationBcp && fichEvaluation){
                while( !(feof(fichEvaluationBcp)) ){
                    fscanf(fichEvaluationBcp, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                    fprintf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%.2f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, eval.ponderation);
                }
                fclose(fichEvaluation);
                fclose(fichEvaluationBcp);
                system("cls");
                affichage(30, 10);
                printf("Annulation faite avec succ%cs", 138);
            }

            fichNoteEvalAnnuler = fopen(fichierNoteEvalAnnuler, "a+");
            if(!(fichNoteEvalAnnuler)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier note %cvaluation annuler!!", 130);
                affichage(40, 17);
                system("pause");
            }

            fichNote = fopen(fichierNote, "r");//on n'a pas besoin de tester son ouverture

            if(fichNote && fichNoteEvalAnnuler){ //si le fichier existe c'est à ce moment qu'on peut le scanner.
                while( !(feof(fichNote)) ){
                    fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
                    if(strcasecmp(point.id_eval, idEval)== 0){
                        fprintf(fichNoteEvalAnnuler, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", point.idNote, point.id_eval, point.id_cours, point.idEtud, point.note);
                    }
                }
                fclose(fichNoteEvalAnnuler);
                fclose(fichNote);
            }

            fichNoteBcp = fopen(fichierNoteBcp, "w");
            if(!(fichNote)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier note Backup!!");
                affichage(40, 17);
                system("pause");
            }

            fichNote = fopen(fichierNote, "r");
            if(!(fichNote)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier note !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichNote && fichNoteBcp){
                while(!(feof(fichNote))){
                    fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
                    if(strcasecmp(point.id_eval, idEval) != 0){
                        fprintf(fichNoteBcp, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%.2f\n", point.idNote, point.id_eval, point.id_cours, point.idEtud, point.note);
                    }
                }
                fclose(fichNote);
                fclose(fichNoteBcp);
            }

            fichNoteBcp = fopen(fichierNoteBcp, "r");
            if(!(fichNote)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier note Backup!!");
                affichage(40, 17);
                system("pause");
            }

            fichNote = fopen(fichierNote, "w");
            if(!(fichNote)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier note !!");
                affichage(40, 17);
                system("pause");
            }

            if(fichNote && fichNoteBcp){
                while(!feof(fichNoteBcp)){
                    fscanf(fichNoteBcp, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
                    fprintf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%.2f\n", point.idNote, point.id_eval, point.id_cours, point.idEtud, point.note);
                }
                fclose(fichNoteBcp);
                fclose(fichNote);
            }

            fichEvaluationAnnuler = fopen(fichierEvaluationAnnuler, "a+");
            //un fichier archive
            if(!(fichEvaluationAnnuler)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier %cvaluation annuler!!", 130);
                affichage(40, 17);
                system("pause");
            }
            if(fichEvaluationAnnuler){
                fprintf(fichEvaluationAnnuler, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%.2f\n", eval1.id_eval, eval1.id_cours, eval1.nom_cours, eval1.type, eval.ponderation);
                fclose(fichEvaluationAnnuler);
            }
            affichage(30, 11);
            system("pause");
        }

        else{
            system("cls");
            affichage(30, 10);
            printf("Vous venez d'arr%cter le processus d'annulation", 136);
            affichage(30, 11);
            system("pause");
        }
    }
}

////////////////////////////////////////////////////

#endif // GESTIONEVALUATIONS_H_INCLUDED
