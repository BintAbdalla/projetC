#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> // Pour getpass()

int menuetudiant() {
    int choix;
    do {
        printf("BIENVENUE DANS VOTRE MENU CHERS APPRENANT!!!:\n");
        printf("----------------------------------------------:\n");
        printf("1) Marquer ma presence :\n");
        printf("-----------------------------------:\n");
        printf("2) Nombre de minutes d'absence :\n");
        printf("-------------------------------------------------:\n");
        printf("3) Mes message(0):\n");
        printf("--------------------------------:\n");
        printf("4) Quitter:\n");
        scanf("%d", &choix);
    } while (choix > 4 || choix < 1);

    return choix;
}

int menuadmin() {
    int option;
    do {
        printf("BIENVENUE DANS VOTRE MENU CHERS ADMINS:\n");
        printf("------------------------------------------------:\n");
        printf("1) GESTION DES ETUDIANTS:\n");
        printf("-----------------------------------:\n");
        printf("2)  GENERATION DES FICHIERS :\n");
        printf("----------------------------------------:\n");
        printf("3) MARQUER LES PRESENCES :\n");
        printf("--------------------------------------------:\n");
        printf("4) ENVOYER UN MESSAGE:\n");
        printf("------------------------------------------------------:\n");
        printf("5) QUITTER:\n");
        scanf("%d", &option);
    } while (option < 1 || option > 5);

    return option;
}

int login(char matricule[20]) {
    char ligne[100], login[50], password1[50], username[50], password[50], ca;char password_input[20] ;
    int type;
    
    do {
        while (1) {
            printf("Veuillez saisir un username :\n");
            ca = getchar();
            int i = 0;
            while (ca != '\n') {
                if (ca != '\n') {
                    username[i++] = ca;
                } else {
                    while (getchar() != '\n');
                    i = 0;
                    break;
                }
                ca = getchar();
            }
            if (i != 0) break;
            else {
                puts("Vous n'avez pas saisie correctement votre username\n");
            }
        }

        printf("Veuillez saisir un password :\n ");
        
        strcpy(password_input, getpass("****"));
        break;
        
        

    } while (1);

    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return -1;
    }

    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        sscanf(ligne, "%s %s %d %s", login, password1, &type, matricule);
        if (strncmp(username, login, sizeof(username)) == 0 && strncmp(password_input, password1, sizeof(password_input)) == 0) {
            if (type == 1) {
                fclose(file); // Fermeture du fichier après utilisation
                return 1;
            } else {
                fclose(file); // Fermeture du fichier après utilisation
                return 0;
            }
        }
    }
    fclose(file); // Fermeture du fichier après utilisation
    return 3;
}

int liste(char mat[]){
    char ligne[50] ; 
    char nom[50];
    char prenom[50];
    char matricule[10];
    char Id[10];
    int exist=0;

    FILE *file = fopen("etudpresent.txt", "r");
    if (file == NULL) {
         printf("Impossible d'ouvrir le fichier.\n");

         return -1;
     }

    
    
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        sscanf(ligne, "%s %s %s", matricule, prenom, nom);
        if (strcmp(mat, matricule) == 0 ) {
            exist=1;
            break;
        }
    }

    if (exist) {
        FILE *file2=fopen("marquePresent.txt","a");
        fprintf(file2,"%s %s %s \n",mat,nom,prenom);
        printf("vous etes ajouté!!\n");
        fclose(file2); // Fermeture du fichier après utilisation
    }
    fclose(file); // Fermeture du fichier après utilisation
    return 0;
}

int main() {
    while (1) {
        char mat[20];
        
        int b=login(mat);
liste(mat);
        puts(mat);
        if (b==1) {
            printf("Se connecter en tant que étudiant:\n");
            int choix= menuetudiant(); 
if(choix==1){

               printf("veuillez marquer votre presence:\n");

}
        } else if(b==0) {
            printf("Se connecter en tant que admin:\n");
            menuadmin(); 
        } else {
            printf("login ou mdp incorect\n");
        }
    }
    
   return 0;
}