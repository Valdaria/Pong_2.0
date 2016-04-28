#include "Game.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    srand(time(NULL));
    Game game(1280,720, "Pong v2 - Snailing Labs");
    return 0;
}
