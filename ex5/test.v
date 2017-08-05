module test;
    wire a, b, c;
    initial
	begin
	   $getports;
	end
    pipe p1 ( a, b, c );
endmodule

