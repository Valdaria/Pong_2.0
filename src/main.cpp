#include "Game.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    Game game(1280,720, "Pong v2 - Snailing Labs");
    srand(time(NULL));
    return 0;
}
