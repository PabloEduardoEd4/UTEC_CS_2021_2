//pyhsics.hpp

#ifndef pyh
#define pyh

const double gravity_constant =  .00000000006674;

const double force_grav(double mass_1, double mass_2, double distance){
    return gravity_constant*mass_1*mass_2/(distance*distance);
}
const double accleration(double force, double mass){
    return force/mass;
}


#endif