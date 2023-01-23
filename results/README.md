# Results
## How to read
hexdump command:
```sh
$ hexdump -e '/4 " %d "' foo.dat
```

Scilab:

```scilab
m = mopen('foo.dat', 'rb');
result = mget(120000, m);
mclose(m);
```

C:
```c
int result[120000];
FILE * fp = fopen("foo.dat", "rb");
fread(result, sizeof(result), 1, fp);
fclose(fp);
```

The unit(resolution) is 20[nano seconds].


