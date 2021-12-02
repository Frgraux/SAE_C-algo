#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define fic "annuaire5000.csv"

// création de la struct csv
typedef struct csv
{
    char prenom[20],nom[20],ville[20],codep[20],tel[20],mail[20],metier[20];
} CSV;

CSV recherche_index(CSV (*blop)[],int index);
char tri_liste(CSV(*blop)[],int ligne);
int recherche_occu_vide(CSV(*tab)[],int ligne,int colone);
void affichage(CSV(*tab)[],int ligne);

// main feature
int main()
{

    // char a[30] = "Salut ca va !";
    // char (*b)[] = &a;

    // printf("%s\n",a);
    // printf("%d", b);

    // (*b)[3] = 'c';
    // printf("%d\n", b);

    // printf("%s\n",a);
    // printf("%d", b);

    char tableau[250];
    int ligne = 0;
    int colone = 0;
    int j = 0;
    CSV csv_tab[7000];
    CSV (*pt_annuaire)[]=&csv_tab;

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
               if (tableau[i]==','| tableau[i]== '\n')
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
    // printf("%s\n",csv_tab[2].nom);

    // tri_liste(pt_annuaire,ligne);
    
    // for (int i = 0; i < 5000; i++)
    // {
    //     recherche_index(pt_annuaire,i);
    // }

    recherche_occu_vide(pt_annuaire,ligne,colone);
    
    return 0;
}
// ---------------fonction----------------
CSV recherche_index(CSV (*tab)[],int index)
// redigé par Graux François 

{
    printf("[%s]\n",(*tab)[index].nom);
}

char tri_liste(CSV(*tab)[],int ligne)
// redigé par Graux François
{
    int j;
    int i;
    CSV ppt;
    i=1;
    while (i < ligne)
    {
        ppt = (*tab)[i];
        j=i-1;
        while (j>=0 && strcasecmp(ppt.nom,(*tab)[j].nom)<0)
        {
            (*tab)[j+1]=(*tab)[j];
            j=j-1;
        }
        (*tab)[j+1]=ppt;
        i=i+1;
        
    }
}

void affichage(CSV(*tab)[],int ligne)
{
    for(int i=0;i<ligne;i++)
    {
        printf("index : %d) %s\n",i,(*tab)[i].prenom);
    }
}

int recherche_occu_vide(CSV(*tab)[],int ligne,int colone)
// rédiger par François Graux
{
    int j;
    int conteur;
    for (int i = 0; i < ligne; i++)
    {
        j=0;
        while (j<colone)
        {
          switch(j)
            {
            case 1:
                 if(strlen((*tab)[i].prenom)==0)
                {
                    affichage(tab,i);
                }
                conteur++;
                break;
            case 2:
                 if(strlen((*tab)[i].nom)==0)
                {
                    affichage(tab,i);
                }
                conteur++;
                break;
            case 3:
                 if(strlen((*tab)[i].ville)==0)
                {
                    affichage(tab,i);
                }
                conteur++; 
                break;
            case 4:
                 if(strlen((*tab)[i].codep)==0)
                {
                    affichage(tab,i);
                }
                conteur++;  
                break;
            case 5:
                 if(strlen((*tab)[i].tel)==0)
                {
                    affichage(tab,i);
                }
                conteur++; 
                break;
            case 6:
                 if(strlen((*tab)[i].mail)==0)
                {
                    affichage(tab,i);
                }
                conteur++;  
                break;
            case 7:
                 if(strlen((*tab)[i].metier)==0)
                {
                    affichage(tab,i);
                }
                conteur++;  
                break;
            
            default:
                printf("une erreur c'est produite");
                break;  
            }
        j++;

        }
        
    }
    printf("\nil y a %d personne ou il manque des info",conteur);
}