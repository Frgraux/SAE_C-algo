#ifndef ACTIONS_H
#define ACTIONS_H
#define fic "annuaire5000.csv"


typedef struct csv
{
	char prenom[20], nom[20], ville[20], codep[20], tel[20], mail[20], metier[20];
} CSV;

char* champ(CSV *personne,int rang);
/**rédiger par François Graux
	Entre csv_tab :tableau de stucture char , ligne int (nombre de ligne de csv_tab)
	post condition:
	 permet l'affichage des lignes en fonction de nos besoins
*/
void affichage(CSV csv_tab[], int ligne);
CSV recherche_index(CSV csv_tab[], int index);
char tri_liste(CSV csv_tab[], int ligne);
char tri_liste_indirect(CSV csv_tab[],int ligne,int indice[],int rang);
void recherche(CSV csv_tab[],int ligne,int indice[],int rang);
int recherche_occu_vide(CSV csv_tab[], int ligne);
int ouverture_attribution(CSV csv_tab[]);
int ajout(CSV csv_tab[],int ligne);
void filtre(CSV csv_tab[],int ligne,char chaine[],int rang,int indice[],int type_filtre);
#endif







