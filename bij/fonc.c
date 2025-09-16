#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc.h"


FORMATION afficher_formation_plus_couteuse(CENTRE centre) {
    float prix_max = 0;
    FORMATION F;

    for (int i = 0; i < centre.nbr_Locales; i++) {

        for (int j = 0; j < (centre.locale+i)->nbr_Formations; j++) {
            if (((centre.locale+i)->formation+j)->prix > prix_max) {
                F=*((centre.locale+i)->formation+j);
                 prix_max=((centre.locale+i)->formation+j)->prix;
            }
        }
    }

    return F;
}

CANDIDAT afficher_candidat_meilleure_moyenne(FORMATEUR formateur) {
    float moyenne_max = 0;
    CANDIDAT meilleur_candidat;

    for (int i = 0; i < formateur.nbr_seance; i++) {

        for (int j = 0; j < (formateur.seance+i)->nbr_candidat; j++) {
            CANDIDAT candidat = formateur.seance[i].candidat[j];
            if (((formateur.seance+i)->candidat+j)->moyenne > moyenne_max) {
                moyenne_max = ((formateur.seance+i)->candidat+j)->moyenne;
                meilleur_candidat = *((formateur.seance+i)->candidat+j);
            }
        }
    }
    return meilleur_candidat;
}

void afficher_locales_donnee(CENTRE c,int n) {
    printf("Local num %d:\n", n);

    printf("\nid =\t%d",(c.locale+(n-1))->id);
    printf("\nnom =\t%s",(c.locale+(n-1))->nom);
    printf("\nlocalisation =\t%s",(c.locale+n-1)->localisation);
    printf("\nnombre des formation =\t%d",(c.locale+(n-1))->nbr_Formations);
}

void afficher_formations_locale(CENTRE c,int id_loc) {
    LOCALE locale;
    printf("Formations assurées par la locale %s:\n", (c.locale+id_loc-1)->nom);

    for (int i = 0; i < (c.locale+id_loc-1)->nbr_Formations; i++) {

        printf("- %s\n", ((c.locale+id_loc-1)->formation+i)->nom);
    }
}

float calculer_revenu_formateur(FORMATEUR formateur) {
    float revenu_total = 0;

    for (int i = 0; i < formateur.nbr_seance; i++) {
        revenu_total +=(formateur.seance+i)->prix_seance * formateur.seance[i].nbr_candidat;
    }

    return revenu_total;
}

int calculer_nombre_formations(CENTRE centre) {
    int total_formations = 0;

    for (int i = 0; i < centre.nbr_Locales; i++) {

        total_formations += (centre.locale+i)->nbr_Formations;
    }
    return total_formations;
}

CANDIDAT afficher_plus_petit_candidat(FORMATEUR F) {
    int j, i;
    int a = 0, m = 0, jj = 0;
    CANDIDAT c;


    for (i = 0; i < F.nbr_seance; i++) {
        for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
            int annee = ((F.seance+i)->candidat+j)->date_Naissance.annee;
            int mois = ((F.seance+i)->candidat+j)->date_Naissance.mois;
            int jour = ((F.seance+i)->candidat+j)->date_Naissance.jour;


            if (annee > a || (annee == a && mois > m) || (annee == a && mois == m && jour > jj)) {
                a = annee;
                m = mois;
                jj = jour;
                c =  *((F.seance+i)->candidat+j);
            }
        }
    }

    return c;

}

CANDIDAT afficher_plus_grand_candidat(FORMATEUR F) {
   int j, i;
    int a = 0, m = 0, jj = 0;
    CANDIDAT c;


    a = 9999;
    m = 13;
    jj = 32;


    for (i = 0; i < F.nbr_seance; i++) {
        for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
            int annee = ((F.seance+i)->candidat+j)->date_Naissance.annee;
            int mois = ((F.seance+i)->candidat+j)->date_Naissance.mois;
            int jour = ((F.seance+i)->candidat+j)->date_Naissance.jour;
            if (annee < a || (annee == a && mois < m) || (annee == a && mois == m && jour < jj)) {
                a = annee;
                m = mois;
                jj = jour;
                c = *((F.seance+i)->candidat+j);
            }
        }
    }

    return c;
}


