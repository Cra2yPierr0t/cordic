all:
	verilator --cc -Wno-lint --top-module sin_pwm sin_pwm.sv --exe sin_pwm_tb.cpp
	cd ./obj_dir ; make -j -f Vsin_pwm.mk Vsin_pwm

run:
	./obj_dir/Vsin_pwm

clean:
	rm -r obj_dir
	rm a.out
