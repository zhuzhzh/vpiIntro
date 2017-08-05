module test;
  wire a, b, c;
  initial
    begin
      $module_info;
    end
  pipe p1 (a, b, c);
  //stimuli
  //monitor response
endmodule
