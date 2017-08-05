//
// Created by         : Harris Zhu
// Filename           : hello_vpi_nc.c
// Author             : Harris Zhu
// Created On         : 2017-07-21 17:10
// Last Modified      : 
// Update Count       : 2017-07-21 17:10
// Tags               :  
// Description        : 
// Conclusion         : 
//                      
//=======================================================================
#include "hello_vpi.c"
#include "greet_vpi.c"

// Associate C Function with a New System Task
void registerHelloSystfs() {
  s_vpi_systf_data task_data_s;
  p_vpi_systf_data task_data_p = &task_data_s;
  task_data_p->type = vpiSysTask;
  task_data_p->tfname = "$hello";
  task_data_p->calltf = hello;
  task_data_p->compiletf = 0;

  vpi_register_systf(task_data_p);
}

void registerGreetSystfs() {
  s_vpi_systf_data task_data_s;
  p_vpi_systf_data task_data_p = &task_data_s;
  task_data_p->type = vpiSysTask;
  task_data_p->tfname = "$greet";
  task_data_p->calltf = greet;
  task_data_p->compiletf = 0;

  vpi_register_systf(task_data_p);
}

// Register the new system task here
void (*vlog_startup_routines[ ] ) () = {
   registerHelloSystfs,
   registerGreetSystfs,
   0  // last entry must be 0 
}; 
