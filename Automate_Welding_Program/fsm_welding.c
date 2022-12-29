//
// Created by Malip on 14.12.2022.
//

#include "fsm_welding.h"
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>


#define TIME_DELTA(time) ((time)*10)


void engine_init(struct Engine *engine) {
    if(engine != 0) {
        engine_reset(engine);
    }
}

static void automate_tick(struct Automate* automate, enum InputSignal signal){
    switch (automate->state) {
        case AUTOMATE_OFF: {
            if (signal == WELDING_ON) {
                automate->state = AUTOMATE_T_N;
                automate->timer_tick = 0;
            }
            break;
        }
        case AUTOMATE_T_N:  {
            if(signal == WELDING_ON){
                automate->timer_tick++;
                if(automate->timer_tick >= automate->time_n){
                    automate->state = AUTOMATE_WELDING_ON;
                }else{
                    automate->value++;
                }
            }else{
                automate->state = AUTOMATE_T_C;
                automate->timer_tick = 0;
            }
            break;
        }
        case AUTOMATE_WELDING_ON:{
            if(signal == WELDING_ON){
                automate->state = AUTOMATE_WELDING_ON;
            }else{
                automate->state = AUTOMATE_T_C;
                automate->timer_tick = 0;
            }
            break;
        }
        case AUTOMATE_T_C: {
            automate->timer_tick++;
            if(automate->timer_tick >= automate->time_c || automate->value == 0){
                automate->state = AUTOMATE_COMPLETE;
            }else{
                automate->value--;
            }
            break;
        }
        case AUTOMATE_COMPLETE: {
            break;
        }
    }
}

void engine_tick(struct Engine *engine, enum InputSignal signal) {
    switch (engine->state) {
        case ENGINE_WELDING_OFF: {
            if(signal == WELDING_ON){
                engine->state = ENGINE_WELDING_GAS_ON;
                engine->timer_tick = 0;
            }else{
                engine->state = ENGINE_WELDING_OFF;
            }
            break;
        }
        case ENGINE_WELDING_GAS_ON: {
            if(signal == WELDING_ON){
                engine->timer_tick++;
                if(engine->timer_tick >= engine->time_n){
                    engine->state = ENGINE_WELDING_RUN_AUTOMATE;
                    engine->timer_tick = 0;
                }else{
                    engine->value++;
                }
            }else{
                engine->state = ENGINE_WELDING_GAS_STABLE;
                engine->timer_tick = 0;
            }
            break;
        }
        case ENGINE_WELDING_RUN_AUTOMATE: {
            if(signal == WELDING_ON){
                bool welding = true;
                for(int indAutomate = 0; indAutomate < AUTOMATE_COUNT; ++indAutomate){
                    automate_tick(&engine->automate[indAutomate], signal);
                    welding = welding && (engine->automate[indAutomate].state == AUTOMATE_WELDING_ON);
                }
                if(welding){
                    engine->state = ENGINE_WELDING_RUNNING;
                }else{
                    engine->state = ENGINE_WELDING_RUN_AUTOMATE;
                }
            }else{
                engine->state = ENGINE_WELDING_COMPLETE_AUTOMATE;
                engine->timer_tick = 0;
            }
            break;
        }
        case ENGINE_WELDING_RUNNING: {
            if(signal == WELDING_OFF){
                engine->state = ENGINE_WELDING_COMPLETE_AUTOMATE;
            }
            break;
        }
        case ENGINE_WELDING_COMPLETE_AUTOMATE: {
            bool complete = true;
            for(int ind = 0; ind < AUTOMATE_COUNT; ++ind){
                automate_tick(&engine->automate[ind], signal);
                complete = complete && (engine->automate[ind].state == AUTOMATE_COMPLETE);
            }
            if(complete){
                engine->state = ENGINE_WELDING_GAS_STABLE;
                engine->timer_tick = 0;
            }

            break;
        }
        case ENGINE_WELDING_GAS_STABLE: {
            engine->timer_tick++;
            if(engine->timer_tick >= engine->time_g){
                engine->state = ENGINE_WELDING_GAS_OFF;
                engine->timer_tick = 0;
            }
            break;
        }
        case ENGINE_WELDING_GAS_OFF: {
            engine->timer_tick++;
            if(engine->timer_tick >= engine->time_c || engine->value == 0){
                engine->state = ENGINE_WELDING_COMPLETE;
                engine->timer_tick = 0;
            }else{
                engine->value--;
            }
            break;
        }
        case ENGINE_WELDING_COMPLETE: {
            if(signal == WELDING_ON){
                for(int indAutomate = 0; indAutomate < AUTOMATE_COUNT; ++indAutomate) {
                    engine->automate[indAutomate].state = AUTOMATE_OFF;
                }
                engine->state = ENGINE_WELDING_OFF;
            }
            engine->timer_tick = 0;
            break;
        }
    }
}

void engine_reset(struct Engine *engine) {
    engine->state = ENGINE_WELDING_OFF;
    engine->timer_tick = 0;
    engine->time_n = TIME_DELTA(7);
    engine->time_c = TIME_DELTA(7);
    engine->time_g = TIME_DELTA(7);

    engine->automate[AUTOMATE_I].state = AUTOMATE_OFF;
    engine->automate[AUTOMATE_I].timer_tick = 0;
    engine->automate[AUTOMATE_I].time_n = TIME_DELTA(8);
    engine->automate[AUTOMATE_I].time_c = TIME_DELTA(8);
    engine->automate[AUTOMATE_I].value = 0;

    engine->automate[AUTOMATE_U].state = AUTOMATE_OFF;
    engine->automate[AUTOMATE_U].timer_tick = 0;
    engine->automate[AUTOMATE_U].time_n = TIME_DELTA(5);
    engine->automate[AUTOMATE_U].time_c = TIME_DELTA(5);
    engine->automate[AUTOMATE_U].value = 0;

    engine->automate[AUTOMATE_V].state = AUTOMATE_OFF;
    engine->automate[AUTOMATE_V].timer_tick = 0;
    engine->automate[AUTOMATE_V].time_n = TIME_DELTA(3);
    engine->automate[AUTOMATE_V].time_c = TIME_DELTA(3);
    engine->automate[AUTOMATE_V].value = 0;
}