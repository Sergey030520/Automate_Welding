
/*  ------------------------------------------------------
     Routine name:  AutomateWelding
     Description:   
     Project file:  model_automate_welding.prt

------------------------------------------------------  */

/*  --- Base generator data types --- */
/* Real data type */
typedef double g_real_type;
/* Integer data type */
typedef int g_int_type;
/* Boolean data type */
typedef char g_boolean_type;
/* Complex data type */
typedef complex_64 g_complex_type;


/* Default initialization values */
const double out_0_default=0;
const double out_1_default=0;
const double out_2_default=0;
const double out_3_default=0;
const char input_0_default=0;
const double automateweldingv1_out_0_default=0;
const double automateweldingv1_out_1_default=0;
const double automateweldingv1_out_2_default=0;
const double automateweldingv1_out_3_default=0;
const char automateweldingv0_out_0_default=0;

/* Project signal database hash */
const unsigned int sp_database_hash_32=0;
/* Project sheme structure hash */
const unsigned int sp_sheme_hash_32=3590188211;


/* Structures defines */
/*  --- Source model preferences --- */
/* Minimum integration step */
#define INTEGRATION_MIN_STEP 0.001
/* Maximum integration step */
#define INTEGRATION_MAX_STEP 0.001
/* Integration synchronization step */
#define INTEGRATION_SYNC_STEP 0
/* Model integration method */
#define INTEGRATION_METHOD 0
/* Model relative error */
#define INTEGRATION_RELATIVE_ERROR 0.0001
/* Model absolute error */
#define INTEGRATION_ABSOLUTE_ERROR 1E-6
/* Model end time */
#define INTEGRATION_END_TIME 10
/* Model maximum iteration count */
#define INTEGRATION_MAX_LOOP_ITER_COUNT 10

/* External variables */
#define ext_vars_count 5

#define out_0 (*(double*)(ext_vars_addr[0]))
#define out_1 (*(double*)(ext_vars_addr[1]))
#define out_2 (*(double*)(ext_vars_addr[2]))
#define out_3 (*(double*)(ext_vars_addr[3]))
#define input_0 (*(char*)(ext_vars_addr[4]))

const ext_var_info_record ext_vars_names[ext_vars_count] = {
  {"out:0", "", (void*)&out_0_default, vt_double,   {1}, 0, dir_out, sizeof(double)} ,
  {"out:1", "", (void*)&out_1_default, vt_double,   {1}, 1, dir_out, sizeof(double)} ,
  {"out:2", "", (void*)&out_2_default, vt_double,   {1}, 2, dir_out, sizeof(double)} ,
  {"out:3", "", (void*)&out_3_default, vt_double,   {1}, 3, dir_out, sizeof(double)} ,
  {"input:0", "", (void*)&input_0_default, vt_bool,   {1}, 4, dir_input, sizeof(char)} 
};
/* State variables */
#define state_vars_count 5


typedef struct {
  double automateweldingv1_out_0_;
  double automateweldingv1_out_1_;
  double automateweldingv1_out_2_;
  double automateweldingv1_out_3_;
  char automateweldingv0_out_0_;
} t_state_vars;



const ext_var_info_record state_vars_names[state_vars_count] = {
  {"automateweldingv1_out_0", "Language out", (void*)&automateweldingv1_out_0_default, vt_double,   {1}, 0, dir_input, sizeof(double)} ,
  {"automateweldingv1_out_1", "Language out", (void*)&automateweldingv1_out_1_default, vt_double,   {1}, 8, dir_input, sizeof(double)} ,
  {"automateweldingv1_out_2", "Language out", (void*)&automateweldingv1_out_2_default, vt_double,   {1}, 16, dir_input, sizeof(double)} ,
  {"automateweldingv1_out_3", "Language out", (void*)&automateweldingv1_out_3_default, vt_double,   {1}, 24, dir_input, sizeof(double)} ,
  {"automateweldingv0_out_0", "Input pin state variable", (void*)&automateweldingv0_out_0_default, vt_bool,   {1}, 32, dir_input, sizeof(char)} 
};
typedef char t_consts;
typedef char t_local;
#include "C:/SimInTech64/Projects/Automate_Welding/Automate_Welding_Program/fsm_welding.h"
#include "C:/SimInTech64/Projects/Automate_Welding/Automate_Welding_Program/fsm_welding.c"

enum InputSignal inSignal = {WELDING_OFF};
struct Engine engine = {ENGINE_WELDING_OFF, 0, 0, 0};
