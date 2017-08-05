USER_C_FILE = getports.c
VLOG_FILE = test.v pipe.v
REG_TASK_NAME = register_my_systfs

onestep:
	irun *.v *.c -loadvpi :getports
	#doesn't work

loadvpi: lib nc simrun
#doesn't work

nc: 
	ncvlog ${VLOG_FILE}
	ncelab -access +rw test -loadvpi libmyvpi:${REG_TASK_NAME}

lib:
	gcc -fPIC -shared -o libmyvpi.so vpi_user.c ${USER_C_FILE} -I${IES_HOME}/tools/include -I${IES_HOME}/tools/inca/include

simrun:
	ncsim test
	
plimap:
	irun ${VLOG_FILE} ${USER_C_FILE} -afile pli.map -c -access rw
	irun -64bit -R

clean:
	rm -rf INCA_libs *.log *.history *.msg *.err *.so *.vcd

.PHONY: clean nc lib
