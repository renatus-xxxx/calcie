zcc +msx -create-app -O3 -subtype=msxdos calcie.c -lm -bn CALCIE.COM
del CALCIE.img
move /y CALCIE.COM bin
cd bin
START /WAIT DISKMGR.exe -A -F -C CALCIE.DSK CALCIE.COM
START /WAIT DISKMGR.exe -A -F -C CALCIE.DSK AUTOEXEC.BAT
cd ../
