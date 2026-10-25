# unix-utils


Coding classic unix utility programs in C. 
Occassionally adding better output and messaging. 

### utils

touch - open
ls    - openat, getdents, close, write, fstat / fcntl
cat   - fopen, fgetc, putchar
mkdir - mkdir
mv    - stat, rename
rm    - lstat, unlink, rmdir, opendir, readdir
find  - lstat, strstr, opendir, readdir

### installing system wide

create the binary
```
clang program.c -o program
```
install executable into directory on `PATH`
```
sudo install -m 755 program /usr/local/bin/program
```

