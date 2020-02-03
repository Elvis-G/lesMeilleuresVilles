#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void SetColor(int ForgC) {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

// Strcuture lieux
typedef struct Lieux lieux_t;
struct Lieux
{
  char nom[20];
  char description[300];
  int difficulte;
  int tableauID;

};

// started from the bottom now we here #coffre
char coffre[15];
int coffreID;
int coffrePosteRepos;
int jeu = 0;
int stamina = 100;
int staminaMax = 100;

int main (){


// NOM des villes
lieux_t ville1 = {"Jogo", "Capitale du monde de Sealed D., elle est considere comme la ville ou tout aventurier y commence son aventure", 1, 0};
lieux_t ville2 = {"Vinel", "Ville cotiere et la plus proche de Jogo, elle est populaire pour son commerce et terrestre et maritime ainsi que pour les quetes un peu plus hardu que Jogo", 3, 1};
lieux_t ville3 = {"Bossel", "Ville fantome ou quasi aucun aventuriers n'ose s'y aventurer au vu du nombre de creatures gargantuesque et leurs niveaux faramineux", 18, 2};
lieux_t ville4 = {"Bann", "C'est la plus grande cite de Sealed D., son marche, ses universites, ses arenes ou encore ses residences sont toutes exceptionnelles. Les monstres aux alentours sont souvent attirer par les bruits faisant l'objet de quete pour les joueurs.", 5, 3};
lieux_t ville5 = {"Katri", "Assez grand village se trouvant a la bordure des terres sauvages, ou les immondes creatures y sont massivement presentes", 6, 4};
lieux_t ville6 = {"Zela", "Premiere ville en dehors des frontieres securise de Sealed D., c'est malheureusement dans ses alentours que bon nombre d'aventuriers viennent y laisser leur vie", 9, 5};
lieux_t ville7 = {"Ragt", "Peu de personnes peuvent se venter de revenir vivant de Ragt, les monstres y sont feroces et il residerait dans ses lieux un demon aux capacites pouvant faire trembler n'importe quel heros", 12, 6};

// NOM DU MONDE
  printf("\n%s\n", "                            _____________________________________________________________ ");
  printf("%s\n", "                           |                                                             |");
  printf("%s\n", "                           |                             SEALED D                        |");
  printf("%s\n\n", "                           |_____________________________________________________________|");


// INTRODUCTION
SetColor (8);
printf("\n%s\n", "Un panneau indiquant un nom de ville est en face de vous indiquant Jogo");
printf("\nEntrez le nom de la ville pour vous y diriger : [%s]\n", ville1.nom);
printf("Votre choix : ");
SetColor (3);
scanf("%s", &coffre);
SetColor (15);

while (strcmp(ville1.nom, coffre) != 0) {
  printf("\nVous avez peut-etre fait une faute concernant le nom de la ville, ressayez\n");
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
Sleep(2000);
}
SetColor (8);
if (strcmp(ville1.nom, coffre) == 0) {
  printf("\nVous avez decider de vous rendre a Jogo\n");
  coffreID = ville1.tableauID;
  Sleep(2000);
}
SetColor (15);

while (jeu == 0){


// VILLE 1
if (strcmp(ville1.nom, coffre) == 0 && stamina >= ville1.difficulte || strcmp(ville1.nom, coffre) == 0 && coffreID == ville2.tableauID && stamina >= ville2.difficulte || strcmp(ville1.nom, coffre) == 0 && coffreID == ville4.tableauID && stamina >= ville4.difficulte){
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
    coffreID = ville1.tableauID;
printf("\n%s\n", "Vous etes arrive dans la ville de Jogo");
printf("\n%s\n", ville1.description);
stamina = stamina - ville1.difficulte;
// Mecanique REPOS
if (ville1.difficulte < 5)
printf("\nSouhaitez-vous vous reposez afin de recuperer de l'endurance ? Si oui entrer [0], si non entrer [1]\n", ville2.nom);
SetColor (3);
scanf("%d", &coffrePosteRepos);
SetColor (8);
  if (coffrePosteRepos == 0) {
    printf("\nVous avez decider de vous reposez\n");
    stamina = stamina + 50;
    if (stamina > staminaMax) {
      stamina = 100;
    }
  } else {
    printf("\nVous avez decider de ne pas vous reposez\n");
  }
printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville2.nom, ville4.nom);
SetColor (3);
scanf("%s", &coffre);
SetColor (8);
  while (strcmp(ville2.nom, coffre) != 0 && strcmp(ville4.nom, coffre) != 0) {
    SetColor (8);
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (8);
  Sleep(2000);
  }
  if (strcmp(ville2.nom, coffre) == 0 && stamina >= ville2.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville2.nom);
    Sleep(2000);
  } else if (strcmp(ville4.nom, coffre) == 0 && stamina >= ville4.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  } 
SetColor (15);
}


