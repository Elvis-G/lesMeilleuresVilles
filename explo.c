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
};

// started from the bottom now we here #coffre
char coffre[15];
char ville1[15] = "Jogo";
char ville2[15] = "Vinel";

int main (){


  printf("\n%s\n", "                            _____________________________________________________________ ");
  printf("%s\n", "                           |                                                             |");
  printf("%s\n", "                           |                         CHOIX DES VILLES                    |");
  printf("%s\n\n", "                           |_____________________________________________________________|");


/* printf("\n%s\n", "Un panneau indiquant deux noms de villes est en face, de vous, l'un indiquant Jogo, l'autre Vinel");
printf("\n%s\n", "Dans quel lieu souhaitez-vous aller : [0] pour Jogo ; [1] pour Vinel");
printf("Votre choix : ");
SetColor (3);
scanf("%d", &coffre);
SetColor (15);

if (coffre == 0) {
  printf("\n%s\n", "Vous avez decider de vous rendre a Jogo");
  Sleep(2000);
} else if (coffre == 1) {
printf("\n%s\n", "Vous avez decider de vous rendre a Vinel");
Sleep(2000);
} */

printf("\n%s\n", "Un panneau indiquant deux noms de villes est en face, de vous, l'un indiquant Jogo, l'autre Vinel");
printf("\n%s\n", "Dans quel lieu souhaitez-vous aller : [Jogo] ; [Vinel]");
printf("Votre choix : ");
SetColor (3);
scanf("%s", &coffre);
SetColor (15);

if (strcmp(ville1, coffre) == 0) {
  printf("\nVous avez decider de vous rendre a Jogo\n");
  Sleep(2000);
} else if (strcmp(ville2, coffre) == 0) {
printf("\nVous avez decider de vous rendre a Vinel\n");
Sleep(2000);
}

return 0;
}
