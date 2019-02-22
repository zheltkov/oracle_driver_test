# oracle_driver_test
test cursor leak in 18 oracle client

# Компиляция



###ORACLE 11
```
$ export LD_LIBRARY_PATH=/opt/oracle/product/11.2.0/client_1/lib
$ /opt/oracle/product/11.2.0/client_1/bin/proc iname=test_curs test.pc && gcc -O3 -I/opt/oracle/product/11.2.0/client_1/precomp/public -L/opt/oracle/product/11.2.0/client_1/lib -lclntsh test.c -o test_curs11
$ ldd ./test_curs11
$ ./test_curs11
```

###ORACLE 12
```
$ export LD_LIBRARY_PATH=/opt/oracle/product/12.2.0/client_1/lib
$ /opt/oracle/product/12.2.0/client_1/bin/proc iname=test_curs test.pc && gcc -O3 -I/opt/oracle/product/12.2.0/client_1/precomp/public -L/opt/oracle/product/12.2.0/client_1/lib -lclntsh test.c -o test_curs12
$ ldd ./test_curs12
$ ./test_curs12
```

###ORACLE 18

```
$ export LD_LIBRARY_PATH=/opt/oracle/product/18.3/client_1/lib
$ /opt/oracle/product/18.3/client_1/bin/proc iname=test_curs test.pc && gcc -O3 -I/opt/oracle/product/18.3/client_1/precomp/public -L/opt/oracle/product/18.3/client_1/lib -lclntsh test.c -o test_curs18
$ ldd ./test_curs18
$ ./test_curs18
```

