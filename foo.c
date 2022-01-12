#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "foo.h"
#define save "sauvgarde.csv"

const int espace[] = { 20,20,20,15,20,45,20 };



char* champ(CSV *personne,int rang)
{
    switch (rang)
    {
    case 0:
        return (*personne).prenom;
        break;
    case 1:
        return (*personne).nom;
        break;
    case 2:
        return (*personne).ville;
        break;
    case 3:
        return (*personne).codep;
        break;
    case 4:
        return (*personne).tel;
        break;
    case 5:
        return (*personne).mail;
        break;
    case 6:
        return (*personne).metier;
        break;
    }
}

void affichage(CSV csv_tab[], int ligne)
{
	printf("Personne : %4d | %*s | %*s | %*s | %*s | %*s | %*s | %*s |\n",ligne+1,espace[0],csv_tab[ligne].prenom,espace[1],csv_tab[ligne].nom,espace[2],csv_tab[ligne].ville,espace[3],csv_tab[ligne].codep,espace[4],csv_tab[ligne].tel,espace[5],csv_tab[ligne].mail,espace[6],csv_tab[ligne].metier);
}

CSV recherche_index(CSV csv_tab[], int index)
{
	clock_t begin=clock();
	printf("[%s]\n", csv_tab[index].nom);
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
	system("pause");
}

char tri_liste(CSV csv_tab[], int ligne)
{
	clock_t begin=clock();
	int j;
	int i;
	CSV ppt;
	i = 1;
	while (i < ligne)
	{
		ppt = csv_tab[i];
		j = i - 1;
		while (j >= 0 && strcasecmp(ppt.nom, csv_tab[j].nom) < 0)
		{
			csv_tab[j + 1] = csv_tab[j];
			j = j - 1;
		}
		csv_tab[j + 1] = ppt;
		i = i + 1;
	}
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
	system("pause");
}

char tri_liste_indirect(CSV csv_tab[],int ligne,int indice[],int rang)
{
	clock_t begin=clock();
	int i=1;
	int j;
	int petit;
	while (i<ligne)
	{
		petit = indice[i];
		j=i-1;
		while (j >= 0 && strcasecmp(champ(&csv_tab[petit],rang), champ(&csv_tab[indice[j]],rang))<0)
		{
			indice[j+1] = indice[j];
			j=j-1;
		}
		indice[j+1] = petit;
		i=i+1;
	}
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
	system("pause");
}

void recherche(CSV csv_tab[],int ligne,int indice[],int rang)
{
	
	tri_liste_indirect(csv_tab,ligne,indice,rang);
	int i=0;
	char type_rec[50];
	printf("Entrez ce que vous souhaiter rechercher : ");
	fgets(type_rec,sizeof(type_rec),stdin);
	clock_t begin=clock();
	type_rec[strlen(type_rec)-1] = '\0';

	while (i < ligne && strcasecmp(champ(&csv_tab[indice[i]],rang),type_rec)<=0)
	{
		if (strcasecmp(champ(&csv_tab[indice[i]],rang),type_rec)==0)
		{
			affichage(csv_tab,indice[i]);
		}
		i++;
	}
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
}

int recherche_occu_vide(CSV csv_tab[], int ligne)
{
	clock_t begin=clock();
	int j;
	int conteur = 0;
	for (int i = 0; i < ligne; i++)
	{
		if (strlen(csv_tab[i].prenom) == 0 || strlen(csv_tab[i].nom) == 0 || strlen(csv_tab[i].ville) == 0 || strlen(csv_tab[i].codep) == 0 || strlen(csv_tab[i].tel) == 0 || strlen(csv_tab[i].mail) == 0 || strlen(csv_tab[i].metier) == 0)
		{
			affichage(csv_tab, i);
			conteur++;
		}
	}
	printf("\nil y a %d personne ou il manque des information\n", conteur);
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
	system("pause");
}

int ouverture_attribution(CSV csv_tab[])
{
	char fichier[25];
	printf("Entrez le nom du fichier a manipuler : ");
	scanf("%s",&fichier);
	char tableau[250];
	int colone = 0;
	int j = 0;
	int ligne = 0;

	FILE *annuaire = fopen(fichier, "r");

	if (annuaire == NULL)
	{
		printf("erreur de lecture");
		EXIT_FAILURE;
	}

	do
	{
		if (fgets(tableau, sizeof(tableau), annuaire))
		{
			colone = 0;
			j = 0;
			for (int i = 0; tableau[i] != '\0'; i++)
			{
				if (tableau[i] == ',' | tableau[i] == '\n')
				{
					champ(&csv_tab[ligne],colone)[j]='\0';
					j = 0;
					colone++;
				}

				else
				{
					champ(&csv_tab[ligne],colone)[j]=tableau[i];
					j++;
				}
			}
			ligne++;
		}
	} while (!feof(annuaire));

	return ligne;
}

