#include<stdio.h>
#include<stdlib.h>
#define fic "annuaire5000.csv"

// création de la struct csv
typedef struct csv
{
    char prenom[20],nom[20],ville[20],codep[20],tel[20],mail[20],metier[20];
} CSV;



// main feature
int main()
{
    char tableau[250];
    int ligne = 0;
    int colone = 0;
    int j = 0;
    CSV csv_tab[7000];

    FILE * annuaire = fopen(fic,"r") ;
    // test de l'ouverture
    if (fic==NULL)
    {
        printf("erreur de lecture");
        EXIT_FAILURE;
    }
    // affichage du csv
    do
    {
        fgets(tableau,sizeof(tableau),annuaire);
        // reset tu nombre de colone
        colone=0;
        j=0;
        for(int i=0;tableau[i]!='\0';i++)
            {
               if (tableau[i]==','&& tableau[i]== '\n')
               {
                    switch (colone)
                   {
                   case 0:
                       csv_tab[ligne].prenom[j] = '\0';
                       break;
                    case 1:
                        csv_tab[ligne].nom[j] = '\0';
                        break;
                    case 2:
                        csv_tab[ligne].ville[j] = '\0';
                        break;
                    case 3:
                        csv_tab[ligne].codep[j] = '\0';
                        break;
                    case 4:
                        csv_tab[ligne].tel[j] = '\0';
                        break;
                    case 5:
                        csv_tab[ligne].mail[j] = '\0';
                         
                        break;
                    case 6:
                        csv_tab[ligne].metier[j] = '\0';

                        break;
                    }
                    j=0;
                    colone++;
               }

               else
               {
                    
                //    remplis les colones du tab de struct chaque case correpond au partie du strict
                   switch (colone)
                   {
                   case 0:
                       csv_tab[ligne].prenom[j] = tableau[i];
                       break;
                    case 1:
                        csv_tab[ligne].nom[j] = tableau[i];
                        break;
                    case 2:
                        csv_tab[ligne].ville[j] = tableau[i];
                        break;
                    case 3:
                        csv_tab[ligne].codep[j] = tableau[i];
                        break;
                    case 4:
                        csv_tab[ligne].tel[j] = tableau[i];
                        break;
                    case 5:
                        csv_tab[ligne].mail[j] = tableau[i];
                         
                        break;
                    case 6:
                        csv_tab[ligne].metier[j] = tableau[i];

                        break;
                   }
                    j++;
               }
                 
            }
        ligne++;
    } while (!feof(annuaire));
    printf("%s\n",csv_tab[2].nom);
        
    return 0;
}

// --------tri de la liste --------

