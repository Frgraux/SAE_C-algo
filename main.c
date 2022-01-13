#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "foo.h"


int main()
{
	// ------------------Variables-------------------------
	CSV csv_tab[7000];
	int ligne = ouverture_attribution(csv_tab);
	int user_choice;
	int indice[7000];
	int type_colone;
	int index_supr;
	int type_filtre;
	char chaine[25];

	
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
		printf("\tSaisir 0 si vous souhaiter afficher votre annuaire dans la totaliteS\n");
		printf("\tSaisir 1 si vous souhaiter afficher votre annuaire trie avec vos critaire\n");
		printf("\tSaisir 2 si vous voulez faire une recherche dans votre annuaire avec vos critaires\n");
		printf("\tSaisir 3 si vous voulez filtrer\n");
		printf("\tSaisir 4 si vous voulez ajouter une personne a l'annuaire\n");
		printf("\tSaisir 5 si vous voulez supprimer une personne a l'annuaire\n");
		printf("\tSaisir 6 si vous voulez afficher le nombre et la liste des personne avec des infos manquantes\n");
		printf("\tSaisir 7 si vous voulez modifez les infos d'une personne\n");
		printf("\tSaisir 8 si vous voulez faire une sauvgarde de votre annuaire dans un autre fichier\n");
		printf("\tSaisir 9 si vous voulez quitter...");
		printf("\n\nVeuillez entrez votre choix : ");
		scanf("%d",&user_choice);
	
		switch (user_choice)
		{
		case 0:
			for (int i = 0; i < ligne; i++)
			{
				affichage(csv_tab,i);
			}

			break;
		case 1:
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
		case 2:
			printf("\tSi vous voulez rechercher par le prenom tapez 0\n");
			printf("\tSi vous voulez rechercher par le nom tapez 1\n");
			printf("\tSi vous voulez rechercher par le ville tapez 2\n");
			printf("\tSi vous voulez rechercher par le codep tapez 3\n");
			printf("\tSi vous voulez rechercher par le tel tapez 4\n");
			printf("\tSi vous voulez rechercher par le mail tapez 5\n");
			printf("\tSi vous voulez rechercher par le metier tapez 6\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			fflush(stdin);
			recherche(csv_tab,ligne,indice,type_colone);
			break;
		case 3:
			printf("\tSi vous voulez filtrer par le prenom tapez 0\n");
			printf("\tSi vous voulez filtrer par le nom tapez 1\n");
			printf("\tSi vous voulez filtrer par le ville tapez 2\n");
			printf("\tSi vous voulez filtrer par le codep tapez 3\n");
			printf("\tSi vous voulez filtrer par le tel tapez 4\n");
			printf("\tSi vous voulez filtrer par le mail tapez 5\n");
			printf("\tSi vous voulez filtrer par le metier tapez 6\n");
			printf("entrez votre choix : \n");
			scanf("%d",&type_colone);
			fflush(stdin);
			printf("\tRecherche Identique dans votre annuaire tapez 1 \n");
			printf("\tRecherche ce trouvant dans le mot de l annuaire tapez 2\n");
			printf("\tRecherche au fin du mots de l annuaire tapez 3\n");
			printf("\tRecherche a la debut du mots de l annuaire tapez 4\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_filtre);
			fflush(stdin);
			printf("Entrez votre element a rechercher/filtrer : ");
			scanf("%s",&chaine);
			fflush(stdin);
			filtre(csv_tab,ligne,chaine,type_colone,indice,type_filtre);
			break;
		case 4:
			fflush(stdin);
			ligne=ajout(csv_tab,ligne);
			affichage(csv_tab,indice[ligne-1]);
			printf("\nla personne a bien etait ajouter a l annuaire\n\n");
			break;
		case 5:
			printf("veuillez entrez une information pour trouver la personne que vous voulez supprimer\n\n");
			printf("\tSi vous voulez rechercher par le prenom taper 0\n");
			printf("\tSi vous voulez rechercher par le nom taper 1\n");
			printf("\tSi vous voulez rechercher par le ville taper 2\n");
			printf("\tSi vous voulez rechercher par le codep taper 3\n");
			printf("\tSi vous voulez rechercher par le tel taper 4\n");
			printf("\tSi vous voulez rechercher par le mail taper 5\n");
			printf("\tSi vous voulez rechercher par le metier taper 7\n\n");
			printf("Entrez votre choix : ");
			scanf("%d",&type_colone);
			fflush(stdin);
			recherche(csv_tab,ligne,indice,type_colone);
			suppression(csv_tab,&ligne);
			break;
		case 6:
			recherche_occu_vide(csv_tab,ligne);
			break;
		case 7:
			maj(csv_tab);
			break;
		case 8:
			ecriture(csv_tab,ligne);
			break;
		default:
			break;
		}
	} while (user_choice != 9);
	
	return 0;
}