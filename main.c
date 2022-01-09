#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foo.h"
#define fic "annuaire5000.csv"


int main()
{
	// ------------------Variables-------------------------
	CSV csv_tab[7000];
	int ligne = ouverture_attribution(csv_tab);
	int user_choice;
	int indice[7000];
	int type_colone;
	int index_supr;
	char chaine[]="Ade";

	
	for (int i = 0; i < 7000; i++)
	{
		indice[i]=i;
	}
	// ---------------------------------------------------------
	
	// ---------------------------------------------appel--------------------------------------------------------
	do
	{
		printf("-------------------------Bienvenue l'interface de votre annuaire-------------------------\n\n");
		printf("Menu : \n");
		printf("\tSaisir 0 si vous souhaiter afficher votre annuaire trie avec vos critaire\n");
		printf("\tSaisir 1 si vous voulez faire une recherche dans votre annuaire avec vos critaires\n");
		printf("\tSaisir 2 si vous voulez filtrer\n");
		printf("\tSaisir 3 si vous voulez ajouter une personne a l'annuaire\n");
		printf("\tSaisir 4 si vous voulez supprimer une personne a l'annuaire\n");
		printf("\tSaisir 5 si vous voulez afficher le nombre et la liste des personne avec des infos manquantes\n");
		printf("\tSaisir 6 si vous voulez quitter...");
		printf("\n\nVeuillez entrez votre choix : ");
		scanf("%d",&user_choice);
	
		switch (user_choice)
		{
		case 0:
			printf("\tSi vous voulez trier par le prenom tapez 1\n");
			printf("\tSi vous voulez trier par le nom tapez 2\n");
			printf("\tSi vous voulez trier par le ville tapez 3\n");
			printf("\tSi vous voulez trier par le codep tapez 4\n");
			printf("\tSi vous voulez trier par le tel tapez 5\n");
			printf("\tSi vous voulez trier par le mail tapez 6\n");
			printf("\tSi vous voulez trier par le metier tapez 7\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			
			tri_liste_indirect(csv_tab,ligne,indice,type_colone-1);
			for (int i = 0; i < ligne; i++)
			{
				affichage(csv_tab,indice[i]);
			}
			break;
		case 1:
			printf("\tSi vous voulez rechercher par le nom tapez 0\n");
			printf("\tSi vous voulez rechercher par le prenom tapez 1\n");
			printf("\tSi vous voulez rechercher par le ville tapez 2\n");
			printf("\tSi vous voulez rechercher par le codep tapez 3\n");
			printf("\tSi vous voulez rechercher par le tel tapez 4\n");
			printf("\tSi vous voulez rechercher par le mail tapez 5\n");
			printf("\tSi vous voulez rechercher par le metier tapez 6\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			getchar();
			recherche(csv_tab,ligne,indice,type_colone);
			break;
		case 2:
			filtre(csv_tab,ligne,chaine,0,indice,4);
			break;
		case 3:
			getchar();
			ligne=ajout(csv_tab,ligne);
			affichage(csv_tab,indice[ligne-1]);
			printf("\nla personne a bien etait ajouter a l annuaire\n\n");
			break;
		case 4:
			printf("veuillez entrez une information pour trouver la personne que vous voulez supprimer\n\n");
			printf("\tSi vous voulez rechercher par le prenom taper 1\n");
			printf("\tSi vous voulez rechercher par le nom taper 2\n");
			printf("\tSi vous voulez rechercher par le ville taper 3\n");
			printf("\tSi vous voulez rechercher par le codep taper 4\n");
			printf("\tSi vous voulez rechercher par le tel taper 5\n");
			printf("\tSi vous voulez rechercher par le mail taper 6\n");
			printf("\tSi vous voulez rechercher par le metier taper 7\n\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			recherche(csv_tab,ligne,indice,type_colone);


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


void supretion(CSV csv_tab,int ligne,int index)
{
	printf("Entrez la ligne qui correspond a votre choix de supresion : ");
	// scanf("%d",&);
}