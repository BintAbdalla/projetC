#include <stdio.h>
#include <string.h>
#include <unistd.h>


int menu(){

int choix;
             do { printf("BIENVENUE DANS VOTRE MENU CHERS APPRENANT!!!:\n");
                  printf("----------------------------------------------:\n");
                  printf("1) Marquer ma presence :\n");
                  printf("-----------------------------------:\n");
                  printf("2) Nombre de minutes d'absence :\n");
                  printf("-------------------------------------------------:\n");
                  printf("3) Mes message(0):\n");
                  printf("--------------------------------:\n");
                  printf("4) Quitter:\n");
                  scanf("%d",&choix);
             }while(choix>4 || choix<1);





return choix;





}


int main() {

    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    char ligne[100], login[50], password1[50], username[50], password[50],ca;
    int i = 0; int type;
    while(fgets(ligne, sizeof(ligne), file) != NULL){
    sscanf(ligne, "%s %s %d", login, password1,type);
    fclose(file);
    }
    do {
        while(1){
            printf("Veuillez saisir un username :\n");
            ca = getchar();
            while (ca != '\n')
            {
                if(ca != '\n'){
                    username[i++] = ca;
                }else{
                    while (getchar() != '\n'); i=0; break;
                }
            }
            if(i!=0) break;
            else{
                puts("Vous n'avez pas saisie correctement votre username\n");
            }
            
        }

        printf("Veuillez saisir un password :\n");
        
      char  *password=getpass("*****");
        strncpy(password,password,sizeof(password));
        printf("\npassword saisi :%s\n","****");

        if (strcmp(username, login) == 0 && strcmp(password, password1) == 0) {
            printf("succes de connexion:\n");
            
            break;
        } else {
            printf("Oups!!echec ! veuillez resaisir:\n");
        }
    } while (1);
int a;
//Appel de fonction
int choix;
a=menu(choix);


int menuadmin(){

int option;




return option;
};



FILE *file1 = fopen("admin.txt", "r");
    if (file1 == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    char etape[100], user[50], motdepas1[50], user1[50], motdepas[50];
    fgets(etape, sizeof(etape), file);
    sscanf(etape, "%s %s", user, motdepas);
    fclose(file);

    do {
        printf("Veuillez saisir un username :\n");
        scanf("%s", user);
        printf("Veuillez saisir un password :\n");
        
      char  *motdepas1=getpass("*****");
        strncpy(motdepas1,motdepas1,sizeof(motdepas1));
        printf("\npassword saisi :%s\n","****");

        if (strcmp(user, user1) == 0 && strcmp(motdepas, motdepas1) == 0) {
            printf("succes de connexion:\n");
            break;
        } else {
            printf("Oups!!echec ! veuillez resaisir:\n");
        }
    } while (1);
































    return 0;
}