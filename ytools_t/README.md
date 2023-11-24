# ytools_t

Set of tools containing a few functions and comparison macros. We've also redefined the basic types to standardize macros that expect a type formed from a single word.

## types
```
TYPE_CHAR == char; TYPE_U_CHAR == unsigned char; TYPE_INT == int; 
TYPE_U_INT == unsigned int; TYPE_L_INT == long int; TYPE_U_L_INT == unsigned long int
TYPE_SIZE_T == size_t; TYPE_FLOAT == float; TYPE_DOUBLE == double; 
TYPE_L_DOUBLE == long double; TYPE_STRING == char*
```

## Precision
`PRECISION_TYPE_FLOAT,  PRECISION_TYPE_DOUBLE, PRECISION_TYPE_L_DOUBLE` values can be modified on compilation with :
```
-D PRECISION_TYPE_FLOAT=100000000
-D PRECISION_TYPE_DOUBLE=100000000000 
-D PRECISION_TYPE_L_DOUBLE=100000000000000
```
for example, these values are the default precision for each type.

Precision values for other types are 1.


