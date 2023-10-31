
#ifndef OOPCPP_EFFECT_H
#define OOPCPP_EFFECT_H

enum EffectType {
    Slowness,
    Fatigue,
    Poison /* ,
    ...
    */
};

class Effect {
protected:
    const EffectType effectType;
public:
    void dealEffect(Enemy *enemy);
};

#endif //OOPCPP_EFFECT_H
