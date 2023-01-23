// measure_core.v

// This file was auto-generated as a prototype implementation of a module
// created in component editor.  It ties off all outputs to ground and
// ignores all inputs.  It needs to be edited to make it do something
// useful.
// 
// This file will not be automatically regenerated.  You should check it in
// to your version control system if you want to keep it.

`timescale 1 ps / 1 ps
module measure_core (
		input  logic [7:0]  avalon_slave_address,  // avalon_slave.address
		input  logic        avalon_slave_read,     //             .read
		output logic [31:0] avalon_slave_readdata, //             .readdata
		input  logic        clock_sink_clk,        //   clock_sink.clk
		input  logic        reset_sink_reset,      //   reset_sink.reset
		input  logic [1:0]  gpio                   //  conduit_end.new_signal
	);

	logic [31:0] current_value;
	logic [7:0] counter;
	logic [31:0] mem[7:0];
	logic [31:0] rd;
	// TODO: Auto-generated HDL template
	assign avalon_slave_readdata = rd;
	
	always_ff @(posedge clock_sink_clk) begin
		if(reset_sink_reset) begin
			current_value <= 0;
			counter <= 1;
			rd <= 'x;
		end else begin
			rd <= avalon_slave_address == 0 ? {24'b0, counter} : mem[avalon_slave_address];
			if(gpio[0] ^ gpio[1]) begin
				current_value <= current_value + 8'b1;
			end else begin
				if (current_value == 0) begin
					// continue;
				end else begin
					mem[counter] <= current_value;
					current_value <= 0;
					counter <= counter == 8'hff ? 8'b1 : counter + 8'b1;
				end
			end
		end
	end
endmodule
