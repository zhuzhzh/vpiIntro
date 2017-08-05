#include <stdio.h>
#include "vpi_user.h"
#include "vpi_user_cds.h"

void show_val(char* user_data)
{
	vpiHandle systf_hdl, net_hdl, arg_it;
	s_vpi_value cur_value;

	systf_hdl = vpi_handle(vpiSysTfCall, NULL); /* get a handle to the system task */
	arg_it = vpi_iterate(vpiArgument, systf_hdl); /* get an iterator handle */

	if(!arg_it) {
		vpi_printf("No arguments for this system task.\n");
		return;
	}
	net_hdl = vpi_scan(arg_it);  /* obtain a handle to system task argument */

	cur_value.format = vpiBinStrVal; /* get value in string format */

	vpi_get_value(net_hdl, &cur_value);
	vpi_printf("Signal %s ", vpi_get_str(vpiFullName, net_hdl));
	vpi_printf("has the value %s\n\n", cur_value.value.str);
}

void register_my_systfs()
{
	s_vpi_systf_data task_data_s;
	p_vpi_systf_data task_data_p = &task_data_s;

	task_data_p->type = vpiSysTask;
	task_data_p->tfname = "$show_val";
	task_data_p->calltf = (int(*)()) show_val;
	task_data_p->compiletf = NULL;

	vpi_register_systf(task_data_p);
} 

