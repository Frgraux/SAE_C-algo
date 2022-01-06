#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fic "annuaire5000.csv"
const int espace[] = { 25,25,25,10,20,45,20 };

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
char tri_liste_indirect(CSV csv_tab[],int ligne,int tab[],int rang);
char* champ(CSV *personne,int rang);
int ajout(CSV csv_tab[],int ligne);

int main()
{
	// ------------------ouverture du fichier-------------------------
	CSV csv_tab[7000];
	int ligne = ouverture_attribution(csv_tab);
	int user_choice;
	int indice[7000];
	int type_colone;
	int index_supr;
	
	
	
	for (int i = 0; i < 7000; i++)
	{
		indice[i]=i;
	}
	
	// recherche(csv_tab,ligne);
	
	// -----------------------------------------------------------------------------------------------------------
	do
	{
		printf("-------------------------Bienvenue l'interface de votre annuaire-------------------------\n\n");
		printf("Menu : \n");
		printf("\tSaisir 0 si vous souhaiter afficher votre annuaire trié avec vos critaire\n");
		printf("\tSaisir 1 si vous voulez faire une recherche dans votre annuaire avec vos critaires\n");
		printf("\tSaisir 2 si vous voulez filtrer\n");
		printf("\tSaisir 3 si vous voulez ajouter une personne à l'annuaire\n");
		printf("\tSaisir 4 si vous voulez supprimer une personne à l'annuaire\n");
		printf("\tSaisir 5 si vous voulez afficher le nombre et la liste des personne avec des infos manquantes\n");
		printf("\tSaisir 6 si vous voulez quitter...");
		printf("\n\nVeuillez entrez votre choix : ");
		scanf("%d",&user_choice);
	
		switch (user_choice)
		{
		case 0:
			printf("\tSi vous voulez trier par le prenom taper 0\n");
			printf("\tSi vous voulez trier par le nom taper 1\n");
			printf("\tSi vous voulez trier par le ville taper 2\n");
			printf("\tSi vous voulez trier par le codep taper 3\n");
			printf("\tSi vous voulez trier par le tel taper 4\n");
			printf("\tSi vous voulez trier par le mail taper 5\n");
			printf("\tSi vous voulez trier par le metier taper 6\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			
			tri_liste_indirect(csv_tab,ligne,indice,type_colone);
			for (int i = 0; i < ligne; i++)
			{
				affichage(csv_tab,indice[i]);
			}
			break;
		case 1:
			// printf("\tSi vous voulez rechercher par le prenom taper 0\n");
			// printf("\tSi vous voulez rechercher par le nom taper 1\n");
			// printf("\tSi vous voulez rechercher par le ville taper 2\n");
			// printf("\tSi vous voulez rechercher par le codep taper 3\n");
			// printf("\tSi vous voulez rechercher par le tel taper 4\n");
			// printf("\tSi vous voulez rechercher par le mail taper 5\n");
			// printf("\tSi vous voulez rechercher par le metier taper 6\n");
			// printf("Entrez votre choix : ");
			// scanf("%d",&type_colone);
			getchar();
			recherche(csv_tab,ligne);
			break;
		case 2:
				
			break;
		case 3:
			getchar();
			ligne=ajout(csv_tab,ligne);
			affichage(csv_tab,indice[ligne-1]);
			printf("\nla personne a bien etait ajouter a l annuaire\n\n");
			break;
		case 4:
			
			break;
		case 5:
			recherche_occu_vide(csv_tab,ligne);
			break;

		default:
			break;
		}
	} while (user_choice != 6);
	
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

char tri_liste_indirect(CSV csv_tab[],int ligne,int indice[],int rang)
{
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
	
}

void affichage(CSV csv_tab[], int ligne)
{
	printf("Information de la personne : %*s | %*s | %*s | %*s | %*s | %*s | %*s |\n",espace[0],csv_tab[ligne].nom,espace[1],csv_tab[ligne].prenom,espace[2],csv_tab[ligne].ville,espace[3],csv_tab[ligne].codep,espace[4],csv_tab[ligne].tel,espace[5],csv_tab[ligne].mail,espace[6],csv_tab[ligne].metier);
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
	printf("\nil y a %d personne ou il manque des information\n", conteur);
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

char* champ(CSV *personne,int rang)
{
	switch (rang)
	{
	case 0:
		return (*personne).prenom;
	case 1:
		return (*personne).nom;
	case 2:
		return (*personne).ville;
	case 3:
		return (*personne).codep;
	case 4:
		return (*personne).tel;
	case 5:
		return (*personne).mail;
	case 6:
		return (*personne).metier;
	}
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

	// faire une boucle qui incremente pour faire moins de lignes
}

void supretion(CSV csv_tab,int ligne,int index)
{
	printf("Entrez la ligne qui correspond a votre choix de supresion : ");// scanf("%d",&);
}