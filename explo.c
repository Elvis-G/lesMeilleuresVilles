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
int jeu = 0;

int main (){

lieux_t ville1 = {"Jogo", "Capitale du monde de Sealed D., elle est considere comme la ville ou tout aventurier y commence son aventure", 1, 0};
lieux_t ville2 = {"Vinel", "Ville cotiere et la plus proche de Jogo, elle est populaire pour son commerce et terrestre et maritime ainsi que pour les quetes un peu plus hardu que Jogo", 3, 1};
lieux_t ville3 = {"Bossel", "Ville fantome ou quasi aucun aventuriers n'ose s'y aventurer au vu du nombre de creatures gargantuesque et leurs niveaux faramineux", 18, 2};
lieux_t ville4 = {"Bann", "C'est la plus grande cite de Sealed D., son marche, ses universites, ses arenes ou encore ses residences sont toutes exceptionnelles. Les monstres aux alentours sont souvent attirer par les bruits faisant l'objet de quete pour les joueurs.", 5, 3};
lieux_t ville5 = {"Katri", "Assez grand village se trouvant a la bordure des terres sauvages, ou les immondes creatures y sont massivement presentes", 6, 4};
lieux_t ville6 = {"Zela", "Premiere ville en dehors des frontieres securise de Sealed D., c'est malheureusement dans ses alentours que bon nombre d'aventuriers viennent y laisser leur vie", 9, 5};
lieux_t ville7 = {"Ragt", "Peu de personnes peuvent se venter de revenir vivant de Ragt, les monstres y sont feroces et il residerait dans ses lieux un demon aux capacites pouvant faire trembler n'importe quel heros", 12, 6};


  printf("\n%s\n", "                            _____________________________________________________________ ");
  printf("%s\n", "                           |                                                             |");
  printf("%s\n", "                           |                             SEALED D                        |");
  printf("%s\n\n", "                           |_____________________________________________________________|");


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
if (strcmp(ville1.nom, coffre) == 0 || strcmp(ville1.nom, coffre) == 0 && coffreID == ville2.tableauID || strcmp(ville1.nom, coffre) == 0 && coffreID == ville4.tableauID){
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
    coffreID = ville1.tableauID;
printf("\n%s\n", "Vous etes arrive dans la ville de Jogo");
printf("\n%s\n", ville1.description);
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
  if (strcmp(ville2.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville2.nom);
    Sleep(2000);
  } else if (strcmp(ville4.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 2
if (strcmp(ville2.nom, coffre) == 0 && coffreID == ville1.tableauID || strcmp(ville2.nom, coffre) == 0 && coffreID == ville4.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville2.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Vinel");
  printf("\n%s\n", ville2.description);
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
  if (strcmp(ville1.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville1.nom);
    Sleep(2000);
  } else if (strcmp(ville4.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 3
if (strcmp(ville3.nom, coffre) == 0 && coffreID == ville7.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville3.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Bossel");
  printf("\n%s\n", ville3.description);
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
  if (strcmp(ville7.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville7.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 4
if (strcmp(ville4.nom, coffre) == 0 && coffreID == ville1.tableauID || strcmp(ville4.nom, coffre) == 0 && coffreID == ville2.tableauID || strcmp(ville4.nom, coffre) == 0 && coffreID == ville5.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville4.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Bann");
  printf("\n%s\n", ville4.description);
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
  if (strcmp(ville1.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville1.nom);
    Sleep(2000);
  } else if (strcmp(ville2.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville2.nom);
    Sleep(2000);
  } else if (strcmp(ville5.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville5.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 5
if (strcmp(ville5.nom, coffre) == 0 && coffreID == ville4.tableauID || strcmp(ville5.nom, coffre) == 0 && coffreID == ville6.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville5.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Katri");
  printf("\n%s\n", ville5.description);
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
  if (strcmp(ville4.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville4.nom);
    Sleep(2000);
  } else if (strcmp(ville6.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville6.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 6
if (strcmp(ville6.nom, coffre) == 0 && coffreID == ville5.tableauID || strcmp(ville6.nom, coffre) == 0 && coffreID == ville7.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville6.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Zela");
  printf("\n%s\n", ville6.description);
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
  if (strcmp(ville6.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville6.nom);
    Sleep(2000);
  } else if (strcmp(ville7.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville7.nom);
    Sleep(2000);
  }
SetColor (15);
}


// VILLE 7
if (strcmp(ville7.nom, coffre) == 0 && coffreID == ville6.tableauID || strcmp(ville7.nom, coffre) == 0 && coffreID == ville3.tableauID) {
printf("\n%s\n", "----------------------------------------------------------------------------------");
SetColor (8);
  coffreID = ville7.tableauID;
  printf("\n%s\n", "Vous etes arrive dans la ville de Ragt");
  printf("\n%s\n", ville7.description);
  printf("\nSi vous ne souhaitez pas rester, choissisez votre prochaine destination : [%s] ; [%s]\n", ville3.nom, ville6.nom);
  SetColor (3);
  scanf("%s", &coffre);
  SetColor (8);
  while (strcmp(ville7.nom, coffre) != 0 && strcmp(ville3.nom, coffre) != 0) {
    printf("\nVous avez peut-etre fait une faute concernant le nom de la ville ou vous avez entre une ville trop eloigne de votre lieu actuel\n");
    SetColor (3);
    scanf("%s", &coffre);
    SetColor (15);
  Sleep(2000);
  }
  if (strcmp(ville7.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville7.nom);
    Sleep(2000);
  } else if (strcmp(ville3.nom, coffre) == 0) {
    printf("\nVous avez decider de vous rendre a %s\n", ville3.nom);
    Sleep(2000);
  }
}
SetColor (15);

}

return 0;
}
