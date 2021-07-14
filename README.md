# CORDIC sin_pwm

CORDIC$B$G<BAu$7$?(Bsin$B$N7W;;$9$k$d$D(B
![kekka](chart.png)

## Features

* sin_pwm.sv$B$,K\BN(B
* $BF~NO(B8bit, $B=PNO(B8bit
* $BF~NO$O(B0~180$B!k$^$GBP1~!"=PNO$H$7$F(Bsin(input) * 100$B$rJV$9(B
* $BAH$_9g$o$;2sO)$@$1$G<BAu$7$F$k$N$GF~NO8eB(:B$K=PNO$,7h$^$k(B
* 181$B!k0J>e$rF~NO$9$k$H;`$L(B

## usage

$B$3$s$J46$8$G;H$C$F$b$m$F(B

```SystemVerilog
module test_module (...);

    sin_pwm sin(
        .theta( kakudo ),
        .duty( du_ty )
    );

endmodule
```

```
make ; make run
``` 
$B$G(B 0~180$B!k$rF~NO$7$?;~$N%7%_%e%l!<%7%g%s$,8+$i$l$k(B
