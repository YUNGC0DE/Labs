#include <memory>

#include "game/game.h"
#include "strategies/human.h"
#include "strategies/computer_first_strategy.h"
#include "strategies/computer_second_strategy.h"


int main() {

    auto player2 = std::make_shared<human_strategy_t>("Second player");

    auto player1 = std::make_shared<human_strategy_t>("First player");
//    auto player2 = std::make_shared<human_strategy_t>("Second player");
//

    game_t game(player1, player2);
    game.play();
    return 0;
}