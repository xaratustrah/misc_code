module decode (A15, RD, WR, CSRAM);
   input A15;
   input RD;
   input WR;
   output CSRAM;
   assign CSRAM = (~A15 & ( ~RD | ~WR ));
endmodule
