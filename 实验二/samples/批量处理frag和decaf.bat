@echo off
echo "˵��:��pp2.exe�ļ���frag��decaf�ļ��ŵ�ͬһĿ¼�¼���"
pause
setlocal EnableDelayedExpansion

for %%n in (*.frag) do (

pp2 "%%n">"%%n.my"

)

for %%n in (*.decaf) do (

pp2 "%%n">"%%n.my"

)