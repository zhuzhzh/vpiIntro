#include "vpi_user.h"
#include "vpi_user_cds.h"

int recursive_walk (vpiHandle ModHdl) {
	vpiHandle ItHdl, portItHdl, portHdl, lowHdl, highHdl;

	ItHdl = vpi_iterate(vpiModule, ModHdl);

	if (!ItHdl) {
		return(0);
	}

	while (ModHdl = vpi_scan(ItHdl))
	{
		vpi_printf("2: Module %s\n\n", vpi_get_str(vpiFullName, ModHdl));
		vpi_printf(" Ports for module %s, instance %s:\n",
			vpi_get_str(vpiDefName, ModHdl), vpi_get_str(vpiFullName, ModHdl));

		portItHdl = vpi_iterate(vpiPort, ModHdl);
		if (!portItHdl) {
			vpi_printf("    No ports exist for the module\n");
		} 
		while (portHdl = vpi_scan(portItHdl)) {
			switch (vpi_get(vpiDirection, portHdl)) {
			case vpiInput : vpi_printf("\n   Input \n"); break;
			case vpiOutput: vpi_printf("\n   Output \n"); break;
			case vpiInout : vpi_printf("\n   Inout \n"); break;
			}
			vpi_printf("   %s ", vpi_get_str(vpiName, portHdl));
			vpi_printf(": port index %d\n", vpi_get(vpiPortIndex, portHdl));

			lowHdl = vpi_handle(vpiLowConn, portHdl);
			vpi_printf("   Low Conn data type is "); 
			switch (vpi_get(vpiType, lowHdl)) {
			case vpiNet : vpi_printf("vpiNet\n"); break;
			case vpiReg : vpi_printf("vpiReg\n"); break;
						  /* add other data types here */
			default     : vpi_printf("Undefined\n"); 
			}

			highHdl = vpi_handle(vpiHighConn, portHdl);
			if (!highHdl) {
				vpi_printf("   No high conn exists!\n");
			}
			vpi_printf("   High Conn data type is ");
			switch (vpi_get(vpiType, highHdl)) {
			case vpiNet : vpi_printf("vpiNet\n"); break;
			case vpiReg : vpi_printf("vpiReg\n"); break;
						  /* add other data types here */
			default     : vpi_printf("Undefined\n");
			}
		}  
		recursive_walk(ModHdl);
	}
}

void getports()
{
	vpiHandle top_ModItHdl, top_ModHdl;

	top_ModItHdl = vpi_iterate(vpiModule, 0);

	if(!top_ModItHdl) {
		vpi_printf("    Error: There are no modules in design\n");
		return;
	}
	while (top_ModHdl = vpi_scan(top_ModItHdl)) {

		vpi_printf("\n1: Module %s\n", vpi_get_str(vpiFullName, top_ModHdl));
		recursive_walk(top_ModHdl);
	}
}

void register_my_systfs()
{
	s_vpi_systf_data task_data_s;
	p_vpi_systf_data task_data_p = &task_data_s;

	task_data_p->type = vpiSysTask;
	task_data_p->tfname = "$getports";
	task_data_p->calltf = (int(*)()) getports;
	task_data_p->compiletf = 0;

	vpi_register_systf(task_data_p);
}

