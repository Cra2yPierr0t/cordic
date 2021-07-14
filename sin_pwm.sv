module sin_pwm #(
    parameter WIDTH = 33,
    parameter INT   = 9,
    parameter FRA   = 24
)(
    input   logic [INT-2:0] theta,
    output  logic [INT-2:0] duty
);

    parameter THETA_0   = 32'h2D_000000;
    parameter THETA_1   = 32'h1A_90A731;
    parameter THETA_2   = 32'h0E_094740;
    parameter THETA_3   = 32'h07_200112;
    parameter THETA_4   = 32'h03_938AA6;
    parameter THETA_5   = 32'h01_CA3794;
    parameter THETA_6   = 32'h00_E52A1A;
    parameter THETA_7   = 32'h00_7296D7;
    parameter THETA_8   = 32'h00_394BA5;
    parameter THETA_9   = 32'h00_1CA5D9;
    parameter THETA_10  = 32'h00_0E52ED;
    parameter THETA_11  = 32'h00_072976;
    parameter THETA_12  = 32'h00_0394BB;
    parameter THETA_13  = 32'h00_01CA5D;
    parameter THETA_14  = 32'h00_00E52E;
    parameter THETA_15  = 32'h00_007297;
    parameter THETA_16  = 32'h00_00394B;
    parameter THETA_17  = 32'h00_001CA5;
    parameter R17_INV   = 32'h00_9B74ED;

    logic [WIDTH-1:0] x;
    logic [WIDTH-1:0] y;

    logic [WIDTH-1:0] x_buf;
    logic [WIDTH-1:0] y_buf;

    logic [WIDTH-1:0] duty_buf;

    logic [WIDTH-1:0] buffer;
    
    logic [INT-2:0] _theta;

    always_comb begin
        if(theta > 90) begin
            _theta = theta - 90;
        end else begin
            _theta = theta;
        end

        buffer = THETA_0 - (_theta << FRA);
        if(buffer[WIDTH-1] == 0) begin
            x_buf = (100 << FRA) + ((100 << FRA) >> 1);
            y_buf = (100 << FRA) - ((100 << FRA) >> 1);
            buffer = buffer - THETA_1;
        end else begin
            x_buf = (100 << FRA) - ((100 << FRA) >> 1);
            y_buf = (100 << FRA) + ((100 << FRA) >> 1);
            buffer = buffer + THETA_1;
        end
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 2);
            y_buf = signed'(y) - (signed'(x) >>> 2);
            buffer = buffer - THETA_2;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 2);
            y_buf = signed'(y) + (signed'(x) >>> 2);
            buffer = buffer + THETA_2;
        end
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 3);
            y_buf = signed'(y) - (signed'(x) >>> 3);
            buffer = buffer - THETA_3;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 3);
            y_buf = signed'(y) + (signed'(x) >>> 3);
            buffer = buffer + THETA_3;
        end
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 4);
            y_buf = signed'(y) - (signed'(x) >>> 4);
            buffer = buffer - THETA_4;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 4);
            y_buf = signed'(y) + (signed'(x) >>> 4);
            buffer = buffer + THETA_4;
        end
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 5);
            y_buf = signed'(y) - (signed'(x) >>> 5);
            buffer = buffer - THETA_5;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 5);
            y_buf = signed'(y) + (signed'(x) >>> 5);
            buffer = buffer + THETA_5;
        end
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 6);
            y_buf = signed'(y) - (signed'(x) >>> 6);
            buffer = buffer - THETA_6;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 6);
            y_buf = signed'(y) + (signed'(x) >>> 6);
            buffer = buffer + THETA_6;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 7);
            y_buf = signed'(y) - (signed'(x) >>> 7);
            buffer = buffer - THETA_7;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 7);
            y_buf = signed'(y) + (signed'(x) >>> 7);
            buffer = buffer + THETA_7;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 8);
            y_buf = signed'(y) - (signed'(x) >>> 8);
            buffer = buffer - THETA_8;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 8);
            y_buf = signed'(y) + (signed'(x) >>> 8);
            buffer = buffer + THETA_8;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 9);
            y_buf = signed'(y) - (signed'(x) >>> 9);
            buffer = buffer - THETA_9;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 9);
            y_buf = signed'(y) + (signed'(x) >>> 9);
            buffer = buffer + THETA_9;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 10);
            y_buf = signed'(y) - (signed'(x) >>> 10);
            buffer = buffer - THETA_10;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 10);
            y_buf = signed'(y) + (signed'(x) >>> 10);
            buffer = buffer + THETA_10;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 11);
            y_buf = signed'(y) - (signed'(x) >>> 11);
            buffer = buffer - THETA_11;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 11);
            y_buf = signed'(y) + (signed'(x) >>> 11);
            buffer = buffer + THETA_11;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 12);
            y_buf = signed'(y) - (signed'(x) >>> 12);
            buffer = buffer - THETA_12;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 12);
            y_buf = signed'(y) + (signed'(x) >>> 12);
            buffer = buffer + THETA_12;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 13);
            y_buf = signed'(y) - (signed'(x) >>> 13);
            buffer = buffer - THETA_13;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 13);
            y_buf = signed'(y) + (signed'(x) >>> 13);
            buffer = buffer + THETA_13;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 14);
            y_buf = signed'(y) - (signed'(x) >>> 14);
            buffer = buffer - THETA_14;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 14);
            y_buf = signed'(y) + (signed'(x) >>> 14);
            buffer = buffer + THETA_14;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 15);
            y_buf = signed'(y) - (signed'(x) >>> 15);
            buffer = buffer - THETA_15;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 15);
            y_buf = signed'(y) + (signed'(x) >>> 15);
            buffer = buffer + THETA_15;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 16);
            y_buf = signed'(y) - (signed'(x) >>> 16);
            buffer = buffer - THETA_16;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 16);
            y_buf = signed'(y) + (signed'(x) >>> 16);
            buffer = buffer + THETA_16;
        end   
        x = x_buf;
        y = y_buf;

        if(buffer[WIDTH-1] == 0) begin
            x_buf = signed'(x) + (signed'(y) >>> 17);
            y_buf = signed'(y) - (signed'(x) >>> 17);
            buffer = buffer - THETA_17;
        end else begin
            x_buf = signed'(x) - (signed'(y) >>> 17);
            y_buf = signed'(y) + (signed'(x) >>> 17);
            buffer = buffer + THETA_17;
        end   
        x = x_buf;
        y = y_buf;

        if(theta > 90) begin
            duty_buf = 32'((64'(x) * 64'(signed'(R17_INV))) >> FRA);
        end else begin
            duty_buf = 32'((64'(y) * 64'(signed'(R17_INV))) >> FRA);
        end
        duty = duty_buf[WIDTH-2:FRA];
    end
endmodule
