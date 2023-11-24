![](https://github.com/fanasina/DOc/blob/master/new_screen.gif)

# ytest 
C library like `gtest / gmock`  like, but works mainly with functions 

## env
linux

## install
### generate the library
to create `libytest.so`
```
make
```
or 
```
./kreate_library_ytest.sh
```
### install in local machine
We have 2 options: setup env, or install
#### set env
```
chmod +x set_env.sh
```
to set local env: (only in the active terminal)
```
. set_env.sh 
```
If you want permanent variable env:
```
./set_env.sh ~/.bashrc
```
or 
```
./set_env.sh /path/file/local/env/shell
```



####  install by copying files and directory
This creates a permanent copy of `libytest.so` and the file headers of `ytest: include_ytest/include/*` in local machine
```
sudo make install
```
or
```
sudo ./install.sh
```

### uninstall
like install, there are 2 methods: unset env, or uninstall
#### unset env
```
chmod +x unset_env.sh
```
to unset variables env in local terminal:
```
. unset_env.sh
```
to unset variable permanently:  need to have the same arg as `set_env.sh` 
```
./unset_env.sh ~/.bashrc
```
or 
```
./unset_env.sh /path/file/local/env/shell
```



#### uninstall script remove:
this remove from locale machine env all files and directory copied by `make install` or `./install.sh`
```
sudo make uninstall
```
or
```
sudo ./uninstall.sh
```

## using lib ytest
if you do not install the library:
### include
copy the headers in `include_ytest/include` to include directory, for example
```
cp -r include_ytest/include/* /usr/include/
```
or
```
cp -r include_ytest/include/* ~/.local/include/
```
if `/usr/include` or `~/.local/include` is in `CPATH`
or
execute 
```
export CPATH=/Path_to_dir_ytest/include_ytest/include:$CPATH
``` 
or add the precedent line  in `~/.bashrc`.
 
We can avoid these copy or export to CPATH env by adding 
```
-I/Path_to_dir_ytest/include_ytest/include
``` 
when compiling our test.
### library
Also, we need to add `-L/Path_to_dir_ytest`  when compiling our test, this `/Path_to_dir_ytest` contain `libytest.so`. 
Or we can copy `libytest.so` in a directory in `/usr/lib/` or other directory in 
```
echo $LD_LIBRARY_PATH
```
Or, copy `libytest.so` in `/path_to/lib_ytest/` and then 
add 
```
export LD_LIBRARY_PATH=/path_to/lib_ytest:$LD_LIBRARY_PATH
```  
in `~/.bashrc`.


## test examples
`test/is_good.c` and `permutation_test/is_good.c`

## compile and run the example
```
cd test
make 
./launch_is_good_m
```
or
```
chmod +x compile.sh
./compile.sh "is_good.c" 
./launch_is_good_c
```
## error
if we have  /* if the library is not installed */
```
./launch_is_good_m
./launch_is_good_m: error while loading shared libraries: libytest.so: cannot open shared object file: No such file or directory
```` 
we need to add LD_LIBRARY_PATH env permanently or 
```
LD_LIBRARY_PATH=.. ./launch_is_good_m 
```
i.e
```
LD_LIBRARY_PATH=/path_to/lib_ytest ./launch_is_good_m 
```
it is th same if `./launch_is_good_c` does not find `libytest.so` 



## some compile options
### if need to print debug with PRINT_DEBUG_
`PRINT_DEBUG` is the macro to print debug in this ytest lib, but in `tools_t.h` we define `PRINT_DEBUG_` to print debug beut it need to activate DEBUG macro by `-D DEBUG=1`option so, if we need to print debug in tools_t we have to:
```
./kreate_library_ytest "-D DEBUG=1"
cd test
./compile "is_good.c"  "-D DEBUG=1"
```


### if need gdb
```
./kreate_library_ytest "-g"
cd test
./compile "is_good.c"  "-g"
```

so we need to use `./launch_is_good_c` to active these options

## launch options if using run_all_tests_args(argc, argv);
By default `./launch_is_good_{c,m}` is on 1 thread but we can add some options to run tests in parallel, or change colors, to disable progress bar, ..., to print help

### help
`./launch_is_good_c -h`
```
usage: ./launch_is_good_c [OPTIONS] [<ARGS>] 

  or : ./launch_is_good_c [OPTIONS]=[<ARGS>]

OPTIONS
	 -h, --help 
		print help, options variables

	 -d, --debug 
		to print debug by using PRINT_DEBUG, by default PRINT_DEBUG is off

	 -g, --gtestlike 
		to have gtest hook like!

	 -p <NB>, --parallel <NB>, -p=<NB>, --parallel=<NB>
		by default the program ran in sequantial all test, 
		if this option is set, the program run tests on NB threads.
		Each thread pull up one test out the list of all test not yet executed,
		and execute it, until the list is empty 

	 -t <unit>, --time <unit>, -t=<unit>, --time=<unit>  
		by default unit is millisecons ms, the other of unit are choices are second (or s), and nanosecond (or ns)
		ex: -t ns or -t=nanosecond or --time=n to set nanosecond unit

	 -u , --unicolour
		by default, the result is colored, if you choice this option, it prints with default color

	 -r , --remove
		if the option parallel is choosen the result on each thread is record in separate files,
		this option remove the file logs of each thread after all tests.

	 -s <file>, --savelog <file>, -s=file, --savelog=file
		this option save the global ordered result in 'file',
		  

	 -n=<NUM1>,<NUM2> <NUM3>... ,--numtests=<NUM1>,<NUM2>...
		this option allow to execute only the selected numbers of tests (in the order in file test)
		ex: -n=0,6,3 8 to execute   the tests 0,3,6,8 (if the number is less than the count of all tests)

	 -l=<NAME1>,<NAME2> <NAME3>... ,--listests=<NAME1>,<NAME2>...<NAMEn>
		this option allow to execute only the selected name of tests. It allows empty name by using '-l=,'
		ex:  -l=name0,,name2 : execute only (if they exist): TEST(name0),TEST(),TEST(name2)

	 -b <BPRGSS>, --bar_progress <BPRGSS>, -b=BPRGSS, --bar_progress=BPRGSS. Example: -b="#_c"
		this option change progression bar if it is active. The first character ('#') fills the bar
		the second char ('_') fills the other part of bar. the bar is colored if the 3rd char is 'c' and not if different.
		by default the progress bar is active and the option is -b="  c", if need not colored, we can put -b="  n" option.

	 -z=<option> 
		this option is to set option=0,
		for example, -z=progress is to not load progress bar, it is need if we want to redirect (pipe) the result to file.
		other option: -z=log_parallel (to avoid logs not ordered when parallel tests which is loged by default)

```

For example, to launch tests (`test/is_good.c`) on 4 threads, using unicolor(black&white), and remove logs when all tests are done:
```
./launch_is_good_c -p 4 -r -u
```


# How to compile test
## include path
We need to add `/path_to/include_ytest/include` in `CPATH` by ```export CPATH=/path_to/include_ytest/include:$CPATH``` in terminal or in `~/.bashrc` file for example. 

Or we can add ```-I/path_to/include_ytest/include``` when compiling. 
## library path
The others option when compiling are `-L/path_to/directorytest` this path must contain `libytest.so` generated by `make` or `./kreate_library_ytest` or we can put this path in `LD_LIBRARY_PATH`.
## -lytest
And we must add `-lytest` to add the shared library in compilation.

# How to create test (ftest)
## include
```
#include "ftest/ftest.h"

TEST(nametest){ 
	EXPECT_EQ(1,1);
}
/* allow empty nametest, e.g*/
TEST(){}
/* allow duplicate name test, to have suit test */
TEST(){
	EXPECT_TRUE(true);
}
```

## in function main 
### if using options:
```
int main(int arc, char** argv){
	run_all_tests_args(argc, argv);
	return 0;
}
```
### if only use sequential tests
```
int main(){
	run_all_tests();
	return 0;
}
```
### if use only parrallel tests
```
int main(){
	run_all_tests_parallel(4); /* to use 4 threads */
	return 0;
}
```

# FMOCK 
## How to create fmock

```
#include "fmock/fmock.h"
```
outside all functions:
```
MOCK_FUNC(returnType, name_function_mock,(prototype of the function with paranthesis),(args when call the funct with parathesis))
/* use (returnType) in parathesis if the returType has more than 1 words for example (long int) or (struct someStruct) */
```
For example, to create a function mock as signature:
```
int f_mock(int a,int b);
```
we use
```
MOCK_FUNC(int, f_mock,(int a,int b),(a,b))
```
args:
```
returnType: 		 						int,
name_function_mock:	 						f_mock,
args prototype with paranthesis:					(int a,int b),
args variable names with parathesis (same variable names as prototype):	(a,b)
```
## print variables 
We may define a function to print variables of the mock function, it is usefull in logs, the macro has almost the same args as MOCK_FUNC, without returnType wich is always `char*`.
For example with `f_mock` we define:
```
STR_PRINT_CUR_VAR(f_mock, (int a,int b),(a,b)){
  char *ret=malloc(150);
  sprintf(ret,"(int)a: %d, (int)b: %d",a,b);
  return ret;
}
```
## define expect call
```
EXPECT_MOCK_CALL(int, f_mock, (int a,int b), (a<b), 3){
  return a+b;
}
```
args:
```
returnType: 		 							int,
name_function_mock:	 							f_mock,
arg prototype of the function with paranthesis:					(int a,int b),
conditions to check on args before calling the function:(bool expression):	(a<b)
number of repetition response (number of call times):				3	  
```
## define will call
```
WILL_MOCK_CALL(int, f_mock, (int a,int b), (a==b), 1){
  return a*b;
}
```
same args as EXPECT_MOCK_CALL, the difference is, the EXPECT_MOCK_CALL has to be called by the test earlier, but not  WILL_MOCK_CALL.

## init call and call
in TEST environement, we may use macro `INIT_CALLER_MOCK(f_mock);` before calling `f_mock` to have explicit logs again!

Call function mock is the same as other normal functions.

Example:
```
TEST(f_mock_test){
	INIT_CALLER_MOCK(f_mock);
	PRINTF(" first call: %d\n",f_mock(2,3)); 
 	PRINTF(" second call: %d\n",f_mock(3,3));
}
```
# PRINTF
We may use standard printf function, but I provide a macro PRINTF to allow us record logs in files and also ordered logs when we use parallel tests.

args are the same as `printf` stdio.h function.
example:
```
PRINTF("hello\n");
```
I introduce also an alias `LOG` for `PRINTF`


![](https://github.com/fanasina/DOc/blob/master/example_ftest.gif)

