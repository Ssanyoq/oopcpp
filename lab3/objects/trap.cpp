#include "trap.h"
#include "../utility/functions.h"

void Trap::dealEffect(std::vector<Entity> entities) {
    if (cooldown != 0) {
        return;
    }
}

void Trap::doAction(vector<Entity> &entities) {
    dealEffect(std::vector<Entity>());
}