int ajout(CSV csv_tab[],int ligne)
{	
	printf("Veuillez entrer le prenom de la personne : ");
	fgets(champ(&csv_tab[ligne],0),50,stdin);
	if (champ(&csv_tab[ligne],0)[strlen(champ(&csv_tab[ligne],0))-1]=='\n')
	{
		champ(&csv_tab[ligne],0)[strlen(champ(&csv_tab[ligne],0))-1]='\0';
	}
	printf("Veuillez entrez le nom de la personne : ");
	fgets(champ(&csv_tab[ligne],1),50,stdin);
	if (champ(&csv_tab[ligne],1)[strlen(champ(&csv_tab[ligne],1))-1]=='\n')
	{
		champ(&csv_tab[ligne],1)[strlen(champ(&csv_tab[ligne],1))-1]='\0';
	}
	printf("Veuillez entrez la ville de la personne : ");
	fgets(champ(&csv_tab[ligne],2),50,stdin);
	if (champ(&csv_tab[ligne],2)[strlen(champ(&csv_tab[ligne],2))-1]=='\n')
	{
		champ(&csv_tab[ligne],2)[strlen(champ(&csv_tab[ligne],2))-1]='\0';
	}
	printf("Veuillez entrez le code posatle de la personne : ");
	fgets(champ(&csv_tab[ligne],3),50,stdin);
	if (champ(&csv_tab[ligne],3)[strlen(champ(&csv_tab[ligne],3))-1]=='\n')
	{
		champ(&csv_tab[ligne],3)[strlen(champ(&csv_tab[ligne],3))-1]='\0';
	}
	printf("Veuillez entrez le tel de la personne : ");
	fgets(champ(&csv_tab[ligne],4),50,stdin);
	if (champ(&csv_tab[ligne],4)[strlen(champ(&csv_tab[ligne],4))-1]=='\n')
	{
		champ(&csv_tab[ligne],4)[strlen(champ(&csv_tab[ligne],4))-1]='\0';
	}
	printf("Veuillez entrez la mail de la personne : ");
	fgets(champ(&csv_tab[ligne],5),50,stdin);
	if (champ(&csv_tab[ligne],5)[strlen(champ(&csv_tab[ligne],5))-1]=='\n')
	{
		champ(&csv_tab[ligne],5)[strlen(champ(&csv_tab[ligne],5))-1]='\0';
	}
	printf("Veuillez entrez la metier de la personne : ");
	fgets(champ(&csv_tab[ligne],6),50,stdin);
	if (champ(&csv_tab[ligne],6)[strlen(champ(&csv_tab[ligne],6))-1]=='\n')
	{
		champ(&csv_tab[ligne],6)[strlen(champ(&csv_tab[ligne],6))-1]='\0';
	}
	return ligne+1;
}

void filtre(CSV csv_tab[],int ligne,char chaine[],int rang,int indice[],int type_filtre)
{
	clock_t begin=clock();
	int i;
	for (i=0; i < ligne; i++)
	{
		if (type_filtre==1 && strcasecmp(champ(&csv_tab[indice[i]],rang),chaine)==0)
		{
			affichage(csv_tab,indice[i]);
		}
		else if (type_filtre==2 &&strstr(champ(&csv_tab[indice[i]],rang),chaine)!=NULL)
		{
			affichage(csv_tab,indice[i]);
		}
		else if (type_filtre==3 && strcasecmp(chaine,&champ(&csv_tab[indice[i]],rang)[strlen(champ(&csv_tab[indice[i]],rang))-strlen(chaine)])==0)
		{
			affichage(csv_tab,indice[i]);
		}
		else if (type_filtre==4 && strncmp(chaine,champ(&csv_tab[indice[i]],rang),strlen(chaine))==0)
		{
			affichage(csv_tab,indice[i]);
		}
		
	}
	clock_t end=clock();
	unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
	system("pause");
}

int ecriture(CSV csv_tab[],int ligne)
{
    int colone = 0;
    FILE *fichier=fopen(save,"w");
   for (int i = 0; i < ligne; i++)
   {
       for (colone = 0 ; colone < 6; colone++)
       {
           fprintf(fichier,"%s,",champ(&csv_tab[i],colone));
       }
       fprintf(fichier,"%s\n",champ(&csv_tab[i],colone));
   }
}

void suppression(CSV csv_tab[],int *ligne)
{
	int index;
	printf("Entrez la ligne qui correspond a votre choix de supresion : ");
	scanf("%d",&index);
	csv_tab[index-1]=csv_tab[*ligne-1];
	*ligne=*ligne-1;
}

void maj(CSV csv_tab[])
{
	int choix_colone;
	int choix_index;
	printf("Entrez l'indice de la personne que vous voulez modifier\n");
	scanf("%d",&choix_index);
	printf("\tEntrez 0 si vous voulez modifier le prenom\n");
	printf("\tEntrez 1 si vous voulez modifier le nom\n");
	printf("\tEntrez 2 si vous voulez modifier le ville\n");
	printf("\tEntrez 3 si vous voulez modifier le codep\n");
	printf("\tEntrez 4 si vous voulez modifier le tel\n");
	printf("\tEntrez 5 si vous voulez modifier le mail\n");
	printf("\tEntrez 6 si vous voulez modifier le metier\n");
	printf("Entrez votre choix : \n");
	scanf("%d",&choix_colone);
	fflush(stdin);
	printf("Entrez la modication : ");
	fgets(champ(&csv_tab[choix_index-1],choix_colone),50,stdin);
	if (champ(&csv_tab[choix_index],choix_colone)[strlen(champ(&csv_tab[choix_index],choix_colone))-1]=='\n')
	{
		champ(&csv_tab[choix_index],choix_colone)[strlen(champ(&csv_tab[choix_index],choix_colone))-1]='\0';
	}
	printf("la ligne a bien ete modifier\n");
	
}
