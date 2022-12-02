C_FLAGS="-CFLAGS \"-std=c++11 -Wall -g -O0 -DAUXS\""

LD_FLAGS="-LDFLAGS \"-pthread -lutil\""

CC_FILES="dv/common_functions.cc \
dv/auxloader.cc \
dv/elfloader.cc \
dv/toplevel.cc"

WARNING_FLAGS="-Wall \
-Wno-fatal \
-Wno-PINCONNECTEMPTY \
-Wno-BLKANDNBLK \
-Wno-DECLFILENAME \
-Wno-PINMISSING \
-Wno-WIDTH \
-Wno-SELRANGE \
-Wno-WIDTHCONCAT \
-Wno-VARHIDDEN \
-Wno-LATCH \
-Wno-SYMRSVDWORD \
-Wno-CASEINCOMPLETE \
-Wno-UNSIGNED \
-Wno-UNDRIVEN \
-Wno-UNUSEDPARAM \
-Wno-UNUSEDSIGNAL \
-Wno-ALWCOMBORDER \
-Wno-IMPORTSTAR \
-Wno-ENUMVALUE \
-Wno-SYNCASYNCNET \
-Wno-BLKSEQ \
-Wno-LITENDIAN \
-Wno-UNOPTFLAT"

TRACE_FLAGS="--trace-fst \
--trace-structs \
--trace-params \
--trace-max-array 1024"

# H_FILES=dv/elf.h \
# dv/ticks.h \
# dv/testbench.h

SV_FILES=src/ariane_tiny_soc.sv

verilator --cc $SV_FILES $WARNING_FLAGS $TRACE_FLAGS \
    --exe -Idv $CC_FILES \
    -CFLAGS "-std=c++11 -Wall -O0 -DAUXS" \
    -LDFLAGS "-pthread -lutil"