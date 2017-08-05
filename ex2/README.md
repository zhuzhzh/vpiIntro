# Auther
Harris Zhu (zhuzhzh@163.com)

# Files contained
test.v          -- Verilog top file
pipe.v          -- Verilog design under test
mod_info.c      -- VPI application with a registration C function
vpi_user.c.xl   -- the vpi_user.c file to use with Verilog-XL, rename to vpi_user.c
vpi_user.c.nc   -- the vpi_user.c file to use with NC-Verilog, rename to vpi_user.c
this file

# Simulation
For a description of supported simulation flows and how to run this example with Verilog-XL or NC-Verilog simulator, see the VPI User Guide and Reference, chapter 2 "Using VPI".

Use irun to simulate the design in one step (preferred method):
```
irun *.v *.c -loadvpi :module_info
```

You do not need to call the registration function (register_my_systfs) from your C code if you use irun, and you do not need to include the system task name in your Verilog file. Comment the lines in the corresponding files.

Using other tools to run the example (you need to register the system task in your C code - uncomment the lines):

Compile and link the C code to the simulator as described in the User Guide.

Use the following command to run the design with Verilog-XL (one-step mode):
```
verilog test.v pipe.v
```

Use the following commands to run the design with NC-Verilog (three-step mode):
```
ncvlog test.v pipe.v
ncelab -access +rw test
ncsim test
```

The VPI function output is:
```
Top module Full Name: test
 Top module Name: test
```
To run these tools with SimVision, add the +gui or -gui option to the verilog or ncvlog commands, respectively.


