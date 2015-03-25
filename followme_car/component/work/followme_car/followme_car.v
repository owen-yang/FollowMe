//////////////////////////////////////////////////////////////////////
// Created by SmartDesign Wed Mar 25 18:23:49 2015
// Version: v11.4 11.4.0.112
//////////////////////////////////////////////////////////////////////

`timescale 1 ns/100 ps

// followme_car
module followme_car(
    // Inputs
    MSS_RESET_N,
    // Outputs
    LEFT_HB1,
    LEFT_HB2,
    RIGHT_HB1,
    RIGHT_HB2
);

//--------------------------------------------------------------------
// Input
//--------------------------------------------------------------------
input  MSS_RESET_N;
//--------------------------------------------------------------------
// Output
//--------------------------------------------------------------------
output LEFT_HB1;
output LEFT_HB2;
output RIGHT_HB1;
output RIGHT_HB2;
//--------------------------------------------------------------------
// Nets
//--------------------------------------------------------------------
wire   [31:0] CoreAPB3_0_APBmslave0_PADDR;
wire          CoreAPB3_0_APBmslave0_PENABLE;
wire   [31:0] CoreAPB3_0_APBmslave0_PRDATA;
wire          CoreAPB3_0_APBmslave0_PREADY;
wire          CoreAPB3_0_APBmslave0_PSELx;
wire          CoreAPB3_0_APBmslave0_PSLVERR;
wire   [31:0] CoreAPB3_0_APBmslave0_PWDATA;
wire          CoreAPB3_0_APBmslave0_PWRITE;
wire          followme_car_MSS_0_FAB_CLK;
wire          followme_car_MSS_0_M2F_RESET_N;
wire          followme_car_MSS_0_MSS_MASTER_APB_PENABLE;
wire   [31:0] followme_car_MSS_0_MSS_MASTER_APB_PRDATA;
wire          followme_car_MSS_0_MSS_MASTER_APB_PREADY;
wire          followme_car_MSS_0_MSS_MASTER_APB_PSELx;
wire          followme_car_MSS_0_MSS_MASTER_APB_PSLVERR;
wire   [31:0] followme_car_MSS_0_MSS_MASTER_APB_PWDATA;
wire          followme_car_MSS_0_MSS_MASTER_APB_PWRITE;
wire          LEFT_HB1_net_0;
wire          LEFT_HB2_net_0;
wire          MSS_RESET_N;
wire          RIGHT_HB1_net_0;
wire          RIGHT_HB2_net_0;
wire          LEFT_HB1_net_1;
wire          RIGHT_HB1_net_1;
wire          LEFT_HB2_net_1;
wire          RIGHT_HB2_net_1;
//--------------------------------------------------------------------
// TiedOff Nets
//--------------------------------------------------------------------
wire          GND_net;
wire          VCC_net;
wire   [31:0] IADDR_const_net_0;
wire   [31:0] PRDATAS1_const_net_0;
wire   [31:0] PRDATAS2_const_net_0;
wire   [31:0] PRDATAS3_const_net_0;
wire   [31:0] PRDATAS4_const_net_0;
wire   [31:0] PRDATAS5_const_net_0;
wire   [31:0] PRDATAS6_const_net_0;
wire   [31:0] PRDATAS7_const_net_0;
wire   [31:0] PRDATAS8_const_net_0;
wire   [31:0] PRDATAS9_const_net_0;
wire   [31:0] PRDATAS10_const_net_0;
wire   [31:0] PRDATAS11_const_net_0;
wire   [31:0] PRDATAS12_const_net_0;
wire   [31:0] PRDATAS13_const_net_0;
wire   [31:0] PRDATAS14_const_net_0;
wire   [31:0] PRDATAS15_const_net_0;
wire   [31:0] PRDATAS16_const_net_0;
//--------------------------------------------------------------------
// Bus Interface Nets Declarations - Unequal Pin Widths
//--------------------------------------------------------------------
wire   [31:20]followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_31to20;
wire   [19:0] followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_19to0;
wire   [31:0] followme_car_MSS_0_MSS_MASTER_APB_PADDR_0;
wire   [19:0] followme_car_MSS_0_MSS_MASTER_APB_PADDR;
//--------------------------------------------------------------------
// Constant assignments
//--------------------------------------------------------------------
assign GND_net               = 1'b0;
assign VCC_net               = 1'b1;
assign IADDR_const_net_0     = 32'h00000000;
assign PRDATAS1_const_net_0  = 32'h00000000;
assign PRDATAS2_const_net_0  = 32'h00000000;
assign PRDATAS3_const_net_0  = 32'h00000000;
assign PRDATAS4_const_net_0  = 32'h00000000;
assign PRDATAS5_const_net_0  = 32'h00000000;
assign PRDATAS6_const_net_0  = 32'h00000000;
assign PRDATAS7_const_net_0  = 32'h00000000;
assign PRDATAS8_const_net_0  = 32'h00000000;
assign PRDATAS9_const_net_0  = 32'h00000000;
assign PRDATAS10_const_net_0 = 32'h00000000;
assign PRDATAS11_const_net_0 = 32'h00000000;
assign PRDATAS12_const_net_0 = 32'h00000000;
assign PRDATAS13_const_net_0 = 32'h00000000;
assign PRDATAS14_const_net_0 = 32'h00000000;
assign PRDATAS15_const_net_0 = 32'h00000000;
assign PRDATAS16_const_net_0 = 32'h00000000;
//--------------------------------------------------------------------
// Top level output port assignments
//--------------------------------------------------------------------
assign LEFT_HB1_net_1  = LEFT_HB1_net_0;
assign LEFT_HB1        = LEFT_HB1_net_1;
assign RIGHT_HB1_net_1 = RIGHT_HB1_net_0;
assign RIGHT_HB1       = RIGHT_HB1_net_1;
assign LEFT_HB2_net_1  = LEFT_HB2_net_0;
assign LEFT_HB2        = LEFT_HB2_net_1;
assign RIGHT_HB2_net_1 = RIGHT_HB2_net_0;
assign RIGHT_HB2       = RIGHT_HB2_net_1;
//--------------------------------------------------------------------
// Bus Interface Nets Assignments - Unequal Pin Widths
//--------------------------------------------------------------------
assign followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_31to20 = 12'h0;
assign followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_19to0 = followme_car_MSS_0_MSS_MASTER_APB_PADDR[19:0];
assign followme_car_MSS_0_MSS_MASTER_APB_PADDR_0 = { followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_31to20, followme_car_MSS_0_MSS_MASTER_APB_PADDR_0_19to0 };

//--------------------------------------------------------------------
// Component instances
//--------------------------------------------------------------------
//--------CoreAPB3   -   Actel:DirectCore:CoreAPB3:4.0.100
CoreAPB3 #( 
        .APB_DWIDTH      ( 32 ),
        .APBSLOT0ENABLE  ( 1 ),
        .APBSLOT1ENABLE  ( 0 ),
        .APBSLOT2ENABLE  ( 0 ),
        .APBSLOT3ENABLE  ( 0 ),
        .APBSLOT4ENABLE  ( 0 ),
        .APBSLOT5ENABLE  ( 0 ),
        .APBSLOT6ENABLE  ( 0 ),
        .APBSLOT7ENABLE  ( 0 ),
        .APBSLOT8ENABLE  ( 0 ),
        .APBSLOT9ENABLE  ( 0 ),
        .APBSLOT10ENABLE ( 0 ),
        .APBSLOT11ENABLE ( 0 ),
        .APBSLOT12ENABLE ( 0 ),
        .APBSLOT13ENABLE ( 0 ),
        .APBSLOT14ENABLE ( 0 ),
        .APBSLOT15ENABLE ( 0 ),
        .IADDR_OPTION    ( 0 ),
        .MADDR_BITS      ( 12 ),
        .SC_0            ( 0 ),
        .SC_1            ( 0 ),
        .SC_2            ( 0 ),
        .SC_3            ( 0 ),
        .SC_4            ( 0 ),
        .SC_5            ( 0 ),
        .SC_6            ( 0 ),
        .SC_7            ( 0 ),
        .SC_8            ( 0 ),
        .SC_9            ( 0 ),
        .SC_10           ( 0 ),
        .SC_11           ( 0 ),
        .SC_12           ( 0 ),
        .SC_13           ( 0 ),
        .SC_14           ( 0 ),
        .SC_15           ( 0 ),
        .UPR_NIBBLE_POSN ( 2 ) )
CoreAPB3_0(
        // Inputs
        .PRESETN    ( GND_net ), // tied to 1'b0 from definition
        .PCLK       ( GND_net ), // tied to 1'b0 from definition
        .PADDR      ( followme_car_MSS_0_MSS_MASTER_APB_PADDR_0 ),
        .PWRITE     ( followme_car_MSS_0_MSS_MASTER_APB_PWRITE ),
        .PENABLE    ( followme_car_MSS_0_MSS_MASTER_APB_PENABLE ),
        .PWDATA     ( followme_car_MSS_0_MSS_MASTER_APB_PWDATA ),
        .PSEL       ( followme_car_MSS_0_MSS_MASTER_APB_PSELx ),
        .PRDATAS0   ( CoreAPB3_0_APBmslave0_PRDATA ),
        .PREADYS0   ( CoreAPB3_0_APBmslave0_PREADY ),
        .PSLVERRS0  ( CoreAPB3_0_APBmslave0_PSLVERR ),
        .PRDATAS1   ( PRDATAS1_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS1   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS1  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS2   ( PRDATAS2_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS2   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS2  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS3   ( PRDATAS3_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS3   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS3  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS4   ( PRDATAS4_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS4   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS4  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS5   ( PRDATAS5_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS5   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS5  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS6   ( PRDATAS6_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS6   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS6  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS7   ( PRDATAS7_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS7   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS7  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS8   ( PRDATAS8_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS8   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS8  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS9   ( PRDATAS9_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS9   ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS9  ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS10  ( PRDATAS10_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS10  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS10 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS11  ( PRDATAS11_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS11  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS11 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS12  ( PRDATAS12_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS12  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS12 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS13  ( PRDATAS13_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS13  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS13 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS14  ( PRDATAS14_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS14  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS14 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS15  ( PRDATAS15_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS15  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS15 ( GND_net ), // tied to 1'b0 from definition
        .PRDATAS16  ( PRDATAS16_const_net_0 ), // tied to 32'h00000000 from definition
        .PREADYS16  ( VCC_net ), // tied to 1'b1 from definition
        .PSLVERRS16 ( GND_net ), // tied to 1'b0 from definition
        .IADDR      ( IADDR_const_net_0 ), // tied to 32'h00000000 from definition
        // Outputs
        .PRDATA     ( followme_car_MSS_0_MSS_MASTER_APB_PRDATA ),
        .PREADY     ( followme_car_MSS_0_MSS_MASTER_APB_PREADY ),
        .PSLVERR    ( followme_car_MSS_0_MSS_MASTER_APB_PSLVERR ),
        .PADDRS     ( CoreAPB3_0_APBmslave0_PADDR ),
        .PWRITES    ( CoreAPB3_0_APBmslave0_PWRITE ),
        .PENABLES   ( CoreAPB3_0_APBmslave0_PENABLE ),
        .PWDATAS    ( CoreAPB3_0_APBmslave0_PWDATA ),
        .PSELS0     ( CoreAPB3_0_APBmslave0_PSELx ),
        .PSELS1     (  ),
        .PSELS2     (  ),
        .PSELS3     (  ),
        .PSELS4     (  ),
        .PSELS5     (  ),
        .PSELS6     (  ),
        .PSELS7     (  ),
        .PSELS8     (  ),
        .PSELS9     (  ),
        .PSELS10    (  ),
        .PSELS11    (  ),
        .PSELS12    (  ),
        .PSELS13    (  ),
        .PSELS14    (  ),
        .PSELS15    (  ),
        .PSELS16    (  ) 
        );

//--------followme_car_MSS
followme_car_MSS followme_car_MSS_0(
        // Inputs
        .MSS_RESET_N ( MSS_RESET_N ),
        .MSSPRDATA   ( followme_car_MSS_0_MSS_MASTER_APB_PRDATA ),
        .MSSPREADY   ( followme_car_MSS_0_MSS_MASTER_APB_PREADY ),
        .MSSPSLVERR  ( followme_car_MSS_0_MSS_MASTER_APB_PSLVERR ),
        // Outputs
        .FAB_CLK     ( followme_car_MSS_0_FAB_CLK ),
        .MSSPADDR    ( followme_car_MSS_0_MSS_MASTER_APB_PADDR ),
        .MSSPSEL     ( followme_car_MSS_0_MSS_MASTER_APB_PSELx ),
        .MSSPENABLE  ( followme_car_MSS_0_MSS_MASTER_APB_PENABLE ),
        .MSSPWRITE   ( followme_car_MSS_0_MSS_MASTER_APB_PWRITE ),
        .MSSPWDATA   ( followme_car_MSS_0_MSS_MASTER_APB_PWDATA ),
        .M2F_RESET_N ( followme_car_MSS_0_M2F_RESET_N ) 
        );

//--------MOTOR_CONTROLLER
MOTOR_CONTROLLER MOTOR_CONTROLLER_0(
        // Inputs
        .PCLK      ( followme_car_MSS_0_FAB_CLK ),
        .PRESERN   ( followme_car_MSS_0_M2F_RESET_N ),
        .PSEL      ( CoreAPB3_0_APBmslave0_PSELx ),
        .PENABLE   ( CoreAPB3_0_APBmslave0_PENABLE ),
        .PWRITE    ( CoreAPB3_0_APBmslave0_PWRITE ),
        .PADDR     ( CoreAPB3_0_APBmslave0_PADDR ),
        .PWDATA    ( CoreAPB3_0_APBmslave0_PWDATA ),
        // Outputs
        .PREADY    ( CoreAPB3_0_APBmslave0_PREADY ),
        .PSLVERR   ( CoreAPB3_0_APBmslave0_PSLVERR ),
        .PRDATA    ( CoreAPB3_0_APBmslave0_PRDATA ),
        .RIGHT_HB1 ( RIGHT_HB1_net_0 ),
        .RIGHT_HB2 ( RIGHT_HB2_net_0 ),
        .LEFT_HB1  ( LEFT_HB1_net_0 ),
        .LEFT_HB2  ( LEFT_HB2_net_0 ) 
        );


endmodule
