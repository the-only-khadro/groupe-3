
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir the struct date
struct date {
    int jour;
    int mois;
    int annee;
};

// Define the struct client
struct client {
    int codecl;
    char prenom[25];
    char nom[25];
    char tel[15];
    char ville[50];
};

// Define the struct compte
struct compte {
    int numero_compte;
    struct date date;
    int solde;
    int codecl;
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
    switch (choice){
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


void ajout_compte(int numero_compte, struct date date, int solde, int codecl){
    struct compte* t = malloc(sizeof(t));
    t->numero_compte = numero_compte;
    t->date = date;
    t->solde = solde;
    t->codecl = codecl;
    FILE* fptr;
    fptr = fopen("comptes.txt", "a");
    if(fptr != NULL) {
        fprintf(fptr, "Nom: %s\n", t->numero_compte);
        fprintf(fptr, "date: %s\n", t->date.jour);
        fprintf(fptr, "solde: %s\n", t->solde);
        fprintf(fptr, "codecl: %s\n", t->codecl);
        fclose(fptr);
    }

}

void ajout_client(int codecl, char prenom[5], char nom[5], char tel[5], char ville[5]){
    struct client * m[1];
    m[1]= malloc(50 * sizeof(struct client));
    
    m[0]->codecl = codecl;
    strcpy(m[0]->prenom, prenom);
    strcpy(m[0]->nom, nom);
    strcpy(m[0]->tel, tel);
    strcpy(m[0]->ville, ville);
}

void prendre_inf(){
    int numero_compte;
    char nom[5];
    char prenom[5];
    char ville[5];
    char telephone[5];
    int solde;
    int codecl;
    struct date date;
    printf("Entrer le jour\n");
    scanf("%d", &date.jour);
    while (date.jour < 1 || date.jour > 31) {
        printf("Veuillez entrer un jour valide\n");
        scanf("%d", &date.jour);
    }

    printf("Entrer le mois\n");
    scanf("%d", &date.mois);
    while (date.mois < 1 || date.mois > 12) {
        printf("Veuillez entrer un mois valide\n");
        scanf("%d", &date.mois);
    }

    printf("Entrer l'année\n");
    scanf("%d", &numero_compte);
    while (date.annee < 2024 || date.annee > 2025) {
        printf("Veuillez entrer une année valide\n");
        scanf("%d", &date.annee);
    }

    printf("entrer le numero de compte");
    scanf("%s", &numero_compte);
    while(numero_compte <=0){
        printf("entrer un numero valide");
        scanf("%d\n", &numero_compte);
    }

    printf("Entrer le nom du client\n");
    scanf("%s", &nom);
    while (strlen(nom) > 5) {
        printf("veuillez entrer un nom valide\n");
        scanf("%s\n", &nom);
    }

    printf("Entrer le prenom du client\n");
    scanf("%s", &prenom);
    while (strlen(prenom) > 5) {
        printf("veuillez entrer un prenom valide\n");
        scanf("%s\n", &prenom);
    }
    
    printf("Entrer la ville du client\n");
    scanf("%s", &ville);
    while (strlen(ville) > 5) {
        printf("veuillez entrer une ville valide\n");
        scanf("%s\n", &ville);
    }

    printf("Entrer le numero de telephone du client\n");
    scanf("%d", &telephone);
    while(strlen(telephone)>5){
        printf("entrer une numero valide");
        scanf("%s\n", &telephone);
    }

    printf("entrer votre solde");
    scanf("%d\n",solde);
    while(solde <= 0){
        printf("entrer une solde valide");
        scanf("%d\n", &solde);
    }
    printf("Entrer le code client\n");
    scanf("%d", &codecl);
    while (codecl <= 0){
        printf("mauvais saisie");
        scanf("%s\n", &codecl);
    }
    ajout_compte(numero_compte,date,solde,codecl);
    ajout_client(codecl,prenom,nom,telephone,ville);
}

// fonction envoie d'argent
    void envoie_argent(){
    int num_compte;
    int num_dest; 
    int montant;
    char hist [1000];
    printf("entrer votre numero de compte\n");
    scanf("%d\n", &num_compte);
    printf("entrer le numero de compte du destinataire");
    scanf("%d\n", &num_dest);
    printf("entrer le montant que vous voulez envoyer");
    scanf("%d\n", &montant);
    FILE * fptr;
    fptr = fopen(comptes.txt, "r")
    while (i != EOF)
    {
        fgets(hist,1000,fptr);
    }
    int i,j;
    for (size_t i = 0; i < count ; i++)
    {
        while (t[i]->numero_compte = num_compte )
        {
            while ( t[j]->numero-compte = num_dest)
            {
                t[i]->solde -= montant;
                t[j]->solde += montant
            }    
        }
        
    }
    printf("votre envoie a bien ete effectue");
    FILE * fptr;
    fptr= fopen(historique.txt,"w")
    fputs("le compte numero %d a envoyer %d  au compte numero %d",numero_compte,montant,numero_dest);
}

//fonction retrait d'argent
// fonction envoie
    void retrait_argent(){
    int num_compte;
    int montant;
    char hist [1000];
    printf("entrer votre numero de compte\n");
    scanf("%d\n", &num_compte);
    printf("entrer le montant que vous voulez envoyer");
    scanf("%d\n", &montant);
    FILE * fptr;
    fptr = fopen(comptes.txt, "r")
    while (i != EOF)
    {
        fgets(hist,1000,fptr);
    }
    int i;
    for (size_t i = 0; i < count ; i++)
    {
        while (t[i]->numero_compte = num_compte && t[i]->solde >= montant )
        {
            t[i]->solde -= montant; 
        }
        
    }
    printf("votre retrait a bien ete effectue");
    FILE * fptr;
    fptr= fopen(historique.txt,"w")
    fputs("le compte numero %d a retirer %d fcfa",numero_compte,montant);
}

void suppr_compte(){
    int num_compte;
    prpintf("entrer le numero de votre compte");
    scanf("%d\n",&num_compte);
    for (size_t i = 0; i < count; i++)
    {
        if(t[i]->numero_compte = num_compte){
        t[i]= 0;
        }
    }
    printf("le compte %d a bien ete supprimer",num_compte);
}

int main(){
    
    printf("Bienvenue dans notre application de gestion de compte\n");
    accueil();
    if(accueil() == 1) {
        prendre_inf();
    } else if (accueil() == 2){
        suppr_compte();
    } else {
        printf("entrer 1 si vous voulez envoyer de l'argent et 2 si vous souhaiter en retirer");
        int reponse;
        scanf("%d\n",&reponse);
        if (reponse == 1){
                envoie_argent();
        } else{
            retrait argent();
            }
    }    
    return 0;
}



