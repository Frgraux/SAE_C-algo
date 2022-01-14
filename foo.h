#ifndef ACTIONS_H
#define ACTIONS_H


typedef struct csv
{
	char prenom[20], nom[20], ville[20], codep[20], tel[20], mail[20], metier[20];
} CSV;
/**
 * entre/sortie personne : pointeur de type CSV
 * entre rang :int
 * post condition:
 * Permet de renvoyer l'adresse d'une colone du tableau de structure en fonction des choix de l'utilisateur
 * 
*/
char* champ(CSV *personne,int rang);
/**rédiger par François Graux
	Entrée csv_tab :tableau de stucture char , ligne int (nombre de ligne de csv_tab)
	post condition:
	permet l'affichage des lignes en fonction de nos besoins
*/
void affichage(CSV csv_tab[], int ligne);
/**redigé par Graux François
	
	Entrée csv_tab :tableau de structure ,index : int
	sortie csv_tab[index]
	post condition:
	pemret de faire une recherche dans l'annuaire avec sont index et revoie la ligne correspondante
*/
CSV recherche_index(CSV csv_tab[], int index);
/** redigé par Graux François
	// Entrée ligne :int
	// Entrée/sortie csv_tab: tableau de structure 
	// declaration :
	// i,j :int
	// ppt :CSV
	// post condition :
	// permet de trié le tableau de structure de manière alphabétique par rapport au nom
*/
char tri_liste(CSV csv_tab[], int ligne);
/** rédiger par François Graux
	entrée ligne :int (nombre de ligne de csv_tab) , indice :tableau de int ,rang :int
	entrée/sortie csv_tab: tableau de structure char
	declaration:
	i,j,petit : int
	post condition:
	Permet de trié le tableau de structure de maniere alphabetique de plusieur maniere en fonction des besoin de l'utilisateur
*/
char tri_liste_indirect(CSV csv_tab[],int ligne,int indice[],int rang);
/** rédiger par François Graux
	
	Entrée csv_tab:tableau de structure char ,ligne:int , indice : tableau de int (indice pour le tri indirect) , rang : int
	declaration:
	type_rec : tableau de char 
	i : int
	post condition:
	Permet d'effectuer une recherche dans toute le tableau sur un element entrer en argument par l'utilisateur et le type d'element et choisi par l'utilisateur
*/
void recherche(CSV csv_tab[],int ligne,int indice[],int rang);
/** rédiger par François Graux
	
	Entrée csv_tab : tableau de structure char , ligne :int (nombre de ligne de csv_tab)
	sorti csv_tab
	declaration;
	j,conteur : int
	post condition:
	Permet d'afficher les informations ainsi que le nommbre des lignes ou il manque des inforamtion dans la tableau de structure 
*/
int recherche_occu_vide(CSV csv_tab[], int ligne);
/** redigé par Graux François

	Entrée csv_tab : tableau de structure
	sortie ligne :int
	declaration:
	tableau :tableau de char , fichier : tableau de char
	colone,ligne,j : int
	post condition:
	Permet de remplir le tableau de structure à partir du CSV en utilisant ma fonction champ pour remplir les bonnes informations
*/
int ouverture_attribution(CSV csv_tab[]);
/** rédiger par François Graux
	
	Entrée char, ligne :int (nombre de ligne de csv_tab)
	entrée /sortie csv_tab:tableau de structure,ligne :int
	postcondition:
	Permet d'ajouter une nouvelle personne à l'annuaire ainsi que de retouner le nombre de ligne + 1 et remplace les '\n' par des \0
*/
int ajout(CSV csv_tab[],int ligne);
/** rédiger par François Graux
 
	Entrée/sortie csv_tav :tableau de structure char,Ligne:int du nb de ligne de la strcuture,rang :int, indice:tableau de int ,type_filtre:int
	declaration:
	int i
	post condition:
	Permet de trouver si une chaine de caratere ou une sous chaine de caractere ce trouve dans le tableau de strucre a une ligne donné
*/
void filtre(CSV csv_tab[],int ligne,char chaine[],int rang,int indice[],int type_filtre);
/**rédiger par François Graux
	entrée csv_tab: tableau de structure char ,ligne : int
 	sortie fichier
	Declaration : 
	colone : int
	post condition:
	permet de remplir un fichier crée dans la fonction avec une copie du tableau de structure csv_tab
 */
int ecriture(CSV csv_tab[],int ligne);
/**rédiger par François Graux
 * entrée/sortie csv_tab : tableau de structure
 * entrée ligne : pointeur de int
 * declaration : 
 * index : int
 * post condition :
 * permet de supprimé une ligne choisi par l'utilisateur
 */
void suppression(CSV csv_tab[],int *ligne);
/**rédiger par François Graux
 * entrée/sortie csv_tab : tableau de structure
 * entrée ligne : pointeur de int
 * declaration : 
 * choix_index,choix_colone : int
 * post condition:
 * permet de modifier une information d'une personne de l'annuaire
 */
void maj(CSV csv_tab[]);
/**rédiger par graux françois
 * Entrée csv_tab : tableau de structure char , ligne :int (nombre de ligne de csv_tab)
	sorti csv_tab
	post condition:
	Permet d'afficher les informations ainsi que le nommbre des lignes ou il manque des inforamtion dans la tableau de structure avec le nom prenom et tel
*/
void recherche2(CSV csv_tab[],int ligne,int indice[]);
#endif







