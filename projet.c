#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//ici nous créons un tableau pour representer le nomber d'etudiant d'une classe 
#define notes 100


FILE *fEtudiant;
FILE *fMatiere;
FILE *fClasse;
FILE *fNotes;
FILE *fclasse_mat;

// les nouveaux pointeurs temporels qui pointent vers les fichiers créer;
FILE *ftmp_Classe;
FILE *ftmp_Etudiant;
FILE *ftmp_Matiere;

typedef struct ddn ddn;
struct ddn{
    int jour;
    int mois;
    int annee;
};
//ici nous avons une énumération des diff niveaux de nôtre Etablissement;
enum niveau_classe {
    licence,
    Master
};

 typedef struct Etudiant Etudiant;
struct Etudiant{
    int num_et;
    int code_et;
    char nom_et[100], prenom_et [100], email_et[150];
    ddn ddn_et; 
};

typedef struct Matiere Matiere;
struct Matiere{
    int reference;
    char libelle_mat[100];
    int coefficient;
};

typedef struct Classe Classe;
struct Classe{
    int code_classe; 
    char nom_classe[100];
    char niveau_classe[100];     
};
typedef struct Note Note;
struct Note{
    int reference_mat, numero_et;
    float note_cc, note_ds;
};
typedef struct matiere_classe matiere_classe;
struct matiere_classe{
    int code_classe, ref_matiere;
};
int main()
{
    /*ici nous mettons l'ensembles des variables
        dont nous aurons besoin au cour de notre programme*/

    // l'ensemble des variables pour le choix du menu;
    int choix, choix1, choix2;
    //ici on déclare les variables utilisées au niveau des fonctiannalitées;
    //elles sont utilisée surtout pour être comparer aux identifiants
    int recois, code, code1, mat_fait, tail_classe;
    char nom_classe[100], niveau_classe[100];
    int num_et, code_et, jour, mois, annee;
    char nom_et[100], prenom_et[100], email_et[100];

    //ici on déclare les variables qui ont pour type un de nos structure créer précedement;
    Classe classe;
    Etudiant etudiant;
    Matiere matiere;
    Note note, tab_note[notes];
    //ici on déclare les variables pour l'utilisation de nos fichiers en format csv;
    char lecture[200];
    char lecture_note[200];
    // ce menu represente les differents choix de notre application 
    retour_menu : 
    {
        printf("\n\t\t\t\t ********* Menus Principale *********\n");
        printf("\n");
        printf("\t\t\t\t\t 1- Gestion Des Etudiants\n");
        printf("\t\t\t\t\t 2- Gestion Des Matières \n");
        printf("\t\t\t\t\t 3- Gestion Des Classes \n");
        printf("\t\t\t\t\t 4- Gestion Des Notes \n");
        printf("\t\t\t\t\t 5- Quitter\n");
        printf("\n");
        printf("entrez vôtre choix: ");
        scanf("%d", &choix);
        printf("----------------------\n");
    }

    switch (choix)
    {

                                    //GESTION DES ETUDIANTS//
    case 1:
        printf("\n");
        //les différents options relatif à la gestion des Etudiants
        menu_Etudiant:
        {
        printf("\t\t\t\t ***** Gestion Des Etudiants *****\n");
        printf("\n");
        printf("\t\t\t\t\t 1- Afficher Les Etudiants\n");
        printf("\t\t\t\t\t 2- Recherche D'Etudiant\n");
        printf("\t\t\t\t\t 3- Ajout D'Etudiant\n");
        printf("\t\t\t\t\t 4- Modification D'Etudiant\n");
        printf("\t\t\t\t\t 5- Suppression D'Etudiant\n");
        printf("\t\t\t\t\t 6- <--- Précédent\n");
        printf("\n");
        printf("entrez vôtre choix: ");
        scanf("%d", &choix1);
        printf("------------------------------\n");
        }

            switch(choix1)
            {
                case 1:
                     ////ici, cette fonctionnalité affiche la liste des étudiants presentent dans notre etablissement
                     printf("\n");
                     fEtudiant = fopen("Etudiant.csv", "r");
                     if(fEtudiant != NULL)
                     {
                        printf(" Liste Des Etudiants: \n");
                        while(fgets(lecture, 200, fEtudiant)!= NULL)
                        {
                        printf("\n%s\n", lecture);
                        }
                     }
                    printf("-----------------------------------\n");
                goto menu_Etudiant;
                break;

                case 2:
                //ici, cette fonctionnalitée permet de rechercher un étudiant present dans l'établissement 
                 printf("\n");
                 printf("entrer le numéro de l'etudiant\n");
                 scanf("%d", &code);
                 fEtudiant = fopen("Etudiant.csv", "r");               
                 if(fEtudiant != NULL)
                 {
                     do
                     {
                        fscanf(fEtudiant, "%d ;%d ;%s ;%s ;%s ;%d-%d-%d; \n", &etudiant.num_et, &etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, &etudiant.ddn_et.jour, &etudiant.ddn_et.mois, &etudiant.ddn_et.annee );
                        fflush(stdin);
                        if(code==etudiant.num_et)
                        {
                            fclose(fEtudiant);
                            printf("etudiant trouvé\n");
                            printf("-----------------------------------\n");
                        }
                        else{
                            fclose(fEtudiant);
                            printf("ce numéro ne correspond à n'aucun étudiant de l'etablissement\n");
                            printf("----------------------------------------------------\n");
                        }
                     }while(feof(fEtudiant)); 
                 }
                goto menu_Etudiant;
                break;
                case 3:
                //ici cette fonctionnalitée permet d'ajouter un etudiant;
                        fEtudiant = fopen("Etudiant.csv", "a");
                                printf("-----------------------------------\n");
                                printf("\nentrer le code de l'etudiant ");
                                scanf("%d", &etudiant.code_et);
                                printf("\nentrer le nom de l'etudiant ");
                                scanf("%s", etudiant.nom_et);
                                printf("\nentrer le prenom de l'etudiant ");
                                scanf("%s", etudiant.prenom_et);
                                printf("\nentrer l'email de l'etudiant ");
                                scanf("%s", etudiant.email_et);
                                printf("\nentrer le jour de naissance de l'etudiant ");
                                scanf("%d", &etudiant.ddn_et.jour);
                                printf("\nentrer le mois de naissance de l'etudiant ");
                                scanf("%d", &etudiant.ddn_et.mois);
                                printf("\nentrer l'année de naissance de l'etudiant ");
                                scanf("%d", &etudiant.ddn_et.annee);
                                if((etudiant.ddn_et.jour > 31) && (etudiant.ddn_et.mois > 12))
                                {
                                    //ici nous mettons cette condition pour gérer la validitée du jour et du mois entrer; 
                                    printf("le jour ou le mois que vous avez entrer n'est pas valide\n");
                                }
                                else{                
                                        fprintf(fEtudiant, "%d ;%d ;%s ;%s ;%s ;%d-%d-%d \n", etudiant.num_et, etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, etudiant.ddn_et.jour, etudiant.ddn_et.mois, etudiant.ddn_et.annee );
                                        printf("Etudiant ajouter avec succées\n");
                                        fclose(fEtudiant);
                                    }
                        printf("-------------------------------------------\n");
                goto menu_Etudiant;
                break;
                case 4:
                //ici cette fonctionnalité permet de modifier une ou plusieurs information sur un étudiant 
                        /* MODIFICATIONS */
                        fEtudiant = fopen("Etudiant.csv", "r");
                        ftmp_Etudiant = fopen("etudiant_tmp.csv", "r+");
                            printf("entrer le numéro de l'étudiant: ");
                            scanf("%d", &code);
                            do
                            {
                                fscanf(fEtudiant, "%d %d %s %s %s %d %d %d", &etudiant.num_et, &etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, &etudiant.ddn_et.jour, &etudiant.ddn_et.mois, &etudiant.ddn_et.annee );
                                if(code==etudiant.num_et)
                                {
                                    recois=1;
                                    break;
                                }
                                else {printf("classe introuvable\n");    break;}
                            }while(!feof(fEtudiant));
                            fclose(fEtudiant);
                        fEtudiant = fopen("Etudiant.csv", "r");
                                if(recois==1)
                                {
                                    printf("entrer le code de l'etudiant ");
                                    scanf("%d", &code_et);
                                    printf("\nentrer le nom del'etudiant ");
                                    scanf("%s", nom_et);
                                    printf("\nentrer le prenom de l'etudiant ");
                                    scanf("%s", prenom_et);
                                    printf("\nentrer l'email de l'étudiant ");
                                    scanf("%s", email_et);
                                    printf("\nentrer le jour de naissancce de l'etudiant ");
                                    scanf("%d", &jour);
                                    printf("\nentrer le mois de naissance de l'etudiant ");
                                    scanf("%d", &mois);
                                    printf("\nentrer l'année de naissance de l'etudiant ");
                                    scanf("%d", &annee);
                                    if((etudiant.ddn_et.jour > 31) && (etudiant.ddn_et.mois > 12))
                                    { printf("le jour ou le mois que vous avez entrer n'est pas valide\n"); break;}
                                    else
                                    {
                                        do 
                                        {
                                            fprintf(ftmp_Etudiant, "%d ;%d ;%s ;%s ;%s ;%d ;%d ;%d;\n", num_et, code_et, nom_et, prenom_et, email_et, jour, mois, annee );
                                        }while(!feof(fEtudiant));
                                        fclose(ftmp_Etudiant);
                                        fclose(fEtudiant);
                                        remove("Etudiant.csv");
                                        rename("etudiant_tmp.csv", "Etudiant.csv");
                                        printf("modification effectuée avec succées\n");
                                    }

                goto menu_Etudiant;
                break;
                case 5: 
                //ici cette fonctionnalitée permet supprimer les informations d'un etudiant
                        fEtudiant = fopen("Etudiant.csv", "r");
                        ftmp_Etudiant = fopen("etudiant_tmp.csv", "a");
                                printf("entrer le numéro de l'étudiant: ");
                                scanf("%d", &code);
                                do 
                                {
                                    fscanf(fEtudiant, "%d %d %s %s %s %d %d %d", &etudiant.num_et, &etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, &etudiant.ddn_et.jour, &etudiant.ddn_et.mois, &etudiant.ddn_et.annee );
                                    if(code!=etudiant.num_et)
                                    {
                                        fprintf(ftmp_Etudiant, "%d ;%d ;%s ;%s ;%s ;%d ;%d ;%d \n", etudiant.num_et, etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, etudiant.ddn_et.jour, etudiant.ddn_et.mois, etudiant.ddn_et.annee );
                                        break;
                                    }
                                }while(!feof(fEtudiant));
                            fclose(ftmp_Etudiant);
                            fclose(fEtudiant);
                            remove("Etudiant.csv");
                            rename("etudiant_tmp.csv", "Etudiant.csv");
                           printf("Suppression effectuée avec succées\n");
                            printf("--------------------------------------------------\n");
                        } 
                goto menu_Etudiant;
                break;
                default:
                    goto retour_menu;
                break;
            }

                                    //GESTION DES MATIERE//
    case 2:
        //les différents options relatif à la gestion des Matières
        printf("\n");
        retour_matiere:
        {
        printf("\t\t\t\t  *****Gestion Des Matières***** \t\t\t\t\n");
        printf("\n");
        printf("\t\t\t\t\t  1- Afficher Matère\n");
        printf("\t\t\t\t\t  2- Recherche Matière\n");
        printf("\t\t\t\t\t  3- Ajouter Matière\n");
        printf("\t\t\t\t\t  4- Modification Matière\n");
        printf("\t\t\t\t\t  5- Suppression Matière\n");
        printf("\t\t\t\t\t  6- <--- Précédent\n");
        printf("\n");
        printf("entrez vôtre choix: ");
        scanf("%d", &choix1);
        printf("--------------------\n");
        }
            switch (choix1)
            {
            case 1:
                // ici cette fonctionnalité affiche la liste des matières présentes dans l'école;
                fMatiere = fopen("Matieres.csv", "r");
                printf("voici la liste des classes\n");
                printf("----------------------------------\n");
                while(fgets(lecture, 200, fMatiere)!=NULL)
                {
                    printf("%s\n", lecture);
                }
                fclose(fMatiere);
                printf("------------------------------------\n");
                goto retour_matiere;
            break;
            case 2:
                //ici cette fonctionnalité permet de rechercher une Matière dans fait dans l'etablissement

                    printf("entrer la réference de la matière recherchée: ");
                    scanf("%d", &code);
                    fMatiere = fopen("Matieres.csv", "r");
                    do
                    {
                        fscanf(fMatiere, "\n %d ;libelle = %s ;coefficient = %d; \n", &matiere.reference, matiere.libelle_mat, &matiere.coefficient);
                        if(code==matiere.reference)
                        {
                            printf("Matière trouvée \n");
                            break;
                        }
                        else
                        {
                            printf("Matière introuvable \n");
                            break;
                        }
                    } while (!feof(fMatiere));
                    
                    fclose(fMatiere);
                goto retour_matiere;
            break;
            case 3:
                //ici cette fonctionnalitée permet d'ajouter une nouvelle matiere dans l'etablissement
                    printf("entrer la reference de la matière: ");
                    scanf("%d", &matiere.reference);
                    printf("entrer le nom de la matière: ");
                    scanf("%s", matiere.libelle_mat);
                    printf("entrer le coefficient de la matière: ");
                    scanf("%d", &matiere.coefficient);
                    fMatiere = fopen("Matieres.csv", "a");
                    fprintf(fMatiere, "\n %d ;libelle = %s ;coefficient = %d; \n", matiere.reference, matiere.libelle_mat, matiere.coefficient);
                    fflush(fMatiere);
                    printf("Matière ajoutée \n");
                    printf("-------------------\n");
                    fclose(fMatiere);
                goto retour_matiere;
            break;
            case 4:
                //ici cette fonctionnalitée permet de modifier les informations sur une matières
                    fMatiere = fopen("Matieres.csv", "r");
                    ftmp_Matiere = fopen("matiere_tmp.csv", "a");
                    printf("entrer la reference de la matière a modifier: \n");
                    scanf("%d", &code);
                    do
                    {
                        fscanf(fMatiere, "\n %d ;libelle = %s ;coefficient = %d; \n", &matiere.reference, matiere.libelle_mat, &matiere.coefficient);
                        if(matiere.reference==code)
                        {
                            recois = 1;
                            break;
                        }
                        else
                        {
                            printf("classe introuvable \n");
                            break;
                        }
                    } while (!feof(fMatiere));
                    fclose(fMatiere);
                    fMatiere = fopen("matiere.csv", "r");
                    if(recois==1)
                    {
                        printf("entrer la nouvelle matière: ");
                        scanf("%s", matiere.libelle_mat);
                        printf("\n entrer le coefficient: ");
                        scanf("%d", &matiere.coefficient);
                        fprintf(ftmp_Matiere, "\n %d ;libelle = %s ;coefficient = %d; ", code, matiere.libelle_mat, matiere.coefficient);
                        printf("Modification effectuer avec succée. \n");
                        fclose(ftmp_Matiere);
                        fclose(fMatiere);
                        remove("Matieres.csv");
                        rename("matiere_tmp.csv", "Matieres.csv");
                    }
                    printf("-----------------------------------------------\n");
                goto retour_matiere;
            case 5: 
                //ici cette fonctionnalitée permet la suppression d'une matière
                    fMatiere = fopen("Matieres.csv", "r");
                    ftmp_Matiere = fopen("matiere_tmp.csv", "a");
                    printf("entrer la reference de la matière a supprimer: ");
                    scanf("%d", &code);
                    do
                    {
                        fscanf(fMatiere, "\n %d ;libelle = %s ;coefficient = %d; \n", &matiere.reference, matiere.libelle_mat, &matiere.coefficient);
                        if(matiere.reference!=code)
                        {
                            fprintf(ftmp_Matiere, "\n %d ;libelle = %s ;coefficient = %d; \n", matiere.reference, matiere.libelle_mat, matiere.coefficient);
                            break;
                        }
                        else 
                        {
                            printf("Matière introuvable\n");
                        }
                    } while (!feof(fMatiere));
                    fclose(ftmp_Matiere);
                    fclose(fMatiere);
                    remove("Matieres.csv");
                    rename("matiere_tmp.csv", "Matieres.csv");
                    printf("Suppression effectuée avec succées\n");
                    printf("-----------------------------------------------\n");
                goto retour_matiere;
            break;
            default:
                goto retour_menu;
                break;
            } 

                                        //GESTION DES CLASSES//

    case 3:
        //les différents options relatif à la gestion des Classes             
        menu_classe:
        {
            printf("\n");
            printf("\t\t\t\t *****Gestion Des Classes*****\n");
            printf("\n");
            printf("\t\t\t\t\t  1- Afficher La Liste Des Classes\n");
            printf("\t\t\t\t\t  2- Recherche D'une Classes\n");
            printf("\t\t\t\t\t  3- Ajouter Une Classe\n");
            printf("\t\t\t\t\t  4- Modification Une Classe\n");
            printf("\t\t\t\t\t  5- Suppression Une Classe\n");
            printf("\t\t\t\t\t  6- <--- Précédent\n");
            printf("\n");
            printf("entrez vôtre choix: ");
            scanf("%d", &choix1);
            printf("-------------------------\n");
        }
        
    
        switch (choix1)
            {
            case 1:
                //ici, cette fonctionnalité affiche la liste des classes presentent dans notre etablissement;
                printf("\n");
                fClasse= fopen("Classe.csv", "r");
                   while(fgets(lecture, 200, fClasse)!= NULL)
                   {
                       printf("%s\n", lecture);
                   }
                fclose(fClasse);
                printf("---------------------------\n");
                //cette fonctionnalitée goto permet de refaire un retour au niveau du sous menu;
                goto menu_classe;
                break;
            case 2:
                //ici nous créons la fonctionnalité de recherche d'une  classe presente dans l'etablissement;
                    fClasse=fopen("Classe.csv", "r");
                            do
                            {   
                                printf("entrer le code de la classe à rechercher: ");
                                scanf("%d", &code);                        
                                fscanf(fClasse, "%d ;%s ;%s \n", &classe.code_classe, classe.nom_classe, classe.niveau_classe);
                                if(code==classe.code_classe)
                                {
                                    printf("Classe trouvée : %s, %s\n", classe.nom_classe, classe.niveau_classe);
                                    break; 

                                }
                                else
                                {
                                    printf("cette Classe n'existe dans cette établissement\n");
                                    break;                        
                                }    
                            }while(!feof(fEtudiant));
                            fclose(fClasse);
                            printf("--------------------------------------\n");  
                goto menu_classe;
            break;
            case 3:
                //ici nous créons la fonctionnalité d'ajout d'une classe;
                            fClasse =fopen("Classe.csv", "a");
                                printf("entrer le code de la classe: ");
                                scanf("%d", &code);
                                fscanf(fClasse, "%d, %s,  %s;\n", &classe.code_classe, classe.nom_classe, classe.niveau_classe);
                                if (code != classe.code_classe)
                                {
                                    printf("entrez le nom de la classe\n");
                                    scanf("%s", nom_classe);
                                    printf("entrez le niveau de la classe\n");
                                    scanf("%s", niveau_classe);
                                    fprintf(fClasse, "%d ;%s ;%s\n", code, nom_classe, niveau_classe);
                                    printf("Classe ajouter\n");
                                }
                                else
                                {
                                    printf("ce code est déja attribué a une classe\n");
                                    break;
                                }   
                            fclose(fClasse);
                            printf("--------------------------------------\n"); 
                goto menu_classe;
            break; 
            case 4:
                //ici nous créons la fonctionnalité de modification d'une classe;
                                fClasse = fopen("Classe.csv", "r");
                                ftmp_Classe = fopen("classe_tmp.csv", "a");
                                    printf("entrez le code de la classe: ");
                                    scanf("%d", &code);
                                    do
                                    {
                                        fscanf(fClasse, "%d ;%s ;%s", &classe.code_classe, classe.nom_classe, classe.niveau_classe);
                                        if(classe.code_classe==code)
                                        {
                                            recois = 1;
                                            break;
                                        }
                                        else {printf("classe introuvable\n"); break;}
                                    } while (!feof(fClasse));
                                    fclose(fClasse);
                                fClasse = fopen("Classe.csv", "r");
                                        if(recois==1)
                                        {
                                            printf("\nentrer le nouveau nom de la classe: ");
                                            scanf("%s",  nom_classe); 
                                            printf("\n entrez le niveau de cette classe: ");
                                            scanf("%s", niveau_classe);
                                            fprintf(ftmp_Classe, "%d ;%s ;%s\n", code, nom_classe, niveau_classe);
                                            printf("modification effectuée avec succées\n");
                                        }
                                        fclose(ftmp_Classe);
                                        fclose(fClasse);
                                        remove("Classe.csv");
                                        rename("classe_tmp.csv", "Classe.csv");
                                printf("----------------------------------------------------------\n");
                            goto menu_classe;
                            
            break;
            case 5: 
                //ici nous créons la fonctionnalitée de supression d'une classe;
                        printf("entrez le code de la classe: ");
                        scanf("%d", &code);
                        fClasse = fopen("Classe.csv", "r");
                        ftmp_Classe = fopen("classe_tmp.csv", "a");
                        if (fClasse != NULL)
                        {
                            if (ftmp_Classe != NULL)
                            {
                                do
                                {
                                    fscanf(fClasse, "%d ;%s ;%s", &classe.code_classe, classe.nom_classe, classe.niveau_classe);
                                    if(classe.code_classe!=code)
                                    {
                                        fprintf(ftmp_Classe, "%ls ;%s ;%s\n", &classe.code_classe, classe.nom_classe, classe.niveau_classe);
                                        break;
                                    }
                                    else{printf("classe introuvable\n"); break;}
                                } while (!feof(fClasse));
                                fclose(ftmp_Classe);
                                fclose(fClasse);
                                remove("Classe.csv");
                                rename("classe_tmp.csv", "Classe.csv"); 
                            }
                            else
                            {
                                printf("Erreur d'ouverture du fichier \n");
                                exit(1);
                            }
                            
                        }
                        printf("Supression effectuer avec succée \n");
                    goto menu_classe;
            break;
            default:
                goto retour_menu;
            break;
        }


                                        //GESTION DES NOTES //
    case 4:
    // ici nous créons la fonctionnalitée de la gestion des notes
    menu_note:
    {
    printf("\n");
    printf("\t\t\t\t\t ********************* GESTION DES NOTES ******************\n");
    printf("\t\t\t\t\t 1- Ajouter une note\n");
    printf("\t\t\t\t\t 2- Modifier une note\n");
    printf("\t\t\t\t\t 3- Supprimer une note\n"); 
    printf("\t\t\t\t\t 4- Consulter une note\n");
    printf("\t\t\t\t\t 5- <--- Précédent\n");
    printf("entrez votre choix\n");
    printf("---------------------------------------\n");
    scanf("%d", &choix1);
    }
    switch(choix1)
    {
        case 1:
            //ici nous créons la fonctionnalitée d'ajout de note
            sous_menu_note:
            {
            printf("\n");
            printf("\t\t\t\t 1- Ajout de note d'un etudiant dans une matière\n"); 
            printf("\t\t\t\t 2- Ajout des notes d'un etudiant dans toutes ses matières\n"); 
            printf("\t\t\t\t 3- Ajout des notes d'une classe dans une matière\n");
            printf("\t\t\t\t 4- <--- Précédent\n");
            printf("\n"); 
            printf("entrer votre choix\n");
            scanf("%d", &choix2);
            printf("-----------------------------------\n"); 
            }
            switch (choix2)
            {
            case 1:
            //ici nous créons la fonctionnalitée qui permet d'ajouter une note à un étudiant dans une matière donnée.
                fEtudiant = fopen("Etudiant.csv", "r");
                fMatiere = fopen("Matieres.csv", "r");
                    do
                    {
                        fscanf(fEtudiant, "%d ;%d ;%s ;%s ;%s ;%d-%d-%d; \n", &etudiant.num_et, &etudiant.code_et, etudiant.nom_et, etudiant.prenom_et, etudiant.email_et, &etudiant.ddn_et.jour, &etudiant.ddn_et.mois, &etudiant.ddn_et.annee );
                        fscanf(fMatiere, "%d, %s, %d", &matiere.reference, matiere.libelle_mat, &matiere.coefficient);
                            printf("entrer le numéro de l'étudiant\n");
                            scanf("%d", &code);
                            printf("entrer la reference de la matière\n");
                            scanf("%d", &code1);
                        if((code==etudiant.num_et)&&(code1==matiere.reference))
                        {
                            fNotes = fopen("Notes.csv", "a");
                            printf("------------------------------------------------\n");
                            printf("entrer la note de l'etudiant en contôle continu\n");
                            scanf("%f", &note.note_cc);
                            printf("entrer la note de l'etudiant en devoir surveillé\n");
                            scanf("%f", &note.note_ds);
                            fprintf(fNotes, "numéro étudiant: %d ;refence matière: %d ;note cc: %f ;note ds: %f \n", code, code1, note.note_cc, note.note_ds);
                            fclose(fNotes);
                            break;
                        }
                        else{printf("Erreur sur le numéro de l'étudiant ou la réfèrence de la matière entré.\n"); break;}
                    }while ((!feof(fEtudiant)) && (!feof(fEtudiant)));
                    fclose(fEtudiant);
                    fclose(fMatiere);
                    printf("---------------------------------------------------------\n");
                    goto sous_menu_note;
                break;
            case 2:
                //ici nous créons la fonctionnalitée qui permet d'ajouter un note à tous les matières faites par un Etudiant;
                printf("enter le numéro de l'etudiant\n");
                scanf("%d", &code);
                printf("Combien de matière est fait par l'etudiant\n");
                scanf("%d", &mat_fait);
                for(int i=0; i<mat_fait; i++)
                {
                    printf("enter la note de controle continu de la matière %d: ", i+1);
                    scanf("%f", &tab_note[i].note_cc);
                    printf("entrer la note de devoir surveillé de la matière %d: ", i+1);
                    scanf("%f", &tab_note[i].note_ds);
                }
                fNotes = fopen("Notes.csv", "a");
                for(int i=0; i<mat_fait; i++)
                {
                    fprintf(fNotes, "Etudiant numéro : %d ;Reference_Matière : %d ;Note CC = %0.2f ;Note DS = %0.2f \n", code, i, tab_note[i].note_cc, tab_note[i].note_ds);
                }
                fclose(fNotes);
                printf(" Note  ajoutées avec succée  \n");
                printf("--------------------------------------------------\n");
            goto sous_menu_note;
            break;
            case 3:
            //ici nous créons la fonctionnalitée qui permet d'ajouter des notes d'une classe dans une matière
                printf("entrer la réference de la matière: ");
                scanf("%d", &matiere.reference);
                printf("Combien d'etudiant fait la classe: ");
                scanf("%d", &tail_classe);
                for(int i=0; i<tail_classe; i++)
                {
                    printf("enter la note de controle continu de l'étudiant %d: ", i+1);
                    scanf("%f", &tab_note[i].note_cc);
                    printf("entrer la note de devoir surveillé de l'étudiant %d: ", i+1);
                    scanf("%f", &tab_note[i].note_ds);  
                }
                fclasse_mat = fopen("Classe_Matiere.csv", "a");
                for(int i=0; i<tail_classe; i++)
                {
                    fprintf(fNotes, "Etudiant : %d ;Réference matière : %d ;Note CC : %0.2f ;Note DS : %0.2f \n", i, matiere.reference, tab_note[i].note_cc, tab_note[i].note_ds);
                }
                fclose(fNotes);
                printf(" Notes  ajoutées avec succée  \n");
                printf("--------------------------------------------------\n");
            goto sous_menu_note;
            break;
            default:
            //ce goto permet de retourner au menu relatif au notes
            goto menu_note;
            break;
        }
        break;
    case 2:
    //cette fonctionnalitée permet de Modifier les notes d'un ou de plusieurs etudiant(s) 
        printf("ERROR cette fonctionnalitée est en construction :) \n");
        goto menu_note;
    break;
    case 3:
    //cette fonctionnalitée permet la suppression d'une ou de plusiuers note(s) d'un ou de plusieurs etudiants(s)
        printf("ERROR cette fonctionnalitée est en construction :) \n");
        goto menu_note;
    break;
    case 4: 
    //cette fonctionnalité permet la consultation d'une ou de plusieurs notes
    sous_menu_consult:
    {
        printf("\n");
        printf("\t\t\t\t 1- Consulter Les Notes d'un Etudiant\n");
        printf("\t\t\t\t 2- Consulter Les Notes d'une classe\n");
        printf("\t\t\t\t 3- <--- Précédent\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix2);
        printf("--------------------------------\n");
    }
        switch (choix2)
        {
        case 1:
            // cette fonctionnalitée permet de consulter les notes d'un etudiant 
            fNotes=fopen("Notes.csv", "r");
            printf("\nListe Des Notes Des Etudiants: \n");
            while(fgets(lecture_note, 200, fNotes)!= NULL)
            {
                printf("%s", lecture_note);
            }
            fclose(fNotes);
            printf("---------------------------------------------\n");
            goto sous_menu_consult;
         break;
        case 2: 
        //cette fonctionnalitée permet de consulter les notes d'une classe
            fclasse_mat = fopen("Classe_Matiere.csv", "r");
            printf("\nLa Liste Des Notes De La Classe: \n");
            while(fgets(lecture_note, 200, fclasse_mat)!= NULL)
            {
                printf("%s", lecture_note);
            }
            fclose(fclasse_mat);
            printf("---------------------------------------------\n");
            goto sous_menu_consult;
        break;
        default:
            goto menu_note;
            break;
        }
    break;
    default:
        goto retour_menu;
        break;
    }
    default:
        printf("merci d'etre passer\n");
        break;            
    }
    return 0;
}

