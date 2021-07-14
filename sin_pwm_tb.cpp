#include <iostream>
#include <verilated.h>
#include "Vsin_pwm.h"

int main(int argc, char *argv[]){
    Verilated::commandArgs(argc, argv);

    Vsin_pwm *sim = new Vsin_pwm();

    for(int i = 0; i <= 180; i++){
        sim->theta = i;
        sim->eval();
        printf("%d : %d\n", i, sim->duty);
    }
    sim->final();
    return 0;
}
