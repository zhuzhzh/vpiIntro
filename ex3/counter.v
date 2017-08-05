//
// Created by         : Harris Zhu
// Filename           : counter.v
// Author             : Harris Zhu
// Created On         : 2017-07-23 22:38
// Last Modified      : 
// Update Count       : 2017-07-23 22:38
// Tags               :  
// Description        : 
// Conclusion         : 
//                      
//=======================================================================

`timescale 1ns/10ps
module counter (
        input clk,
        input reset,
        input enable,
        output reg [3:0] count
        );
    
    always @(posedge clk or posedge reset)
    begin
        if(reset)
        begin
            count <=  4'b0;
        end
        else if(enable)
        begin
            count <= count+1'b1;
        end
    end
endmodule
