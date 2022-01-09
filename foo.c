#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foo.h"
#define fic "annuaire5000.csv"

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
	printf("Personne : %4d | %*s | %*s | %*s | %*s | %*s | %*s | %*s |\n",ligne,espace[0],csv_tab[ligne].nom,espace[1],csv_tab[ligne].prenom,espace[2],csv_tab[ligne].ville,espace[3],csv_tab[ligne].codep,espace[4],csv_tab[ligne].tel,espace[5],csv_tab[ligne].mail,espace[6],csv_tab[ligne].metier);
}

CSV recherche_index(CSV csv_tab[], int index)
{
	// redigé par Graux François
	// """
	// Entre csv_tab :tableau de structure ,index : int
	// sortie csv_tab[index]
	// post condition:
	// pemret de faire une recherche dans l'annuaire avec sont index et revoie la ligne correspondante
	// """
	printf("[%s]\n", csv_tab[index].nom);
}

char tri_liste(CSV csv_tab[], int ligne)
{
	// redigé par Graux François
	// """
	// Entre ligne :int
	// Entre/sortie csv_tab: tableau de structure 
	// declaration :
	// i,j :int
	// ppt :CSV
	// post condition :
	// permet de trié le tableau de structure de manière alphabétique par rapport au nom
	// """
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
	// rédiger par François Graux
	// """
	// entre ligne :int (nombre de ligne de csv_tab) , indice :tableau de int ,rang :int
	// entre/sortie csv_tab: tableau de structure char
	// declaration:
	// int i,j,petit
	// post condition:
	// Permet de trié le tableau de structure de maniere alphabetique de plusieur maniere en fonction des besoin de l'utilisateur
	// """
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

void recherche(CSV csv_tab[],int ligne,int indice[],int rang)
{
	// rédiger par François Graux
	// """
	// Entre csv_tab:tableau de structure char ,ligne:int , indice : tableau de int (indice pour le tri indirect) , rang : int
	//declaration:
	// char type_rec[]
	//int i
	// post condition:
	// Permet d'effectuer une recherche dans toute le tableau sur un element entrer en argument par l'utilisateur et le type d'element et choisi par l'utilisateur
	// """
	tri_liste_indirect(csv_tab,ligne,indice,rang);
	int i=0;
	char type_rec[50];
	printf("Entrez ce que vous souhaiter rechercher : ");
	fgets(type_rec,sizeof(type_rec),stdin);
	type_rec[strlen(type_rec)-1] = '\0';

	while (i < ligne && strcasecmp(champ(&csv_tab[indice[i]],rang),type_rec)<=0)
	{
		if (strcasecmp(champ(&csv_tab[indice[i]],rang),type_rec)==0)
		{
			affichage(csv_tab,indice[i]);
		}
		i++;
	}
}

int recherche_occu_vide(CSV csv_tab[], int ligne)
{
	// rédiger par François Graux
	// """
	// Entre csv_tab : tableau de structure char , ligne :int (nombre de ligne de csv_tab)
	// sorti csv_tab
	// declaration;
	// int j,contenuer
	// post condition:
	// Permet d'afficher les informations ainsi que le nommbre des lignes ou il manque des inforamtion dans la tableau de structure 
	// """
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

int ouverture_attribution(CSV csv_tab[])
{
	// redigé par Graux François
	// """
	// Entre csv_tab : tableau de structure
	// sortie ligne :int
	// declaration:
	// tableau :char
	// colone,ligne,j : int
	// post condition:
	// Permet de remplir le tableau de structure à partir du CSV en utilisant ma fonction champ pour remplir les bonnes informations
	// """
	char tableau[250];
	int colone = 0;
	int j = 0;
	int ligne = 0;

	FILE *annuaire = fopen(fic, "r");

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
	// rédiger par François Graux
	// """
	// Entre char, ligne :int (nombre de ligne de csv_tab)
	// entre /sortie csv_tab:tableau de structure,ligne :int
	// postcondition:
	// 	Permet d'ajouter une nouvelle personne à l'annuaire ainsi que de retouner le nombre de ligne + 1 et remplace les \n par des \0
	// """
	
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
	// rédiger par François Graux
	// """
	// Entre csv_tav :char tableau de structure char,Ligne:int du nb de ligne de la strcuture,rang :int, indice:tableau de int ,type_filtre:int
	// declaration:
	// int i
	//post condition:
	//Permet de trouver si une chaine de caratere ou une sous chaine de caractere ce trouve dans le tableau de strucre a une ligne donné
	// """
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
	
}