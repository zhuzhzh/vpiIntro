module add2bit (in1, in2, sum);
input in1, in2;
output[1:0] sum;
wire in1, in2;
reg[0:1] sum;

always @(in1 or in2) begin
  sum = in1 + in2;
end

endmodule

