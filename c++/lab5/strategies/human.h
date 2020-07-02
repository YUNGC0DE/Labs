#pragma once
#include "interface.h"

class human_strategy_t : public strategy_interface_t {
public:
    human_strategy_t(std::string name);

    step_t make_first_step(const field_t &fld) override;

    void on_incorrect_step(const step_t &step) const override;

    void on_win() override;

    void on_lose() override;

    void on_tie() override;

    step_t make_next_step(const field_t &fld, std::pair<size_t, size_t> current_checker) override;

    bool check_attack(const field_t &field, std::set<std::pair<int, int>> &attack_checker) override;

private:
    std::string name;
};
