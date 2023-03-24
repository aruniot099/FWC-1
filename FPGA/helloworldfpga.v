module helloworldfpga(

    input  wire X,
    input  wire Y,
    input  wire Z,
    
    output wire F,
    );
    
    always @(*)
    begin
   F=Y|X&(!Z); 
    end
    endmodule
