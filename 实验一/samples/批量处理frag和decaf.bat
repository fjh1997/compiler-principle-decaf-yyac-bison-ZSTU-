@echo off
echo "˵��:��pp1.exe�ļ���frag��decaf�ļ��ŵ�ͬһĿ¼�¼���"
pause
setlocal EnableDelayedExpansion

for %%n in (*.frag) do (

pp1 "%%n">"%%n.my"

)

for %%n in (*.decaf) do (

pp1 "%%n">"%%n.my"

)