CENTRE saisie_centre()
{
    int i,j;
    CENTRE c;
 printf("\n donner ID du centre: ");
 scanf("%d", &c.ID);
 printf("donner Nom du centre: ");
 scanf("%s", &c.Nom);
 printf("donner Nombre de locaux: ");
scanf("%d", &c.nbr_Locales);
 c.locale = (LOCALE*)malloc(c.nbr_Locales * sizeof(LOCALE));
 if (!c.locale) exit(-1);
 for (i = 0; i < c.nbr_Locales; i++) {
 printf("\ndonner  ID du local num %d : ",i+1 );
 scanf("%d", &(c.locale+i)->id);
 printf("\n donner Nom du local num %d: ",i+1);
 scanf("%s", (c.locale+i)->nom);
 printf("\n donner Localisation du local num %d : ",i+1 );
 scanf("%s", (c.locale+i)->localisation);
 printf("\n donner Nombre de formations du local num %d :",i+1 );
 scanf("%d", &(c.locale+i)->nbr_Formations);
 (c.locale+i)->formation = (FORMATION*)malloc((c.locale+i)->nbr_Formations *
sizeof(FORMATION));
 if (!(c.locale+i)->formation) exit(-2);
 for (j = 0; j < (c.locale+i)->nbr_Formations; j++) {
 printf("\n donner Nom de la formation num %d de local num %d : ",j+1,i+1 );
 scanf("%s", ((c.locale+i)->formation+j)->nom);
 printf("\n donner Prix de la formation num %d de local num %d : ",j+1,i+1);
 scanf("%d", &((c.locale+i)->formation+j)->prix);
 printf("\n donner Durée de la formation  num %d de local num %d :",j+1,i+1);
 printf("\n donner le nombre d'heures :");
scanf("%d", &((c.locale+i)->formation+j)->duree.heure);
 printf("donner le nombre de minutes :");
 scanf("%d", &((c.locale+i)->formation+j)->duree.minute);
 }
 }
 return c;

}
void affichage_centre(CENTRE c)
{
     int i,j;
    printf("\n -------------------------CENTRE---------------------\n");
 printf("\n ID du centre: %d ",c.ID);
 printf("\n Nom du centre: %s ",c.Nom);
 printf("\n Nombre de locaux: %d",c.nbr_Locales);
 for (i = 0; i < c.nbr_Locales; i++) {
 printf("\n******************LOCALE num=%d**************************\n",i+1);
 printf("\n \t\t\t\t\t\tID du local num %d : \t %d",i+1,(c.locale+i)->id);
 printf("\n \t\t\t\t\t\tNom du local num %d: \t %s ",i+1,(c.locale+i)->nom);
 printf("\n \t\t\t\t\t\tLocalisation du local num %d : \t  %s",i+1,(c.locale+i)->localisation);
 printf("\n \t\t\t\t\t\tNombre de formations du local num %d : \t %d",i+1,(c.locale+i)->nbr_Formations);
 printf("\n****************************************************\n");
 for (j = 0; j < (c.locale+i)->nbr_Formations; j++) {
 printf("\n ................FORMATION num=%d....................................\n",j+1);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tNom de la formation num %d de local num %d : `\t %s",j+1,i+1,((c.locale+i)->formation+j)->nom);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tPrix de la formation num %d de local num %d : \t%dDTN",j+1,i+1,((c.locale+i)->formation+j)->prix);
printf("\n \t\t\t\t\t\t\t\t\t\t\tDuree de la formation  num %d de local num %d : \t %dh%dmin",j+1,i+1,
 ((c.locale+i)->formation+j)->duree.heure,((c.locale+i)->formation+j)->duree.minute);
 }
 }
 printf("\n...................................................................................................................................................................\n");

}

FORMATEUR saisie_formateur( ){
 int i,j;
 FORMATEUR F;
 printf("\n...................................................................................................................................................................\n");
 printf("\nDonner l'id du formateur: ");
 scanf("%d", &F.ident);
 printf("\nDonner le nom du formateur: ");
 scanf("%s", &F.nom);
 printf("\nDonner le prenom du formateur: ");
 scanf("%s", &F.prenom);
 printf("Donner la date de naissance du formateur (JJ/MM/AAAA): ");
 printf("\n\t\tjour: ");
 scanf("%d", &F.date_Naissance.jour);
 printf("\n\t\tmois: ");
 scanf("%d", &F.date_Naissance.mois);
 printf("\n\t\tannee: ");
 scanf("%d", &F.date_Naissance.annee);
 printf("Donner la formation qui fournit ce formateur:");
printf("\n\t\tnom: ");
 scanf("%s", &F.formation.nom);
 printf("\n\t\tprix: ");
 scanf("%d", &F.formation.prix);
 printf("\n\t\tduree: ");
 printf("\n\t\t\t\theure: ");
 scanf("%d", &F.formation.duree.heure);
 printf("\n\t\t\t\tminutes: ");
 scanf("%d", &F.formation.duree.minute);
 printf("Donner le nombre de seances necessaire pour cette formation: ");
 scanf("%d", &F.nbr_seance);
 F.seance = (SEANCE*)malloc(F.nbr_seance * sizeof(SEANCE));
 if (!F.seance) exit(-1);
 for (i = 0; i < F.nbr_seance; i++) {
 printf("\nDonner la date de la seance numero %d (JJ/MM/AAAA):", i + 1);
 printf("\n\t\tjour: ");
 scanf("%d", &(F.seance+i)->date_seance.jour);
 printf("\n\t\tmois: ");
scanf("%d", &(F.seance+i)->date_seance.mois);
 printf("\n\t\tannee: ");
 scanf("%d", &(F.seance+i)->date_seance.annee);
 printf("Donner le temps de debut de la seance %d (HH:MM): ", i + 1);
 printf("\n\t\t\t\theure: ");
 scanf("%d", &(F.seance+i)->temps.heure);
 printf("\n\t\t\t\tminutes: ");
 scanf("%d", &(F.seance+i)->temps.minute);
 printf("Donner le prix de la seance %d: ", i + 1);
 scanf("%f", &(F.seance+i)->prix_seance);
 printf("Donner le nombre de candidats de la seance %d: ", i + 1);
 scanf("%d", &(F.seance+i)->nbr_candidat);
 (F.seance+i)->candidat = (CANDIDAT*)malloc((F.seance+i)->nbr_candidat *
sizeof(CANDIDAT));
 if (!(F.seance+i)->candidat) exit(-2);
 for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
 printf("Donner l'id du candidat numero %d: ", j + 1);
 scanf("%d", &((F.seance+i)->candidat+j)->code);
printf("Donner le nom du candidat numero %d: ", j + 1);
 scanf("%s", ((F.seance+i)->candidat+j)->nom);
 printf("Donner le prenom du candidat numero %d: ", j + 1);
 scanf("%s", ((F.seance+i)->candidat+j)->prenom);
 printf("Donner la date de naissance du candidat numero %d (JJ/MM/AAAA): ", j + 1);
 printf("\n\t\tjour: ");
 scanf("%d", &((F.seance+i)->candidat+j)->date_Naissance.jour);
 printf("\n\t\tmois: ");
 scanf("%d", &((F.seance+i)->candidat+j)->date_Naissance.mois);
 printf("\n\t\tannee: ");
 scanf("%d", &((F.seance+i)->candidat+j)->date_Naissance.annee);
 printf("Donner la moyenne: ");
 scanf("%f", &((F.seance+i)->candidat+j)->moyenne);
 }
 }
 return F;

}
void affichage_formateur(FORMATEUR F){
 int i,j;
printf("\n_________________FORMATEUR_______________________\n");
 printf("\nL'id du formateur: %d", F.ident);
 printf("\nNom et prenom du formateur: %s\t%s", F.nom, F.prenom);
 printf("\nLa date de naissance du formateur: %d/%d/%d", F.date_Naissance.jour,
F.date_Naissance.mois, F.date_Naissance.annee);
printf("\nNom de formation: %s \t\tPrix de formation: %dDTN \t\tDuree de formation: %dh%dmin",
F.formation.nom, F.formation.prix, F.formation.duree.heure, F.formation.duree.minute);
 printf("\nLe nombre des seances: %d", F.nbr_seance);
 for (i = 0; i < F.nbr_seance; i++) {
 printf("\n************SEANCE num=%d********************\n",i+1);
 printf("\n \t\t\t\t\t\tLa date de la seance numero %d: %d/%d/%d", i + 1, (F.seance+i)->date_seance.jour,
(F.seance+i)->date_seance.mois,(F.seance+i)->date_seance.annee);
 printf("\n \t\t\t\t\t\tLe temps du debut de la seance numero %d: \t%d:%d",i+1,(F.seance+i)->temps.heure,(F.seance+i)->temps.minute);
 printf("\n \t\t\t\t\t\tLe prix de la seance numero %d: \t%f",i+1,(F.seance+i)->prix_seance);
 printf("\n \t\t\t\t\t\tLe nombre des candidat de la seance numero %d: \t%d",i+1,(F.seance+i)->nbr_candidat);
  printf("\n********************************\n");
 for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
 printf("\n ...................CANDIDAT num=%d........................\n",j+1);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tCode de candidat num %d de seance num %d : `\t %d",j+1,i+1,((F.seance+i)->candidat+j)->code);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tNom de candidat num %d de seance num %d : `\t %s",j+1,i+1,((F.seance+i)->candidat+j)->nom);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tPrenom de candidat num %d de seance num %d : `\t %s",j+1,i+1,((F.seance+i)->candidat+j)->prenom);- printf("\n Date de Naissance de candidat num %d de seance num %d : \t %d /%d/%d",j+1,i+1,((F.seance+i)->candidat+j)->date_Naissance.jour,((F.seance+i)->candidat+j)->date_Naissance.mois,((F.seance+i)->candidat+j)->date_Naissance.annee);
 printf("\n \t\t\t\t\t\t\t\t\t\t\tMoyenne de candidat num %d de seance num %d : \t %.2f",j+1,i+1,((F.seance+i)->candidat+j)->moyenne);
}
 }
}

void resultat(FORMATEUR F){
    int i,j,k,cee;
float max;
 RESULTAT** R;
 R = malloc(3 * sizeof(RESULTAT*));
 for ( k = 0; k < 3; k++) {
 *(R+k)= malloc(sizeof(RESULTAT));
 }
 max = 0;
 cee = 0;
 for (i = 0; i < F.nbr_seance; i++) {
 for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
 if (((F.seance+i)->candidat+j)->moyenne > max) {
 max = ((F.seance+i)->candidat+j)->moyenne;
 cee = ((F.seance+i)->candidat+j)->code;
 }
 }
 }
 (*R)->ce = cee;
 (*R)->moy = max;
 for (k = 1; k < 3; k++) {
 max = 0;
 cee = 0;
for (i = 0; i < F.nbr_seance; i++) {
 for (j = 0; j < (F.seance+i)->nbr_candidat; j++) {
 if (((F.seance+i)->candidat+j)->moyenne > max &&((F.seance+i)->candidat+j)->moyenne< (*R+k-1)->moy) {
 max =((F.seance+i)->candidat+j)->moyenne;
 cee = ((F.seance+i)->candidat+j)->code;
 }
 }
 }
 (*R+k)->ce = cee;
 (*R+k)->moy = max;
 }
 for (k = 0; k < 3; k++) {
 printf("\nCLASSEMENT \n candidat num %d = \n ce: %d\n moy: %.2f\n", k+1, (*R+k)->ce,
(*R+k)->moy);
 }
 }

 void menu_affichage(CENTRE c,FORMATEUR F)
 {
     printf("\n\t\t\t\t\t-------------menu_AFFICHAGE----------------\n");
      while(1){
     int choix;
     printf("\n\t\t\t\t\ttapez :\n \t\t\t\t\t-1 pour afficher les informations de centre\n\t\t\t\t\t-2 pour afficher les informations de formateur\n saisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
         affichage_centre(c );
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==2){
        affichage_formateur(F);
         printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

        break;
     }

 }
 }
 void affichage_formation(FORMATION F)
 {
     printf("\n /////////////////////////////////////////////////////////////////////////////\n");
 printf("\n Nom de la formation : `\t %s",F.nom);
 printf("\n Prix de la formation  : \t%dDTN",F.prix);
printf("\n Duree de la formation : \t %dh%dmin",F.duree.heure,F.duree.minute);
 }
void affichage_candidat(CANDIDAT can)
{
    printf("\n /////////////////////////////////////////////////////////////////////////////\n");
 printf("\n Code de candidat  : `\t %d",can.code);
 printf("\n Nom de candidat : `\t %s",can.nom);
 printf("\n Prenom de candidat : `\t %s",can.prenom);
 printf("\n Date de Naissance de candidat : \t %d /%d/%d",can.date_Naissance.jour,can.date_Naissance.mois,can.date_Naissance.annee);
 printf("\n Moyenne de candidat  : \t %.2f",can.moyenne);
}
 void menu_traitements(CENTRE c,FORMATEUR F)
 {
     while(1){
     FORMATION fo;
     CANDIDAT can;
     int n,id_loc,choix;
     float rev;
     printf("\n\t\t\t\t\t--------------menu traitements---------------------\n");
     printf("tapez :\n\t\t\t\t\t1)afficher le nom de la formation la plus couteuse assuree par le centre.\n\t\t\t\t\t2) afficher le candidat qui a la moyenne la plus elevee qui suit une formation chez un formateur donne.\n\t\t\t\t\t3) afficher les informations du n-ieme local .\n\t\t\t\t\t4) afficher toutes les formations assurees par un locale donne.\n\t\t\t\t\t5) afficher le revenu d’un formateur donne. \n\t\t\t\t\t6) afficher le nombre total des formations assurees par le centre. \n\t\t\t\t\t7) afficher le plus grand candidat.\n\t\t\t\t\t8) afficher le plus petit candidat\n saisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
         fo=afficher_formation_plus_couteuse( c);
         affichage_formation(fo);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==2)
     {
         can=afficher_candidat_meilleure_moyenne( F);
         affichage_candidat(can);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==3)
     {
         printf("\ndonner le numero de local a afficher:\t");
         scanf("%d",&n);
         afficher_locales_donnee( c, n);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==4)
     {
         printf("\ndonner le numero du local :\t");
         scanf("%d",&id_loc);
         afficher_formations_locale( c, id_loc);

          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==5)
     {
         rev=calculer_revenu_formateur(F);
         printf("le revenue est=%fDTN",rev);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
     if(choix==6)
     {
         n=calculer_nombre_formations(c);
         printf("le nombre total des formation est = \t%d",n);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
      if(choix==7)
     {
         can= afficher_plus_grand_candidat( F);
         affichage_candidat(can);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
      if(choix==8)
     {
         can= afficher_plus_petit_candidat( F);
         affichage_candidat(can);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
}
printf("\n-----------------------------------------\n");
}
FORMATION saisie_formation()
{
    FORMATION f;
 printf("\n donner Nom de la formation  : " );
 scanf("%s", &f.nom);
 printf("\n donner Prix de la formation d : ");
 scanf("%d", &f.prix);
 printf("\n donner Durée de la formation  :");
 printf("\n donner le nombre d'heures :");
scanf("%d", &f.duree.heure);
 printf("donner le nombre de minutes :");
 scanf("%d", &f.duree.minute);
 return f;
}
void ajouter_formation(CENTRE* centre, int id_local, FORMATION nouvelle_formation) {
    if (centre == NULL) {
        printf("Le centre n'existe pas.\n");
        return;
    }

    if (id_local - 1 < 0 || id_local - 1 >= centre->nbr_Locales) {
        printf("Le local numéro %d n'existe pas dans ce centre.\n", id_local);
        return;
    }
    LOCALE* local = &centre->locale[id_local - 1];
    local->formation = realloc(local->formation, (local->nbr_Formations + 1) * sizeof(FORMATION));

    if (local->formation == NULL) {
        printf("Erreur d'allocation de mémoire pour la formation.\n");
        return;
    }

    local->formation[local->nbr_Formations] = nouvelle_formation;
    local->nbr_Formations++;
    printf("La formation '%s' a été ajoutée avec succès au local numéro %d du centre '%s'.\n",
           nouvelle_formation.nom, id_local, centre->Nom);
}

void supprimer_formation(CENTRE* centre, int id_local, const char* nom_formation) {

    if (centre == NULL) {
        printf("Le centre n'existe pas.\n");
        return;
    }
    if (id_local - 1 < 0 || id_local - 1 >= centre->nbr_Locales) {
        printf("Le local avec l'ID %d n'existe pas dans ce centre.\n", id_local);
        return;
    }
    LOCALE* local = &centre->locale[id_local - 1];
    if (local->nbr_Formations == 0) {
        printf("Aucune formation n'est présente dans ce local.\n");
        return;
    }
    int index_formation = -1;
    for (int i = 0; i < local->nbr_Formations; i++) {
        if (strcmp(local->formation[i].nom, nom_formation) == 0) {
            index_formation = i;
            break;
        }
    }
    if (index_formation == -1) {
        printf("La formation '%s' n'existe pas dans ce local.\n", nom_formation);
        return;
    }
    for (int i = index_formation; i < local->nbr_Formations - 1; i++) {
        local->formation[i] = local->formation[i + 1];
    }
    local->nbr_Formations--;
    if (local->nbr_Formations == 0) {
        free(local->formation);
        local->formation = NULL;
    } else {
        FORMATION* temp = realloc(local->formation, local->nbr_Formations * sizeof(FORMATION));
        if (temp != NULL) {
            local->formation = temp;
        } else {
            printf("Erreur d'allocation de mémoire lors de la suppression de la formation.\n");
            return;
        }
    }

    printf("La formation '%s' a été supprimée avec succès du local num %d.\n", nom_formation, id_local);
}

void menu_gestion_centre(CENTRE c,FORMATEUR F)
{
    while(1){
     FORMATION fo;
     int n,choix;
     char ch[20];
       printf("\n\t\t\t\t\t--------------menu_gestion_centre---------------------\n");
     printf("\n\t\t\t\t\ttapez :\n \t\t\t\t\t-1 pour ajouter une formation\n\t\t\t\t\t-2 pour suprimer une formation\n saisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
         affichage_centre(c);
         printf("\ndonner le numero du local :\t");
         scanf("%d",&n);
         fo=saisie_formation();
         ajouter_formation( &c,  n,  fo);
         affichage_centre(c);
          printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );


         break;
     }
      if(choix==2)
     {
         affichage_centre(c);
        printf("\ndonner le numero du local :\t");
        scanf("%d",&n);
        printf("\ndonner le nom de formation");
        scanf("%s",ch);
        supprimer_formation(&c,  n, ch);
        affichage_centre(c);
         printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
    }
    printf("\n-----------------------------------------\n");
}
void ajouter_candidat_a_seance(FORMATEUR* formateur, int id_seance, CANDIDAT candidat) {
    if (formateur == NULL) {
        printf("Erreur : formateur NULL.\n");
        return;
    }
    if (id_seance-1 < 0 || id_seance >= formateur->nbr_seance+1) {
        printf("Erreur : séance inexistante.\n");
        return;
    }
    SEANCE* seance = &formateur->seance[id_seance-1];
    CANDIDAT* temp = realloc(seance->candidat, (seance->nbr_candidat + 1) * sizeof(CANDIDAT));
    if (temp == NULL) {
        printf("Erreur d'allocation de mémoire pour ajouter un candidat.\n");
        return;
    }
    seance->candidat = temp;
    seance->candidat[seance->nbr_candidat] = candidat;
    seance->nbr_candidat++;

    printf("Candidat %s %s ajouté à la séance %d du formateur %s %s.\n",
           candidat.nom, candidat.prenom, id_seance, formateur->nom, formateur->prenom);
}
CANDIDAT saisie_candidat()
{
    CANDIDAT can;
    printf("Donner l'id du candidat : ");
 scanf("%d", &can.code);
printf("Donner le nom du candidat : ");
 scanf("%s", can.nom);
 printf("Donner le prenom du candidat numero %d: ");
 scanf("%s", can.prenom);
 printf("Donner la date de naissance du candidat numero %d (JJ/MM/AAAA): ");
 printf("\n\t\tjour: ");
 scanf("%d", &can.date_Naissance.jour);
 printf("\n\t\tmois: ");
 scanf("%d", &can.date_Naissance.mois);
 printf("\n\t\tannee: ");
 scanf("%d", &can.date_Naissance.annee);
 printf("Donner la moyenne: ");
 scanf("%f", &can.moyenne);
 return can;
}
void supprimer_candidat(FORMATEUR* F, int num_seance, int code_candidat) {
    if (F == NULL) {
        printf("Erreur : Formateur NULL.\n");
        return;
    }
    if (num_seance <= 0 || num_seance > F->nbr_seance) {
        printf("Erreur : Séance inexistante.\n");
        return;
    }
    SEANCE* seance = &F->seance[num_seance - 1];
    int found = 0;

    for (int i = 0; i < seance->nbr_candidat; i++) {
        if (seance->candidat[i].code == code_candidat) {

            for (int j = i; j < seance->nbr_candidat - 1; j++) {
                seance->candidat[j] = seance->candidat[j + 1];
            }
            seance->nbr_candidat--;


            if (seance->nbr_candidat == 0) {
                free(seance->candidat);
                seance->candidat = NULL;
            } else {

                CANDIDAT* temp = realloc(seance->candidat, seance->nbr_candidat * sizeof(CANDIDAT));
                if (temp != NULL) {
                    seance->candidat = temp;
                } else {
                    printf("Erreur de réallocation de mémoire après suppression du candidat.\n");
                }
            }

            printf("Candidat avec le code %d supprimé avec succès de la séance %d.\n", code_candidat, num_seance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Candidat avec le code %d non trouvé dans la séance %d.\n", code_candidat, num_seance);
    }
}

void menu_gestion_formateur(CENTRE c,FORMATEUR F)
{
    while(1){
     CANDIDAT can;
     int n,id,choix,co;

     printf("\n\t\t\t\t\t--------------menu_gestion_formateur---------------------\n");
     printf("\n\t\t\t\t\ttapez :\n\t\t\t\t\t -1 pour ajouter un candidat\n\t\t\t\t\t-2 pour suprimer un candidat\n saisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
          affichage_formateur(F);
         printf("\ndonner le numero de seance :\t\n");
         scanf("%d",&n);
         printf("\n saisir le candidat a ajouter:\n");
         can=saisie_candidat();
         ajouter_candidat_a_seance( &F,  n, can);
         affichage_formateur(F);
         printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
      if(choix==2)
     {
          affichage_formateur(F);
         printf("\ndonner le num de seance :\t\n");
        scanf("%d",&n);
        printf("\ndonner l'code de candidat a effacer\n");
        scanf("%d",&co);
        supprimer_candidat(&F,  n,  co);
        affichage_formateur(F);
         printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );

         break;
     }
    }
    printf("\n-----------------------------------------\n");
}
void menu_principale(CENTRE c,FORMATEUR F)
{
     while(1){
     CANDIDAT can;
     int n,id,choix;
     printf("\n\t\t\t\t\t-------------- menu_principale---------------------\n");
     printf("\n\t\t\t\t\ttapez :\n\t\t\t\t\t-1 pour rejoindre le menu AFFICHAGE:\n\t\t\t\t\t-2 pour rejoindre le menu TRAITEMENTS:\n\t\t\t\t\t-3 pour gestionner le CENTRE:\n\t\t\t\t\t-4 pour gestionner le FORMATEUR:\n\t\t\t\t\t-5 pour afficher RESULTAT:\nsaisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
         menu_affichage(c ,F );
         break;
     }
      if(choix==2)
     {
         menu_traitements(c ,F );

         break;
     }
      if(choix==3)
     {
        menu_gestion_centre(c,F );

         break;
     }
      if(choix==4)
     {
         menu_gestion_formateur(c,F );

         break;
     }
     if(choix==5)
     {
       affichage_formateur(F);
       printf("\n\t\t\t\t\t----------CLASSEMENT---------------\n");
       resultat( F);
       printf("\n-------------tapez 1 pour retourner au menu principal--------------------\n");
         printf("\n-------------tapez 2 pour quiter--------------------\n");
         scanf("%d",&choix);
         if( choix==1)
             menu_principale(c ,F );


         break;
     }
     }
}
void charger_centre(CENTRE* centre) {
    FILE* fp = fopen("centre", "rb");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    fread(&centre->ID, sizeof(int), 1, fp);
    fread(centre->Nom, sizeof(char), 20, fp);
    fread(&centre->nbr_Locales, sizeof(int), 1, fp);
    centre->locale = (LOCALE*)malloc(centre->nbr_Locales * sizeof(LOCALE));
    if (centre->locale == NULL) {
        printf("Erreur d'allocation mémoire pour les locales.\n");
        fclose(fp);
        return;
    }
    for (int i = 0; i < centre->nbr_Locales; i++) {
        LOCALE* loc = &centre->locale[i];
        fread(&loc->id, sizeof(int), 1, fp);
        fread(loc->nom, sizeof(char), 20, fp);
        fread(loc->localisation, sizeof(char), 20, fp);
        fread(&loc->nbr_Formations, sizeof(int), 1, fp);
        loc->formation = (FORMATION*)malloc(loc->nbr_Formations * sizeof(FORMATION));
        if (loc->formation == NULL) {
            printf("Erreur d'allocation mémoire pour les formations.\n");
            fclose(fp);
            return;
        }
        for (int j = 0; j < loc->nbr_Formations; j++) {
            FORMATION* form = &loc->formation[j];
            fread(form->nom, sizeof(char), 20, fp);
            fread(&form->prix, sizeof(float), 1, fp);
            fread(&form->duree, sizeof(TEMPS), 1, fp);
        }
    }
    fclose(fp);
}

void charger_formateur(FORMATEUR* F) {
    FILE* fp = fopen("formateur", "rb");

    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    fread(&F->ident, sizeof(int), 1, fp);
    fread(F->nom, sizeof(char), 20, fp);
    fread(F->prenom, sizeof(char), 20, fp);
    fread(&F->date_Naissance.jour, sizeof(int), 1, fp);
    fread(&F->date_Naissance.mois, sizeof(int), 1, fp);
    fread(&F->date_Naissance.annee, sizeof(int), 1, fp);
    fread(F->formation.nom, sizeof(char), 20, fp);
    fread(&F->formation.duree, sizeof(int), 1, fp);
    fread(&F->formation.prix, sizeof(float), 1, fp);
    fread(&F->nbr_seance, sizeof(int), 1, fp);

    F->seance = (SEANCE*)malloc(F->nbr_seance * sizeof(SEANCE));

    for (int i = 0; i < F->nbr_seance; i++) {
        fread(&(F->seance+i)->date_seance.jour, sizeof(int), 1, fp);
        fread(&(F->seance+i)->date_seance.mois, sizeof(int), 1, fp);
        fread(&(F->seance+i)->date_seance.annee, sizeof(int), 1, fp);
        fread(&(F->seance+i)->temps.heure, sizeof(int), 1, fp);
        fread(&(F->seance+i)->temps.minute, sizeof(int), 1, fp);
        fread(&(F->seance+i)->prix_seance, sizeof(float), 1, fp);
        fread(&(F->seance+i)->nbr_candidat, sizeof(int), 1, fp);

       (F->seance+i)->candidat = (CANDIDAT*)malloc((F->seance+i)->nbr_candidat * sizeof(CANDIDAT));

        for (int j = 0; j < (F->seance+i)->nbr_candidat; j++) {
            fread(&((F->seance+i)->candidat+j)->code, sizeof(int), 1, fp);
            fread(&((F->seance+i)->candidat+j)->nom, sizeof(char), 20, fp);
            fread(&((F->seance+i)->candidat+j)->prenom, sizeof(char), 20, fp);
            fread(&((F->seance+i)->candidat+j)->date_Naissance.jour, sizeof(int), 1, fp);
            fread(&((F->seance+i)->candidat+j)->date_Naissance.mois, sizeof(int), 1, fp);
            fread(&((F->seance+i)->candidat+j)->date_Naissance.annee, sizeof(int), 1, fp);
            fread(&((F->seance+i)->candidat+j)->moyenne, sizeof(float), 1, fp);
        }
    }

    fclose(fp);
}


void enregistrer_formateur(FORMATEUR F) {
    FILE* fp = fopen("formateur2", "wb+");

    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fwrite(&F.ident, sizeof(int), 1, fp);
    fwrite(F.nom, sizeof(char), 20, fp);
    fwrite(F.prenom, sizeof(char), 20, fp);
    fwrite(&F.date_Naissance.jour, sizeof(int), 1, fp);
    fwrite(&F.date_Naissance.mois, sizeof(int), 1, fp);
    fwrite(&F.date_Naissance.annee, sizeof(int), 1, fp);
    fwrite(F.formation.nom, sizeof(char), 20, fp);
    fwrite(&F.formation.duree, sizeof(int), 1, fp);
    fwrite(&F.formation.prix, sizeof(float), 1, fp);
    fwrite(&F.nbr_seance, sizeof(int), 1, fp);

    for (int i = 0; i < F.nbr_seance; i++) {
        fwrite(&(F.seance+i)->date_seance.jour, sizeof(int), 1, fp);
        fwrite(&(F.seance+i)->date_seance.mois, sizeof(int), 1, fp);
        fwrite(&(F.seance+i)->date_seance.annee, sizeof(int), 1, fp);
        fwrite(&(F.seance+i)->temps.heure, sizeof(int), 1, fp);
        fwrite(&(F.seance+i)->temps.minute, sizeof(int), 1, fp);
        fwrite(&(F.seance+i)->prix_seance, sizeof(float), 1, fp);
        fwrite(&(F.seance+i)->nbr_candidat, sizeof(int), 1, fp);

        for (int j = 0; j < (F.seance+i)->nbr_candidat; j++) {
            fwrite(&((F.seance+i)->candidat+j)->code, sizeof(int), 1, fp);
            fwrite(((F.seance+i)->candidat+j)->nom, sizeof(char), 20, fp);
            fwrite(((F.seance+i)->candidat+j)->prenom, sizeof(char), 20, fp);
            fwrite(&((F.seance+i)->candidat+j)->date_Naissance.jour, sizeof(int), 1, fp);
            fwrite(&((F.seance+i)->candidat+j)->date_Naissance.mois, sizeof(int), 1, fp);
            fwrite(&((F.seance+i)->candidat+j)->date_Naissance.annee, sizeof(int), 1, fp);
            fwrite(&((F.seance+i)->candidat+j)->moyenne, sizeof(float), 1, fp);
        }
    }

    fclose(fp);
}
void enregistrer_centre(CENTRE c){
FILE *fp;
    fp = fopen("centre2", "wb+");

    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }


    fwrite(&c.ID, sizeof(int), 1, fp);
    fwrite(c.Nom, sizeof(char), 20, fp);
    fwrite(&c.nbr_Locales, sizeof(int), 1, fp);

    for (int i = 0; i < c.nbr_Locales; i++) {
        fwrite(&(c.locale+i)->id, sizeof(int), 1, fp);
        fwrite((c.locale+i)->nom, sizeof(char), 20, fp);
        fwrite((c.locale+i)->localisation, sizeof(char), 20, fp);
        fwrite(&(c.locale+i)->nbr_Formations, sizeof(int), 1, fp);

        for (int j = 0; j < (c.locale+i)->nbr_Formations; j++) {
            fwrite(((c.locale+i)->formation+j)->nom, sizeof(char), 20, fp);
            fwrite(&((c.locale+i)->formation+j)->prix, sizeof(float), 1, fp);
            fwrite(&((c.locale+i)->formation+j)->duree.heure, sizeof(int), 1, fp);
            fwrite(&((c.locale+i)->formation+j)->duree.minute, sizeof(int), 1, fp);
        }
    }

    fclose(fp);
    }
