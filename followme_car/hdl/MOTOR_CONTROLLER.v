module MOTOR_CONTROLLER(

/*** APB3 BUS INTERFACE ***/
input PCLK,                 // clock
input PRESERN,              // system reset
input PSEL,                 // peripheral select
input PENABLE,              // distinguishes access phase
output wire PREADY,         // peripheral ready signal
output wire PSLVERR,        // error signal
input PWRITE,               // distinguishes read and write cycles
input [31:0] PADDR,         // I/O address
input wire [31:0] PWDATA,   // data from processor to I/O device (32 bits)
output reg [31:0] PRDATA,   // data to processor from I/O device (32-bits)

/*** I/O PORTS DECLARATION ***/
output reg RIGHT_HB1,
output reg RIGHT_HB2,
output reg LEFT_HB1,
output reg LEFT_HB2
);

assign PSLVERR = 0;
assign PREADY = 1;

//////////////////////////////////
// end of APB3 interface header //
//////////////////////////////////

reg [6:0] RIGHT_DUTY_CYCLE;
reg [6:0] LEFT_DUTY_CYCLE;

reg RIGHT_FWD;
reg LEFT_FWD;

wire RIGHT_PWM;
wire LEFT_PWM;

PWM pwm_right(PCLK, RIGHT_DUTY_CYCLE, RIGHT_PWM);
PWM pwm_left(PCLK, LEFT_DUTY_CYCLE, LEFT_PWM);

always @(posedge PCLK) begin
    if (PSEL && PENABLE) begin
        if (PWRITE) begin
            RIGHT_DUTY_CYCLE <= PWDATA[8:2];
            LEFT_DUTY_CYCLE <= PWDATA[15:9];

            RIGHT_FWD <= PWDATA[0];
            LEFT_FWD <= PWDATA[1];
        end
    end

    if (~PRESERN) begin
        RIGHT_DUTY_CYCLE <= 0;
        LEFT_DUTY_CYCLE <= 0;
        RIGHT_FWD <= 1;
        LEFT_FWD <= 1;
    end
end

always @(posedge PCLK) begin
    if (RIGHT_FWD == 0) begin
        RIGHT_HB1 <= RIGHT_PWM;
        RIGHT_HB2 <= 0;
    end else begin
        RIGHT_HB1 <= 0;
        RIGHT_HB2 <= RIGHT_PWM;
    end

    if (LEFT_FWD == 0) begin
        LEFT_HB1 <= LEFT_PWM;
        LEFT_HB2 <= 0;
    end else begin
        LEFT_HB1 <= 0;
        LEFT_HB2 <= LEFT_PWM;
    end
end

endmodule


module PWM(
input CLK,
input [6:0] DUTY_CYCLE,     // 0-100%
output reg PWM_OUT
);

`define PWM_PERIOD 1000000  // 1 million cycles in 0.01 seconds (motor controller frequency is 100Hz)

reg [19:0] count;

always @(posedge CLK) begin
    if (count == `PWM_PERIOD)
        count <= 0;
    else
        count <= count + 1;

    if (count < DUTY_CYCLE * `PWM_PERIOD / 100)
        PWM_OUT <= 1;
    else
        PWM_OUT <= 0;
end
endmodule



