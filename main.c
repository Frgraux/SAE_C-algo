#include<stdio.h>
#include<stdlib.h>
#define fic "annuaire5000.csv"

// création de la struct csv
typedef struct csv
{
    char prenom[20],nom[20],ville[20],codep[20],tel[20],mail[20],metier[20]
} CSV;


// main feature
int main()
{
    char tableau[250];
    int ligne = 0;
    int colone = 0;
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
        // printf("%s",tableau);
        for(int i=0;tableau[i]!='\0';i++)
            {
               if (tableau[i]==',')
               {
                   printf("\n");
               }

               else
               {
                    printf("%c",tableau[i]);
               }
                 
            }
        ligne++;
    } while (!feof(annuaire));
    printf("%d\n",ligne);
        
    return 0;
}

// --------tri de la liste --------



