#ifndef CONSULTATIONSNOTES_H_INCLUDED
#define CONSULTATIONSNOTES_H_INCLUDED

/////////////////////////////////////////////////////`
int menuGestionNotes()
{
    int choix = -1;
    system("cls");
    affichageEntete();
    affichage(43, 6);
    printf("========= Menu Consultations des notes =========");
    affichage(43, 8);
    printf("1. Enregistrer une note d'un cours d%cj%c %cvalu%c", 130, 133, 130, 130);
    affichage(43, 9);
    printf("2. Lister toutes les notes");
    affichage(43, 10);
    printf("3. Lister les notes d'un cours donn%c", 130);
    affichage(43, 11);
    printf("4. Lister les notes d'un %ctudiant donn%c", 130, 130);
    affichage(43, 12);
    printf("5. Lister la note d'un %ctudiant pour un cours donn%c", 130, 130);
    affichage(43, 13);
    printf("6. Modifier la note d'un %ctudiant pour un cours donn%c", 130, 130);
    affichage(43, 14);
    printf("7. Calculer automatiquement la moyenne d'un %ctudiant donn%c", 130, 130);
    affichage(43, 15);
    printf("0. Retour au menu Principal");
    affichage(43, 16);
    printf("------------Fa%ctes votre choix", 140);

    int h = 43, l = 17;
    choix = testChoix(h, l);

    return choix;
}

