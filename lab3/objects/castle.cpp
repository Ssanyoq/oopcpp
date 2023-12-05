#include "castle.h"

void Castle::receiveDamage(int amount) {
    if (amount >= hp) {
        hp = 0;
    } else {
        hp -= amount;
    }
}

bool Castle::isDead() const {
    return hp <= 0;
}