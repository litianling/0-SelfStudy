onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib forw_back_opt

do {wave.do}

view wave
view structure
view signals

do {forw_back.udo}

run -all

quit -force
