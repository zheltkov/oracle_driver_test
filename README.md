# oracle_driver_test
test cursor leak in 18 oracle client

Компиляция

$ export LD_LIBRARY_PATH=/opt/oracle/product/12.2.0/client_1/lib:


ORACLE 12

$ /opt/oracle/product/12.2.0/client_1/bin/proc iname=test_curs test.pc && gcc -I/opt/oracle/product/12.2.0/client_1/precomp/public -L/opt/oracle/product/12.2.0/client_1/lib -lclntsh test.c -o test_curs12


ORACLE 18

$ proc iname=test_curs test.pc && gcc -I$ORACLE_HOME/precomp/public -L$ORACLE_HOME/lib -lclntsh test.c -o test_curs18