////////////////////////////////////////////////////
void gestionNotes()
 {
    int choix;
    do{
        system("cls");
        choix = menuGestionNotes();

        switch(choix){
            case 0: {
                principal();
                break;
            }
            case 1: {
                enregistrerNotes();
                break;
            }
            case 2: {
                listerNotes();
                break;
            }
            case 3: {
                listerNoteCours();
                break;
            }
            case 4: {
               listerNoteEtudiant();
                break;
            }
            case 5: {
                listerNoteEtudiantCours();
                break;
            }
            case 6: {
                modifierNoteEtudiant();
                break;
            }
            case 7: {
                moyenneEtudiant();
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
    }while(choix >= 0 || choix <= 7);
 }

////////////////////////////////////////////////////
void enregistrerNotes()
{
    char idEval[15], idEtud[15], note1[9], n1[5];
    int r = 0, r1 = 0, r2 = 0, id = 0;
    float note;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section enregistrer Note ==========");
        affichage(43, 8);
        printf("Entrer l'identifiant de l'%cvaluation : ", 130);
        affichage(43, 9);
        printf("((                                   ))");
        affichage(46, 9);
        gets(idEval);

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
                if(strcasecmp(eval.id_eval, idEval) == 0){
                    r = 1;
                    break;
                }
                if(feof(fichEvaluation)){
                    system("cls");
                    affichage(40, 16);
                    printf("Id introuvable !!");
                    affichage(40, 17);
                    system("pause");
                }
            }
        }
        fclose(fichEvaluation);
    }while(testChampVide(idEval) > 0 || r != 1);

    if( r == 1){
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section enregistrer note ==========");
            affichage(43, 8);
            printf("Entrer l'Id de l'%ctudiant :", 130);
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(idEtud);

            fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
            if(!(fichAffectationEtudiants)){
                system("cls");
                affichage(40, 16);
                printf("Impossible d'ouvrir le fichier etudiants !!");
                affichage(40, 17);
                system("pause");
            }
            if(fichAffectationEtudiants){
                while( !(feof(fichAffectationEtudiants)) ){
                    fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);

                    if( strcasecmp(idEtud, affEtud.id_etud) == 0){
                        r1 = 1;
                        break;
                    }
                    if(feof(fichAffectationEtudiants)){
                        system("cls");
                        affichage(40, 13);
                        printf("Ce code n'est pas dans la liste des cours affect%c %c l'%ctudiants.", 130, 133, 130);
                        affichage(40, 14);
                        system("pause");
                    }
                }
            }
            fclose(fichAffectationEtudiants);
        }while(testChampVide(idEtud) > 0 || r1 != 1);
    }

    fichNote = fopen(fichierNote, "r");
    if(fichNote){//si le fichier existe
        while(!(feof(fichNote))){//nous le parcourons
           fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
           if(point.idNote > id){
                id = point.idNote;//Pour récupérer le dernier IdNote enregistré
            }
           if(strcasecmp(point.id_eval, idEval) == 0 && strcasecmp(point.idEtud, idEtud) == 0){
                r2 = 1;//si on trouve un même id étudiant qui soit enregistré pour un même id Evaluation
                system("cls");
                affichage(40, 13);
                printf("On a d%cj%c enregistr%c cette note pour l'%ctudiants %s.", 130, 133, 130, 130, idEtud);
                affichage(40, 14);
                printf("Nous vous conseillons de le modifier en cas d'erreur de saisir!!");
                affichage(44, 16);
                system("pause");
            }
        }
    }
    fclose(fichNote);

    if(r == 1 && r1 == 1 && r2 != 1){//de toute façon cette condition est vraie pour r et r1

        fichEvaluation = fopen(fichierEvaluation, "r");
        if(!(fichEvaluation)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
            affichage(40, 17);
            system("pause");
        }

        fichAffectationEtudiants = fopen(fichierAffectationsEtudiants, "r");
        if(!(fichAffectationEtudiants)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier etudiants !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichAffectationEtudiants){
            while( !(feof(fichAffectationEtudiants)) ){
                fscanf(fichAffectationEtudiants, "%s\t\t\t\t\t%s\t\t\t\t\t%s\n", affEtud.id, affEtud.id_etud, affEtud.id_cour);
                if( strcasecmp(idEtud, affEtud.id_etud) == 0){
                    strcpy(point.idEtud, idEtud);
                    break;
                }
            }
        }
        if(fichEvaluation){
            while( !(feof(fichEvaluation)) ){
                fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                if(strcasecmp(eval.id_eval, idEval) == 0){
                    strcpy(point.id_eval, idEval);
                    strcpy(point.id_cours, eval.id_cours);
                    break;
                }
            }
        }
        fclose(fichEvaluation);
        fclose(fichAffectationEtudiants);

        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section enregistrer note ==========");
            affichage(43, 8);
            printf("Entrer la note de l'%ctudiant :", 130);
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(note1);

            note = atof(note1);
            if(note <= 0.0 || note >100){
                system("cls");
                affichage(30, 12);
                printf("Erreur !! Veuillez entrer une note valide, la note maximale est 100 !!");
                affichage(30, 13);
                system("pause");
            }
        }while(testChampVide(note1) > 0 || note <= 0.0 || note > 100);
        point.note = note;

        fichNote = fopen(fichierNote, "a+");
        if(!(fichNote)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier note !!");
            affichage(40, 17);
            system("pause");
        }
        if(fichNote){
            point.idNote = id + 1;
            fprintf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%.2lf\n", point.idNote, point.id_eval, point.id_cours, point.idEtud, point.note);
            fclose(fichNote);
            system("cls");
            affichage(40, 16);
            printf("Enregistrement termin%c !!", 130);
            affichage(40, 17);
            system("pause");

            system("cls");
            affichage(20, 8);
            printf("voulez-vous enregistrer un autre note ? (Taper 1 pour oui ou une autre touche pour non)");
            affichage(40, 9);
            printf("((         ))");
            affichage(43, 9);
            gets(n1);

            if(n1[0] == '1' && strlen(n1) == 1) {
                enregistrerNotes();
            }
            else{
                gestionNotes();
            }

        }
    }
}

////////////////////////////////////////////////////
void listerNotes()
{
    int k = 4;

    afficherEnteteNote();

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
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
    if(fichNote && fichEvaluation){
        while( !(feof(fichNote)) ){
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            while(!(feof(fichEvaluation))){
                fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                if(strcasecmp(point.id_eval, eval.id_eval) == 0){
                    affichage(1, k);
                    printf("%d", point.idNote);
                    affichage(15, k);
                    printf("%s", point.id_eval);
                    affichage(45, k);
                    printf("%s", point.id_cours);
                    affichage(65, k);
                    printf("%s", point.idEtud);
                    affichage(85, k);
                    printf("%.2f", point.note);
                    affichage(95, k);
                    printf("%s", eval.type);
                    k++;
                    break;
                }
            }
            fseek(fichEvaluation, 0, SEEK_SET);
        }
    }
    fclose(fichNote);
    fclose(fichEvaluation);
    affichage(30, k+1);
    system("pause");
}

