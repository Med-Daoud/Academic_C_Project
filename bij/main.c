#include <stdio.h>
#include <stdlib.h>
#include "fonc.h"
#include <string.h>

int main()
{
   FORMATEUR  F;
 CENTRE c;
      while(1){

     int n,choix;
     char ch[20];
       printf("\n\t\t\t\t\t--------------MENU---------------------\n");
     printf("\n\t\t\t\t\ttapez :\n \t\t\t\t\t-1 pour SAISIR MANUELLEMENT\n\t\t\t\t\t-2 pour REMPLIRE A PARTIR DE FICHIER\n saisie votre choix:\n ");
     scanf("%d",&choix);
     if(choix==1)
     {
             printf("\n\t\t\t\tSAISIE MANUEL\n");
             printf("\nCENTRE ::\n");
             c=saisie_centre();
              printf("\nFORMATEUR ::\n");
             F=saisie_formateur();
             menu_principale(c ,F );


         break;
     }
      if(choix==2)
     {

         charger_centre(&c );
         charger_formateur(&F );
         menu_principale(c ,F );

         break;
     }
    }
}





