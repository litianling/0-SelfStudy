export PATH=D:/Xilinx/Vivado/2019.1/msys64/usr/bin;D:/Xilinx/Vivado/2019.1/msys64/mingw64/bin;D:/Xilinx/Vivado/2019.1/bin;D:/Xilinx/Vivado/2019.1/win64/bin;D:/Xilinx/Vivado/2019.1/win64/tools/bin;D:/Xilinx/Vivado/2019.1/bin;D:/Xilinx/Vivado/2019.1/lib/win64.o;D:/Xilinx/Vivado/2019.1/tps/win64/jre9.0.4/bin/server;D:/Xilinx/Vivado/2019.1/tps/win64/jre9.0.4/bin;D:/Xilinx/SDK/2019.1/bin;D:/Xilinx/Vivado/2019.1/ids_lite/ISE/bin/nt64;D:/Xilinx/Vivado/2019.1/ids_lite/ISE/lib/nt64;D:\Xilinx\Vivado\2019.1\bin\..\msys64\mingw64\bin;D:\Xilinx\Vivado\2019.1\bin\..\msys64\usr\bin;D:/Xilinx/Vivado/2019.1/msys64/usr/bin;D:/Xilinx/Vivado/2019.1/msys64/mingw64/bin;D:/Xilinx/Vivado/2019.1/win64/bin;D:/Xilinx/Vivado/2019.1/win64/tools/bin;C:\mingw64\bin;c:\mingw\bin;c:\msys\1.0\bin;C:\Python310\Scripts\;C:\Python310\;D:\Python\Anaconda3;D:\Python\Anaconda3\Library\mingw-w64\bin;D:\Python\Anaconda3\Library\usr\bin;D:\Python\Anaconda3\Library\bin;D:\Python\Anaconda3\Scripts;D:\VMware\VMware Workstation\bin\;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;D:\Git\cmd;D:\adb_serves\platform-tools;D:\MATLAB\R2017b\runtime\win64;D:\MATLAB\R2017b\bin;C:\mips-mingw32\bin;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Users\LTL\AppData\Local\Microsoft\WindowsApps;;D:\Python\PyCharm 2021.2.3\bin;C:\Users\LTL\AppData\Roaming\npm;D:/Xilinx/Vivado/2019.1\tps\mingw\6.2.0\win64.o\nt\bin;D:/Xilinx/Vivado/2019.1\tps\mingw\6.2.0\win64.o\nt\libexec\gcc\x86_64-w64-mingw32\6.2.0;D:/Xilinx/Vivado/2019.1/win64/tools/fpo_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/fft_v9_1;D:/Xilinx/Vivado/2019.1/win64/tools/opencv;D:/Xilinx/Vivado/2019.1/win64/tools/fir_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/dds_v6_0;D:/Xilinx/Vivado/2019.1/win64/lib/csim;D:/Xilinx/Vivado/2019.1/win64/tools/fpo_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/fft_v9_1;D:/Xilinx/Vivado/2019.1/win64/tools/opencv;D:/Xilinx/Vivado/2019.1/win64/tools/fir_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/dds_v6_0;D:/Xilinx/Vivado/2019.1/win64/lib/csim
export LD_LIBRARY_PATH=D:/Xilinx/Vivado/2019.1/win64/tools/gdb_v7_2;D:/Xilinx/Vivado/2019.1/tps/win64/dot-2.28/lib;D:/Xilinx/Vivado/2019.1/win64/bin;D:/Xilinx/Vivado/2019.1/win64/tools/gdb_v7_2;D:/Xilinx/Vivado/2019.1/tps/win64/dot-2.28/lib;D:/Xilinx/Vivado/2019.1/win64/bin;D:/Xilinx/Vivado/2019.1/win64/tools/fpo_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/fft_v9_1;D:/Xilinx/Vivado/2019.1/win64/tools/opencv;D:/Xilinx/Vivado/2019.1/win64/tools/fir_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/dds_v6_0;D:/Xilinx/Vivado/2019.1/win64/lib/csim;D:/Xilinx/Vivado/2019.1/win64/tools/fpo_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/fft_v9_1;D:/Xilinx/Vivado/2019.1/win64/tools/opencv;D:/Xilinx/Vivado/2019.1/win64/tools/fir_v7_0;D:/Xilinx/Vivado/2019.1/win64/tools/dds_v6_0;D:/Xilinx/Vivado/2019.1/win64/lib/csim
export HDI_APPROOT=D:/Xilinx/Vivado/2019.1
export XILINX_OPENCL_CLANG=D:/Xilinx/Vivado/2019.1/win64/tools/clang
export RDI_PLATFORM=win64
bugpoint -mlimit=32000  --load libhls_support.so  --load libhls_bugpoint.so  -hls -strip  -function-uniquify -auto-function-inline -globaldce  -ptrArgReplace -mem2reg -dce  -reset-lda  -loop-simplify -indvars -licm -loop-dep  -loop-bound -licm -loop-simplify -flattenloopnest  -array-flatten -gvn -instcombine -dce  -array-map -dce -func-legal  -gvn -adce -instcombine -cfgopt -simplifycfg -loop-simplify   -array-burst -promote-global-argument -dce  -ptrLegalization -axi4-lower -array-seg-normalize  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa -gvn -gvn  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa -dse -adse -adce -licm  -inst-simplify -dce  -globaldce -instcombine -array-stream -eliminate-keepreads -instcombine  -dce   -deadargelim -doublePtrSimplify  -doublePtrElim -dce -doublePtrSimplify -promote-dbg-pointer  -dce -scalarrepl -mem2reg -disaggr -norm-name -mem2reg  -instcombine  -dse -adse -adce -ptrLegalization -dce -auto-rom-infer -array-flatten -dce -instcombine -check-doubleptr  -loop-rot -constprop -cfgopt -simplifycfg -loop-simplify -indvars -pointer-simplify -dce -loop-bound  -loop-simplify -loop-preproc  -constprop -global-constprop -gvn -mem2reg -instcombine -dce  -loop-bound  -loop-merge -dce  -bitwidthmin  -deadargelim -dce  -canonicalize-dataflow -dce  -scalar-propagation -deadargelim -globaldce -mem2reg  -read-loop-dep  -interface-preproc -directive-preproc -interface-gen  -bram-byte-enable  -deadargelim -inst-simplify -dce  -gvn -mem2reg -instcombine -dce -adse  -loop-bound  -instcombine -cfgopt -simplifycfg -loop-simplify  -clean-region -io-protocol  -find-region -mem2reg  -bitop-raise -complex-op-raise -inst-simplify -inst-rectify -instcombine -adce -deadargelim  -loop-simplify -phi-opt -bitop-raise  -cfgopt -simplifycfg -strip-dead-prototypes  -interface-lower -bitop-lower -intrinsic-lower -auto-function-inline  -basicaa -aggrmodref-aa -globalsmodref-aa -aggr-aa  -inst-simplify -simplifycfg   -loop-simplify  -mergereturn -inst-simplify -inst-rectify  -dce -load-elim -bitop-lower  -loop-rewind -pointer-simplify -dce -cfgopt  -dce -loop-bound -loop-dep -read-loop-dep -dce  -check-stream -norm-name -legalize  -validate-dataflow -inst-clarity -bitwidth -dump-loop-dep-to-ir -check-all-ssdm  C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_2/solution1/.autopilot/db/a.o.2.bc
llvm-dis bugpoint-reduced-simplified.bc 
