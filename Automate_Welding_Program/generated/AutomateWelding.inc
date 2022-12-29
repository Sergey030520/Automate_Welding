/*  ------------------------------------------------------
     Routine name:  AutomateWelding
     Description:   
     Project file:  model_automate_welding.prt

------------------------------------------------------  */

/*       Local stack variables                */
int i;
int j;
int c;
int itmp1;
int itmp2;
int itmp3;
double tmp1;
double tmp2;
double tmp3;
double tmp4;
double tmp5;
double tmp6;
double tmp7;
char f;
char tmp_f_1;
char u_s;
char u_r;
ret = 0;

switch (action){
case f_Stop:{
/* Index=1
   UID=1
   GeneratorClassName=TLanguage
   Name=LangBlock22
   Type=Язык программирования */

automateweldingv1_sfinal__0:
;
};break;
case f_GetDeri:{
};break;
case f_GetAlgFun:{
};break;
default:{

/* Index=0
   UID=0
   GeneratorClassName=TInputPin
   Name=Const_source19
   Type=Входной контакт */

state_vars->automateweldingv0_out_0_ = ((input_0));

/* Index=1
   UID=1
   GeneratorClassName=TLanguage
   Name=LangBlock22
   Type=Язык программирования */

inSignal = (enum InputSignal)state_vars->automateweldingv0_out_0_;

engine_tick(&engine, inSignal);

state_vars->automateweldingv1_out_0_ = engine.value;
state_vars->automateweldingv1_out_1_ = engine.automate[AUTOMATE_I].value;
state_vars->automateweldingv1_out_2_ = engine.automate[AUTOMATE_U].value;
state_vars->automateweldingv1_out_3_ = engine.automate[AUTOMATE_V].value;
/* Index=1
   UID=1
   GeneratorClassName=TLanguage
   Name=LangBlock22
   Type=Язык программирования */

l_start_automateweldingv1:;
automateweldingv1___0:
;

/* Index=2
   UID=2
   GeneratorClassName=TOutPin
   Name=OutPin16
   Type=Выходной контакт */

if(isfinite(state_vars->automateweldingv1_out_0_)){
out_0 = state_vars->automateweldingv1_out_0_;
};

/* Index=3
   UID=3
   GeneratorClassName=TOutPin
   Name=OutPin17
   Type=Выходной контакт */

if(isfinite(state_vars->automateweldingv1_out_1_)){
out_1 = state_vars->automateweldingv1_out_1_;
};

/* Index=4
   UID=4
   GeneratorClassName=TOutPin
   Name=OutPin18
   Type=Выходной контакт */

if(isfinite(state_vars->automateweldingv1_out_2_)){
out_2 = state_vars->automateweldingv1_out_2_;
};

/* Index=5
   UID=5
   GeneratorClassName=TOutPin
   Name=OutPin19
   Type=Выходной контакт */

if(isfinite(state_vars->automateweldingv1_out_3_)){
out_3 = state_vars->automateweldingv1_out_3_;
};
};break;
};
