module component1 (in1, in2, out); 
   input in1, in2; 
   output out; 
   assign out = (in1 & in2) | (~in1 & in2); 
endmodule 

module mainmod (a, b, c, d, e); 
   input a, b, c, d; 
   output e; 
   wire   w1, w2; and(a, b, w1);
   or(c, d, w2); 
   component1 inst1 (w1, w2, e); 
endmodule