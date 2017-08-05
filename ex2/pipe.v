module pipe ( out, in, clk );
  output out; reg out;
  input in, clk;
     always @ (in)
     @ (posedge clk)
    out <= repeat (2) @ (posedge clk) in;
endmodule