////////////////////////////////////////////////////
void listerNoteCours()
{
    char idcours[12];
    int ind = 1, k = 5;

    fichNote = fopen(fichierNote, "r");
    if(!(fichNote)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note !!");
        affichage(40, 17);
        system("pause");
    }

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %ctudiant !!", 130);
        affichage(40, 17);
        system("pause");
    }

    fichEvaluation = fopen(fichierEvaluation, "r");
   if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 144);
        affichage(40, 17);
        system("pause");
    }

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister note d'un cours ==========");
        affichage(43, 8);
        printf("Entrer l'Id du cours :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idcours);
    }while(testChampVide(idcours) > 0);

    system("cls");
    if(fichNote && fichEtudiants && fichEvaluation){
        while(!(feof(fichNote))) {
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            if(strcasecmp(idcours, point.id_cours) == 0) {
                while(!(feof(fichEtudiants))){
                    fscanf(fichEtudiants, "%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);
                    if(strcasecmp(point.idEtud, etud.idEtud) == 0) {
                        while((!feof(fichEvaluation))) {
                            fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                            if(strcasecmp(point.id_cours, eval.id_cours) == 0 && strcasecmp(eval.id_eval, point.id_eval) == 0) {
                                affichage(30, 2);
                                printf("La liste des notes du cours %s :", eval.nom_cours);
                                affichage(1, 4);
                                printf("No");
                                affichage(15, 4);
                                printf("Nom");
                                affichage(35, 4);
                                printf("Pr%cnom", 130);
                                affichage(55, 4);
                                printf("Note");
                                affichage(75, 4);
                                printf("Type Evaluation");

                                affichage(1, k);
                                printf("%d", ind);
                                affichage(15, k);
                                printf("%s", etud.nom);
                                affichage(35, k);
                                printf("%s", etud.prenom);
                                affichage(55, k);
                                printf("%.2f", point.note);
                                affichage(75, k);
                                printf("%s", eval.type);
                                k++;
                                ind++;
                                break;
                            }
                        }
                        fseek(fichEvaluation,0,SEEK_SET);
                    }
                }
                fseek(fichEtudiants,0,SEEK_SET);
            }
        }
    }
    fclose(fichEvaluation);
    fclose(fichEtudiants);
    fclose(fichNote);

    if(k == 5){
        system("cls");
        affichage(40, 16);
        printf("Ce cours n'a pas de note enregistr%ce !!", 130);
        affichage(40, 17);
        system("pause");
    }
    affichage(45, k+2);
    system("pause");
}

////////////////////////////////////////////////////
void listerNoteEtudiant()
{
    char idEtud[15];
    int k = 7;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section Lister note %ctudiant ==========", 130);
        affichage(43, 8);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

    fichNote = fopen(fichierNote, "r");
    if(!(fichNote)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note !!");
        affichage(40, 17);
        system("pause");
    }

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    system("cls");
    if(fichNote && fichEvaluation){
        while(!(feof(fichNote))){
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            if(strcasecmp(idEtud, point.idEtud) == 0){
                while(!(feof(fichEvaluation))){
                    fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                    if(strcasecmp(point.id_eval, eval.id_eval) == 0 ){
                        affichage(30, 3);
                        printf("Les notes de %s", idEtud);
                        affichage(10, 6);
                        printf("Nom Cours");
                        affichage(30, 6);
                        printf("Nbre Point");
                        affichage(50, 6);
                        printf("Type %cvaluation", 144);

                        affichage(10, k);
                        printf("%s", eval.nom_cours);
                        affichage(30, k);
                        printf("%.2f", point.note);
                        affichage(50, k);
                        printf("%s", eval.type);
                        k++;
                    }
                }
                fseek(fichEvaluation, 0, SEEK_SET);
            }
        }
    }

    if(k == 7){
        system("cls");
        affichage(40, k+2);
        printf("Cet Id n'a pas de note enregistr%ce !!", 130);
    }
    affichage(40, k+4);
    system("pause");
}

