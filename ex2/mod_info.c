#include <stdio.h>
#include "vpi_user.h"
#include "vpi_user_cds.h"

void module_info()
{
  vpiHandle moditH, topmodH;
  moditH = vpi_iterate(vpiModule, NULL);
  if(!moditH) {
     vpi_printf("    Error: no modules in the design\n");
  }
   while (topmodH = vpi_scan(moditH)) {
    vpi_printf("Top module Full Name: %s\n", 
     vpi_get_str(vpiFullName, topmodH));
    vpi_printf(" Top module Name: %s\n", vpi_get_str(vpiName, topmodH));
   }
} 
void register_my_systfs()
{
  s_vpi_systf_data task_data_s;
  p_vpi_systf_data task_data_p = &task_data_s;
  task_data_p->type = vpiSysTask;
  task_data_p->tfname = "$module_info";
  task_data_p->calltf = (int(*)()) module_info;
  task_data_p->compiletf = 0;
  vpi_register_systf(task_data_p);
}
