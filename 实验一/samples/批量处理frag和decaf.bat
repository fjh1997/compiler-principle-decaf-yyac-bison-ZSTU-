@echo off
echo "说明:把pp1.exe文件和frag与decaf文件放到同一目录下即可"
pause
setlocal EnableDelayedExpansion

for %%n in (*.frag) do (

pp1 "%%n">"%%n.my"

)

for %%n in (*.decaf) do (

pp1 "%%n">"%%n.my"

)