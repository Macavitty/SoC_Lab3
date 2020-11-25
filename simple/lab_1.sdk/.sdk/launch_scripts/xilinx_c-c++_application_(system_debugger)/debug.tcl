connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Nexys4DDR 210292709610A" && level==0} -index 0
fpga -file E:/University/4course/SoC/Labs/1/V2/SoC_Lab1/lab_1.runs/impl_1/design_1_wrapper.bit
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Nexys4DDR 210292709610A"} -index 0
rst -system
after 3000
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Nexys4DDR 210292709610A"} -index 0
dow E:/University/4course/SoC/Labs/1/V2/SoC_Lab1/lab_1.sdk/lab_1/Debug/lab_1.elf
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Nexys4DDR 210292709610A"} -index 0
con
