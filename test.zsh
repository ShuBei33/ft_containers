#!/bin/zsh
#
#

make re && ./containers > logFT && make re DEFINE=-DSTD && ./containers > logSTD;
diff logFT logSTD
return 0
