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

int main()
{
	CSV csv_tab[7000];
	int ligne = ouverture_attribution(csv_tab);

	for (int i = 0; i < ligne; i++)
		affichage(csv_tab, i);
	

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
		fgets(tableau, sizeof(tableau), annuaire);
		// reset tu nombre de colone
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
	printf("%d / Nom et Prenom de la personne : %s-%s\n", ligne + 1, csv_tab[ligne].nom, csv_tab[ligne].prenom);
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
			printf("Il manque des informations  : ", i);
			affichage(csv_tab, i);
			conteur++;
		}
	}
	printf("\nil y a %d personne ou il manque des information", conteur);
}