# CORDIC sin_pwm

CORDICで実装したsinの計算するやつ
![kekka](chart.png)

## Features

* sin_pwm.svが本体
* 入力8bit, 出力8bit
* 入力は0~180°まで対応、出力としてsin(input) * 100を返す
* 組み合わせ回路だけで実装してるので入力後即座に出力が決まる
* 181°以上を入力すると死ぬ

## usage

こんな感じで使ってもろて

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
で 0~180°を入力した時のシミュレーションが見られる
