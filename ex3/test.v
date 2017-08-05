//
// Created by         : Harris Zhu
// Filename           : tb.sv
// Author             : Harris Zhu
// Created On         : 2017-07-23 22:39
// Last Modified      : 
// Update Count       : 2017-07-23 22:39
// Tags               :  
// Description        : 
// Conclusion         : 
//                      
//=======================================================================

`timescale 1ns/10ps
module test();
	reg enable;
	reg reset;
	reg clk_reg;
	wire clk;
	wire [3:0] dut_count;
       
initial begin
	enable = 0;
	clk_reg = 0;
	reset = 0;
	$display("%g , Asserting reset", $time);
	#10 reset = 1;
	#10 reset = 0;
	$display ("%g, Asserting Enable", $time);
	#10 enable = 1;
	#55 enable = 0;
	$display ("%g, Deasserting Enable", $time);
	#1 $display ("%g, Terminating Simulator", $time);
	#1 $finish;
end
    
always begin
	#5 clk_reg = !clk_reg;
end
       
assign clk = clk_reg;
initial
begin
	$dumpfile("wave.vcd");
	$dumpvars;
end 

initial begin
	$counter_monitor(test.clk, test.reset, test.enable, test.dut_count);
end

counter u_counter(
.clk (clk),
.reset (reset),
.enable (enable),
.count (dut_count)
);
    
endmodule