// VILLE 2
if (strcmp(ville2.nom, coffre) == 0 && coffreID == ville1.tableauID && stamina >= ville2.difficulte || strcmp(ville2.nom, coffre) == 0 && coffreID == ville4.tableauID && stamina >= ville4.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville2.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Vinel");
  printf("\n%s\n", ville2.description);
  stamina = stamina - ville2.difficulte;
  if (ville2.difficulte < 5)
  printf("\nSouhaitez-vous vous reposez afin de recuperer de l'endurance ? Si oui entrer [0], si non entrer [1]\n", ville2.nom);
  SetColor (3);
  scanf("%d", &coffrePosteRepos);
  SetColor (8);
    if (coffrePosteRepos == 0) {
      printf("\nVous avez decider de vous reposez\n");
      stamina = stamina + 50;
      if (stamina > staminaMax) {
        stamina = 100;
      }
    } else {
      printf("\nVous avez decider de ne pas vous reposez\n");
    }
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville1.nom, ville4.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville1.nom, coffre) != 0 && strcmp(ville4.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (8);
  Sleep(2000);
  }
  if (strcmp(ville1.nom, coffre) == 0 && stamina >= ville1.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville1.nom);
    Sleep(2000);
  } else if (strcmp(ville4.nom, coffre) == 0 && stamina >= ville4.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 3
if (strcmp(ville3.nom, coffre) == 0 && coffreID == ville7.tableauID && stamina >= ville7.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville3.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Bossel");
  printf("\n%s\n", ville3.description);
// Mécanique Avant-Poste
  if (ville3.difficulte > 10)
  printf("\nSouhaitez-vous etablir un avant-poste dans %s (Le coût d'un avant-poste est de 15 d'endurance) ? Si oui entrer [0], si non entrer [1]\n", ville3.nom);
  SetColor (3);
  scanf("%d", &coffrePosteRepos);
  SetColor (8);
    if (coffrePosteRepos == 0) {
      printf("\nVous avez decider de construire un avant poste dans %s\n", ville3.nom);
      ville3.description == "Peu de personnes peuvent se venter de revenir vivant de Ragt, les monstres y sont feroces et il residerait dans ses lieux un demon aux capacites pouvant faire trembler n'importe quel heros. Un avant-poste est construit dans cette ville";
      ville3.difficulte = ville3.difficulte/2;
      stamina = stamina - 15;
    } else {
      printf("\nVous avez decider de ne pas construire d'Avant poste dans %s\n", ville3.nom);
    }
  stamina = stamina - ville3.difficulte;
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s]\n", ville7.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville7.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
  if (strcmp(ville7.nom, coffre) == 0 && stamina >= ville7.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville7.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 4
if (strcmp(ville4.nom, coffre) == 0 && coffreID == ville1.tableauID  && stamina >= ville1.difficulte || strcmp(ville4.nom, coffre) == 0 && coffreID == ville2.tableauID  && stamina >= ville2.difficulte || strcmp(ville4.nom, coffre) == 0 && coffreID == ville5.tableauID && stamina >= ville5.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville4.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Bann");
  printf("\n%s\n", ville4.description);
  stamina = stamina - ville4.difficulte;
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s] ; [%s]\n", ville1.nom, ville2.nom, ville5.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville1.nom, coffre) != 0 && strcmp(ville2.nom, coffre) != 0 && strcmp(ville5.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
  if (strcmp(ville1.nom, coffre) == 0 && stamina >= ville1.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville1.nom);
    Sleep(2000);
  } else if (strcmp(ville2.nom, coffre) == 0 && stamina >= ville2.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville2.nom);
    Sleep(2000);
  } else if (strcmp(ville5.nom, coffre) == 0 && stamina >= ville5.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville5.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 5
if (strcmp(ville5.nom, coffre) == 0 && coffreID == ville4.tableauID && stamina >= ville4.difficulte || strcmp(ville5.nom, coffre) == 0 && coffreID == ville6.tableauID && stamina >= ville6.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville5.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Katri");
  printf("\n%s\n", ville5.description);
  stamina = stamina - ville5.difficulte;
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville4.nom, ville6.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville4.nom, coffre) != 0 && strcmp(ville6.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
  if (strcmp(ville4.nom, coffre) == 0 && stamina >= ville4.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  } else if (strcmp(ville6.nom, coffre) == 0 && stamina >= ville6.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville6.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 6
if (strcmp(ville6.nom, coffre) == 0 && coffreID == ville5.tableauID && stamina >= ville5.difficulte || strcmp(ville6.nom, coffre) == 0 && coffreID == ville7.tableauID && stamina >= ville7.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville6.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Zela");
  printf("\n%s\n", ville6.description);
  stamina = stamina - ville6.difficulte;
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville5.nom, ville7.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville6.nom, coffre) != 0 && strcmp(ville7.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
SetColor(8);
  if (strcmp(ville6.nom, coffre) == 0 && stamina >= ville5.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville5.nom);
    Sleep(2000);
  } else if (strcmp(ville7.nom, coffre) == 0 && stamina >= ville7.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville7.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 7
if (strcmp(ville7.nom, coffre) == 0 && coffreID == ville6.tableauID && stamina >= ville6.difficulte || strcmp(ville7.nom, coffre) == 0 && coffreID == ville3.tableauID && stamina >= ville3.difficulte) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (3);
printf("\nVotre STAMINA : %d/%d\n", stamina, staminaMax);
SetColor (8);
  coffreID = ville7.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Ragt");
  printf("\n%s\n", ville7.description);
  if (ville7.difficulte > 10)
  printf("\nSouhaitez-vous etablir un avant-poste dans %s (Le coût d'un avant-poste est de 15 d'endurance) ? Si oui entrer [0], si non entrer [1]\n", ville7.nom);
  SetColor (3);
  scanf("%d", &coffrePosteRepos);
  SetColor (8);
    if (coffrePosteRepos == 0) {
      printf("\nVous avez decider de construire un avant poste dans %s\n", ville7.nom);
      ville7.description == "Peu de personnes peuvent se venter de revenir vivant de Ragt, les monstres y sont feroces et il residerait dans ses lieux un demon aux capacites pouvant faire trembler n'importe quel heros. Un avant-poste est construit dans cette ville";
      ville7.difficulte = ville7.difficulte/2;
      stamina = stamina - 15;
    } else {
      printf("\nVous avez decider de ne pas construire d'Avant poste dans %s\n", ville7.nom);
    }
  stamina = stamina - ville7.difficulte;
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville3.nom, ville6.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville6.nom, coffre) != 0 && strcmp(ville3.nom, coffre) != 0) {
    SetColor (8);
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
  if (strcmp(ville6.nom, coffre) == 0 && stamina >= ville6.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville6.nom);
    Sleep(2000);
  } else if (strcmp(ville3.nom, coffre) == 0 && stamina >= ville3.difficulte) {
    printf("\nVous avez decider de vous rendre a %s\n", ville3.nom);
    Sleep(2000);
  }
}
SetColor (15);

}

return 0;
}