////////////////////////////////////////////////////
void listerNoteEtudiantCours()
{
    char idEtud[15], idcours[15];
    int k = 7, r = 0, r1 = 0;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section lister note %ctudiant d'un cours ==========", 144);
        affichage(43, 8);
        printf("Entrer l'Id du cours :");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(idcours);
    }while(testChampVide(idcours) > 0);

    fichNote = fopen(fichierNote, "r");
    if(!(fichNote)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note !!");
        affichage(40, 17);
        system("pause");
    }

    if(fichNote){
        while(!(feof(fichNote))){
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            if(strcasecmp(point.id_cours, idcours) == 0){
                r = 1;
            }
        }
        fclose(fichNote);
    }

    if(r == 1){
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section Lister note %ctudiant d'un cours ==========", 144);
            affichage(43, 8);
            printf("Entrer l'Id de l'%ctudiant :", 130);
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(idEtud);
        }while(testChampVide(idEtud) > 0);

        fichNote = fopen(fichierNote, "r");
        if(!(fichNote)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier note !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichNote){
            while(!(feof(fichNote))){
                fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
                if(strcasecmp(point.idEtud, idEtud) == 0){
                    r1 = 1;
                }
            }
            fclose(fichNote);
        }

    }

    if(r == 1 && r1 == 1){//De toute façon r1 = 1 <==> r = 1
        fichNote = fopen(fichierNote, "r");
        if(!(fichNote)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier note !!");
            affichage(40, 17);
            system("pause");
        }

        fichEvaluation = fopen(fichierEvaluation, "r");
        if(!(fichEvaluation)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
            affichage(40, 17);
            system("pause");
        }

        system("cls");
        if(fichEvaluation && fichNote){
            while(!(feof(fichNote))) {
                fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
                if(strcasecmp(point.idEtud, idEtud) == 0 && strcasecmp(point.id_cours, idcours) == 0){
                    while( !(feof(fichEvaluation)) ){
                        fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                        if(strcasecmp(point.id_eval, eval.id_eval) == 0){
                            affichage(20, 3);
                            printf("Note de %s Dans le cours %s", point.idEtud, eval.nom_cours);
                            affichage(30, k);
                            printf("%s ===>", eval.type);
                            affichage(45, k);
                            printf("%.2f", point.note);
                            k++;
                        }
                    }
                    fseek(fichEvaluation, 0, SEEK_SET);
                }
            }
            fclose(fichNote);
            fclose(fichEvaluation);
        }

    }
    if(r != 1){
        system("cls");
        affichage(40, k+3);
        printf("Ce cours n'a pas de note enregistr%c!!", 130);
    }

    if(r == 1 && r1 != 1){
        system("cls");
        affichage(40, k+3);
        printf("Cet %ctudiant n'a pas de note enregistr%c!!", 130, 130);
    }
    affichage(40, k+4);
    system("pause");
}

