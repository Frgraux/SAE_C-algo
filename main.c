#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fic "annuaire5000.csv"

// création de la struct csv
typedef struct csv
{
	char prenom[20], nom[20], ville[20], codep[20], tel[20], mail[20], metier[20];
} CSV;

int ouverture_attribution(CSV csv_tab[]);
CSV recherche_index(CSV csv_tab[], int index);
char tri_liste(CSV csv_tab[], int ligne);
int recherche_occu_vide(CSV csv_tab[], int ligne);
void affichage(CSV csv_tab[], int ligne);
void recherche(CSV csv_tab[],int ligne);

int main()
{
	// ------------------ouverture du fichier-------------------------
	CSV csv_tab[7000];
	int ligne = ouverture_attribution(csv_tab);
	int user_choice;
	// ------------------------------------------------------------------
	do
	{
		printf("-------------------------Bienvenue l'interface de votre annuaire-------------------------\n\n");
		printf("Menu : \n");
		printf("\tSaisir 1 si vous souhaiter afficher votre annuaire trié avec vos critaire\n");
		printf("\tSaisir 2 si vous voulez faire une recherche dans votre annuaire avec vos critaires\n");
		printf("\tSaisir 3 si vous voulez si vous voulez filtrer\n");
		printf("\tSaisir 4 si vous voulez faire des modification dans votre annuaire\n");
		printf("\tSaisir 5 si vous voulez afficher le nombre et la liste des personne avec des infos manquantes\n");
		printf("\tSaisir 6 si vous voulez quitter...");
		printf("\n\nVeuillez entrez votre choix : ");
		scanf("%d",&user_choice);
		switch (user_choice)
		{
		case 1:
			
			break;
		
		default:
			break;
		}
		
		


	} while (user_choice != 5);
	
	// recherche_occu_vide(csv_tab,ligne);
	

	return 0;
}
// ---------------fonction----------------
int ouverture_attribution(CSV csv_tab[])
{
	char tableau[250];
	int colone = 0;
	int j = 0;
	int ligne = 0;
	// CSV (*pt_annuaire)[]=&csv_tab;

	FILE *annuaire = fopen(fic, "r");

	if (annuaire == NULL)
	{
		printf("erreur de lecture");
		EXIT_FAILURE;
	}

	do
	{
		if (fgets(tableau, sizeof(tableau), annuaire))
		// reset tu nombre de colone
		{
			colone = 0;
			j = 0;
			for (int i = 0; tableau[i] != '\0'; i++)
			{
				if (tableau[i] == ',' | tableau[i] == '\n')
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
					j = 0;
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
		}
	} while (!feof(annuaire));
	

	return ligne;

	// recherche_occu_vide(csv_tab,ligne);
}

CSV recherche_index(CSV csv_tab[], int index)
// redigé par Graux François

{
	printf("[%s]\n", csv_tab[index].nom);
}

char tri_liste(CSV csv_tab[], int ligne)
// redigé par Graux François
{
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
}

void affichage(CSV csv_tab[], int ligne)
{
	printf("Information de la personne : %s / %s / %s / %s / %s / %s / %s \n",csv_tab[ligne].nom,csv_tab[ligne].prenom,csv_tab[ligne].ville,csv_tab[ligne].codep,csv_tab[ligne].tel,csv_tab[ligne].mail,csv_tab[ligne].metier);
}

int recherche_occu_vide(CSV csv_tab[], int ligne)
// rédiger par François Graux
// ligne = taille du tableau
{
	int j;
	int conteur;
	for (int i = 0; i < ligne; i++)
	{
		if (strlen(csv_tab[i].prenom) == 0 || strlen(csv_tab[i].nom) == 0 || strlen(csv_tab[i].ville) == 0 || strlen(csv_tab[i].codep) == 0 || strlen(csv_tab[i].tel) == 0 || strlen(csv_tab[i].mail) == 0 || strlen(csv_tab[i].metier) == 0)
		{
			affichage(csv_tab, i);
			conteur++;
		}
	}
	printf("\nil y a %d personne ou il manque des information", conteur);
}

void recherche(CSV csv_tab[],int ligne)
{
	tri_liste(csv_tab,ligne);
	int i=0;
	char type_rec[50];
	printf("Entrez ce que vous souhaiter rechercher : ");
	fgets(type_rec,sizeof(type_rec),stdin);
	type_rec[strlen(type_rec)-1] = '\0';

	while (i < ligne && strcasecmp(csv_tab[i].nom,type_rec)<=0)
	{
		if (strcasecmp(csv_tab[i].nom,type_rec)==0)
		{
			affichage(csv_tab,i);
		}
		i++;
	}
}

