#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
struct date
 {
 int jour;
 int mois;
 int annee;
};
 typedef struct date DATE;
 struct temps
 {
 int heure;
 int minute;
 };

 typedef struct temps TEMPS;
 struct formation
 {
 char nom[20];
 int prix;
 TEMPS duree;
 };

 typedef struct formation FORMATION ;
 struct locale
 {
 int id ;
 char nom[20];
char localisation[20];
 int nbr_Formations;
 FORMATION* formation;
 }  ;
 typedef struct locale LOCALE;
 struct centre
 {
     int ID;
 char Nom[20];
 int nbr_Locales;
 LOCALE* locale;
 };

 typedef struct centre CENTRE;
 struct candidat
 {
    int code ;
 char nom[20];
 char prenom[20];
 DATE date_Naissance;
 float moyenne;
 };

 typedef struct candidat CANDIDAT;
struct seance
 {
 DATE date_seance;
 TEMPS temps;
 float prix_seance;
 int nbr_candidat;
 CANDIDAT* candidat;
 };

 typedef struct seance SEANCE;
 struct formateur
 {
 int ident ;
 char nom[20];
 char prenom[20];
 DATE date_Naissance;
 FORMATION formation;
 int nbr_seance;
 SEANCE* seance;
 };
typedef struct formateur FORMATEUR;
struct resultat
 {
 int ce;
 float moy;
 };
typedef struct resultat RESULTAT;
FORMATION afficher_formation_plus_couteuse(CENTRE );
CANDIDAT afficher_candidat_meilleure_moyenne(FORMATEUR  );
void afficher_locales_donnee(CENTRE ,int );
void afficher_formations_locale(CENTRE ,int );
float calculer_revenu_formateur(FORMATEUR );
int calculer_nombre_formations(CENTRE );
CANDIDAT afficher_plus_petit_candidat(FORMATEUR );
CANDIDAT afficher_plus_grand_candidat(FORMATEUR );
CENTRE saisie_centre();
void affichage_centre(CENTRE );
FORMATEUR saisie_formateur( );
void affichage_formateur(FORMATEUR);
void menu_affichage(CENTRE ,FORMATEUR );
void affichage_formation(FORMATION );
void menu_traitements(CENTRE ,FORMATEUR );
FORMATION saisie_formation();
void ajouter_formation(CENTRE* , int , FORMATION );
void supprimer_formation(CENTRE* , int , const char* );
void menu_gestion_centre(CENTRE,FORMATEUR );
void ajouter_candidat_a_seance(FORMATEUR* , int , CANDIDAT );
CANDIDAT saisie_candidat();
void supprimer_candidat(FORMATEUR* , int , int );
void menu_gestion_formateur(CENTRE,FORMATEUR );
void menu_principale(CENTRE ,FORMATEUR );
void resultat(FORMATEUR );
void charger_centre( CENTRE* );
void charger_formateur(FORMATEUR* );
void enregistrer_formateur(FORMATEUR );
void enregistrer_centre(CENTRE );
void resultat(FORMATEUR F);
#endif
