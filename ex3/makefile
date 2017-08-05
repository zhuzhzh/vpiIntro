onestep:
	irun *.v *.c -loadvpi :counter_monitor
	#doesn't work

loadvpi: lib nc simrun
#doesn't work

nc: 
	ncvlog test.v counter.v
	ncelab -access +rw test -loadvpi libmyvpi:register_counter_monitor

lib:
	gcc -fPIC -shared -o libmyvpi.so vpi_user.c pli.c -I${IES_HOME}/tools/include -I${IES_HOME}/tools/inca/include

simrun:
	ncsim test
	
plimap:
	irun test.v counter.v pli.c -afile pli.map -c -access rw
	irun -64bit -R

clean:
	rm -rf INCA_libs *.log *.history *.msg *.err *.so *.vcd

.PHONY: clean nc lib
