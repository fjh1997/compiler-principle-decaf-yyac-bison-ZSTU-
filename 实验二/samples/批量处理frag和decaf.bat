@echo off
echo "说明:把pp2.exe文件和frag与decaf文件放到同一目录下即可"
pause
setlocal EnableDelayedExpansion

for %%n in (*.frag) do (

pp2 "%%n">"%%n.my"

)

for %%n in (*.decaf) do (

pp2 "%%n">"%%n.my"

)