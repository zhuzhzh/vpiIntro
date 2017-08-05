build: cc nc simrun

cc:
	gcc -o libvpi.so -g -shared -fPIC -I${IES_HOME}/tools/include -I./ hello_vpi_nc.c 

nc:
	irun -c -64bit hello_pli.v

simrun: 
	irun -R -64bit


clean:
	rm -rf INCA_libs *.o *.so *.log *.history
