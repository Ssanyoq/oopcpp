#ifndef OOPCPP_TRAP_H
#define OOPCPP_TRAP_H

#include "defence.h"
#include "../effects/effect.h"

class Trap: public Defence {
protected:
    Effect effect;
    unsigned maxAmtOfEnemies;
public:
    void dealEffect();
};
#endif //OOPCPP_TRAP_H
