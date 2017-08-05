onestep:
	irun *.v *.c -loadvpi :module_info
	#doesn't work

ncsim:
	ncvlog test.v pipe.v
	ncelab -access +rw test
	ncsim test

loadvpi: lib nc simrun

lib:
	gcc -fPIC -shared -o libmyvpi.so vpi_user.c mod_info.c -I${IES_HOME}/tools/include -I${IES_HOME}/tools/inca/include

nc:
	irun -c test.v pipe.v -loadvpi libmyvpi:register_my_systfs

simrun:
	irun -64bit -R

clean:
	rm -rf INCA_libs *.log *.msg *.key *.history *.err *.so

.PHONY: clean loadvpi
