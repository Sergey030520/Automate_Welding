//
// Created by Malip on 14.12.2022.
//

#ifndef AUTOMATE_WELDING_PROGRAM_FSM_WELDING_H
#define AUTOMATE_WELDING_PROGRAM_FSM_WELDING_H

#if defined(__cplusplus)
extern "C" {
#endif

enum InputSignal{
    WELDING_OFF = 0,
    WELDING_ON = 1
};

enum AutomateState{
    AUTOMATE_OFF = 0, /*Автомат выключен*/
    AUTOMATE_T_N,/*Насыщение*/
    AUTOMATE_WELDING_ON,/*Сварка*/
    AUTOMATE_T_C, /*Спад*/
    AUTOMATE_COMPLETE
};
struct Automate{
    enum AutomateState state;
    int timer_tick;/*Внутренний счётчик*/
    int time_n;/*Время насыщения*/
    int time_c; /*Время спада*/
    double value;/*Значение параметра SimInTech*/
};



enum AutomateParameter {
    AUTOMATE_I = 0,/*Ток сварки*/
    AUTOMATE_U, /*Напряжение дуги*/
    AUTOMATE_V,/*Скорости подачи проволоки*/
    AUTOMATE_COUNT
};

enum EngineState{
    ENGINE_WELDING_OFF = 0,
    ENGINE_WELDING_GAS_ON,
    ENGINE_WELDING_RUN_AUTOMATE,
    ENGINE_WELDING_RUNNING,
    ENGINE_WELDING_COMPLETE_AUTOMATE,
    ENGINE_WELDING_GAS_STABLE,
    ENGINE_WELDING_GAS_OFF,
    ENGINE_WELDING_COMPLETE
};

struct Engine {
    enum EngineState state;
    int timer_tick;/*Внутренний счётчик*/
    int time_n;/*Время насыщения, газ*/
    int time_g;/*Время окончательной подачи газа*/
    int time_c; /*Время спада, газ*/
    struct Automate automate[3];
    double value; /*Расход газа*/
};

void engine_init(struct Engine* engine);
void engine_tick(struct Engine* engine, enum InputSignal signal);
void engine_reset(struct Engine* engine);

#if defined(__cplusplus)
}
#endif

#endif //AUTOMATE_WELDING_PROGRAM_FSM_WELDING_H
