//
// Created by         : Harris Zhu
// Filename           : hello_pli.v
// Author             : Harris Zhu
// Created On         : 2017-07-21 17:11
// Last Modified      : 
// Update Count       : 2017-07-21 17:11
// Tags               :  
// Description        : 
// Conclusion         : 
//                      
//=======================================================================

module hello_pli ();
  	 
initial begin
  $hello("abc");
  #10;
  $greet("abc");
  #10 $finish;
end
  	  
endmodule
