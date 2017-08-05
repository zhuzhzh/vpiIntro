module test;

    wire [1:0] c;
    reg  a, b;

    add2bit a1 ( a, b, c );

    initial 
      begin
       a = 0;
       b = 0;
       $monitor("%0t: a = %b, b = %b, c = %b", $time,a,b,c);
       #5;
       b = 1;
       #5;
       $show_val(c);
       #5;
       a = 1; 
       #5;
       $show_val(c);
       #5;
       b = 0;
       #5;
       $show_val(c);
      end
    
endmodule

