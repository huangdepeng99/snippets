" vim cheat sheet
" ===============
"
" 这个文件用来记录我在使用 vim 的过程中用到的一些有用的 Ex 命令

" 1. 将缓冲区(buffer)中和模式(pattern)相匹配的所有行输出到指定的文件(file)中
" help :global, help :write, help :print
" 注：是否觉得 Ex 命令 global 和实用程序 grep (g/re/p) 有几分相似
g/{pattern}/.w! >> {file}

" 2. 将下面第一行的句子转化为下面第二行的形式
" ---> SFC_RST_N      92.6100       3142.6100
" ---> list(92.6100   3142.6100)    "SFC_RST_N"
" (方法1)
" help :execute, help :normal
exe "{range}normal! \e0\"xyiWW\"yyiWW\"zyiW0Clist(\<C-r>y\t\t\<C-r>z)\t\t\"\<C-r>x\"\e"
" (方法2)
" help :substitute
[range]s/^\(\S\+\)\s\+\(\S\+\)\s\+\(\S\+\)$/list(\2\t\t\3)\t\t"\1"/
" (方法2-简洁版)
[range]s/\v^(\S+)\s+(\S+)\s+(\S+)$/list(\2\t\t\3)\t\t"\1"/

