#include <memory>

#include "game/game.h"
#include "strategies/human.h"
#include "strategies/computer_first_strategy.h"
#include "strategies/computer_second_strategy.h"


int main() {

    auto player2 = std::make_shared<computer_strategy_t_1>("Second player");

    auto player1 = std::make_shared<computer_strategy_t_2>("First player");
//    auto player2 = std::make_shared<human_strategy_t>("Second player");
//
    for(int i = 0; i<1000; i++){
        game_t game(player1, player2);
        game.play();
    }

    player1->print_stat();
    player2->print_stat();
    return 0;
}