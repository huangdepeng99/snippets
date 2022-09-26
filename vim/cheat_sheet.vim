" vim cheat sheet
" ===============
"
" 这个文件用来记录我在使用 vim 的过程中用到的一些有用的 Ex 命令

" 1. 将缓冲区(buffer)中和模式(pattern)相匹配的所有行输出到指定的文件(file)中
" help :global, help :write, help :print
" 注：是否觉得 Ex 命令 global 和实用程序 grep (g/re/p) 有几分相似
g/{pattern}/.w! >> {file}

