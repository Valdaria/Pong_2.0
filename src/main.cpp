#include "Game.h"
#include <ctime>
#include <stdlib.h>

int main(){
    Game game(1280,720, "Pong v2 - Snailing Labs");
    srand(time(0));
    return 0;
}
