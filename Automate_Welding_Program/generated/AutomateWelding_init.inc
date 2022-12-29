/*  ------------------------------------------------------
     Routine name:  AutomateWelding
     Description:   
     Project file:  model_automate_welding.prt

------------------------------------------------------  */

int i;
int j;
int c;
ret = 0;
memcpy(&state_vars->automateweldingv1_out_0_,&automateweldingv1_out_0_default,sizeof(automateweldingv1_out_0_default));
memcpy(&state_vars->automateweldingv1_out_1_,&automateweldingv1_out_1_default,sizeof(automateweldingv1_out_1_default));
memcpy(&state_vars->automateweldingv1_out_2_,&automateweldingv1_out_2_default,sizeof(automateweldingv1_out_2_default));
memcpy(&state_vars->automateweldingv1_out_3_,&automateweldingv1_out_3_default,sizeof(automateweldingv1_out_3_default));
memcpy(&state_vars->automateweldingv0_out_0_,&automateweldingv0_out_0_default,sizeof(automateweldingv0_out_0_default));
automateweldingv1_sinit__0:
;
engine_init(&engine);
