#include<stdio.h>
#include<stdlib.h>
#define fic "annuaire5000.csv"
int main()
{
    char tableau[250];
    FILE * annuaire = fopen(fic,"r") ;
    do
    {
        fgets(tableau,250,annuaire);
        printf("%s",tableau);
    } while (!feof(annuaire));
    

    return 0;
}
