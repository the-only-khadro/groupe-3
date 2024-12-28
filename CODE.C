// creation des onctions de gestion de compte bancaire
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct compte
struct compte {
    int numero_compte;
    int solde;
    char nom[25];
    char prenom[25];
    char ville[50];
    char telephone[15];
};

//fonction accueil
int accueil() {
    int choice;
    printf("que veut tu faire?\n");
    printf("entrer 1 pour ajouter un compte\n");
    printf("entrer 2 pour supprimer un compte\n");
    printf("entrer 3 pour faire des operations dans un compte\n");
    scanf("%d\n", &choice);
    switch (choice)
    {
        case 1:
            printf("vous avez choisi d'ajouter un compte\n");
            break;
        case 2:
            printf("vous avez choisi de supprimer un compte\n");
            break;
        case 3:
            printf("vous avez choisi de faire des operations dans un compte\n");
            break;
        default:
            break;
    }
    return choice;
}

// Function to add an account
struct compte ajout_compte(int numero_compte, int solde, char* nom, char* prenom, char* ville, char* telephone) {
    struct compte c1;
    struct compte t[1000];
    strcpy(c1.nom, nom);
    strcpy(c1.prenom, prenom);
    strcpy(c1.ville, ville);
    strcpy(c1.telephone, telephone);
    c1.numero_compte = numero_compte;
    c1.solde = solde;
        printf("Le compte %d a ete ajoute\n", c1.numero_compte);
        printf("voici les informations du compte\n");
        printf("Nom: %s\n", c1.nom);
        printf("Prenom: %s\n", c1.prenom);
        printf("Ville: %s\n", c1.ville);
        printf("Telephone: %s\n", c1.telephone);
        printf("Solde: %d\n", c1.solde);

        
    return c1;
}

// Function to take inputs
void prendre_inf() {
    char nom[5];
    char prenom[5];
    char ville[5];
    char telephone[5];
    int solde;

    printf("Entrer le nom du client\n");
    scanf("%s\n", nom);
    while (strlen(nom) > 5) {
        printf("veuillez entrer un nom valide\n");
        scanf("%s\n", nom);
    }
    printf("Entrer le prenom du client\n");
    scanf("%s\n", prenom);
    while (strlen(prenom) > 5) {
        printf("veuillez entrer un prenom valide\n");
        scanf("%s\n", prenom);
    }
  
    printf("Entrer la ville du client\n");
    scanf("%s\n", ville);
    while (strlen(ville) > 5) {
        printf("veuillez entrer une ville valide\n");
        scanf("%s\n", ville);
    }
    printf("Entrer le numero de telephone du client\n");
    do {
        scanf("%s\n", telephone);
        printf("veuillez entrer un numero de telephone valide\n");
    } while (strlen(telephone) > 5);

    printf("Entrer le solde du client\n");
    do {
        scanf("%d\n", &solde);
        printf("veuillez entrer un solde valide\n");
    } while (solde <= 0);
    ajout_compte(1, solde, nom, prenom, ville, telephone);
}



int main() {
    
    printf("Bienvenue dans notre application de gestion de compte\n");
    accueil();
    if(accueil() == 1) {
        prendre_inf();
    }
    struct compte c1;
    FILE* fptr;
    fptr = fopen("comptes.txt", "a");
    if(fptr != NULL) {
        fprintf(fptr, "Nom: %s\n", c1.nom);
        fprintf(fptr, "Prenom: %s\n", c1.prenom);
        fprintf(fptr, "Ville: %s\n", c1.ville);
        fprintf(fptr, "Telephone: %s\n", c1.telephone);
        fprintf(fptr, "Solde: %d\n", c1.solde);
        fclose(fptr);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
      
    char mychar[100];   
    fptr = fopen("comptes.txt", "r");
    if(fptr != NULL) {
        while(fgets(mychar, 100, fptr) != NULL) {
            printf("this is%s", mychar);
        }
        fclose(fptr);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
    return 0;
}

