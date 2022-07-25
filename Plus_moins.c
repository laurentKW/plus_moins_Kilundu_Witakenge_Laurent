#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int i,j,nombreEntrer,choix,mode;
int compteur1=25,compteur2=10,compteur3=100000;
int choix,coup,joueur1,joueur2,score=0,tour;

int player2()
{
    printf("Mode 2 joueurs\n");
    joueur1=1;
    joueur2=2;
    printf("   Le nombre de tour que vous souhaitez jouer : ");
    scanf("%d",&tour);
    for (j=1;j<tour+1;j++)
    {
        printf("\n    Joueur  n_0%d est maitre de jeux, veuillez precisez le nombre de tentative(s) : ",joueur1);
    	scanf("%d",&coup);
    	printf("  Joueur n_0%d, quel est votre choix: ",joueur2);
    	scanf("%d",&choix);
    	int compteur=coup;
    	for (i=0;i<coup;i++)
        {
                compteur--;
                if (nombreEntrer < choix)
        		{
        		    printf("   Moins\n");
        		    printf("   Il vous reste %d tentative(s)\n\n",compteur);
        		}
        		else if (nombreEntrer > choix)
       			{
       			    printf("   Plus\n");
        		    printf("   Il vous reste %d tentative(s)\n\n",compteur);
        		}
        		score=coup-i;
    			if(compteur==0)
    		    {
        		    printf("   Le joueur n_0%d a obtenu une score de  %d point(s)\n",joueur2,score);
        		    int temp=joueur1;
        		    joueur1=joueur2;
        		    joueur2=temp;
        		    srand(time(NULL));
    			    nombreEntrer=rand()%100;
    			    printf("%d",nombreEntrer);
    			    exit(0);
        		    break;
        		}
    			if (nombreEntrer == choix)
    		    {
        		    printf("   Bingo \n\n");
        		    printf("    Le joueur n_0%d, a obtenu une score  %d point(s)\n\n",joueur2,score);
        		    int temp=joueur1;
        		    joueur1=joueur2;
            		    joueur2=temp;
            		    srand(time(NULL));
   		            nombreEntrer=rand()%100;
       				break;
        		}
        	    printf("   Choisir un autre chiffre: ");
   				 scanf("%d",&choix);
        }
    }
}


int plus_moins(int nombreEntrer_a_trouver, int choix_joueur,char mode)
{

     switch (mode)
    {
        case 1:
        {
            for (i=1;i<50;i++)
            {
                compteur3--;

                if (nombreEntrer_a_trouver < choix_joueur)
                {
                    printf("   Moins\n\n");
                }
                else if (nombreEntrer_a_trouver > choix_joueur)
                {
                    printf("   Plus\n\n");
                }
                if(nombreEntrer_a_trouver == choix_joueur)
                {
                   printf("   Bingo!\n\n");
                   exit(1);
                }
               printf("   Entrer un autre chiffre: ");
               scanf("%d",&choix_joueur);
            }
        }
    }
     switch (mode)
    {
        case 2:
        {
            for (i=1;i<26;i++)
            {
                compteur1--;

                if (nombreEntrer_a_trouver < choix_joueur)
                {
                    printf("   Il vous reste  %d tentative(s)\n",compteur1);
                    printf("   Moins\n\n");
                }
                else if (nombreEntrer_a_trouver > choix_joueur)
                {
                    printf("   Il vous reste  %d tentative(s)\n",compteur1);
                    printf("   Plus\n\n");
                }
                if(nombreEntrer_a_trouver == choix_joueur)
                {
                   printf("   Bingo!\n\n");
                   exit(1);
                }
               printf("   Entrer un autre chiffre: ");
               scanf("%d",&choix_joueur);
            }
        }
    }
       switch (mode)
    {
        case 3:
        {
            for (i=1;i<11;i++)
            {
                compteur2--;

                if (nombreEntrer_a_trouver < choix_joueur)
                    {
                        printf("   Il vous reste %d essaie(s) \n",compteur2);
                        printf("   Moins\n\n");
                    }
                else if (nombreEntrer_a_trouver > choix_joueur)
                {
                    printf("   Il vous reste %d essaie(s) \n",compteur2);
                   printf("   Plus\n\n");
                }
                if(nombreEntrer_a_trouver == choix_joueur)
                {
                   printf("   Bingo!\n\n");
                   exit(1);
                }
                printf("   Saisissez un autre chiffre: ");
                scanf("%d",&choix_joueur);
            }
	}	
    }
}
void chiffre()
{
    printf("Mode  joueur unique");
    printf("\n   Choisissez un chiffre : ");
    scanf("%d",&choix); 
    plus_moins(nombreEntrer,choix,mode);
}

void mod()
{
    srand(time(NULL));
    nombreEntrer=rand()%100;
    printf("   Mission de mode \n");
    printf(" 1/ Facile     2/Moyen    3/ Difficile\n\n");
    printf("   Choisissez le mode:  ");
    scanf("%d",&mode);
    if (mode==1 || mode==2 || mode==3)
    {

        chiffre();
    }
    else 
    {
    	printf("  Erreur, veuillez selectionner l'une des 3 alternatives \n\n");
    	mod();
	} 
}


int main()
{
    int joueur;
    printf("\n\n  PLUS_OU_MOINS /n");
    printf("  1/ 1 joueur     2/ 2 joueurs\n\n");
    printf("   Indiquez votre choix : ");
    scanf("%d",&joueur);
    if (joueur==1)
    { 
       mod(); 
    }
    if (joueur==2)
    {
    	player2();
	}
    else 
    {
    	printf("   Erreur, choisissez l'une des deux options \n\n");
        main();
    }
}