////////////////////////////////////////////////////
void modifierNoteEtudiant()
{
    char id_note[15], note1[9];
    int r = 0, idNote;
    float noteN;

    do{
        system("cls");
        affichage(43, 6);
        printf("=========== Section modifier note d'un %ctudiant ==========", 144);
        affichage(43, 8);
        printf("Entrer l'Id note");
        affichage(43, 9);
        printf("((                ))");
        affichage(46, 9);
        gets(id_note);

        idNote = atoi(id_note);
        if(idNote == 0){
            system("cls");
            affichage(40, 16);
            printf("ID note invalide, veuillez r%cessayer !!", 130);
            affichage(40, 17);
            system("pause");
        }
    }while(idNote <= 0 || testDigit(id_note) > 0);

    fichNote = fopen(fichierNote, "r");
    if(!(fichNote)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note !!");
        affichage(40, 17);
        system("pause");
    }

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    if(fichNote && fichEvaluation){
        while(!(feof(fichNote))){
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            while(!(feof(fichEvaluation))){
                fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                if(point.idNote == idNote && strcasecmp(point.id_eval, eval.id_eval) == 0){
                    point1.idNote = point.idNote;
                    strcpy(point1.id_eval, point.id_eval);
                    strcpy(point1.idEtud, point.idEtud);
                    strcpy(point1.id_cours, point.id_cours);

                    afficherEnteteNote();
                    affichage(1, 4);
                    printf("%d", point.idNote);
                    affichage(15, 4);
                    printf("%s", point.id_eval);
                    affichage(45, 4);
                    printf("%s", point.id_cours);
                    affichage(65, 4);
                    printf("%s", point.idEtud);
                    affichage(85, 4);
                    printf("%.2f", point.note);
                    affichage(95, 4);
                    printf("%s", eval.type);
                    r = 1;//Cela dit que l'ID note est enregistré
                    affichage(30, 6);
                    system("pause");
                    break;
                }
            }
            fseek(fichEvaluation, 0, SEEK_SET);
        }
        fclose(fichNote);
        fclose(fichEvaluation);
    }

    if(r == 1){//A oui on continue
        do{
            system("cls");
            affichage(43, 6);
            printf("=========== Section modifier note d'un %ctudiant ==========", 144);
            affichage(43, 8);
            printf("Entrer la nouvelle note de l'%ctudiant :", 130);
            affichage(43, 9);
            printf("((                ))");
            affichage(46, 9);
            gets(note1);

            noteN = atof(note1);
            if(noteN <= 0.0 || noteN >100){
                system("cls");
                affichage(30, 12);
                printf("Erreur !! Veuillez entrer une note valide, la note maximale est 100 !!");
                affichage(30, 13);
                system("pause");
            }
        }while(testChampVide(note1) > 0 || noteN <= 0.0 || noteN > 100);
        point1.note = noteN;

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
                if(point1.idNote != point.idNote){
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

        fichNote = fopen(fichierNote, "a+");
        if(!(fichNote)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier note !!");
            affichage(40, 17);
            system("pause");
        }

        if(fichNote){
            fprintf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%.2f\n", point1.idNote, point1.id_eval, point1.id_cours, point1.idEtud, point1.note);
            fclose(fichNote);
            system("cls");
            affichage(30, 10);
            printf("C'est fait !!");
            affichage(30, 11);
            system("pause");
        }
    }
    else{
        system("cls");
        affichage(40, 16);
        printf("Cet ID n'est pas dans le fichier note !!");
        affichage(40, 17);
        system("pause");
    }
}

////////////////////////////////////////////////////
void moyenneEtudiant()
{
    char idEtud[15];
    int r = 0, k = 3, i = 1;

    fichNote = fopen(fichierNote, "r");
    if(!(fichNote)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note !!");
        affichage(40, 17);
        system("pause");
    }

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    fichNoteFinaleBcp = fopen(fichierNoteFinaleBcp, "w");
    if(!(fichNoteFinaleBcp)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale backup!!");
        affichage(40, 17);
        system("pause");
    }

    fichEtudiants = fopen(fichierEtudiants, "r");
    if(!(fichEtudiants)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %ctudiant!!", 130);
        affichage(40, 17);
        system("pause");
    }
    /*
    Nous allons parcourir le fichier note et le fichier etudiant et enfin le fichier evaluation
    pour mettre les notes intra sur 40% et les notes finales sur 60%. Pour le mettre dans le fichier
    où le pointeur fichNoteFinaleBcp est fixé!!
    */
    if(fichNote && fichEvaluation && fichNoteFinaleBcp && fichEtudiants){
        while(!(feof(fichNote))){
            fscanf(fichNote, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n", &point.idNote, point.id_eval, point.id_cours, point.idEtud, &point.note);
            while( !(feof(fichEtudiants)) ){
                fscanf(fichEtudiants,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", etud.idEtud, etud.nom, etud.prenom, etud.sexe, etud.tel);
                if(strcasecmp(point.idEtud, etud.idEtud) == 0){
                    while(!(feof(fichEvaluation))){
                        fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                        if(strcasecmp(point.id_eval, eval.id_eval) == 0){
                            point2.note = point.note*eval.ponderation;
                            strcpy(point2.idEtud, etud.idEtud);
                            strcpy(etud1.nom, etud.nom);
                            strcpy(etud1.prenom, etud.prenom);
                            strcpy(eval1.nom_cours, eval.nom_cours);
                            fprintf(fichNoteFinaleBcp, "%s\t\t%s %s\t\t\t%s\t\t\t%.2f\t\t%s\n", point2.idEtud, etud1.prenom, etud1.nom, eval1.nom_cours, point2.note, eval.id_eval);
                        }
                    }
                    fseek(fichEvaluation, 0, SEEK_SET);
                }
            }
            fseek(fichEtudiants, 0, SEEK_SET);
        }
        fclose(fichNote);
        fclose(fichNoteFinaleBcp);
        fclose(fichEtudiants);
        fclose(fichEvaluation);
    }

/////////////////////////////
    fichNoteFinaleBcp = fopen(fichierNoteFinaleBcp, "r");
    if(!(fichNoteFinaleBcp)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale backup1!!");
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

    fichEvaluation = fopen(fichierEvaluation, "r");
    if(!(fichEvaluation)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier %cvaluation !!", 130);
        affichage(40, 17);
        system("pause");
    }

    //Maintenant nous pouvons afficher le palmares de tous les etudiants

    system("cls");
    if(fichNoteFinaleBcp && fichCours && fichEvaluation){
        while(!feof(fichNoteFinaleBcp)){
            fscanf(fichNoteFinaleBcp, "%s\t\t%s %s\t\t\t%s\t\t\t%f\t\t%s\n", point3.idEtud, etud2.prenom, etud2.nom, eval.nom_cours, &point3.note, eval1.id_eval);
            while( !(feof(fichCours)) ){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                while(!(feof(fichEvaluation))){
                    fscanf(fichEvaluation, "%s\t\t\t%s\t\t\t%s\t\t\t\t%s\t\t\t%f\n", eval.id_eval, eval.id_cours, eval.nom_cours, eval.type, &eval.ponderation);
                    if(strcasecmp(eval.nom_cours, cours.nom) == 0 && strcasecmp(eval1.id_eval, eval.id_eval) == 0){
                        affichage(1, 1);
                        printf("No");
                        affichage(8, 1);
                        printf("ID Etudiant");
                        affichage(23,1);
                        printf("NOM");
                        affichage(40, 1);
                        printf("PR%cNOM", 144);
                        affichage(60, 1);
                        printf("COURS");
                        affichage(80, 1);
                        printf("NOTE TOTALE");

                        affichage(1, k);
                        printf("%d", i);
                        affichage(8, k);
                        printf("%s", point3.idEtud);
                        affichage(23, k);
                        printf("%s", etud2.nom);
                        affichage(40, k);
                        printf("%s", etud2.prenom);
                        affichage(60, k);
                        printf("%s", eval.nom_cours);
                        affichage(80, k);
                        printf("%.2f / %s", point3.note, eval.type);
                        k++;
                        i++;
                    }
                }
                fseek(fichEvaluation, 0, SEEK_SET);
            }
            fseek(fichCours, 0, SEEK_SET);
        }
        fclose(fichNoteFinaleBcp);
        fclose(fichCours);
        fclose(fichEvaluation);
    }
        //////////////////////////////L'ID de l'étudiant
    do{
        affichage(3, k+1.5);
        printf("Entrer l'Id de l'%ctudiant :", 130);
        affichage(30, k+1.5);
        printf("((                ))");
        affichage(33, k+1.5);
        gets(idEtud);
    }while(testChampVide(idEtud) > 0);

////////////////////////////////////
    fichNoteFinaleBcp = fopen(fichierNoteFinaleBcp, "r");
    if(!(fichNoteFinaleBcp)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale backup!!");
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

    fichNoteFinaleBcp1 = fopen(fichierNoteFinaleBcps, "w");
    if(!(fichNoteFinaleBcp1)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale backup1!!");
        affichage(40, 17);
        system("pause");
    }
    //Maintenant nous allons multiplier les notes intra et finales par le coefficient des matières
    //respectives
    if(fichNoteFinaleBcp && fichNoteFinaleBcp1 && fichCours){
        while( !(feof(fichCours)) ){
            fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
            while(!feof(fichNoteFinaleBcp)){
                fscanf(fichNoteFinaleBcp, "%s\t\t%s %s\t\t\t%s\t\t\t%f\t\t%s\n", point2.idEtud, etud1.prenom, etud1.nom, eval1.nom_cours, &point2.note, eval.id_eval);
                if(strcasecmp(cours.nom, eval1.nom_cours) == 0){
                    point3.note = point2.note * cours.cofficient;
                    fprintf(fichNoteFinaleBcp1, "%s\t\t%s %s\t\t\t%s\t\t\t%.2f\t\t%s\n", point2.idEtud, etud1.prenom, etud1.nom, eval1.nom_cours, point3.note, eval.id_eval);
                }
            }
            fseek(fichNoteFinaleBcp, 0, SEEK_SET);
        }
        fclose(fichCours);
        fclose(fichNoteFinaleBcp1);
        fclose(fichNoteFinaleBcp);
    }

    fichNoteFinaleBcp1 = fopen(fichierNoteFinaleBcps, "r");
    if(!(fichNoteFinaleBcp1)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale backup1!!");
        affichage(40, 17);
        system("pause");
    }

    fichNoteFinale = fopen(fichierNoteFinale, "w");
    if(!(fichNoteFinale)){
        system("cls");
        affichage(40, 16);
        printf("Impossible d'ouvrir le fichier note finale!!");
        affichage(40, 17);
        system("pause");
    }

    point4.note = 0;//une variable de structure au lieu de déclarer une autre variable
    // On fait la somme des notes de l'ID étudiant saisi par l'USER
    if(fichNoteFinaleBcp1 && fichNoteFinale){
        while(!feof(fichNoteFinaleBcp1)){
            fscanf(fichNoteFinaleBcp1, "%s\t\t%s %s\t\t\t%s\t\t\t%f\t\t%s\n", point3.idEtud, etud2.prenom, etud2.nom, eval.nom_cours, &point3.note, eval1.id_eval);
            if(strcasecmp(point3.idEtud, idEtud) == 0){
                point4.note += point3.note;
                point.note = point4.note;
                strcpy(etud1.idEtud, point3.idEtud);
                strcpy(etud1.nom, etud2.nom);
                strcpy(etud1.prenom, etud2.prenom);
                strcpy(eval1.nom_cours, eval.nom_cours);
                strcpy(eval.id_eval, eval1.id_eval);
                r = 1;
            }
        }
        //On stocke ces donnees dans le fichier note finale backup
        fprintf(fichNoteFinale, "%s\t\t%s %s\t\t\t%s\t\t\t%.2f\t\t%s\n", etud1.idEtud, etud1.prenom, etud1.nom, eval1.nom_cours, point4.note, eval.id_eval);
        fclose(fichNoteFinaleBcp1);
        fclose(fichNoteFinale);
    }

    if(r == 1){
        fichCours = fopen(fichierCours, "r");
        if(!(fichCours)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier cours !!");
            affichage(40, 17);
            system("pause");
        }

        point5.note = 0;//Un variable de structure pour faire la somme des coefficients
        if(fichCours){
            while( !(feof(fichCours)) ){
                fscanf(fichCours,"%s\t\t\t\t%s\t\t\t\t%d\n", cours.id_cours, cours.nom, &cours.cofficient);
                point5.note += cours.cofficient;
            }
            fclose(fichCours);
        }

        fichNoteFinale = fopen(fichierNoteFinale, "r");
        if(!(fichNoteFinale)){
            system("cls");
            affichage(40, 16);
            printf("Impossible d'ouvrir le fichier note finale!!");
            affichage(40, 17);
            system("pause");
        }

        // On affiche la note finale de l'étudiant après le palmares et sa moyenne
        if(fichNoteFinale){
            while(!feof(fichNoteFinale)){
                fscanf(fichNoteFinale, "%s\t\t%s %s\t\t\t%s\t\t\t%f\t\t%s\n", etud1.idEtud, etud1.prenom, etud1.nom, eval1.nom_cours, &point4.note, eval.id_eval);
                affichage(45, k+3);
                printf("Note totale de %s %s ===> %.2f", etud1.prenom, etud1.nom, point.note);
                affichage(40, k+5);
                printf("     Moyenne de l'%ctudiant =====> %.2f", 130, point4.note/point5.note);
            }
            fclose(fichNoteFinale);
        }
    }
    else{
        affichage(30, k+5);
        printf("Cet Etudiant n'a pas de note enregistre");
        affichage(30, k+6);
        system("pause");
    }
    affichage(30, k+7);
    system("pause");


}

////////////////////////////////////////////////////

#endif // CONSULTATIONSNOTES_H_INCLUDED
