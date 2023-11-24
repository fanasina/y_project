
launch_is_good_c:     format de fichier elf64-x86-64


Déassemblage de la section .init :

0000000000002000 <_init>:
    2000:	f3 0f 1e fa          	endbr64 
    2004:	48 83 ec 08          	sub    rsp,0x8
    2008:	48 8b 05 99 ef 00 00 	mov    rax,QWORD PTR [rip+0xef99]        # 10fa8 <__gmon_start__@Base>
    200f:	48 85 c0             	test   rax,rax
    2012:	74 02                	je     2016 <_init+0x16>
    2014:	ff d0                	call   rax
    2016:	48 83 c4 08          	add    rsp,0x8
    201a:	c3                   	ret    

Déassemblage de la section .plt :

0000000000002020 <.plt>:
    2020:	ff 35 32 ee 00 00    	push   QWORD PTR [rip+0xee32]        # 10e58 <_GLOBAL_OFFSET_TABLE_+0x8>
    2026:	f2 ff 25 33 ee 00 00 	bnd jmp QWORD PTR [rip+0xee33]        # 10e60 <_GLOBAL_OFFSET_TABLE_+0x10>
    202d:	0f 1f 00             	nop    DWORD PTR [rax]
    2030:	f3 0f 1e fa          	endbr64 
    2034:	68 00 00 00 00       	push   0x0
    2039:	f2 e9 e1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    203f:	90                   	nop
    2040:	f3 0f 1e fa          	endbr64 
    2044:	68 01 00 00 00       	push   0x1
    2049:	f2 e9 d1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    204f:	90                   	nop
    2050:	f3 0f 1e fa          	endbr64 
    2054:	68 02 00 00 00       	push   0x2
    2059:	f2 e9 c1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    205f:	90                   	nop
    2060:	f3 0f 1e fa          	endbr64 
    2064:	68 03 00 00 00       	push   0x3
    2069:	f2 e9 b1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    206f:	90                   	nop
    2070:	f3 0f 1e fa          	endbr64 
    2074:	68 04 00 00 00       	push   0x4
    2079:	f2 e9 a1 ff ff ff    	bnd jmp 2020 <_init+0x20>
    207f:	90                   	nop
    2080:	f3 0f 1e fa          	endbr64 
    2084:	68 05 00 00 00       	push   0x5
    2089:	f2 e9 91 ff ff ff    	bnd jmp 2020 <_init+0x20>
    208f:	90                   	nop
    2090:	f3 0f 1e fa          	endbr64 
    2094:	68 06 00 00 00       	push   0x6
    2099:	f2 e9 81 ff ff ff    	bnd jmp 2020 <_init+0x20>
    209f:	90                   	nop
    20a0:	f3 0f 1e fa          	endbr64 
    20a4:	68 07 00 00 00       	push   0x7
    20a9:	f2 e9 71 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20af:	90                   	nop
    20b0:	f3 0f 1e fa          	endbr64 
    20b4:	68 08 00 00 00       	push   0x8
    20b9:	f2 e9 61 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20bf:	90                   	nop
    20c0:	f3 0f 1e fa          	endbr64 
    20c4:	68 09 00 00 00       	push   0x9
    20c9:	f2 e9 51 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20cf:	90                   	nop
    20d0:	f3 0f 1e fa          	endbr64 
    20d4:	68 0a 00 00 00       	push   0xa
    20d9:	f2 e9 41 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20df:	90                   	nop
    20e0:	f3 0f 1e fa          	endbr64 
    20e4:	68 0b 00 00 00       	push   0xb
    20e9:	f2 e9 31 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20ef:	90                   	nop
    20f0:	f3 0f 1e fa          	endbr64 
    20f4:	68 0c 00 00 00       	push   0xc
    20f9:	f2 e9 21 ff ff ff    	bnd jmp 2020 <_init+0x20>
    20ff:	90                   	nop
    2100:	f3 0f 1e fa          	endbr64 
    2104:	68 0d 00 00 00       	push   0xd
    2109:	f2 e9 11 ff ff ff    	bnd jmp 2020 <_init+0x20>
    210f:	90                   	nop
    2110:	f3 0f 1e fa          	endbr64 
    2114:	68 0e 00 00 00       	push   0xe
    2119:	f2 e9 01 ff ff ff    	bnd jmp 2020 <_init+0x20>
    211f:	90                   	nop
    2120:	f3 0f 1e fa          	endbr64 
    2124:	68 0f 00 00 00       	push   0xf
    2129:	f2 e9 f1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    212f:	90                   	nop
    2130:	f3 0f 1e fa          	endbr64 
    2134:	68 10 00 00 00       	push   0x10
    2139:	f2 e9 e1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    213f:	90                   	nop
    2140:	f3 0f 1e fa          	endbr64 
    2144:	68 11 00 00 00       	push   0x11
    2149:	f2 e9 d1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    214f:	90                   	nop
    2150:	f3 0f 1e fa          	endbr64 
    2154:	68 12 00 00 00       	push   0x12
    2159:	f2 e9 c1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    215f:	90                   	nop
    2160:	f3 0f 1e fa          	endbr64 
    2164:	68 13 00 00 00       	push   0x13
    2169:	f2 e9 b1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    216f:	90                   	nop
    2170:	f3 0f 1e fa          	endbr64 
    2174:	68 14 00 00 00       	push   0x14
    2179:	f2 e9 a1 fe ff ff    	bnd jmp 2020 <_init+0x20>
    217f:	90                   	nop
    2180:	f3 0f 1e fa          	endbr64 
    2184:	68 15 00 00 00       	push   0x15
    2189:	f2 e9 91 fe ff ff    	bnd jmp 2020 <_init+0x20>
    218f:	90                   	nop
    2190:	f3 0f 1e fa          	endbr64 
    2194:	68 16 00 00 00       	push   0x16
    2199:	f2 e9 81 fe ff ff    	bnd jmp 2020 <_init+0x20>
    219f:	90                   	nop
    21a0:	f3 0f 1e fa          	endbr64 
    21a4:	68 17 00 00 00       	push   0x17
    21a9:	f2 e9 71 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21af:	90                   	nop
    21b0:	f3 0f 1e fa          	endbr64 
    21b4:	68 18 00 00 00       	push   0x18
    21b9:	f2 e9 61 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21bf:	90                   	nop
    21c0:	f3 0f 1e fa          	endbr64 
    21c4:	68 19 00 00 00       	push   0x19
    21c9:	f2 e9 51 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21cf:	90                   	nop
    21d0:	f3 0f 1e fa          	endbr64 
    21d4:	68 1a 00 00 00       	push   0x1a
    21d9:	f2 e9 41 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21df:	90                   	nop
    21e0:	f3 0f 1e fa          	endbr64 
    21e4:	68 1b 00 00 00       	push   0x1b
    21e9:	f2 e9 31 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21ef:	90                   	nop
    21f0:	f3 0f 1e fa          	endbr64 
    21f4:	68 1c 00 00 00       	push   0x1c
    21f9:	f2 e9 21 fe ff ff    	bnd jmp 2020 <_init+0x20>
    21ff:	90                   	nop
    2200:	f3 0f 1e fa          	endbr64 
    2204:	68 1d 00 00 00       	push   0x1d
    2209:	f2 e9 11 fe ff ff    	bnd jmp 2020 <_init+0x20>
    220f:	90                   	nop
    2210:	f3 0f 1e fa          	endbr64 
    2214:	68 1e 00 00 00       	push   0x1e
    2219:	f2 e9 01 fe ff ff    	bnd jmp 2020 <_init+0x20>
    221f:	90                   	nop
    2220:	f3 0f 1e fa          	endbr64 
    2224:	68 1f 00 00 00       	push   0x1f
    2229:	f2 e9 f1 fd ff ff    	bnd jmp 2020 <_init+0x20>
    222f:	90                   	nop
    2230:	f3 0f 1e fa          	endbr64 
    2234:	68 20 00 00 00       	push   0x20
    2239:	f2 e9 e1 fd ff ff    	bnd jmp 2020 <_init+0x20>
    223f:	90                   	nop
    2240:	f3 0f 1e fa          	endbr64 
    2244:	68 21 00 00 00       	push   0x21
    2249:	f2 e9 d1 fd ff ff    	bnd jmp 2020 <_init+0x20>
    224f:	90                   	nop
    2250:	f3 0f 1e fa          	endbr64 
    2254:	68 22 00 00 00       	push   0x22
    2259:	f2 e9 c1 fd ff ff    	bnd jmp 2020 <_init+0x20>
    225f:	90                   	nop

Déassemblage de la section .plt.got :

0000000000002260 <COMPARE_N_TYPE_U_CHAR@plt>:
    2260:	f3 0f 1e fa          	endbr64 
    2264:	f2 ff 25 25 ed 00 00 	bnd jmp QWORD PTR [rip+0xed25]        # 10f90 <COMPARE_N_TYPE_U_CHAR@Base>
    226b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002270 <COMPARE_N_TYPE_CHAR@plt>:
    2270:	f3 0f 1e fa          	endbr64 
    2274:	f2 ff 25 1d ed 00 00 	bnd jmp QWORD PTR [rip+0xed1d]        # 10f98 <COMPARE_N_TYPE_CHAR@Base>
    227b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002280 <COMPARE_N_TYPE_L_DOUBLE@plt>:
    2280:	f3 0f 1e fa          	endbr64 
    2284:	f2 ff 25 15 ed 00 00 	bnd jmp QWORD PTR [rip+0xed15]        # 10fa0 <COMPARE_N_TYPE_L_DOUBLE@Base>
    228b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002290 <COMPARE_N_TYPE_SIZE_T@plt>:
    2290:	f3 0f 1e fa          	endbr64 
    2294:	f2 ff 25 15 ed 00 00 	bnd jmp QWORD PTR [rip+0xed15]        # 10fb0 <COMPARE_N_TYPE_SIZE_T@Base>
    229b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022a0 <COMPARE_N_TYPE_L_INT@plt>:
    22a0:	f3 0f 1e fa          	endbr64 
    22a4:	f2 ff 25 0d ed 00 00 	bnd jmp QWORD PTR [rip+0xed0d]        # 10fb8 <COMPARE_N_TYPE_L_INT@Base>
    22ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022b0 <COMPARE_N_TYPE_FLOAT@plt>:
    22b0:	f3 0f 1e fa          	endbr64 
    22b4:	f2 ff 25 05 ed 00 00 	bnd jmp QWORD PTR [rip+0xed05]        # 10fc0 <COMPARE_N_TYPE_FLOAT@Base>
    22bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022c0 <COMPARE_N_TYPE_U_INT@plt>:
    22c0:	f3 0f 1e fa          	endbr64 
    22c4:	f2 ff 25 fd ec 00 00 	bnd jmp QWORD PTR [rip+0xecfd]        # 10fc8 <COMPARE_N_TYPE_U_INT@Base>
    22cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022d0 <COMPARE_N_TYPE_STRING@plt>:
    22d0:	f3 0f 1e fa          	endbr64 
    22d4:	f2 ff 25 f5 ec 00 00 	bnd jmp QWORD PTR [rip+0xecf5]        # 10fd0 <COMPARE_N_TYPE_STRING@Base>
    22db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022e0 <COMPARE_N_TYPE_U_L_INT@plt>:
    22e0:	f3 0f 1e fa          	endbr64 
    22e4:	f2 ff 25 ed ec 00 00 	bnd jmp QWORD PTR [rip+0xeced]        # 10fd8 <COMPARE_N_TYPE_U_L_INT@Base>
    22eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000022f0 <COMPARE_N_TYPE_INT@plt>:
    22f0:	f3 0f 1e fa          	endbr64 
    22f4:	f2 ff 25 e5 ec 00 00 	bnd jmp QWORD PTR [rip+0xece5]        # 10fe0 <COMPARE_N_TYPE_INT@Base>
    22fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002300 <COMPARE_N_TYPE_DOUBLE@plt>:
    2300:	f3 0f 1e fa          	endbr64 
    2304:	f2 ff 25 dd ec 00 00 	bnd jmp QWORD PTR [rip+0xecdd]        # 10fe8 <COMPARE_N_TYPE_DOUBLE@Base>
    230b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002310 <__cxa_finalize@plt>:
    2310:	f3 0f 1e fa          	endbr64 
    2314:	f2 ff 25 dd ec 00 00 	bnd jmp QWORD PTR [rip+0xecdd]        # 10ff8 <__cxa_finalize@GLIBC_2.2.5>
    231b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Déassemblage de la section .plt.sec :

0000000000002320 <COPY_ARRAY_TYPE_INT@plt>:
    2320:	f3 0f 1e fa          	endbr64 
    2324:	f2 ff 25 3d eb 00 00 	bnd jmp QWORD PTR [rip+0xeb3d]        # 10e68 <COPY_ARRAY_TYPE_INT@Base>
    232b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002330 <free@plt>:
    2330:	f3 0f 1e fa          	endbr64 
    2334:	f2 ff 25 35 eb 00 00 	bnd jmp QWORD PTR [rip+0xeb35]        # 10e70 <free@GLIBC_2.2.5>
    233b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002340 <append_func@plt>:
    2340:	f3 0f 1e fa          	endbr64 
    2344:	f2 ff 25 2d eb 00 00 	bnd jmp QWORD PTR [rip+0xeb2d]        # 10e78 <append_func@Base>
    234b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002350 <open_memstream@plt>:
    2350:	f3 0f 1e fa          	endbr64 
    2354:	f2 ff 25 25 eb 00 00 	bnd jmp QWORD PTR [rip+0xeb25]        # 10e80 <open_memstream@GLIBC_2.2.5>
    235b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002360 <puts@plt>:
    2360:	f3 0f 1e fa          	endbr64 
    2364:	f2 ff 25 1d eb 00 00 	bnd jmp QWORD PTR [rip+0xeb1d]        # 10e88 <puts@GLIBC_2.2.5>
    236b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002370 <COPY_ARRAY_TYPE_L_INT@plt>:
    2370:	f3 0f 1e fa          	endbr64 
    2374:	f2 ff 25 15 eb 00 00 	bnd jmp QWORD PTR [rip+0xeb15]        # 10e90 <COPY_ARRAY_TYPE_L_INT@Base>
    237b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002380 <expected_EQ_name_TYPE_L_INT@plt>:
    2380:	f3 0f 1e fa          	endbr64 
    2384:	f2 ff 25 0d eb 00 00 	bnd jmp QWORD PTR [rip+0xeb0d]        # 10e98 <expected_EQ_name_TYPE_L_INT@Base>
    238b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002390 <qsort@plt>:
    2390:	f3 0f 1e fa          	endbr64 
    2394:	f2 ff 25 05 eb 00 00 	bnd jmp QWORD PTR [rip+0xeb05]        # 10ea0 <qsort@GLIBC_2.2.5>
    239b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023a0 <COPY_ARRAY_TYPE_DOUBLE@plt>:
    23a0:	f3 0f 1e fa          	endbr64 
    23a4:	f2 ff 25 fd ea 00 00 	bnd jmp QWORD PTR [rip+0xeafd]        # 10ea8 <COPY_ARRAY_TYPE_DOUBLE@Base>
    23ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023b0 <fclose@plt>:
    23b0:	f3 0f 1e fa          	endbr64 
    23b4:	f2 ff 25 f5 ea 00 00 	bnd jmp QWORD PTR [rip+0xeaf5]        # 10eb0 <fclose@GLIBC_2.2.5>
    23bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023c0 <__stack_chk_fail@plt>:
    23c0:	f3 0f 1e fa          	endbr64 
    23c4:	f2 ff 25 ed ea 00 00 	bnd jmp QWORD PTR [rip+0xeaed]        # 10eb8 <__stack_chk_fail@GLIBC_2.4>
    23cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023d0 <COPY_ARRAY_TYPE_CHAR@plt>:
    23d0:	f3 0f 1e fa          	endbr64 
    23d4:	f2 ff 25 e5 ea 00 00 	bnd jmp QWORD PTR [rip+0xeae5]        # 10ec0 <COPY_ARRAY_TYPE_CHAR@Base>
    23db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023e0 <fputs@plt>:
    23e0:	f3 0f 1e fa          	endbr64 
    23e4:	f2 ff 25 dd ea 00 00 	bnd jmp QWORD PTR [rip+0xeadd]        # 10ec8 <fputs@GLIBC_2.2.5>
    23eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000023f0 <expected_true_f_name@plt>:
    23f0:	f3 0f 1e fa          	endbr64 
    23f4:	f2 ff 25 d5 ea 00 00 	bnd jmp QWORD PTR [rip+0xead5]        # 10ed0 <expected_true_f_name@Base>
    23fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002400 <expected_EQ_TYPE_L_INT@plt>:
    2400:	f3 0f 1e fa          	endbr64 
    2404:	f2 ff 25 cd ea 00 00 	bnd jmp QWORD PTR [rip+0xeacd]        # 10ed8 <expected_EQ_TYPE_L_INT@Base>
    240b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002410 <COPY_ARRAY_TYPE_U_L_INT@plt>:
    2410:	f3 0f 1e fa          	endbr64 
    2414:	f2 ff 25 c5 ea 00 00 	bnd jmp QWORD PTR [rip+0xeac5]        # 10ee0 <COPY_ARRAY_TYPE_U_L_INT@Base>
    241b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002420 <fputc@plt>:
    2420:	f3 0f 1e fa          	endbr64 
    2424:	f2 ff 25 bd ea 00 00 	bnd jmp QWORD PTR [rip+0xeabd]        # 10ee8 <fputc@GLIBC_2.2.5>
    242b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002430 <COPY_ARRAY_TYPE_U_INT@plt>:
    2430:	f3 0f 1e fa          	endbr64 
    2434:	f2 ff 25 b5 ea 00 00 	bnd jmp QWORD PTR [rip+0xeab5]        # 10ef0 <COPY_ARRAY_TYPE_U_INT@Base>
    243b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002440 <calloc@plt>:
    2440:	f3 0f 1e fa          	endbr64 
    2444:	f2 ff 25 ad ea 00 00 	bnd jmp QWORD PTR [rip+0xeaad]        # 10ef8 <calloc@GLIBC_2.2.5>
    244b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002450 <id_of_thread_executed@plt>:
    2450:	f3 0f 1e fa          	endbr64 
    2454:	f2 ff 25 a5 ea 00 00 	bnd jmp QWORD PTR [rip+0xeaa5]        # 10f00 <id_of_thread_executed@Base>
    245b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002460 <fprintf@plt>:
    2460:	f3 0f 1e fa          	endbr64 
    2464:	f2 ff 25 9d ea 00 00 	bnd jmp QWORD PTR [rip+0xea9d]        # 10f08 <fprintf@GLIBC_2.2.5>
    246b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002470 <expected_true_f@plt>:
    2470:	f3 0f 1e fa          	endbr64 
    2474:	f2 ff 25 95 ea 00 00 	bnd jmp QWORD PTR [rip+0xea95]        # 10f10 <expected_true_f@Base>
    247b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002480 <malloc@plt>:
    2480:	f3 0f 1e fa          	endbr64 
    2484:	f2 ff 25 8d ea 00 00 	bnd jmp QWORD PTR [rip+0xea8d]        # 10f18 <malloc@GLIBC_2.2.5>
    248b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002490 <fflush@plt>:
    2490:	f3 0f 1e fa          	endbr64 
    2494:	f2 ff 25 85 ea 00 00 	bnd jmp QWORD PTR [rip+0xea85]        # 10f20 <fflush@GLIBC_2.2.5>
    249b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024a0 <COPY_ARRAY_TYPE_STRING@plt>:
    24a0:	f3 0f 1e fa          	endbr64 
    24a4:	f2 ff 25 7d ea 00 00 	bnd jmp QWORD PTR [rip+0xea7d]        # 10f28 <COPY_ARRAY_TYPE_STRING@Base>
    24ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024b0 <COPY_ARRAY_TYPE_FLOAT@plt>:
    24b0:	f3 0f 1e fa          	endbr64 
    24b4:	f2 ff 25 75 ea 00 00 	bnd jmp QWORD PTR [rip+0xea75]        # 10f30 <COPY_ARRAY_TYPE_FLOAT@Base>
    24bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024c0 <expected_false_f@plt>:
    24c0:	f3 0f 1e fa          	endbr64 
    24c4:	f2 ff 25 6d ea 00 00 	bnd jmp QWORD PTR [rip+0xea6d]        # 10f38 <expected_false_f@Base>
    24cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024d0 <COPY_ARRAY_TYPE_SIZE_T@plt>:
    24d0:	f3 0f 1e fa          	endbr64 
    24d4:	f2 ff 25 65 ea 00 00 	bnd jmp QWORD PTR [rip+0xea65]        # 10f40 <COPY_ARRAY_TYPE_SIZE_T@Base>
    24db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024e0 <expected_false_f_name@plt>:
    24e0:	f3 0f 1e fa          	endbr64 
    24e4:	f2 ff 25 5d ea 00 00 	bnd jmp QWORD PTR [rip+0xea5d]        # 10f48 <expected_false_f_name@Base>
    24eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000024f0 <run_all_tests_args@plt>:
    24f0:	f3 0f 1e fa          	endbr64 
    24f4:	f2 ff 25 55 ea 00 00 	bnd jmp QWORD PTR [rip+0xea55]        # 10f50 <run_all_tests_args@Base>
    24fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002500 <fopen@plt>:
    2500:	f3 0f 1e fa          	endbr64 
    2504:	f2 ff 25 4d ea 00 00 	bnd jmp QWORD PTR [rip+0xea4d]        # 10f58 <fopen@GLIBC_2.2.5>
    250b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002510 <COPY_ARRAY_TYPE_L_DOUBLE@plt>:
    2510:	f3 0f 1e fa          	endbr64 
    2514:	f2 ff 25 45 ea 00 00 	bnd jmp QWORD PTR [rip+0xea45]        # 10f60 <COPY_ARRAY_TYPE_L_DOUBLE@Base>
    251b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002520 <exit@plt>:
    2520:	f3 0f 1e fa          	endbr64 
    2524:	f2 ff 25 3d ea 00 00 	bnd jmp QWORD PTR [rip+0xea3d]        # 10f68 <exit@GLIBC_2.2.5>
    252b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002530 <TYPE_L_INT_TO_STR@plt>:
    2530:	f3 0f 1e fa          	endbr64 
    2534:	f2 ff 25 35 ea 00 00 	bnd jmp QWORD PTR [rip+0xea35]        # 10f70 <TYPE_L_INT_TO_STR@Base>
    253b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002540 <COPY_ARRAY_TYPE_U_CHAR@plt>:
    2540:	f3 0f 1e fa          	endbr64 
    2544:	f2 ff 25 2d ea 00 00 	bnd jmp QWORD PTR [rip+0xea2d]        # 10f78 <COPY_ARRAY_TYPE_U_CHAR@Base>
    254b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Déassemblage de la section .text :

0000000000002550 <_start>:
    2550:	f3 0f 1e fa          	endbr64 
    2554:	31 ed                	xor    ebp,ebp
    2556:	49 89 d1             	mov    r9,rdx
    2559:	5e                   	pop    rsi
    255a:	48 89 e2             	mov    rdx,rsp
    255d:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    2561:	50                   	push   rax
    2562:	54                   	push   rsp
    2563:	45 31 c0             	xor    r8d,r8d
    2566:	31 c9                	xor    ecx,ecx
    2568:	48 8d 3d ea 85 00 00 	lea    rdi,[rip+0x85ea]        # ab59 <main>
    256f:	ff 15 0b ea 00 00    	call   QWORD PTR [rip+0xea0b]        # 10f80 <__libc_start_main@GLIBC_2.34>
    2575:	f4                   	hlt    
    2576:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    257d:	00 00 00 

0000000000002580 <deregister_tm_clones>:
    2580:	48 8d 3d 89 ea 00 00 	lea    rdi,[rip+0xea89]        # 11010 <__TMC_END__>
    2587:	48 8d 05 82 ea 00 00 	lea    rax,[rip+0xea82]        # 11010 <__TMC_END__>
    258e:	48 39 f8             	cmp    rax,rdi
    2591:	74 15                	je     25a8 <deregister_tm_clones+0x28>
    2593:	48 8b 05 ee e9 00 00 	mov    rax,QWORD PTR [rip+0xe9ee]        # 10f88 <_ITM_deregisterTMCloneTable@Base>
    259a:	48 85 c0             	test   rax,rax
    259d:	74 09                	je     25a8 <deregister_tm_clones+0x28>
    259f:	ff e0                	jmp    rax
    25a1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    25a8:	c3                   	ret    
    25a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000025b0 <register_tm_clones>:
    25b0:	48 8d 3d 59 ea 00 00 	lea    rdi,[rip+0xea59]        # 11010 <__TMC_END__>
    25b7:	48 8d 35 52 ea 00 00 	lea    rsi,[rip+0xea52]        # 11010 <__TMC_END__>
    25be:	48 29 fe             	sub    rsi,rdi
    25c1:	48 89 f0             	mov    rax,rsi
    25c4:	48 c1 ee 3f          	shr    rsi,0x3f
    25c8:	48 c1 f8 03          	sar    rax,0x3
    25cc:	48 01 c6             	add    rsi,rax
    25cf:	48 d1 fe             	sar    rsi,1
    25d2:	74 14                	je     25e8 <register_tm_clones+0x38>
    25d4:	48 8b 05 15 ea 00 00 	mov    rax,QWORD PTR [rip+0xea15]        # 10ff0 <_ITM_registerTMCloneTable@Base>
    25db:	48 85 c0             	test   rax,rax
    25de:	74 08                	je     25e8 <register_tm_clones+0x38>
    25e0:	ff e0                	jmp    rax
    25e2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    25e8:	c3                   	ret    
    25e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000025f0 <__do_global_dtors_aux>:
    25f0:	f3 0f 1e fa          	endbr64 
    25f4:	80 3d 0d eb 00 00 00 	cmp    BYTE PTR [rip+0xeb0d],0x0        # 11108 <completed.0>
    25fb:	75 2b                	jne    2628 <__do_global_dtors_aux+0x38>
    25fd:	55                   	push   rbp
    25fe:	48 83 3d f2 e9 00 00 	cmp    QWORD PTR [rip+0xe9f2],0x0        # 10ff8 <__cxa_finalize@GLIBC_2.2.5>
    2605:	00 
    2606:	48 89 e5             	mov    rbp,rsp
    2609:	74 0c                	je     2617 <__do_global_dtors_aux+0x27>
    260b:	48 8b 3d f6 e9 00 00 	mov    rdi,QWORD PTR [rip+0xe9f6]        # 11008 <__dso_handle>
    2612:	e8 f9 fc ff ff       	call   2310 <__cxa_finalize@plt>
    2617:	e8 64 ff ff ff       	call   2580 <deregister_tm_clones>
    261c:	c6 05 e5 ea 00 00 01 	mov    BYTE PTR [rip+0xeae5],0x1        # 11108 <completed.0>
    2623:	5d                   	pop    rbp
    2624:	c3                   	ret    
    2625:	0f 1f 00             	nop    DWORD PTR [rax]
    2628:	c3                   	ret    
    2629:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000002630 <frame_dummy>:
    2630:	f3 0f 1e fa          	endbr64 
    2634:	e9 77 ff ff ff       	jmp    25b0 <register_tm_clones>

0000000000002639 <append_test_size_permutation0>:
    2639:	f3 0f 1e fa          	endbr64 
    263d:	55                   	push   rbp
    263e:	48 89 e5             	mov    rbp,rsp
    2641:	48 8d 05 d8 b9 00 00 	lea    rax,[rip+0xb9d8]        # e020 <_IO_stdin_used+0x20>
    2648:	48 89 c6             	mov    rsi,rax
    264b:	48 8d 05 0a 00 00 00 	lea    rax,[rip+0xa]        # 265c <TEST_size_permutation____0>
    2652:	48 89 c7             	mov    rdi,rax
    2655:	e8 e6 fc ff ff       	call   2340 <append_func@plt>
    265a:	5d                   	pop    rbp
    265b:	c3                   	ret    

000000000000265c <TEST_size_permutation____0>:
    265c:	f3 0f 1e fa          	endbr64 
    2660:	55                   	push   rbp
    2661:	48 89 e5             	mov    rbp,rsp
    2664:	53                   	push   rbx
    2665:	48 81 ec d8 00 00 00 	sub    rsp,0xd8
    266c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    2673:	00 00 
    2675:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    2679:	31 c0                	xor    eax,eax
    267b:	bf 03 00 00 00       	mov    edi,0x3
    2680:	e8 eb 89 00 00       	call   b070 <CREATE_PERMUTATION_TYPE_CHAR>
    2685:	48 89 85 38 ff ff ff 	mov    QWORD PTR [rbp-0xc8],rax
    268c:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    2693:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    269a:	48 89 d6             	mov    rsi,rdx
    269d:	48 89 c7             	mov    rdi,rax
    26a0:	e8 ab fc ff ff       	call   2350 <open_memstream@plt>
    26a5:	48 89 85 40 ff ff ff 	mov    QWORD PTR [rbp-0xc0],rax
    26ac:	48 83 bd 40 ff ff ff 	cmp    QWORD PTR [rbp-0xc0],0x0
    26b3:	00 
    26b4:	75 38                	jne    26ee <TEST_size_permutation____0+0x92>
    26b6:	48 8b 05 43 ea 00 00 	mov    rax,QWORD PTR [rip+0xea43]        # 11100 <stderr@GLIBC_2.2.5>
    26bd:	4c 8d 05 3c bc 00 00 	lea    r8,[rip+0xbc3c]        # e300 <__func__.4>
    26c4:	b9 19 00 00 00       	mov    ecx,0x19
    26c9:	48 8d 15 74 b9 00 00 	lea    rdx,[rip+0xb974]        # e044 <_IO_stdin_used+0x44>
    26d0:	48 8d 35 79 b9 00 00 	lea    rsi,[rip+0xb979]        # e050 <_IO_stdin_used+0x50>
    26d7:	48 89 c7             	mov    rdi,rax
    26da:	b8 00 00 00 00       	mov    eax,0x0
    26df:	e8 7c fd ff ff       	call   2460 <fprintf@plt>
    26e4:	bf 00 00 00 00       	mov    edi,0x0
    26e9:	e8 32 fe ff ff       	call   2520 <exit@plt>
    26ee:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    26f5:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    26f8:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    26ff:	48 8d 0d 6b b9 00 00 	lea    rcx,[rip+0xb96b]        # e071 <_IO_stdin_used+0x71>
    2706:	48 89 ce             	mov    rsi,rcx
    2709:	48 89 c7             	mov    rdi,rax
    270c:	b8 00 00 00 00       	mov    eax,0x0
    2711:	e8 4a fd ff ff       	call   2460 <fprintf@plt>
    2716:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    271d:	48 89 c7             	mov    rdi,rax
    2720:	e8 6b fd ff ff       	call   2490 <fflush@plt>
    2725:	0f b6 05 64 e9 00 00 	movzx  eax,BYTE PTR [rip+0xe964]        # 11090 <is_parallel_nb@@Base>
    272c:	84 c0                	test   al,al
    272e:	0f 84 01 01 00 00    	je     2835 <TEST_size_permutation____0+0x1d9>
    2734:	e8 17 fd ff ff       	call   2450 <id_of_thread_executed@plt>
    2739:	48 89 85 50 ff ff ff 	mov    QWORD PTR [rbp-0xb0],rax
    2740:	0f b6 05 d9 e8 00 00 	movzx  eax,BYTE PTR [rip+0xe8d9]        # 11020 <log_parallel@@Base>
    2747:	84 c0                	test   al,al
    2749:	74 76                	je     27c1 <TEST_size_permutation____0+0x165>
    274b:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2752:	48 8b 15 cf e8 00 00 	mov    rdx,QWORD PTR [rip+0xe8cf]        # 11028 <stdout@GLIBC_2.2.5>
    2759:	48 89 d6             	mov    rsi,rdx
    275c:	48 89 c7             	mov    rdi,rax
    275f:	e8 7c fc ff ff       	call   23e0 <fputs@plt>
    2764:	48 83 bd 50 ff ff ff 	cmp    QWORD PTR [rbp-0xb0],0x0
    276b:	00 
    276c:	0f 88 30 01 00 00    	js     28a2 <TEST_size_permutation____0+0x246>
    2772:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2779:	48 8b 0d b0 e8 00 00 	mov    rcx,QWORD PTR [rip+0xe8b0]        # 11030 <f_ou_th@@Base>
    2780:	48 8b 95 50 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb0]
    2787:	48 c1 e2 03          	shl    rdx,0x3
    278b:	48 01 ca             	add    rdx,rcx
    278e:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2791:	48 89 d6             	mov    rsi,rdx
    2794:	48 89 c7             	mov    rdi,rax
    2797:	e8 44 fc ff ff       	call   23e0 <fputs@plt>
    279c:	48 8b 15 8d e8 00 00 	mov    rdx,QWORD PTR [rip+0xe88d]        # 11030 <f_ou_th@@Base>
    27a3:	48 8b 85 50 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb0]
    27aa:	48 c1 e0 03          	shl    rax,0x3
    27ae:	48 01 d0             	add    rax,rdx
    27b1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    27b4:	48 89 c7             	mov    rdi,rax
    27b7:	e8 d4 fc ff ff       	call   2490 <fflush@plt>
    27bc:	e9 e1 00 00 00       	jmp    28a2 <TEST_size_permutation____0+0x246>
    27c1:	48 83 bd 50 ff ff ff 	cmp    QWORD PTR [rbp-0xb0],0x0
    27c8:	00 
    27c9:	78 4f                	js     281a <TEST_size_permutation____0+0x1be>
    27cb:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    27d2:	48 8b 0d 57 e8 00 00 	mov    rcx,QWORD PTR [rip+0xe857]        # 11030 <f_ou_th@@Base>
    27d9:	48 8b 95 50 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb0]
    27e0:	48 c1 e2 03          	shl    rdx,0x3
    27e4:	48 01 ca             	add    rdx,rcx
    27e7:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    27ea:	48 89 d6             	mov    rsi,rdx
    27ed:	48 89 c7             	mov    rdi,rax
    27f0:	e8 eb fb ff ff       	call   23e0 <fputs@plt>
    27f5:	48 8b 15 34 e8 00 00 	mov    rdx,QWORD PTR [rip+0xe834]        # 11030 <f_ou_th@@Base>
    27fc:	48 8b 85 50 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb0]
    2803:	48 c1 e0 03          	shl    rax,0x3
    2807:	48 01 d0             	add    rax,rdx
    280a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    280d:	48 89 c7             	mov    rdi,rax
    2810:	e8 7b fc ff ff       	call   2490 <fflush@plt>
    2815:	e9 88 00 00 00       	jmp    28a2 <TEST_size_permutation____0+0x246>
    281a:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2821:	48 8b 15 00 e8 00 00 	mov    rdx,QWORD PTR [rip+0xe800]        # 11028 <stdout@GLIBC_2.2.5>
    2828:	48 89 d6             	mov    rsi,rdx
    282b:	48 89 c7             	mov    rdi,rax
    282e:	e8 ad fb ff ff       	call   23e0 <fputs@plt>
    2833:	eb 6d                	jmp    28a2 <TEST_size_permutation____0+0x246>
    2835:	48 8b 05 fc e7 00 00 	mov    rax,QWORD PTR [rip+0xe7fc]        # 11038 <savelog@@Base>
    283c:	48 85 c0             	test   rax,rax
    283f:	74 48                	je     2889 <TEST_size_permutation____0+0x22d>
    2841:	48 8b 05 f0 e7 00 00 	mov    rax,QWORD PTR [rip+0xe7f0]        # 11038 <savelog@@Base>
    2848:	48 8d 15 30 b8 00 00 	lea    rdx,[rip+0xb830]        # e07f <_IO_stdin_used+0x7f>
    284f:	48 89 d6             	mov    rsi,rdx
    2852:	48 89 c7             	mov    rdi,rax
    2855:	e8 a6 fc ff ff       	call   2500 <fopen@plt>
    285a:	48 89 85 48 ff ff ff 	mov    QWORD PTR [rbp-0xb8],rax
    2861:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2868:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    286f:	48 89 d6             	mov    rsi,rdx
    2872:	48 89 c7             	mov    rdi,rax
    2875:	e8 66 fb ff ff       	call   23e0 <fputs@plt>
    287a:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    2881:	48 89 c7             	mov    rdi,rax
    2884:	e8 27 fb ff ff       	call   23b0 <fclose@plt>
    2889:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2890:	48 8b 15 91 e7 00 00 	mov    rdx,QWORD PTR [rip+0xe791]        # 11028 <stdout@GLIBC_2.2.5>
    2897:	48 89 d6             	mov    rsi,rdx
    289a:	48 89 c7             	mov    rdi,rax
    289d:	e8 3e fb ff ff       	call   23e0 <fputs@plt>
    28a2:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    28a9:	48 89 c7             	mov    rdi,rax
    28ac:	e8 ff fa ff ff       	call   23b0 <fclose@plt>
    28b1:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    28b8:	48 89 c7             	mov    rdi,rax
    28bb:	e8 70 fa ff ff       	call   2330 <free@plt>
    28c0:	0f b6 05 c9 e7 00 00 	movzx  eax,BYTE PTR [rip+0xe7c9]        # 11090 <is_parallel_nb@@Base>
    28c7:	83 f0 01             	xor    eax,0x1
    28ca:	84 c0                	test   al,al
    28cc:	0f 84 26 07 00 00    	je     2ff8 <TEST_size_permutation____0+0x99c>
    28d2:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    28d9:	48 8b 00             	mov    rax,QWORD PTR [rax]
    28dc:	be 03 00 00 00       	mov    esi,0x3
    28e1:	48 89 c7             	mov    rdi,rax
    28e4:	e8 17 fb ff ff       	call   2400 <expected_EQ_TYPE_L_INT@plt>
    28e9:	84 c0                	test   al,al
    28eb:	0f 84 57 02 00 00    	je     2b48 <TEST_size_permutation____0+0x4ec>
    28f1:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    28f8:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    28ff:	48 89 d6             	mov    rsi,rdx
    2902:	48 89 c7             	mov    rdi,rax
    2905:	e8 46 fa ff ff       	call   2350 <open_memstream@plt>
    290a:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
    290e:	48 83 7d d0 00       	cmp    QWORD PTR [rbp-0x30],0x0
    2913:	75 38                	jne    294d <TEST_size_permutation____0+0x2f1>
    2915:	48 8b 05 e4 e7 00 00 	mov    rax,QWORD PTR [rip+0xe7e4]        # 11100 <stderr@GLIBC_2.2.5>
    291c:	4c 8d 05 dd b9 00 00 	lea    r8,[rip+0xb9dd]        # e300 <__func__.4>
    2923:	b9 1a 00 00 00       	mov    ecx,0x1a
    2928:	48 8d 15 15 b7 00 00 	lea    rdx,[rip+0xb715]        # e044 <_IO_stdin_used+0x44>
    292f:	48 8d 35 1a b7 00 00 	lea    rsi,[rip+0xb71a]        # e050 <_IO_stdin_used+0x50>
    2936:	48 89 c7             	mov    rdi,rax
    2939:	b8 00 00 00 00       	mov    eax,0x0
    293e:	e8 1d fb ff ff       	call   2460 <fprintf@plt>
    2943:	bf 00 00 00 00       	mov    edi,0x0
    2948:	e8 d3 fb ff ff       	call   2520 <exit@plt>
    294d:	8b 05 4d e7 00 00    	mov    eax,DWORD PTR [rip+0xe74d]        # 110a0 <k_DEFAULT@@Base>
    2953:	48 98                	cdqe   
    2955:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    295c:	00 
    295d:	48 8d 05 5c e7 00 00 	lea    rax,[rip+0xe75c]        # 110c0 <colors_f@@Base>
    2964:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    2968:	8b 05 12 e7 00 00    	mov    eax,DWORD PTR [rip+0xe712]        # 11080 <hk_TR@@Base>
    296e:	48 98                	cdqe   
    2970:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    2977:	00 
    2978:	48 8d 05 c1 e6 00 00 	lea    rax,[rip+0xe6c1]        # 11040 <tab_hk_f@@Base>
    297f:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    2983:	8b 05 67 e7 00 00    	mov    eax,DWORD PTR [rip+0xe767]        # 110f0 <k_GREEN@@Base>
    2989:	48 98                	cdqe   
    298b:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    2992:	00 
    2993:	48 8d 05 26 e7 00 00 	lea    rax,[rip+0xe726]        # 110c0 <colors_f@@Base>
    299a:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    299e:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    29a2:	4c 8d 0d 57 b9 00 00 	lea    r9,[rip+0xb957]        # e300 <__func__.4>
    29a9:	49 89 f0             	mov    r8,rsi
    29ac:	48 8d 35 d5 b6 00 00 	lea    rsi,[rip+0xb6d5]        # e088 <_IO_stdin_used+0x88>
    29b3:	48 89 c7             	mov    rdi,rax
    29b6:	b8 00 00 00 00       	mov    eax,0x0
    29bb:	e8 a0 fa ff ff       	call   2460 <fprintf@plt>
    29c0:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    29c4:	48 89 c7             	mov    rdi,rax
    29c7:	e8 c4 fa ff ff       	call   2490 <fflush@plt>
    29cc:	0f b6 05 bd e6 00 00 	movzx  eax,BYTE PTR [rip+0xe6bd]        # 11090 <is_parallel_nb@@Base>
    29d3:	84 c0                	test   al,al
    29d5:	0f 84 e9 00 00 00    	je     2ac4 <TEST_size_permutation____0+0x468>
    29db:	e8 70 fa ff ff       	call   2450 <id_of_thread_executed@plt>
    29e0:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    29e4:	0f b6 05 35 e6 00 00 	movzx  eax,BYTE PTR [rip+0xe635]        # 11020 <log_parallel@@Base>
    29eb:	84 c0                	test   al,al
    29ed:	74 6d                	je     2a5c <TEST_size_permutation____0+0x400>
    29ef:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    29f6:	48 8b 15 2b e6 00 00 	mov    rdx,QWORD PTR [rip+0xe62b]        # 11028 <stdout@GLIBC_2.2.5>
    29fd:	48 89 d6             	mov    rsi,rdx
    2a00:	48 89 c7             	mov    rdi,rax
    2a03:	e8 d8 f9 ff ff       	call   23e0 <fputs@plt>
    2a08:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    2a0d:	0f 88 15 01 00 00    	js     2b28 <TEST_size_permutation____0+0x4cc>
    2a13:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2a1a:	48 8b 0d 0f e6 00 00 	mov    rcx,QWORD PTR [rip+0xe60f]        # 11030 <f_ou_th@@Base>
    2a21:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    2a25:	48 c1 e2 03          	shl    rdx,0x3
    2a29:	48 01 ca             	add    rdx,rcx
    2a2c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2a2f:	48 89 d6             	mov    rsi,rdx
    2a32:	48 89 c7             	mov    rdi,rax
    2a35:	e8 a6 f9 ff ff       	call   23e0 <fputs@plt>
    2a3a:	48 8b 15 ef e5 00 00 	mov    rdx,QWORD PTR [rip+0xe5ef]        # 11030 <f_ou_th@@Base>
    2a41:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    2a45:	48 c1 e0 03          	shl    rax,0x3
    2a49:	48 01 d0             	add    rax,rdx
    2a4c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2a4f:	48 89 c7             	mov    rdi,rax
    2a52:	e8 39 fa ff ff       	call   2490 <fflush@plt>
    2a57:	e9 cc 00 00 00       	jmp    2b28 <TEST_size_permutation____0+0x4cc>
    2a5c:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    2a61:	78 46                	js     2aa9 <TEST_size_permutation____0+0x44d>
    2a63:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2a6a:	48 8b 0d bf e5 00 00 	mov    rcx,QWORD PTR [rip+0xe5bf]        # 11030 <f_ou_th@@Base>
    2a71:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    2a75:	48 c1 e2 03          	shl    rdx,0x3
    2a79:	48 01 ca             	add    rdx,rcx
    2a7c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2a7f:	48 89 d6             	mov    rsi,rdx
    2a82:	48 89 c7             	mov    rdi,rax
    2a85:	e8 56 f9 ff ff       	call   23e0 <fputs@plt>
    2a8a:	48 8b 15 9f e5 00 00 	mov    rdx,QWORD PTR [rip+0xe59f]        # 11030 <f_ou_th@@Base>
    2a91:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    2a95:	48 c1 e0 03          	shl    rax,0x3
    2a99:	48 01 d0             	add    rax,rdx
    2a9c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2a9f:	48 89 c7             	mov    rdi,rax
    2aa2:	e8 e9 f9 ff ff       	call   2490 <fflush@plt>
    2aa7:	eb 7f                	jmp    2b28 <TEST_size_permutation____0+0x4cc>
    2aa9:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2ab0:	48 8b 15 71 e5 00 00 	mov    rdx,QWORD PTR [rip+0xe571]        # 11028 <stdout@GLIBC_2.2.5>
    2ab7:	48 89 d6             	mov    rsi,rdx
    2aba:	48 89 c7             	mov    rdi,rax
    2abd:	e8 1e f9 ff ff       	call   23e0 <fputs@plt>
    2ac2:	eb 64                	jmp    2b28 <TEST_size_permutation____0+0x4cc>
    2ac4:	48 8b 05 6d e5 00 00 	mov    rax,QWORD PTR [rip+0xe56d]        # 11038 <savelog@@Base>
    2acb:	48 85 c0             	test   rax,rax
    2ace:	74 3f                	je     2b0f <TEST_size_permutation____0+0x4b3>
    2ad0:	48 8b 05 61 e5 00 00 	mov    rax,QWORD PTR [rip+0xe561]        # 11038 <savelog@@Base>
    2ad7:	48 8d 15 a1 b5 00 00 	lea    rdx,[rip+0xb5a1]        # e07f <_IO_stdin_used+0x7f>
    2ade:	48 89 d6             	mov    rsi,rdx
    2ae1:	48 89 c7             	mov    rdi,rax
    2ae4:	e8 17 fa ff ff       	call   2500 <fopen@plt>
    2ae9:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    2aed:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2af4:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    2af8:	48 89 d6             	mov    rsi,rdx
    2afb:	48 89 c7             	mov    rdi,rax
    2afe:	e8 dd f8 ff ff       	call   23e0 <fputs@plt>
    2b03:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    2b07:	48 89 c7             	mov    rdi,rax
    2b0a:	e8 a1 f8 ff ff       	call   23b0 <fclose@plt>
    2b0f:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2b16:	48 8b 15 0b e5 00 00 	mov    rdx,QWORD PTR [rip+0xe50b]        # 11028 <stdout@GLIBC_2.2.5>
    2b1d:	48 89 d6             	mov    rsi,rdx
    2b20:	48 89 c7             	mov    rdi,rax
    2b23:	e8 b8 f8 ff ff       	call   23e0 <fputs@plt>
    2b28:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    2b2c:	48 89 c7             	mov    rdi,rax
    2b2f:	e8 7c f8 ff ff       	call   23b0 <fclose@plt>
    2b34:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2b3b:	48 89 c7             	mov    rdi,rax
    2b3e:	e8 ed f7 ff ff       	call   2330 <free@plt>
    2b43:	e9 29 0c 00 00       	jmp    3771 <TEST_size_permutation____0+0x1115>
    2b48:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    2b4f:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    2b56:	48 89 d6             	mov    rsi,rdx
    2b59:	48 89 c7             	mov    rdi,rax
    2b5c:	e8 ef f7 ff ff       	call   2350 <open_memstream@plt>
    2b61:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
    2b65:	48 83 7d a0 00       	cmp    QWORD PTR [rbp-0x60],0x0
    2b6a:	75 38                	jne    2ba4 <TEST_size_permutation____0+0x548>
    2b6c:	48 8b 05 8d e5 00 00 	mov    rax,QWORD PTR [rip+0xe58d]        # 11100 <stderr@GLIBC_2.2.5>
    2b73:	4c 8d 05 86 b7 00 00 	lea    r8,[rip+0xb786]        # e300 <__func__.4>
    2b7a:	b9 1a 00 00 00       	mov    ecx,0x1a
    2b7f:	48 8d 15 be b4 00 00 	lea    rdx,[rip+0xb4be]        # e044 <_IO_stdin_used+0x44>
    2b86:	48 8d 35 c3 b4 00 00 	lea    rsi,[rip+0xb4c3]        # e050 <_IO_stdin_used+0x50>
    2b8d:	48 89 c7             	mov    rdi,rax
    2b90:	b8 00 00 00 00       	mov    eax,0x0
    2b95:	e8 c6 f8 ff ff       	call   2460 <fprintf@plt>
    2b9a:	bf 00 00 00 00       	mov    edi,0x0
    2b9f:	e8 7c f9 ff ff       	call   2520 <exit@plt>
    2ba4:	bf 03 00 00 00       	mov    edi,0x3
    2ba9:	e8 82 f9 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    2bae:	48 89 c3             	mov    rbx,rax
    2bb1:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    2bb8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2bbb:	48 89 c7             	mov    rdi,rax
    2bbe:	e8 6d f9 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    2bc3:	48 89 c2             	mov    rdx,rax
    2bc6:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    2bca:	53                   	push   rbx
    2bcb:	48 8d 0d 30 b5 00 00 	lea    rcx,[rip+0xb530]        # e102 <_IO_stdin_used+0x102>
    2bd2:	51                   	push   rcx
    2bd3:	52                   	push   rdx
    2bd4:	48 8d 15 cd b4 00 00 	lea    rdx,[rip+0xb4cd]        # e0a8 <_IO_stdin_used+0xa8>
    2bdb:	52                   	push   rdx
    2bdc:	48 8d 15 1f b5 00 00 	lea    rdx,[rip+0xb51f]        # e102 <_IO_stdin_used+0x102>
    2be3:	52                   	push   rdx
    2be4:	48 8d 15 19 b5 00 00 	lea    rdx,[rip+0xb519]        # e104 <_IO_stdin_used+0x104>
    2beb:	52                   	push   rdx
    2bec:	4c 8d 0d b5 b4 00 00 	lea    r9,[rip+0xb4b5]        # e0a8 <_IO_stdin_used+0xa8>
    2bf3:	4c 8d 05 06 b7 00 00 	lea    r8,[rip+0xb706]        # e300 <__func__.4>
    2bfa:	b9 1a 00 00 00       	mov    ecx,0x1a
    2bff:	48 8d 15 3e b4 00 00 	lea    rdx,[rip+0xb43e]        # e044 <_IO_stdin_used+0x44>
    2c06:	48 8d 35 a3 b4 00 00 	lea    rsi,[rip+0xb4a3]        # e0b0 <_IO_stdin_used+0xb0>
    2c0d:	48 89 c7             	mov    rdi,rax
    2c10:	b8 00 00 00 00       	mov    eax,0x0
    2c15:	e8 46 f8 ff ff       	call   2460 <fprintf@plt>
    2c1a:	48 83 c4 30          	add    rsp,0x30
    2c1e:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    2c22:	48 89 c7             	mov    rdi,rax
    2c25:	e8 66 f8 ff ff       	call   2490 <fflush@plt>
    2c2a:	0f b6 05 5f e4 00 00 	movzx  eax,BYTE PTR [rip+0xe45f]        # 11090 <is_parallel_nb@@Base>
    2c31:	84 c0                	test   al,al
    2c33:	0f 84 e9 00 00 00    	je     2d22 <TEST_size_permutation____0+0x6c6>
    2c39:	e8 12 f8 ff ff       	call   2450 <id_of_thread_executed@plt>
    2c3e:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
    2c42:	0f b6 05 d7 e3 00 00 	movzx  eax,BYTE PTR [rip+0xe3d7]        # 11020 <log_parallel@@Base>
    2c49:	84 c0                	test   al,al
    2c4b:	74 6d                	je     2cba <TEST_size_permutation____0+0x65e>
    2c4d:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2c54:	48 8b 15 cd e3 00 00 	mov    rdx,QWORD PTR [rip+0xe3cd]        # 11028 <stdout@GLIBC_2.2.5>
    2c5b:	48 89 d6             	mov    rsi,rdx
    2c5e:	48 89 c7             	mov    rdi,rax
    2c61:	e8 7a f7 ff ff       	call   23e0 <fputs@plt>
    2c66:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    2c6b:	0f 88 15 01 00 00    	js     2d86 <TEST_size_permutation____0+0x72a>
    2c71:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2c78:	48 8b 0d b1 e3 00 00 	mov    rcx,QWORD PTR [rip+0xe3b1]        # 11030 <f_ou_th@@Base>
    2c7f:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    2c83:	48 c1 e2 03          	shl    rdx,0x3
    2c87:	48 01 ca             	add    rdx,rcx
    2c8a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2c8d:	48 89 d6             	mov    rsi,rdx
    2c90:	48 89 c7             	mov    rdi,rax
    2c93:	e8 48 f7 ff ff       	call   23e0 <fputs@plt>
    2c98:	48 8b 15 91 e3 00 00 	mov    rdx,QWORD PTR [rip+0xe391]        # 11030 <f_ou_th@@Base>
    2c9f:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    2ca3:	48 c1 e0 03          	shl    rax,0x3
    2ca7:	48 01 d0             	add    rax,rdx
    2caa:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2cad:	48 89 c7             	mov    rdi,rax
    2cb0:	e8 db f7 ff ff       	call   2490 <fflush@plt>
    2cb5:	e9 cc 00 00 00       	jmp    2d86 <TEST_size_permutation____0+0x72a>
    2cba:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    2cbf:	78 46                	js     2d07 <TEST_size_permutation____0+0x6ab>
    2cc1:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2cc8:	48 8b 0d 61 e3 00 00 	mov    rcx,QWORD PTR [rip+0xe361]        # 11030 <f_ou_th@@Base>
    2ccf:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    2cd3:	48 c1 e2 03          	shl    rdx,0x3
    2cd7:	48 01 ca             	add    rdx,rcx
    2cda:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2cdd:	48 89 d6             	mov    rsi,rdx
    2ce0:	48 89 c7             	mov    rdi,rax
    2ce3:	e8 f8 f6 ff ff       	call   23e0 <fputs@plt>
    2ce8:	48 8b 15 41 e3 00 00 	mov    rdx,QWORD PTR [rip+0xe341]        # 11030 <f_ou_th@@Base>
    2cef:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    2cf3:	48 c1 e0 03          	shl    rax,0x3
    2cf7:	48 01 d0             	add    rax,rdx
    2cfa:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2cfd:	48 89 c7             	mov    rdi,rax
    2d00:	e8 8b f7 ff ff       	call   2490 <fflush@plt>
    2d05:	eb 7f                	jmp    2d86 <TEST_size_permutation____0+0x72a>
    2d07:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2d0e:	48 8b 15 13 e3 00 00 	mov    rdx,QWORD PTR [rip+0xe313]        # 11028 <stdout@GLIBC_2.2.5>
    2d15:	48 89 d6             	mov    rsi,rdx
    2d18:	48 89 c7             	mov    rdi,rax
    2d1b:	e8 c0 f6 ff ff       	call   23e0 <fputs@plt>
    2d20:	eb 64                	jmp    2d86 <TEST_size_permutation____0+0x72a>
    2d22:	48 8b 05 0f e3 00 00 	mov    rax,QWORD PTR [rip+0xe30f]        # 11038 <savelog@@Base>
    2d29:	48 85 c0             	test   rax,rax
    2d2c:	74 3f                	je     2d6d <TEST_size_permutation____0+0x711>
    2d2e:	48 8b 05 03 e3 00 00 	mov    rax,QWORD PTR [rip+0xe303]        # 11038 <savelog@@Base>
    2d35:	48 8d 15 43 b3 00 00 	lea    rdx,[rip+0xb343]        # e07f <_IO_stdin_used+0x7f>
    2d3c:	48 89 d6             	mov    rsi,rdx
    2d3f:	48 89 c7             	mov    rdi,rax
    2d42:	e8 b9 f7 ff ff       	call   2500 <fopen@plt>
    2d47:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    2d4b:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2d52:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
    2d56:	48 89 d6             	mov    rsi,rdx
    2d59:	48 89 c7             	mov    rdi,rax
    2d5c:	e8 7f f6 ff ff       	call   23e0 <fputs@plt>
    2d61:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    2d65:	48 89 c7             	mov    rdi,rax
    2d68:	e8 43 f6 ff ff       	call   23b0 <fclose@plt>
    2d6d:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2d74:	48 8b 15 ad e2 00 00 	mov    rdx,QWORD PTR [rip+0xe2ad]        # 11028 <stdout@GLIBC_2.2.5>
    2d7b:	48 89 d6             	mov    rsi,rdx
    2d7e:	48 89 c7             	mov    rdi,rax
    2d81:	e8 5a f6 ff ff       	call   23e0 <fputs@plt>
    2d86:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    2d8a:	48 89 c7             	mov    rdi,rax
    2d8d:	e8 1e f6 ff ff       	call   23b0 <fclose@plt>
    2d92:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2d99:	48 89 c7             	mov    rdi,rax
    2d9c:	e8 8f f5 ff ff       	call   2330 <free@plt>
    2da1:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    2da8:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    2daf:	48 89 d6             	mov    rsi,rdx
    2db2:	48 89 c7             	mov    rdi,rax
    2db5:	e8 96 f5 ff ff       	call   2350 <open_memstream@plt>
    2dba:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
    2dbe:	48 83 7d b8 00       	cmp    QWORD PTR [rbp-0x48],0x0
    2dc3:	75 38                	jne    2dfd <TEST_size_permutation____0+0x7a1>
    2dc5:	48 8b 05 34 e3 00 00 	mov    rax,QWORD PTR [rip+0xe334]        # 11100 <stderr@GLIBC_2.2.5>
    2dcc:	4c 8d 05 2d b5 00 00 	lea    r8,[rip+0xb52d]        # e300 <__func__.4>
    2dd3:	b9 1a 00 00 00       	mov    ecx,0x1a
    2dd8:	48 8d 15 65 b2 00 00 	lea    rdx,[rip+0xb265]        # e044 <_IO_stdin_used+0x44>
    2ddf:	48 8d 35 6a b2 00 00 	lea    rsi,[rip+0xb26a]        # e050 <_IO_stdin_used+0x50>
    2de6:	48 89 c7             	mov    rdi,rax
    2de9:	b8 00 00 00 00       	mov    eax,0x0
    2dee:	e8 6d f6 ff ff       	call   2460 <fprintf@plt>
    2df3:	bf 00 00 00 00       	mov    edi,0x0
    2df8:	e8 23 f7 ff ff       	call   2520 <exit@plt>
    2dfd:	8b 05 9d e2 00 00    	mov    eax,DWORD PTR [rip+0xe29d]        # 110a0 <k_DEFAULT@@Base>
    2e03:	48 98                	cdqe   
    2e05:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    2e0c:	00 
    2e0d:	48 8d 05 ac e2 00 00 	lea    rax,[rip+0xe2ac]        # 110c0 <colors_f@@Base>
    2e14:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    2e18:	8b 05 62 e2 00 00    	mov    eax,DWORD PTR [rip+0xe262]        # 11080 <hk_TR@@Base>
    2e1e:	48 98                	cdqe   
    2e20:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    2e27:	00 
    2e28:	48 8d 05 11 e2 00 00 	lea    rax,[rip+0xe211]        # 11040 <tab_hk_f@@Base>
    2e2f:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    2e33:	8b 05 4b e2 00 00    	mov    eax,DWORD PTR [rip+0xe24b]        # 11084 <k_RED@@Base>
    2e39:	48 98                	cdqe   
    2e3b:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    2e42:	00 
    2e43:	48 8d 05 76 e2 00 00 	lea    rax,[rip+0xe276]        # 110c0 <colors_f@@Base>
    2e4a:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    2e4e:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    2e52:	4c 8d 0d a7 b4 00 00 	lea    r9,[rip+0xb4a7]        # e300 <__func__.4>
    2e59:	49 89 f0             	mov    r8,rsi
    2e5c:	48 8d 35 a5 b2 00 00 	lea    rsi,[rip+0xb2a5]        # e108 <_IO_stdin_used+0x108>
    2e63:	48 89 c7             	mov    rdi,rax
    2e66:	b8 00 00 00 00       	mov    eax,0x0
    2e6b:	e8 f0 f5 ff ff       	call   2460 <fprintf@plt>
    2e70:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    2e74:	48 89 c7             	mov    rdi,rax
    2e77:	e8 14 f6 ff ff       	call   2490 <fflush@plt>
    2e7c:	0f b6 05 0d e2 00 00 	movzx  eax,BYTE PTR [rip+0xe20d]        # 11090 <is_parallel_nb@@Base>
    2e83:	84 c0                	test   al,al
    2e85:	0f 84 e9 00 00 00    	je     2f74 <TEST_size_permutation____0+0x918>
    2e8b:	e8 c0 f5 ff ff       	call   2450 <id_of_thread_executed@plt>
    2e90:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
    2e94:	0f b6 05 85 e1 00 00 	movzx  eax,BYTE PTR [rip+0xe185]        # 11020 <log_parallel@@Base>
    2e9b:	84 c0                	test   al,al
    2e9d:	74 6d                	je     2f0c <TEST_size_permutation____0+0x8b0>
    2e9f:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2ea6:	48 8b 15 7b e1 00 00 	mov    rdx,QWORD PTR [rip+0xe17b]        # 11028 <stdout@GLIBC_2.2.5>
    2ead:	48 89 d6             	mov    rsi,rdx
    2eb0:	48 89 c7             	mov    rdi,rax
    2eb3:	e8 28 f5 ff ff       	call   23e0 <fputs@plt>
    2eb8:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    2ebd:	0f 88 15 01 00 00    	js     2fd8 <TEST_size_permutation____0+0x97c>
    2ec3:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2eca:	48 8b 0d 5f e1 00 00 	mov    rcx,QWORD PTR [rip+0xe15f]        # 11030 <f_ou_th@@Base>
    2ed1:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    2ed5:	48 c1 e2 03          	shl    rdx,0x3
    2ed9:	48 01 ca             	add    rdx,rcx
    2edc:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2edf:	48 89 d6             	mov    rsi,rdx
    2ee2:	48 89 c7             	mov    rdi,rax
    2ee5:	e8 f6 f4 ff ff       	call   23e0 <fputs@plt>
    2eea:	48 8b 15 3f e1 00 00 	mov    rdx,QWORD PTR [rip+0xe13f]        # 11030 <f_ou_th@@Base>
    2ef1:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    2ef5:	48 c1 e0 03          	shl    rax,0x3
    2ef9:	48 01 d0             	add    rax,rdx
    2efc:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2eff:	48 89 c7             	mov    rdi,rax
    2f02:	e8 89 f5 ff ff       	call   2490 <fflush@plt>
    2f07:	e9 cc 00 00 00       	jmp    2fd8 <TEST_size_permutation____0+0x97c>
    2f0c:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    2f11:	78 46                	js     2f59 <TEST_size_permutation____0+0x8fd>
    2f13:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2f1a:	48 8b 0d 0f e1 00 00 	mov    rcx,QWORD PTR [rip+0xe10f]        # 11030 <f_ou_th@@Base>
    2f21:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    2f25:	48 c1 e2 03          	shl    rdx,0x3
    2f29:	48 01 ca             	add    rdx,rcx
    2f2c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    2f2f:	48 89 d6             	mov    rsi,rdx
    2f32:	48 89 c7             	mov    rdi,rax
    2f35:	e8 a6 f4 ff ff       	call   23e0 <fputs@plt>
    2f3a:	48 8b 15 ef e0 00 00 	mov    rdx,QWORD PTR [rip+0xe0ef]        # 11030 <f_ou_th@@Base>
    2f41:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    2f45:	48 c1 e0 03          	shl    rax,0x3
    2f49:	48 01 d0             	add    rax,rdx
    2f4c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    2f4f:	48 89 c7             	mov    rdi,rax
    2f52:	e8 39 f5 ff ff       	call   2490 <fflush@plt>
    2f57:	eb 7f                	jmp    2fd8 <TEST_size_permutation____0+0x97c>
    2f59:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2f60:	48 8b 15 c1 e0 00 00 	mov    rdx,QWORD PTR [rip+0xe0c1]        # 11028 <stdout@GLIBC_2.2.5>
    2f67:	48 89 d6             	mov    rsi,rdx
    2f6a:	48 89 c7             	mov    rdi,rax
    2f6d:	e8 6e f4 ff ff       	call   23e0 <fputs@plt>
    2f72:	eb 64                	jmp    2fd8 <TEST_size_permutation____0+0x97c>
    2f74:	48 8b 05 bd e0 00 00 	mov    rax,QWORD PTR [rip+0xe0bd]        # 11038 <savelog@@Base>
    2f7b:	48 85 c0             	test   rax,rax
    2f7e:	74 3f                	je     2fbf <TEST_size_permutation____0+0x963>
    2f80:	48 8b 05 b1 e0 00 00 	mov    rax,QWORD PTR [rip+0xe0b1]        # 11038 <savelog@@Base>
    2f87:	48 8d 15 f1 b0 00 00 	lea    rdx,[rip+0xb0f1]        # e07f <_IO_stdin_used+0x7f>
    2f8e:	48 89 d6             	mov    rsi,rdx
    2f91:	48 89 c7             	mov    rdi,rax
    2f94:	e8 67 f5 ff ff       	call   2500 <fopen@plt>
    2f99:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
    2f9d:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2fa4:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
    2fa8:	48 89 d6             	mov    rsi,rdx
    2fab:	48 89 c7             	mov    rdi,rax
    2fae:	e8 2d f4 ff ff       	call   23e0 <fputs@plt>
    2fb3:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
    2fb7:	48 89 c7             	mov    rdi,rax
    2fba:	e8 f1 f3 ff ff       	call   23b0 <fclose@plt>
    2fbf:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2fc6:	48 8b 15 5b e0 00 00 	mov    rdx,QWORD PTR [rip+0xe05b]        # 11028 <stdout@GLIBC_2.2.5>
    2fcd:	48 89 d6             	mov    rsi,rdx
    2fd0:	48 89 c7             	mov    rdi,rax
    2fd3:	e8 08 f4 ff ff       	call   23e0 <fputs@plt>
    2fd8:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    2fdc:	48 89 c7             	mov    rdi,rax
    2fdf:	e8 cc f3 ff ff       	call   23b0 <fclose@plt>
    2fe4:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    2feb:	48 89 c7             	mov    rdi,rax
    2fee:	e8 3d f3 ff ff       	call   2330 <free@plt>
    2ff3:	e9 79 07 00 00       	jmp    3771 <TEST_size_permutation____0+0x1115>
    2ff8:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    2fff:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3002:	48 89 c1             	mov    rcx,rax
    3005:	48 8d 05 f4 b2 00 00 	lea    rax,[rip+0xb2f4]        # e300 <__func__.4>
    300c:	48 89 c2             	mov    rdx,rax
    300f:	be 03 00 00 00       	mov    esi,0x3
    3014:	48 89 cf             	mov    rdi,rcx
    3017:	e8 64 f3 ff ff       	call   2380 <expected_EQ_name_TYPE_L_INT@plt>
    301c:	84 c0                	test   al,al
    301e:	0f 84 57 02 00 00    	je     327b <TEST_size_permutation____0+0xc1f>
    3024:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    302b:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    3032:	48 89 d6             	mov    rsi,rdx
    3035:	48 89 c7             	mov    rdi,rax
    3038:	e8 13 f3 ff ff       	call   2350 <open_memstream@plt>
    303d:	48 89 45 88          	mov    QWORD PTR [rbp-0x78],rax
    3041:	48 83 7d 88 00       	cmp    QWORD PTR [rbp-0x78],0x0
    3046:	75 38                	jne    3080 <TEST_size_permutation____0+0xa24>
    3048:	48 8b 05 b1 e0 00 00 	mov    rax,QWORD PTR [rip+0xe0b1]        # 11100 <stderr@GLIBC_2.2.5>
    304f:	4c 8d 05 aa b2 00 00 	lea    r8,[rip+0xb2aa]        # e300 <__func__.4>
    3056:	b9 1a 00 00 00       	mov    ecx,0x1a
    305b:	48 8d 15 e2 af 00 00 	lea    rdx,[rip+0xafe2]        # e044 <_IO_stdin_used+0x44>
    3062:	48 8d 35 e7 af 00 00 	lea    rsi,[rip+0xafe7]        # e050 <_IO_stdin_used+0x50>
    3069:	48 89 c7             	mov    rdi,rax
    306c:	b8 00 00 00 00       	mov    eax,0x0
    3071:	e8 ea f3 ff ff       	call   2460 <fprintf@plt>
    3076:	bf 00 00 00 00       	mov    edi,0x0
    307b:	e8 a0 f4 ff ff       	call   2520 <exit@plt>
    3080:	8b 05 1a e0 00 00    	mov    eax,DWORD PTR [rip+0xe01a]        # 110a0 <k_DEFAULT@@Base>
    3086:	48 98                	cdqe   
    3088:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    308f:	00 
    3090:	48 8d 05 29 e0 00 00 	lea    rax,[rip+0xe029]        # 110c0 <colors_f@@Base>
    3097:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    309b:	8b 05 df df 00 00    	mov    eax,DWORD PTR [rip+0xdfdf]        # 11080 <hk_TR@@Base>
    30a1:	48 98                	cdqe   
    30a3:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    30aa:	00 
    30ab:	48 8d 05 8e df 00 00 	lea    rax,[rip+0xdf8e]        # 11040 <tab_hk_f@@Base>
    30b2:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    30b6:	8b 05 34 e0 00 00    	mov    eax,DWORD PTR [rip+0xe034]        # 110f0 <k_GREEN@@Base>
    30bc:	48 98                	cdqe   
    30be:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    30c5:	00 
    30c6:	48 8d 05 f3 df 00 00 	lea    rax,[rip+0xdff3]        # 110c0 <colors_f@@Base>
    30cd:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    30d1:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    30d5:	4c 8d 0d 24 b2 00 00 	lea    r9,[rip+0xb224]        # e300 <__func__.4>
    30dc:	49 89 f0             	mov    r8,rsi
    30df:	48 8d 35 a2 af 00 00 	lea    rsi,[rip+0xafa2]        # e088 <_IO_stdin_used+0x88>
    30e6:	48 89 c7             	mov    rdi,rax
    30e9:	b8 00 00 00 00       	mov    eax,0x0
    30ee:	e8 6d f3 ff ff       	call   2460 <fprintf@plt>
    30f3:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    30f7:	48 89 c7             	mov    rdi,rax
    30fa:	e8 91 f3 ff ff       	call   2490 <fflush@plt>
    30ff:	0f b6 05 8a df 00 00 	movzx  eax,BYTE PTR [rip+0xdf8a]        # 11090 <is_parallel_nb@@Base>
    3106:	84 c0                	test   al,al
    3108:	0f 84 e9 00 00 00    	je     31f7 <TEST_size_permutation____0+0xb9b>
    310e:	e8 3d f3 ff ff       	call   2450 <id_of_thread_executed@plt>
    3113:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
    3117:	0f b6 05 02 df 00 00 	movzx  eax,BYTE PTR [rip+0xdf02]        # 11020 <log_parallel@@Base>
    311e:	84 c0                	test   al,al
    3120:	74 6d                	je     318f <TEST_size_permutation____0+0xb33>
    3122:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3129:	48 8b 15 f8 de 00 00 	mov    rdx,QWORD PTR [rip+0xdef8]        # 11028 <stdout@GLIBC_2.2.5>
    3130:	48 89 d6             	mov    rsi,rdx
    3133:	48 89 c7             	mov    rdi,rax
    3136:	e8 a5 f2 ff ff       	call   23e0 <fputs@plt>
    313b:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    3140:	0f 88 15 01 00 00    	js     325b <TEST_size_permutation____0+0xbff>
    3146:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    314d:	48 8b 0d dc de 00 00 	mov    rcx,QWORD PTR [rip+0xdedc]        # 11030 <f_ou_th@@Base>
    3154:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    3158:	48 c1 e2 03          	shl    rdx,0x3
    315c:	48 01 ca             	add    rdx,rcx
    315f:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3162:	48 89 d6             	mov    rsi,rdx
    3165:	48 89 c7             	mov    rdi,rax
    3168:	e8 73 f2 ff ff       	call   23e0 <fputs@plt>
    316d:	48 8b 15 bc de 00 00 	mov    rdx,QWORD PTR [rip+0xdebc]        # 11030 <f_ou_th@@Base>
    3174:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    3178:	48 c1 e0 03          	shl    rax,0x3
    317c:	48 01 d0             	add    rax,rdx
    317f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3182:	48 89 c7             	mov    rdi,rax
    3185:	e8 06 f3 ff ff       	call   2490 <fflush@plt>
    318a:	e9 cc 00 00 00       	jmp    325b <TEST_size_permutation____0+0xbff>
    318f:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    3194:	78 46                	js     31dc <TEST_size_permutation____0+0xb80>
    3196:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    319d:	48 8b 0d 8c de 00 00 	mov    rcx,QWORD PTR [rip+0xde8c]        # 11030 <f_ou_th@@Base>
    31a4:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    31a8:	48 c1 e2 03          	shl    rdx,0x3
    31ac:	48 01 ca             	add    rdx,rcx
    31af:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    31b2:	48 89 d6             	mov    rsi,rdx
    31b5:	48 89 c7             	mov    rdi,rax
    31b8:	e8 23 f2 ff ff       	call   23e0 <fputs@plt>
    31bd:	48 8b 15 6c de 00 00 	mov    rdx,QWORD PTR [rip+0xde6c]        # 11030 <f_ou_th@@Base>
    31c4:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    31c8:	48 c1 e0 03          	shl    rax,0x3
    31cc:	48 01 d0             	add    rax,rdx
    31cf:	48 8b 00             	mov    rax,QWORD PTR [rax]
    31d2:	48 89 c7             	mov    rdi,rax
    31d5:	e8 b6 f2 ff ff       	call   2490 <fflush@plt>
    31da:	eb 7f                	jmp    325b <TEST_size_permutation____0+0xbff>
    31dc:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    31e3:	48 8b 15 3e de 00 00 	mov    rdx,QWORD PTR [rip+0xde3e]        # 11028 <stdout@GLIBC_2.2.5>
    31ea:	48 89 d6             	mov    rsi,rdx
    31ed:	48 89 c7             	mov    rdi,rax
    31f0:	e8 eb f1 ff ff       	call   23e0 <fputs@plt>
    31f5:	eb 64                	jmp    325b <TEST_size_permutation____0+0xbff>
    31f7:	48 8b 05 3a de 00 00 	mov    rax,QWORD PTR [rip+0xde3a]        # 11038 <savelog@@Base>
    31fe:	48 85 c0             	test   rax,rax
    3201:	74 3f                	je     3242 <TEST_size_permutation____0+0xbe6>
    3203:	48 8b 05 2e de 00 00 	mov    rax,QWORD PTR [rip+0xde2e]        # 11038 <savelog@@Base>
    320a:	48 8d 15 6e ae 00 00 	lea    rdx,[rip+0xae6e]        # e07f <_IO_stdin_used+0x7f>
    3211:	48 89 d6             	mov    rsi,rdx
    3214:	48 89 c7             	mov    rdi,rax
    3217:	e8 e4 f2 ff ff       	call   2500 <fopen@plt>
    321c:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
    3220:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3227:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
    322b:	48 89 d6             	mov    rsi,rdx
    322e:	48 89 c7             	mov    rdi,rax
    3231:	e8 aa f1 ff ff       	call   23e0 <fputs@plt>
    3236:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
    323a:	48 89 c7             	mov    rdi,rax
    323d:	e8 6e f1 ff ff       	call   23b0 <fclose@plt>
    3242:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3249:	48 8b 15 d8 dd 00 00 	mov    rdx,QWORD PTR [rip+0xddd8]        # 11028 <stdout@GLIBC_2.2.5>
    3250:	48 89 d6             	mov    rsi,rdx
    3253:	48 89 c7             	mov    rdi,rax
    3256:	e8 85 f1 ff ff       	call   23e0 <fputs@plt>
    325b:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    325f:	48 89 c7             	mov    rdi,rax
    3262:	e8 49 f1 ff ff       	call   23b0 <fclose@plt>
    3267:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    326e:	48 89 c7             	mov    rdi,rax
    3271:	e8 ba f0 ff ff       	call   2330 <free@plt>
    3276:	e9 f6 04 00 00       	jmp    3771 <TEST_size_permutation____0+0x1115>
    327b:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    3282:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    3289:	48 89 d6             	mov    rsi,rdx
    328c:	48 89 c7             	mov    rdi,rax
    328f:	e8 bc f0 ff ff       	call   2350 <open_memstream@plt>
    3294:	48 89 85 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rax
    329b:	48 83 bd 58 ff ff ff 	cmp    QWORD PTR [rbp-0xa8],0x0
    32a2:	00 
    32a3:	75 38                	jne    32dd <TEST_size_permutation____0+0xc81>
    32a5:	48 8b 05 54 de 00 00 	mov    rax,QWORD PTR [rip+0xde54]        # 11100 <stderr@GLIBC_2.2.5>
    32ac:	4c 8d 05 4d b0 00 00 	lea    r8,[rip+0xb04d]        # e300 <__func__.4>
    32b3:	b9 1a 00 00 00       	mov    ecx,0x1a
    32b8:	48 8d 15 85 ad 00 00 	lea    rdx,[rip+0xad85]        # e044 <_IO_stdin_used+0x44>
    32bf:	48 8d 35 8a ad 00 00 	lea    rsi,[rip+0xad8a]        # e050 <_IO_stdin_used+0x50>
    32c6:	48 89 c7             	mov    rdi,rax
    32c9:	b8 00 00 00 00       	mov    eax,0x0
    32ce:	e8 8d f1 ff ff       	call   2460 <fprintf@plt>
    32d3:	bf 00 00 00 00       	mov    edi,0x0
    32d8:	e8 43 f2 ff ff       	call   2520 <exit@plt>
    32dd:	bf 03 00 00 00       	mov    edi,0x3
    32e2:	e8 49 f2 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    32e7:	48 89 c3             	mov    rbx,rax
    32ea:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    32f1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    32f4:	48 89 c7             	mov    rdi,rax
    32f7:	e8 34 f2 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    32fc:	48 89 c2             	mov    rdx,rax
    32ff:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    3306:	53                   	push   rbx
    3307:	48 8d 0d f4 ad 00 00 	lea    rcx,[rip+0xadf4]        # e102 <_IO_stdin_used+0x102>
    330e:	51                   	push   rcx
    330f:	52                   	push   rdx
    3310:	48 8d 15 91 ad 00 00 	lea    rdx,[rip+0xad91]        # e0a8 <_IO_stdin_used+0xa8>
    3317:	52                   	push   rdx
    3318:	48 8d 15 e3 ad 00 00 	lea    rdx,[rip+0xade3]        # e102 <_IO_stdin_used+0x102>
    331f:	52                   	push   rdx
    3320:	48 8d 15 dd ad 00 00 	lea    rdx,[rip+0xaddd]        # e104 <_IO_stdin_used+0x104>
    3327:	52                   	push   rdx
    3328:	4c 8d 0d 79 ad 00 00 	lea    r9,[rip+0xad79]        # e0a8 <_IO_stdin_used+0xa8>
    332f:	4c 8d 05 ca af 00 00 	lea    r8,[rip+0xafca]        # e300 <__func__.4>
    3336:	b9 1a 00 00 00       	mov    ecx,0x1a
    333b:	48 8d 15 02 ad 00 00 	lea    rdx,[rip+0xad02]        # e044 <_IO_stdin_used+0x44>
    3342:	48 8d 35 67 ad 00 00 	lea    rsi,[rip+0xad67]        # e0b0 <_IO_stdin_used+0xb0>
    3349:	48 89 c7             	mov    rdi,rax
    334c:	b8 00 00 00 00       	mov    eax,0x0
    3351:	e8 0a f1 ff ff       	call   2460 <fprintf@plt>
    3356:	48 83 c4 30          	add    rsp,0x30
    335a:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    3361:	48 89 c7             	mov    rdi,rax
    3364:	e8 27 f1 ff ff       	call   2490 <fflush@plt>
    3369:	0f b6 05 20 dd 00 00 	movzx  eax,BYTE PTR [rip+0xdd20]        # 11090 <is_parallel_nb@@Base>
    3370:	84 c0                	test   al,al
    3372:	0f 84 01 01 00 00    	je     3479 <TEST_size_permutation____0+0xe1d>
    3378:	e8 d3 f0 ff ff       	call   2450 <id_of_thread_executed@plt>
    337d:	48 89 85 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rax
    3384:	0f b6 05 95 dc 00 00 	movzx  eax,BYTE PTR [rip+0xdc95]        # 11020 <log_parallel@@Base>
    338b:	84 c0                	test   al,al
    338d:	74 76                	je     3405 <TEST_size_permutation____0+0xda9>
    338f:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3396:	48 8b 15 8b dc 00 00 	mov    rdx,QWORD PTR [rip+0xdc8b]        # 11028 <stdout@GLIBC_2.2.5>
    339d:	48 89 d6             	mov    rsi,rdx
    33a0:	48 89 c7             	mov    rdi,rax
    33a3:	e8 38 f0 ff ff       	call   23e0 <fputs@plt>
    33a8:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    33af:	00 
    33b0:	0f 88 30 01 00 00    	js     34e6 <TEST_size_permutation____0+0xe8a>
    33b6:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    33bd:	48 8b 0d 6c dc 00 00 	mov    rcx,QWORD PTR [rip+0xdc6c]        # 11030 <f_ou_th@@Base>
    33c4:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    33cb:	48 c1 e2 03          	shl    rdx,0x3
    33cf:	48 01 ca             	add    rdx,rcx
    33d2:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    33d5:	48 89 d6             	mov    rsi,rdx
    33d8:	48 89 c7             	mov    rdi,rax
    33db:	e8 00 f0 ff ff       	call   23e0 <fputs@plt>
    33e0:	48 8b 15 49 dc 00 00 	mov    rdx,QWORD PTR [rip+0xdc49]        # 11030 <f_ou_th@@Base>
    33e7:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    33ee:	48 c1 e0 03          	shl    rax,0x3
    33f2:	48 01 d0             	add    rax,rdx
    33f5:	48 8b 00             	mov    rax,QWORD PTR [rax]
    33f8:	48 89 c7             	mov    rdi,rax
    33fb:	e8 90 f0 ff ff       	call   2490 <fflush@plt>
    3400:	e9 e1 00 00 00       	jmp    34e6 <TEST_size_permutation____0+0xe8a>
    3405:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    340c:	00 
    340d:	78 4f                	js     345e <TEST_size_permutation____0+0xe02>
    340f:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3416:	48 8b 0d 13 dc 00 00 	mov    rcx,QWORD PTR [rip+0xdc13]        # 11030 <f_ou_th@@Base>
    341d:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    3424:	48 c1 e2 03          	shl    rdx,0x3
    3428:	48 01 ca             	add    rdx,rcx
    342b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    342e:	48 89 d6             	mov    rsi,rdx
    3431:	48 89 c7             	mov    rdi,rax
    3434:	e8 a7 ef ff ff       	call   23e0 <fputs@plt>
    3439:	48 8b 15 f0 db 00 00 	mov    rdx,QWORD PTR [rip+0xdbf0]        # 11030 <f_ou_th@@Base>
    3440:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    3447:	48 c1 e0 03          	shl    rax,0x3
    344b:	48 01 d0             	add    rax,rdx
    344e:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3451:	48 89 c7             	mov    rdi,rax
    3454:	e8 37 f0 ff ff       	call   2490 <fflush@plt>
    3459:	e9 88 00 00 00       	jmp    34e6 <TEST_size_permutation____0+0xe8a>
    345e:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3465:	48 8b 15 bc db 00 00 	mov    rdx,QWORD PTR [rip+0xdbbc]        # 11028 <stdout@GLIBC_2.2.5>
    346c:	48 89 d6             	mov    rsi,rdx
    346f:	48 89 c7             	mov    rdi,rax
    3472:	e8 69 ef ff ff       	call   23e0 <fputs@plt>
    3477:	eb 6d                	jmp    34e6 <TEST_size_permutation____0+0xe8a>
    3479:	48 8b 05 b8 db 00 00 	mov    rax,QWORD PTR [rip+0xdbb8]        # 11038 <savelog@@Base>
    3480:	48 85 c0             	test   rax,rax
    3483:	74 48                	je     34cd <TEST_size_permutation____0+0xe71>
    3485:	48 8b 05 ac db 00 00 	mov    rax,QWORD PTR [rip+0xdbac]        # 11038 <savelog@@Base>
    348c:	48 8d 15 ec ab 00 00 	lea    rdx,[rip+0xabec]        # e07f <_IO_stdin_used+0x7f>
    3493:	48 89 d6             	mov    rsi,rdx
    3496:	48 89 c7             	mov    rdi,rax
    3499:	e8 62 f0 ff ff       	call   2500 <fopen@plt>
    349e:	48 89 85 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rax
    34a5:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    34ac:	48 8b 95 60 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa0]
    34b3:	48 89 d6             	mov    rsi,rdx
    34b6:	48 89 c7             	mov    rdi,rax
    34b9:	e8 22 ef ff ff       	call   23e0 <fputs@plt>
    34be:	48 8b 85 60 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa0]
    34c5:	48 89 c7             	mov    rdi,rax
    34c8:	e8 e3 ee ff ff       	call   23b0 <fclose@plt>
    34cd:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    34d4:	48 8b 15 4d db 00 00 	mov    rdx,QWORD PTR [rip+0xdb4d]        # 11028 <stdout@GLIBC_2.2.5>
    34db:	48 89 d6             	mov    rsi,rdx
    34de:	48 89 c7             	mov    rdi,rax
    34e1:	e8 fa ee ff ff       	call   23e0 <fputs@plt>
    34e6:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    34ed:	48 89 c7             	mov    rdi,rax
    34f0:	e8 bb ee ff ff       	call   23b0 <fclose@plt>
    34f5:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    34fc:	48 89 c7             	mov    rdi,rax
    34ff:	e8 2c ee ff ff       	call   2330 <free@plt>
    3504:	48 8d 95 28 ff ff ff 	lea    rdx,[rbp-0xd8]
    350b:	48 8d 85 30 ff ff ff 	lea    rax,[rbp-0xd0]
    3512:	48 89 d6             	mov    rsi,rdx
    3515:	48 89 c7             	mov    rdi,rax
    3518:	e8 33 ee ff ff       	call   2350 <open_memstream@plt>
    351d:	48 89 85 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rax
    3524:	48 83 bd 70 ff ff ff 	cmp    QWORD PTR [rbp-0x90],0x0
    352b:	00 
    352c:	75 38                	jne    3566 <TEST_size_permutation____0+0xf0a>
    352e:	48 8b 05 cb db 00 00 	mov    rax,QWORD PTR [rip+0xdbcb]        # 11100 <stderr@GLIBC_2.2.5>
    3535:	4c 8d 05 c4 ad 00 00 	lea    r8,[rip+0xadc4]        # e300 <__func__.4>
    353c:	b9 1a 00 00 00       	mov    ecx,0x1a
    3541:	48 8d 15 fc aa 00 00 	lea    rdx,[rip+0xaafc]        # e044 <_IO_stdin_used+0x44>
    3548:	48 8d 35 01 ab 00 00 	lea    rsi,[rip+0xab01]        # e050 <_IO_stdin_used+0x50>
    354f:	48 89 c7             	mov    rdi,rax
    3552:	b8 00 00 00 00       	mov    eax,0x0
    3557:	e8 04 ef ff ff       	call   2460 <fprintf@plt>
    355c:	bf 00 00 00 00       	mov    edi,0x0
    3561:	e8 ba ef ff ff       	call   2520 <exit@plt>
    3566:	8b 05 34 db 00 00    	mov    eax,DWORD PTR [rip+0xdb34]        # 110a0 <k_DEFAULT@@Base>
    356c:	48 98                	cdqe   
    356e:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3575:	00 
    3576:	48 8d 05 43 db 00 00 	lea    rax,[rip+0xdb43]        # 110c0 <colors_f@@Base>
    357d:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    3581:	8b 05 f9 da 00 00    	mov    eax,DWORD PTR [rip+0xdaf9]        # 11080 <hk_TR@@Base>
    3587:	48 98                	cdqe   
    3589:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3590:	00 
    3591:	48 8d 05 a8 da 00 00 	lea    rax,[rip+0xdaa8]        # 11040 <tab_hk_f@@Base>
    3598:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    359c:	8b 05 e2 da 00 00    	mov    eax,DWORD PTR [rip+0xdae2]        # 11084 <k_RED@@Base>
    35a2:	48 98                	cdqe   
    35a4:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    35ab:	00 
    35ac:	48 8d 05 0d db 00 00 	lea    rax,[rip+0xdb0d]        # 110c0 <colors_f@@Base>
    35b3:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    35b7:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    35be:	4c 8d 0d 3b ad 00 00 	lea    r9,[rip+0xad3b]        # e300 <__func__.4>
    35c5:	49 89 f0             	mov    r8,rsi
    35c8:	48 8d 35 39 ab 00 00 	lea    rsi,[rip+0xab39]        # e108 <_IO_stdin_used+0x108>
    35cf:	48 89 c7             	mov    rdi,rax
    35d2:	b8 00 00 00 00       	mov    eax,0x0
    35d7:	e8 84 ee ff ff       	call   2460 <fprintf@plt>
    35dc:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    35e3:	48 89 c7             	mov    rdi,rax
    35e6:	e8 a5 ee ff ff       	call   2490 <fflush@plt>
    35eb:	0f b6 05 9e da 00 00 	movzx  eax,BYTE PTR [rip+0xda9e]        # 11090 <is_parallel_nb@@Base>
    35f2:	84 c0                	test   al,al
    35f4:	0f 84 ec 00 00 00    	je     36e6 <TEST_size_permutation____0+0x108a>
    35fa:	e8 51 ee ff ff       	call   2450 <id_of_thread_executed@plt>
    35ff:	48 89 45 80          	mov    QWORD PTR [rbp-0x80],rax
    3603:	0f b6 05 16 da 00 00 	movzx  eax,BYTE PTR [rip+0xda16]        # 11020 <log_parallel@@Base>
    360a:	84 c0                	test   al,al
    360c:	74 6d                	je     367b <TEST_size_permutation____0+0x101f>
    360e:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3615:	48 8b 15 0c da 00 00 	mov    rdx,QWORD PTR [rip+0xda0c]        # 11028 <stdout@GLIBC_2.2.5>
    361c:	48 89 d6             	mov    rsi,rdx
    361f:	48 89 c7             	mov    rdi,rax
    3622:	e8 b9 ed ff ff       	call   23e0 <fputs@plt>
    3627:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    362c:	0f 88 21 01 00 00    	js     3753 <TEST_size_permutation____0+0x10f7>
    3632:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3639:	48 8b 0d f0 d9 00 00 	mov    rcx,QWORD PTR [rip+0xd9f0]        # 11030 <f_ou_th@@Base>
    3640:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    3644:	48 c1 e2 03          	shl    rdx,0x3
    3648:	48 01 ca             	add    rdx,rcx
    364b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    364e:	48 89 d6             	mov    rsi,rdx
    3651:	48 89 c7             	mov    rdi,rax
    3654:	e8 87 ed ff ff       	call   23e0 <fputs@plt>
    3659:	48 8b 15 d0 d9 00 00 	mov    rdx,QWORD PTR [rip+0xd9d0]        # 11030 <f_ou_th@@Base>
    3660:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    3664:	48 c1 e0 03          	shl    rax,0x3
    3668:	48 01 d0             	add    rax,rdx
    366b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    366e:	48 89 c7             	mov    rdi,rax
    3671:	e8 1a ee ff ff       	call   2490 <fflush@plt>
    3676:	e9 d8 00 00 00       	jmp    3753 <TEST_size_permutation____0+0x10f7>
    367b:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    3680:	78 49                	js     36cb <TEST_size_permutation____0+0x106f>
    3682:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3689:	48 8b 0d a0 d9 00 00 	mov    rcx,QWORD PTR [rip+0xd9a0]        # 11030 <f_ou_th@@Base>
    3690:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    3694:	48 c1 e2 03          	shl    rdx,0x3
    3698:	48 01 ca             	add    rdx,rcx
    369b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    369e:	48 89 d6             	mov    rsi,rdx
    36a1:	48 89 c7             	mov    rdi,rax
    36a4:	e8 37 ed ff ff       	call   23e0 <fputs@plt>
    36a9:	48 8b 15 80 d9 00 00 	mov    rdx,QWORD PTR [rip+0xd980]        # 11030 <f_ou_th@@Base>
    36b0:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    36b4:	48 c1 e0 03          	shl    rax,0x3
    36b8:	48 01 d0             	add    rax,rdx
    36bb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    36be:	48 89 c7             	mov    rdi,rax
    36c1:	e8 ca ed ff ff       	call   2490 <fflush@plt>
    36c6:	e9 88 00 00 00       	jmp    3753 <TEST_size_permutation____0+0x10f7>
    36cb:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    36d2:	48 8b 15 4f d9 00 00 	mov    rdx,QWORD PTR [rip+0xd94f]        # 11028 <stdout@GLIBC_2.2.5>
    36d9:	48 89 d6             	mov    rsi,rdx
    36dc:	48 89 c7             	mov    rdi,rax
    36df:	e8 fc ec ff ff       	call   23e0 <fputs@plt>
    36e4:	eb 6d                	jmp    3753 <TEST_size_permutation____0+0x10f7>
    36e6:	48 8b 05 4b d9 00 00 	mov    rax,QWORD PTR [rip+0xd94b]        # 11038 <savelog@@Base>
    36ed:	48 85 c0             	test   rax,rax
    36f0:	74 48                	je     373a <TEST_size_permutation____0+0x10de>
    36f2:	48 8b 05 3f d9 00 00 	mov    rax,QWORD PTR [rip+0xd93f]        # 11038 <savelog@@Base>
    36f9:	48 8d 15 7f a9 00 00 	lea    rdx,[rip+0xa97f]        # e07f <_IO_stdin_used+0x7f>
    3700:	48 89 d6             	mov    rsi,rdx
    3703:	48 89 c7             	mov    rdi,rax
    3706:	e8 f5 ed ff ff       	call   2500 <fopen@plt>
    370b:	48 89 85 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rax
    3712:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3719:	48 8b 95 78 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x88]
    3720:	48 89 d6             	mov    rsi,rdx
    3723:	48 89 c7             	mov    rdi,rax
    3726:	e8 b5 ec ff ff       	call   23e0 <fputs@plt>
    372b:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    3732:	48 89 c7             	mov    rdi,rax
    3735:	e8 76 ec ff ff       	call   23b0 <fclose@plt>
    373a:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3741:	48 8b 15 e0 d8 00 00 	mov    rdx,QWORD PTR [rip+0xd8e0]        # 11028 <stdout@GLIBC_2.2.5>
    3748:	48 89 d6             	mov    rsi,rdx
    374b:	48 89 c7             	mov    rdi,rax
    374e:	e8 8d ec ff ff       	call   23e0 <fputs@plt>
    3753:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    375a:	48 89 c7             	mov    rdi,rax
    375d:	e8 4e ec ff ff       	call   23b0 <fclose@plt>
    3762:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    3769:	48 89 c7             	mov    rdi,rax
    376c:	e8 bf eb ff ff       	call   2330 <free@plt>
    3771:	90                   	nop
    3772:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    3776:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
    377d:	00 00 
    377f:	74 05                	je     3786 <TEST_size_permutation____0+0x112a>
    3781:	e8 3a ec ff ff       	call   23c0 <__stack_chk_fail@plt>
    3786:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    378a:	c9                   	leave  
    378b:	c3                   	ret    

000000000000378c <append_test_permutation_t_float_trans1>:
    378c:	f3 0f 1e fa          	endbr64 
    3790:	55                   	push   rbp
    3791:	48 89 e5             	mov    rbp,rsp
    3794:	48 8d 05 8d a9 00 00 	lea    rax,[rip+0xa98d]        # e128 <_IO_stdin_used+0x128>
    379b:	48 89 c6             	mov    rsi,rax
    379e:	48 8d 05 0a 00 00 00 	lea    rax,[rip+0xa]        # 37af <TEST_permutation_t_float_trans____1>
    37a5:	48 89 c7             	mov    rdi,rax
    37a8:	e8 93 eb ff ff       	call   2340 <append_func@plt>
    37ad:	5d                   	pop    rbp
    37ae:	c3                   	ret    

00000000000037af <TEST_permutation_t_float_trans____1>:
    37af:	f3 0f 1e fa          	endbr64 
    37b3:	55                   	push   rbp
    37b4:	48 89 e5             	mov    rbp,rsp
    37b7:	53                   	push   rbx
    37b8:	48 81 ec 18 02 00 00 	sub    rsp,0x218
    37bf:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    37c6:	00 00 
    37c8:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    37cc:	31 c0                	xor    eax,eax
    37ce:	c7 85 ec fd ff ff 06 	mov    DWORD PTR [rbp-0x214],0x6
    37d5:	00 00 00 
    37d8:	8b 85 ec fd ff ff    	mov    eax,DWORD PTR [rbp-0x214]
    37de:	48 98                	cdqe   
    37e0:	48 89 c7             	mov    rdi,rax
    37e3:	e8 29 8b 00 00       	call   c311 <CREATE_PERMUTATION_TYPE_FLOAT>
    37e8:	48 89 85 08 fe ff ff 	mov    QWORD PTR [rbp-0x1f8],rax
    37ef:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    37f6:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    37fd:	48 89 d6             	mov    rsi,rdx
    3800:	48 89 c7             	mov    rdi,rax
    3803:	e8 48 eb ff ff       	call   2350 <open_memstream@plt>
    3808:	48 89 85 10 fe ff ff 	mov    QWORD PTR [rbp-0x1f0],rax
    380f:	48 83 bd 10 fe ff ff 	cmp    QWORD PTR [rbp-0x1f0],0x0
    3816:	00 
    3817:	75 38                	jne    3851 <TEST_permutation_t_float_trans____1+0xa2>
    3819:	48 8b 05 e0 d8 00 00 	mov    rax,QWORD PTR [rip+0xd8e0]        # 11100 <stderr@GLIBC_2.2.5>
    3820:	4c 8d 05 f9 aa 00 00 	lea    r8,[rip+0xaaf9]        # e320 <__func__.3>
    3827:	b9 24 00 00 00       	mov    ecx,0x24
    382c:	48 8d 15 11 a8 00 00 	lea    rdx,[rip+0xa811]        # e044 <_IO_stdin_used+0x44>
    3833:	48 8d 35 16 a8 00 00 	lea    rsi,[rip+0xa816]        # e050 <_IO_stdin_used+0x50>
    383a:	48 89 c7             	mov    rdi,rax
    383d:	b8 00 00 00 00       	mov    eax,0x0
    3842:	e8 19 ec ff ff       	call   2460 <fprintf@plt>
    3847:	bf 00 00 00 00       	mov    edi,0x0
    384c:	e8 cf ec ff ff       	call   2520 <exit@plt>
    3851:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    3858:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    385b:	48 8b 85 10 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f0]
    3862:	48 8d 0d 08 a8 00 00 	lea    rcx,[rip+0xa808]        # e071 <_IO_stdin_used+0x71>
    3869:	48 89 ce             	mov    rsi,rcx
    386c:	48 89 c7             	mov    rdi,rax
    386f:	b8 00 00 00 00       	mov    eax,0x0
    3874:	e8 e7 eb ff ff       	call   2460 <fprintf@plt>
    3879:	48 8b 85 10 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f0]
    3880:	48 89 c7             	mov    rdi,rax
    3883:	e8 08 ec ff ff       	call   2490 <fflush@plt>
    3888:	0f b6 05 01 d8 00 00 	movzx  eax,BYTE PTR [rip+0xd801]        # 11090 <is_parallel_nb@@Base>
    388f:	84 c0                	test   al,al
    3891:	0f 84 01 01 00 00    	je     3998 <TEST_permutation_t_float_trans____1+0x1e9>
    3897:	e8 b4 eb ff ff       	call   2450 <id_of_thread_executed@plt>
    389c:	48 89 85 20 fe ff ff 	mov    QWORD PTR [rbp-0x1e0],rax
    38a3:	0f b6 05 76 d7 00 00 	movzx  eax,BYTE PTR [rip+0xd776]        # 11020 <log_parallel@@Base>
    38aa:	84 c0                	test   al,al
    38ac:	74 76                	je     3924 <TEST_permutation_t_float_trans____1+0x175>
    38ae:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    38b5:	48 8b 15 6c d7 00 00 	mov    rdx,QWORD PTR [rip+0xd76c]        # 11028 <stdout@GLIBC_2.2.5>
    38bc:	48 89 d6             	mov    rsi,rdx
    38bf:	48 89 c7             	mov    rdi,rax
    38c2:	e8 19 eb ff ff       	call   23e0 <fputs@plt>
    38c7:	48 83 bd 20 fe ff ff 	cmp    QWORD PTR [rbp-0x1e0],0x0
    38ce:	00 
    38cf:	0f 88 30 01 00 00    	js     3a05 <TEST_permutation_t_float_trans____1+0x256>
    38d5:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    38dc:	48 8b 0d 4d d7 00 00 	mov    rcx,QWORD PTR [rip+0xd74d]        # 11030 <f_ou_th@@Base>
    38e3:	48 8b 95 20 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1e0]
    38ea:	48 c1 e2 03          	shl    rdx,0x3
    38ee:	48 01 ca             	add    rdx,rcx
    38f1:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    38f4:	48 89 d6             	mov    rsi,rdx
    38f7:	48 89 c7             	mov    rdi,rax
    38fa:	e8 e1 ea ff ff       	call   23e0 <fputs@plt>
    38ff:	48 8b 15 2a d7 00 00 	mov    rdx,QWORD PTR [rip+0xd72a]        # 11030 <f_ou_th@@Base>
    3906:	48 8b 85 20 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1e0]
    390d:	48 c1 e0 03          	shl    rax,0x3
    3911:	48 01 d0             	add    rax,rdx
    3914:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3917:	48 89 c7             	mov    rdi,rax
    391a:	e8 71 eb ff ff       	call   2490 <fflush@plt>
    391f:	e9 e1 00 00 00       	jmp    3a05 <TEST_permutation_t_float_trans____1+0x256>
    3924:	48 83 bd 20 fe ff ff 	cmp    QWORD PTR [rbp-0x1e0],0x0
    392b:	00 
    392c:	78 4f                	js     397d <TEST_permutation_t_float_trans____1+0x1ce>
    392e:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3935:	48 8b 0d f4 d6 00 00 	mov    rcx,QWORD PTR [rip+0xd6f4]        # 11030 <f_ou_th@@Base>
    393c:	48 8b 95 20 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1e0]
    3943:	48 c1 e2 03          	shl    rdx,0x3
    3947:	48 01 ca             	add    rdx,rcx
    394a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    394d:	48 89 d6             	mov    rsi,rdx
    3950:	48 89 c7             	mov    rdi,rax
    3953:	e8 88 ea ff ff       	call   23e0 <fputs@plt>
    3958:	48 8b 15 d1 d6 00 00 	mov    rdx,QWORD PTR [rip+0xd6d1]        # 11030 <f_ou_th@@Base>
    395f:	48 8b 85 20 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1e0]
    3966:	48 c1 e0 03          	shl    rax,0x3
    396a:	48 01 d0             	add    rax,rdx
    396d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3970:	48 89 c7             	mov    rdi,rax
    3973:	e8 18 eb ff ff       	call   2490 <fflush@plt>
    3978:	e9 88 00 00 00       	jmp    3a05 <TEST_permutation_t_float_trans____1+0x256>
    397d:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3984:	48 8b 15 9d d6 00 00 	mov    rdx,QWORD PTR [rip+0xd69d]        # 11028 <stdout@GLIBC_2.2.5>
    398b:	48 89 d6             	mov    rsi,rdx
    398e:	48 89 c7             	mov    rdi,rax
    3991:	e8 4a ea ff ff       	call   23e0 <fputs@plt>
    3996:	eb 6d                	jmp    3a05 <TEST_permutation_t_float_trans____1+0x256>
    3998:	48 8b 05 99 d6 00 00 	mov    rax,QWORD PTR [rip+0xd699]        # 11038 <savelog@@Base>
    399f:	48 85 c0             	test   rax,rax
    39a2:	74 48                	je     39ec <TEST_permutation_t_float_trans____1+0x23d>
    39a4:	48 8b 05 8d d6 00 00 	mov    rax,QWORD PTR [rip+0xd68d]        # 11038 <savelog@@Base>
    39ab:	48 8d 15 cd a6 00 00 	lea    rdx,[rip+0xa6cd]        # e07f <_IO_stdin_used+0x7f>
    39b2:	48 89 d6             	mov    rsi,rdx
    39b5:	48 89 c7             	mov    rdi,rax
    39b8:	e8 43 eb ff ff       	call   2500 <fopen@plt>
    39bd:	48 89 85 18 fe ff ff 	mov    QWORD PTR [rbp-0x1e8],rax
    39c4:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    39cb:	48 8b 95 18 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1e8]
    39d2:	48 89 d6             	mov    rsi,rdx
    39d5:	48 89 c7             	mov    rdi,rax
    39d8:	e8 03 ea ff ff       	call   23e0 <fputs@plt>
    39dd:	48 8b 85 18 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1e8]
    39e4:	48 89 c7             	mov    rdi,rax
    39e7:	e8 c4 e9 ff ff       	call   23b0 <fclose@plt>
    39ec:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    39f3:	48 8b 15 2e d6 00 00 	mov    rdx,QWORD PTR [rip+0xd62e]        # 11028 <stdout@GLIBC_2.2.5>
    39fa:	48 89 d6             	mov    rsi,rdx
    39fd:	48 89 c7             	mov    rdi,rax
    3a00:	e8 db e9 ff ff       	call   23e0 <fputs@plt>
    3a05:	48 8b 85 10 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f0]
    3a0c:	48 89 c7             	mov    rdi,rax
    3a0f:	e8 9c e9 ff ff       	call   23b0 <fclose@plt>
    3a14:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3a1b:	48 89 c7             	mov    rdi,rax
    3a1e:	e8 0d e9 ff ff       	call   2330 <free@plt>
    3a23:	0f b6 05 66 d6 00 00 	movzx  eax,BYTE PTR [rip+0xd666]        # 11090 <is_parallel_nb@@Base>
    3a2a:	83 f0 01             	xor    eax,0x1
    3a2d:	84 c0                	test   al,al
    3a2f:	0f 84 c2 07 00 00    	je     41f7 <TEST_permutation_t_float_trans____1+0xa48>
    3a35:	8b 85 ec fd ff ff    	mov    eax,DWORD PTR [rbp-0x214]
    3a3b:	48 98                	cdqe   
    3a3d:	48 8b 95 08 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1f8]
    3a44:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3a47:	48 89 c6             	mov    rsi,rax
    3a4a:	48 89 d7             	mov    rdi,rdx
    3a4d:	e8 ae e9 ff ff       	call   2400 <expected_EQ_TYPE_L_INT@plt>
    3a52:	84 c0                	test   al,al
    3a54:	0f 84 87 02 00 00    	je     3ce1 <TEST_permutation_t_float_trans____1+0x532>
    3a5a:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    3a61:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    3a68:	48 89 d6             	mov    rsi,rdx
    3a6b:	48 89 c7             	mov    rdi,rax
    3a6e:	e8 dd e8 ff ff       	call   2350 <open_memstream@plt>
    3a73:	48 89 85 a0 fe ff ff 	mov    QWORD PTR [rbp-0x160],rax
    3a7a:	48 83 bd a0 fe ff ff 	cmp    QWORD PTR [rbp-0x160],0x0
    3a81:	00 
    3a82:	75 38                	jne    3abc <TEST_permutation_t_float_trans____1+0x30d>
    3a84:	48 8b 05 75 d6 00 00 	mov    rax,QWORD PTR [rip+0xd675]        # 11100 <stderr@GLIBC_2.2.5>
    3a8b:	4c 8d 05 8e a8 00 00 	lea    r8,[rip+0xa88e]        # e320 <__func__.3>
    3a92:	b9 25 00 00 00       	mov    ecx,0x25
    3a97:	48 8d 15 a6 a5 00 00 	lea    rdx,[rip+0xa5a6]        # e044 <_IO_stdin_used+0x44>
    3a9e:	48 8d 35 ab a5 00 00 	lea    rsi,[rip+0xa5ab]        # e050 <_IO_stdin_used+0x50>
    3aa5:	48 89 c7             	mov    rdi,rax
    3aa8:	b8 00 00 00 00       	mov    eax,0x0
    3aad:	e8 ae e9 ff ff       	call   2460 <fprintf@plt>
    3ab2:	bf 00 00 00 00       	mov    edi,0x0
    3ab7:	e8 64 ea ff ff       	call   2520 <exit@plt>
    3abc:	8b 05 de d5 00 00    	mov    eax,DWORD PTR [rip+0xd5de]        # 110a0 <k_DEFAULT@@Base>
    3ac2:	48 98                	cdqe   
    3ac4:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3acb:	00 
    3acc:	48 8d 05 ed d5 00 00 	lea    rax,[rip+0xd5ed]        # 110c0 <colors_f@@Base>
    3ad3:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    3ad7:	8b 05 a3 d5 00 00    	mov    eax,DWORD PTR [rip+0xd5a3]        # 11080 <hk_TR@@Base>
    3add:	48 98                	cdqe   
    3adf:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3ae6:	00 
    3ae7:	48 8d 05 52 d5 00 00 	lea    rax,[rip+0xd552]        # 11040 <tab_hk_f@@Base>
    3aee:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    3af2:	8b 05 f8 d5 00 00    	mov    eax,DWORD PTR [rip+0xd5f8]        # 110f0 <k_GREEN@@Base>
    3af8:	48 98                	cdqe   
    3afa:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3b01:	00 
    3b02:	48 8d 05 b7 d5 00 00 	lea    rax,[rip+0xd5b7]        # 110c0 <colors_f@@Base>
    3b09:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    3b0d:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    3b14:	4c 8d 0d 05 a8 00 00 	lea    r9,[rip+0xa805]        # e320 <__func__.3>
    3b1b:	49 89 f0             	mov    r8,rsi
    3b1e:	48 8d 35 63 a5 00 00 	lea    rsi,[rip+0xa563]        # e088 <_IO_stdin_used+0x88>
    3b25:	48 89 c7             	mov    rdi,rax
    3b28:	b8 00 00 00 00       	mov    eax,0x0
    3b2d:	e8 2e e9 ff ff       	call   2460 <fprintf@plt>
    3b32:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    3b39:	48 89 c7             	mov    rdi,rax
    3b3c:	e8 4f e9 ff ff       	call   2490 <fflush@plt>
    3b41:	0f b6 05 48 d5 00 00 	movzx  eax,BYTE PTR [rip+0xd548]        # 11090 <is_parallel_nb@@Base>
    3b48:	84 c0                	test   al,al
    3b4a:	0f 84 01 01 00 00    	je     3c51 <TEST_permutation_t_float_trans____1+0x4a2>
    3b50:	e8 fb e8 ff ff       	call   2450 <id_of_thread_executed@plt>
    3b55:	48 89 85 b0 fe ff ff 	mov    QWORD PTR [rbp-0x150],rax
    3b5c:	0f b6 05 bd d4 00 00 	movzx  eax,BYTE PTR [rip+0xd4bd]        # 11020 <log_parallel@@Base>
    3b63:	84 c0                	test   al,al
    3b65:	74 76                	je     3bdd <TEST_permutation_t_float_trans____1+0x42e>
    3b67:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3b6e:	48 8b 15 b3 d4 00 00 	mov    rdx,QWORD PTR [rip+0xd4b3]        # 11028 <stdout@GLIBC_2.2.5>
    3b75:	48 89 d6             	mov    rsi,rdx
    3b78:	48 89 c7             	mov    rdi,rax
    3b7b:	e8 60 e8 ff ff       	call   23e0 <fputs@plt>
    3b80:	48 83 bd b0 fe ff ff 	cmp    QWORD PTR [rbp-0x150],0x0
    3b87:	00 
    3b88:	0f 88 30 01 00 00    	js     3cbe <TEST_permutation_t_float_trans____1+0x50f>
    3b8e:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3b95:	48 8b 0d 94 d4 00 00 	mov    rcx,QWORD PTR [rip+0xd494]        # 11030 <f_ou_th@@Base>
    3b9c:	48 8b 95 b0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x150]
    3ba3:	48 c1 e2 03          	shl    rdx,0x3
    3ba7:	48 01 ca             	add    rdx,rcx
    3baa:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3bad:	48 89 d6             	mov    rsi,rdx
    3bb0:	48 89 c7             	mov    rdi,rax
    3bb3:	e8 28 e8 ff ff       	call   23e0 <fputs@plt>
    3bb8:	48 8b 15 71 d4 00 00 	mov    rdx,QWORD PTR [rip+0xd471]        # 11030 <f_ou_th@@Base>
    3bbf:	48 8b 85 b0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x150]
    3bc6:	48 c1 e0 03          	shl    rax,0x3
    3bca:	48 01 d0             	add    rax,rdx
    3bcd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3bd0:	48 89 c7             	mov    rdi,rax
    3bd3:	e8 b8 e8 ff ff       	call   2490 <fflush@plt>
    3bd8:	e9 e1 00 00 00       	jmp    3cbe <TEST_permutation_t_float_trans____1+0x50f>
    3bdd:	48 83 bd b0 fe ff ff 	cmp    QWORD PTR [rbp-0x150],0x0
    3be4:	00 
    3be5:	78 4f                	js     3c36 <TEST_permutation_t_float_trans____1+0x487>
    3be7:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3bee:	48 8b 0d 3b d4 00 00 	mov    rcx,QWORD PTR [rip+0xd43b]        # 11030 <f_ou_th@@Base>
    3bf5:	48 8b 95 b0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x150]
    3bfc:	48 c1 e2 03          	shl    rdx,0x3
    3c00:	48 01 ca             	add    rdx,rcx
    3c03:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3c06:	48 89 d6             	mov    rsi,rdx
    3c09:	48 89 c7             	mov    rdi,rax
    3c0c:	e8 cf e7 ff ff       	call   23e0 <fputs@plt>
    3c11:	48 8b 15 18 d4 00 00 	mov    rdx,QWORD PTR [rip+0xd418]        # 11030 <f_ou_th@@Base>
    3c18:	48 8b 85 b0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x150]
    3c1f:	48 c1 e0 03          	shl    rax,0x3
    3c23:	48 01 d0             	add    rax,rdx
    3c26:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3c29:	48 89 c7             	mov    rdi,rax
    3c2c:	e8 5f e8 ff ff       	call   2490 <fflush@plt>
    3c31:	e9 88 00 00 00       	jmp    3cbe <TEST_permutation_t_float_trans____1+0x50f>
    3c36:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3c3d:	48 8b 15 e4 d3 00 00 	mov    rdx,QWORD PTR [rip+0xd3e4]        # 11028 <stdout@GLIBC_2.2.5>
    3c44:	48 89 d6             	mov    rsi,rdx
    3c47:	48 89 c7             	mov    rdi,rax
    3c4a:	e8 91 e7 ff ff       	call   23e0 <fputs@plt>
    3c4f:	eb 6d                	jmp    3cbe <TEST_permutation_t_float_trans____1+0x50f>
    3c51:	48 8b 05 e0 d3 00 00 	mov    rax,QWORD PTR [rip+0xd3e0]        # 11038 <savelog@@Base>
    3c58:	48 85 c0             	test   rax,rax
    3c5b:	74 48                	je     3ca5 <TEST_permutation_t_float_trans____1+0x4f6>
    3c5d:	48 8b 05 d4 d3 00 00 	mov    rax,QWORD PTR [rip+0xd3d4]        # 11038 <savelog@@Base>
    3c64:	48 8d 15 14 a4 00 00 	lea    rdx,[rip+0xa414]        # e07f <_IO_stdin_used+0x7f>
    3c6b:	48 89 d6             	mov    rsi,rdx
    3c6e:	48 89 c7             	mov    rdi,rax
    3c71:	e8 8a e8 ff ff       	call   2500 <fopen@plt>
    3c76:	48 89 85 a8 fe ff ff 	mov    QWORD PTR [rbp-0x158],rax
    3c7d:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3c84:	48 8b 95 a8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x158]
    3c8b:	48 89 d6             	mov    rsi,rdx
    3c8e:	48 89 c7             	mov    rdi,rax
    3c91:	e8 4a e7 ff ff       	call   23e0 <fputs@plt>
    3c96:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    3c9d:	48 89 c7             	mov    rdi,rax
    3ca0:	e8 0b e7 ff ff       	call   23b0 <fclose@plt>
    3ca5:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3cac:	48 8b 15 75 d3 00 00 	mov    rdx,QWORD PTR [rip+0xd375]        # 11028 <stdout@GLIBC_2.2.5>
    3cb3:	48 89 d6             	mov    rsi,rdx
    3cb6:	48 89 c7             	mov    rdi,rax
    3cb9:	e8 22 e7 ff ff       	call   23e0 <fputs@plt>
    3cbe:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    3cc5:	48 89 c7             	mov    rdi,rax
    3cc8:	e8 e3 e6 ff ff       	call   23b0 <fclose@plt>
    3ccd:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3cd4:	48 89 c7             	mov    rdi,rax
    3cd7:	e8 54 e6 ff ff       	call   2330 <free@plt>
    3cdc:	e9 dd 0c 00 00       	jmp    49be <TEST_permutation_t_float_trans____1+0x120f>
    3ce1:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    3ce8:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    3cef:	48 89 d6             	mov    rsi,rdx
    3cf2:	48 89 c7             	mov    rdi,rax
    3cf5:	e8 56 e6 ff ff       	call   2350 <open_memstream@plt>
    3cfa:	48 89 85 70 fe ff ff 	mov    QWORD PTR [rbp-0x190],rax
    3d01:	48 83 bd 70 fe ff ff 	cmp    QWORD PTR [rbp-0x190],0x0
    3d08:	00 
    3d09:	75 38                	jne    3d43 <TEST_permutation_t_float_trans____1+0x594>
    3d0b:	48 8b 05 ee d3 00 00 	mov    rax,QWORD PTR [rip+0xd3ee]        # 11100 <stderr@GLIBC_2.2.5>
    3d12:	4c 8d 05 07 a6 00 00 	lea    r8,[rip+0xa607]        # e320 <__func__.3>
    3d19:	b9 25 00 00 00       	mov    ecx,0x25
    3d1e:	48 8d 15 1f a3 00 00 	lea    rdx,[rip+0xa31f]        # e044 <_IO_stdin_used+0x44>
    3d25:	48 8d 35 24 a3 00 00 	lea    rsi,[rip+0xa324]        # e050 <_IO_stdin_used+0x50>
    3d2c:	48 89 c7             	mov    rdi,rax
    3d2f:	b8 00 00 00 00       	mov    eax,0x0
    3d34:	e8 27 e7 ff ff       	call   2460 <fprintf@plt>
    3d39:	bf 00 00 00 00       	mov    edi,0x0
    3d3e:	e8 dd e7 ff ff       	call   2520 <exit@plt>
    3d43:	8b 85 ec fd ff ff    	mov    eax,DWORD PTR [rbp-0x214]
    3d49:	48 98                	cdqe   
    3d4b:	48 89 c7             	mov    rdi,rax
    3d4e:	e8 dd e7 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    3d53:	48 89 c3             	mov    rbx,rax
    3d56:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    3d5d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3d60:	48 89 c7             	mov    rdi,rax
    3d63:	e8 c8 e7 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    3d68:	48 89 c2             	mov    rdx,rax
    3d6b:	48 8b 85 70 fe ff ff 	mov    rax,QWORD PTR [rbp-0x190]
    3d72:	53                   	push   rbx
    3d73:	48 8d 0d db a3 00 00 	lea    rcx,[rip+0xa3db]        # e155 <_IO_stdin_used+0x155>
    3d7a:	51                   	push   rcx
    3d7b:	52                   	push   rdx
    3d7c:	48 8d 15 25 a3 00 00 	lea    rdx,[rip+0xa325]        # e0a8 <_IO_stdin_used+0xa8>
    3d83:	52                   	push   rdx
    3d84:	48 8d 15 ca a3 00 00 	lea    rdx,[rip+0xa3ca]        # e155 <_IO_stdin_used+0x155>
    3d8b:	52                   	push   rdx
    3d8c:	48 8d 15 71 a3 00 00 	lea    rdx,[rip+0xa371]        # e104 <_IO_stdin_used+0x104>
    3d93:	52                   	push   rdx
    3d94:	4c 8d 0d 0d a3 00 00 	lea    r9,[rip+0xa30d]        # e0a8 <_IO_stdin_used+0xa8>
    3d9b:	4c 8d 05 7e a5 00 00 	lea    r8,[rip+0xa57e]        # e320 <__func__.3>
    3da2:	b9 25 00 00 00       	mov    ecx,0x25
    3da7:	48 8d 15 96 a2 00 00 	lea    rdx,[rip+0xa296]        # e044 <_IO_stdin_used+0x44>
    3dae:	48 8d 35 fb a2 00 00 	lea    rsi,[rip+0xa2fb]        # e0b0 <_IO_stdin_used+0xb0>
    3db5:	48 89 c7             	mov    rdi,rax
    3db8:	b8 00 00 00 00       	mov    eax,0x0
    3dbd:	e8 9e e6 ff ff       	call   2460 <fprintf@plt>
    3dc2:	48 83 c4 30          	add    rsp,0x30
    3dc6:	48 8b 85 70 fe ff ff 	mov    rax,QWORD PTR [rbp-0x190]
    3dcd:	48 89 c7             	mov    rdi,rax
    3dd0:	e8 bb e6 ff ff       	call   2490 <fflush@plt>
    3dd5:	0f b6 05 b4 d2 00 00 	movzx  eax,BYTE PTR [rip+0xd2b4]        # 11090 <is_parallel_nb@@Base>
    3ddc:	84 c0                	test   al,al
    3dde:	0f 84 01 01 00 00    	je     3ee5 <TEST_permutation_t_float_trans____1+0x736>
    3de4:	e8 67 e6 ff ff       	call   2450 <id_of_thread_executed@plt>
    3de9:	48 89 85 80 fe ff ff 	mov    QWORD PTR [rbp-0x180],rax
    3df0:	0f b6 05 29 d2 00 00 	movzx  eax,BYTE PTR [rip+0xd229]        # 11020 <log_parallel@@Base>
    3df7:	84 c0                	test   al,al
    3df9:	74 76                	je     3e71 <TEST_permutation_t_float_trans____1+0x6c2>
    3dfb:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3e02:	48 8b 15 1f d2 00 00 	mov    rdx,QWORD PTR [rip+0xd21f]        # 11028 <stdout@GLIBC_2.2.5>
    3e09:	48 89 d6             	mov    rsi,rdx
    3e0c:	48 89 c7             	mov    rdi,rax
    3e0f:	e8 cc e5 ff ff       	call   23e0 <fputs@plt>
    3e14:	48 83 bd 80 fe ff ff 	cmp    QWORD PTR [rbp-0x180],0x0
    3e1b:	00 
    3e1c:	0f 88 30 01 00 00    	js     3f52 <TEST_permutation_t_float_trans____1+0x7a3>
    3e22:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3e29:	48 8b 0d 00 d2 00 00 	mov    rcx,QWORD PTR [rip+0xd200]        # 11030 <f_ou_th@@Base>
    3e30:	48 8b 95 80 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x180]
    3e37:	48 c1 e2 03          	shl    rdx,0x3
    3e3b:	48 01 ca             	add    rdx,rcx
    3e3e:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3e41:	48 89 d6             	mov    rsi,rdx
    3e44:	48 89 c7             	mov    rdi,rax
    3e47:	e8 94 e5 ff ff       	call   23e0 <fputs@plt>
    3e4c:	48 8b 15 dd d1 00 00 	mov    rdx,QWORD PTR [rip+0xd1dd]        # 11030 <f_ou_th@@Base>
    3e53:	48 8b 85 80 fe ff ff 	mov    rax,QWORD PTR [rbp-0x180]
    3e5a:	48 c1 e0 03          	shl    rax,0x3
    3e5e:	48 01 d0             	add    rax,rdx
    3e61:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3e64:	48 89 c7             	mov    rdi,rax
    3e67:	e8 24 e6 ff ff       	call   2490 <fflush@plt>
    3e6c:	e9 e1 00 00 00       	jmp    3f52 <TEST_permutation_t_float_trans____1+0x7a3>
    3e71:	48 83 bd 80 fe ff ff 	cmp    QWORD PTR [rbp-0x180],0x0
    3e78:	00 
    3e79:	78 4f                	js     3eca <TEST_permutation_t_float_trans____1+0x71b>
    3e7b:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3e82:	48 8b 0d a7 d1 00 00 	mov    rcx,QWORD PTR [rip+0xd1a7]        # 11030 <f_ou_th@@Base>
    3e89:	48 8b 95 80 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x180]
    3e90:	48 c1 e2 03          	shl    rdx,0x3
    3e94:	48 01 ca             	add    rdx,rcx
    3e97:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    3e9a:	48 89 d6             	mov    rsi,rdx
    3e9d:	48 89 c7             	mov    rdi,rax
    3ea0:	e8 3b e5 ff ff       	call   23e0 <fputs@plt>
    3ea5:	48 8b 15 84 d1 00 00 	mov    rdx,QWORD PTR [rip+0xd184]        # 11030 <f_ou_th@@Base>
    3eac:	48 8b 85 80 fe ff ff 	mov    rax,QWORD PTR [rbp-0x180]
    3eb3:	48 c1 e0 03          	shl    rax,0x3
    3eb7:	48 01 d0             	add    rax,rdx
    3eba:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3ebd:	48 89 c7             	mov    rdi,rax
    3ec0:	e8 cb e5 ff ff       	call   2490 <fflush@plt>
    3ec5:	e9 88 00 00 00       	jmp    3f52 <TEST_permutation_t_float_trans____1+0x7a3>
    3eca:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3ed1:	48 8b 15 50 d1 00 00 	mov    rdx,QWORD PTR [rip+0xd150]        # 11028 <stdout@GLIBC_2.2.5>
    3ed8:	48 89 d6             	mov    rsi,rdx
    3edb:	48 89 c7             	mov    rdi,rax
    3ede:	e8 fd e4 ff ff       	call   23e0 <fputs@plt>
    3ee3:	eb 6d                	jmp    3f52 <TEST_permutation_t_float_trans____1+0x7a3>
    3ee5:	48 8b 05 4c d1 00 00 	mov    rax,QWORD PTR [rip+0xd14c]        # 11038 <savelog@@Base>
    3eec:	48 85 c0             	test   rax,rax
    3eef:	74 48                	je     3f39 <TEST_permutation_t_float_trans____1+0x78a>
    3ef1:	48 8b 05 40 d1 00 00 	mov    rax,QWORD PTR [rip+0xd140]        # 11038 <savelog@@Base>
    3ef8:	48 8d 15 80 a1 00 00 	lea    rdx,[rip+0xa180]        # e07f <_IO_stdin_used+0x7f>
    3eff:	48 89 d6             	mov    rsi,rdx
    3f02:	48 89 c7             	mov    rdi,rax
    3f05:	e8 f6 e5 ff ff       	call   2500 <fopen@plt>
    3f0a:	48 89 85 78 fe ff ff 	mov    QWORD PTR [rbp-0x188],rax
    3f11:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3f18:	48 8b 95 78 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x188]
    3f1f:	48 89 d6             	mov    rsi,rdx
    3f22:	48 89 c7             	mov    rdi,rax
    3f25:	e8 b6 e4 ff ff       	call   23e0 <fputs@plt>
    3f2a:	48 8b 85 78 fe ff ff 	mov    rax,QWORD PTR [rbp-0x188]
    3f31:	48 89 c7             	mov    rdi,rax
    3f34:	e8 77 e4 ff ff       	call   23b0 <fclose@plt>
    3f39:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3f40:	48 8b 15 e1 d0 00 00 	mov    rdx,QWORD PTR [rip+0xd0e1]        # 11028 <stdout@GLIBC_2.2.5>
    3f47:	48 89 d6             	mov    rsi,rdx
    3f4a:	48 89 c7             	mov    rdi,rax
    3f4d:	e8 8e e4 ff ff       	call   23e0 <fputs@plt>
    3f52:	48 8b 85 70 fe ff ff 	mov    rax,QWORD PTR [rbp-0x190]
    3f59:	48 89 c7             	mov    rdi,rax
    3f5c:	e8 4f e4 ff ff       	call   23b0 <fclose@plt>
    3f61:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    3f68:	48 89 c7             	mov    rdi,rax
    3f6b:	e8 c0 e3 ff ff       	call   2330 <free@plt>
    3f70:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    3f77:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    3f7e:	48 89 d6             	mov    rsi,rdx
    3f81:	48 89 c7             	mov    rdi,rax
    3f84:	e8 c7 e3 ff ff       	call   2350 <open_memstream@plt>
    3f89:	48 89 85 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rax
    3f90:	48 83 bd 88 fe ff ff 	cmp    QWORD PTR [rbp-0x178],0x0
    3f97:	00 
    3f98:	75 38                	jne    3fd2 <TEST_permutation_t_float_trans____1+0x823>
    3f9a:	48 8b 05 5f d1 00 00 	mov    rax,QWORD PTR [rip+0xd15f]        # 11100 <stderr@GLIBC_2.2.5>
    3fa1:	4c 8d 05 78 a3 00 00 	lea    r8,[rip+0xa378]        # e320 <__func__.3>
    3fa8:	b9 25 00 00 00       	mov    ecx,0x25
    3fad:	48 8d 15 90 a0 00 00 	lea    rdx,[rip+0xa090]        # e044 <_IO_stdin_used+0x44>
    3fb4:	48 8d 35 95 a0 00 00 	lea    rsi,[rip+0xa095]        # e050 <_IO_stdin_used+0x50>
    3fbb:	48 89 c7             	mov    rdi,rax
    3fbe:	b8 00 00 00 00       	mov    eax,0x0
    3fc3:	e8 98 e4 ff ff       	call   2460 <fprintf@plt>
    3fc8:	bf 00 00 00 00       	mov    edi,0x0
    3fcd:	e8 4e e5 ff ff       	call   2520 <exit@plt>
    3fd2:	8b 05 c8 d0 00 00    	mov    eax,DWORD PTR [rip+0xd0c8]        # 110a0 <k_DEFAULT@@Base>
    3fd8:	48 98                	cdqe   
    3fda:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3fe1:	00 
    3fe2:	48 8d 05 d7 d0 00 00 	lea    rax,[rip+0xd0d7]        # 110c0 <colors_f@@Base>
    3fe9:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    3fed:	8b 05 8d d0 00 00    	mov    eax,DWORD PTR [rip+0xd08d]        # 11080 <hk_TR@@Base>
    3ff3:	48 98                	cdqe   
    3ff5:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    3ffc:	00 
    3ffd:	48 8d 05 3c d0 00 00 	lea    rax,[rip+0xd03c]        # 11040 <tab_hk_f@@Base>
    4004:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    4008:	8b 05 76 d0 00 00    	mov    eax,DWORD PTR [rip+0xd076]        # 11084 <k_RED@@Base>
    400e:	48 98                	cdqe   
    4010:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    4017:	00 
    4018:	48 8d 05 a1 d0 00 00 	lea    rax,[rip+0xd0a1]        # 110c0 <colors_f@@Base>
    401f:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    4023:	48 8b 85 88 fe ff ff 	mov    rax,QWORD PTR [rbp-0x178]
    402a:	4c 8d 0d ef a2 00 00 	lea    r9,[rip+0xa2ef]        # e320 <__func__.3>
    4031:	49 89 f0             	mov    r8,rsi
    4034:	48 8d 35 cd a0 00 00 	lea    rsi,[rip+0xa0cd]        # e108 <_IO_stdin_used+0x108>
    403b:	48 89 c7             	mov    rdi,rax
    403e:	b8 00 00 00 00       	mov    eax,0x0
    4043:	e8 18 e4 ff ff       	call   2460 <fprintf@plt>
    4048:	48 8b 85 88 fe ff ff 	mov    rax,QWORD PTR [rbp-0x178]
    404f:	48 89 c7             	mov    rdi,rax
    4052:	e8 39 e4 ff ff       	call   2490 <fflush@plt>
    4057:	0f b6 05 32 d0 00 00 	movzx  eax,BYTE PTR [rip+0xd032]        # 11090 <is_parallel_nb@@Base>
    405e:	84 c0                	test   al,al
    4060:	0f 84 01 01 00 00    	je     4167 <TEST_permutation_t_float_trans____1+0x9b8>
    4066:	e8 e5 e3 ff ff       	call   2450 <id_of_thread_executed@plt>
    406b:	48 89 85 98 fe ff ff 	mov    QWORD PTR [rbp-0x168],rax
    4072:	0f b6 05 a7 cf 00 00 	movzx  eax,BYTE PTR [rip+0xcfa7]        # 11020 <log_parallel@@Base>
    4079:	84 c0                	test   al,al
    407b:	74 76                	je     40f3 <TEST_permutation_t_float_trans____1+0x944>
    407d:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4084:	48 8b 15 9d cf 00 00 	mov    rdx,QWORD PTR [rip+0xcf9d]        # 11028 <stdout@GLIBC_2.2.5>
    408b:	48 89 d6             	mov    rsi,rdx
    408e:	48 89 c7             	mov    rdi,rax
    4091:	e8 4a e3 ff ff       	call   23e0 <fputs@plt>
    4096:	48 83 bd 98 fe ff ff 	cmp    QWORD PTR [rbp-0x168],0x0
    409d:	00 
    409e:	0f 88 30 01 00 00    	js     41d4 <TEST_permutation_t_float_trans____1+0xa25>
    40a4:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    40ab:	48 8b 0d 7e cf 00 00 	mov    rcx,QWORD PTR [rip+0xcf7e]        # 11030 <f_ou_th@@Base>
    40b2:	48 8b 95 98 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x168]
    40b9:	48 c1 e2 03          	shl    rdx,0x3
    40bd:	48 01 ca             	add    rdx,rcx
    40c0:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    40c3:	48 89 d6             	mov    rsi,rdx
    40c6:	48 89 c7             	mov    rdi,rax
    40c9:	e8 12 e3 ff ff       	call   23e0 <fputs@plt>
    40ce:	48 8b 15 5b cf 00 00 	mov    rdx,QWORD PTR [rip+0xcf5b]        # 11030 <f_ou_th@@Base>
    40d5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    40dc:	48 c1 e0 03          	shl    rax,0x3
    40e0:	48 01 d0             	add    rax,rdx
    40e3:	48 8b 00             	mov    rax,QWORD PTR [rax]
    40e6:	48 89 c7             	mov    rdi,rax
    40e9:	e8 a2 e3 ff ff       	call   2490 <fflush@plt>
    40ee:	e9 e1 00 00 00       	jmp    41d4 <TEST_permutation_t_float_trans____1+0xa25>
    40f3:	48 83 bd 98 fe ff ff 	cmp    QWORD PTR [rbp-0x168],0x0
    40fa:	00 
    40fb:	78 4f                	js     414c <TEST_permutation_t_float_trans____1+0x99d>
    40fd:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4104:	48 8b 0d 25 cf 00 00 	mov    rcx,QWORD PTR [rip+0xcf25]        # 11030 <f_ou_th@@Base>
    410b:	48 8b 95 98 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x168]
    4112:	48 c1 e2 03          	shl    rdx,0x3
    4116:	48 01 ca             	add    rdx,rcx
    4119:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    411c:	48 89 d6             	mov    rsi,rdx
    411f:	48 89 c7             	mov    rdi,rax
    4122:	e8 b9 e2 ff ff       	call   23e0 <fputs@plt>
    4127:	48 8b 15 02 cf 00 00 	mov    rdx,QWORD PTR [rip+0xcf02]        # 11030 <f_ou_th@@Base>
    412e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    4135:	48 c1 e0 03          	shl    rax,0x3
    4139:	48 01 d0             	add    rax,rdx
    413c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    413f:	48 89 c7             	mov    rdi,rax
    4142:	e8 49 e3 ff ff       	call   2490 <fflush@plt>
    4147:	e9 88 00 00 00       	jmp    41d4 <TEST_permutation_t_float_trans____1+0xa25>
    414c:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4153:	48 8b 15 ce ce 00 00 	mov    rdx,QWORD PTR [rip+0xcece]        # 11028 <stdout@GLIBC_2.2.5>
    415a:	48 89 d6             	mov    rsi,rdx
    415d:	48 89 c7             	mov    rdi,rax
    4160:	e8 7b e2 ff ff       	call   23e0 <fputs@plt>
    4165:	eb 6d                	jmp    41d4 <TEST_permutation_t_float_trans____1+0xa25>
    4167:	48 8b 05 ca ce 00 00 	mov    rax,QWORD PTR [rip+0xceca]        # 11038 <savelog@@Base>
    416e:	48 85 c0             	test   rax,rax
    4171:	74 48                	je     41bb <TEST_permutation_t_float_trans____1+0xa0c>
    4173:	48 8b 05 be ce 00 00 	mov    rax,QWORD PTR [rip+0xcebe]        # 11038 <savelog@@Base>
    417a:	48 8d 15 fe 9e 00 00 	lea    rdx,[rip+0x9efe]        # e07f <_IO_stdin_used+0x7f>
    4181:	48 89 d6             	mov    rsi,rdx
    4184:	48 89 c7             	mov    rdi,rax
    4187:	e8 74 e3 ff ff       	call   2500 <fopen@plt>
    418c:	48 89 85 90 fe ff ff 	mov    QWORD PTR [rbp-0x170],rax
    4193:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    419a:	48 8b 95 90 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x170]
    41a1:	48 89 d6             	mov    rsi,rdx
    41a4:	48 89 c7             	mov    rdi,rax
    41a7:	e8 34 e2 ff ff       	call   23e0 <fputs@plt>
    41ac:	48 8b 85 90 fe ff ff 	mov    rax,QWORD PTR [rbp-0x170]
    41b3:	48 89 c7             	mov    rdi,rax
    41b6:	e8 f5 e1 ff ff       	call   23b0 <fclose@plt>
    41bb:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    41c2:	48 8b 15 5f ce 00 00 	mov    rdx,QWORD PTR [rip+0xce5f]        # 11028 <stdout@GLIBC_2.2.5>
    41c9:	48 89 d6             	mov    rsi,rdx
    41cc:	48 89 c7             	mov    rdi,rax
    41cf:	e8 0c e2 ff ff       	call   23e0 <fputs@plt>
    41d4:	48 8b 85 88 fe ff ff 	mov    rax,QWORD PTR [rbp-0x178]
    41db:	48 89 c7             	mov    rdi,rax
    41de:	e8 cd e1 ff ff       	call   23b0 <fclose@plt>
    41e3:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    41ea:	48 89 c7             	mov    rdi,rax
    41ed:	e8 3e e1 ff ff       	call   2330 <free@plt>
    41f2:	e9 c7 07 00 00       	jmp    49be <TEST_permutation_t_float_trans____1+0x120f>
    41f7:	8b 85 ec fd ff ff    	mov    eax,DWORD PTR [rbp-0x214]
    41fd:	48 98                	cdqe   
    41ff:	48 8b 95 08 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1f8]
    4206:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4209:	48 89 d1             	mov    rcx,rdx
    420c:	48 8d 15 0d a1 00 00 	lea    rdx,[rip+0xa10d]        # e320 <__func__.3>
    4213:	48 89 c6             	mov    rsi,rax
    4216:	48 89 cf             	mov    rdi,rcx
    4219:	e8 62 e1 ff ff       	call   2380 <expected_EQ_name_TYPE_L_INT@plt>
    421e:	84 c0                	test   al,al
    4220:	0f 84 87 02 00 00    	je     44ad <TEST_permutation_t_float_trans____1+0xcfe>
    4226:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    422d:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    4234:	48 89 d6             	mov    rsi,rdx
    4237:	48 89 c7             	mov    rdi,rax
    423a:	e8 11 e1 ff ff       	call   2350 <open_memstream@plt>
    423f:	48 89 85 58 fe ff ff 	mov    QWORD PTR [rbp-0x1a8],rax
    4246:	48 83 bd 58 fe ff ff 	cmp    QWORD PTR [rbp-0x1a8],0x0
    424d:	00 
    424e:	75 38                	jne    4288 <TEST_permutation_t_float_trans____1+0xad9>
    4250:	48 8b 05 a9 ce 00 00 	mov    rax,QWORD PTR [rip+0xcea9]        # 11100 <stderr@GLIBC_2.2.5>
    4257:	4c 8d 05 c2 a0 00 00 	lea    r8,[rip+0xa0c2]        # e320 <__func__.3>
    425e:	b9 25 00 00 00       	mov    ecx,0x25
    4263:	48 8d 15 da 9d 00 00 	lea    rdx,[rip+0x9dda]        # e044 <_IO_stdin_used+0x44>
    426a:	48 8d 35 df 9d 00 00 	lea    rsi,[rip+0x9ddf]        # e050 <_IO_stdin_used+0x50>
    4271:	48 89 c7             	mov    rdi,rax
    4274:	b8 00 00 00 00       	mov    eax,0x0
    4279:	e8 e2 e1 ff ff       	call   2460 <fprintf@plt>
    427e:	bf 00 00 00 00       	mov    edi,0x0
    4283:	e8 98 e2 ff ff       	call   2520 <exit@plt>
    4288:	8b 05 12 ce 00 00    	mov    eax,DWORD PTR [rip+0xce12]        # 110a0 <k_DEFAULT@@Base>
    428e:	48 98                	cdqe   
    4290:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    4297:	00 
    4298:	48 8d 05 21 ce 00 00 	lea    rax,[rip+0xce21]        # 110c0 <colors_f@@Base>
    429f:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    42a3:	8b 05 d7 cd 00 00    	mov    eax,DWORD PTR [rip+0xcdd7]        # 11080 <hk_TR@@Base>
    42a9:	48 98                	cdqe   
    42ab:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    42b2:	00 
    42b3:	48 8d 05 86 cd 00 00 	lea    rax,[rip+0xcd86]        # 11040 <tab_hk_f@@Base>
    42ba:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    42be:	8b 05 2c ce 00 00    	mov    eax,DWORD PTR [rip+0xce2c]        # 110f0 <k_GREEN@@Base>
    42c4:	48 98                	cdqe   
    42c6:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    42cd:	00 
    42ce:	48 8d 05 eb cd 00 00 	lea    rax,[rip+0xcdeb]        # 110c0 <colors_f@@Base>
    42d5:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    42d9:	48 8b 85 58 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1a8]
    42e0:	4c 8d 0d 39 a0 00 00 	lea    r9,[rip+0xa039]        # e320 <__func__.3>
    42e7:	49 89 f0             	mov    r8,rsi
    42ea:	48 8d 35 97 9d 00 00 	lea    rsi,[rip+0x9d97]        # e088 <_IO_stdin_used+0x88>
    42f1:	48 89 c7             	mov    rdi,rax
    42f4:	b8 00 00 00 00       	mov    eax,0x0
    42f9:	e8 62 e1 ff ff       	call   2460 <fprintf@plt>
    42fe:	48 8b 85 58 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1a8]
    4305:	48 89 c7             	mov    rdi,rax
    4308:	e8 83 e1 ff ff       	call   2490 <fflush@plt>
    430d:	0f b6 05 7c cd 00 00 	movzx  eax,BYTE PTR [rip+0xcd7c]        # 11090 <is_parallel_nb@@Base>
    4314:	84 c0                	test   al,al
    4316:	0f 84 01 01 00 00    	je     441d <TEST_permutation_t_float_trans____1+0xc6e>
    431c:	e8 2f e1 ff ff       	call   2450 <id_of_thread_executed@plt>
    4321:	48 89 85 68 fe ff ff 	mov    QWORD PTR [rbp-0x198],rax
    4328:	0f b6 05 f1 cc 00 00 	movzx  eax,BYTE PTR [rip+0xccf1]        # 11020 <log_parallel@@Base>
    432f:	84 c0                	test   al,al
    4331:	74 76                	je     43a9 <TEST_permutation_t_float_trans____1+0xbfa>
    4333:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    433a:	48 8b 15 e7 cc 00 00 	mov    rdx,QWORD PTR [rip+0xcce7]        # 11028 <stdout@GLIBC_2.2.5>
    4341:	48 89 d6             	mov    rsi,rdx
    4344:	48 89 c7             	mov    rdi,rax
    4347:	e8 94 e0 ff ff       	call   23e0 <fputs@plt>
    434c:	48 83 bd 68 fe ff ff 	cmp    QWORD PTR [rbp-0x198],0x0
    4353:	00 
    4354:	0f 88 30 01 00 00    	js     448a <TEST_permutation_t_float_trans____1+0xcdb>
    435a:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4361:	48 8b 0d c8 cc 00 00 	mov    rcx,QWORD PTR [rip+0xccc8]        # 11030 <f_ou_th@@Base>
    4368:	48 8b 95 68 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x198]
    436f:	48 c1 e2 03          	shl    rdx,0x3
    4373:	48 01 ca             	add    rdx,rcx
    4376:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4379:	48 89 d6             	mov    rsi,rdx
    437c:	48 89 c7             	mov    rdi,rax
    437f:	e8 5c e0 ff ff       	call   23e0 <fputs@plt>
    4384:	48 8b 15 a5 cc 00 00 	mov    rdx,QWORD PTR [rip+0xcca5]        # 11030 <f_ou_th@@Base>
    438b:	48 8b 85 68 fe ff ff 	mov    rax,QWORD PTR [rbp-0x198]
    4392:	48 c1 e0 03          	shl    rax,0x3
    4396:	48 01 d0             	add    rax,rdx
    4399:	48 8b 00             	mov    rax,QWORD PTR [rax]
    439c:	48 89 c7             	mov    rdi,rax
    439f:	e8 ec e0 ff ff       	call   2490 <fflush@plt>
    43a4:	e9 e1 00 00 00       	jmp    448a <TEST_permutation_t_float_trans____1+0xcdb>
    43a9:	48 83 bd 68 fe ff ff 	cmp    QWORD PTR [rbp-0x198],0x0
    43b0:	00 
    43b1:	78 4f                	js     4402 <TEST_permutation_t_float_trans____1+0xc53>
    43b3:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    43ba:	48 8b 0d 6f cc 00 00 	mov    rcx,QWORD PTR [rip+0xcc6f]        # 11030 <f_ou_th@@Base>
    43c1:	48 8b 95 68 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x198]
    43c8:	48 c1 e2 03          	shl    rdx,0x3
    43cc:	48 01 ca             	add    rdx,rcx
    43cf:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    43d2:	48 89 d6             	mov    rsi,rdx
    43d5:	48 89 c7             	mov    rdi,rax
    43d8:	e8 03 e0 ff ff       	call   23e0 <fputs@plt>
    43dd:	48 8b 15 4c cc 00 00 	mov    rdx,QWORD PTR [rip+0xcc4c]        # 11030 <f_ou_th@@Base>
    43e4:	48 8b 85 68 fe ff ff 	mov    rax,QWORD PTR [rbp-0x198]
    43eb:	48 c1 e0 03          	shl    rax,0x3
    43ef:	48 01 d0             	add    rax,rdx
    43f2:	48 8b 00             	mov    rax,QWORD PTR [rax]
    43f5:	48 89 c7             	mov    rdi,rax
    43f8:	e8 93 e0 ff ff       	call   2490 <fflush@plt>
    43fd:	e9 88 00 00 00       	jmp    448a <TEST_permutation_t_float_trans____1+0xcdb>
    4402:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4409:	48 8b 15 18 cc 00 00 	mov    rdx,QWORD PTR [rip+0xcc18]        # 11028 <stdout@GLIBC_2.2.5>
    4410:	48 89 d6             	mov    rsi,rdx
    4413:	48 89 c7             	mov    rdi,rax
    4416:	e8 c5 df ff ff       	call   23e0 <fputs@plt>
    441b:	eb 6d                	jmp    448a <TEST_permutation_t_float_trans____1+0xcdb>
    441d:	48 8b 05 14 cc 00 00 	mov    rax,QWORD PTR [rip+0xcc14]        # 11038 <savelog@@Base>
    4424:	48 85 c0             	test   rax,rax
    4427:	74 48                	je     4471 <TEST_permutation_t_float_trans____1+0xcc2>
    4429:	48 8b 05 08 cc 00 00 	mov    rax,QWORD PTR [rip+0xcc08]        # 11038 <savelog@@Base>
    4430:	48 8d 15 48 9c 00 00 	lea    rdx,[rip+0x9c48]        # e07f <_IO_stdin_used+0x7f>
    4437:	48 89 d6             	mov    rsi,rdx
    443a:	48 89 c7             	mov    rdi,rax
    443d:	e8 be e0 ff ff       	call   2500 <fopen@plt>
    4442:	48 89 85 60 fe ff ff 	mov    QWORD PTR [rbp-0x1a0],rax
    4449:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4450:	48 8b 95 60 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1a0]
    4457:	48 89 d6             	mov    rsi,rdx
    445a:	48 89 c7             	mov    rdi,rax
    445d:	e8 7e df ff ff       	call   23e0 <fputs@plt>
    4462:	48 8b 85 60 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1a0]
    4469:	48 89 c7             	mov    rdi,rax
    446c:	e8 3f df ff ff       	call   23b0 <fclose@plt>
    4471:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4478:	48 8b 15 a9 cb 00 00 	mov    rdx,QWORD PTR [rip+0xcba9]        # 11028 <stdout@GLIBC_2.2.5>
    447f:	48 89 d6             	mov    rsi,rdx
    4482:	48 89 c7             	mov    rdi,rax
    4485:	e8 56 df ff ff       	call   23e0 <fputs@plt>
    448a:	48 8b 85 58 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1a8]
    4491:	48 89 c7             	mov    rdi,rax
    4494:	e8 17 df ff ff       	call   23b0 <fclose@plt>
    4499:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    44a0:	48 89 c7             	mov    rdi,rax
    44a3:	e8 88 de ff ff       	call   2330 <free@plt>
    44a8:	e9 11 05 00 00       	jmp    49be <TEST_permutation_t_float_trans____1+0x120f>
    44ad:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    44b4:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    44bb:	48 89 d6             	mov    rsi,rdx
    44be:	48 89 c7             	mov    rdi,rax
    44c1:	e8 8a de ff ff       	call   2350 <open_memstream@plt>
    44c6:	48 89 85 28 fe ff ff 	mov    QWORD PTR [rbp-0x1d8],rax
    44cd:	48 83 bd 28 fe ff ff 	cmp    QWORD PTR [rbp-0x1d8],0x0
    44d4:	00 
    44d5:	75 38                	jne    450f <TEST_permutation_t_float_trans____1+0xd60>
    44d7:	48 8b 05 22 cc 00 00 	mov    rax,QWORD PTR [rip+0xcc22]        # 11100 <stderr@GLIBC_2.2.5>
    44de:	4c 8d 05 3b 9e 00 00 	lea    r8,[rip+0x9e3b]        # e320 <__func__.3>
    44e5:	b9 25 00 00 00       	mov    ecx,0x25
    44ea:	48 8d 15 53 9b 00 00 	lea    rdx,[rip+0x9b53]        # e044 <_IO_stdin_used+0x44>
    44f1:	48 8d 35 58 9b 00 00 	lea    rsi,[rip+0x9b58]        # e050 <_IO_stdin_used+0x50>
    44f8:	48 89 c7             	mov    rdi,rax
    44fb:	b8 00 00 00 00       	mov    eax,0x0
    4500:	e8 5b df ff ff       	call   2460 <fprintf@plt>
    4505:	bf 00 00 00 00       	mov    edi,0x0
    450a:	e8 11 e0 ff ff       	call   2520 <exit@plt>
    450f:	8b 85 ec fd ff ff    	mov    eax,DWORD PTR [rbp-0x214]
    4515:	48 98                	cdqe   
    4517:	48 89 c7             	mov    rdi,rax
    451a:	e8 11 e0 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    451f:	48 89 c3             	mov    rbx,rax
    4522:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    4529:	48 8b 00             	mov    rax,QWORD PTR [rax]
    452c:	48 89 c7             	mov    rdi,rax
    452f:	e8 fc df ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    4534:	48 89 c2             	mov    rdx,rax
    4537:	48 8b 85 28 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1d8]
    453e:	53                   	push   rbx
    453f:	48 8d 0d 0f 9c 00 00 	lea    rcx,[rip+0x9c0f]        # e155 <_IO_stdin_used+0x155>
    4546:	51                   	push   rcx
    4547:	52                   	push   rdx
    4548:	48 8d 15 59 9b 00 00 	lea    rdx,[rip+0x9b59]        # e0a8 <_IO_stdin_used+0xa8>
    454f:	52                   	push   rdx
    4550:	48 8d 15 fe 9b 00 00 	lea    rdx,[rip+0x9bfe]        # e155 <_IO_stdin_used+0x155>
    4557:	52                   	push   rdx
    4558:	48 8d 15 a5 9b 00 00 	lea    rdx,[rip+0x9ba5]        # e104 <_IO_stdin_used+0x104>
    455f:	52                   	push   rdx
    4560:	4c 8d 0d 41 9b 00 00 	lea    r9,[rip+0x9b41]        # e0a8 <_IO_stdin_used+0xa8>
    4567:	4c 8d 05 b2 9d 00 00 	lea    r8,[rip+0x9db2]        # e320 <__func__.3>
    456e:	b9 25 00 00 00       	mov    ecx,0x25
    4573:	48 8d 15 ca 9a 00 00 	lea    rdx,[rip+0x9aca]        # e044 <_IO_stdin_used+0x44>
    457a:	48 8d 35 2f 9b 00 00 	lea    rsi,[rip+0x9b2f]        # e0b0 <_IO_stdin_used+0xb0>
    4581:	48 89 c7             	mov    rdi,rax
    4584:	b8 00 00 00 00       	mov    eax,0x0
    4589:	e8 d2 de ff ff       	call   2460 <fprintf@plt>
    458e:	48 83 c4 30          	add    rsp,0x30
    4592:	48 8b 85 28 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1d8]
    4599:	48 89 c7             	mov    rdi,rax
    459c:	e8 ef de ff ff       	call   2490 <fflush@plt>
    45a1:	0f b6 05 e8 ca 00 00 	movzx  eax,BYTE PTR [rip+0xcae8]        # 11090 <is_parallel_nb@@Base>
    45a8:	84 c0                	test   al,al
    45aa:	0f 84 01 01 00 00    	je     46b1 <TEST_permutation_t_float_trans____1+0xf02>
    45b0:	e8 9b de ff ff       	call   2450 <id_of_thread_executed@plt>
    45b5:	48 89 85 38 fe ff ff 	mov    QWORD PTR [rbp-0x1c8],rax
    45bc:	0f b6 05 5d ca 00 00 	movzx  eax,BYTE PTR [rip+0xca5d]        # 11020 <log_parallel@@Base>
    45c3:	84 c0                	test   al,al
    45c5:	74 76                	je     463d <TEST_permutation_t_float_trans____1+0xe8e>
    45c7:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    45ce:	48 8b 15 53 ca 00 00 	mov    rdx,QWORD PTR [rip+0xca53]        # 11028 <stdout@GLIBC_2.2.5>
    45d5:	48 89 d6             	mov    rsi,rdx
    45d8:	48 89 c7             	mov    rdi,rax
    45db:	e8 00 de ff ff       	call   23e0 <fputs@plt>
    45e0:	48 83 bd 38 fe ff ff 	cmp    QWORD PTR [rbp-0x1c8],0x0
    45e7:	00 
    45e8:	0f 88 30 01 00 00    	js     471e <TEST_permutation_t_float_trans____1+0xf6f>
    45ee:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    45f5:	48 8b 0d 34 ca 00 00 	mov    rcx,QWORD PTR [rip+0xca34]        # 11030 <f_ou_th@@Base>
    45fc:	48 8b 95 38 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1c8]
    4603:	48 c1 e2 03          	shl    rdx,0x3
    4607:	48 01 ca             	add    rdx,rcx
    460a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    460d:	48 89 d6             	mov    rsi,rdx
    4610:	48 89 c7             	mov    rdi,rax
    4613:	e8 c8 dd ff ff       	call   23e0 <fputs@plt>
    4618:	48 8b 15 11 ca 00 00 	mov    rdx,QWORD PTR [rip+0xca11]        # 11030 <f_ou_th@@Base>
    461f:	48 8b 85 38 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1c8]
    4626:	48 c1 e0 03          	shl    rax,0x3
    462a:	48 01 d0             	add    rax,rdx
    462d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4630:	48 89 c7             	mov    rdi,rax
    4633:	e8 58 de ff ff       	call   2490 <fflush@plt>
    4638:	e9 e1 00 00 00       	jmp    471e <TEST_permutation_t_float_trans____1+0xf6f>
    463d:	48 83 bd 38 fe ff ff 	cmp    QWORD PTR [rbp-0x1c8],0x0
    4644:	00 
    4645:	78 4f                	js     4696 <TEST_permutation_t_float_trans____1+0xee7>
    4647:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    464e:	48 8b 0d db c9 00 00 	mov    rcx,QWORD PTR [rip+0xc9db]        # 11030 <f_ou_th@@Base>
    4655:	48 8b 95 38 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1c8]
    465c:	48 c1 e2 03          	shl    rdx,0x3
    4660:	48 01 ca             	add    rdx,rcx
    4663:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4666:	48 89 d6             	mov    rsi,rdx
    4669:	48 89 c7             	mov    rdi,rax
    466c:	e8 6f dd ff ff       	call   23e0 <fputs@plt>
    4671:	48 8b 15 b8 c9 00 00 	mov    rdx,QWORD PTR [rip+0xc9b8]        # 11030 <f_ou_th@@Base>
    4678:	48 8b 85 38 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1c8]
    467f:	48 c1 e0 03          	shl    rax,0x3
    4683:	48 01 d0             	add    rax,rdx
    4686:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4689:	48 89 c7             	mov    rdi,rax
    468c:	e8 ff dd ff ff       	call   2490 <fflush@plt>
    4691:	e9 88 00 00 00       	jmp    471e <TEST_permutation_t_float_trans____1+0xf6f>
    4696:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    469d:	48 8b 15 84 c9 00 00 	mov    rdx,QWORD PTR [rip+0xc984]        # 11028 <stdout@GLIBC_2.2.5>
    46a4:	48 89 d6             	mov    rsi,rdx
    46a7:	48 89 c7             	mov    rdi,rax
    46aa:	e8 31 dd ff ff       	call   23e0 <fputs@plt>
    46af:	eb 6d                	jmp    471e <TEST_permutation_t_float_trans____1+0xf6f>
    46b1:	48 8b 05 80 c9 00 00 	mov    rax,QWORD PTR [rip+0xc980]        # 11038 <savelog@@Base>
    46b8:	48 85 c0             	test   rax,rax
    46bb:	74 48                	je     4705 <TEST_permutation_t_float_trans____1+0xf56>
    46bd:	48 8b 05 74 c9 00 00 	mov    rax,QWORD PTR [rip+0xc974]        # 11038 <savelog@@Base>
    46c4:	48 8d 15 b4 99 00 00 	lea    rdx,[rip+0x99b4]        # e07f <_IO_stdin_used+0x7f>
    46cb:	48 89 d6             	mov    rsi,rdx
    46ce:	48 89 c7             	mov    rdi,rax
    46d1:	e8 2a de ff ff       	call   2500 <fopen@plt>
    46d6:	48 89 85 30 fe ff ff 	mov    QWORD PTR [rbp-0x1d0],rax
    46dd:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    46e4:	48 8b 95 30 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1d0]
    46eb:	48 89 d6             	mov    rsi,rdx
    46ee:	48 89 c7             	mov    rdi,rax
    46f1:	e8 ea dc ff ff       	call   23e0 <fputs@plt>
    46f6:	48 8b 85 30 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1d0]
    46fd:	48 89 c7             	mov    rdi,rax
    4700:	e8 ab dc ff ff       	call   23b0 <fclose@plt>
    4705:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    470c:	48 8b 15 15 c9 00 00 	mov    rdx,QWORD PTR [rip+0xc915]        # 11028 <stdout@GLIBC_2.2.5>
    4713:	48 89 d6             	mov    rsi,rdx
    4716:	48 89 c7             	mov    rdi,rax
    4719:	e8 c2 dc ff ff       	call   23e0 <fputs@plt>
    471e:	48 8b 85 28 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1d8]
    4725:	48 89 c7             	mov    rdi,rax
    4728:	e8 83 dc ff ff       	call   23b0 <fclose@plt>
    472d:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4734:	48 89 c7             	mov    rdi,rax
    4737:	e8 f4 db ff ff       	call   2330 <free@plt>
    473c:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    4743:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    474a:	48 89 d6             	mov    rsi,rdx
    474d:	48 89 c7             	mov    rdi,rax
    4750:	e8 fb db ff ff       	call   2350 <open_memstream@plt>
    4755:	48 89 85 40 fe ff ff 	mov    QWORD PTR [rbp-0x1c0],rax
    475c:	48 83 bd 40 fe ff ff 	cmp    QWORD PTR [rbp-0x1c0],0x0
    4763:	00 
    4764:	75 38                	jne    479e <TEST_permutation_t_float_trans____1+0xfef>
    4766:	48 8b 05 93 c9 00 00 	mov    rax,QWORD PTR [rip+0xc993]        # 11100 <stderr@GLIBC_2.2.5>
    476d:	4c 8d 05 ac 9b 00 00 	lea    r8,[rip+0x9bac]        # e320 <__func__.3>
    4774:	b9 25 00 00 00       	mov    ecx,0x25
    4779:	48 8d 15 c4 98 00 00 	lea    rdx,[rip+0x98c4]        # e044 <_IO_stdin_used+0x44>
    4780:	48 8d 35 c9 98 00 00 	lea    rsi,[rip+0x98c9]        # e050 <_IO_stdin_used+0x50>
    4787:	48 89 c7             	mov    rdi,rax
    478a:	b8 00 00 00 00       	mov    eax,0x0
    478f:	e8 cc dc ff ff       	call   2460 <fprintf@plt>
    4794:	bf 00 00 00 00       	mov    edi,0x0
    4799:	e8 82 dd ff ff       	call   2520 <exit@plt>
    479e:	8b 05 fc c8 00 00    	mov    eax,DWORD PTR [rip+0xc8fc]        # 110a0 <k_DEFAULT@@Base>
    47a4:	48 98                	cdqe   
    47a6:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    47ad:	00 
    47ae:	48 8d 05 0b c9 00 00 	lea    rax,[rip+0xc90b]        # 110c0 <colors_f@@Base>
    47b5:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    47b9:	8b 05 c1 c8 00 00    	mov    eax,DWORD PTR [rip+0xc8c1]        # 11080 <hk_TR@@Base>
    47bf:	48 98                	cdqe   
    47c1:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    47c8:	00 
    47c9:	48 8d 05 70 c8 00 00 	lea    rax,[rip+0xc870]        # 11040 <tab_hk_f@@Base>
    47d0:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    47d4:	8b 05 aa c8 00 00    	mov    eax,DWORD PTR [rip+0xc8aa]        # 11084 <k_RED@@Base>
    47da:	48 98                	cdqe   
    47dc:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    47e3:	00 
    47e4:	48 8d 05 d5 c8 00 00 	lea    rax,[rip+0xc8d5]        # 110c0 <colors_f@@Base>
    47eb:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    47ef:	48 8b 85 40 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1c0]
    47f6:	4c 8d 0d 23 9b 00 00 	lea    r9,[rip+0x9b23]        # e320 <__func__.3>
    47fd:	49 89 f0             	mov    r8,rsi
    4800:	48 8d 35 01 99 00 00 	lea    rsi,[rip+0x9901]        # e108 <_IO_stdin_used+0x108>
    4807:	48 89 c7             	mov    rdi,rax
    480a:	b8 00 00 00 00       	mov    eax,0x0
    480f:	e8 4c dc ff ff       	call   2460 <fprintf@plt>
    4814:	48 8b 85 40 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1c0]
    481b:	48 89 c7             	mov    rdi,rax
    481e:	e8 6d dc ff ff       	call   2490 <fflush@plt>
    4823:	0f b6 05 66 c8 00 00 	movzx  eax,BYTE PTR [rip+0xc866]        # 11090 <is_parallel_nb@@Base>
    482a:	84 c0                	test   al,al
    482c:	0f 84 01 01 00 00    	je     4933 <TEST_permutation_t_float_trans____1+0x1184>
    4832:	e8 19 dc ff ff       	call   2450 <id_of_thread_executed@plt>
    4837:	48 89 85 50 fe ff ff 	mov    QWORD PTR [rbp-0x1b0],rax
    483e:	0f b6 05 db c7 00 00 	movzx  eax,BYTE PTR [rip+0xc7db]        # 11020 <log_parallel@@Base>
    4845:	84 c0                	test   al,al
    4847:	74 76                	je     48bf <TEST_permutation_t_float_trans____1+0x1110>
    4849:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4850:	48 8b 15 d1 c7 00 00 	mov    rdx,QWORD PTR [rip+0xc7d1]        # 11028 <stdout@GLIBC_2.2.5>
    4857:	48 89 d6             	mov    rsi,rdx
    485a:	48 89 c7             	mov    rdi,rax
    485d:	e8 7e db ff ff       	call   23e0 <fputs@plt>
    4862:	48 83 bd 50 fe ff ff 	cmp    QWORD PTR [rbp-0x1b0],0x0
    4869:	00 
    486a:	0f 88 30 01 00 00    	js     49a0 <TEST_permutation_t_float_trans____1+0x11f1>
    4870:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4877:	48 8b 0d b2 c7 00 00 	mov    rcx,QWORD PTR [rip+0xc7b2]        # 11030 <f_ou_th@@Base>
    487e:	48 8b 95 50 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1b0]
    4885:	48 c1 e2 03          	shl    rdx,0x3
    4889:	48 01 ca             	add    rdx,rcx
    488c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    488f:	48 89 d6             	mov    rsi,rdx
    4892:	48 89 c7             	mov    rdi,rax
    4895:	e8 46 db ff ff       	call   23e0 <fputs@plt>
    489a:	48 8b 15 8f c7 00 00 	mov    rdx,QWORD PTR [rip+0xc78f]        # 11030 <f_ou_th@@Base>
    48a1:	48 8b 85 50 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1b0]
    48a8:	48 c1 e0 03          	shl    rax,0x3
    48ac:	48 01 d0             	add    rax,rdx
    48af:	48 8b 00             	mov    rax,QWORD PTR [rax]
    48b2:	48 89 c7             	mov    rdi,rax
    48b5:	e8 d6 db ff ff       	call   2490 <fflush@plt>
    48ba:	e9 e1 00 00 00       	jmp    49a0 <TEST_permutation_t_float_trans____1+0x11f1>
    48bf:	48 83 bd 50 fe ff ff 	cmp    QWORD PTR [rbp-0x1b0],0x0
    48c6:	00 
    48c7:	78 4f                	js     4918 <TEST_permutation_t_float_trans____1+0x1169>
    48c9:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    48d0:	48 8b 0d 59 c7 00 00 	mov    rcx,QWORD PTR [rip+0xc759]        # 11030 <f_ou_th@@Base>
    48d7:	48 8b 95 50 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1b0]
    48de:	48 c1 e2 03          	shl    rdx,0x3
    48e2:	48 01 ca             	add    rdx,rcx
    48e5:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    48e8:	48 89 d6             	mov    rsi,rdx
    48eb:	48 89 c7             	mov    rdi,rax
    48ee:	e8 ed da ff ff       	call   23e0 <fputs@plt>
    48f3:	48 8b 15 36 c7 00 00 	mov    rdx,QWORD PTR [rip+0xc736]        # 11030 <f_ou_th@@Base>
    48fa:	48 8b 85 50 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1b0]
    4901:	48 c1 e0 03          	shl    rax,0x3
    4905:	48 01 d0             	add    rax,rdx
    4908:	48 8b 00             	mov    rax,QWORD PTR [rax]
    490b:	48 89 c7             	mov    rdi,rax
    490e:	e8 7d db ff ff       	call   2490 <fflush@plt>
    4913:	e9 88 00 00 00       	jmp    49a0 <TEST_permutation_t_float_trans____1+0x11f1>
    4918:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    491f:	48 8b 15 02 c7 00 00 	mov    rdx,QWORD PTR [rip+0xc702]        # 11028 <stdout@GLIBC_2.2.5>
    4926:	48 89 d6             	mov    rsi,rdx
    4929:	48 89 c7             	mov    rdi,rax
    492c:	e8 af da ff ff       	call   23e0 <fputs@plt>
    4931:	eb 6d                	jmp    49a0 <TEST_permutation_t_float_trans____1+0x11f1>
    4933:	48 8b 05 fe c6 00 00 	mov    rax,QWORD PTR [rip+0xc6fe]        # 11038 <savelog@@Base>
    493a:	48 85 c0             	test   rax,rax
    493d:	74 48                	je     4987 <TEST_permutation_t_float_trans____1+0x11d8>
    493f:	48 8b 05 f2 c6 00 00 	mov    rax,QWORD PTR [rip+0xc6f2]        # 11038 <savelog@@Base>
    4946:	48 8d 15 32 97 00 00 	lea    rdx,[rip+0x9732]        # e07f <_IO_stdin_used+0x7f>
    494d:	48 89 d6             	mov    rsi,rdx
    4950:	48 89 c7             	mov    rdi,rax
    4953:	e8 a8 db ff ff       	call   2500 <fopen@plt>
    4958:	48 89 85 48 fe ff ff 	mov    QWORD PTR [rbp-0x1b8],rax
    495f:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4966:	48 8b 95 48 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x1b8]
    496d:	48 89 d6             	mov    rsi,rdx
    4970:	48 89 c7             	mov    rdi,rax
    4973:	e8 68 da ff ff       	call   23e0 <fputs@plt>
    4978:	48 8b 85 48 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1b8]
    497f:	48 89 c7             	mov    rdi,rax
    4982:	e8 29 da ff ff       	call   23b0 <fclose@plt>
    4987:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    498e:	48 8b 15 93 c6 00 00 	mov    rdx,QWORD PTR [rip+0xc693]        # 11028 <stdout@GLIBC_2.2.5>
    4995:	48 89 d6             	mov    rsi,rdx
    4998:	48 89 c7             	mov    rdi,rax
    499b:	e8 40 da ff ff       	call   23e0 <fputs@plt>
    49a0:	48 8b 85 40 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1c0]
    49a7:	48 89 c7             	mov    rdi,rax
    49aa:	e8 01 da ff ff       	call   23b0 <fclose@plt>
    49af:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    49b6:	48 89 c7             	mov    rdi,rax
    49b9:	e8 72 d9 ff ff       	call   2330 <free@plt>
    49be:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    49c5:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    49c9:	f3 0f 10 05 cb 99 00 	movss  xmm0,DWORD PTR [rip+0x99cb]        # e39c <__func__.0+0xc>
    49d0:	00 
    49d1:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    49d5:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    49dc:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    49e0:	48 83 c0 04          	add    rax,0x4
    49e4:	f3 0f 10 05 b4 99 00 	movss  xmm0,DWORD PTR [rip+0x99b4]        # e3a0 <__func__.0+0x10>
    49eb:	00 
    49ec:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    49f0:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    49f7:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    49fb:	48 83 c0 08          	add    rax,0x8
    49ff:	f3 0f 10 05 9d 99 00 	movss  xmm0,DWORD PTR [rip+0x999d]        # e3a4 <__func__.0+0x14>
    4a06:	00 
    4a07:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    4a0b:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    4a12:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    4a16:	48 83 c0 0c          	add    rax,0xc
    4a1a:	f3 0f 10 05 86 99 00 	movss  xmm0,DWORD PTR [rip+0x9986]        # e3a8 <__func__.0+0x18>
    4a21:	00 
    4a22:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    4a26:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    4a2d:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    4a31:	48 83 c0 10          	add    rax,0x10
    4a35:	f3 0f 10 05 6f 99 00 	movss  xmm0,DWORD PTR [rip+0x996f]        # e3ac <__func__.0+0x1c>
    4a3c:	00 
    4a3d:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    4a41:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    4a48:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    4a4c:	48 83 c0 14          	add    rax,0x14
    4a50:	f3 0f 10 05 54 99 00 	movss  xmm0,DWORD PTR [rip+0x9954]        # e3ac <__func__.0+0x1c>
    4a57:	00 
    4a58:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    4a5c:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    4a63:	48 89 c7             	mov    rdi,rax
    4a66:	e8 fe 78 00 00       	call   c369 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT>
    4a6b:	48 89 85 b8 fe ff ff 	mov    QWORD PTR [rbp-0x148],rax
    4a72:	48 c7 45 b0 00 00 00 	mov    QWORD PTR [rbp-0x50],0x0
    4a79:	00 
    4a7a:	48 c7 45 b8 02 00 00 	mov    QWORD PTR [rbp-0x48],0x2
    4a81:	00 
    4a82:	48 c7 45 c0 01 00 00 	mov    QWORD PTR [rbp-0x40],0x1
    4a89:	00 
    4a8a:	48 c7 45 c8 03 00 00 	mov    QWORD PTR [rbp-0x38],0x3
    4a91:	00 
    4a92:	48 c7 45 d0 04 00 00 	mov    QWORD PTR [rbp-0x30],0x4
    4a99:	00 
    4a9a:	48 c7 45 d8 04 00 00 	mov    QWORD PTR [rbp-0x28],0x4
    4aa1:	00 
    4aa2:	48 c7 85 00 fe ff ff 	mov    QWORD PTR [rbp-0x200],0x0
    4aa9:	00 00 00 00 
    4aad:	e9 a1 0f 00 00       	jmp    5a53 <TEST_permutation_t_float_trans____1+0x22a4>
    4ab2:	0f b6 05 d7 c5 00 00 	movzx  eax,BYTE PTR [rip+0xc5d7]        # 11090 <is_parallel_nb@@Base>
    4ab9:	83 f0 01             	xor    eax,0x1
    4abc:	84 c0                	test   al,al
    4abe:	0f 84 91 07 00 00    	je     5255 <TEST_permutation_t_float_trans____1+0x1aa6>
    4ac4:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    4acb:	48 8b 44 c5 b0       	mov    rax,QWORD PTR [rbp+rax*8-0x50]
    4ad0:	48 89 c2             	mov    rdx,rax
    4ad3:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    4ada:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    4ade:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    4ae5:	48 c1 e0 03          	shl    rax,0x3
    4ae9:	48 01 c8             	add    rax,rcx
    4aec:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4aef:	48 89 d6             	mov    rsi,rdx
    4af2:	48 89 c7             	mov    rdi,rax
    4af5:	e8 06 d9 ff ff       	call   2400 <expected_EQ_TYPE_L_INT@plt>
    4afa:	84 c0                	test   al,al
    4afc:	0f 84 57 02 00 00    	je     4d59 <TEST_permutation_t_float_trans____1+0x15aa>
    4b02:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    4b09:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    4b10:	48 89 d6             	mov    rsi,rdx
    4b13:	48 89 c7             	mov    rdi,rax
    4b16:	e8 35 d8 ff ff       	call   2350 <open_memstream@plt>
    4b1b:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
    4b1f:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    4b24:	75 38                	jne    4b5e <TEST_permutation_t_float_trans____1+0x13af>
    4b26:	48 8b 05 d3 c5 00 00 	mov    rax,QWORD PTR [rip+0xc5d3]        # 11100 <stderr@GLIBC_2.2.5>
    4b2d:	4c 8d 05 ec 97 00 00 	lea    r8,[rip+0x97ec]        # e320 <__func__.3>
    4b34:	b9 34 00 00 00       	mov    ecx,0x34
    4b39:	48 8d 15 04 95 00 00 	lea    rdx,[rip+0x9504]        # e044 <_IO_stdin_used+0x44>
    4b40:	48 8d 35 09 95 00 00 	lea    rsi,[rip+0x9509]        # e050 <_IO_stdin_used+0x50>
    4b47:	48 89 c7             	mov    rdi,rax
    4b4a:	b8 00 00 00 00       	mov    eax,0x0
    4b4f:	e8 0c d9 ff ff       	call   2460 <fprintf@plt>
    4b54:	bf 00 00 00 00       	mov    edi,0x0
    4b59:	e8 c2 d9 ff ff       	call   2520 <exit@plt>
    4b5e:	8b 05 3c c5 00 00    	mov    eax,DWORD PTR [rip+0xc53c]        # 110a0 <k_DEFAULT@@Base>
    4b64:	48 98                	cdqe   
    4b66:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    4b6d:	00 
    4b6e:	48 8d 05 4b c5 00 00 	lea    rax,[rip+0xc54b]        # 110c0 <colors_f@@Base>
    4b75:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    4b79:	8b 05 01 c5 00 00    	mov    eax,DWORD PTR [rip+0xc501]        # 11080 <hk_TR@@Base>
    4b7f:	48 98                	cdqe   
    4b81:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    4b88:	00 
    4b89:	48 8d 05 b0 c4 00 00 	lea    rax,[rip+0xc4b0]        # 11040 <tab_hk_f@@Base>
    4b90:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    4b94:	8b 05 56 c5 00 00    	mov    eax,DWORD PTR [rip+0xc556]        # 110f0 <k_GREEN@@Base>
    4b9a:	48 98                	cdqe   
    4b9c:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    4ba3:	00 
    4ba4:	48 8d 05 15 c5 00 00 	lea    rax,[rip+0xc515]        # 110c0 <colors_f@@Base>
    4bab:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    4baf:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    4bb3:	4c 8d 0d 66 97 00 00 	lea    r9,[rip+0x9766]        # e320 <__func__.3>
    4bba:	49 89 f0             	mov    r8,rsi
    4bbd:	48 8d 35 c4 94 00 00 	lea    rsi,[rip+0x94c4]        # e088 <_IO_stdin_used+0x88>
    4bc4:	48 89 c7             	mov    rdi,rax
    4bc7:	b8 00 00 00 00       	mov    eax,0x0
    4bcc:	e8 8f d8 ff ff       	call   2460 <fprintf@plt>
    4bd1:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    4bd5:	48 89 c7             	mov    rdi,rax
    4bd8:	e8 b3 d8 ff ff       	call   2490 <fflush@plt>
    4bdd:	0f b6 05 ac c4 00 00 	movzx  eax,BYTE PTR [rip+0xc4ac]        # 11090 <is_parallel_nb@@Base>
    4be4:	84 c0                	test   al,al
    4be6:	0f 84 e9 00 00 00    	je     4cd5 <TEST_permutation_t_float_trans____1+0x1526>
    4bec:	e8 5f d8 ff ff       	call   2450 <id_of_thread_executed@plt>
    4bf1:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    4bf5:	0f b6 05 24 c4 00 00 	movzx  eax,BYTE PTR [rip+0xc424]        # 11020 <log_parallel@@Base>
    4bfc:	84 c0                	test   al,al
    4bfe:	74 6d                	je     4c6d <TEST_permutation_t_float_trans____1+0x14be>
    4c00:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4c07:	48 8b 15 1a c4 00 00 	mov    rdx,QWORD PTR [rip+0xc41a]        # 11028 <stdout@GLIBC_2.2.5>
    4c0e:	48 89 d6             	mov    rsi,rdx
    4c11:	48 89 c7             	mov    rdi,rax
    4c14:	e8 c7 d7 ff ff       	call   23e0 <fputs@plt>
    4c19:	48 83 7d a8 00       	cmp    QWORD PTR [rbp-0x58],0x0
    4c1e:	0f 88 15 01 00 00    	js     4d39 <TEST_permutation_t_float_trans____1+0x158a>
    4c24:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4c2b:	48 8b 0d fe c3 00 00 	mov    rcx,QWORD PTR [rip+0xc3fe]        # 11030 <f_ou_th@@Base>
    4c32:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
    4c36:	48 c1 e2 03          	shl    rdx,0x3
    4c3a:	48 01 ca             	add    rdx,rcx
    4c3d:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4c40:	48 89 d6             	mov    rsi,rdx
    4c43:	48 89 c7             	mov    rdi,rax
    4c46:	e8 95 d7 ff ff       	call   23e0 <fputs@plt>
    4c4b:	48 8b 15 de c3 00 00 	mov    rdx,QWORD PTR [rip+0xc3de]        # 11030 <f_ou_th@@Base>
    4c52:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    4c56:	48 c1 e0 03          	shl    rax,0x3
    4c5a:	48 01 d0             	add    rax,rdx
    4c5d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4c60:	48 89 c7             	mov    rdi,rax
    4c63:	e8 28 d8 ff ff       	call   2490 <fflush@plt>
    4c68:	e9 cc 00 00 00       	jmp    4d39 <TEST_permutation_t_float_trans____1+0x158a>
    4c6d:	48 83 7d a8 00       	cmp    QWORD PTR [rbp-0x58],0x0
    4c72:	78 46                	js     4cba <TEST_permutation_t_float_trans____1+0x150b>
    4c74:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4c7b:	48 8b 0d ae c3 00 00 	mov    rcx,QWORD PTR [rip+0xc3ae]        # 11030 <f_ou_th@@Base>
    4c82:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
    4c86:	48 c1 e2 03          	shl    rdx,0x3
    4c8a:	48 01 ca             	add    rdx,rcx
    4c8d:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4c90:	48 89 d6             	mov    rsi,rdx
    4c93:	48 89 c7             	mov    rdi,rax
    4c96:	e8 45 d7 ff ff       	call   23e0 <fputs@plt>
    4c9b:	48 8b 15 8e c3 00 00 	mov    rdx,QWORD PTR [rip+0xc38e]        # 11030 <f_ou_th@@Base>
    4ca2:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    4ca6:	48 c1 e0 03          	shl    rax,0x3
    4caa:	48 01 d0             	add    rax,rdx
    4cad:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4cb0:	48 89 c7             	mov    rdi,rax
    4cb3:	e8 d8 d7 ff ff       	call   2490 <fflush@plt>
    4cb8:	eb 7f                	jmp    4d39 <TEST_permutation_t_float_trans____1+0x158a>
    4cba:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4cc1:	48 8b 15 60 c3 00 00 	mov    rdx,QWORD PTR [rip+0xc360]        # 11028 <stdout@GLIBC_2.2.5>
    4cc8:	48 89 d6             	mov    rsi,rdx
    4ccb:	48 89 c7             	mov    rdi,rax
    4cce:	e8 0d d7 ff ff       	call   23e0 <fputs@plt>
    4cd3:	eb 64                	jmp    4d39 <TEST_permutation_t_float_trans____1+0x158a>
    4cd5:	48 8b 05 5c c3 00 00 	mov    rax,QWORD PTR [rip+0xc35c]        # 11038 <savelog@@Base>
    4cdc:	48 85 c0             	test   rax,rax
    4cdf:	74 3f                	je     4d20 <TEST_permutation_t_float_trans____1+0x1571>
    4ce1:	48 8b 05 50 c3 00 00 	mov    rax,QWORD PTR [rip+0xc350]        # 11038 <savelog@@Base>
    4ce8:	48 8d 15 90 93 00 00 	lea    rdx,[rip+0x9390]        # e07f <_IO_stdin_used+0x7f>
    4cef:	48 89 d6             	mov    rsi,rdx
    4cf2:	48 89 c7             	mov    rdi,rax
    4cf5:	e8 06 d8 ff ff       	call   2500 <fopen@plt>
    4cfa:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
    4cfe:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4d05:	48 8b 55 a0          	mov    rdx,QWORD PTR [rbp-0x60]
    4d09:	48 89 d6             	mov    rsi,rdx
    4d0c:	48 89 c7             	mov    rdi,rax
    4d0f:	e8 cc d6 ff ff       	call   23e0 <fputs@plt>
    4d14:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    4d18:	48 89 c7             	mov    rdi,rax
    4d1b:	e8 90 d6 ff ff       	call   23b0 <fclose@plt>
    4d20:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4d27:	48 8b 15 fa c2 00 00 	mov    rdx,QWORD PTR [rip+0xc2fa]        # 11028 <stdout@GLIBC_2.2.5>
    4d2e:	48 89 d6             	mov    rsi,rdx
    4d31:	48 89 c7             	mov    rdi,rax
    4d34:	e8 a7 d6 ff ff       	call   23e0 <fputs@plt>
    4d39:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    4d3d:	48 89 c7             	mov    rdi,rax
    4d40:	e8 6b d6 ff ff       	call   23b0 <fclose@plt>
    4d45:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4d4c:	48 89 c7             	mov    rdi,rax
    4d4f:	e8 dc d5 ff ff       	call   2330 <free@plt>
    4d54:	e9 f2 0c 00 00       	jmp    5a4b <TEST_permutation_t_float_trans____1+0x229c>
    4d59:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    4d60:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    4d67:	48 89 d6             	mov    rsi,rdx
    4d6a:	48 89 c7             	mov    rdi,rax
    4d6d:	e8 de d5 ff ff       	call   2350 <open_memstream@plt>
    4d72:	48 89 85 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rax
    4d79:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    4d80:	00 
    4d81:	75 38                	jne    4dbb <TEST_permutation_t_float_trans____1+0x160c>
    4d83:	48 8b 05 76 c3 00 00 	mov    rax,QWORD PTR [rip+0xc376]        # 11100 <stderr@GLIBC_2.2.5>
    4d8a:	4c 8d 05 8f 95 00 00 	lea    r8,[rip+0x958f]        # e320 <__func__.3>
    4d91:	b9 34 00 00 00       	mov    ecx,0x34
    4d96:	48 8d 15 a7 92 00 00 	lea    rdx,[rip+0x92a7]        # e044 <_IO_stdin_used+0x44>
    4d9d:	48 8d 35 ac 92 00 00 	lea    rsi,[rip+0x92ac]        # e050 <_IO_stdin_used+0x50>
    4da4:	48 89 c7             	mov    rdi,rax
    4da7:	b8 00 00 00 00       	mov    eax,0x0
    4dac:	e8 af d6 ff ff       	call   2460 <fprintf@plt>
    4db1:	bf 00 00 00 00       	mov    edi,0x0
    4db6:	e8 65 d7 ff ff       	call   2520 <exit@plt>
    4dbb:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    4dc2:	48 8b 44 c5 b0       	mov    rax,QWORD PTR [rbp+rax*8-0x50]
    4dc7:	48 89 c7             	mov    rdi,rax
    4dca:	e8 61 d7 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    4dcf:	48 89 c3             	mov    rbx,rax
    4dd2:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    4dd9:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    4ddd:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    4de4:	48 c1 e0 03          	shl    rax,0x3
    4de8:	48 01 d0             	add    rax,rdx
    4deb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4dee:	48 89 c7             	mov    rdi,rax
    4df1:	e8 3a d7 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    4df6:	48 89 c2             	mov    rdx,rax
    4df9:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    4e00:	53                   	push   rbx
    4e01:	48 8d 0d 64 93 00 00 	lea    rcx,[rip+0x9364]        # e16c <_IO_stdin_used+0x16c>
    4e08:	51                   	push   rcx
    4e09:	52                   	push   rdx
    4e0a:	48 8d 15 46 93 00 00 	lea    rdx,[rip+0x9346]        # e157 <_IO_stdin_used+0x157>
    4e11:	52                   	push   rdx
    4e12:	48 8d 15 53 93 00 00 	lea    rdx,[rip+0x9353]        # e16c <_IO_stdin_used+0x16c>
    4e19:	52                   	push   rdx
    4e1a:	48 8d 15 e3 92 00 00 	lea    rdx,[rip+0x92e3]        # e104 <_IO_stdin_used+0x104>
    4e21:	52                   	push   rdx
    4e22:	4c 8d 0d 2e 93 00 00 	lea    r9,[rip+0x932e]        # e157 <_IO_stdin_used+0x157>
    4e29:	4c 8d 05 f0 94 00 00 	lea    r8,[rip+0x94f0]        # e320 <__func__.3>
    4e30:	b9 34 00 00 00       	mov    ecx,0x34
    4e35:	48 8d 15 08 92 00 00 	lea    rdx,[rip+0x9208]        # e044 <_IO_stdin_used+0x44>
    4e3c:	48 8d 35 6d 92 00 00 	lea    rsi,[rip+0x926d]        # e0b0 <_IO_stdin_used+0xb0>
    4e43:	48 89 c7             	mov    rdi,rax
    4e46:	b8 00 00 00 00       	mov    eax,0x0
    4e4b:	e8 10 d6 ff ff       	call   2460 <fprintf@plt>
    4e50:	48 83 c4 30          	add    rsp,0x30
    4e54:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    4e5b:	48 89 c7             	mov    rdi,rax
    4e5e:	e8 2d d6 ff ff       	call   2490 <fflush@plt>
    4e63:	0f b6 05 26 c2 00 00 	movzx  eax,BYTE PTR [rip+0xc226]        # 11090 <is_parallel_nb@@Base>
    4e6a:	84 c0                	test   al,al
    4e6c:	0f 84 01 01 00 00    	je     4f73 <TEST_permutation_t_float_trans____1+0x17c4>
    4e72:	e8 d9 d5 ff ff       	call   2450 <id_of_thread_executed@plt>
    4e77:	48 89 85 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rax
    4e7e:	0f b6 05 9b c1 00 00 	movzx  eax,BYTE PTR [rip+0xc19b]        # 11020 <log_parallel@@Base>
    4e85:	84 c0                	test   al,al
    4e87:	74 76                	je     4eff <TEST_permutation_t_float_trans____1+0x1750>
    4e89:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4e90:	48 8b 15 91 c1 00 00 	mov    rdx,QWORD PTR [rip+0xc191]        # 11028 <stdout@GLIBC_2.2.5>
    4e97:	48 89 d6             	mov    rsi,rdx
    4e9a:	48 89 c7             	mov    rdi,rax
    4e9d:	e8 3e d5 ff ff       	call   23e0 <fputs@plt>
    4ea2:	48 83 bd 78 ff ff ff 	cmp    QWORD PTR [rbp-0x88],0x0
    4ea9:	00 
    4eaa:	0f 88 30 01 00 00    	js     4fe0 <TEST_permutation_t_float_trans____1+0x1831>
    4eb0:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4eb7:	48 8b 0d 72 c1 00 00 	mov    rcx,QWORD PTR [rip+0xc172]        # 11030 <f_ou_th@@Base>
    4ebe:	48 8b 95 78 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x88]
    4ec5:	48 c1 e2 03          	shl    rdx,0x3
    4ec9:	48 01 ca             	add    rdx,rcx
    4ecc:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4ecf:	48 89 d6             	mov    rsi,rdx
    4ed2:	48 89 c7             	mov    rdi,rax
    4ed5:	e8 06 d5 ff ff       	call   23e0 <fputs@plt>
    4eda:	48 8b 15 4f c1 00 00 	mov    rdx,QWORD PTR [rip+0xc14f]        # 11030 <f_ou_th@@Base>
    4ee1:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    4ee8:	48 c1 e0 03          	shl    rax,0x3
    4eec:	48 01 d0             	add    rax,rdx
    4eef:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4ef2:	48 89 c7             	mov    rdi,rax
    4ef5:	e8 96 d5 ff ff       	call   2490 <fflush@plt>
    4efa:	e9 e1 00 00 00       	jmp    4fe0 <TEST_permutation_t_float_trans____1+0x1831>
    4eff:	48 83 bd 78 ff ff ff 	cmp    QWORD PTR [rbp-0x88],0x0
    4f06:	00 
    4f07:	78 4f                	js     4f58 <TEST_permutation_t_float_trans____1+0x17a9>
    4f09:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4f10:	48 8b 0d 19 c1 00 00 	mov    rcx,QWORD PTR [rip+0xc119]        # 11030 <f_ou_th@@Base>
    4f17:	48 8b 95 78 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x88]
    4f1e:	48 c1 e2 03          	shl    rdx,0x3
    4f22:	48 01 ca             	add    rdx,rcx
    4f25:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    4f28:	48 89 d6             	mov    rsi,rdx
    4f2b:	48 89 c7             	mov    rdi,rax
    4f2e:	e8 ad d4 ff ff       	call   23e0 <fputs@plt>
    4f33:	48 8b 15 f6 c0 00 00 	mov    rdx,QWORD PTR [rip+0xc0f6]        # 11030 <f_ou_th@@Base>
    4f3a:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    4f41:	48 c1 e0 03          	shl    rax,0x3
    4f45:	48 01 d0             	add    rax,rdx
    4f48:	48 8b 00             	mov    rax,QWORD PTR [rax]
    4f4b:	48 89 c7             	mov    rdi,rax
    4f4e:	e8 3d d5 ff ff       	call   2490 <fflush@plt>
    4f53:	e9 88 00 00 00       	jmp    4fe0 <TEST_permutation_t_float_trans____1+0x1831>
    4f58:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4f5f:	48 8b 15 c2 c0 00 00 	mov    rdx,QWORD PTR [rip+0xc0c2]        # 11028 <stdout@GLIBC_2.2.5>
    4f66:	48 89 d6             	mov    rsi,rdx
    4f69:	48 89 c7             	mov    rdi,rax
    4f6c:	e8 6f d4 ff ff       	call   23e0 <fputs@plt>
    4f71:	eb 6d                	jmp    4fe0 <TEST_permutation_t_float_trans____1+0x1831>
    4f73:	48 8b 05 be c0 00 00 	mov    rax,QWORD PTR [rip+0xc0be]        # 11038 <savelog@@Base>
    4f7a:	48 85 c0             	test   rax,rax
    4f7d:	74 48                	je     4fc7 <TEST_permutation_t_float_trans____1+0x1818>
    4f7f:	48 8b 05 b2 c0 00 00 	mov    rax,QWORD PTR [rip+0xc0b2]        # 11038 <savelog@@Base>
    4f86:	48 8d 15 f2 90 00 00 	lea    rdx,[rip+0x90f2]        # e07f <_IO_stdin_used+0x7f>
    4f8d:	48 89 d6             	mov    rsi,rdx
    4f90:	48 89 c7             	mov    rdi,rax
    4f93:	e8 68 d5 ff ff       	call   2500 <fopen@plt>
    4f98:	48 89 85 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rax
    4f9f:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4fa6:	48 8b 95 70 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x90]
    4fad:	48 89 d6             	mov    rsi,rdx
    4fb0:	48 89 c7             	mov    rdi,rax
    4fb3:	e8 28 d4 ff ff       	call   23e0 <fputs@plt>
    4fb8:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    4fbf:	48 89 c7             	mov    rdi,rax
    4fc2:	e8 e9 d3 ff ff       	call   23b0 <fclose@plt>
    4fc7:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4fce:	48 8b 15 53 c0 00 00 	mov    rdx,QWORD PTR [rip+0xc053]        # 11028 <stdout@GLIBC_2.2.5>
    4fd5:	48 89 d6             	mov    rsi,rdx
    4fd8:	48 89 c7             	mov    rdi,rax
    4fdb:	e8 00 d4 ff ff       	call   23e0 <fputs@plt>
    4fe0:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    4fe7:	48 89 c7             	mov    rdi,rax
    4fea:	e8 c1 d3 ff ff       	call   23b0 <fclose@plt>
    4fef:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    4ff6:	48 89 c7             	mov    rdi,rax
    4ff9:	e8 32 d3 ff ff       	call   2330 <free@plt>
    4ffe:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    5005:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    500c:	48 89 d6             	mov    rsi,rdx
    500f:	48 89 c7             	mov    rdi,rax
    5012:	e8 39 d3 ff ff       	call   2350 <open_memstream@plt>
    5017:	48 89 45 80          	mov    QWORD PTR [rbp-0x80],rax
    501b:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    5020:	75 38                	jne    505a <TEST_permutation_t_float_trans____1+0x18ab>
    5022:	48 8b 05 d7 c0 00 00 	mov    rax,QWORD PTR [rip+0xc0d7]        # 11100 <stderr@GLIBC_2.2.5>
    5029:	4c 8d 05 f0 92 00 00 	lea    r8,[rip+0x92f0]        # e320 <__func__.3>
    5030:	b9 34 00 00 00       	mov    ecx,0x34
    5035:	48 8d 15 08 90 00 00 	lea    rdx,[rip+0x9008]        # e044 <_IO_stdin_used+0x44>
    503c:	48 8d 35 0d 90 00 00 	lea    rsi,[rip+0x900d]        # e050 <_IO_stdin_used+0x50>
    5043:	48 89 c7             	mov    rdi,rax
    5046:	b8 00 00 00 00       	mov    eax,0x0
    504b:	e8 10 d4 ff ff       	call   2460 <fprintf@plt>
    5050:	bf 00 00 00 00       	mov    edi,0x0
    5055:	e8 c6 d4 ff ff       	call   2520 <exit@plt>
    505a:	8b 05 40 c0 00 00    	mov    eax,DWORD PTR [rip+0xc040]        # 110a0 <k_DEFAULT@@Base>
    5060:	48 98                	cdqe   
    5062:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5069:	00 
    506a:	48 8d 05 4f c0 00 00 	lea    rax,[rip+0xc04f]        # 110c0 <colors_f@@Base>
    5071:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    5075:	8b 05 05 c0 00 00    	mov    eax,DWORD PTR [rip+0xc005]        # 11080 <hk_TR@@Base>
    507b:	48 98                	cdqe   
    507d:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5084:	00 
    5085:	48 8d 05 b4 bf 00 00 	lea    rax,[rip+0xbfb4]        # 11040 <tab_hk_f@@Base>
    508c:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    5090:	8b 05 ee bf 00 00    	mov    eax,DWORD PTR [rip+0xbfee]        # 11084 <k_RED@@Base>
    5096:	48 98                	cdqe   
    5098:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    509f:	00 
    50a0:	48 8d 05 19 c0 00 00 	lea    rax,[rip+0xc019]        # 110c0 <colors_f@@Base>
    50a7:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    50ab:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    50af:	4c 8d 0d 6a 92 00 00 	lea    r9,[rip+0x926a]        # e320 <__func__.3>
    50b6:	49 89 f0             	mov    r8,rsi
    50b9:	48 8d 35 48 90 00 00 	lea    rsi,[rip+0x9048]        # e108 <_IO_stdin_used+0x108>
    50c0:	48 89 c7             	mov    rdi,rax
    50c3:	b8 00 00 00 00       	mov    eax,0x0
    50c8:	e8 93 d3 ff ff       	call   2460 <fprintf@plt>
    50cd:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    50d1:	48 89 c7             	mov    rdi,rax
    50d4:	e8 b7 d3 ff ff       	call   2490 <fflush@plt>
    50d9:	0f b6 05 b0 bf 00 00 	movzx  eax,BYTE PTR [rip+0xbfb0]        # 11090 <is_parallel_nb@@Base>
    50e0:	84 c0                	test   al,al
    50e2:	0f 84 e9 00 00 00    	je     51d1 <TEST_permutation_t_float_trans____1+0x1a22>
    50e8:	e8 63 d3 ff ff       	call   2450 <id_of_thread_executed@plt>
    50ed:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
    50f1:	0f b6 05 28 bf 00 00 	movzx  eax,BYTE PTR [rip+0xbf28]        # 11020 <log_parallel@@Base>
    50f8:	84 c0                	test   al,al
    50fa:	74 6d                	je     5169 <TEST_permutation_t_float_trans____1+0x19ba>
    50fc:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5103:	48 8b 15 1e bf 00 00 	mov    rdx,QWORD PTR [rip+0xbf1e]        # 11028 <stdout@GLIBC_2.2.5>
    510a:	48 89 d6             	mov    rsi,rdx
    510d:	48 89 c7             	mov    rdi,rax
    5110:	e8 cb d2 ff ff       	call   23e0 <fputs@plt>
    5115:	48 83 7d 90 00       	cmp    QWORD PTR [rbp-0x70],0x0
    511a:	0f 88 15 01 00 00    	js     5235 <TEST_permutation_t_float_trans____1+0x1a86>
    5120:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5127:	48 8b 0d 02 bf 00 00 	mov    rcx,QWORD PTR [rip+0xbf02]        # 11030 <f_ou_th@@Base>
    512e:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
    5132:	48 c1 e2 03          	shl    rdx,0x3
    5136:	48 01 ca             	add    rdx,rcx
    5139:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    513c:	48 89 d6             	mov    rsi,rdx
    513f:	48 89 c7             	mov    rdi,rax
    5142:	e8 99 d2 ff ff       	call   23e0 <fputs@plt>
    5147:	48 8b 15 e2 be 00 00 	mov    rdx,QWORD PTR [rip+0xbee2]        # 11030 <f_ou_th@@Base>
    514e:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
    5152:	48 c1 e0 03          	shl    rax,0x3
    5156:	48 01 d0             	add    rax,rdx
    5159:	48 8b 00             	mov    rax,QWORD PTR [rax]
    515c:	48 89 c7             	mov    rdi,rax
    515f:	e8 2c d3 ff ff       	call   2490 <fflush@plt>
    5164:	e9 cc 00 00 00       	jmp    5235 <TEST_permutation_t_float_trans____1+0x1a86>
    5169:	48 83 7d 90 00       	cmp    QWORD PTR [rbp-0x70],0x0
    516e:	78 46                	js     51b6 <TEST_permutation_t_float_trans____1+0x1a07>
    5170:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5177:	48 8b 0d b2 be 00 00 	mov    rcx,QWORD PTR [rip+0xbeb2]        # 11030 <f_ou_th@@Base>
    517e:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
    5182:	48 c1 e2 03          	shl    rdx,0x3
    5186:	48 01 ca             	add    rdx,rcx
    5189:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    518c:	48 89 d6             	mov    rsi,rdx
    518f:	48 89 c7             	mov    rdi,rax
    5192:	e8 49 d2 ff ff       	call   23e0 <fputs@plt>
    5197:	48 8b 15 92 be 00 00 	mov    rdx,QWORD PTR [rip+0xbe92]        # 11030 <f_ou_th@@Base>
    519e:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
    51a2:	48 c1 e0 03          	shl    rax,0x3
    51a6:	48 01 d0             	add    rax,rdx
    51a9:	48 8b 00             	mov    rax,QWORD PTR [rax]
    51ac:	48 89 c7             	mov    rdi,rax
    51af:	e8 dc d2 ff ff       	call   2490 <fflush@plt>
    51b4:	eb 7f                	jmp    5235 <TEST_permutation_t_float_trans____1+0x1a86>
    51b6:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    51bd:	48 8b 15 64 be 00 00 	mov    rdx,QWORD PTR [rip+0xbe64]        # 11028 <stdout@GLIBC_2.2.5>
    51c4:	48 89 d6             	mov    rsi,rdx
    51c7:	48 89 c7             	mov    rdi,rax
    51ca:	e8 11 d2 ff ff       	call   23e0 <fputs@plt>
    51cf:	eb 64                	jmp    5235 <TEST_permutation_t_float_trans____1+0x1a86>
    51d1:	48 8b 05 60 be 00 00 	mov    rax,QWORD PTR [rip+0xbe60]        # 11038 <savelog@@Base>
    51d8:	48 85 c0             	test   rax,rax
    51db:	74 3f                	je     521c <TEST_permutation_t_float_trans____1+0x1a6d>
    51dd:	48 8b 05 54 be 00 00 	mov    rax,QWORD PTR [rip+0xbe54]        # 11038 <savelog@@Base>
    51e4:	48 8d 15 94 8e 00 00 	lea    rdx,[rip+0x8e94]        # e07f <_IO_stdin_used+0x7f>
    51eb:	48 89 d6             	mov    rsi,rdx
    51ee:	48 89 c7             	mov    rdi,rax
    51f1:	e8 0a d3 ff ff       	call   2500 <fopen@plt>
    51f6:	48 89 45 88          	mov    QWORD PTR [rbp-0x78],rax
    51fa:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5201:	48 8b 55 88          	mov    rdx,QWORD PTR [rbp-0x78]
    5205:	48 89 d6             	mov    rsi,rdx
    5208:	48 89 c7             	mov    rdi,rax
    520b:	e8 d0 d1 ff ff       	call   23e0 <fputs@plt>
    5210:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    5214:	48 89 c7             	mov    rdi,rax
    5217:	e8 94 d1 ff ff       	call   23b0 <fclose@plt>
    521c:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5223:	48 8b 15 fe bd 00 00 	mov    rdx,QWORD PTR [rip+0xbdfe]        # 11028 <stdout@GLIBC_2.2.5>
    522a:	48 89 d6             	mov    rsi,rdx
    522d:	48 89 c7             	mov    rdi,rax
    5230:	e8 ab d1 ff ff       	call   23e0 <fputs@plt>
    5235:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    5239:	48 89 c7             	mov    rdi,rax
    523c:	e8 6f d1 ff ff       	call   23b0 <fclose@plt>
    5241:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5248:	48 89 c7             	mov    rdi,rax
    524b:	e8 e0 d0 ff ff       	call   2330 <free@plt>
    5250:	e9 f6 07 00 00       	jmp    5a4b <TEST_permutation_t_float_trans____1+0x229c>
    5255:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    525c:	48 8b 44 c5 b0       	mov    rax,QWORD PTR [rbp+rax*8-0x50]
    5261:	48 89 c6             	mov    rsi,rax
    5264:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    526b:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    526f:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    5276:	48 c1 e0 03          	shl    rax,0x3
    527a:	48 01 d0             	add    rax,rdx
    527d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5280:	48 89 c1             	mov    rcx,rax
    5283:	48 8d 05 96 90 00 00 	lea    rax,[rip+0x9096]        # e320 <__func__.3>
    528a:	48 89 c2             	mov    rdx,rax
    528d:	48 89 cf             	mov    rdi,rcx
    5290:	e8 eb d0 ff ff       	call   2380 <expected_EQ_name_TYPE_L_INT@plt>
    5295:	84 c0                	test   al,al
    5297:	0f 84 87 02 00 00    	je     5524 <TEST_permutation_t_float_trans____1+0x1d75>
    529d:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    52a4:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    52ab:	48 89 d6             	mov    rsi,rdx
    52ae:	48 89 c7             	mov    rdi,rax
    52b1:	e8 9a d0 ff ff       	call   2350 <open_memstream@plt>
    52b6:	48 89 85 50 ff ff ff 	mov    QWORD PTR [rbp-0xb0],rax
    52bd:	48 83 bd 50 ff ff ff 	cmp    QWORD PTR [rbp-0xb0],0x0
    52c4:	00 
    52c5:	75 38                	jne    52ff <TEST_permutation_t_float_trans____1+0x1b50>
    52c7:	48 8b 05 32 be 00 00 	mov    rax,QWORD PTR [rip+0xbe32]        # 11100 <stderr@GLIBC_2.2.5>
    52ce:	4c 8d 05 4b 90 00 00 	lea    r8,[rip+0x904b]        # e320 <__func__.3>
    52d5:	b9 34 00 00 00       	mov    ecx,0x34
    52da:	48 8d 15 63 8d 00 00 	lea    rdx,[rip+0x8d63]        # e044 <_IO_stdin_used+0x44>
    52e1:	48 8d 35 68 8d 00 00 	lea    rsi,[rip+0x8d68]        # e050 <_IO_stdin_used+0x50>
    52e8:	48 89 c7             	mov    rdi,rax
    52eb:	b8 00 00 00 00       	mov    eax,0x0
    52f0:	e8 6b d1 ff ff       	call   2460 <fprintf@plt>
    52f5:	bf 00 00 00 00       	mov    edi,0x0
    52fa:	e8 21 d2 ff ff       	call   2520 <exit@plt>
    52ff:	8b 05 9b bd 00 00    	mov    eax,DWORD PTR [rip+0xbd9b]        # 110a0 <k_DEFAULT@@Base>
    5305:	48 98                	cdqe   
    5307:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    530e:	00 
    530f:	48 8d 05 aa bd 00 00 	lea    rax,[rip+0xbdaa]        # 110c0 <colors_f@@Base>
    5316:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    531a:	8b 05 60 bd 00 00    	mov    eax,DWORD PTR [rip+0xbd60]        # 11080 <hk_TR@@Base>
    5320:	48 98                	cdqe   
    5322:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5329:	00 
    532a:	48 8d 05 0f bd 00 00 	lea    rax,[rip+0xbd0f]        # 11040 <tab_hk_f@@Base>
    5331:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    5335:	8b 05 b5 bd 00 00    	mov    eax,DWORD PTR [rip+0xbdb5]        # 110f0 <k_GREEN@@Base>
    533b:	48 98                	cdqe   
    533d:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5344:	00 
    5345:	48 8d 05 74 bd 00 00 	lea    rax,[rip+0xbd74]        # 110c0 <colors_f@@Base>
    534c:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    5350:	48 8b 85 50 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb0]
    5357:	4c 8d 0d c2 8f 00 00 	lea    r9,[rip+0x8fc2]        # e320 <__func__.3>
    535e:	49 89 f0             	mov    r8,rsi
    5361:	48 8d 35 20 8d 00 00 	lea    rsi,[rip+0x8d20]        # e088 <_IO_stdin_used+0x88>
    5368:	48 89 c7             	mov    rdi,rax
    536b:	b8 00 00 00 00       	mov    eax,0x0
    5370:	e8 eb d0 ff ff       	call   2460 <fprintf@plt>
    5375:	48 8b 85 50 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb0]
    537c:	48 89 c7             	mov    rdi,rax
    537f:	e8 0c d1 ff ff       	call   2490 <fflush@plt>
    5384:	0f b6 05 05 bd 00 00 	movzx  eax,BYTE PTR [rip+0xbd05]        # 11090 <is_parallel_nb@@Base>
    538b:	84 c0                	test   al,al
    538d:	0f 84 01 01 00 00    	je     5494 <TEST_permutation_t_float_trans____1+0x1ce5>
    5393:	e8 b8 d0 ff ff       	call   2450 <id_of_thread_executed@plt>
    5398:	48 89 85 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rax
    539f:	0f b6 05 7a bc 00 00 	movzx  eax,BYTE PTR [rip+0xbc7a]        # 11020 <log_parallel@@Base>
    53a6:	84 c0                	test   al,al
    53a8:	74 76                	je     5420 <TEST_permutation_t_float_trans____1+0x1c71>
    53aa:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    53b1:	48 8b 15 70 bc 00 00 	mov    rdx,QWORD PTR [rip+0xbc70]        # 11028 <stdout@GLIBC_2.2.5>
    53b8:	48 89 d6             	mov    rsi,rdx
    53bb:	48 89 c7             	mov    rdi,rax
    53be:	e8 1d d0 ff ff       	call   23e0 <fputs@plt>
    53c3:	48 83 bd 60 ff ff ff 	cmp    QWORD PTR [rbp-0xa0],0x0
    53ca:	00 
    53cb:	0f 88 30 01 00 00    	js     5501 <TEST_permutation_t_float_trans____1+0x1d52>
    53d1:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    53d8:	48 8b 0d 51 bc 00 00 	mov    rcx,QWORD PTR [rip+0xbc51]        # 11030 <f_ou_th@@Base>
    53df:	48 8b 95 60 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa0]
    53e6:	48 c1 e2 03          	shl    rdx,0x3
    53ea:	48 01 ca             	add    rdx,rcx
    53ed:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    53f0:	48 89 d6             	mov    rsi,rdx
    53f3:	48 89 c7             	mov    rdi,rax
    53f6:	e8 e5 cf ff ff       	call   23e0 <fputs@plt>
    53fb:	48 8b 15 2e bc 00 00 	mov    rdx,QWORD PTR [rip+0xbc2e]        # 11030 <f_ou_th@@Base>
    5402:	48 8b 85 60 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa0]
    5409:	48 c1 e0 03          	shl    rax,0x3
    540d:	48 01 d0             	add    rax,rdx
    5410:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5413:	48 89 c7             	mov    rdi,rax
    5416:	e8 75 d0 ff ff       	call   2490 <fflush@plt>
    541b:	e9 e1 00 00 00       	jmp    5501 <TEST_permutation_t_float_trans____1+0x1d52>
    5420:	48 83 bd 60 ff ff ff 	cmp    QWORD PTR [rbp-0xa0],0x0
    5427:	00 
    5428:	78 4f                	js     5479 <TEST_permutation_t_float_trans____1+0x1cca>
    542a:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5431:	48 8b 0d f8 bb 00 00 	mov    rcx,QWORD PTR [rip+0xbbf8]        # 11030 <f_ou_th@@Base>
    5438:	48 8b 95 60 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa0]
    543f:	48 c1 e2 03          	shl    rdx,0x3
    5443:	48 01 ca             	add    rdx,rcx
    5446:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5449:	48 89 d6             	mov    rsi,rdx
    544c:	48 89 c7             	mov    rdi,rax
    544f:	e8 8c cf ff ff       	call   23e0 <fputs@plt>
    5454:	48 8b 15 d5 bb 00 00 	mov    rdx,QWORD PTR [rip+0xbbd5]        # 11030 <f_ou_th@@Base>
    545b:	48 8b 85 60 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa0]
    5462:	48 c1 e0 03          	shl    rax,0x3
    5466:	48 01 d0             	add    rax,rdx
    5469:	48 8b 00             	mov    rax,QWORD PTR [rax]
    546c:	48 89 c7             	mov    rdi,rax
    546f:	e8 1c d0 ff ff       	call   2490 <fflush@plt>
    5474:	e9 88 00 00 00       	jmp    5501 <TEST_permutation_t_float_trans____1+0x1d52>
    5479:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5480:	48 8b 15 a1 bb 00 00 	mov    rdx,QWORD PTR [rip+0xbba1]        # 11028 <stdout@GLIBC_2.2.5>
    5487:	48 89 d6             	mov    rsi,rdx
    548a:	48 89 c7             	mov    rdi,rax
    548d:	e8 4e cf ff ff       	call   23e0 <fputs@plt>
    5492:	eb 6d                	jmp    5501 <TEST_permutation_t_float_trans____1+0x1d52>
    5494:	48 8b 05 9d bb 00 00 	mov    rax,QWORD PTR [rip+0xbb9d]        # 11038 <savelog@@Base>
    549b:	48 85 c0             	test   rax,rax
    549e:	74 48                	je     54e8 <TEST_permutation_t_float_trans____1+0x1d39>
    54a0:	48 8b 05 91 bb 00 00 	mov    rax,QWORD PTR [rip+0xbb91]        # 11038 <savelog@@Base>
    54a7:	48 8d 15 d1 8b 00 00 	lea    rdx,[rip+0x8bd1]        # e07f <_IO_stdin_used+0x7f>
    54ae:	48 89 d6             	mov    rsi,rdx
    54b1:	48 89 c7             	mov    rdi,rax
    54b4:	e8 47 d0 ff ff       	call   2500 <fopen@plt>
    54b9:	48 89 85 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rax
    54c0:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    54c7:	48 8b 95 58 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa8]
    54ce:	48 89 d6             	mov    rsi,rdx
    54d1:	48 89 c7             	mov    rdi,rax
    54d4:	e8 07 cf ff ff       	call   23e0 <fputs@plt>
    54d9:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    54e0:	48 89 c7             	mov    rdi,rax
    54e3:	e8 c8 ce ff ff       	call   23b0 <fclose@plt>
    54e8:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    54ef:	48 8b 15 32 bb 00 00 	mov    rdx,QWORD PTR [rip+0xbb32]        # 11028 <stdout@GLIBC_2.2.5>
    54f6:	48 89 d6             	mov    rsi,rdx
    54f9:	48 89 c7             	mov    rdi,rax
    54fc:	e8 df ce ff ff       	call   23e0 <fputs@plt>
    5501:	48 8b 85 50 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb0]
    5508:	48 89 c7             	mov    rdi,rax
    550b:	e8 a0 ce ff ff       	call   23b0 <fclose@plt>
    5510:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5517:	48 89 c7             	mov    rdi,rax
    551a:	e8 11 ce ff ff       	call   2330 <free@plt>
    551f:	e9 27 05 00 00       	jmp    5a4b <TEST_permutation_t_float_trans____1+0x229c>
    5524:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    552b:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    5532:	48 89 d6             	mov    rsi,rdx
    5535:	48 89 c7             	mov    rdi,rax
    5538:	e8 13 ce ff ff       	call   2350 <open_memstream@plt>
    553d:	48 89 85 20 ff ff ff 	mov    QWORD PTR [rbp-0xe0],rax
    5544:	48 83 bd 20 ff ff ff 	cmp    QWORD PTR [rbp-0xe0],0x0
    554b:	00 
    554c:	75 38                	jne    5586 <TEST_permutation_t_float_trans____1+0x1dd7>
    554e:	48 8b 05 ab bb 00 00 	mov    rax,QWORD PTR [rip+0xbbab]        # 11100 <stderr@GLIBC_2.2.5>
    5555:	4c 8d 05 c4 8d 00 00 	lea    r8,[rip+0x8dc4]        # e320 <__func__.3>
    555c:	b9 34 00 00 00       	mov    ecx,0x34
    5561:	48 8d 15 dc 8a 00 00 	lea    rdx,[rip+0x8adc]        # e044 <_IO_stdin_used+0x44>
    5568:	48 8d 35 e1 8a 00 00 	lea    rsi,[rip+0x8ae1]        # e050 <_IO_stdin_used+0x50>
    556f:	48 89 c7             	mov    rdi,rax
    5572:	b8 00 00 00 00       	mov    eax,0x0
    5577:	e8 e4 ce ff ff       	call   2460 <fprintf@plt>
    557c:	bf 00 00 00 00       	mov    edi,0x0
    5581:	e8 9a cf ff ff       	call   2520 <exit@plt>
    5586:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    558d:	48 8b 44 c5 b0       	mov    rax,QWORD PTR [rbp+rax*8-0x50]
    5592:	48 89 c7             	mov    rdi,rax
    5595:	e8 96 cf ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    559a:	48 89 c3             	mov    rbx,rax
    559d:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    55a4:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    55a8:	48 8b 85 00 fe ff ff 	mov    rax,QWORD PTR [rbp-0x200]
    55af:	48 c1 e0 03          	shl    rax,0x3
    55b3:	48 01 d0             	add    rax,rdx
    55b6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    55b9:	48 89 c7             	mov    rdi,rax
    55bc:	e8 6f cf ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    55c1:	48 89 c2             	mov    rdx,rax
    55c4:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    55cb:	53                   	push   rbx
    55cc:	48 8d 0d 99 8b 00 00 	lea    rcx,[rip+0x8b99]        # e16c <_IO_stdin_used+0x16c>
    55d3:	51                   	push   rcx
    55d4:	52                   	push   rdx
    55d5:	48 8d 15 7b 8b 00 00 	lea    rdx,[rip+0x8b7b]        # e157 <_IO_stdin_used+0x157>
    55dc:	52                   	push   rdx
    55dd:	48 8d 15 88 8b 00 00 	lea    rdx,[rip+0x8b88]        # e16c <_IO_stdin_used+0x16c>
    55e4:	52                   	push   rdx
    55e5:	48 8d 15 18 8b 00 00 	lea    rdx,[rip+0x8b18]        # e104 <_IO_stdin_used+0x104>
    55ec:	52                   	push   rdx
    55ed:	4c 8d 0d 63 8b 00 00 	lea    r9,[rip+0x8b63]        # e157 <_IO_stdin_used+0x157>
    55f4:	4c 8d 05 25 8d 00 00 	lea    r8,[rip+0x8d25]        # e320 <__func__.3>
    55fb:	b9 34 00 00 00       	mov    ecx,0x34
    5600:	48 8d 15 3d 8a 00 00 	lea    rdx,[rip+0x8a3d]        # e044 <_IO_stdin_used+0x44>
    5607:	48 8d 35 a2 8a 00 00 	lea    rsi,[rip+0x8aa2]        # e0b0 <_IO_stdin_used+0xb0>
    560e:	48 89 c7             	mov    rdi,rax
    5611:	b8 00 00 00 00       	mov    eax,0x0
    5616:	e8 45 ce ff ff       	call   2460 <fprintf@plt>
    561b:	48 83 c4 30          	add    rsp,0x30
    561f:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    5626:	48 89 c7             	mov    rdi,rax
    5629:	e8 62 ce ff ff       	call   2490 <fflush@plt>
    562e:	0f b6 05 5b ba 00 00 	movzx  eax,BYTE PTR [rip+0xba5b]        # 11090 <is_parallel_nb@@Base>
    5635:	84 c0                	test   al,al
    5637:	0f 84 01 01 00 00    	je     573e <TEST_permutation_t_float_trans____1+0x1f8f>
    563d:	e8 0e ce ff ff       	call   2450 <id_of_thread_executed@plt>
    5642:	48 89 85 30 ff ff ff 	mov    QWORD PTR [rbp-0xd0],rax
    5649:	0f b6 05 d0 b9 00 00 	movzx  eax,BYTE PTR [rip+0xb9d0]        # 11020 <log_parallel@@Base>
    5650:	84 c0                	test   al,al
    5652:	74 76                	je     56ca <TEST_permutation_t_float_trans____1+0x1f1b>
    5654:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    565b:	48 8b 15 c6 b9 00 00 	mov    rdx,QWORD PTR [rip+0xb9c6]        # 11028 <stdout@GLIBC_2.2.5>
    5662:	48 89 d6             	mov    rsi,rdx
    5665:	48 89 c7             	mov    rdi,rax
    5668:	e8 73 cd ff ff       	call   23e0 <fputs@plt>
    566d:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    5674:	00 
    5675:	0f 88 30 01 00 00    	js     57ab <TEST_permutation_t_float_trans____1+0x1ffc>
    567b:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5682:	48 8b 0d a7 b9 00 00 	mov    rcx,QWORD PTR [rip+0xb9a7]        # 11030 <f_ou_th@@Base>
    5689:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    5690:	48 c1 e2 03          	shl    rdx,0x3
    5694:	48 01 ca             	add    rdx,rcx
    5697:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    569a:	48 89 d6             	mov    rsi,rdx
    569d:	48 89 c7             	mov    rdi,rax
    56a0:	e8 3b cd ff ff       	call   23e0 <fputs@plt>
    56a5:	48 8b 15 84 b9 00 00 	mov    rdx,QWORD PTR [rip+0xb984]        # 11030 <f_ou_th@@Base>
    56ac:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    56b3:	48 c1 e0 03          	shl    rax,0x3
    56b7:	48 01 d0             	add    rax,rdx
    56ba:	48 8b 00             	mov    rax,QWORD PTR [rax]
    56bd:	48 89 c7             	mov    rdi,rax
    56c0:	e8 cb cd ff ff       	call   2490 <fflush@plt>
    56c5:	e9 e1 00 00 00       	jmp    57ab <TEST_permutation_t_float_trans____1+0x1ffc>
    56ca:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    56d1:	00 
    56d2:	78 4f                	js     5723 <TEST_permutation_t_float_trans____1+0x1f74>
    56d4:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    56db:	48 8b 0d 4e b9 00 00 	mov    rcx,QWORD PTR [rip+0xb94e]        # 11030 <f_ou_th@@Base>
    56e2:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    56e9:	48 c1 e2 03          	shl    rdx,0x3
    56ed:	48 01 ca             	add    rdx,rcx
    56f0:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    56f3:	48 89 d6             	mov    rsi,rdx
    56f6:	48 89 c7             	mov    rdi,rax
    56f9:	e8 e2 cc ff ff       	call   23e0 <fputs@plt>
    56fe:	48 8b 15 2b b9 00 00 	mov    rdx,QWORD PTR [rip+0xb92b]        # 11030 <f_ou_th@@Base>
    5705:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    570c:	48 c1 e0 03          	shl    rax,0x3
    5710:	48 01 d0             	add    rax,rdx
    5713:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5716:	48 89 c7             	mov    rdi,rax
    5719:	e8 72 cd ff ff       	call   2490 <fflush@plt>
    571e:	e9 88 00 00 00       	jmp    57ab <TEST_permutation_t_float_trans____1+0x1ffc>
    5723:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    572a:	48 8b 15 f7 b8 00 00 	mov    rdx,QWORD PTR [rip+0xb8f7]        # 11028 <stdout@GLIBC_2.2.5>
    5731:	48 89 d6             	mov    rsi,rdx
    5734:	48 89 c7             	mov    rdi,rax
    5737:	e8 a4 cc ff ff       	call   23e0 <fputs@plt>
    573c:	eb 6d                	jmp    57ab <TEST_permutation_t_float_trans____1+0x1ffc>
    573e:	48 8b 05 f3 b8 00 00 	mov    rax,QWORD PTR [rip+0xb8f3]        # 11038 <savelog@@Base>
    5745:	48 85 c0             	test   rax,rax
    5748:	74 48                	je     5792 <TEST_permutation_t_float_trans____1+0x1fe3>
    574a:	48 8b 05 e7 b8 00 00 	mov    rax,QWORD PTR [rip+0xb8e7]        # 11038 <savelog@@Base>
    5751:	48 8d 15 27 89 00 00 	lea    rdx,[rip+0x8927]        # e07f <_IO_stdin_used+0x7f>
    5758:	48 89 d6             	mov    rsi,rdx
    575b:	48 89 c7             	mov    rdi,rax
    575e:	e8 9d cd ff ff       	call   2500 <fopen@plt>
    5763:	48 89 85 28 ff ff ff 	mov    QWORD PTR [rbp-0xd8],rax
    576a:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5771:	48 8b 95 28 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd8]
    5778:	48 89 d6             	mov    rsi,rdx
    577b:	48 89 c7             	mov    rdi,rax
    577e:	e8 5d cc ff ff       	call   23e0 <fputs@plt>
    5783:	48 8b 85 28 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd8]
    578a:	48 89 c7             	mov    rdi,rax
    578d:	e8 1e cc ff ff       	call   23b0 <fclose@plt>
    5792:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5799:	48 8b 15 88 b8 00 00 	mov    rdx,QWORD PTR [rip+0xb888]        # 11028 <stdout@GLIBC_2.2.5>
    57a0:	48 89 d6             	mov    rsi,rdx
    57a3:	48 89 c7             	mov    rdi,rax
    57a6:	e8 35 cc ff ff       	call   23e0 <fputs@plt>
    57ab:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    57b2:	48 89 c7             	mov    rdi,rax
    57b5:	e8 f6 cb ff ff       	call   23b0 <fclose@plt>
    57ba:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    57c1:	48 89 c7             	mov    rdi,rax
    57c4:	e8 67 cb ff ff       	call   2330 <free@plt>
    57c9:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    57d0:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    57d7:	48 89 d6             	mov    rsi,rdx
    57da:	48 89 c7             	mov    rdi,rax
    57dd:	e8 6e cb ff ff       	call   2350 <open_memstream@plt>
    57e2:	48 89 85 38 ff ff ff 	mov    QWORD PTR [rbp-0xc8],rax
    57e9:	48 83 bd 38 ff ff ff 	cmp    QWORD PTR [rbp-0xc8],0x0
    57f0:	00 
    57f1:	75 38                	jne    582b <TEST_permutation_t_float_trans____1+0x207c>
    57f3:	48 8b 05 06 b9 00 00 	mov    rax,QWORD PTR [rip+0xb906]        # 11100 <stderr@GLIBC_2.2.5>
    57fa:	4c 8d 05 1f 8b 00 00 	lea    r8,[rip+0x8b1f]        # e320 <__func__.3>
    5801:	b9 34 00 00 00       	mov    ecx,0x34
    5806:	48 8d 15 37 88 00 00 	lea    rdx,[rip+0x8837]        # e044 <_IO_stdin_used+0x44>
    580d:	48 8d 35 3c 88 00 00 	lea    rsi,[rip+0x883c]        # e050 <_IO_stdin_used+0x50>
    5814:	48 89 c7             	mov    rdi,rax
    5817:	b8 00 00 00 00       	mov    eax,0x0
    581c:	e8 3f cc ff ff       	call   2460 <fprintf@plt>
    5821:	bf 00 00 00 00       	mov    edi,0x0
    5826:	e8 f5 cc ff ff       	call   2520 <exit@plt>
    582b:	8b 05 6f b8 00 00    	mov    eax,DWORD PTR [rip+0xb86f]        # 110a0 <k_DEFAULT@@Base>
    5831:	48 98                	cdqe   
    5833:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    583a:	00 
    583b:	48 8d 05 7e b8 00 00 	lea    rax,[rip+0xb87e]        # 110c0 <colors_f@@Base>
    5842:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    5846:	8b 05 34 b8 00 00    	mov    eax,DWORD PTR [rip+0xb834]        # 11080 <hk_TR@@Base>
    584c:	48 98                	cdqe   
    584e:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5855:	00 
    5856:	48 8d 05 e3 b7 00 00 	lea    rax,[rip+0xb7e3]        # 11040 <tab_hk_f@@Base>
    585d:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    5861:	8b 05 1d b8 00 00    	mov    eax,DWORD PTR [rip+0xb81d]        # 11084 <k_RED@@Base>
    5867:	48 98                	cdqe   
    5869:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    5870:	00 
    5871:	48 8d 05 48 b8 00 00 	lea    rax,[rip+0xb848]        # 110c0 <colors_f@@Base>
    5878:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    587c:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    5883:	4c 8d 0d 96 8a 00 00 	lea    r9,[rip+0x8a96]        # e320 <__func__.3>
    588a:	49 89 f0             	mov    r8,rsi
    588d:	48 8d 35 74 88 00 00 	lea    rsi,[rip+0x8874]        # e108 <_IO_stdin_used+0x108>
    5894:	48 89 c7             	mov    rdi,rax
    5897:	b8 00 00 00 00       	mov    eax,0x0
    589c:	e8 bf cb ff ff       	call   2460 <fprintf@plt>
    58a1:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    58a8:	48 89 c7             	mov    rdi,rax
    58ab:	e8 e0 cb ff ff       	call   2490 <fflush@plt>
    58b0:	0f b6 05 d9 b7 00 00 	movzx  eax,BYTE PTR [rip+0xb7d9]        # 11090 <is_parallel_nb@@Base>
    58b7:	84 c0                	test   al,al
    58b9:	0f 84 01 01 00 00    	je     59c0 <TEST_permutation_t_float_trans____1+0x2211>
    58bf:	e8 8c cb ff ff       	call   2450 <id_of_thread_executed@plt>
    58c4:	48 89 85 48 ff ff ff 	mov    QWORD PTR [rbp-0xb8],rax
    58cb:	0f b6 05 4e b7 00 00 	movzx  eax,BYTE PTR [rip+0xb74e]        # 11020 <log_parallel@@Base>
    58d2:	84 c0                	test   al,al
    58d4:	74 76                	je     594c <TEST_permutation_t_float_trans____1+0x219d>
    58d6:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    58dd:	48 8b 15 44 b7 00 00 	mov    rdx,QWORD PTR [rip+0xb744]        # 11028 <stdout@GLIBC_2.2.5>
    58e4:	48 89 d6             	mov    rsi,rdx
    58e7:	48 89 c7             	mov    rdi,rax
    58ea:	e8 f1 ca ff ff       	call   23e0 <fputs@plt>
    58ef:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    58f6:	00 
    58f7:	0f 88 30 01 00 00    	js     5a2d <TEST_permutation_t_float_trans____1+0x227e>
    58fd:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5904:	48 8b 0d 25 b7 00 00 	mov    rcx,QWORD PTR [rip+0xb725]        # 11030 <f_ou_th@@Base>
    590b:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    5912:	48 c1 e2 03          	shl    rdx,0x3
    5916:	48 01 ca             	add    rdx,rcx
    5919:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    591c:	48 89 d6             	mov    rsi,rdx
    591f:	48 89 c7             	mov    rdi,rax
    5922:	e8 b9 ca ff ff       	call   23e0 <fputs@plt>
    5927:	48 8b 15 02 b7 00 00 	mov    rdx,QWORD PTR [rip+0xb702]        # 11030 <f_ou_th@@Base>
    592e:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    5935:	48 c1 e0 03          	shl    rax,0x3
    5939:	48 01 d0             	add    rax,rdx
    593c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    593f:	48 89 c7             	mov    rdi,rax
    5942:	e8 49 cb ff ff       	call   2490 <fflush@plt>
    5947:	e9 e1 00 00 00       	jmp    5a2d <TEST_permutation_t_float_trans____1+0x227e>
    594c:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    5953:	00 
    5954:	78 4f                	js     59a5 <TEST_permutation_t_float_trans____1+0x21f6>
    5956:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    595d:	48 8b 0d cc b6 00 00 	mov    rcx,QWORD PTR [rip+0xb6cc]        # 11030 <f_ou_th@@Base>
    5964:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    596b:	48 c1 e2 03          	shl    rdx,0x3
    596f:	48 01 ca             	add    rdx,rcx
    5972:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5975:	48 89 d6             	mov    rsi,rdx
    5978:	48 89 c7             	mov    rdi,rax
    597b:	e8 60 ca ff ff       	call   23e0 <fputs@plt>
    5980:	48 8b 15 a9 b6 00 00 	mov    rdx,QWORD PTR [rip+0xb6a9]        # 11030 <f_ou_th@@Base>
    5987:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    598e:	48 c1 e0 03          	shl    rax,0x3
    5992:	48 01 d0             	add    rax,rdx
    5995:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5998:	48 89 c7             	mov    rdi,rax
    599b:	e8 f0 ca ff ff       	call   2490 <fflush@plt>
    59a0:	e9 88 00 00 00       	jmp    5a2d <TEST_permutation_t_float_trans____1+0x227e>
    59a5:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    59ac:	48 8b 15 75 b6 00 00 	mov    rdx,QWORD PTR [rip+0xb675]        # 11028 <stdout@GLIBC_2.2.5>
    59b3:	48 89 d6             	mov    rsi,rdx
    59b6:	48 89 c7             	mov    rdi,rax
    59b9:	e8 22 ca ff ff       	call   23e0 <fputs@plt>
    59be:	eb 6d                	jmp    5a2d <TEST_permutation_t_float_trans____1+0x227e>
    59c0:	48 8b 05 71 b6 00 00 	mov    rax,QWORD PTR [rip+0xb671]        # 11038 <savelog@@Base>
    59c7:	48 85 c0             	test   rax,rax
    59ca:	74 48                	je     5a14 <TEST_permutation_t_float_trans____1+0x2265>
    59cc:	48 8b 05 65 b6 00 00 	mov    rax,QWORD PTR [rip+0xb665]        # 11038 <savelog@@Base>
    59d3:	48 8d 15 a5 86 00 00 	lea    rdx,[rip+0x86a5]        # e07f <_IO_stdin_used+0x7f>
    59da:	48 89 d6             	mov    rsi,rdx
    59dd:	48 89 c7             	mov    rdi,rax
    59e0:	e8 1b cb ff ff       	call   2500 <fopen@plt>
    59e5:	48 89 85 40 ff ff ff 	mov    QWORD PTR [rbp-0xc0],rax
    59ec:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    59f3:	48 8b 95 40 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xc0]
    59fa:	48 89 d6             	mov    rsi,rdx
    59fd:	48 89 c7             	mov    rdi,rax
    5a00:	e8 db c9 ff ff       	call   23e0 <fputs@plt>
    5a05:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    5a0c:	48 89 c7             	mov    rdi,rax
    5a0f:	e8 9c c9 ff ff       	call   23b0 <fclose@plt>
    5a14:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5a1b:	48 8b 15 06 b6 00 00 	mov    rdx,QWORD PTR [rip+0xb606]        # 11028 <stdout@GLIBC_2.2.5>
    5a22:	48 89 d6             	mov    rsi,rdx
    5a25:	48 89 c7             	mov    rdi,rax
    5a28:	e8 b3 c9 ff ff       	call   23e0 <fputs@plt>
    5a2d:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    5a34:	48 89 c7             	mov    rdi,rax
    5a37:	e8 74 c9 ff ff       	call   23b0 <fclose@plt>
    5a3c:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5a43:	48 89 c7             	mov    rdi,rax
    5a46:	e8 e5 c8 ff ff       	call   2330 <free@plt>
    5a4b:	48 83 85 00 fe ff ff 	add    QWORD PTR [rbp-0x200],0x1
    5a52:	01 
    5a53:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    5a5a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5a5d:	48 39 85 00 fe ff ff 	cmp    QWORD PTR [rbp-0x200],rax
    5a64:	0f 82 48 f0 ff ff    	jb     4ab2 <TEST_permutation_t_float_trans____1+0x1303>
    5a6a:	c7 85 e4 fd ff ff 00 	mov    DWORD PTR [rbp-0x21c],0x0
    5a71:	00 00 00 
    5a74:	e9 51 02 00 00       	jmp    5cca <TEST_permutation_t_float_trans____1+0x251b>
    5a79:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    5a80:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    5a87:	48 89 d6             	mov    rsi,rdx
    5a8a:	48 89 c7             	mov    rdi,rax
    5a8d:	e8 be c8 ff ff       	call   2350 <open_memstream@plt>
    5a92:	48 89 85 08 ff ff ff 	mov    QWORD PTR [rbp-0xf8],rax
    5a99:	48 83 bd 08 ff ff ff 	cmp    QWORD PTR [rbp-0xf8],0x0
    5aa0:	00 
    5aa1:	75 38                	jne    5adb <TEST_permutation_t_float_trans____1+0x232c>
    5aa3:	48 8b 05 56 b6 00 00 	mov    rax,QWORD PTR [rip+0xb656]        # 11100 <stderr@GLIBC_2.2.5>
    5aaa:	4c 8d 05 6f 88 00 00 	lea    r8,[rip+0x886f]        # e320 <__func__.3>
    5ab1:	b9 37 00 00 00       	mov    ecx,0x37
    5ab6:	48 8d 15 87 85 00 00 	lea    rdx,[rip+0x8587]        # e044 <_IO_stdin_used+0x44>
    5abd:	48 8d 35 8c 85 00 00 	lea    rsi,[rip+0x858c]        # e050 <_IO_stdin_used+0x50>
    5ac4:	48 89 c7             	mov    rdi,rax
    5ac7:	b8 00 00 00 00       	mov    eax,0x0
    5acc:	e8 8f c9 ff ff       	call   2460 <fprintf@plt>
    5ad1:	bf 00 00 00 00       	mov    edi,0x0
    5ad6:	e8 45 ca ff ff       	call   2520 <exit@plt>
    5adb:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    5ae2:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    5ae6:	8b 85 e4 fd ff ff    	mov    eax,DWORD PTR [rbp-0x21c]
    5aec:	48 98                	cdqe   
    5aee:	48 c1 e0 03          	shl    rax,0x3
    5af2:	48 01 d0             	add    rax,rdx
    5af5:	48 8b 08             	mov    rcx,QWORD PTR [rax]
    5af8:	8b 95 e4 fd ff ff    	mov    edx,DWORD PTR [rbp-0x21c]
    5afe:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    5b05:	48 8d 35 6a 86 00 00 	lea    rsi,[rip+0x866a]        # e176 <_IO_stdin_used+0x176>
    5b0c:	48 89 c7             	mov    rdi,rax
    5b0f:	b8 00 00 00 00       	mov    eax,0x0
    5b14:	e8 47 c9 ff ff       	call   2460 <fprintf@plt>
    5b19:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    5b20:	48 89 c7             	mov    rdi,rax
    5b23:	e8 68 c9 ff ff       	call   2490 <fflush@plt>
    5b28:	0f b6 05 61 b5 00 00 	movzx  eax,BYTE PTR [rip+0xb561]        # 11090 <is_parallel_nb@@Base>
    5b2f:	84 c0                	test   al,al
    5b31:	0f 84 01 01 00 00    	je     5c38 <TEST_permutation_t_float_trans____1+0x2489>
    5b37:	e8 14 c9 ff ff       	call   2450 <id_of_thread_executed@plt>
    5b3c:	48 89 85 18 ff ff ff 	mov    QWORD PTR [rbp-0xe8],rax
    5b43:	0f b6 05 d6 b4 00 00 	movzx  eax,BYTE PTR [rip+0xb4d6]        # 11020 <log_parallel@@Base>
    5b4a:	84 c0                	test   al,al
    5b4c:	74 76                	je     5bc4 <TEST_permutation_t_float_trans____1+0x2415>
    5b4e:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5b55:	48 8b 15 cc b4 00 00 	mov    rdx,QWORD PTR [rip+0xb4cc]        # 11028 <stdout@GLIBC_2.2.5>
    5b5c:	48 89 d6             	mov    rsi,rdx
    5b5f:	48 89 c7             	mov    rdi,rax
    5b62:	e8 79 c8 ff ff       	call   23e0 <fputs@plt>
    5b67:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    5b6e:	00 
    5b6f:	0f 88 30 01 00 00    	js     5ca5 <TEST_permutation_t_float_trans____1+0x24f6>
    5b75:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5b7c:	48 8b 0d ad b4 00 00 	mov    rcx,QWORD PTR [rip+0xb4ad]        # 11030 <f_ou_th@@Base>
    5b83:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    5b8a:	48 c1 e2 03          	shl    rdx,0x3
    5b8e:	48 01 ca             	add    rdx,rcx
    5b91:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5b94:	48 89 d6             	mov    rsi,rdx
    5b97:	48 89 c7             	mov    rdi,rax
    5b9a:	e8 41 c8 ff ff       	call   23e0 <fputs@plt>
    5b9f:	48 8b 15 8a b4 00 00 	mov    rdx,QWORD PTR [rip+0xb48a]        # 11030 <f_ou_th@@Base>
    5ba6:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    5bad:	48 c1 e0 03          	shl    rax,0x3
    5bb1:	48 01 d0             	add    rax,rdx
    5bb4:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5bb7:	48 89 c7             	mov    rdi,rax
    5bba:	e8 d1 c8 ff ff       	call   2490 <fflush@plt>
    5bbf:	e9 e1 00 00 00       	jmp    5ca5 <TEST_permutation_t_float_trans____1+0x24f6>
    5bc4:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    5bcb:	00 
    5bcc:	78 4f                	js     5c1d <TEST_permutation_t_float_trans____1+0x246e>
    5bce:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5bd5:	48 8b 0d 54 b4 00 00 	mov    rcx,QWORD PTR [rip+0xb454]        # 11030 <f_ou_th@@Base>
    5bdc:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    5be3:	48 c1 e2 03          	shl    rdx,0x3
    5be7:	48 01 ca             	add    rdx,rcx
    5bea:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5bed:	48 89 d6             	mov    rsi,rdx
    5bf0:	48 89 c7             	mov    rdi,rax
    5bf3:	e8 e8 c7 ff ff       	call   23e0 <fputs@plt>
    5bf8:	48 8b 15 31 b4 00 00 	mov    rdx,QWORD PTR [rip+0xb431]        # 11030 <f_ou_th@@Base>
    5bff:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    5c06:	48 c1 e0 03          	shl    rax,0x3
    5c0a:	48 01 d0             	add    rax,rdx
    5c0d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5c10:	48 89 c7             	mov    rdi,rax
    5c13:	e8 78 c8 ff ff       	call   2490 <fflush@plt>
    5c18:	e9 88 00 00 00       	jmp    5ca5 <TEST_permutation_t_float_trans____1+0x24f6>
    5c1d:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5c24:	48 8b 15 fd b3 00 00 	mov    rdx,QWORD PTR [rip+0xb3fd]        # 11028 <stdout@GLIBC_2.2.5>
    5c2b:	48 89 d6             	mov    rsi,rdx
    5c2e:	48 89 c7             	mov    rdi,rax
    5c31:	e8 aa c7 ff ff       	call   23e0 <fputs@plt>
    5c36:	eb 6d                	jmp    5ca5 <TEST_permutation_t_float_trans____1+0x24f6>
    5c38:	48 8b 05 f9 b3 00 00 	mov    rax,QWORD PTR [rip+0xb3f9]        # 11038 <savelog@@Base>
    5c3f:	48 85 c0             	test   rax,rax
    5c42:	74 48                	je     5c8c <TEST_permutation_t_float_trans____1+0x24dd>
    5c44:	48 8b 05 ed b3 00 00 	mov    rax,QWORD PTR [rip+0xb3ed]        # 11038 <savelog@@Base>
    5c4b:	48 8d 15 2d 84 00 00 	lea    rdx,[rip+0x842d]        # e07f <_IO_stdin_used+0x7f>
    5c52:	48 89 d6             	mov    rsi,rdx
    5c55:	48 89 c7             	mov    rdi,rax
    5c58:	e8 a3 c8 ff ff       	call   2500 <fopen@plt>
    5c5d:	48 89 85 10 ff ff ff 	mov    QWORD PTR [rbp-0xf0],rax
    5c64:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5c6b:	48 8b 95 10 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xf0]
    5c72:	48 89 d6             	mov    rsi,rdx
    5c75:	48 89 c7             	mov    rdi,rax
    5c78:	e8 63 c7 ff ff       	call   23e0 <fputs@plt>
    5c7d:	48 8b 85 10 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf0]
    5c84:	48 89 c7             	mov    rdi,rax
    5c87:	e8 24 c7 ff ff       	call   23b0 <fclose@plt>
    5c8c:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5c93:	48 8b 15 8e b3 00 00 	mov    rdx,QWORD PTR [rip+0xb38e]        # 11028 <stdout@GLIBC_2.2.5>
    5c9a:	48 89 d6             	mov    rsi,rdx
    5c9d:	48 89 c7             	mov    rdi,rax
    5ca0:	e8 3b c7 ff ff       	call   23e0 <fputs@plt>
    5ca5:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    5cac:	48 89 c7             	mov    rdi,rax
    5caf:	e8 fc c6 ff ff       	call   23b0 <fclose@plt>
    5cb4:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5cbb:	48 89 c7             	mov    rdi,rax
    5cbe:	e8 6d c6 ff ff       	call   2330 <free@plt>
    5cc3:	83 85 e4 fd ff ff 01 	add    DWORD PTR [rbp-0x21c],0x1
    5cca:	8b 85 e4 fd ff ff    	mov    eax,DWORD PTR [rbp-0x21c]
    5cd0:	48 63 d0             	movsxd rdx,eax
    5cd3:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    5cda:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5cdd:	48 39 c2             	cmp    rdx,rax
    5ce0:	0f 82 93 fd ff ff    	jb     5a79 <TEST_permutation_t_float_trans____1+0x22ca>
    5ce6:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    5ced:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    5cf4:	48 89 d6             	mov    rsi,rdx
    5cf7:	48 89 c7             	mov    rdi,rax
    5cfa:	e8 51 c6 ff ff       	call   2350 <open_memstream@plt>
    5cff:	48 89 85 c0 fe ff ff 	mov    QWORD PTR [rbp-0x140],rax
    5d06:	48 83 bd c0 fe ff ff 	cmp    QWORD PTR [rbp-0x140],0x0
    5d0d:	00 
    5d0e:	75 38                	jne    5d48 <TEST_permutation_t_float_trans____1+0x2599>
    5d10:	48 8b 05 e9 b3 00 00 	mov    rax,QWORD PTR [rip+0xb3e9]        # 11100 <stderr@GLIBC_2.2.5>
    5d17:	4c 8d 05 02 86 00 00 	lea    r8,[rip+0x8602]        # e320 <__func__.3>
    5d1e:	b9 38 00 00 00       	mov    ecx,0x38
    5d23:	48 8d 15 1a 83 00 00 	lea    rdx,[rip+0x831a]        # e044 <_IO_stdin_used+0x44>
    5d2a:	48 8d 35 1f 83 00 00 	lea    rsi,[rip+0x831f]        # e050 <_IO_stdin_used+0x50>
    5d31:	48 89 c7             	mov    rdi,rax
    5d34:	b8 00 00 00 00       	mov    eax,0x0
    5d39:	e8 22 c7 ff ff       	call   2460 <fprintf@plt>
    5d3e:	bf 00 00 00 00       	mov    edi,0x0
    5d43:	e8 d8 c7 ff ff       	call   2520 <exit@plt>
    5d48:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    5d4f:	48 89 c6             	mov    rsi,rax
    5d52:	bf 0a 00 00 00       	mov    edi,0xa
    5d57:	e8 c4 c6 ff ff       	call   2420 <fputc@plt>
    5d5c:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    5d63:	48 89 c7             	mov    rdi,rax
    5d66:	e8 25 c7 ff ff       	call   2490 <fflush@plt>
    5d6b:	0f b6 05 1e b3 00 00 	movzx  eax,BYTE PTR [rip+0xb31e]        # 11090 <is_parallel_nb@@Base>
    5d72:	84 c0                	test   al,al
    5d74:	0f 84 01 01 00 00    	je     5e7b <TEST_permutation_t_float_trans____1+0x26cc>
    5d7a:	e8 d1 c6 ff ff       	call   2450 <id_of_thread_executed@plt>
    5d7f:	48 89 85 d0 fe ff ff 	mov    QWORD PTR [rbp-0x130],rax
    5d86:	0f b6 05 93 b2 00 00 	movzx  eax,BYTE PTR [rip+0xb293]        # 11020 <log_parallel@@Base>
    5d8d:	84 c0                	test   al,al
    5d8f:	74 76                	je     5e07 <TEST_permutation_t_float_trans____1+0x2658>
    5d91:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5d98:	48 8b 15 89 b2 00 00 	mov    rdx,QWORD PTR [rip+0xb289]        # 11028 <stdout@GLIBC_2.2.5>
    5d9f:	48 89 d6             	mov    rsi,rdx
    5da2:	48 89 c7             	mov    rdi,rax
    5da5:	e8 36 c6 ff ff       	call   23e0 <fputs@plt>
    5daa:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    5db1:	00 
    5db2:	0f 88 30 01 00 00    	js     5ee8 <TEST_permutation_t_float_trans____1+0x2739>
    5db8:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5dbf:	48 8b 0d 6a b2 00 00 	mov    rcx,QWORD PTR [rip+0xb26a]        # 11030 <f_ou_th@@Base>
    5dc6:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    5dcd:	48 c1 e2 03          	shl    rdx,0x3
    5dd1:	48 01 ca             	add    rdx,rcx
    5dd4:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5dd7:	48 89 d6             	mov    rsi,rdx
    5dda:	48 89 c7             	mov    rdi,rax
    5ddd:	e8 fe c5 ff ff       	call   23e0 <fputs@plt>
    5de2:	48 8b 15 47 b2 00 00 	mov    rdx,QWORD PTR [rip+0xb247]        # 11030 <f_ou_th@@Base>
    5de9:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    5df0:	48 c1 e0 03          	shl    rax,0x3
    5df4:	48 01 d0             	add    rax,rdx
    5df7:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5dfa:	48 89 c7             	mov    rdi,rax
    5dfd:	e8 8e c6 ff ff       	call   2490 <fflush@plt>
    5e02:	e9 e1 00 00 00       	jmp    5ee8 <TEST_permutation_t_float_trans____1+0x2739>
    5e07:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    5e0e:	00 
    5e0f:	78 4f                	js     5e60 <TEST_permutation_t_float_trans____1+0x26b1>
    5e11:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5e18:	48 8b 0d 11 b2 00 00 	mov    rcx,QWORD PTR [rip+0xb211]        # 11030 <f_ou_th@@Base>
    5e1f:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    5e26:	48 c1 e2 03          	shl    rdx,0x3
    5e2a:	48 01 ca             	add    rdx,rcx
    5e2d:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    5e30:	48 89 d6             	mov    rsi,rdx
    5e33:	48 89 c7             	mov    rdi,rax
    5e36:	e8 a5 c5 ff ff       	call   23e0 <fputs@plt>
    5e3b:	48 8b 15 ee b1 00 00 	mov    rdx,QWORD PTR [rip+0xb1ee]        # 11030 <f_ou_th@@Base>
    5e42:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    5e49:	48 c1 e0 03          	shl    rax,0x3
    5e4d:	48 01 d0             	add    rax,rdx
    5e50:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5e53:	48 89 c7             	mov    rdi,rax
    5e56:	e8 35 c6 ff ff       	call   2490 <fflush@plt>
    5e5b:	e9 88 00 00 00       	jmp    5ee8 <TEST_permutation_t_float_trans____1+0x2739>
    5e60:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5e67:	48 8b 15 ba b1 00 00 	mov    rdx,QWORD PTR [rip+0xb1ba]        # 11028 <stdout@GLIBC_2.2.5>
    5e6e:	48 89 d6             	mov    rsi,rdx
    5e71:	48 89 c7             	mov    rdi,rax
    5e74:	e8 67 c5 ff ff       	call   23e0 <fputs@plt>
    5e79:	eb 6d                	jmp    5ee8 <TEST_permutation_t_float_trans____1+0x2739>
    5e7b:	48 8b 05 b6 b1 00 00 	mov    rax,QWORD PTR [rip+0xb1b6]        # 11038 <savelog@@Base>
    5e82:	48 85 c0             	test   rax,rax
    5e85:	74 48                	je     5ecf <TEST_permutation_t_float_trans____1+0x2720>
    5e87:	48 8b 05 aa b1 00 00 	mov    rax,QWORD PTR [rip+0xb1aa]        # 11038 <savelog@@Base>
    5e8e:	48 8d 15 ea 81 00 00 	lea    rdx,[rip+0x81ea]        # e07f <_IO_stdin_used+0x7f>
    5e95:	48 89 d6             	mov    rsi,rdx
    5e98:	48 89 c7             	mov    rdi,rax
    5e9b:	e8 60 c6 ff ff       	call   2500 <fopen@plt>
    5ea0:	48 89 85 c8 fe ff ff 	mov    QWORD PTR [rbp-0x138],rax
    5ea7:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5eae:	48 8b 95 c8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x138]
    5eb5:	48 89 d6             	mov    rsi,rdx
    5eb8:	48 89 c7             	mov    rdi,rax
    5ebb:	e8 20 c5 ff ff       	call   23e0 <fputs@plt>
    5ec0:	48 8b 85 c8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x138]
    5ec7:	48 89 c7             	mov    rdi,rax
    5eca:	e8 e1 c4 ff ff       	call   23b0 <fclose@plt>
    5ecf:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5ed6:	48 8b 15 4b b1 00 00 	mov    rdx,QWORD PTR [rip+0xb14b]        # 11028 <stdout@GLIBC_2.2.5>
    5edd:	48 89 d6             	mov    rsi,rdx
    5ee0:	48 89 c7             	mov    rdi,rax
    5ee3:	e8 f8 c4 ff ff       	call   23e0 <fputs@plt>
    5ee8:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    5eef:	48 89 c7             	mov    rdi,rax
    5ef2:	e8 b9 c4 ff ff       	call   23b0 <fclose@plt>
    5ef7:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    5efe:	48 89 c7             	mov    rdi,rax
    5f01:	e8 2a c4 ff ff       	call   2330 <free@plt>
    5f06:	c7 85 e8 fd ff ff 00 	mov    DWORD PTR [rbp-0x218],0x0
    5f0d:	00 00 00 
    5f10:	e9 67 02 00 00       	jmp    617c <TEST_permutation_t_float_trans____1+0x29cd>
    5f15:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    5f1c:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    5f23:	48 89 d6             	mov    rsi,rdx
    5f26:	48 89 c7             	mov    rdi,rax
    5f29:	e8 22 c4 ff ff       	call   2350 <open_memstream@plt>
    5f2e:	48 89 85 f0 fe ff ff 	mov    QWORD PTR [rbp-0x110],rax
    5f35:	48 83 bd f0 fe ff ff 	cmp    QWORD PTR [rbp-0x110],0x0
    5f3c:	00 
    5f3d:	75 38                	jne    5f77 <TEST_permutation_t_float_trans____1+0x27c8>
    5f3f:	48 8b 05 ba b1 00 00 	mov    rax,QWORD PTR [rip+0xb1ba]        # 11100 <stderr@GLIBC_2.2.5>
    5f46:	4c 8d 05 d3 83 00 00 	lea    r8,[rip+0x83d3]        # e320 <__func__.3>
    5f4d:	b9 39 00 00 00       	mov    ecx,0x39
    5f52:	48 8d 15 eb 80 00 00 	lea    rdx,[rip+0x80eb]        # e044 <_IO_stdin_used+0x44>
    5f59:	48 8d 35 f0 80 00 00 	lea    rsi,[rip+0x80f0]        # e050 <_IO_stdin_used+0x50>
    5f60:	48 89 c7             	mov    rdi,rax
    5f63:	b8 00 00 00 00       	mov    eax,0x0
    5f68:	e8 f3 c4 ff ff       	call   2460 <fprintf@plt>
    5f6d:	bf 00 00 00 00       	mov    edi,0x0
    5f72:	e8 a9 c5 ff ff       	call   2520 <exit@plt>
    5f77:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    5f7e:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    5f82:	8b 85 e8 fd ff ff    	mov    eax,DWORD PTR [rbp-0x218]
    5f88:	48 98                	cdqe   
    5f8a:	48 c1 e0 02          	shl    rax,0x2
    5f8e:	48 01 d0             	add    rax,rdx
    5f91:	f3 0f 10 00          	movss  xmm0,DWORD PTR [rax]
    5f95:	66 0f ef c9          	pxor   xmm1,xmm1
    5f99:	f3 0f 5a c8          	cvtss2sd xmm1,xmm0
    5f9d:	66 48 0f 7e c9       	movq   rcx,xmm1
    5fa2:	8b 95 e8 fd ff ff    	mov    edx,DWORD PTR [rbp-0x218]
    5fa8:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    5faf:	66 48 0f 6e c1       	movq   xmm0,rcx
    5fb4:	48 8d 0d c9 81 00 00 	lea    rcx,[rip+0x81c9]        # e184 <_IO_stdin_used+0x184>
    5fbb:	48 89 ce             	mov    rsi,rcx
    5fbe:	48 89 c7             	mov    rdi,rax
    5fc1:	b8 01 00 00 00       	mov    eax,0x1
    5fc6:	e8 95 c4 ff ff       	call   2460 <fprintf@plt>
    5fcb:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    5fd2:	48 89 c7             	mov    rdi,rax
    5fd5:	e8 b6 c4 ff ff       	call   2490 <fflush@plt>
    5fda:	0f b6 05 af b0 00 00 	movzx  eax,BYTE PTR [rip+0xb0af]        # 11090 <is_parallel_nb@@Base>
    5fe1:	84 c0                	test   al,al
    5fe3:	0f 84 01 01 00 00    	je     60ea <TEST_permutation_t_float_trans____1+0x293b>
    5fe9:	e8 62 c4 ff ff       	call   2450 <id_of_thread_executed@plt>
    5fee:	48 89 85 00 ff ff ff 	mov    QWORD PTR [rbp-0x100],rax
    5ff5:	0f b6 05 24 b0 00 00 	movzx  eax,BYTE PTR [rip+0xb024]        # 11020 <log_parallel@@Base>
    5ffc:	84 c0                	test   al,al
    5ffe:	74 76                	je     6076 <TEST_permutation_t_float_trans____1+0x28c7>
    6000:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6007:	48 8b 15 1a b0 00 00 	mov    rdx,QWORD PTR [rip+0xb01a]        # 11028 <stdout@GLIBC_2.2.5>
    600e:	48 89 d6             	mov    rsi,rdx
    6011:	48 89 c7             	mov    rdi,rax
    6014:	e8 c7 c3 ff ff       	call   23e0 <fputs@plt>
    6019:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    6020:	00 
    6021:	0f 88 30 01 00 00    	js     6157 <TEST_permutation_t_float_trans____1+0x29a8>
    6027:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    602e:	48 8b 0d fb af 00 00 	mov    rcx,QWORD PTR [rip+0xaffb]        # 11030 <f_ou_th@@Base>
    6035:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    603c:	48 c1 e2 03          	shl    rdx,0x3
    6040:	48 01 ca             	add    rdx,rcx
    6043:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6046:	48 89 d6             	mov    rsi,rdx
    6049:	48 89 c7             	mov    rdi,rax
    604c:	e8 8f c3 ff ff       	call   23e0 <fputs@plt>
    6051:	48 8b 15 d8 af 00 00 	mov    rdx,QWORD PTR [rip+0xafd8]        # 11030 <f_ou_th@@Base>
    6058:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    605f:	48 c1 e0 03          	shl    rax,0x3
    6063:	48 01 d0             	add    rax,rdx
    6066:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6069:	48 89 c7             	mov    rdi,rax
    606c:	e8 1f c4 ff ff       	call   2490 <fflush@plt>
    6071:	e9 e1 00 00 00       	jmp    6157 <TEST_permutation_t_float_trans____1+0x29a8>
    6076:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    607d:	00 
    607e:	78 4f                	js     60cf <TEST_permutation_t_float_trans____1+0x2920>
    6080:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6087:	48 8b 0d a2 af 00 00 	mov    rcx,QWORD PTR [rip+0xafa2]        # 11030 <f_ou_th@@Base>
    608e:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    6095:	48 c1 e2 03          	shl    rdx,0x3
    6099:	48 01 ca             	add    rdx,rcx
    609c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    609f:	48 89 d6             	mov    rsi,rdx
    60a2:	48 89 c7             	mov    rdi,rax
    60a5:	e8 36 c3 ff ff       	call   23e0 <fputs@plt>
    60aa:	48 8b 15 7f af 00 00 	mov    rdx,QWORD PTR [rip+0xaf7f]        # 11030 <f_ou_th@@Base>
    60b1:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    60b8:	48 c1 e0 03          	shl    rax,0x3
    60bc:	48 01 d0             	add    rax,rdx
    60bf:	48 8b 00             	mov    rax,QWORD PTR [rax]
    60c2:	48 89 c7             	mov    rdi,rax
    60c5:	e8 c6 c3 ff ff       	call   2490 <fflush@plt>
    60ca:	e9 88 00 00 00       	jmp    6157 <TEST_permutation_t_float_trans____1+0x29a8>
    60cf:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    60d6:	48 8b 15 4b af 00 00 	mov    rdx,QWORD PTR [rip+0xaf4b]        # 11028 <stdout@GLIBC_2.2.5>
    60dd:	48 89 d6             	mov    rsi,rdx
    60e0:	48 89 c7             	mov    rdi,rax
    60e3:	e8 f8 c2 ff ff       	call   23e0 <fputs@plt>
    60e8:	eb 6d                	jmp    6157 <TEST_permutation_t_float_trans____1+0x29a8>
    60ea:	48 8b 05 47 af 00 00 	mov    rax,QWORD PTR [rip+0xaf47]        # 11038 <savelog@@Base>
    60f1:	48 85 c0             	test   rax,rax
    60f4:	74 48                	je     613e <TEST_permutation_t_float_trans____1+0x298f>
    60f6:	48 8b 05 3b af 00 00 	mov    rax,QWORD PTR [rip+0xaf3b]        # 11038 <savelog@@Base>
    60fd:	48 8d 15 7b 7f 00 00 	lea    rdx,[rip+0x7f7b]        # e07f <_IO_stdin_used+0x7f>
    6104:	48 89 d6             	mov    rsi,rdx
    6107:	48 89 c7             	mov    rdi,rax
    610a:	e8 f1 c3 ff ff       	call   2500 <fopen@plt>
    610f:	48 89 85 f8 fe ff ff 	mov    QWORD PTR [rbp-0x108],rax
    6116:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    611d:	48 8b 95 f8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x108]
    6124:	48 89 d6             	mov    rsi,rdx
    6127:	48 89 c7             	mov    rdi,rax
    612a:	e8 b1 c2 ff ff       	call   23e0 <fputs@plt>
    612f:	48 8b 85 f8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x108]
    6136:	48 89 c7             	mov    rdi,rax
    6139:	e8 72 c2 ff ff       	call   23b0 <fclose@plt>
    613e:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6145:	48 8b 15 dc ae 00 00 	mov    rdx,QWORD PTR [rip+0xaedc]        # 11028 <stdout@GLIBC_2.2.5>
    614c:	48 89 d6             	mov    rsi,rdx
    614f:	48 89 c7             	mov    rdi,rax
    6152:	e8 89 c2 ff ff       	call   23e0 <fputs@plt>
    6157:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    615e:	48 89 c7             	mov    rdi,rax
    6161:	e8 4a c2 ff ff       	call   23b0 <fclose@plt>
    6166:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    616d:	48 89 c7             	mov    rdi,rax
    6170:	e8 bb c1 ff ff       	call   2330 <free@plt>
    6175:	83 85 e8 fd ff ff 01 	add    DWORD PTR [rbp-0x218],0x1
    617c:	8b 85 e8 fd ff ff    	mov    eax,DWORD PTR [rbp-0x218]
    6182:	48 63 d0             	movsxd rdx,eax
    6185:	48 8b 85 08 fe ff ff 	mov    rax,QWORD PTR [rbp-0x1f8]
    618c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    618f:	48 39 c2             	cmp    rdx,rax
    6192:	0f 82 7d fd ff ff    	jb     5f15 <TEST_permutation_t_float_trans____1+0x2766>
    6198:	48 8d 95 f0 fd ff ff 	lea    rdx,[rbp-0x210]
    619f:	48 8d 85 f8 fd ff ff 	lea    rax,[rbp-0x208]
    61a6:	48 89 d6             	mov    rsi,rdx
    61a9:	48 89 c7             	mov    rdi,rax
    61ac:	e8 9f c1 ff ff       	call   2350 <open_memstream@plt>
    61b1:	48 89 85 d8 fe ff ff 	mov    QWORD PTR [rbp-0x128],rax
    61b8:	48 83 bd d8 fe ff ff 	cmp    QWORD PTR [rbp-0x128],0x0
    61bf:	00 
    61c0:	75 38                	jne    61fa <TEST_permutation_t_float_trans____1+0x2a4b>
    61c2:	48 8b 05 37 af 00 00 	mov    rax,QWORD PTR [rip+0xaf37]        # 11100 <stderr@GLIBC_2.2.5>
    61c9:	4c 8d 05 50 81 00 00 	lea    r8,[rip+0x8150]        # e320 <__func__.3>
    61d0:	b9 3a 00 00 00       	mov    ecx,0x3a
    61d5:	48 8d 15 68 7e 00 00 	lea    rdx,[rip+0x7e68]        # e044 <_IO_stdin_used+0x44>
    61dc:	48 8d 35 6d 7e 00 00 	lea    rsi,[rip+0x7e6d]        # e050 <_IO_stdin_used+0x50>
    61e3:	48 89 c7             	mov    rdi,rax
    61e6:	b8 00 00 00 00       	mov    eax,0x0
    61eb:	e8 70 c2 ff ff       	call   2460 <fprintf@plt>
    61f0:	bf 00 00 00 00       	mov    edi,0x0
    61f5:	e8 26 c3 ff ff       	call   2520 <exit@plt>
    61fa:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    6201:	48 89 c6             	mov    rsi,rax
    6204:	bf 0a 00 00 00       	mov    edi,0xa
    6209:	e8 12 c2 ff ff       	call   2420 <fputc@plt>
    620e:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    6215:	48 89 c7             	mov    rdi,rax
    6218:	e8 73 c2 ff ff       	call   2490 <fflush@plt>
    621d:	0f b6 05 6c ae 00 00 	movzx  eax,BYTE PTR [rip+0xae6c]        # 11090 <is_parallel_nb@@Base>
    6224:	84 c0                	test   al,al
    6226:	0f 84 01 01 00 00    	je     632d <TEST_permutation_t_float_trans____1+0x2b7e>
    622c:	e8 1f c2 ff ff       	call   2450 <id_of_thread_executed@plt>
    6231:	48 89 85 e8 fe ff ff 	mov    QWORD PTR [rbp-0x118],rax
    6238:	0f b6 05 e1 ad 00 00 	movzx  eax,BYTE PTR [rip+0xade1]        # 11020 <log_parallel@@Base>
    623f:	84 c0                	test   al,al
    6241:	74 76                	je     62b9 <TEST_permutation_t_float_trans____1+0x2b0a>
    6243:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    624a:	48 8b 15 d7 ad 00 00 	mov    rdx,QWORD PTR [rip+0xadd7]        # 11028 <stdout@GLIBC_2.2.5>
    6251:	48 89 d6             	mov    rsi,rdx
    6254:	48 89 c7             	mov    rdi,rax
    6257:	e8 84 c1 ff ff       	call   23e0 <fputs@plt>
    625c:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    6263:	00 
    6264:	0f 88 30 01 00 00    	js     639a <TEST_permutation_t_float_trans____1+0x2beb>
    626a:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6271:	48 8b 0d b8 ad 00 00 	mov    rcx,QWORD PTR [rip+0xadb8]        # 11030 <f_ou_th@@Base>
    6278:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    627f:	48 c1 e2 03          	shl    rdx,0x3
    6283:	48 01 ca             	add    rdx,rcx
    6286:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6289:	48 89 d6             	mov    rsi,rdx
    628c:	48 89 c7             	mov    rdi,rax
    628f:	e8 4c c1 ff ff       	call   23e0 <fputs@plt>
    6294:	48 8b 15 95 ad 00 00 	mov    rdx,QWORD PTR [rip+0xad95]        # 11030 <f_ou_th@@Base>
    629b:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    62a2:	48 c1 e0 03          	shl    rax,0x3
    62a6:	48 01 d0             	add    rax,rdx
    62a9:	48 8b 00             	mov    rax,QWORD PTR [rax]
    62ac:	48 89 c7             	mov    rdi,rax
    62af:	e8 dc c1 ff ff       	call   2490 <fflush@plt>
    62b4:	e9 e1 00 00 00       	jmp    639a <TEST_permutation_t_float_trans____1+0x2beb>
    62b9:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    62c0:	00 
    62c1:	78 4f                	js     6312 <TEST_permutation_t_float_trans____1+0x2b63>
    62c3:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    62ca:	48 8b 0d 5f ad 00 00 	mov    rcx,QWORD PTR [rip+0xad5f]        # 11030 <f_ou_th@@Base>
    62d1:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    62d8:	48 c1 e2 03          	shl    rdx,0x3
    62dc:	48 01 ca             	add    rdx,rcx
    62df:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    62e2:	48 89 d6             	mov    rsi,rdx
    62e5:	48 89 c7             	mov    rdi,rax
    62e8:	e8 f3 c0 ff ff       	call   23e0 <fputs@plt>
    62ed:	48 8b 15 3c ad 00 00 	mov    rdx,QWORD PTR [rip+0xad3c]        # 11030 <f_ou_th@@Base>
    62f4:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    62fb:	48 c1 e0 03          	shl    rax,0x3
    62ff:	48 01 d0             	add    rax,rdx
    6302:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6305:	48 89 c7             	mov    rdi,rax
    6308:	e8 83 c1 ff ff       	call   2490 <fflush@plt>
    630d:	e9 88 00 00 00       	jmp    639a <TEST_permutation_t_float_trans____1+0x2beb>
    6312:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6319:	48 8b 15 08 ad 00 00 	mov    rdx,QWORD PTR [rip+0xad08]        # 11028 <stdout@GLIBC_2.2.5>
    6320:	48 89 d6             	mov    rsi,rdx
    6323:	48 89 c7             	mov    rdi,rax
    6326:	e8 b5 c0 ff ff       	call   23e0 <fputs@plt>
    632b:	eb 6d                	jmp    639a <TEST_permutation_t_float_trans____1+0x2beb>
    632d:	48 8b 05 04 ad 00 00 	mov    rax,QWORD PTR [rip+0xad04]        # 11038 <savelog@@Base>
    6334:	48 85 c0             	test   rax,rax
    6337:	74 48                	je     6381 <TEST_permutation_t_float_trans____1+0x2bd2>
    6339:	48 8b 05 f8 ac 00 00 	mov    rax,QWORD PTR [rip+0xacf8]        # 11038 <savelog@@Base>
    6340:	48 8d 15 38 7d 00 00 	lea    rdx,[rip+0x7d38]        # e07f <_IO_stdin_used+0x7f>
    6347:	48 89 d6             	mov    rsi,rdx
    634a:	48 89 c7             	mov    rdi,rax
    634d:	e8 ae c1 ff ff       	call   2500 <fopen@plt>
    6352:	48 89 85 e0 fe ff ff 	mov    QWORD PTR [rbp-0x120],rax
    6359:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6360:	48 8b 95 e0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x120]
    6367:	48 89 d6             	mov    rsi,rdx
    636a:	48 89 c7             	mov    rdi,rax
    636d:	e8 6e c0 ff ff       	call   23e0 <fputs@plt>
    6372:	48 8b 85 e0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x120]
    6379:	48 89 c7             	mov    rdi,rax
    637c:	e8 2f c0 ff ff       	call   23b0 <fclose@plt>
    6381:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    6388:	48 8b 15 99 ac 00 00 	mov    rdx,QWORD PTR [rip+0xac99]        # 11028 <stdout@GLIBC_2.2.5>
    638f:	48 89 d6             	mov    rsi,rdx
    6392:	48 89 c7             	mov    rdi,rax
    6395:	e8 46 c0 ff ff       	call   23e0 <fputs@plt>
    639a:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    63a1:	48 89 c7             	mov    rdi,rax
    63a4:	e8 07 c0 ff ff       	call   23b0 <fclose@plt>
    63a9:	48 8b 85 f8 fd ff ff 	mov    rax,QWORD PTR [rbp-0x208]
    63b0:	48 89 c7             	mov    rdi,rax
    63b3:	e8 78 bf ff ff       	call   2330 <free@plt>
    63b8:	90                   	nop
    63b9:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    63bd:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
    63c4:	00 00 
    63c6:	74 05                	je     63cd <TEST_permutation_t_float_trans____1+0x2c1e>
    63c8:	e8 f3 bf ff ff       	call   23c0 <__stack_chk_fail@plt>
    63cd:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    63d1:	c9                   	leave  
    63d2:	c3                   	ret    

00000000000063d3 <append_test_not_permutation_2>:
    63d3:	f3 0f 1e fa          	endbr64 
    63d7:	55                   	push   rbp
    63d8:	48 89 e5             	mov    rbp,rsp
    63db:	48 8d 05 ae 7d 00 00 	lea    rax,[rip+0x7dae]        # e190 <_IO_stdin_used+0x190>
    63e2:	48 89 c6             	mov    rsi,rax
    63e5:	48 8d 05 0a 00 00 00 	lea    rax,[rip+0xa]        # 63f6 <TEST_not_permutation_____2>
    63ec:	48 89 c7             	mov    rdi,rax
    63ef:	e8 4c bf ff ff       	call   2340 <append_func@plt>
    63f4:	5d                   	pop    rbp
    63f5:	c3                   	ret    

00000000000063f6 <TEST_not_permutation_____2>:
    63f6:	f3 0f 1e fa          	endbr64 
    63fa:	55                   	push   rbp
    63fb:	48 89 e5             	mov    rbp,rsp
    63fe:	53                   	push   rbx
    63ff:	48 81 ec 78 01 00 00 	sub    rsp,0x178
    6406:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    640d:	00 00 
    640f:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    6413:	31 c0                	xor    eax,eax
    6415:	c7 85 8c fe ff ff 08 	mov    DWORD PTR [rbp-0x174],0x8
    641c:	00 00 00 
    641f:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    6425:	48 98                	cdqe   
    6427:	48 89 c7             	mov    rdi,rax
    642a:	e8 e2 5e 00 00       	call   c311 <CREATE_PERMUTATION_TYPE_FLOAT>
    642f:	48 89 85 a0 fe ff ff 	mov    QWORD PTR [rbp-0x160],rax
    6436:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    643d:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    6444:	48 89 d6             	mov    rsi,rdx
    6447:	48 89 c7             	mov    rdi,rax
    644a:	e8 01 bf ff ff       	call   2350 <open_memstream@plt>
    644f:	48 89 85 a8 fe ff ff 	mov    QWORD PTR [rbp-0x158],rax
    6456:	48 83 bd a8 fe ff ff 	cmp    QWORD PTR [rbp-0x158],0x0
    645d:	00 
    645e:	75 38                	jne    6498 <TEST_not_permutation_____2+0xa2>
    6460:	48 8b 05 99 ac 00 00 	mov    rax,QWORD PTR [rip+0xac99]        # 11100 <stderr@GLIBC_2.2.5>
    6467:	4c 8d 05 e2 7e 00 00 	lea    r8,[rip+0x7ee2]        # e350 <__func__.2>
    646e:	b9 46 00 00 00       	mov    ecx,0x46
    6473:	48 8d 15 ca 7b 00 00 	lea    rdx,[rip+0x7bca]        # e044 <_IO_stdin_used+0x44>
    647a:	48 8d 35 cf 7b 00 00 	lea    rsi,[rip+0x7bcf]        # e050 <_IO_stdin_used+0x50>
    6481:	48 89 c7             	mov    rdi,rax
    6484:	b8 00 00 00 00       	mov    eax,0x0
    6489:	e8 d2 bf ff ff       	call   2460 <fprintf@plt>
    648e:	bf 00 00 00 00       	mov    edi,0x0
    6493:	e8 88 c0 ff ff       	call   2520 <exit@plt>
    6498:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    649f:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    64a2:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    64a9:	48 8d 0d c1 7b 00 00 	lea    rcx,[rip+0x7bc1]        # e071 <_IO_stdin_used+0x71>
    64b0:	48 89 ce             	mov    rsi,rcx
    64b3:	48 89 c7             	mov    rdi,rax
    64b6:	b8 00 00 00 00       	mov    eax,0x0
    64bb:	e8 a0 bf ff ff       	call   2460 <fprintf@plt>
    64c0:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    64c7:	48 89 c7             	mov    rdi,rax
    64ca:	e8 c1 bf ff ff       	call   2490 <fflush@plt>
    64cf:	0f b6 05 ba ab 00 00 	movzx  eax,BYTE PTR [rip+0xabba]        # 11090 <is_parallel_nb@@Base>
    64d6:	84 c0                	test   al,al
    64d8:	0f 84 01 01 00 00    	je     65df <TEST_not_permutation_____2+0x1e9>
    64de:	e8 6d bf ff ff       	call   2450 <id_of_thread_executed@plt>
    64e3:	48 89 85 b8 fe ff ff 	mov    QWORD PTR [rbp-0x148],rax
    64ea:	0f b6 05 2f ab 00 00 	movzx  eax,BYTE PTR [rip+0xab2f]        # 11020 <log_parallel@@Base>
    64f1:	84 c0                	test   al,al
    64f3:	74 76                	je     656b <TEST_not_permutation_____2+0x175>
    64f5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    64fc:	48 8b 15 25 ab 00 00 	mov    rdx,QWORD PTR [rip+0xab25]        # 11028 <stdout@GLIBC_2.2.5>
    6503:	48 89 d6             	mov    rsi,rdx
    6506:	48 89 c7             	mov    rdi,rax
    6509:	e8 d2 be ff ff       	call   23e0 <fputs@plt>
    650e:	48 83 bd b8 fe ff ff 	cmp    QWORD PTR [rbp-0x148],0x0
    6515:	00 
    6516:	0f 88 30 01 00 00    	js     664c <TEST_not_permutation_____2+0x256>
    651c:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6523:	48 8b 0d 06 ab 00 00 	mov    rcx,QWORD PTR [rip+0xab06]        # 11030 <f_ou_th@@Base>
    652a:	48 8b 95 b8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x148]
    6531:	48 c1 e2 03          	shl    rdx,0x3
    6535:	48 01 ca             	add    rdx,rcx
    6538:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    653b:	48 89 d6             	mov    rsi,rdx
    653e:	48 89 c7             	mov    rdi,rax
    6541:	e8 9a be ff ff       	call   23e0 <fputs@plt>
    6546:	48 8b 15 e3 aa 00 00 	mov    rdx,QWORD PTR [rip+0xaae3]        # 11030 <f_ou_th@@Base>
    654d:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    6554:	48 c1 e0 03          	shl    rax,0x3
    6558:	48 01 d0             	add    rax,rdx
    655b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    655e:	48 89 c7             	mov    rdi,rax
    6561:	e8 2a bf ff ff       	call   2490 <fflush@plt>
    6566:	e9 e1 00 00 00       	jmp    664c <TEST_not_permutation_____2+0x256>
    656b:	48 83 bd b8 fe ff ff 	cmp    QWORD PTR [rbp-0x148],0x0
    6572:	00 
    6573:	78 4f                	js     65c4 <TEST_not_permutation_____2+0x1ce>
    6575:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    657c:	48 8b 0d ad aa 00 00 	mov    rcx,QWORD PTR [rip+0xaaad]        # 11030 <f_ou_th@@Base>
    6583:	48 8b 95 b8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x148]
    658a:	48 c1 e2 03          	shl    rdx,0x3
    658e:	48 01 ca             	add    rdx,rcx
    6591:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6594:	48 89 d6             	mov    rsi,rdx
    6597:	48 89 c7             	mov    rdi,rax
    659a:	e8 41 be ff ff       	call   23e0 <fputs@plt>
    659f:	48 8b 15 8a aa 00 00 	mov    rdx,QWORD PTR [rip+0xaa8a]        # 11030 <f_ou_th@@Base>
    65a6:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    65ad:	48 c1 e0 03          	shl    rax,0x3
    65b1:	48 01 d0             	add    rax,rdx
    65b4:	48 8b 00             	mov    rax,QWORD PTR [rax]
    65b7:	48 89 c7             	mov    rdi,rax
    65ba:	e8 d1 be ff ff       	call   2490 <fflush@plt>
    65bf:	e9 88 00 00 00       	jmp    664c <TEST_not_permutation_____2+0x256>
    65c4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    65cb:	48 8b 15 56 aa 00 00 	mov    rdx,QWORD PTR [rip+0xaa56]        # 11028 <stdout@GLIBC_2.2.5>
    65d2:	48 89 d6             	mov    rsi,rdx
    65d5:	48 89 c7             	mov    rdi,rax
    65d8:	e8 03 be ff ff       	call   23e0 <fputs@plt>
    65dd:	eb 6d                	jmp    664c <TEST_not_permutation_____2+0x256>
    65df:	48 8b 05 52 aa 00 00 	mov    rax,QWORD PTR [rip+0xaa52]        # 11038 <savelog@@Base>
    65e6:	48 85 c0             	test   rax,rax
    65e9:	74 48                	je     6633 <TEST_not_permutation_____2+0x23d>
    65eb:	48 8b 05 46 aa 00 00 	mov    rax,QWORD PTR [rip+0xaa46]        # 11038 <savelog@@Base>
    65f2:	48 8d 15 86 7a 00 00 	lea    rdx,[rip+0x7a86]        # e07f <_IO_stdin_used+0x7f>
    65f9:	48 89 d6             	mov    rsi,rdx
    65fc:	48 89 c7             	mov    rdi,rax
    65ff:	e8 fc be ff ff       	call   2500 <fopen@plt>
    6604:	48 89 85 b0 fe ff ff 	mov    QWORD PTR [rbp-0x150],rax
    660b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6612:	48 8b 95 b0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x150]
    6619:	48 89 d6             	mov    rsi,rdx
    661c:	48 89 c7             	mov    rdi,rax
    661f:	e8 bc bd ff ff       	call   23e0 <fputs@plt>
    6624:	48 8b 85 b0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x150]
    662b:	48 89 c7             	mov    rdi,rax
    662e:	e8 7d bd ff ff       	call   23b0 <fclose@plt>
    6633:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    663a:	48 8b 15 e7 a9 00 00 	mov    rdx,QWORD PTR [rip+0xa9e7]        # 11028 <stdout@GLIBC_2.2.5>
    6641:	48 89 d6             	mov    rsi,rdx
    6644:	48 89 c7             	mov    rdi,rax
    6647:	e8 94 bd ff ff       	call   23e0 <fputs@plt>
    664c:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    6653:	48 89 c7             	mov    rdi,rax
    6656:	e8 55 bd ff ff       	call   23b0 <fclose@plt>
    665b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6662:	48 89 c7             	mov    rdi,rax
    6665:	e8 c6 bc ff ff       	call   2330 <free@plt>
    666a:	0f b6 05 1f aa 00 00 	movzx  eax,BYTE PTR [rip+0xaa1f]        # 11090 <is_parallel_nb@@Base>
    6671:	83 f0 01             	xor    eax,0x1
    6674:	84 c0                	test   al,al
    6676:	0f 84 c2 07 00 00    	je     6e3e <TEST_not_permutation_____2+0xa48>
    667c:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    6682:	48 98                	cdqe   
    6684:	48 8b 95 a0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x160]
    668b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    668e:	48 89 c6             	mov    rsi,rax
    6691:	48 89 d7             	mov    rdi,rdx
    6694:	e8 67 bd ff ff       	call   2400 <expected_EQ_TYPE_L_INT@plt>
    6699:	84 c0                	test   al,al
    669b:	0f 84 87 02 00 00    	je     6928 <TEST_not_permutation_____2+0x532>
    66a1:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    66a8:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    66af:	48 89 d6             	mov    rsi,rdx
    66b2:	48 89 c7             	mov    rdi,rax
    66b5:	e8 96 bc ff ff       	call   2350 <open_memstream@plt>
    66ba:	48 89 85 38 ff ff ff 	mov    QWORD PTR [rbp-0xc8],rax
    66c1:	48 83 bd 38 ff ff ff 	cmp    QWORD PTR [rbp-0xc8],0x0
    66c8:	00 
    66c9:	75 38                	jne    6703 <TEST_not_permutation_____2+0x30d>
    66cb:	48 8b 05 2e aa 00 00 	mov    rax,QWORD PTR [rip+0xaa2e]        # 11100 <stderr@GLIBC_2.2.5>
    66d2:	4c 8d 05 77 7c 00 00 	lea    r8,[rip+0x7c77]        # e350 <__func__.2>
    66d9:	b9 47 00 00 00       	mov    ecx,0x47
    66de:	48 8d 15 5f 79 00 00 	lea    rdx,[rip+0x795f]        # e044 <_IO_stdin_used+0x44>
    66e5:	48 8d 35 64 79 00 00 	lea    rsi,[rip+0x7964]        # e050 <_IO_stdin_used+0x50>
    66ec:	48 89 c7             	mov    rdi,rax
    66ef:	b8 00 00 00 00       	mov    eax,0x0
    66f4:	e8 67 bd ff ff       	call   2460 <fprintf@plt>
    66f9:	bf 00 00 00 00       	mov    edi,0x0
    66fe:	e8 1d be ff ff       	call   2520 <exit@plt>
    6703:	8b 05 97 a9 00 00    	mov    eax,DWORD PTR [rip+0xa997]        # 110a0 <k_DEFAULT@@Base>
    6709:	48 98                	cdqe   
    670b:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6712:	00 
    6713:	48 8d 05 a6 a9 00 00 	lea    rax,[rip+0xa9a6]        # 110c0 <colors_f@@Base>
    671a:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    671e:	8b 05 5c a9 00 00    	mov    eax,DWORD PTR [rip+0xa95c]        # 11080 <hk_TR@@Base>
    6724:	48 98                	cdqe   
    6726:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    672d:	00 
    672e:	48 8d 05 0b a9 00 00 	lea    rax,[rip+0xa90b]        # 11040 <tab_hk_f@@Base>
    6735:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    6739:	8b 05 b1 a9 00 00    	mov    eax,DWORD PTR [rip+0xa9b1]        # 110f0 <k_GREEN@@Base>
    673f:	48 98                	cdqe   
    6741:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6748:	00 
    6749:	48 8d 05 70 a9 00 00 	lea    rax,[rip+0xa970]        # 110c0 <colors_f@@Base>
    6750:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    6754:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    675b:	4c 8d 0d ee 7b 00 00 	lea    r9,[rip+0x7bee]        # e350 <__func__.2>
    6762:	49 89 f0             	mov    r8,rsi
    6765:	48 8d 35 1c 79 00 00 	lea    rsi,[rip+0x791c]        # e088 <_IO_stdin_used+0x88>
    676c:	48 89 c7             	mov    rdi,rax
    676f:	b8 00 00 00 00       	mov    eax,0x0
    6774:	e8 e7 bc ff ff       	call   2460 <fprintf@plt>
    6779:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    6780:	48 89 c7             	mov    rdi,rax
    6783:	e8 08 bd ff ff       	call   2490 <fflush@plt>
    6788:	0f b6 05 01 a9 00 00 	movzx  eax,BYTE PTR [rip+0xa901]        # 11090 <is_parallel_nb@@Base>
    678f:	84 c0                	test   al,al
    6791:	0f 84 01 01 00 00    	je     6898 <TEST_not_permutation_____2+0x4a2>
    6797:	e8 b4 bc ff ff       	call   2450 <id_of_thread_executed@plt>
    679c:	48 89 85 48 ff ff ff 	mov    QWORD PTR [rbp-0xb8],rax
    67a3:	0f b6 05 76 a8 00 00 	movzx  eax,BYTE PTR [rip+0xa876]        # 11020 <log_parallel@@Base>
    67aa:	84 c0                	test   al,al
    67ac:	74 76                	je     6824 <TEST_not_permutation_____2+0x42e>
    67ae:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    67b5:	48 8b 15 6c a8 00 00 	mov    rdx,QWORD PTR [rip+0xa86c]        # 11028 <stdout@GLIBC_2.2.5>
    67bc:	48 89 d6             	mov    rsi,rdx
    67bf:	48 89 c7             	mov    rdi,rax
    67c2:	e8 19 bc ff ff       	call   23e0 <fputs@plt>
    67c7:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    67ce:	00 
    67cf:	0f 88 30 01 00 00    	js     6905 <TEST_not_permutation_____2+0x50f>
    67d5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    67dc:	48 8b 0d 4d a8 00 00 	mov    rcx,QWORD PTR [rip+0xa84d]        # 11030 <f_ou_th@@Base>
    67e3:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    67ea:	48 c1 e2 03          	shl    rdx,0x3
    67ee:	48 01 ca             	add    rdx,rcx
    67f1:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    67f4:	48 89 d6             	mov    rsi,rdx
    67f7:	48 89 c7             	mov    rdi,rax
    67fa:	e8 e1 bb ff ff       	call   23e0 <fputs@plt>
    67ff:	48 8b 15 2a a8 00 00 	mov    rdx,QWORD PTR [rip+0xa82a]        # 11030 <f_ou_th@@Base>
    6806:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    680d:	48 c1 e0 03          	shl    rax,0x3
    6811:	48 01 d0             	add    rax,rdx
    6814:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6817:	48 89 c7             	mov    rdi,rax
    681a:	e8 71 bc ff ff       	call   2490 <fflush@plt>
    681f:	e9 e1 00 00 00       	jmp    6905 <TEST_not_permutation_____2+0x50f>
    6824:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    682b:	00 
    682c:	78 4f                	js     687d <TEST_not_permutation_____2+0x487>
    682e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6835:	48 8b 0d f4 a7 00 00 	mov    rcx,QWORD PTR [rip+0xa7f4]        # 11030 <f_ou_th@@Base>
    683c:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    6843:	48 c1 e2 03          	shl    rdx,0x3
    6847:	48 01 ca             	add    rdx,rcx
    684a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    684d:	48 89 d6             	mov    rsi,rdx
    6850:	48 89 c7             	mov    rdi,rax
    6853:	e8 88 bb ff ff       	call   23e0 <fputs@plt>
    6858:	48 8b 15 d1 a7 00 00 	mov    rdx,QWORD PTR [rip+0xa7d1]        # 11030 <f_ou_th@@Base>
    685f:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    6866:	48 c1 e0 03          	shl    rax,0x3
    686a:	48 01 d0             	add    rax,rdx
    686d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6870:	48 89 c7             	mov    rdi,rax
    6873:	e8 18 bc ff ff       	call   2490 <fflush@plt>
    6878:	e9 88 00 00 00       	jmp    6905 <TEST_not_permutation_____2+0x50f>
    687d:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6884:	48 8b 15 9d a7 00 00 	mov    rdx,QWORD PTR [rip+0xa79d]        # 11028 <stdout@GLIBC_2.2.5>
    688b:	48 89 d6             	mov    rsi,rdx
    688e:	48 89 c7             	mov    rdi,rax
    6891:	e8 4a bb ff ff       	call   23e0 <fputs@plt>
    6896:	eb 6d                	jmp    6905 <TEST_not_permutation_____2+0x50f>
    6898:	48 8b 05 99 a7 00 00 	mov    rax,QWORD PTR [rip+0xa799]        # 11038 <savelog@@Base>
    689f:	48 85 c0             	test   rax,rax
    68a2:	74 48                	je     68ec <TEST_not_permutation_____2+0x4f6>
    68a4:	48 8b 05 8d a7 00 00 	mov    rax,QWORD PTR [rip+0xa78d]        # 11038 <savelog@@Base>
    68ab:	48 8d 15 cd 77 00 00 	lea    rdx,[rip+0x77cd]        # e07f <_IO_stdin_used+0x7f>
    68b2:	48 89 d6             	mov    rsi,rdx
    68b5:	48 89 c7             	mov    rdi,rax
    68b8:	e8 43 bc ff ff       	call   2500 <fopen@plt>
    68bd:	48 89 85 40 ff ff ff 	mov    QWORD PTR [rbp-0xc0],rax
    68c4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    68cb:	48 8b 95 40 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xc0]
    68d2:	48 89 d6             	mov    rsi,rdx
    68d5:	48 89 c7             	mov    rdi,rax
    68d8:	e8 03 bb ff ff       	call   23e0 <fputs@plt>
    68dd:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    68e4:	48 89 c7             	mov    rdi,rax
    68e7:	e8 c4 ba ff ff       	call   23b0 <fclose@plt>
    68ec:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    68f3:	48 8b 15 2e a7 00 00 	mov    rdx,QWORD PTR [rip+0xa72e]        # 11028 <stdout@GLIBC_2.2.5>
    68fa:	48 89 d6             	mov    rsi,rdx
    68fd:	48 89 c7             	mov    rdi,rax
    6900:	e8 db ba ff ff       	call   23e0 <fputs@plt>
    6905:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    690c:	48 89 c7             	mov    rdi,rax
    690f:	e8 9c ba ff ff       	call   23b0 <fclose@plt>
    6914:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    691b:	48 89 c7             	mov    rdi,rax
    691e:	e8 0d ba ff ff       	call   2330 <free@plt>
    6923:	e9 dd 0c 00 00       	jmp    7605 <TEST_not_permutation_____2+0x120f>
    6928:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    692f:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    6936:	48 89 d6             	mov    rsi,rdx
    6939:	48 89 c7             	mov    rdi,rax
    693c:	e8 0f ba ff ff       	call   2350 <open_memstream@plt>
    6941:	48 89 85 08 ff ff ff 	mov    QWORD PTR [rbp-0xf8],rax
    6948:	48 83 bd 08 ff ff ff 	cmp    QWORD PTR [rbp-0xf8],0x0
    694f:	00 
    6950:	75 38                	jne    698a <TEST_not_permutation_____2+0x594>
    6952:	48 8b 05 a7 a7 00 00 	mov    rax,QWORD PTR [rip+0xa7a7]        # 11100 <stderr@GLIBC_2.2.5>
    6959:	4c 8d 05 f0 79 00 00 	lea    r8,[rip+0x79f0]        # e350 <__func__.2>
    6960:	b9 47 00 00 00       	mov    ecx,0x47
    6965:	48 8d 15 d8 76 00 00 	lea    rdx,[rip+0x76d8]        # e044 <_IO_stdin_used+0x44>
    696c:	48 8d 35 dd 76 00 00 	lea    rsi,[rip+0x76dd]        # e050 <_IO_stdin_used+0x50>
    6973:	48 89 c7             	mov    rdi,rax
    6976:	b8 00 00 00 00       	mov    eax,0x0
    697b:	e8 e0 ba ff ff       	call   2460 <fprintf@plt>
    6980:	bf 00 00 00 00       	mov    edi,0x0
    6985:	e8 96 bb ff ff       	call   2520 <exit@plt>
    698a:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    6990:	48 98                	cdqe   
    6992:	48 89 c7             	mov    rdi,rax
    6995:	e8 96 bb ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    699a:	48 89 c3             	mov    rbx,rax
    699d:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    69a4:	48 8b 00             	mov    rax,QWORD PTR [rax]
    69a7:	48 89 c7             	mov    rdi,rax
    69aa:	e8 81 bb ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    69af:	48 89 c2             	mov    rdx,rax
    69b2:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    69b9:	53                   	push   rbx
    69ba:	48 8d 0d 94 77 00 00 	lea    rcx,[rip+0x7794]        # e155 <_IO_stdin_used+0x155>
    69c1:	51                   	push   rcx
    69c2:	52                   	push   rdx
    69c3:	48 8d 15 de 76 00 00 	lea    rdx,[rip+0x76de]        # e0a8 <_IO_stdin_used+0xa8>
    69ca:	52                   	push   rdx
    69cb:	48 8d 15 83 77 00 00 	lea    rdx,[rip+0x7783]        # e155 <_IO_stdin_used+0x155>
    69d2:	52                   	push   rdx
    69d3:	48 8d 15 2a 77 00 00 	lea    rdx,[rip+0x772a]        # e104 <_IO_stdin_used+0x104>
    69da:	52                   	push   rdx
    69db:	4c 8d 0d c6 76 00 00 	lea    r9,[rip+0x76c6]        # e0a8 <_IO_stdin_used+0xa8>
    69e2:	4c 8d 05 67 79 00 00 	lea    r8,[rip+0x7967]        # e350 <__func__.2>
    69e9:	b9 47 00 00 00       	mov    ecx,0x47
    69ee:	48 8d 15 4f 76 00 00 	lea    rdx,[rip+0x764f]        # e044 <_IO_stdin_used+0x44>
    69f5:	48 8d 35 b4 76 00 00 	lea    rsi,[rip+0x76b4]        # e0b0 <_IO_stdin_used+0xb0>
    69fc:	48 89 c7             	mov    rdi,rax
    69ff:	b8 00 00 00 00       	mov    eax,0x0
    6a04:	e8 57 ba ff ff       	call   2460 <fprintf@plt>
    6a09:	48 83 c4 30          	add    rsp,0x30
    6a0d:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    6a14:	48 89 c7             	mov    rdi,rax
    6a17:	e8 74 ba ff ff       	call   2490 <fflush@plt>
    6a1c:	0f b6 05 6d a6 00 00 	movzx  eax,BYTE PTR [rip+0xa66d]        # 11090 <is_parallel_nb@@Base>
    6a23:	84 c0                	test   al,al
    6a25:	0f 84 01 01 00 00    	je     6b2c <TEST_not_permutation_____2+0x736>
    6a2b:	e8 20 ba ff ff       	call   2450 <id_of_thread_executed@plt>
    6a30:	48 89 85 18 ff ff ff 	mov    QWORD PTR [rbp-0xe8],rax
    6a37:	0f b6 05 e2 a5 00 00 	movzx  eax,BYTE PTR [rip+0xa5e2]        # 11020 <log_parallel@@Base>
    6a3e:	84 c0                	test   al,al
    6a40:	74 76                	je     6ab8 <TEST_not_permutation_____2+0x6c2>
    6a42:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6a49:	48 8b 15 d8 a5 00 00 	mov    rdx,QWORD PTR [rip+0xa5d8]        # 11028 <stdout@GLIBC_2.2.5>
    6a50:	48 89 d6             	mov    rsi,rdx
    6a53:	48 89 c7             	mov    rdi,rax
    6a56:	e8 85 b9 ff ff       	call   23e0 <fputs@plt>
    6a5b:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    6a62:	00 
    6a63:	0f 88 30 01 00 00    	js     6b99 <TEST_not_permutation_____2+0x7a3>
    6a69:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6a70:	48 8b 0d b9 a5 00 00 	mov    rcx,QWORD PTR [rip+0xa5b9]        # 11030 <f_ou_th@@Base>
    6a77:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    6a7e:	48 c1 e2 03          	shl    rdx,0x3
    6a82:	48 01 ca             	add    rdx,rcx
    6a85:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6a88:	48 89 d6             	mov    rsi,rdx
    6a8b:	48 89 c7             	mov    rdi,rax
    6a8e:	e8 4d b9 ff ff       	call   23e0 <fputs@plt>
    6a93:	48 8b 15 96 a5 00 00 	mov    rdx,QWORD PTR [rip+0xa596]        # 11030 <f_ou_th@@Base>
    6a9a:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    6aa1:	48 c1 e0 03          	shl    rax,0x3
    6aa5:	48 01 d0             	add    rax,rdx
    6aa8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6aab:	48 89 c7             	mov    rdi,rax
    6aae:	e8 dd b9 ff ff       	call   2490 <fflush@plt>
    6ab3:	e9 e1 00 00 00       	jmp    6b99 <TEST_not_permutation_____2+0x7a3>
    6ab8:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    6abf:	00 
    6ac0:	78 4f                	js     6b11 <TEST_not_permutation_____2+0x71b>
    6ac2:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6ac9:	48 8b 0d 60 a5 00 00 	mov    rcx,QWORD PTR [rip+0xa560]        # 11030 <f_ou_th@@Base>
    6ad0:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    6ad7:	48 c1 e2 03          	shl    rdx,0x3
    6adb:	48 01 ca             	add    rdx,rcx
    6ade:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6ae1:	48 89 d6             	mov    rsi,rdx
    6ae4:	48 89 c7             	mov    rdi,rax
    6ae7:	e8 f4 b8 ff ff       	call   23e0 <fputs@plt>
    6aec:	48 8b 15 3d a5 00 00 	mov    rdx,QWORD PTR [rip+0xa53d]        # 11030 <f_ou_th@@Base>
    6af3:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    6afa:	48 c1 e0 03          	shl    rax,0x3
    6afe:	48 01 d0             	add    rax,rdx
    6b01:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6b04:	48 89 c7             	mov    rdi,rax
    6b07:	e8 84 b9 ff ff       	call   2490 <fflush@plt>
    6b0c:	e9 88 00 00 00       	jmp    6b99 <TEST_not_permutation_____2+0x7a3>
    6b11:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6b18:	48 8b 15 09 a5 00 00 	mov    rdx,QWORD PTR [rip+0xa509]        # 11028 <stdout@GLIBC_2.2.5>
    6b1f:	48 89 d6             	mov    rsi,rdx
    6b22:	48 89 c7             	mov    rdi,rax
    6b25:	e8 b6 b8 ff ff       	call   23e0 <fputs@plt>
    6b2a:	eb 6d                	jmp    6b99 <TEST_not_permutation_____2+0x7a3>
    6b2c:	48 8b 05 05 a5 00 00 	mov    rax,QWORD PTR [rip+0xa505]        # 11038 <savelog@@Base>
    6b33:	48 85 c0             	test   rax,rax
    6b36:	74 48                	je     6b80 <TEST_not_permutation_____2+0x78a>
    6b38:	48 8b 05 f9 a4 00 00 	mov    rax,QWORD PTR [rip+0xa4f9]        # 11038 <savelog@@Base>
    6b3f:	48 8d 15 39 75 00 00 	lea    rdx,[rip+0x7539]        # e07f <_IO_stdin_used+0x7f>
    6b46:	48 89 d6             	mov    rsi,rdx
    6b49:	48 89 c7             	mov    rdi,rax
    6b4c:	e8 af b9 ff ff       	call   2500 <fopen@plt>
    6b51:	48 89 85 10 ff ff ff 	mov    QWORD PTR [rbp-0xf0],rax
    6b58:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6b5f:	48 8b 95 10 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xf0]
    6b66:	48 89 d6             	mov    rsi,rdx
    6b69:	48 89 c7             	mov    rdi,rax
    6b6c:	e8 6f b8 ff ff       	call   23e0 <fputs@plt>
    6b71:	48 8b 85 10 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf0]
    6b78:	48 89 c7             	mov    rdi,rax
    6b7b:	e8 30 b8 ff ff       	call   23b0 <fclose@plt>
    6b80:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6b87:	48 8b 15 9a a4 00 00 	mov    rdx,QWORD PTR [rip+0xa49a]        # 11028 <stdout@GLIBC_2.2.5>
    6b8e:	48 89 d6             	mov    rsi,rdx
    6b91:	48 89 c7             	mov    rdi,rax
    6b94:	e8 47 b8 ff ff       	call   23e0 <fputs@plt>
    6b99:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    6ba0:	48 89 c7             	mov    rdi,rax
    6ba3:	e8 08 b8 ff ff       	call   23b0 <fclose@plt>
    6ba8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6baf:	48 89 c7             	mov    rdi,rax
    6bb2:	e8 79 b7 ff ff       	call   2330 <free@plt>
    6bb7:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    6bbe:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    6bc5:	48 89 d6             	mov    rsi,rdx
    6bc8:	48 89 c7             	mov    rdi,rax
    6bcb:	e8 80 b7 ff ff       	call   2350 <open_memstream@plt>
    6bd0:	48 89 85 20 ff ff ff 	mov    QWORD PTR [rbp-0xe0],rax
    6bd7:	48 83 bd 20 ff ff ff 	cmp    QWORD PTR [rbp-0xe0],0x0
    6bde:	00 
    6bdf:	75 38                	jne    6c19 <TEST_not_permutation_____2+0x823>
    6be1:	48 8b 05 18 a5 00 00 	mov    rax,QWORD PTR [rip+0xa518]        # 11100 <stderr@GLIBC_2.2.5>
    6be8:	4c 8d 05 61 77 00 00 	lea    r8,[rip+0x7761]        # e350 <__func__.2>
    6bef:	b9 47 00 00 00       	mov    ecx,0x47
    6bf4:	48 8d 15 49 74 00 00 	lea    rdx,[rip+0x7449]        # e044 <_IO_stdin_used+0x44>
    6bfb:	48 8d 35 4e 74 00 00 	lea    rsi,[rip+0x744e]        # e050 <_IO_stdin_used+0x50>
    6c02:	48 89 c7             	mov    rdi,rax
    6c05:	b8 00 00 00 00       	mov    eax,0x0
    6c0a:	e8 51 b8 ff ff       	call   2460 <fprintf@plt>
    6c0f:	bf 00 00 00 00       	mov    edi,0x0
    6c14:	e8 07 b9 ff ff       	call   2520 <exit@plt>
    6c19:	8b 05 81 a4 00 00    	mov    eax,DWORD PTR [rip+0xa481]        # 110a0 <k_DEFAULT@@Base>
    6c1f:	48 98                	cdqe   
    6c21:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6c28:	00 
    6c29:	48 8d 05 90 a4 00 00 	lea    rax,[rip+0xa490]        # 110c0 <colors_f@@Base>
    6c30:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    6c34:	8b 05 46 a4 00 00    	mov    eax,DWORD PTR [rip+0xa446]        # 11080 <hk_TR@@Base>
    6c3a:	48 98                	cdqe   
    6c3c:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6c43:	00 
    6c44:	48 8d 05 f5 a3 00 00 	lea    rax,[rip+0xa3f5]        # 11040 <tab_hk_f@@Base>
    6c4b:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    6c4f:	8b 05 2f a4 00 00    	mov    eax,DWORD PTR [rip+0xa42f]        # 11084 <k_RED@@Base>
    6c55:	48 98                	cdqe   
    6c57:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6c5e:	00 
    6c5f:	48 8d 05 5a a4 00 00 	lea    rax,[rip+0xa45a]        # 110c0 <colors_f@@Base>
    6c66:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    6c6a:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    6c71:	4c 8d 0d d8 76 00 00 	lea    r9,[rip+0x76d8]        # e350 <__func__.2>
    6c78:	49 89 f0             	mov    r8,rsi
    6c7b:	48 8d 35 86 74 00 00 	lea    rsi,[rip+0x7486]        # e108 <_IO_stdin_used+0x108>
    6c82:	48 89 c7             	mov    rdi,rax
    6c85:	b8 00 00 00 00       	mov    eax,0x0
    6c8a:	e8 d1 b7 ff ff       	call   2460 <fprintf@plt>
    6c8f:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    6c96:	48 89 c7             	mov    rdi,rax
    6c99:	e8 f2 b7 ff ff       	call   2490 <fflush@plt>
    6c9e:	0f b6 05 eb a3 00 00 	movzx  eax,BYTE PTR [rip+0xa3eb]        # 11090 <is_parallel_nb@@Base>
    6ca5:	84 c0                	test   al,al
    6ca7:	0f 84 01 01 00 00    	je     6dae <TEST_not_permutation_____2+0x9b8>
    6cad:	e8 9e b7 ff ff       	call   2450 <id_of_thread_executed@plt>
    6cb2:	48 89 85 30 ff ff ff 	mov    QWORD PTR [rbp-0xd0],rax
    6cb9:	0f b6 05 60 a3 00 00 	movzx  eax,BYTE PTR [rip+0xa360]        # 11020 <log_parallel@@Base>
    6cc0:	84 c0                	test   al,al
    6cc2:	74 76                	je     6d3a <TEST_not_permutation_____2+0x944>
    6cc4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6ccb:	48 8b 15 56 a3 00 00 	mov    rdx,QWORD PTR [rip+0xa356]        # 11028 <stdout@GLIBC_2.2.5>
    6cd2:	48 89 d6             	mov    rsi,rdx
    6cd5:	48 89 c7             	mov    rdi,rax
    6cd8:	e8 03 b7 ff ff       	call   23e0 <fputs@plt>
    6cdd:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    6ce4:	00 
    6ce5:	0f 88 30 01 00 00    	js     6e1b <TEST_not_permutation_____2+0xa25>
    6ceb:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6cf2:	48 8b 0d 37 a3 00 00 	mov    rcx,QWORD PTR [rip+0xa337]        # 11030 <f_ou_th@@Base>
    6cf9:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    6d00:	48 c1 e2 03          	shl    rdx,0x3
    6d04:	48 01 ca             	add    rdx,rcx
    6d07:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6d0a:	48 89 d6             	mov    rsi,rdx
    6d0d:	48 89 c7             	mov    rdi,rax
    6d10:	e8 cb b6 ff ff       	call   23e0 <fputs@plt>
    6d15:	48 8b 15 14 a3 00 00 	mov    rdx,QWORD PTR [rip+0xa314]        # 11030 <f_ou_th@@Base>
    6d1c:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    6d23:	48 c1 e0 03          	shl    rax,0x3
    6d27:	48 01 d0             	add    rax,rdx
    6d2a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6d2d:	48 89 c7             	mov    rdi,rax
    6d30:	e8 5b b7 ff ff       	call   2490 <fflush@plt>
    6d35:	e9 e1 00 00 00       	jmp    6e1b <TEST_not_permutation_____2+0xa25>
    6d3a:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    6d41:	00 
    6d42:	78 4f                	js     6d93 <TEST_not_permutation_____2+0x99d>
    6d44:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6d4b:	48 8b 0d de a2 00 00 	mov    rcx,QWORD PTR [rip+0xa2de]        # 11030 <f_ou_th@@Base>
    6d52:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    6d59:	48 c1 e2 03          	shl    rdx,0x3
    6d5d:	48 01 ca             	add    rdx,rcx
    6d60:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6d63:	48 89 d6             	mov    rsi,rdx
    6d66:	48 89 c7             	mov    rdi,rax
    6d69:	e8 72 b6 ff ff       	call   23e0 <fputs@plt>
    6d6e:	48 8b 15 bb a2 00 00 	mov    rdx,QWORD PTR [rip+0xa2bb]        # 11030 <f_ou_th@@Base>
    6d75:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    6d7c:	48 c1 e0 03          	shl    rax,0x3
    6d80:	48 01 d0             	add    rax,rdx
    6d83:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6d86:	48 89 c7             	mov    rdi,rax
    6d89:	e8 02 b7 ff ff       	call   2490 <fflush@plt>
    6d8e:	e9 88 00 00 00       	jmp    6e1b <TEST_not_permutation_____2+0xa25>
    6d93:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6d9a:	48 8b 15 87 a2 00 00 	mov    rdx,QWORD PTR [rip+0xa287]        # 11028 <stdout@GLIBC_2.2.5>
    6da1:	48 89 d6             	mov    rsi,rdx
    6da4:	48 89 c7             	mov    rdi,rax
    6da7:	e8 34 b6 ff ff       	call   23e0 <fputs@plt>
    6dac:	eb 6d                	jmp    6e1b <TEST_not_permutation_____2+0xa25>
    6dae:	48 8b 05 83 a2 00 00 	mov    rax,QWORD PTR [rip+0xa283]        # 11038 <savelog@@Base>
    6db5:	48 85 c0             	test   rax,rax
    6db8:	74 48                	je     6e02 <TEST_not_permutation_____2+0xa0c>
    6dba:	48 8b 05 77 a2 00 00 	mov    rax,QWORD PTR [rip+0xa277]        # 11038 <savelog@@Base>
    6dc1:	48 8d 15 b7 72 00 00 	lea    rdx,[rip+0x72b7]        # e07f <_IO_stdin_used+0x7f>
    6dc8:	48 89 d6             	mov    rsi,rdx
    6dcb:	48 89 c7             	mov    rdi,rax
    6dce:	e8 2d b7 ff ff       	call   2500 <fopen@plt>
    6dd3:	48 89 85 28 ff ff ff 	mov    QWORD PTR [rbp-0xd8],rax
    6dda:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6de1:	48 8b 95 28 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd8]
    6de8:	48 89 d6             	mov    rsi,rdx
    6deb:	48 89 c7             	mov    rdi,rax
    6dee:	e8 ed b5 ff ff       	call   23e0 <fputs@plt>
    6df3:	48 8b 85 28 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd8]
    6dfa:	48 89 c7             	mov    rdi,rax
    6dfd:	e8 ae b5 ff ff       	call   23b0 <fclose@plt>
    6e02:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6e09:	48 8b 15 18 a2 00 00 	mov    rdx,QWORD PTR [rip+0xa218]        # 11028 <stdout@GLIBC_2.2.5>
    6e10:	48 89 d6             	mov    rsi,rdx
    6e13:	48 89 c7             	mov    rdi,rax
    6e16:	e8 c5 b5 ff ff       	call   23e0 <fputs@plt>
    6e1b:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    6e22:	48 89 c7             	mov    rdi,rax
    6e25:	e8 86 b5 ff ff       	call   23b0 <fclose@plt>
    6e2a:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6e31:	48 89 c7             	mov    rdi,rax
    6e34:	e8 f7 b4 ff ff       	call   2330 <free@plt>
    6e39:	e9 c7 07 00 00       	jmp    7605 <TEST_not_permutation_____2+0x120f>
    6e3e:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    6e44:	48 98                	cdqe   
    6e46:	48 8b 95 a0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x160]
    6e4d:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6e50:	48 89 d1             	mov    rcx,rdx
    6e53:	48 8d 15 f6 74 00 00 	lea    rdx,[rip+0x74f6]        # e350 <__func__.2>
    6e5a:	48 89 c6             	mov    rsi,rax
    6e5d:	48 89 cf             	mov    rdi,rcx
    6e60:	e8 1b b5 ff ff       	call   2380 <expected_EQ_name_TYPE_L_INT@plt>
    6e65:	84 c0                	test   al,al
    6e67:	0f 84 87 02 00 00    	je     70f4 <TEST_not_permutation_____2+0xcfe>
    6e6d:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    6e74:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    6e7b:	48 89 d6             	mov    rsi,rdx
    6e7e:	48 89 c7             	mov    rdi,rax
    6e81:	e8 ca b4 ff ff       	call   2350 <open_memstream@plt>
    6e86:	48 89 85 f0 fe ff ff 	mov    QWORD PTR [rbp-0x110],rax
    6e8d:	48 83 bd f0 fe ff ff 	cmp    QWORD PTR [rbp-0x110],0x0
    6e94:	00 
    6e95:	75 38                	jne    6ecf <TEST_not_permutation_____2+0xad9>
    6e97:	48 8b 05 62 a2 00 00 	mov    rax,QWORD PTR [rip+0xa262]        # 11100 <stderr@GLIBC_2.2.5>
    6e9e:	4c 8d 05 ab 74 00 00 	lea    r8,[rip+0x74ab]        # e350 <__func__.2>
    6ea5:	b9 47 00 00 00       	mov    ecx,0x47
    6eaa:	48 8d 15 93 71 00 00 	lea    rdx,[rip+0x7193]        # e044 <_IO_stdin_used+0x44>
    6eb1:	48 8d 35 98 71 00 00 	lea    rsi,[rip+0x7198]        # e050 <_IO_stdin_used+0x50>
    6eb8:	48 89 c7             	mov    rdi,rax
    6ebb:	b8 00 00 00 00       	mov    eax,0x0
    6ec0:	e8 9b b5 ff ff       	call   2460 <fprintf@plt>
    6ec5:	bf 00 00 00 00       	mov    edi,0x0
    6eca:	e8 51 b6 ff ff       	call   2520 <exit@plt>
    6ecf:	8b 05 cb a1 00 00    	mov    eax,DWORD PTR [rip+0xa1cb]        # 110a0 <k_DEFAULT@@Base>
    6ed5:	48 98                	cdqe   
    6ed7:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6ede:	00 
    6edf:	48 8d 05 da a1 00 00 	lea    rax,[rip+0xa1da]        # 110c0 <colors_f@@Base>
    6ee6:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    6eea:	8b 05 90 a1 00 00    	mov    eax,DWORD PTR [rip+0xa190]        # 11080 <hk_TR@@Base>
    6ef0:	48 98                	cdqe   
    6ef2:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6ef9:	00 
    6efa:	48 8d 05 3f a1 00 00 	lea    rax,[rip+0xa13f]        # 11040 <tab_hk_f@@Base>
    6f01:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    6f05:	8b 05 e5 a1 00 00    	mov    eax,DWORD PTR [rip+0xa1e5]        # 110f0 <k_GREEN@@Base>
    6f0b:	48 98                	cdqe   
    6f0d:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    6f14:	00 
    6f15:	48 8d 05 a4 a1 00 00 	lea    rax,[rip+0xa1a4]        # 110c0 <colors_f@@Base>
    6f1c:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    6f20:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    6f27:	4c 8d 0d 22 74 00 00 	lea    r9,[rip+0x7422]        # e350 <__func__.2>
    6f2e:	49 89 f0             	mov    r8,rsi
    6f31:	48 8d 35 50 71 00 00 	lea    rsi,[rip+0x7150]        # e088 <_IO_stdin_used+0x88>
    6f38:	48 89 c7             	mov    rdi,rax
    6f3b:	b8 00 00 00 00       	mov    eax,0x0
    6f40:	e8 1b b5 ff ff       	call   2460 <fprintf@plt>
    6f45:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    6f4c:	48 89 c7             	mov    rdi,rax
    6f4f:	e8 3c b5 ff ff       	call   2490 <fflush@plt>
    6f54:	0f b6 05 35 a1 00 00 	movzx  eax,BYTE PTR [rip+0xa135]        # 11090 <is_parallel_nb@@Base>
    6f5b:	84 c0                	test   al,al
    6f5d:	0f 84 01 01 00 00    	je     7064 <TEST_not_permutation_____2+0xc6e>
    6f63:	e8 e8 b4 ff ff       	call   2450 <id_of_thread_executed@plt>
    6f68:	48 89 85 00 ff ff ff 	mov    QWORD PTR [rbp-0x100],rax
    6f6f:	0f b6 05 aa a0 00 00 	movzx  eax,BYTE PTR [rip+0xa0aa]        # 11020 <log_parallel@@Base>
    6f76:	84 c0                	test   al,al
    6f78:	74 76                	je     6ff0 <TEST_not_permutation_____2+0xbfa>
    6f7a:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6f81:	48 8b 15 a0 a0 00 00 	mov    rdx,QWORD PTR [rip+0xa0a0]        # 11028 <stdout@GLIBC_2.2.5>
    6f88:	48 89 d6             	mov    rsi,rdx
    6f8b:	48 89 c7             	mov    rdi,rax
    6f8e:	e8 4d b4 ff ff       	call   23e0 <fputs@plt>
    6f93:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    6f9a:	00 
    6f9b:	0f 88 30 01 00 00    	js     70d1 <TEST_not_permutation_____2+0xcdb>
    6fa1:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    6fa8:	48 8b 0d 81 a0 00 00 	mov    rcx,QWORD PTR [rip+0xa081]        # 11030 <f_ou_th@@Base>
    6faf:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    6fb6:	48 c1 e2 03          	shl    rdx,0x3
    6fba:	48 01 ca             	add    rdx,rcx
    6fbd:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    6fc0:	48 89 d6             	mov    rsi,rdx
    6fc3:	48 89 c7             	mov    rdi,rax
    6fc6:	e8 15 b4 ff ff       	call   23e0 <fputs@plt>
    6fcb:	48 8b 15 5e a0 00 00 	mov    rdx,QWORD PTR [rip+0xa05e]        # 11030 <f_ou_th@@Base>
    6fd2:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    6fd9:	48 c1 e0 03          	shl    rax,0x3
    6fdd:	48 01 d0             	add    rax,rdx
    6fe0:	48 8b 00             	mov    rax,QWORD PTR [rax]
    6fe3:	48 89 c7             	mov    rdi,rax
    6fe6:	e8 a5 b4 ff ff       	call   2490 <fflush@plt>
    6feb:	e9 e1 00 00 00       	jmp    70d1 <TEST_not_permutation_____2+0xcdb>
    6ff0:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    6ff7:	00 
    6ff8:	78 4f                	js     7049 <TEST_not_permutation_____2+0xc53>
    6ffa:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7001:	48 8b 0d 28 a0 00 00 	mov    rcx,QWORD PTR [rip+0xa028]        # 11030 <f_ou_th@@Base>
    7008:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    700f:	48 c1 e2 03          	shl    rdx,0x3
    7013:	48 01 ca             	add    rdx,rcx
    7016:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7019:	48 89 d6             	mov    rsi,rdx
    701c:	48 89 c7             	mov    rdi,rax
    701f:	e8 bc b3 ff ff       	call   23e0 <fputs@plt>
    7024:	48 8b 15 05 a0 00 00 	mov    rdx,QWORD PTR [rip+0xa005]        # 11030 <f_ou_th@@Base>
    702b:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    7032:	48 c1 e0 03          	shl    rax,0x3
    7036:	48 01 d0             	add    rax,rdx
    7039:	48 8b 00             	mov    rax,QWORD PTR [rax]
    703c:	48 89 c7             	mov    rdi,rax
    703f:	e8 4c b4 ff ff       	call   2490 <fflush@plt>
    7044:	e9 88 00 00 00       	jmp    70d1 <TEST_not_permutation_____2+0xcdb>
    7049:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7050:	48 8b 15 d1 9f 00 00 	mov    rdx,QWORD PTR [rip+0x9fd1]        # 11028 <stdout@GLIBC_2.2.5>
    7057:	48 89 d6             	mov    rsi,rdx
    705a:	48 89 c7             	mov    rdi,rax
    705d:	e8 7e b3 ff ff       	call   23e0 <fputs@plt>
    7062:	eb 6d                	jmp    70d1 <TEST_not_permutation_____2+0xcdb>
    7064:	48 8b 05 cd 9f 00 00 	mov    rax,QWORD PTR [rip+0x9fcd]        # 11038 <savelog@@Base>
    706b:	48 85 c0             	test   rax,rax
    706e:	74 48                	je     70b8 <TEST_not_permutation_____2+0xcc2>
    7070:	48 8b 05 c1 9f 00 00 	mov    rax,QWORD PTR [rip+0x9fc1]        # 11038 <savelog@@Base>
    7077:	48 8d 15 01 70 00 00 	lea    rdx,[rip+0x7001]        # e07f <_IO_stdin_used+0x7f>
    707e:	48 89 d6             	mov    rsi,rdx
    7081:	48 89 c7             	mov    rdi,rax
    7084:	e8 77 b4 ff ff       	call   2500 <fopen@plt>
    7089:	48 89 85 f8 fe ff ff 	mov    QWORD PTR [rbp-0x108],rax
    7090:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7097:	48 8b 95 f8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x108]
    709e:	48 89 d6             	mov    rsi,rdx
    70a1:	48 89 c7             	mov    rdi,rax
    70a4:	e8 37 b3 ff ff       	call   23e0 <fputs@plt>
    70a9:	48 8b 85 f8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x108]
    70b0:	48 89 c7             	mov    rdi,rax
    70b3:	e8 f8 b2 ff ff       	call   23b0 <fclose@plt>
    70b8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    70bf:	48 8b 15 62 9f 00 00 	mov    rdx,QWORD PTR [rip+0x9f62]        # 11028 <stdout@GLIBC_2.2.5>
    70c6:	48 89 d6             	mov    rsi,rdx
    70c9:	48 89 c7             	mov    rdi,rax
    70cc:	e8 0f b3 ff ff       	call   23e0 <fputs@plt>
    70d1:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    70d8:	48 89 c7             	mov    rdi,rax
    70db:	e8 d0 b2 ff ff       	call   23b0 <fclose@plt>
    70e0:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    70e7:	48 89 c7             	mov    rdi,rax
    70ea:	e8 41 b2 ff ff       	call   2330 <free@plt>
    70ef:	e9 11 05 00 00       	jmp    7605 <TEST_not_permutation_____2+0x120f>
    70f4:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    70fb:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    7102:	48 89 d6             	mov    rsi,rdx
    7105:	48 89 c7             	mov    rdi,rax
    7108:	e8 43 b2 ff ff       	call   2350 <open_memstream@plt>
    710d:	48 89 85 c0 fe ff ff 	mov    QWORD PTR [rbp-0x140],rax
    7114:	48 83 bd c0 fe ff ff 	cmp    QWORD PTR [rbp-0x140],0x0
    711b:	00 
    711c:	75 38                	jne    7156 <TEST_not_permutation_____2+0xd60>
    711e:	48 8b 05 db 9f 00 00 	mov    rax,QWORD PTR [rip+0x9fdb]        # 11100 <stderr@GLIBC_2.2.5>
    7125:	4c 8d 05 24 72 00 00 	lea    r8,[rip+0x7224]        # e350 <__func__.2>
    712c:	b9 47 00 00 00       	mov    ecx,0x47
    7131:	48 8d 15 0c 6f 00 00 	lea    rdx,[rip+0x6f0c]        # e044 <_IO_stdin_used+0x44>
    7138:	48 8d 35 11 6f 00 00 	lea    rsi,[rip+0x6f11]        # e050 <_IO_stdin_used+0x50>
    713f:	48 89 c7             	mov    rdi,rax
    7142:	b8 00 00 00 00       	mov    eax,0x0
    7147:	e8 14 b3 ff ff       	call   2460 <fprintf@plt>
    714c:	bf 00 00 00 00       	mov    edi,0x0
    7151:	e8 ca b3 ff ff       	call   2520 <exit@plt>
    7156:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    715c:	48 98                	cdqe   
    715e:	48 89 c7             	mov    rdi,rax
    7161:	e8 ca b3 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    7166:	48 89 c3             	mov    rbx,rax
    7169:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    7170:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7173:	48 89 c7             	mov    rdi,rax
    7176:	e8 b5 b3 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    717b:	48 89 c2             	mov    rdx,rax
    717e:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    7185:	53                   	push   rbx
    7186:	48 8d 0d c8 6f 00 00 	lea    rcx,[rip+0x6fc8]        # e155 <_IO_stdin_used+0x155>
    718d:	51                   	push   rcx
    718e:	52                   	push   rdx
    718f:	48 8d 15 12 6f 00 00 	lea    rdx,[rip+0x6f12]        # e0a8 <_IO_stdin_used+0xa8>
    7196:	52                   	push   rdx
    7197:	48 8d 15 b7 6f 00 00 	lea    rdx,[rip+0x6fb7]        # e155 <_IO_stdin_used+0x155>
    719e:	52                   	push   rdx
    719f:	48 8d 15 5e 6f 00 00 	lea    rdx,[rip+0x6f5e]        # e104 <_IO_stdin_used+0x104>
    71a6:	52                   	push   rdx
    71a7:	4c 8d 0d fa 6e 00 00 	lea    r9,[rip+0x6efa]        # e0a8 <_IO_stdin_used+0xa8>
    71ae:	4c 8d 05 9b 71 00 00 	lea    r8,[rip+0x719b]        # e350 <__func__.2>
    71b5:	b9 47 00 00 00       	mov    ecx,0x47
    71ba:	48 8d 15 83 6e 00 00 	lea    rdx,[rip+0x6e83]        # e044 <_IO_stdin_used+0x44>
    71c1:	48 8d 35 e8 6e 00 00 	lea    rsi,[rip+0x6ee8]        # e0b0 <_IO_stdin_used+0xb0>
    71c8:	48 89 c7             	mov    rdi,rax
    71cb:	b8 00 00 00 00       	mov    eax,0x0
    71d0:	e8 8b b2 ff ff       	call   2460 <fprintf@plt>
    71d5:	48 83 c4 30          	add    rsp,0x30
    71d9:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    71e0:	48 89 c7             	mov    rdi,rax
    71e3:	e8 a8 b2 ff ff       	call   2490 <fflush@plt>
    71e8:	0f b6 05 a1 9e 00 00 	movzx  eax,BYTE PTR [rip+0x9ea1]        # 11090 <is_parallel_nb@@Base>
    71ef:	84 c0                	test   al,al
    71f1:	0f 84 01 01 00 00    	je     72f8 <TEST_not_permutation_____2+0xf02>
    71f7:	e8 54 b2 ff ff       	call   2450 <id_of_thread_executed@plt>
    71fc:	48 89 85 d0 fe ff ff 	mov    QWORD PTR [rbp-0x130],rax
    7203:	0f b6 05 16 9e 00 00 	movzx  eax,BYTE PTR [rip+0x9e16]        # 11020 <log_parallel@@Base>
    720a:	84 c0                	test   al,al
    720c:	74 76                	je     7284 <TEST_not_permutation_____2+0xe8e>
    720e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7215:	48 8b 15 0c 9e 00 00 	mov    rdx,QWORD PTR [rip+0x9e0c]        # 11028 <stdout@GLIBC_2.2.5>
    721c:	48 89 d6             	mov    rsi,rdx
    721f:	48 89 c7             	mov    rdi,rax
    7222:	e8 b9 b1 ff ff       	call   23e0 <fputs@plt>
    7227:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    722e:	00 
    722f:	0f 88 30 01 00 00    	js     7365 <TEST_not_permutation_____2+0xf6f>
    7235:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    723c:	48 8b 0d ed 9d 00 00 	mov    rcx,QWORD PTR [rip+0x9ded]        # 11030 <f_ou_th@@Base>
    7243:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    724a:	48 c1 e2 03          	shl    rdx,0x3
    724e:	48 01 ca             	add    rdx,rcx
    7251:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7254:	48 89 d6             	mov    rsi,rdx
    7257:	48 89 c7             	mov    rdi,rax
    725a:	e8 81 b1 ff ff       	call   23e0 <fputs@plt>
    725f:	48 8b 15 ca 9d 00 00 	mov    rdx,QWORD PTR [rip+0x9dca]        # 11030 <f_ou_th@@Base>
    7266:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    726d:	48 c1 e0 03          	shl    rax,0x3
    7271:	48 01 d0             	add    rax,rdx
    7274:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7277:	48 89 c7             	mov    rdi,rax
    727a:	e8 11 b2 ff ff       	call   2490 <fflush@plt>
    727f:	e9 e1 00 00 00       	jmp    7365 <TEST_not_permutation_____2+0xf6f>
    7284:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    728b:	00 
    728c:	78 4f                	js     72dd <TEST_not_permutation_____2+0xee7>
    728e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7295:	48 8b 0d 94 9d 00 00 	mov    rcx,QWORD PTR [rip+0x9d94]        # 11030 <f_ou_th@@Base>
    729c:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    72a3:	48 c1 e2 03          	shl    rdx,0x3
    72a7:	48 01 ca             	add    rdx,rcx
    72aa:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    72ad:	48 89 d6             	mov    rsi,rdx
    72b0:	48 89 c7             	mov    rdi,rax
    72b3:	e8 28 b1 ff ff       	call   23e0 <fputs@plt>
    72b8:	48 8b 15 71 9d 00 00 	mov    rdx,QWORD PTR [rip+0x9d71]        # 11030 <f_ou_th@@Base>
    72bf:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    72c6:	48 c1 e0 03          	shl    rax,0x3
    72ca:	48 01 d0             	add    rax,rdx
    72cd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    72d0:	48 89 c7             	mov    rdi,rax
    72d3:	e8 b8 b1 ff ff       	call   2490 <fflush@plt>
    72d8:	e9 88 00 00 00       	jmp    7365 <TEST_not_permutation_____2+0xf6f>
    72dd:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    72e4:	48 8b 15 3d 9d 00 00 	mov    rdx,QWORD PTR [rip+0x9d3d]        # 11028 <stdout@GLIBC_2.2.5>
    72eb:	48 89 d6             	mov    rsi,rdx
    72ee:	48 89 c7             	mov    rdi,rax
    72f1:	e8 ea b0 ff ff       	call   23e0 <fputs@plt>
    72f6:	eb 6d                	jmp    7365 <TEST_not_permutation_____2+0xf6f>
    72f8:	48 8b 05 39 9d 00 00 	mov    rax,QWORD PTR [rip+0x9d39]        # 11038 <savelog@@Base>
    72ff:	48 85 c0             	test   rax,rax
    7302:	74 48                	je     734c <TEST_not_permutation_____2+0xf56>
    7304:	48 8b 05 2d 9d 00 00 	mov    rax,QWORD PTR [rip+0x9d2d]        # 11038 <savelog@@Base>
    730b:	48 8d 15 6d 6d 00 00 	lea    rdx,[rip+0x6d6d]        # e07f <_IO_stdin_used+0x7f>
    7312:	48 89 d6             	mov    rsi,rdx
    7315:	48 89 c7             	mov    rdi,rax
    7318:	e8 e3 b1 ff ff       	call   2500 <fopen@plt>
    731d:	48 89 85 c8 fe ff ff 	mov    QWORD PTR [rbp-0x138],rax
    7324:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    732b:	48 8b 95 c8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x138]
    7332:	48 89 d6             	mov    rsi,rdx
    7335:	48 89 c7             	mov    rdi,rax
    7338:	e8 a3 b0 ff ff       	call   23e0 <fputs@plt>
    733d:	48 8b 85 c8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x138]
    7344:	48 89 c7             	mov    rdi,rax
    7347:	e8 64 b0 ff ff       	call   23b0 <fclose@plt>
    734c:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7353:	48 8b 15 ce 9c 00 00 	mov    rdx,QWORD PTR [rip+0x9cce]        # 11028 <stdout@GLIBC_2.2.5>
    735a:	48 89 d6             	mov    rsi,rdx
    735d:	48 89 c7             	mov    rdi,rax
    7360:	e8 7b b0 ff ff       	call   23e0 <fputs@plt>
    7365:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    736c:	48 89 c7             	mov    rdi,rax
    736f:	e8 3c b0 ff ff       	call   23b0 <fclose@plt>
    7374:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    737b:	48 89 c7             	mov    rdi,rax
    737e:	e8 ad af ff ff       	call   2330 <free@plt>
    7383:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    738a:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    7391:	48 89 d6             	mov    rsi,rdx
    7394:	48 89 c7             	mov    rdi,rax
    7397:	e8 b4 af ff ff       	call   2350 <open_memstream@plt>
    739c:	48 89 85 d8 fe ff ff 	mov    QWORD PTR [rbp-0x128],rax
    73a3:	48 83 bd d8 fe ff ff 	cmp    QWORD PTR [rbp-0x128],0x0
    73aa:	00 
    73ab:	75 38                	jne    73e5 <TEST_not_permutation_____2+0xfef>
    73ad:	48 8b 05 4c 9d 00 00 	mov    rax,QWORD PTR [rip+0x9d4c]        # 11100 <stderr@GLIBC_2.2.5>
    73b4:	4c 8d 05 95 6f 00 00 	lea    r8,[rip+0x6f95]        # e350 <__func__.2>
    73bb:	b9 47 00 00 00       	mov    ecx,0x47
    73c0:	48 8d 15 7d 6c 00 00 	lea    rdx,[rip+0x6c7d]        # e044 <_IO_stdin_used+0x44>
    73c7:	48 8d 35 82 6c 00 00 	lea    rsi,[rip+0x6c82]        # e050 <_IO_stdin_used+0x50>
    73ce:	48 89 c7             	mov    rdi,rax
    73d1:	b8 00 00 00 00       	mov    eax,0x0
    73d6:	e8 85 b0 ff ff       	call   2460 <fprintf@plt>
    73db:	bf 00 00 00 00       	mov    edi,0x0
    73e0:	e8 3b b1 ff ff       	call   2520 <exit@plt>
    73e5:	8b 05 b5 9c 00 00    	mov    eax,DWORD PTR [rip+0x9cb5]        # 110a0 <k_DEFAULT@@Base>
    73eb:	48 98                	cdqe   
    73ed:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    73f4:	00 
    73f5:	48 8d 05 c4 9c 00 00 	lea    rax,[rip+0x9cc4]        # 110c0 <colors_f@@Base>
    73fc:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    7400:	8b 05 7a 9c 00 00    	mov    eax,DWORD PTR [rip+0x9c7a]        # 11080 <hk_TR@@Base>
    7406:	48 98                	cdqe   
    7408:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    740f:	00 
    7410:	48 8d 05 29 9c 00 00 	lea    rax,[rip+0x9c29]        # 11040 <tab_hk_f@@Base>
    7417:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    741b:	8b 05 63 9c 00 00    	mov    eax,DWORD PTR [rip+0x9c63]        # 11084 <k_RED@@Base>
    7421:	48 98                	cdqe   
    7423:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    742a:	00 
    742b:	48 8d 05 8e 9c 00 00 	lea    rax,[rip+0x9c8e]        # 110c0 <colors_f@@Base>
    7432:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    7436:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    743d:	4c 8d 0d 0c 6f 00 00 	lea    r9,[rip+0x6f0c]        # e350 <__func__.2>
    7444:	49 89 f0             	mov    r8,rsi
    7447:	48 8d 35 ba 6c 00 00 	lea    rsi,[rip+0x6cba]        # e108 <_IO_stdin_used+0x108>
    744e:	48 89 c7             	mov    rdi,rax
    7451:	b8 00 00 00 00       	mov    eax,0x0
    7456:	e8 05 b0 ff ff       	call   2460 <fprintf@plt>
    745b:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    7462:	48 89 c7             	mov    rdi,rax
    7465:	e8 26 b0 ff ff       	call   2490 <fflush@plt>
    746a:	0f b6 05 1f 9c 00 00 	movzx  eax,BYTE PTR [rip+0x9c1f]        # 11090 <is_parallel_nb@@Base>
    7471:	84 c0                	test   al,al
    7473:	0f 84 01 01 00 00    	je     757a <TEST_not_permutation_____2+0x1184>
    7479:	e8 d2 af ff ff       	call   2450 <id_of_thread_executed@plt>
    747e:	48 89 85 e8 fe ff ff 	mov    QWORD PTR [rbp-0x118],rax
    7485:	0f b6 05 94 9b 00 00 	movzx  eax,BYTE PTR [rip+0x9b94]        # 11020 <log_parallel@@Base>
    748c:	84 c0                	test   al,al
    748e:	74 76                	je     7506 <TEST_not_permutation_____2+0x1110>
    7490:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7497:	48 8b 15 8a 9b 00 00 	mov    rdx,QWORD PTR [rip+0x9b8a]        # 11028 <stdout@GLIBC_2.2.5>
    749e:	48 89 d6             	mov    rsi,rdx
    74a1:	48 89 c7             	mov    rdi,rax
    74a4:	e8 37 af ff ff       	call   23e0 <fputs@plt>
    74a9:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    74b0:	00 
    74b1:	0f 88 30 01 00 00    	js     75e7 <TEST_not_permutation_____2+0x11f1>
    74b7:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    74be:	48 8b 0d 6b 9b 00 00 	mov    rcx,QWORD PTR [rip+0x9b6b]        # 11030 <f_ou_th@@Base>
    74c5:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    74cc:	48 c1 e2 03          	shl    rdx,0x3
    74d0:	48 01 ca             	add    rdx,rcx
    74d3:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    74d6:	48 89 d6             	mov    rsi,rdx
    74d9:	48 89 c7             	mov    rdi,rax
    74dc:	e8 ff ae ff ff       	call   23e0 <fputs@plt>
    74e1:	48 8b 15 48 9b 00 00 	mov    rdx,QWORD PTR [rip+0x9b48]        # 11030 <f_ou_th@@Base>
    74e8:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    74ef:	48 c1 e0 03          	shl    rax,0x3
    74f3:	48 01 d0             	add    rax,rdx
    74f6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    74f9:	48 89 c7             	mov    rdi,rax
    74fc:	e8 8f af ff ff       	call   2490 <fflush@plt>
    7501:	e9 e1 00 00 00       	jmp    75e7 <TEST_not_permutation_____2+0x11f1>
    7506:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    750d:	00 
    750e:	78 4f                	js     755f <TEST_not_permutation_____2+0x1169>
    7510:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7517:	48 8b 0d 12 9b 00 00 	mov    rcx,QWORD PTR [rip+0x9b12]        # 11030 <f_ou_th@@Base>
    751e:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    7525:	48 c1 e2 03          	shl    rdx,0x3
    7529:	48 01 ca             	add    rdx,rcx
    752c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    752f:	48 89 d6             	mov    rsi,rdx
    7532:	48 89 c7             	mov    rdi,rax
    7535:	e8 a6 ae ff ff       	call   23e0 <fputs@plt>
    753a:	48 8b 15 ef 9a 00 00 	mov    rdx,QWORD PTR [rip+0x9aef]        # 11030 <f_ou_th@@Base>
    7541:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    7548:	48 c1 e0 03          	shl    rax,0x3
    754c:	48 01 d0             	add    rax,rdx
    754f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7552:	48 89 c7             	mov    rdi,rax
    7555:	e8 36 af ff ff       	call   2490 <fflush@plt>
    755a:	e9 88 00 00 00       	jmp    75e7 <TEST_not_permutation_____2+0x11f1>
    755f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7566:	48 8b 15 bb 9a 00 00 	mov    rdx,QWORD PTR [rip+0x9abb]        # 11028 <stdout@GLIBC_2.2.5>
    756d:	48 89 d6             	mov    rsi,rdx
    7570:	48 89 c7             	mov    rdi,rax
    7573:	e8 68 ae ff ff       	call   23e0 <fputs@plt>
    7578:	eb 6d                	jmp    75e7 <TEST_not_permutation_____2+0x11f1>
    757a:	48 8b 05 b7 9a 00 00 	mov    rax,QWORD PTR [rip+0x9ab7]        # 11038 <savelog@@Base>
    7581:	48 85 c0             	test   rax,rax
    7584:	74 48                	je     75ce <TEST_not_permutation_____2+0x11d8>
    7586:	48 8b 05 ab 9a 00 00 	mov    rax,QWORD PTR [rip+0x9aab]        # 11038 <savelog@@Base>
    758d:	48 8d 15 eb 6a 00 00 	lea    rdx,[rip+0x6aeb]        # e07f <_IO_stdin_used+0x7f>
    7594:	48 89 d6             	mov    rsi,rdx
    7597:	48 89 c7             	mov    rdi,rax
    759a:	e8 61 af ff ff       	call   2500 <fopen@plt>
    759f:	48 89 85 e0 fe ff ff 	mov    QWORD PTR [rbp-0x120],rax
    75a6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    75ad:	48 8b 95 e0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x120]
    75b4:	48 89 d6             	mov    rsi,rdx
    75b7:	48 89 c7             	mov    rdi,rax
    75ba:	e8 21 ae ff ff       	call   23e0 <fputs@plt>
    75bf:	48 8b 85 e0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x120]
    75c6:	48 89 c7             	mov    rdi,rax
    75c9:	e8 e2 ad ff ff       	call   23b0 <fclose@plt>
    75ce:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    75d5:	48 8b 15 4c 9a 00 00 	mov    rdx,QWORD PTR [rip+0x9a4c]        # 11028 <stdout@GLIBC_2.2.5>
    75dc:	48 89 d6             	mov    rsi,rdx
    75df:	48 89 c7             	mov    rdi,rax
    75e2:	e8 f9 ad ff ff       	call   23e0 <fputs@plt>
    75e7:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    75ee:	48 89 c7             	mov    rdi,rax
    75f1:	e8 ba ad ff ff       	call   23b0 <fclose@plt>
    75f6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    75fd:	48 89 c7             	mov    rdi,rax
    7600:	e8 2b ad ff ff       	call   2330 <free@plt>
    7605:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    760c:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    7610:	f3 0f 10 05 84 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d84]        # e39c <__func__.0+0xc>
    7617:	00 
    7618:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    761c:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    7623:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    7627:	48 83 c0 04          	add    rax,0x4
    762b:	f3 0f 10 05 6d 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d6d]        # e3a0 <__func__.0+0x10>
    7632:	00 
    7633:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    7637:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    763e:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    7642:	48 83 c0 08          	add    rax,0x8
    7646:	f3 0f 10 05 56 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d56]        # e3a4 <__func__.0+0x14>
    764d:	00 
    764e:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    7652:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    7659:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    765d:	48 83 c0 0c          	add    rax,0xc
    7661:	f3 0f 10 05 3f 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d3f]        # e3a8 <__func__.0+0x18>
    7668:	00 
    7669:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    766d:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    7674:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    7678:	48 83 c0 10          	add    rax,0x10
    767c:	f3 0f 10 05 28 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d28]        # e3ac <__func__.0+0x1c>
    7683:	00 
    7684:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    7688:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    768f:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    7693:	48 83 c0 14          	add    rax,0x14
    7697:	f3 0f 10 05 0d 6d 00 	movss  xmm0,DWORD PTR [rip+0x6d0d]        # e3ac <__func__.0+0x1c>
    769e:	00 
    769f:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    76a3:	0f b6 05 e6 99 00 00 	movzx  eax,BYTE PTR [rip+0x99e6]        # 11090 <is_parallel_nb@@Base>
    76aa:	83 f0 01             	xor    eax,0x1
    76ad:	84 c0                	test   al,al
    76af:	0f 84 f4 06 00 00    	je     7da9 <TEST_not_permutation_____2+0x19b3>
    76b5:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    76bc:	48 89 c7             	mov    rdi,rax
    76bf:	e8 01 4e 00 00       	call   c4c5 <IS_PERMUTATION_TYPE_FLOAT>
    76c4:	0f b6 c0             	movzx  eax,al
    76c7:	89 c7                	mov    edi,eax
    76c9:	e8 f2 ad ff ff       	call   24c0 <expected_false_f@plt>
    76ce:	84 c0                	test   al,al
    76d0:	0f 84 57 02 00 00    	je     792d <TEST_not_permutation_____2+0x1537>
    76d6:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    76dd:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    76e4:	48 89 d6             	mov    rsi,rdx
    76e7:	48 89 c7             	mov    rdi,rax
    76ea:	e8 61 ac ff ff       	call   2350 <open_memstream@plt>
    76ef:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
    76f3:	48 83 7d d0 00       	cmp    QWORD PTR [rbp-0x30],0x0
    76f8:	75 38                	jne    7732 <TEST_not_permutation_____2+0x133c>
    76fa:	48 8b 05 ff 99 00 00 	mov    rax,QWORD PTR [rip+0x99ff]        # 11100 <stderr@GLIBC_2.2.5>
    7701:	4c 8d 05 48 6c 00 00 	lea    r8,[rip+0x6c48]        # e350 <__func__.2>
    7708:	b9 50 00 00 00       	mov    ecx,0x50
    770d:	48 8d 15 30 69 00 00 	lea    rdx,[rip+0x6930]        # e044 <_IO_stdin_used+0x44>
    7714:	48 8d 35 35 69 00 00 	lea    rsi,[rip+0x6935]        # e050 <_IO_stdin_used+0x50>
    771b:	48 89 c7             	mov    rdi,rax
    771e:	b8 00 00 00 00       	mov    eax,0x0
    7723:	e8 38 ad ff ff       	call   2460 <fprintf@plt>
    7728:	bf 00 00 00 00       	mov    edi,0x0
    772d:	e8 ee ad ff ff       	call   2520 <exit@plt>
    7732:	8b 05 68 99 00 00    	mov    eax,DWORD PTR [rip+0x9968]        # 110a0 <k_DEFAULT@@Base>
    7738:	48 98                	cdqe   
    773a:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7741:	00 
    7742:	48 8d 05 77 99 00 00 	lea    rax,[rip+0x9977]        # 110c0 <colors_f@@Base>
    7749:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    774d:	8b 05 2d 99 00 00    	mov    eax,DWORD PTR [rip+0x992d]        # 11080 <hk_TR@@Base>
    7753:	48 98                	cdqe   
    7755:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    775c:	00 
    775d:	48 8d 05 dc 98 00 00 	lea    rax,[rip+0x98dc]        # 11040 <tab_hk_f@@Base>
    7764:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    7768:	8b 05 82 99 00 00    	mov    eax,DWORD PTR [rip+0x9982]        # 110f0 <k_GREEN@@Base>
    776e:	48 98                	cdqe   
    7770:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7777:	00 
    7778:	48 8d 05 41 99 00 00 	lea    rax,[rip+0x9941]        # 110c0 <colors_f@@Base>
    777f:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    7783:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    7787:	4c 8d 0d c2 6b 00 00 	lea    r9,[rip+0x6bc2]        # e350 <__func__.2>
    778e:	49 89 f0             	mov    r8,rsi
    7791:	48 8d 35 f0 68 00 00 	lea    rsi,[rip+0x68f0]        # e088 <_IO_stdin_used+0x88>
    7798:	48 89 c7             	mov    rdi,rax
    779b:	b8 00 00 00 00       	mov    eax,0x0
    77a0:	e8 bb ac ff ff       	call   2460 <fprintf@plt>
    77a5:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    77a9:	48 89 c7             	mov    rdi,rax
    77ac:	e8 df ac ff ff       	call   2490 <fflush@plt>
    77b1:	0f b6 05 d8 98 00 00 	movzx  eax,BYTE PTR [rip+0x98d8]        # 11090 <is_parallel_nb@@Base>
    77b8:	84 c0                	test   al,al
    77ba:	0f 84 e9 00 00 00    	je     78a9 <TEST_not_permutation_____2+0x14b3>
    77c0:	e8 8b ac ff ff       	call   2450 <id_of_thread_executed@plt>
    77c5:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    77c9:	0f b6 05 50 98 00 00 	movzx  eax,BYTE PTR [rip+0x9850]        # 11020 <log_parallel@@Base>
    77d0:	84 c0                	test   al,al
    77d2:	74 6d                	je     7841 <TEST_not_permutation_____2+0x144b>
    77d4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    77db:	48 8b 15 46 98 00 00 	mov    rdx,QWORD PTR [rip+0x9846]        # 11028 <stdout@GLIBC_2.2.5>
    77e2:	48 89 d6             	mov    rsi,rdx
    77e5:	48 89 c7             	mov    rdi,rax
    77e8:	e8 f3 ab ff ff       	call   23e0 <fputs@plt>
    77ed:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    77f2:	0f 88 15 01 00 00    	js     790d <TEST_not_permutation_____2+0x1517>
    77f8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    77ff:	48 8b 0d 2a 98 00 00 	mov    rcx,QWORD PTR [rip+0x982a]        # 11030 <f_ou_th@@Base>
    7806:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    780a:	48 c1 e2 03          	shl    rdx,0x3
    780e:	48 01 ca             	add    rdx,rcx
    7811:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7814:	48 89 d6             	mov    rsi,rdx
    7817:	48 89 c7             	mov    rdi,rax
    781a:	e8 c1 ab ff ff       	call   23e0 <fputs@plt>
    781f:	48 8b 15 0a 98 00 00 	mov    rdx,QWORD PTR [rip+0x980a]        # 11030 <f_ou_th@@Base>
    7826:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    782a:	48 c1 e0 03          	shl    rax,0x3
    782e:	48 01 d0             	add    rax,rdx
    7831:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7834:	48 89 c7             	mov    rdi,rax
    7837:	e8 54 ac ff ff       	call   2490 <fflush@plt>
    783c:	e9 cc 00 00 00       	jmp    790d <TEST_not_permutation_____2+0x1517>
    7841:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    7846:	78 46                	js     788e <TEST_not_permutation_____2+0x1498>
    7848:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    784f:	48 8b 0d da 97 00 00 	mov    rcx,QWORD PTR [rip+0x97da]        # 11030 <f_ou_th@@Base>
    7856:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    785a:	48 c1 e2 03          	shl    rdx,0x3
    785e:	48 01 ca             	add    rdx,rcx
    7861:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7864:	48 89 d6             	mov    rsi,rdx
    7867:	48 89 c7             	mov    rdi,rax
    786a:	e8 71 ab ff ff       	call   23e0 <fputs@plt>
    786f:	48 8b 15 ba 97 00 00 	mov    rdx,QWORD PTR [rip+0x97ba]        # 11030 <f_ou_th@@Base>
    7876:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    787a:	48 c1 e0 03          	shl    rax,0x3
    787e:	48 01 d0             	add    rax,rdx
    7881:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7884:	48 89 c7             	mov    rdi,rax
    7887:	e8 04 ac ff ff       	call   2490 <fflush@plt>
    788c:	eb 7f                	jmp    790d <TEST_not_permutation_____2+0x1517>
    788e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7895:	48 8b 15 8c 97 00 00 	mov    rdx,QWORD PTR [rip+0x978c]        # 11028 <stdout@GLIBC_2.2.5>
    789c:	48 89 d6             	mov    rsi,rdx
    789f:	48 89 c7             	mov    rdi,rax
    78a2:	e8 39 ab ff ff       	call   23e0 <fputs@plt>
    78a7:	eb 64                	jmp    790d <TEST_not_permutation_____2+0x1517>
    78a9:	48 8b 05 88 97 00 00 	mov    rax,QWORD PTR [rip+0x9788]        # 11038 <savelog@@Base>
    78b0:	48 85 c0             	test   rax,rax
    78b3:	74 3f                	je     78f4 <TEST_not_permutation_____2+0x14fe>
    78b5:	48 8b 05 7c 97 00 00 	mov    rax,QWORD PTR [rip+0x977c]        # 11038 <savelog@@Base>
    78bc:	48 8d 15 bc 67 00 00 	lea    rdx,[rip+0x67bc]        # e07f <_IO_stdin_used+0x7f>
    78c3:	48 89 d6             	mov    rsi,rdx
    78c6:	48 89 c7             	mov    rdi,rax
    78c9:	e8 32 ac ff ff       	call   2500 <fopen@plt>
    78ce:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    78d2:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    78d9:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    78dd:	48 89 d6             	mov    rsi,rdx
    78e0:	48 89 c7             	mov    rdi,rax
    78e3:	e8 f8 aa ff ff       	call   23e0 <fputs@plt>
    78e8:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    78ec:	48 89 c7             	mov    rdi,rax
    78ef:	e8 bc aa ff ff       	call   23b0 <fclose@plt>
    78f4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    78fb:	48 8b 15 26 97 00 00 	mov    rdx,QWORD PTR [rip+0x9726]        # 11028 <stdout@GLIBC_2.2.5>
    7902:	48 89 d6             	mov    rsi,rdx
    7905:	48 89 c7             	mov    rdi,rax
    7908:	e8 d3 aa ff ff       	call   23e0 <fputs@plt>
    790d:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    7911:	48 89 c7             	mov    rdi,rax
    7914:	e8 97 aa ff ff       	call   23b0 <fclose@plt>
    7919:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7920:	48 89 c7             	mov    rdi,rax
    7923:	e8 08 aa ff ff       	call   2330 <free@plt>
    7928:	e9 e8 0b 00 00       	jmp    8515 <TEST_not_permutation_____2+0x211f>
    792d:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    7934:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    793b:	48 89 d6             	mov    rsi,rdx
    793e:	48 89 c7             	mov    rdi,rax
    7941:	e8 0a aa ff ff       	call   2350 <open_memstream@plt>
    7946:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
    794a:	48 83 7d a0 00       	cmp    QWORD PTR [rbp-0x60],0x0
    794f:	75 38                	jne    7989 <TEST_not_permutation_____2+0x1593>
    7951:	48 8b 05 a8 97 00 00 	mov    rax,QWORD PTR [rip+0x97a8]        # 11100 <stderr@GLIBC_2.2.5>
    7958:	4c 8d 05 f1 69 00 00 	lea    r8,[rip+0x69f1]        # e350 <__func__.2>
    795f:	b9 50 00 00 00       	mov    ecx,0x50
    7964:	48 8d 15 d9 66 00 00 	lea    rdx,[rip+0x66d9]        # e044 <_IO_stdin_used+0x44>
    796b:	48 8d 35 de 66 00 00 	lea    rsi,[rip+0x66de]        # e050 <_IO_stdin_used+0x50>
    7972:	48 89 c7             	mov    rdi,rax
    7975:	b8 00 00 00 00       	mov    eax,0x0
    797a:	e8 e1 aa ff ff       	call   2460 <fprintf@plt>
    797f:	bf 00 00 00 00       	mov    edi,0x0
    7984:	e8 97 ab ff ff       	call   2520 <exit@plt>
    7989:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    798d:	48 8d 15 7e 68 00 00 	lea    rdx,[rip+0x687e]        # e212 <_IO_stdin_used+0x212>
    7994:	52                   	push   rdx
    7995:	48 8d 15 7c 68 00 00 	lea    rdx,[rip+0x687c]        # e218 <_IO_stdin_used+0x218>
    799c:	52                   	push   rdx
    799d:	4c 8d 0d 10 68 00 00 	lea    r9,[rip+0x6810]        # e1b4 <_IO_stdin_used+0x1b4>
    79a4:	4c 8d 05 a5 69 00 00 	lea    r8,[rip+0x69a5]        # e350 <__func__.2>
    79ab:	b9 50 00 00 00       	mov    ecx,0x50
    79b0:	48 8d 15 8d 66 00 00 	lea    rdx,[rip+0x668d]        # e044 <_IO_stdin_used+0x44>
    79b7:	48 8d 35 1a 68 00 00 	lea    rsi,[rip+0x681a]        # e1d8 <_IO_stdin_used+0x1d8>
    79be:	48 89 c7             	mov    rdi,rax
    79c1:	b8 00 00 00 00       	mov    eax,0x0
    79c6:	e8 95 aa ff ff       	call   2460 <fprintf@plt>
    79cb:	48 83 c4 10          	add    rsp,0x10
    79cf:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    79d3:	48 89 c7             	mov    rdi,rax
    79d6:	e8 b5 aa ff ff       	call   2490 <fflush@plt>
    79db:	0f b6 05 ae 96 00 00 	movzx  eax,BYTE PTR [rip+0x96ae]        # 11090 <is_parallel_nb@@Base>
    79e2:	84 c0                	test   al,al
    79e4:	0f 84 e9 00 00 00    	je     7ad3 <TEST_not_permutation_____2+0x16dd>
    79ea:	e8 61 aa ff ff       	call   2450 <id_of_thread_executed@plt>
    79ef:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
    79f3:	0f b6 05 26 96 00 00 	movzx  eax,BYTE PTR [rip+0x9626]        # 11020 <log_parallel@@Base>
    79fa:	84 c0                	test   al,al
    79fc:	74 6d                	je     7a6b <TEST_not_permutation_____2+0x1675>
    79fe:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7a05:	48 8b 15 1c 96 00 00 	mov    rdx,QWORD PTR [rip+0x961c]        # 11028 <stdout@GLIBC_2.2.5>
    7a0c:	48 89 d6             	mov    rsi,rdx
    7a0f:	48 89 c7             	mov    rdi,rax
    7a12:	e8 c9 a9 ff ff       	call   23e0 <fputs@plt>
    7a17:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    7a1c:	0f 88 15 01 00 00    	js     7b37 <TEST_not_permutation_____2+0x1741>
    7a22:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7a29:	48 8b 0d 00 96 00 00 	mov    rcx,QWORD PTR [rip+0x9600]        # 11030 <f_ou_th@@Base>
    7a30:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    7a34:	48 c1 e2 03          	shl    rdx,0x3
    7a38:	48 01 ca             	add    rdx,rcx
    7a3b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7a3e:	48 89 d6             	mov    rsi,rdx
    7a41:	48 89 c7             	mov    rdi,rax
    7a44:	e8 97 a9 ff ff       	call   23e0 <fputs@plt>
    7a49:	48 8b 15 e0 95 00 00 	mov    rdx,QWORD PTR [rip+0x95e0]        # 11030 <f_ou_th@@Base>
    7a50:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    7a54:	48 c1 e0 03          	shl    rax,0x3
    7a58:	48 01 d0             	add    rax,rdx
    7a5b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7a5e:	48 89 c7             	mov    rdi,rax
    7a61:	e8 2a aa ff ff       	call   2490 <fflush@plt>
    7a66:	e9 cc 00 00 00       	jmp    7b37 <TEST_not_permutation_____2+0x1741>
    7a6b:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    7a70:	78 46                	js     7ab8 <TEST_not_permutation_____2+0x16c2>
    7a72:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7a79:	48 8b 0d b0 95 00 00 	mov    rcx,QWORD PTR [rip+0x95b0]        # 11030 <f_ou_th@@Base>
    7a80:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    7a84:	48 c1 e2 03          	shl    rdx,0x3
    7a88:	48 01 ca             	add    rdx,rcx
    7a8b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7a8e:	48 89 d6             	mov    rsi,rdx
    7a91:	48 89 c7             	mov    rdi,rax
    7a94:	e8 47 a9 ff ff       	call   23e0 <fputs@plt>
    7a99:	48 8b 15 90 95 00 00 	mov    rdx,QWORD PTR [rip+0x9590]        # 11030 <f_ou_th@@Base>
    7aa0:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    7aa4:	48 c1 e0 03          	shl    rax,0x3
    7aa8:	48 01 d0             	add    rax,rdx
    7aab:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7aae:	48 89 c7             	mov    rdi,rax
    7ab1:	e8 da a9 ff ff       	call   2490 <fflush@plt>
    7ab6:	eb 7f                	jmp    7b37 <TEST_not_permutation_____2+0x1741>
    7ab8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7abf:	48 8b 15 62 95 00 00 	mov    rdx,QWORD PTR [rip+0x9562]        # 11028 <stdout@GLIBC_2.2.5>
    7ac6:	48 89 d6             	mov    rsi,rdx
    7ac9:	48 89 c7             	mov    rdi,rax
    7acc:	e8 0f a9 ff ff       	call   23e0 <fputs@plt>
    7ad1:	eb 64                	jmp    7b37 <TEST_not_permutation_____2+0x1741>
    7ad3:	48 8b 05 5e 95 00 00 	mov    rax,QWORD PTR [rip+0x955e]        # 11038 <savelog@@Base>
    7ada:	48 85 c0             	test   rax,rax
    7add:	74 3f                	je     7b1e <TEST_not_permutation_____2+0x1728>
    7adf:	48 8b 05 52 95 00 00 	mov    rax,QWORD PTR [rip+0x9552]        # 11038 <savelog@@Base>
    7ae6:	48 8d 15 92 65 00 00 	lea    rdx,[rip+0x6592]        # e07f <_IO_stdin_used+0x7f>
    7aed:	48 89 d6             	mov    rsi,rdx
    7af0:	48 89 c7             	mov    rdi,rax
    7af3:	e8 08 aa ff ff       	call   2500 <fopen@plt>
    7af8:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    7afc:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7b03:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
    7b07:	48 89 d6             	mov    rsi,rdx
    7b0a:	48 89 c7             	mov    rdi,rax
    7b0d:	e8 ce a8 ff ff       	call   23e0 <fputs@plt>
    7b12:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    7b16:	48 89 c7             	mov    rdi,rax
    7b19:	e8 92 a8 ff ff       	call   23b0 <fclose@plt>
    7b1e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7b25:	48 8b 15 fc 94 00 00 	mov    rdx,QWORD PTR [rip+0x94fc]        # 11028 <stdout@GLIBC_2.2.5>
    7b2c:	48 89 d6             	mov    rsi,rdx
    7b2f:	48 89 c7             	mov    rdi,rax
    7b32:	e8 a9 a8 ff ff       	call   23e0 <fputs@plt>
    7b37:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    7b3b:	48 89 c7             	mov    rdi,rax
    7b3e:	e8 6d a8 ff ff       	call   23b0 <fclose@plt>
    7b43:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7b4a:	48 89 c7             	mov    rdi,rax
    7b4d:	e8 de a7 ff ff       	call   2330 <free@plt>
    7b52:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    7b59:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    7b60:	48 89 d6             	mov    rsi,rdx
    7b63:	48 89 c7             	mov    rdi,rax
    7b66:	e8 e5 a7 ff ff       	call   2350 <open_memstream@plt>
    7b6b:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
    7b6f:	48 83 7d b8 00       	cmp    QWORD PTR [rbp-0x48],0x0
    7b74:	75 38                	jne    7bae <TEST_not_permutation_____2+0x17b8>
    7b76:	48 8b 05 83 95 00 00 	mov    rax,QWORD PTR [rip+0x9583]        # 11100 <stderr@GLIBC_2.2.5>
    7b7d:	4c 8d 05 cc 67 00 00 	lea    r8,[rip+0x67cc]        # e350 <__func__.2>
    7b84:	b9 50 00 00 00       	mov    ecx,0x50
    7b89:	48 8d 15 b4 64 00 00 	lea    rdx,[rip+0x64b4]        # e044 <_IO_stdin_used+0x44>
    7b90:	48 8d 35 b9 64 00 00 	lea    rsi,[rip+0x64b9]        # e050 <_IO_stdin_used+0x50>
    7b97:	48 89 c7             	mov    rdi,rax
    7b9a:	b8 00 00 00 00       	mov    eax,0x0
    7b9f:	e8 bc a8 ff ff       	call   2460 <fprintf@plt>
    7ba4:	bf 00 00 00 00       	mov    edi,0x0
    7ba9:	e8 72 a9 ff ff       	call   2520 <exit@plt>
    7bae:	8b 05 ec 94 00 00    	mov    eax,DWORD PTR [rip+0x94ec]        # 110a0 <k_DEFAULT@@Base>
    7bb4:	48 98                	cdqe   
    7bb6:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7bbd:	00 
    7bbe:	48 8d 05 fb 94 00 00 	lea    rax,[rip+0x94fb]        # 110c0 <colors_f@@Base>
    7bc5:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    7bc9:	8b 05 b1 94 00 00    	mov    eax,DWORD PTR [rip+0x94b1]        # 11080 <hk_TR@@Base>
    7bcf:	48 98                	cdqe   
    7bd1:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7bd8:	00 
    7bd9:	48 8d 05 60 94 00 00 	lea    rax,[rip+0x9460]        # 11040 <tab_hk_f@@Base>
    7be0:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    7be4:	8b 05 9a 94 00 00    	mov    eax,DWORD PTR [rip+0x949a]        # 11084 <k_RED@@Base>
    7bea:	48 98                	cdqe   
    7bec:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7bf3:	00 
    7bf4:	48 8d 05 c5 94 00 00 	lea    rax,[rip+0x94c5]        # 110c0 <colors_f@@Base>
    7bfb:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    7bff:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    7c03:	4c 8d 0d 46 67 00 00 	lea    r9,[rip+0x6746]        # e350 <__func__.2>
    7c0a:	49 89 f0             	mov    r8,rsi
    7c0d:	48 8d 35 0c 66 00 00 	lea    rsi,[rip+0x660c]        # e220 <_IO_stdin_used+0x220>
    7c14:	48 89 c7             	mov    rdi,rax
    7c17:	b8 00 00 00 00       	mov    eax,0x0
    7c1c:	e8 3f a8 ff ff       	call   2460 <fprintf@plt>
    7c21:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    7c25:	48 89 c7             	mov    rdi,rax
    7c28:	e8 63 a8 ff ff       	call   2490 <fflush@plt>
    7c2d:	0f b6 05 5c 94 00 00 	movzx  eax,BYTE PTR [rip+0x945c]        # 11090 <is_parallel_nb@@Base>
    7c34:	84 c0                	test   al,al
    7c36:	0f 84 e9 00 00 00    	je     7d25 <TEST_not_permutation_____2+0x192f>
    7c3c:	e8 0f a8 ff ff       	call   2450 <id_of_thread_executed@plt>
    7c41:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
    7c45:	0f b6 05 d4 93 00 00 	movzx  eax,BYTE PTR [rip+0x93d4]        # 11020 <log_parallel@@Base>
    7c4c:	84 c0                	test   al,al
    7c4e:	74 6d                	je     7cbd <TEST_not_permutation_____2+0x18c7>
    7c50:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7c57:	48 8b 15 ca 93 00 00 	mov    rdx,QWORD PTR [rip+0x93ca]        # 11028 <stdout@GLIBC_2.2.5>
    7c5e:	48 89 d6             	mov    rsi,rdx
    7c61:	48 89 c7             	mov    rdi,rax
    7c64:	e8 77 a7 ff ff       	call   23e0 <fputs@plt>
    7c69:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    7c6e:	0f 88 15 01 00 00    	js     7d89 <TEST_not_permutation_____2+0x1993>
    7c74:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7c7b:	48 8b 0d ae 93 00 00 	mov    rcx,QWORD PTR [rip+0x93ae]        # 11030 <f_ou_th@@Base>
    7c82:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    7c86:	48 c1 e2 03          	shl    rdx,0x3
    7c8a:	48 01 ca             	add    rdx,rcx
    7c8d:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7c90:	48 89 d6             	mov    rsi,rdx
    7c93:	48 89 c7             	mov    rdi,rax
    7c96:	e8 45 a7 ff ff       	call   23e0 <fputs@plt>
    7c9b:	48 8b 15 8e 93 00 00 	mov    rdx,QWORD PTR [rip+0x938e]        # 11030 <f_ou_th@@Base>
    7ca2:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    7ca6:	48 c1 e0 03          	shl    rax,0x3
    7caa:	48 01 d0             	add    rax,rdx
    7cad:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7cb0:	48 89 c7             	mov    rdi,rax
    7cb3:	e8 d8 a7 ff ff       	call   2490 <fflush@plt>
    7cb8:	e9 cc 00 00 00       	jmp    7d89 <TEST_not_permutation_____2+0x1993>
    7cbd:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    7cc2:	78 46                	js     7d0a <TEST_not_permutation_____2+0x1914>
    7cc4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7ccb:	48 8b 0d 5e 93 00 00 	mov    rcx,QWORD PTR [rip+0x935e]        # 11030 <f_ou_th@@Base>
    7cd2:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    7cd6:	48 c1 e2 03          	shl    rdx,0x3
    7cda:	48 01 ca             	add    rdx,rcx
    7cdd:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7ce0:	48 89 d6             	mov    rsi,rdx
    7ce3:	48 89 c7             	mov    rdi,rax
    7ce6:	e8 f5 a6 ff ff       	call   23e0 <fputs@plt>
    7ceb:	48 8b 15 3e 93 00 00 	mov    rdx,QWORD PTR [rip+0x933e]        # 11030 <f_ou_th@@Base>
    7cf2:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    7cf6:	48 c1 e0 03          	shl    rax,0x3
    7cfa:	48 01 d0             	add    rax,rdx
    7cfd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7d00:	48 89 c7             	mov    rdi,rax
    7d03:	e8 88 a7 ff ff       	call   2490 <fflush@plt>
    7d08:	eb 7f                	jmp    7d89 <TEST_not_permutation_____2+0x1993>
    7d0a:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7d11:	48 8b 15 10 93 00 00 	mov    rdx,QWORD PTR [rip+0x9310]        # 11028 <stdout@GLIBC_2.2.5>
    7d18:	48 89 d6             	mov    rsi,rdx
    7d1b:	48 89 c7             	mov    rdi,rax
    7d1e:	e8 bd a6 ff ff       	call   23e0 <fputs@plt>
    7d23:	eb 64                	jmp    7d89 <TEST_not_permutation_____2+0x1993>
    7d25:	48 8b 05 0c 93 00 00 	mov    rax,QWORD PTR [rip+0x930c]        # 11038 <savelog@@Base>
    7d2c:	48 85 c0             	test   rax,rax
    7d2f:	74 3f                	je     7d70 <TEST_not_permutation_____2+0x197a>
    7d31:	48 8b 05 00 93 00 00 	mov    rax,QWORD PTR [rip+0x9300]        # 11038 <savelog@@Base>
    7d38:	48 8d 15 40 63 00 00 	lea    rdx,[rip+0x6340]        # e07f <_IO_stdin_used+0x7f>
    7d3f:	48 89 d6             	mov    rsi,rdx
    7d42:	48 89 c7             	mov    rdi,rax
    7d45:	e8 b6 a7 ff ff       	call   2500 <fopen@plt>
    7d4a:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
    7d4e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7d55:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
    7d59:	48 89 d6             	mov    rsi,rdx
    7d5c:	48 89 c7             	mov    rdi,rax
    7d5f:	e8 7c a6 ff ff       	call   23e0 <fputs@plt>
    7d64:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
    7d68:	48 89 c7             	mov    rdi,rax
    7d6b:	e8 40 a6 ff ff       	call   23b0 <fclose@plt>
    7d70:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7d77:	48 8b 15 aa 92 00 00 	mov    rdx,QWORD PTR [rip+0x92aa]        # 11028 <stdout@GLIBC_2.2.5>
    7d7e:	48 89 d6             	mov    rsi,rdx
    7d81:	48 89 c7             	mov    rdi,rax
    7d84:	e8 57 a6 ff ff       	call   23e0 <fputs@plt>
    7d89:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    7d8d:	48 89 c7             	mov    rdi,rax
    7d90:	e8 1b a6 ff ff       	call   23b0 <fclose@plt>
    7d95:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7d9c:	48 89 c7             	mov    rdi,rax
    7d9f:	e8 8c a5 ff ff       	call   2330 <free@plt>
    7da4:	e9 6c 07 00 00       	jmp    8515 <TEST_not_permutation_____2+0x211f>
    7da9:	e8 a2 a6 ff ff       	call   2450 <id_of_thread_executed@plt>
    7dae:	48 89 85 50 ff ff ff 	mov    QWORD PTR [rbp-0xb0],rax
    7db5:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    7dbc:	48 89 c7             	mov    rdi,rax
    7dbf:	e8 01 47 00 00       	call   c4c5 <IS_PERMUTATION_TYPE_FLOAT>
    7dc4:	0f b6 c0             	movzx  eax,al
    7dc7:	48 8d 15 82 65 00 00 	lea    rdx,[rip+0x6582]        # e350 <__func__.2>
    7dce:	48 89 d6             	mov    rsi,rdx
    7dd1:	89 c7                	mov    edi,eax
    7dd3:	e8 08 a7 ff ff       	call   24e0 <expected_false_f_name@plt>
    7dd8:	84 c0                	test   al,al
    7dda:	0f 84 65 02 00 00    	je     8045 <TEST_not_permutation_____2+0x1c4f>
    7de0:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    7de7:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    7dee:	48 89 d6             	mov    rsi,rdx
    7df1:	48 89 c7             	mov    rdi,rax
    7df4:	e8 57 a5 ff ff       	call   2350 <open_memstream@plt>
    7df9:	48 89 45 88          	mov    QWORD PTR [rbp-0x78],rax
    7dfd:	48 83 7d 88 00       	cmp    QWORD PTR [rbp-0x78],0x0
    7e02:	75 38                	jne    7e3c <TEST_not_permutation_____2+0x1a46>
    7e04:	48 8b 05 f5 92 00 00 	mov    rax,QWORD PTR [rip+0x92f5]        # 11100 <stderr@GLIBC_2.2.5>
    7e0b:	4c 8d 05 3e 65 00 00 	lea    r8,[rip+0x653e]        # e350 <__func__.2>
    7e12:	b9 50 00 00 00       	mov    ecx,0x50
    7e17:	48 8d 15 26 62 00 00 	lea    rdx,[rip+0x6226]        # e044 <_IO_stdin_used+0x44>
    7e1e:	48 8d 35 2b 62 00 00 	lea    rsi,[rip+0x622b]        # e050 <_IO_stdin_used+0x50>
    7e25:	48 89 c7             	mov    rdi,rax
    7e28:	b8 00 00 00 00       	mov    eax,0x0
    7e2d:	e8 2e a6 ff ff       	call   2460 <fprintf@plt>
    7e32:	bf 00 00 00 00       	mov    edi,0x0
    7e37:	e8 e4 a6 ff ff       	call   2520 <exit@plt>
    7e3c:	8b 05 5e 92 00 00    	mov    eax,DWORD PTR [rip+0x925e]        # 110a0 <k_DEFAULT@@Base>
    7e42:	48 98                	cdqe   
    7e44:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7e4b:	00 
    7e4c:	48 8d 05 6d 92 00 00 	lea    rax,[rip+0x926d]        # 110c0 <colors_f@@Base>
    7e53:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    7e57:	8b 05 23 92 00 00    	mov    eax,DWORD PTR [rip+0x9223]        # 11080 <hk_TR@@Base>
    7e5d:	48 98                	cdqe   
    7e5f:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7e66:	00 
    7e67:	48 8d 05 d2 91 00 00 	lea    rax,[rip+0x91d2]        # 11040 <tab_hk_f@@Base>
    7e6e:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    7e72:	8b 05 78 92 00 00    	mov    eax,DWORD PTR [rip+0x9278]        # 110f0 <k_GREEN@@Base>
    7e78:	48 98                	cdqe   
    7e7a:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    7e81:	00 
    7e82:	48 8d 05 37 92 00 00 	lea    rax,[rip+0x9237]        # 110c0 <colors_f@@Base>
    7e89:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    7e8d:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    7e91:	48 83 ec 08          	sub    rsp,0x8
    7e95:	ff b5 50 ff ff ff    	push   QWORD PTR [rbp-0xb0]
    7e9b:	4c 8d 0d ae 64 00 00 	lea    r9,[rip+0x64ae]        # e350 <__func__.2>
    7ea2:	49 89 f0             	mov    r8,rsi
    7ea5:	48 8d 35 94 63 00 00 	lea    rsi,[rip+0x6394]        # e240 <_IO_stdin_used+0x240>
    7eac:	48 89 c7             	mov    rdi,rax
    7eaf:	b8 00 00 00 00       	mov    eax,0x0
    7eb4:	e8 a7 a5 ff ff       	call   2460 <fprintf@plt>
    7eb9:	48 83 c4 10          	add    rsp,0x10
    7ebd:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    7ec1:	48 89 c7             	mov    rdi,rax
    7ec4:	e8 c7 a5 ff ff       	call   2490 <fflush@plt>
    7ec9:	0f b6 05 c0 91 00 00 	movzx  eax,BYTE PTR [rip+0x91c0]        # 11090 <is_parallel_nb@@Base>
    7ed0:	84 c0                	test   al,al
    7ed2:	0f 84 e9 00 00 00    	je     7fc1 <TEST_not_permutation_____2+0x1bcb>
    7ed8:	e8 73 a5 ff ff       	call   2450 <id_of_thread_executed@plt>
    7edd:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
    7ee1:	0f b6 05 38 91 00 00 	movzx  eax,BYTE PTR [rip+0x9138]        # 11020 <log_parallel@@Base>
    7ee8:	84 c0                	test   al,al
    7eea:	74 6d                	je     7f59 <TEST_not_permutation_____2+0x1b63>
    7eec:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7ef3:	48 8b 15 2e 91 00 00 	mov    rdx,QWORD PTR [rip+0x912e]        # 11028 <stdout@GLIBC_2.2.5>
    7efa:	48 89 d6             	mov    rsi,rdx
    7efd:	48 89 c7             	mov    rdi,rax
    7f00:	e8 db a4 ff ff       	call   23e0 <fputs@plt>
    7f05:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    7f0a:	0f 88 15 01 00 00    	js     8025 <TEST_not_permutation_____2+0x1c2f>
    7f10:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7f17:	48 8b 0d 12 91 00 00 	mov    rcx,QWORD PTR [rip+0x9112]        # 11030 <f_ou_th@@Base>
    7f1e:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    7f22:	48 c1 e2 03          	shl    rdx,0x3
    7f26:	48 01 ca             	add    rdx,rcx
    7f29:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7f2c:	48 89 d6             	mov    rsi,rdx
    7f2f:	48 89 c7             	mov    rdi,rax
    7f32:	e8 a9 a4 ff ff       	call   23e0 <fputs@plt>
    7f37:	48 8b 15 f2 90 00 00 	mov    rdx,QWORD PTR [rip+0x90f2]        # 11030 <f_ou_th@@Base>
    7f3e:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    7f42:	48 c1 e0 03          	shl    rax,0x3
    7f46:	48 01 d0             	add    rax,rdx
    7f49:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7f4c:	48 89 c7             	mov    rdi,rax
    7f4f:	e8 3c a5 ff ff       	call   2490 <fflush@plt>
    7f54:	e9 cc 00 00 00       	jmp    8025 <TEST_not_permutation_____2+0x1c2f>
    7f59:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    7f5e:	78 46                	js     7fa6 <TEST_not_permutation_____2+0x1bb0>
    7f60:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7f67:	48 8b 0d c2 90 00 00 	mov    rcx,QWORD PTR [rip+0x90c2]        # 11030 <f_ou_th@@Base>
    7f6e:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    7f72:	48 c1 e2 03          	shl    rdx,0x3
    7f76:	48 01 ca             	add    rdx,rcx
    7f79:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    7f7c:	48 89 d6             	mov    rsi,rdx
    7f7f:	48 89 c7             	mov    rdi,rax
    7f82:	e8 59 a4 ff ff       	call   23e0 <fputs@plt>
    7f87:	48 8b 15 a2 90 00 00 	mov    rdx,QWORD PTR [rip+0x90a2]        # 11030 <f_ou_th@@Base>
    7f8e:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    7f92:	48 c1 e0 03          	shl    rax,0x3
    7f96:	48 01 d0             	add    rax,rdx
    7f99:	48 8b 00             	mov    rax,QWORD PTR [rax]
    7f9c:	48 89 c7             	mov    rdi,rax
    7f9f:	e8 ec a4 ff ff       	call   2490 <fflush@plt>
    7fa4:	eb 7f                	jmp    8025 <TEST_not_permutation_____2+0x1c2f>
    7fa6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7fad:	48 8b 15 74 90 00 00 	mov    rdx,QWORD PTR [rip+0x9074]        # 11028 <stdout@GLIBC_2.2.5>
    7fb4:	48 89 d6             	mov    rsi,rdx
    7fb7:	48 89 c7             	mov    rdi,rax
    7fba:	e8 21 a4 ff ff       	call   23e0 <fputs@plt>
    7fbf:	eb 64                	jmp    8025 <TEST_not_permutation_____2+0x1c2f>
    7fc1:	48 8b 05 70 90 00 00 	mov    rax,QWORD PTR [rip+0x9070]        # 11038 <savelog@@Base>
    7fc8:	48 85 c0             	test   rax,rax
    7fcb:	74 3f                	je     800c <TEST_not_permutation_____2+0x1c16>
    7fcd:	48 8b 05 64 90 00 00 	mov    rax,QWORD PTR [rip+0x9064]        # 11038 <savelog@@Base>
    7fd4:	48 8d 15 a4 60 00 00 	lea    rdx,[rip+0x60a4]        # e07f <_IO_stdin_used+0x7f>
    7fdb:	48 89 d6             	mov    rsi,rdx
    7fde:	48 89 c7             	mov    rdi,rax
    7fe1:	e8 1a a5 ff ff       	call   2500 <fopen@plt>
    7fe6:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
    7fea:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    7ff1:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
    7ff5:	48 89 d6             	mov    rsi,rdx
    7ff8:	48 89 c7             	mov    rdi,rax
    7ffb:	e8 e0 a3 ff ff       	call   23e0 <fputs@plt>
    8000:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
    8004:	48 89 c7             	mov    rdi,rax
    8007:	e8 a4 a3 ff ff       	call   23b0 <fclose@plt>
    800c:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8013:	48 8b 15 0e 90 00 00 	mov    rdx,QWORD PTR [rip+0x900e]        # 11028 <stdout@GLIBC_2.2.5>
    801a:	48 89 d6             	mov    rsi,rdx
    801d:	48 89 c7             	mov    rdi,rax
    8020:	e8 bb a3 ff ff       	call   23e0 <fputs@plt>
    8025:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    8029:	48 89 c7             	mov    rdi,rax
    802c:	e8 7f a3 ff ff       	call   23b0 <fclose@plt>
    8031:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8038:	48 89 c7             	mov    rdi,rax
    803b:	e8 f0 a2 ff ff       	call   2330 <free@plt>
    8040:	e9 d0 04 00 00       	jmp    8515 <TEST_not_permutation_____2+0x211f>
    8045:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    804c:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    8053:	48 89 d6             	mov    rsi,rdx
    8056:	48 89 c7             	mov    rdi,rax
    8059:	e8 f2 a2 ff ff       	call   2350 <open_memstream@plt>
    805e:	48 89 85 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rax
    8065:	48 83 bd 58 ff ff ff 	cmp    QWORD PTR [rbp-0xa8],0x0
    806c:	00 
    806d:	75 38                	jne    80a7 <TEST_not_permutation_____2+0x1cb1>
    806f:	48 8b 05 8a 90 00 00 	mov    rax,QWORD PTR [rip+0x908a]        # 11100 <stderr@GLIBC_2.2.5>
    8076:	4c 8d 05 d3 62 00 00 	lea    r8,[rip+0x62d3]        # e350 <__func__.2>
    807d:	b9 50 00 00 00       	mov    ecx,0x50
    8082:	48 8d 15 bb 5f 00 00 	lea    rdx,[rip+0x5fbb]        # e044 <_IO_stdin_used+0x44>
    8089:	48 8d 35 c0 5f 00 00 	lea    rsi,[rip+0x5fc0]        # e050 <_IO_stdin_used+0x50>
    8090:	48 89 c7             	mov    rdi,rax
    8093:	b8 00 00 00 00       	mov    eax,0x0
    8098:	e8 c3 a3 ff ff       	call   2460 <fprintf@plt>
    809d:	bf 00 00 00 00       	mov    edi,0x0
    80a2:	e8 79 a4 ff ff       	call   2520 <exit@plt>
    80a7:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    80ae:	48 8d 15 5d 61 00 00 	lea    rdx,[rip+0x615d]        # e212 <_IO_stdin_used+0x212>
    80b5:	52                   	push   rdx
    80b6:	48 8d 15 5b 61 00 00 	lea    rdx,[rip+0x615b]        # e218 <_IO_stdin_used+0x218>
    80bd:	52                   	push   rdx
    80be:	4c 8d 0d ef 60 00 00 	lea    r9,[rip+0x60ef]        # e1b4 <_IO_stdin_used+0x1b4>
    80c5:	4c 8d 05 84 62 00 00 	lea    r8,[rip+0x6284]        # e350 <__func__.2>
    80cc:	b9 50 00 00 00       	mov    ecx,0x50
    80d1:	48 8d 15 6c 5f 00 00 	lea    rdx,[rip+0x5f6c]        # e044 <_IO_stdin_used+0x44>
    80d8:	48 8d 35 f9 60 00 00 	lea    rsi,[rip+0x60f9]        # e1d8 <_IO_stdin_used+0x1d8>
    80df:	48 89 c7             	mov    rdi,rax
    80e2:	b8 00 00 00 00       	mov    eax,0x0
    80e7:	e8 74 a3 ff ff       	call   2460 <fprintf@plt>
    80ec:	48 83 c4 10          	add    rsp,0x10
    80f0:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    80f7:	48 89 c7             	mov    rdi,rax
    80fa:	e8 91 a3 ff ff       	call   2490 <fflush@plt>
    80ff:	0f b6 05 8a 8f 00 00 	movzx  eax,BYTE PTR [rip+0x8f8a]        # 11090 <is_parallel_nb@@Base>
    8106:	84 c0                	test   al,al
    8108:	0f 84 01 01 00 00    	je     820f <TEST_not_permutation_____2+0x1e19>
    810e:	e8 3d a3 ff ff       	call   2450 <id_of_thread_executed@plt>
    8113:	48 89 85 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rax
    811a:	0f b6 05 ff 8e 00 00 	movzx  eax,BYTE PTR [rip+0x8eff]        # 11020 <log_parallel@@Base>
    8121:	84 c0                	test   al,al
    8123:	74 76                	je     819b <TEST_not_permutation_____2+0x1da5>
    8125:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    812c:	48 8b 15 f5 8e 00 00 	mov    rdx,QWORD PTR [rip+0x8ef5]        # 11028 <stdout@GLIBC_2.2.5>
    8133:	48 89 d6             	mov    rsi,rdx
    8136:	48 89 c7             	mov    rdi,rax
    8139:	e8 a2 a2 ff ff       	call   23e0 <fputs@plt>
    813e:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    8145:	00 
    8146:	0f 88 30 01 00 00    	js     827c <TEST_not_permutation_____2+0x1e86>
    814c:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8153:	48 8b 0d d6 8e 00 00 	mov    rcx,QWORD PTR [rip+0x8ed6]        # 11030 <f_ou_th@@Base>
    815a:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    8161:	48 c1 e2 03          	shl    rdx,0x3
    8165:	48 01 ca             	add    rdx,rcx
    8168:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    816b:	48 89 d6             	mov    rsi,rdx
    816e:	48 89 c7             	mov    rdi,rax
    8171:	e8 6a a2 ff ff       	call   23e0 <fputs@plt>
    8176:	48 8b 15 b3 8e 00 00 	mov    rdx,QWORD PTR [rip+0x8eb3]        # 11030 <f_ou_th@@Base>
    817d:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    8184:	48 c1 e0 03          	shl    rax,0x3
    8188:	48 01 d0             	add    rax,rdx
    818b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    818e:	48 89 c7             	mov    rdi,rax
    8191:	e8 fa a2 ff ff       	call   2490 <fflush@plt>
    8196:	e9 e1 00 00 00       	jmp    827c <TEST_not_permutation_____2+0x1e86>
    819b:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    81a2:	00 
    81a3:	78 4f                	js     81f4 <TEST_not_permutation_____2+0x1dfe>
    81a5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    81ac:	48 8b 0d 7d 8e 00 00 	mov    rcx,QWORD PTR [rip+0x8e7d]        # 11030 <f_ou_th@@Base>
    81b3:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    81ba:	48 c1 e2 03          	shl    rdx,0x3
    81be:	48 01 ca             	add    rdx,rcx
    81c1:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    81c4:	48 89 d6             	mov    rsi,rdx
    81c7:	48 89 c7             	mov    rdi,rax
    81ca:	e8 11 a2 ff ff       	call   23e0 <fputs@plt>
    81cf:	48 8b 15 5a 8e 00 00 	mov    rdx,QWORD PTR [rip+0x8e5a]        # 11030 <f_ou_th@@Base>
    81d6:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    81dd:	48 c1 e0 03          	shl    rax,0x3
    81e1:	48 01 d0             	add    rax,rdx
    81e4:	48 8b 00             	mov    rax,QWORD PTR [rax]
    81e7:	48 89 c7             	mov    rdi,rax
    81ea:	e8 a1 a2 ff ff       	call   2490 <fflush@plt>
    81ef:	e9 88 00 00 00       	jmp    827c <TEST_not_permutation_____2+0x1e86>
    81f4:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    81fb:	48 8b 15 26 8e 00 00 	mov    rdx,QWORD PTR [rip+0x8e26]        # 11028 <stdout@GLIBC_2.2.5>
    8202:	48 89 d6             	mov    rsi,rdx
    8205:	48 89 c7             	mov    rdi,rax
    8208:	e8 d3 a1 ff ff       	call   23e0 <fputs@plt>
    820d:	eb 6d                	jmp    827c <TEST_not_permutation_____2+0x1e86>
    820f:	48 8b 05 22 8e 00 00 	mov    rax,QWORD PTR [rip+0x8e22]        # 11038 <savelog@@Base>
    8216:	48 85 c0             	test   rax,rax
    8219:	74 48                	je     8263 <TEST_not_permutation_____2+0x1e6d>
    821b:	48 8b 05 16 8e 00 00 	mov    rax,QWORD PTR [rip+0x8e16]        # 11038 <savelog@@Base>
    8222:	48 8d 15 56 5e 00 00 	lea    rdx,[rip+0x5e56]        # e07f <_IO_stdin_used+0x7f>
    8229:	48 89 d6             	mov    rsi,rdx
    822c:	48 89 c7             	mov    rdi,rax
    822f:	e8 cc a2 ff ff       	call   2500 <fopen@plt>
    8234:	48 89 85 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rax
    823b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8242:	48 8b 95 60 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa0]
    8249:	48 89 d6             	mov    rsi,rdx
    824c:	48 89 c7             	mov    rdi,rax
    824f:	e8 8c a1 ff ff       	call   23e0 <fputs@plt>
    8254:	48 8b 85 60 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa0]
    825b:	48 89 c7             	mov    rdi,rax
    825e:	e8 4d a1 ff ff       	call   23b0 <fclose@plt>
    8263:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    826a:	48 8b 15 b7 8d 00 00 	mov    rdx,QWORD PTR [rip+0x8db7]        # 11028 <stdout@GLIBC_2.2.5>
    8271:	48 89 d6             	mov    rsi,rdx
    8274:	48 89 c7             	mov    rdi,rax
    8277:	e8 64 a1 ff ff       	call   23e0 <fputs@plt>
    827c:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    8283:	48 89 c7             	mov    rdi,rax
    8286:	e8 25 a1 ff ff       	call   23b0 <fclose@plt>
    828b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8292:	48 89 c7             	mov    rdi,rax
    8295:	e8 96 a0 ff ff       	call   2330 <free@plt>
    829a:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    82a1:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    82a8:	48 89 d6             	mov    rsi,rdx
    82ab:	48 89 c7             	mov    rdi,rax
    82ae:	e8 9d a0 ff ff       	call   2350 <open_memstream@plt>
    82b3:	48 89 85 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rax
    82ba:	48 83 bd 70 ff ff ff 	cmp    QWORD PTR [rbp-0x90],0x0
    82c1:	00 
    82c2:	75 38                	jne    82fc <TEST_not_permutation_____2+0x1f06>
    82c4:	48 8b 05 35 8e 00 00 	mov    rax,QWORD PTR [rip+0x8e35]        # 11100 <stderr@GLIBC_2.2.5>
    82cb:	4c 8d 05 7e 60 00 00 	lea    r8,[rip+0x607e]        # e350 <__func__.2>
    82d2:	b9 50 00 00 00       	mov    ecx,0x50
    82d7:	48 8d 15 66 5d 00 00 	lea    rdx,[rip+0x5d66]        # e044 <_IO_stdin_used+0x44>
    82de:	48 8d 35 6b 5d 00 00 	lea    rsi,[rip+0x5d6b]        # e050 <_IO_stdin_used+0x50>
    82e5:	48 89 c7             	mov    rdi,rax
    82e8:	b8 00 00 00 00       	mov    eax,0x0
    82ed:	e8 6e a1 ff ff       	call   2460 <fprintf@plt>
    82f2:	bf 00 00 00 00       	mov    edi,0x0
    82f7:	e8 24 a2 ff ff       	call   2520 <exit@plt>
    82fc:	8b 05 9e 8d 00 00    	mov    eax,DWORD PTR [rip+0x8d9e]        # 110a0 <k_DEFAULT@@Base>
    8302:	48 98                	cdqe   
    8304:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    830b:	00 
    830c:	48 8d 05 ad 8d 00 00 	lea    rax,[rip+0x8dad]        # 110c0 <colors_f@@Base>
    8313:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    8317:	8b 05 63 8d 00 00    	mov    eax,DWORD PTR [rip+0x8d63]        # 11080 <hk_TR@@Base>
    831d:	48 98                	cdqe   
    831f:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    8326:	00 
    8327:	48 8d 05 12 8d 00 00 	lea    rax,[rip+0x8d12]        # 11040 <tab_hk_f@@Base>
    832e:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    8332:	8b 05 4c 8d 00 00    	mov    eax,DWORD PTR [rip+0x8d4c]        # 11084 <k_RED@@Base>
    8338:	48 98                	cdqe   
    833a:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    8341:	00 
    8342:	48 8d 05 77 8d 00 00 	lea    rax,[rip+0x8d77]        # 110c0 <colors_f@@Base>
    8349:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    834d:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    8354:	48 83 ec 08          	sub    rsp,0x8
    8358:	ff b5 50 ff ff ff    	push   QWORD PTR [rbp-0xb0]
    835e:	4c 8d 0d eb 5f 00 00 	lea    r9,[rip+0x5feb]        # e350 <__func__.2>
    8365:	49 89 f0             	mov    r8,rsi
    8368:	48 8d 35 01 5f 00 00 	lea    rsi,[rip+0x5f01]        # e270 <_IO_stdin_used+0x270>
    836f:	48 89 c7             	mov    rdi,rax
    8372:	b8 00 00 00 00       	mov    eax,0x0
    8377:	e8 e4 a0 ff ff       	call   2460 <fprintf@plt>
    837c:	48 83 c4 10          	add    rsp,0x10
    8380:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    8387:	48 89 c7             	mov    rdi,rax
    838a:	e8 01 a1 ff ff       	call   2490 <fflush@plt>
    838f:	0f b6 05 fa 8c 00 00 	movzx  eax,BYTE PTR [rip+0x8cfa]        # 11090 <is_parallel_nb@@Base>
    8396:	84 c0                	test   al,al
    8398:	0f 84 ec 00 00 00    	je     848a <TEST_not_permutation_____2+0x2094>
    839e:	e8 ad a0 ff ff       	call   2450 <id_of_thread_executed@plt>
    83a3:	48 89 45 80          	mov    QWORD PTR [rbp-0x80],rax
    83a7:	0f b6 05 72 8c 00 00 	movzx  eax,BYTE PTR [rip+0x8c72]        # 11020 <log_parallel@@Base>
    83ae:	84 c0                	test   al,al
    83b0:	74 6d                	je     841f <TEST_not_permutation_____2+0x2029>
    83b2:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    83b9:	48 8b 15 68 8c 00 00 	mov    rdx,QWORD PTR [rip+0x8c68]        # 11028 <stdout@GLIBC_2.2.5>
    83c0:	48 89 d6             	mov    rsi,rdx
    83c3:	48 89 c7             	mov    rdi,rax
    83c6:	e8 15 a0 ff ff       	call   23e0 <fputs@plt>
    83cb:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    83d0:	0f 88 21 01 00 00    	js     84f7 <TEST_not_permutation_____2+0x2101>
    83d6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    83dd:	48 8b 0d 4c 8c 00 00 	mov    rcx,QWORD PTR [rip+0x8c4c]        # 11030 <f_ou_th@@Base>
    83e4:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    83e8:	48 c1 e2 03          	shl    rdx,0x3
    83ec:	48 01 ca             	add    rdx,rcx
    83ef:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    83f2:	48 89 d6             	mov    rsi,rdx
    83f5:	48 89 c7             	mov    rdi,rax
    83f8:	e8 e3 9f ff ff       	call   23e0 <fputs@plt>
    83fd:	48 8b 15 2c 8c 00 00 	mov    rdx,QWORD PTR [rip+0x8c2c]        # 11030 <f_ou_th@@Base>
    8404:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    8408:	48 c1 e0 03          	shl    rax,0x3
    840c:	48 01 d0             	add    rax,rdx
    840f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8412:	48 89 c7             	mov    rdi,rax
    8415:	e8 76 a0 ff ff       	call   2490 <fflush@plt>
    841a:	e9 d8 00 00 00       	jmp    84f7 <TEST_not_permutation_____2+0x2101>
    841f:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    8424:	78 49                	js     846f <TEST_not_permutation_____2+0x2079>
    8426:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    842d:	48 8b 0d fc 8b 00 00 	mov    rcx,QWORD PTR [rip+0x8bfc]        # 11030 <f_ou_th@@Base>
    8434:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    8438:	48 c1 e2 03          	shl    rdx,0x3
    843c:	48 01 ca             	add    rdx,rcx
    843f:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8442:	48 89 d6             	mov    rsi,rdx
    8445:	48 89 c7             	mov    rdi,rax
    8448:	e8 93 9f ff ff       	call   23e0 <fputs@plt>
    844d:	48 8b 15 dc 8b 00 00 	mov    rdx,QWORD PTR [rip+0x8bdc]        # 11030 <f_ou_th@@Base>
    8454:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    8458:	48 c1 e0 03          	shl    rax,0x3
    845c:	48 01 d0             	add    rax,rdx
    845f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8462:	48 89 c7             	mov    rdi,rax
    8465:	e8 26 a0 ff ff       	call   2490 <fflush@plt>
    846a:	e9 88 00 00 00       	jmp    84f7 <TEST_not_permutation_____2+0x2101>
    846f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8476:	48 8b 15 ab 8b 00 00 	mov    rdx,QWORD PTR [rip+0x8bab]        # 11028 <stdout@GLIBC_2.2.5>
    847d:	48 89 d6             	mov    rsi,rdx
    8480:	48 89 c7             	mov    rdi,rax
    8483:	e8 58 9f ff ff       	call   23e0 <fputs@plt>
    8488:	eb 6d                	jmp    84f7 <TEST_not_permutation_____2+0x2101>
    848a:	48 8b 05 a7 8b 00 00 	mov    rax,QWORD PTR [rip+0x8ba7]        # 11038 <savelog@@Base>
    8491:	48 85 c0             	test   rax,rax
    8494:	74 48                	je     84de <TEST_not_permutation_____2+0x20e8>
    8496:	48 8b 05 9b 8b 00 00 	mov    rax,QWORD PTR [rip+0x8b9b]        # 11038 <savelog@@Base>
    849d:	48 8d 15 db 5b 00 00 	lea    rdx,[rip+0x5bdb]        # e07f <_IO_stdin_used+0x7f>
    84a4:	48 89 d6             	mov    rsi,rdx
    84a7:	48 89 c7             	mov    rdi,rax
    84aa:	e8 51 a0 ff ff       	call   2500 <fopen@plt>
    84af:	48 89 85 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rax
    84b6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    84bd:	48 8b 95 78 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x88]
    84c4:	48 89 d6             	mov    rsi,rdx
    84c7:	48 89 c7             	mov    rdi,rax
    84ca:	e8 11 9f ff ff       	call   23e0 <fputs@plt>
    84cf:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    84d6:	48 89 c7             	mov    rdi,rax
    84d9:	e8 d2 9e ff ff       	call   23b0 <fclose@plt>
    84de:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    84e5:	48 8b 15 3c 8b 00 00 	mov    rdx,QWORD PTR [rip+0x8b3c]        # 11028 <stdout@GLIBC_2.2.5>
    84ec:	48 89 d6             	mov    rsi,rdx
    84ef:	48 89 c7             	mov    rdi,rax
    84f2:	e8 e9 9e ff ff       	call   23e0 <fputs@plt>
    84f7:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    84fe:	48 89 c7             	mov    rdi,rax
    8501:	e8 aa 9e ff ff       	call   23b0 <fclose@plt>
    8506:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    850d:	48 89 c7             	mov    rdi,rax
    8510:	e8 1b 9e ff ff       	call   2330 <free@plt>
    8515:	90                   	nop
    8516:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    851a:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
    8521:	00 00 
    8523:	74 05                	je     852a <TEST_not_permutation_____2+0x2134>
    8525:	e8 96 9e ff ff       	call   23c0 <__stack_chk_fail@plt>
    852a:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    852e:	c9                   	leave  
    852f:	c3                   	ret    

0000000000008530 <append_test_is_permutation_3>:
    8530:	f3 0f 1e fa          	endbr64 
    8534:	55                   	push   rbp
    8535:	48 89 e5             	mov    rbp,rsp
    8538:	48 8d 05 61 5d 00 00 	lea    rax,[rip+0x5d61]        # e2a0 <_IO_stdin_used+0x2a0>
    853f:	48 89 c6             	mov    rsi,rax
    8542:	48 8d 05 0a 00 00 00 	lea    rax,[rip+0xa]        # 8553 <TEST_is_permutation_____3>
    8549:	48 89 c7             	mov    rdi,rax
    854c:	e8 ef 9d ff ff       	call   2340 <append_func@plt>
    8551:	5d                   	pop    rbp
    8552:	c3                   	ret    

0000000000008553 <TEST_is_permutation_____3>:
    8553:	f3 0f 1e fa          	endbr64 
    8557:	55                   	push   rbp
    8558:	48 89 e5             	mov    rbp,rsp
    855b:	53                   	push   rbx
    855c:	48 81 ec 78 01 00 00 	sub    rsp,0x178
    8563:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    856a:	00 00 
    856c:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    8570:	31 c0                	xor    eax,eax
    8572:	c7 85 8c fe ff ff 06 	mov    DWORD PTR [rbp-0x174],0x6
    8579:	00 00 00 
    857c:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    8582:	48 98                	cdqe   
    8584:	48 89 c7             	mov    rdi,rax
    8587:	e8 85 3d 00 00       	call   c311 <CREATE_PERMUTATION_TYPE_FLOAT>
    858c:	48 89 85 a0 fe ff ff 	mov    QWORD PTR [rbp-0x160],rax
    8593:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    859a:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    85a1:	48 89 d6             	mov    rsi,rdx
    85a4:	48 89 c7             	mov    rdi,rax
    85a7:	e8 a4 9d ff ff       	call   2350 <open_memstream@plt>
    85ac:	48 89 85 a8 fe ff ff 	mov    QWORD PTR [rbp-0x158],rax
    85b3:	48 83 bd a8 fe ff ff 	cmp    QWORD PTR [rbp-0x158],0x0
    85ba:	00 
    85bb:	75 38                	jne    85f5 <TEST_is_permutation_____3+0xa2>
    85bd:	48 8b 05 3c 8b 00 00 	mov    rax,QWORD PTR [rip+0x8b3c]        # 11100 <stderr@GLIBC_2.2.5>
    85c4:	4c 8d 05 a5 5d 00 00 	lea    r8,[rip+0x5da5]        # e370 <__func__.1>
    85cb:	b9 5e 00 00 00       	mov    ecx,0x5e
    85d0:	48 8d 15 6d 5a 00 00 	lea    rdx,[rip+0x5a6d]        # e044 <_IO_stdin_used+0x44>
    85d7:	48 8d 35 72 5a 00 00 	lea    rsi,[rip+0x5a72]        # e050 <_IO_stdin_used+0x50>
    85de:	48 89 c7             	mov    rdi,rax
    85e1:	b8 00 00 00 00       	mov    eax,0x0
    85e6:	e8 75 9e ff ff       	call   2460 <fprintf@plt>
    85eb:	bf 00 00 00 00       	mov    edi,0x0
    85f0:	e8 2b 9f ff ff       	call   2520 <exit@plt>
    85f5:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    85fc:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    85ff:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    8606:	48 8d 0d 64 5a 00 00 	lea    rcx,[rip+0x5a64]        # e071 <_IO_stdin_used+0x71>
    860d:	48 89 ce             	mov    rsi,rcx
    8610:	48 89 c7             	mov    rdi,rax
    8613:	b8 00 00 00 00       	mov    eax,0x0
    8618:	e8 43 9e ff ff       	call   2460 <fprintf@plt>
    861d:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    8624:	48 89 c7             	mov    rdi,rax
    8627:	e8 64 9e ff ff       	call   2490 <fflush@plt>
    862c:	0f b6 05 5d 8a 00 00 	movzx  eax,BYTE PTR [rip+0x8a5d]        # 11090 <is_parallel_nb@@Base>
    8633:	84 c0                	test   al,al
    8635:	0f 84 01 01 00 00    	je     873c <TEST_is_permutation_____3+0x1e9>
    863b:	e8 10 9e ff ff       	call   2450 <id_of_thread_executed@plt>
    8640:	48 89 85 b8 fe ff ff 	mov    QWORD PTR [rbp-0x148],rax
    8647:	0f b6 05 d2 89 00 00 	movzx  eax,BYTE PTR [rip+0x89d2]        # 11020 <log_parallel@@Base>
    864e:	84 c0                	test   al,al
    8650:	74 76                	je     86c8 <TEST_is_permutation_____3+0x175>
    8652:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8659:	48 8b 15 c8 89 00 00 	mov    rdx,QWORD PTR [rip+0x89c8]        # 11028 <stdout@GLIBC_2.2.5>
    8660:	48 89 d6             	mov    rsi,rdx
    8663:	48 89 c7             	mov    rdi,rax
    8666:	e8 75 9d ff ff       	call   23e0 <fputs@plt>
    866b:	48 83 bd b8 fe ff ff 	cmp    QWORD PTR [rbp-0x148],0x0
    8672:	00 
    8673:	0f 88 30 01 00 00    	js     87a9 <TEST_is_permutation_____3+0x256>
    8679:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8680:	48 8b 0d a9 89 00 00 	mov    rcx,QWORD PTR [rip+0x89a9]        # 11030 <f_ou_th@@Base>
    8687:	48 8b 95 b8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x148]
    868e:	48 c1 e2 03          	shl    rdx,0x3
    8692:	48 01 ca             	add    rdx,rcx
    8695:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8698:	48 89 d6             	mov    rsi,rdx
    869b:	48 89 c7             	mov    rdi,rax
    869e:	e8 3d 9d ff ff       	call   23e0 <fputs@plt>
    86a3:	48 8b 15 86 89 00 00 	mov    rdx,QWORD PTR [rip+0x8986]        # 11030 <f_ou_th@@Base>
    86aa:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    86b1:	48 c1 e0 03          	shl    rax,0x3
    86b5:	48 01 d0             	add    rax,rdx
    86b8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    86bb:	48 89 c7             	mov    rdi,rax
    86be:	e8 cd 9d ff ff       	call   2490 <fflush@plt>
    86c3:	e9 e1 00 00 00       	jmp    87a9 <TEST_is_permutation_____3+0x256>
    86c8:	48 83 bd b8 fe ff ff 	cmp    QWORD PTR [rbp-0x148],0x0
    86cf:	00 
    86d0:	78 4f                	js     8721 <TEST_is_permutation_____3+0x1ce>
    86d2:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    86d9:	48 8b 0d 50 89 00 00 	mov    rcx,QWORD PTR [rip+0x8950]        # 11030 <f_ou_th@@Base>
    86e0:	48 8b 95 b8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x148]
    86e7:	48 c1 e2 03          	shl    rdx,0x3
    86eb:	48 01 ca             	add    rdx,rcx
    86ee:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    86f1:	48 89 d6             	mov    rsi,rdx
    86f4:	48 89 c7             	mov    rdi,rax
    86f7:	e8 e4 9c ff ff       	call   23e0 <fputs@plt>
    86fc:	48 8b 15 2d 89 00 00 	mov    rdx,QWORD PTR [rip+0x892d]        # 11030 <f_ou_th@@Base>
    8703:	48 8b 85 b8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x148]
    870a:	48 c1 e0 03          	shl    rax,0x3
    870e:	48 01 d0             	add    rax,rdx
    8711:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8714:	48 89 c7             	mov    rdi,rax
    8717:	e8 74 9d ff ff       	call   2490 <fflush@plt>
    871c:	e9 88 00 00 00       	jmp    87a9 <TEST_is_permutation_____3+0x256>
    8721:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8728:	48 8b 15 f9 88 00 00 	mov    rdx,QWORD PTR [rip+0x88f9]        # 11028 <stdout@GLIBC_2.2.5>
    872f:	48 89 d6             	mov    rsi,rdx
    8732:	48 89 c7             	mov    rdi,rax
    8735:	e8 a6 9c ff ff       	call   23e0 <fputs@plt>
    873a:	eb 6d                	jmp    87a9 <TEST_is_permutation_____3+0x256>
    873c:	48 8b 05 f5 88 00 00 	mov    rax,QWORD PTR [rip+0x88f5]        # 11038 <savelog@@Base>
    8743:	48 85 c0             	test   rax,rax
    8746:	74 48                	je     8790 <TEST_is_permutation_____3+0x23d>
    8748:	48 8b 05 e9 88 00 00 	mov    rax,QWORD PTR [rip+0x88e9]        # 11038 <savelog@@Base>
    874f:	48 8d 15 29 59 00 00 	lea    rdx,[rip+0x5929]        # e07f <_IO_stdin_used+0x7f>
    8756:	48 89 d6             	mov    rsi,rdx
    8759:	48 89 c7             	mov    rdi,rax
    875c:	e8 9f 9d ff ff       	call   2500 <fopen@plt>
    8761:	48 89 85 b0 fe ff ff 	mov    QWORD PTR [rbp-0x150],rax
    8768:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    876f:	48 8b 95 b0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x150]
    8776:	48 89 d6             	mov    rsi,rdx
    8779:	48 89 c7             	mov    rdi,rax
    877c:	e8 5f 9c ff ff       	call   23e0 <fputs@plt>
    8781:	48 8b 85 b0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x150]
    8788:	48 89 c7             	mov    rdi,rax
    878b:	e8 20 9c ff ff       	call   23b0 <fclose@plt>
    8790:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8797:	48 8b 15 8a 88 00 00 	mov    rdx,QWORD PTR [rip+0x888a]        # 11028 <stdout@GLIBC_2.2.5>
    879e:	48 89 d6             	mov    rsi,rdx
    87a1:	48 89 c7             	mov    rdi,rax
    87a4:	e8 37 9c ff ff       	call   23e0 <fputs@plt>
    87a9:	48 8b 85 a8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x158]
    87b0:	48 89 c7             	mov    rdi,rax
    87b3:	e8 f8 9b ff ff       	call   23b0 <fclose@plt>
    87b8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    87bf:	48 89 c7             	mov    rdi,rax
    87c2:	e8 69 9b ff ff       	call   2330 <free@plt>
    87c7:	0f b6 05 c2 88 00 00 	movzx  eax,BYTE PTR [rip+0x88c2]        # 11090 <is_parallel_nb@@Base>
    87ce:	83 f0 01             	xor    eax,0x1
    87d1:	84 c0                	test   al,al
    87d3:	0f 84 c2 07 00 00    	je     8f9b <TEST_is_permutation_____3+0xa48>
    87d9:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    87df:	48 98                	cdqe   
    87e1:	48 8b 95 a0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x160]
    87e8:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    87eb:	48 89 c6             	mov    rsi,rax
    87ee:	48 89 d7             	mov    rdi,rdx
    87f1:	e8 0a 9c ff ff       	call   2400 <expected_EQ_TYPE_L_INT@plt>
    87f6:	84 c0                	test   al,al
    87f8:	0f 84 87 02 00 00    	je     8a85 <TEST_is_permutation_____3+0x532>
    87fe:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    8805:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    880c:	48 89 d6             	mov    rsi,rdx
    880f:	48 89 c7             	mov    rdi,rax
    8812:	e8 39 9b ff ff       	call   2350 <open_memstream@plt>
    8817:	48 89 85 38 ff ff ff 	mov    QWORD PTR [rbp-0xc8],rax
    881e:	48 83 bd 38 ff ff ff 	cmp    QWORD PTR [rbp-0xc8],0x0
    8825:	00 
    8826:	75 38                	jne    8860 <TEST_is_permutation_____3+0x30d>
    8828:	48 8b 05 d1 88 00 00 	mov    rax,QWORD PTR [rip+0x88d1]        # 11100 <stderr@GLIBC_2.2.5>
    882f:	4c 8d 05 3a 5b 00 00 	lea    r8,[rip+0x5b3a]        # e370 <__func__.1>
    8836:	b9 5f 00 00 00       	mov    ecx,0x5f
    883b:	48 8d 15 02 58 00 00 	lea    rdx,[rip+0x5802]        # e044 <_IO_stdin_used+0x44>
    8842:	48 8d 35 07 58 00 00 	lea    rsi,[rip+0x5807]        # e050 <_IO_stdin_used+0x50>
    8849:	48 89 c7             	mov    rdi,rax
    884c:	b8 00 00 00 00       	mov    eax,0x0
    8851:	e8 0a 9c ff ff       	call   2460 <fprintf@plt>
    8856:	bf 00 00 00 00       	mov    edi,0x0
    885b:	e8 c0 9c ff ff       	call   2520 <exit@plt>
    8860:	8b 05 3a 88 00 00    	mov    eax,DWORD PTR [rip+0x883a]        # 110a0 <k_DEFAULT@@Base>
    8866:	48 98                	cdqe   
    8868:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    886f:	00 
    8870:	48 8d 05 49 88 00 00 	lea    rax,[rip+0x8849]        # 110c0 <colors_f@@Base>
    8877:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    887b:	8b 05 ff 87 00 00    	mov    eax,DWORD PTR [rip+0x87ff]        # 11080 <hk_TR@@Base>
    8881:	48 98                	cdqe   
    8883:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    888a:	00 
    888b:	48 8d 05 ae 87 00 00 	lea    rax,[rip+0x87ae]        # 11040 <tab_hk_f@@Base>
    8892:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    8896:	8b 05 54 88 00 00    	mov    eax,DWORD PTR [rip+0x8854]        # 110f0 <k_GREEN@@Base>
    889c:	48 98                	cdqe   
    889e:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    88a5:	00 
    88a6:	48 8d 05 13 88 00 00 	lea    rax,[rip+0x8813]        # 110c0 <colors_f@@Base>
    88ad:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    88b1:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    88b8:	4c 8d 0d b1 5a 00 00 	lea    r9,[rip+0x5ab1]        # e370 <__func__.1>
    88bf:	49 89 f0             	mov    r8,rsi
    88c2:	48 8d 35 bf 57 00 00 	lea    rsi,[rip+0x57bf]        # e088 <_IO_stdin_used+0x88>
    88c9:	48 89 c7             	mov    rdi,rax
    88cc:	b8 00 00 00 00       	mov    eax,0x0
    88d1:	e8 8a 9b ff ff       	call   2460 <fprintf@plt>
    88d6:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    88dd:	48 89 c7             	mov    rdi,rax
    88e0:	e8 ab 9b ff ff       	call   2490 <fflush@plt>
    88e5:	0f b6 05 a4 87 00 00 	movzx  eax,BYTE PTR [rip+0x87a4]        # 11090 <is_parallel_nb@@Base>
    88ec:	84 c0                	test   al,al
    88ee:	0f 84 01 01 00 00    	je     89f5 <TEST_is_permutation_____3+0x4a2>
    88f4:	e8 57 9b ff ff       	call   2450 <id_of_thread_executed@plt>
    88f9:	48 89 85 48 ff ff ff 	mov    QWORD PTR [rbp-0xb8],rax
    8900:	0f b6 05 19 87 00 00 	movzx  eax,BYTE PTR [rip+0x8719]        # 11020 <log_parallel@@Base>
    8907:	84 c0                	test   al,al
    8909:	74 76                	je     8981 <TEST_is_permutation_____3+0x42e>
    890b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8912:	48 8b 15 0f 87 00 00 	mov    rdx,QWORD PTR [rip+0x870f]        # 11028 <stdout@GLIBC_2.2.5>
    8919:	48 89 d6             	mov    rsi,rdx
    891c:	48 89 c7             	mov    rdi,rax
    891f:	e8 bc 9a ff ff       	call   23e0 <fputs@plt>
    8924:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    892b:	00 
    892c:	0f 88 30 01 00 00    	js     8a62 <TEST_is_permutation_____3+0x50f>
    8932:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8939:	48 8b 0d f0 86 00 00 	mov    rcx,QWORD PTR [rip+0x86f0]        # 11030 <f_ou_th@@Base>
    8940:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    8947:	48 c1 e2 03          	shl    rdx,0x3
    894b:	48 01 ca             	add    rdx,rcx
    894e:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8951:	48 89 d6             	mov    rsi,rdx
    8954:	48 89 c7             	mov    rdi,rax
    8957:	e8 84 9a ff ff       	call   23e0 <fputs@plt>
    895c:	48 8b 15 cd 86 00 00 	mov    rdx,QWORD PTR [rip+0x86cd]        # 11030 <f_ou_th@@Base>
    8963:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    896a:	48 c1 e0 03          	shl    rax,0x3
    896e:	48 01 d0             	add    rax,rdx
    8971:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8974:	48 89 c7             	mov    rdi,rax
    8977:	e8 14 9b ff ff       	call   2490 <fflush@plt>
    897c:	e9 e1 00 00 00       	jmp    8a62 <TEST_is_permutation_____3+0x50f>
    8981:	48 83 bd 48 ff ff ff 	cmp    QWORD PTR [rbp-0xb8],0x0
    8988:	00 
    8989:	78 4f                	js     89da <TEST_is_permutation_____3+0x487>
    898b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8992:	48 8b 0d 97 86 00 00 	mov    rcx,QWORD PTR [rip+0x8697]        # 11030 <f_ou_th@@Base>
    8999:	48 8b 95 48 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xb8]
    89a0:	48 c1 e2 03          	shl    rdx,0x3
    89a4:	48 01 ca             	add    rdx,rcx
    89a7:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    89aa:	48 89 d6             	mov    rsi,rdx
    89ad:	48 89 c7             	mov    rdi,rax
    89b0:	e8 2b 9a ff ff       	call   23e0 <fputs@plt>
    89b5:	48 8b 15 74 86 00 00 	mov    rdx,QWORD PTR [rip+0x8674]        # 11030 <f_ou_th@@Base>
    89bc:	48 8b 85 48 ff ff ff 	mov    rax,QWORD PTR [rbp-0xb8]
    89c3:	48 c1 e0 03          	shl    rax,0x3
    89c7:	48 01 d0             	add    rax,rdx
    89ca:	48 8b 00             	mov    rax,QWORD PTR [rax]
    89cd:	48 89 c7             	mov    rdi,rax
    89d0:	e8 bb 9a ff ff       	call   2490 <fflush@plt>
    89d5:	e9 88 00 00 00       	jmp    8a62 <TEST_is_permutation_____3+0x50f>
    89da:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    89e1:	48 8b 15 40 86 00 00 	mov    rdx,QWORD PTR [rip+0x8640]        # 11028 <stdout@GLIBC_2.2.5>
    89e8:	48 89 d6             	mov    rsi,rdx
    89eb:	48 89 c7             	mov    rdi,rax
    89ee:	e8 ed 99 ff ff       	call   23e0 <fputs@plt>
    89f3:	eb 6d                	jmp    8a62 <TEST_is_permutation_____3+0x50f>
    89f5:	48 8b 05 3c 86 00 00 	mov    rax,QWORD PTR [rip+0x863c]        # 11038 <savelog@@Base>
    89fc:	48 85 c0             	test   rax,rax
    89ff:	74 48                	je     8a49 <TEST_is_permutation_____3+0x4f6>
    8a01:	48 8b 05 30 86 00 00 	mov    rax,QWORD PTR [rip+0x8630]        # 11038 <savelog@@Base>
    8a08:	48 8d 15 70 56 00 00 	lea    rdx,[rip+0x5670]        # e07f <_IO_stdin_used+0x7f>
    8a0f:	48 89 d6             	mov    rsi,rdx
    8a12:	48 89 c7             	mov    rdi,rax
    8a15:	e8 e6 9a ff ff       	call   2500 <fopen@plt>
    8a1a:	48 89 85 40 ff ff ff 	mov    QWORD PTR [rbp-0xc0],rax
    8a21:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8a28:	48 8b 95 40 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xc0]
    8a2f:	48 89 d6             	mov    rsi,rdx
    8a32:	48 89 c7             	mov    rdi,rax
    8a35:	e8 a6 99 ff ff       	call   23e0 <fputs@plt>
    8a3a:	48 8b 85 40 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc0]
    8a41:	48 89 c7             	mov    rdi,rax
    8a44:	e8 67 99 ff ff       	call   23b0 <fclose@plt>
    8a49:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8a50:	48 8b 15 d1 85 00 00 	mov    rdx,QWORD PTR [rip+0x85d1]        # 11028 <stdout@GLIBC_2.2.5>
    8a57:	48 89 d6             	mov    rsi,rdx
    8a5a:	48 89 c7             	mov    rdi,rax
    8a5d:	e8 7e 99 ff ff       	call   23e0 <fputs@plt>
    8a62:	48 8b 85 38 ff ff ff 	mov    rax,QWORD PTR [rbp-0xc8]
    8a69:	48 89 c7             	mov    rdi,rax
    8a6c:	e8 3f 99 ff ff       	call   23b0 <fclose@plt>
    8a71:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8a78:	48 89 c7             	mov    rdi,rax
    8a7b:	e8 b0 98 ff ff       	call   2330 <free@plt>
    8a80:	e9 dd 0c 00 00       	jmp    9762 <TEST_is_permutation_____3+0x120f>
    8a85:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    8a8c:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    8a93:	48 89 d6             	mov    rsi,rdx
    8a96:	48 89 c7             	mov    rdi,rax
    8a99:	e8 b2 98 ff ff       	call   2350 <open_memstream@plt>
    8a9e:	48 89 85 08 ff ff ff 	mov    QWORD PTR [rbp-0xf8],rax
    8aa5:	48 83 bd 08 ff ff ff 	cmp    QWORD PTR [rbp-0xf8],0x0
    8aac:	00 
    8aad:	75 38                	jne    8ae7 <TEST_is_permutation_____3+0x594>
    8aaf:	48 8b 05 4a 86 00 00 	mov    rax,QWORD PTR [rip+0x864a]        # 11100 <stderr@GLIBC_2.2.5>
    8ab6:	4c 8d 05 b3 58 00 00 	lea    r8,[rip+0x58b3]        # e370 <__func__.1>
    8abd:	b9 5f 00 00 00       	mov    ecx,0x5f
    8ac2:	48 8d 15 7b 55 00 00 	lea    rdx,[rip+0x557b]        # e044 <_IO_stdin_used+0x44>
    8ac9:	48 8d 35 80 55 00 00 	lea    rsi,[rip+0x5580]        # e050 <_IO_stdin_used+0x50>
    8ad0:	48 89 c7             	mov    rdi,rax
    8ad3:	b8 00 00 00 00       	mov    eax,0x0
    8ad8:	e8 83 99 ff ff       	call   2460 <fprintf@plt>
    8add:	bf 00 00 00 00       	mov    edi,0x0
    8ae2:	e8 39 9a ff ff       	call   2520 <exit@plt>
    8ae7:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    8aed:	48 98                	cdqe   
    8aef:	48 89 c7             	mov    rdi,rax
    8af2:	e8 39 9a ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    8af7:	48 89 c3             	mov    rbx,rax
    8afa:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    8b01:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8b04:	48 89 c7             	mov    rdi,rax
    8b07:	e8 24 9a ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    8b0c:	48 89 c2             	mov    rdx,rax
    8b0f:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    8b16:	53                   	push   rbx
    8b17:	48 8d 0d 37 56 00 00 	lea    rcx,[rip+0x5637]        # e155 <_IO_stdin_used+0x155>
    8b1e:	51                   	push   rcx
    8b1f:	52                   	push   rdx
    8b20:	48 8d 15 81 55 00 00 	lea    rdx,[rip+0x5581]        # e0a8 <_IO_stdin_used+0xa8>
    8b27:	52                   	push   rdx
    8b28:	48 8d 15 26 56 00 00 	lea    rdx,[rip+0x5626]        # e155 <_IO_stdin_used+0x155>
    8b2f:	52                   	push   rdx
    8b30:	48 8d 15 cd 55 00 00 	lea    rdx,[rip+0x55cd]        # e104 <_IO_stdin_used+0x104>
    8b37:	52                   	push   rdx
    8b38:	4c 8d 0d 69 55 00 00 	lea    r9,[rip+0x5569]        # e0a8 <_IO_stdin_used+0xa8>
    8b3f:	4c 8d 05 2a 58 00 00 	lea    r8,[rip+0x582a]        # e370 <__func__.1>
    8b46:	b9 5f 00 00 00       	mov    ecx,0x5f
    8b4b:	48 8d 15 f2 54 00 00 	lea    rdx,[rip+0x54f2]        # e044 <_IO_stdin_used+0x44>
    8b52:	48 8d 35 57 55 00 00 	lea    rsi,[rip+0x5557]        # e0b0 <_IO_stdin_used+0xb0>
    8b59:	48 89 c7             	mov    rdi,rax
    8b5c:	b8 00 00 00 00       	mov    eax,0x0
    8b61:	e8 fa 98 ff ff       	call   2460 <fprintf@plt>
    8b66:	48 83 c4 30          	add    rsp,0x30
    8b6a:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    8b71:	48 89 c7             	mov    rdi,rax
    8b74:	e8 17 99 ff ff       	call   2490 <fflush@plt>
    8b79:	0f b6 05 10 85 00 00 	movzx  eax,BYTE PTR [rip+0x8510]        # 11090 <is_parallel_nb@@Base>
    8b80:	84 c0                	test   al,al
    8b82:	0f 84 01 01 00 00    	je     8c89 <TEST_is_permutation_____3+0x736>
    8b88:	e8 c3 98 ff ff       	call   2450 <id_of_thread_executed@plt>
    8b8d:	48 89 85 18 ff ff ff 	mov    QWORD PTR [rbp-0xe8],rax
    8b94:	0f b6 05 85 84 00 00 	movzx  eax,BYTE PTR [rip+0x8485]        # 11020 <log_parallel@@Base>
    8b9b:	84 c0                	test   al,al
    8b9d:	74 76                	je     8c15 <TEST_is_permutation_____3+0x6c2>
    8b9f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8ba6:	48 8b 15 7b 84 00 00 	mov    rdx,QWORD PTR [rip+0x847b]        # 11028 <stdout@GLIBC_2.2.5>
    8bad:	48 89 d6             	mov    rsi,rdx
    8bb0:	48 89 c7             	mov    rdi,rax
    8bb3:	e8 28 98 ff ff       	call   23e0 <fputs@plt>
    8bb8:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    8bbf:	00 
    8bc0:	0f 88 30 01 00 00    	js     8cf6 <TEST_is_permutation_____3+0x7a3>
    8bc6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8bcd:	48 8b 0d 5c 84 00 00 	mov    rcx,QWORD PTR [rip+0x845c]        # 11030 <f_ou_th@@Base>
    8bd4:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    8bdb:	48 c1 e2 03          	shl    rdx,0x3
    8bdf:	48 01 ca             	add    rdx,rcx
    8be2:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8be5:	48 89 d6             	mov    rsi,rdx
    8be8:	48 89 c7             	mov    rdi,rax
    8beb:	e8 f0 97 ff ff       	call   23e0 <fputs@plt>
    8bf0:	48 8b 15 39 84 00 00 	mov    rdx,QWORD PTR [rip+0x8439]        # 11030 <f_ou_th@@Base>
    8bf7:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    8bfe:	48 c1 e0 03          	shl    rax,0x3
    8c02:	48 01 d0             	add    rax,rdx
    8c05:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8c08:	48 89 c7             	mov    rdi,rax
    8c0b:	e8 80 98 ff ff       	call   2490 <fflush@plt>
    8c10:	e9 e1 00 00 00       	jmp    8cf6 <TEST_is_permutation_____3+0x7a3>
    8c15:	48 83 bd 18 ff ff ff 	cmp    QWORD PTR [rbp-0xe8],0x0
    8c1c:	00 
    8c1d:	78 4f                	js     8c6e <TEST_is_permutation_____3+0x71b>
    8c1f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8c26:	48 8b 0d 03 84 00 00 	mov    rcx,QWORD PTR [rip+0x8403]        # 11030 <f_ou_th@@Base>
    8c2d:	48 8b 95 18 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xe8]
    8c34:	48 c1 e2 03          	shl    rdx,0x3
    8c38:	48 01 ca             	add    rdx,rcx
    8c3b:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8c3e:	48 89 d6             	mov    rsi,rdx
    8c41:	48 89 c7             	mov    rdi,rax
    8c44:	e8 97 97 ff ff       	call   23e0 <fputs@plt>
    8c49:	48 8b 15 e0 83 00 00 	mov    rdx,QWORD PTR [rip+0x83e0]        # 11030 <f_ou_th@@Base>
    8c50:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
    8c57:	48 c1 e0 03          	shl    rax,0x3
    8c5b:	48 01 d0             	add    rax,rdx
    8c5e:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8c61:	48 89 c7             	mov    rdi,rax
    8c64:	e8 27 98 ff ff       	call   2490 <fflush@plt>
    8c69:	e9 88 00 00 00       	jmp    8cf6 <TEST_is_permutation_____3+0x7a3>
    8c6e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8c75:	48 8b 15 ac 83 00 00 	mov    rdx,QWORD PTR [rip+0x83ac]        # 11028 <stdout@GLIBC_2.2.5>
    8c7c:	48 89 d6             	mov    rsi,rdx
    8c7f:	48 89 c7             	mov    rdi,rax
    8c82:	e8 59 97 ff ff       	call   23e0 <fputs@plt>
    8c87:	eb 6d                	jmp    8cf6 <TEST_is_permutation_____3+0x7a3>
    8c89:	48 8b 05 a8 83 00 00 	mov    rax,QWORD PTR [rip+0x83a8]        # 11038 <savelog@@Base>
    8c90:	48 85 c0             	test   rax,rax
    8c93:	74 48                	je     8cdd <TEST_is_permutation_____3+0x78a>
    8c95:	48 8b 05 9c 83 00 00 	mov    rax,QWORD PTR [rip+0x839c]        # 11038 <savelog@@Base>
    8c9c:	48 8d 15 dc 53 00 00 	lea    rdx,[rip+0x53dc]        # e07f <_IO_stdin_used+0x7f>
    8ca3:	48 89 d6             	mov    rsi,rdx
    8ca6:	48 89 c7             	mov    rdi,rax
    8ca9:	e8 52 98 ff ff       	call   2500 <fopen@plt>
    8cae:	48 89 85 10 ff ff ff 	mov    QWORD PTR [rbp-0xf0],rax
    8cb5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8cbc:	48 8b 95 10 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xf0]
    8cc3:	48 89 d6             	mov    rsi,rdx
    8cc6:	48 89 c7             	mov    rdi,rax
    8cc9:	e8 12 97 ff ff       	call   23e0 <fputs@plt>
    8cce:	48 8b 85 10 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf0]
    8cd5:	48 89 c7             	mov    rdi,rax
    8cd8:	e8 d3 96 ff ff       	call   23b0 <fclose@plt>
    8cdd:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8ce4:	48 8b 15 3d 83 00 00 	mov    rdx,QWORD PTR [rip+0x833d]        # 11028 <stdout@GLIBC_2.2.5>
    8ceb:	48 89 d6             	mov    rsi,rdx
    8cee:	48 89 c7             	mov    rdi,rax
    8cf1:	e8 ea 96 ff ff       	call   23e0 <fputs@plt>
    8cf6:	48 8b 85 08 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf8]
    8cfd:	48 89 c7             	mov    rdi,rax
    8d00:	e8 ab 96 ff ff       	call   23b0 <fclose@plt>
    8d05:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8d0c:	48 89 c7             	mov    rdi,rax
    8d0f:	e8 1c 96 ff ff       	call   2330 <free@plt>
    8d14:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    8d1b:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    8d22:	48 89 d6             	mov    rsi,rdx
    8d25:	48 89 c7             	mov    rdi,rax
    8d28:	e8 23 96 ff ff       	call   2350 <open_memstream@plt>
    8d2d:	48 89 85 20 ff ff ff 	mov    QWORD PTR [rbp-0xe0],rax
    8d34:	48 83 bd 20 ff ff ff 	cmp    QWORD PTR [rbp-0xe0],0x0
    8d3b:	00 
    8d3c:	75 38                	jne    8d76 <TEST_is_permutation_____3+0x823>
    8d3e:	48 8b 05 bb 83 00 00 	mov    rax,QWORD PTR [rip+0x83bb]        # 11100 <stderr@GLIBC_2.2.5>
    8d45:	4c 8d 05 24 56 00 00 	lea    r8,[rip+0x5624]        # e370 <__func__.1>
    8d4c:	b9 5f 00 00 00       	mov    ecx,0x5f
    8d51:	48 8d 15 ec 52 00 00 	lea    rdx,[rip+0x52ec]        # e044 <_IO_stdin_used+0x44>
    8d58:	48 8d 35 f1 52 00 00 	lea    rsi,[rip+0x52f1]        # e050 <_IO_stdin_used+0x50>
    8d5f:	48 89 c7             	mov    rdi,rax
    8d62:	b8 00 00 00 00       	mov    eax,0x0
    8d67:	e8 f4 96 ff ff       	call   2460 <fprintf@plt>
    8d6c:	bf 00 00 00 00       	mov    edi,0x0
    8d71:	e8 aa 97 ff ff       	call   2520 <exit@plt>
    8d76:	8b 05 24 83 00 00    	mov    eax,DWORD PTR [rip+0x8324]        # 110a0 <k_DEFAULT@@Base>
    8d7c:	48 98                	cdqe   
    8d7e:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    8d85:	00 
    8d86:	48 8d 05 33 83 00 00 	lea    rax,[rip+0x8333]        # 110c0 <colors_f@@Base>
    8d8d:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    8d91:	8b 05 e9 82 00 00    	mov    eax,DWORD PTR [rip+0x82e9]        # 11080 <hk_TR@@Base>
    8d97:	48 98                	cdqe   
    8d99:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    8da0:	00 
    8da1:	48 8d 05 98 82 00 00 	lea    rax,[rip+0x8298]        # 11040 <tab_hk_f@@Base>
    8da8:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    8dac:	8b 05 d2 82 00 00    	mov    eax,DWORD PTR [rip+0x82d2]        # 11084 <k_RED@@Base>
    8db2:	48 98                	cdqe   
    8db4:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    8dbb:	00 
    8dbc:	48 8d 05 fd 82 00 00 	lea    rax,[rip+0x82fd]        # 110c0 <colors_f@@Base>
    8dc3:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    8dc7:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    8dce:	4c 8d 0d 9b 55 00 00 	lea    r9,[rip+0x559b]        # e370 <__func__.1>
    8dd5:	49 89 f0             	mov    r8,rsi
    8dd8:	48 8d 35 29 53 00 00 	lea    rsi,[rip+0x5329]        # e108 <_IO_stdin_used+0x108>
    8ddf:	48 89 c7             	mov    rdi,rax
    8de2:	b8 00 00 00 00       	mov    eax,0x0
    8de7:	e8 74 96 ff ff       	call   2460 <fprintf@plt>
    8dec:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    8df3:	48 89 c7             	mov    rdi,rax
    8df6:	e8 95 96 ff ff       	call   2490 <fflush@plt>
    8dfb:	0f b6 05 8e 82 00 00 	movzx  eax,BYTE PTR [rip+0x828e]        # 11090 <is_parallel_nb@@Base>
    8e02:	84 c0                	test   al,al
    8e04:	0f 84 01 01 00 00    	je     8f0b <TEST_is_permutation_____3+0x9b8>
    8e0a:	e8 41 96 ff ff       	call   2450 <id_of_thread_executed@plt>
    8e0f:	48 89 85 30 ff ff ff 	mov    QWORD PTR [rbp-0xd0],rax
    8e16:	0f b6 05 03 82 00 00 	movzx  eax,BYTE PTR [rip+0x8203]        # 11020 <log_parallel@@Base>
    8e1d:	84 c0                	test   al,al
    8e1f:	74 76                	je     8e97 <TEST_is_permutation_____3+0x944>
    8e21:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8e28:	48 8b 15 f9 81 00 00 	mov    rdx,QWORD PTR [rip+0x81f9]        # 11028 <stdout@GLIBC_2.2.5>
    8e2f:	48 89 d6             	mov    rsi,rdx
    8e32:	48 89 c7             	mov    rdi,rax
    8e35:	e8 a6 95 ff ff       	call   23e0 <fputs@plt>
    8e3a:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    8e41:	00 
    8e42:	0f 88 30 01 00 00    	js     8f78 <TEST_is_permutation_____3+0xa25>
    8e48:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8e4f:	48 8b 0d da 81 00 00 	mov    rcx,QWORD PTR [rip+0x81da]        # 11030 <f_ou_th@@Base>
    8e56:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    8e5d:	48 c1 e2 03          	shl    rdx,0x3
    8e61:	48 01 ca             	add    rdx,rcx
    8e64:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8e67:	48 89 d6             	mov    rsi,rdx
    8e6a:	48 89 c7             	mov    rdi,rax
    8e6d:	e8 6e 95 ff ff       	call   23e0 <fputs@plt>
    8e72:	48 8b 15 b7 81 00 00 	mov    rdx,QWORD PTR [rip+0x81b7]        # 11030 <f_ou_th@@Base>
    8e79:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    8e80:	48 c1 e0 03          	shl    rax,0x3
    8e84:	48 01 d0             	add    rax,rdx
    8e87:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8e8a:	48 89 c7             	mov    rdi,rax
    8e8d:	e8 fe 95 ff ff       	call   2490 <fflush@plt>
    8e92:	e9 e1 00 00 00       	jmp    8f78 <TEST_is_permutation_____3+0xa25>
    8e97:	48 83 bd 30 ff ff ff 	cmp    QWORD PTR [rbp-0xd0],0x0
    8e9e:	00 
    8e9f:	78 4f                	js     8ef0 <TEST_is_permutation_____3+0x99d>
    8ea1:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8ea8:	48 8b 0d 81 81 00 00 	mov    rcx,QWORD PTR [rip+0x8181]        # 11030 <f_ou_th@@Base>
    8eaf:	48 8b 95 30 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd0]
    8eb6:	48 c1 e2 03          	shl    rdx,0x3
    8eba:	48 01 ca             	add    rdx,rcx
    8ebd:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8ec0:	48 89 d6             	mov    rsi,rdx
    8ec3:	48 89 c7             	mov    rdi,rax
    8ec6:	e8 15 95 ff ff       	call   23e0 <fputs@plt>
    8ecb:	48 8b 15 5e 81 00 00 	mov    rdx,QWORD PTR [rip+0x815e]        # 11030 <f_ou_th@@Base>
    8ed2:	48 8b 85 30 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd0]
    8ed9:	48 c1 e0 03          	shl    rax,0x3
    8edd:	48 01 d0             	add    rax,rdx
    8ee0:	48 8b 00             	mov    rax,QWORD PTR [rax]
    8ee3:	48 89 c7             	mov    rdi,rax
    8ee6:	e8 a5 95 ff ff       	call   2490 <fflush@plt>
    8eeb:	e9 88 00 00 00       	jmp    8f78 <TEST_is_permutation_____3+0xa25>
    8ef0:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8ef7:	48 8b 15 2a 81 00 00 	mov    rdx,QWORD PTR [rip+0x812a]        # 11028 <stdout@GLIBC_2.2.5>
    8efe:	48 89 d6             	mov    rsi,rdx
    8f01:	48 89 c7             	mov    rdi,rax
    8f04:	e8 d7 94 ff ff       	call   23e0 <fputs@plt>
    8f09:	eb 6d                	jmp    8f78 <TEST_is_permutation_____3+0xa25>
    8f0b:	48 8b 05 26 81 00 00 	mov    rax,QWORD PTR [rip+0x8126]        # 11038 <savelog@@Base>
    8f12:	48 85 c0             	test   rax,rax
    8f15:	74 48                	je     8f5f <TEST_is_permutation_____3+0xa0c>
    8f17:	48 8b 05 1a 81 00 00 	mov    rax,QWORD PTR [rip+0x811a]        # 11038 <savelog@@Base>
    8f1e:	48 8d 15 5a 51 00 00 	lea    rdx,[rip+0x515a]        # e07f <_IO_stdin_used+0x7f>
    8f25:	48 89 d6             	mov    rsi,rdx
    8f28:	48 89 c7             	mov    rdi,rax
    8f2b:	e8 d0 95 ff ff       	call   2500 <fopen@plt>
    8f30:	48 89 85 28 ff ff ff 	mov    QWORD PTR [rbp-0xd8],rax
    8f37:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8f3e:	48 8b 95 28 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xd8]
    8f45:	48 89 d6             	mov    rsi,rdx
    8f48:	48 89 c7             	mov    rdi,rax
    8f4b:	e8 90 94 ff ff       	call   23e0 <fputs@plt>
    8f50:	48 8b 85 28 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd8]
    8f57:	48 89 c7             	mov    rdi,rax
    8f5a:	e8 51 94 ff ff       	call   23b0 <fclose@plt>
    8f5f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8f66:	48 8b 15 bb 80 00 00 	mov    rdx,QWORD PTR [rip+0x80bb]        # 11028 <stdout@GLIBC_2.2.5>
    8f6d:	48 89 d6             	mov    rsi,rdx
    8f70:	48 89 c7             	mov    rdi,rax
    8f73:	e8 68 94 ff ff       	call   23e0 <fputs@plt>
    8f78:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
    8f7f:	48 89 c7             	mov    rdi,rax
    8f82:	e8 29 94 ff ff       	call   23b0 <fclose@plt>
    8f87:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    8f8e:	48 89 c7             	mov    rdi,rax
    8f91:	e8 9a 93 ff ff       	call   2330 <free@plt>
    8f96:	e9 c7 07 00 00       	jmp    9762 <TEST_is_permutation_____3+0x120f>
    8f9b:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    8fa1:	48 98                	cdqe   
    8fa3:	48 8b 95 a0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x160]
    8faa:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    8fad:	48 89 d1             	mov    rcx,rdx
    8fb0:	48 8d 15 b9 53 00 00 	lea    rdx,[rip+0x53b9]        # e370 <__func__.1>
    8fb7:	48 89 c6             	mov    rsi,rax
    8fba:	48 89 cf             	mov    rdi,rcx
    8fbd:	e8 be 93 ff ff       	call   2380 <expected_EQ_name_TYPE_L_INT@plt>
    8fc2:	84 c0                	test   al,al
    8fc4:	0f 84 87 02 00 00    	je     9251 <TEST_is_permutation_____3+0xcfe>
    8fca:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    8fd1:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    8fd8:	48 89 d6             	mov    rsi,rdx
    8fdb:	48 89 c7             	mov    rdi,rax
    8fde:	e8 6d 93 ff ff       	call   2350 <open_memstream@plt>
    8fe3:	48 89 85 f0 fe ff ff 	mov    QWORD PTR [rbp-0x110],rax
    8fea:	48 83 bd f0 fe ff ff 	cmp    QWORD PTR [rbp-0x110],0x0
    8ff1:	00 
    8ff2:	75 38                	jne    902c <TEST_is_permutation_____3+0xad9>
    8ff4:	48 8b 05 05 81 00 00 	mov    rax,QWORD PTR [rip+0x8105]        # 11100 <stderr@GLIBC_2.2.5>
    8ffb:	4c 8d 05 6e 53 00 00 	lea    r8,[rip+0x536e]        # e370 <__func__.1>
    9002:	b9 5f 00 00 00       	mov    ecx,0x5f
    9007:	48 8d 15 36 50 00 00 	lea    rdx,[rip+0x5036]        # e044 <_IO_stdin_used+0x44>
    900e:	48 8d 35 3b 50 00 00 	lea    rsi,[rip+0x503b]        # e050 <_IO_stdin_used+0x50>
    9015:	48 89 c7             	mov    rdi,rax
    9018:	b8 00 00 00 00       	mov    eax,0x0
    901d:	e8 3e 94 ff ff       	call   2460 <fprintf@plt>
    9022:	bf 00 00 00 00       	mov    edi,0x0
    9027:	e8 f4 94 ff ff       	call   2520 <exit@plt>
    902c:	8b 05 6e 80 00 00    	mov    eax,DWORD PTR [rip+0x806e]        # 110a0 <k_DEFAULT@@Base>
    9032:	48 98                	cdqe   
    9034:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    903b:	00 
    903c:	48 8d 05 7d 80 00 00 	lea    rax,[rip+0x807d]        # 110c0 <colors_f@@Base>
    9043:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    9047:	8b 05 33 80 00 00    	mov    eax,DWORD PTR [rip+0x8033]        # 11080 <hk_TR@@Base>
    904d:	48 98                	cdqe   
    904f:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9056:	00 
    9057:	48 8d 05 e2 7f 00 00 	lea    rax,[rip+0x7fe2]        # 11040 <tab_hk_f@@Base>
    905e:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    9062:	8b 05 88 80 00 00    	mov    eax,DWORD PTR [rip+0x8088]        # 110f0 <k_GREEN@@Base>
    9068:	48 98                	cdqe   
    906a:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9071:	00 
    9072:	48 8d 05 47 80 00 00 	lea    rax,[rip+0x8047]        # 110c0 <colors_f@@Base>
    9079:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    907d:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    9084:	4c 8d 0d e5 52 00 00 	lea    r9,[rip+0x52e5]        # e370 <__func__.1>
    908b:	49 89 f0             	mov    r8,rsi
    908e:	48 8d 35 f3 4f 00 00 	lea    rsi,[rip+0x4ff3]        # e088 <_IO_stdin_used+0x88>
    9095:	48 89 c7             	mov    rdi,rax
    9098:	b8 00 00 00 00       	mov    eax,0x0
    909d:	e8 be 93 ff ff       	call   2460 <fprintf@plt>
    90a2:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    90a9:	48 89 c7             	mov    rdi,rax
    90ac:	e8 df 93 ff ff       	call   2490 <fflush@plt>
    90b1:	0f b6 05 d8 7f 00 00 	movzx  eax,BYTE PTR [rip+0x7fd8]        # 11090 <is_parallel_nb@@Base>
    90b8:	84 c0                	test   al,al
    90ba:	0f 84 01 01 00 00    	je     91c1 <TEST_is_permutation_____3+0xc6e>
    90c0:	e8 8b 93 ff ff       	call   2450 <id_of_thread_executed@plt>
    90c5:	48 89 85 00 ff ff ff 	mov    QWORD PTR [rbp-0x100],rax
    90cc:	0f b6 05 4d 7f 00 00 	movzx  eax,BYTE PTR [rip+0x7f4d]        # 11020 <log_parallel@@Base>
    90d3:	84 c0                	test   al,al
    90d5:	74 76                	je     914d <TEST_is_permutation_____3+0xbfa>
    90d7:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    90de:	48 8b 15 43 7f 00 00 	mov    rdx,QWORD PTR [rip+0x7f43]        # 11028 <stdout@GLIBC_2.2.5>
    90e5:	48 89 d6             	mov    rsi,rdx
    90e8:	48 89 c7             	mov    rdi,rax
    90eb:	e8 f0 92 ff ff       	call   23e0 <fputs@plt>
    90f0:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    90f7:	00 
    90f8:	0f 88 30 01 00 00    	js     922e <TEST_is_permutation_____3+0xcdb>
    90fe:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9105:	48 8b 0d 24 7f 00 00 	mov    rcx,QWORD PTR [rip+0x7f24]        # 11030 <f_ou_th@@Base>
    910c:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    9113:	48 c1 e2 03          	shl    rdx,0x3
    9117:	48 01 ca             	add    rdx,rcx
    911a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    911d:	48 89 d6             	mov    rsi,rdx
    9120:	48 89 c7             	mov    rdi,rax
    9123:	e8 b8 92 ff ff       	call   23e0 <fputs@plt>
    9128:	48 8b 15 01 7f 00 00 	mov    rdx,QWORD PTR [rip+0x7f01]        # 11030 <f_ou_th@@Base>
    912f:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    9136:	48 c1 e0 03          	shl    rax,0x3
    913a:	48 01 d0             	add    rax,rdx
    913d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9140:	48 89 c7             	mov    rdi,rax
    9143:	e8 48 93 ff ff       	call   2490 <fflush@plt>
    9148:	e9 e1 00 00 00       	jmp    922e <TEST_is_permutation_____3+0xcdb>
    914d:	48 83 bd 00 ff ff ff 	cmp    QWORD PTR [rbp-0x100],0x0
    9154:	00 
    9155:	78 4f                	js     91a6 <TEST_is_permutation_____3+0xc53>
    9157:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    915e:	48 8b 0d cb 7e 00 00 	mov    rcx,QWORD PTR [rip+0x7ecb]        # 11030 <f_ou_th@@Base>
    9165:	48 8b 95 00 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x100]
    916c:	48 c1 e2 03          	shl    rdx,0x3
    9170:	48 01 ca             	add    rdx,rcx
    9173:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9176:	48 89 d6             	mov    rsi,rdx
    9179:	48 89 c7             	mov    rdi,rax
    917c:	e8 5f 92 ff ff       	call   23e0 <fputs@plt>
    9181:	48 8b 15 a8 7e 00 00 	mov    rdx,QWORD PTR [rip+0x7ea8]        # 11030 <f_ou_th@@Base>
    9188:	48 8b 85 00 ff ff ff 	mov    rax,QWORD PTR [rbp-0x100]
    918f:	48 c1 e0 03          	shl    rax,0x3
    9193:	48 01 d0             	add    rax,rdx
    9196:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9199:	48 89 c7             	mov    rdi,rax
    919c:	e8 ef 92 ff ff       	call   2490 <fflush@plt>
    91a1:	e9 88 00 00 00       	jmp    922e <TEST_is_permutation_____3+0xcdb>
    91a6:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    91ad:	48 8b 15 74 7e 00 00 	mov    rdx,QWORD PTR [rip+0x7e74]        # 11028 <stdout@GLIBC_2.2.5>
    91b4:	48 89 d6             	mov    rsi,rdx
    91b7:	48 89 c7             	mov    rdi,rax
    91ba:	e8 21 92 ff ff       	call   23e0 <fputs@plt>
    91bf:	eb 6d                	jmp    922e <TEST_is_permutation_____3+0xcdb>
    91c1:	48 8b 05 70 7e 00 00 	mov    rax,QWORD PTR [rip+0x7e70]        # 11038 <savelog@@Base>
    91c8:	48 85 c0             	test   rax,rax
    91cb:	74 48                	je     9215 <TEST_is_permutation_____3+0xcc2>
    91cd:	48 8b 05 64 7e 00 00 	mov    rax,QWORD PTR [rip+0x7e64]        # 11038 <savelog@@Base>
    91d4:	48 8d 15 a4 4e 00 00 	lea    rdx,[rip+0x4ea4]        # e07f <_IO_stdin_used+0x7f>
    91db:	48 89 d6             	mov    rsi,rdx
    91de:	48 89 c7             	mov    rdi,rax
    91e1:	e8 1a 93 ff ff       	call   2500 <fopen@plt>
    91e6:	48 89 85 f8 fe ff ff 	mov    QWORD PTR [rbp-0x108],rax
    91ed:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    91f4:	48 8b 95 f8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x108]
    91fb:	48 89 d6             	mov    rsi,rdx
    91fe:	48 89 c7             	mov    rdi,rax
    9201:	e8 da 91 ff ff       	call   23e0 <fputs@plt>
    9206:	48 8b 85 f8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x108]
    920d:	48 89 c7             	mov    rdi,rax
    9210:	e8 9b 91 ff ff       	call   23b0 <fclose@plt>
    9215:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    921c:	48 8b 15 05 7e 00 00 	mov    rdx,QWORD PTR [rip+0x7e05]        # 11028 <stdout@GLIBC_2.2.5>
    9223:	48 89 d6             	mov    rsi,rdx
    9226:	48 89 c7             	mov    rdi,rax
    9229:	e8 b2 91 ff ff       	call   23e0 <fputs@plt>
    922e:	48 8b 85 f0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x110]
    9235:	48 89 c7             	mov    rdi,rax
    9238:	e8 73 91 ff ff       	call   23b0 <fclose@plt>
    923d:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9244:	48 89 c7             	mov    rdi,rax
    9247:	e8 e4 90 ff ff       	call   2330 <free@plt>
    924c:	e9 11 05 00 00       	jmp    9762 <TEST_is_permutation_____3+0x120f>
    9251:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    9258:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    925f:	48 89 d6             	mov    rsi,rdx
    9262:	48 89 c7             	mov    rdi,rax
    9265:	e8 e6 90 ff ff       	call   2350 <open_memstream@plt>
    926a:	48 89 85 c0 fe ff ff 	mov    QWORD PTR [rbp-0x140],rax
    9271:	48 83 bd c0 fe ff ff 	cmp    QWORD PTR [rbp-0x140],0x0
    9278:	00 
    9279:	75 38                	jne    92b3 <TEST_is_permutation_____3+0xd60>
    927b:	48 8b 05 7e 7e 00 00 	mov    rax,QWORD PTR [rip+0x7e7e]        # 11100 <stderr@GLIBC_2.2.5>
    9282:	4c 8d 05 e7 50 00 00 	lea    r8,[rip+0x50e7]        # e370 <__func__.1>
    9289:	b9 5f 00 00 00       	mov    ecx,0x5f
    928e:	48 8d 15 af 4d 00 00 	lea    rdx,[rip+0x4daf]        # e044 <_IO_stdin_used+0x44>
    9295:	48 8d 35 b4 4d 00 00 	lea    rsi,[rip+0x4db4]        # e050 <_IO_stdin_used+0x50>
    929c:	48 89 c7             	mov    rdi,rax
    929f:	b8 00 00 00 00       	mov    eax,0x0
    92a4:	e8 b7 91 ff ff       	call   2460 <fprintf@plt>
    92a9:	bf 00 00 00 00       	mov    edi,0x0
    92ae:	e8 6d 92 ff ff       	call   2520 <exit@plt>
    92b3:	8b 85 8c fe ff ff    	mov    eax,DWORD PTR [rbp-0x174]
    92b9:	48 98                	cdqe   
    92bb:	48 89 c7             	mov    rdi,rax
    92be:	e8 6d 92 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    92c3:	48 89 c3             	mov    rbx,rax
    92c6:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    92cd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    92d0:	48 89 c7             	mov    rdi,rax
    92d3:	e8 58 92 ff ff       	call   2530 <TYPE_L_INT_TO_STR@plt>
    92d8:	48 89 c2             	mov    rdx,rax
    92db:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    92e2:	53                   	push   rbx
    92e3:	48 8d 0d 6b 4e 00 00 	lea    rcx,[rip+0x4e6b]        # e155 <_IO_stdin_used+0x155>
    92ea:	51                   	push   rcx
    92eb:	52                   	push   rdx
    92ec:	48 8d 15 b5 4d 00 00 	lea    rdx,[rip+0x4db5]        # e0a8 <_IO_stdin_used+0xa8>
    92f3:	52                   	push   rdx
    92f4:	48 8d 15 5a 4e 00 00 	lea    rdx,[rip+0x4e5a]        # e155 <_IO_stdin_used+0x155>
    92fb:	52                   	push   rdx
    92fc:	48 8d 15 01 4e 00 00 	lea    rdx,[rip+0x4e01]        # e104 <_IO_stdin_used+0x104>
    9303:	52                   	push   rdx
    9304:	4c 8d 0d 9d 4d 00 00 	lea    r9,[rip+0x4d9d]        # e0a8 <_IO_stdin_used+0xa8>
    930b:	4c 8d 05 5e 50 00 00 	lea    r8,[rip+0x505e]        # e370 <__func__.1>
    9312:	b9 5f 00 00 00       	mov    ecx,0x5f
    9317:	48 8d 15 26 4d 00 00 	lea    rdx,[rip+0x4d26]        # e044 <_IO_stdin_used+0x44>
    931e:	48 8d 35 8b 4d 00 00 	lea    rsi,[rip+0x4d8b]        # e0b0 <_IO_stdin_used+0xb0>
    9325:	48 89 c7             	mov    rdi,rax
    9328:	b8 00 00 00 00       	mov    eax,0x0
    932d:	e8 2e 91 ff ff       	call   2460 <fprintf@plt>
    9332:	48 83 c4 30          	add    rsp,0x30
    9336:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    933d:	48 89 c7             	mov    rdi,rax
    9340:	e8 4b 91 ff ff       	call   2490 <fflush@plt>
    9345:	0f b6 05 44 7d 00 00 	movzx  eax,BYTE PTR [rip+0x7d44]        # 11090 <is_parallel_nb@@Base>
    934c:	84 c0                	test   al,al
    934e:	0f 84 01 01 00 00    	je     9455 <TEST_is_permutation_____3+0xf02>
    9354:	e8 f7 90 ff ff       	call   2450 <id_of_thread_executed@plt>
    9359:	48 89 85 d0 fe ff ff 	mov    QWORD PTR [rbp-0x130],rax
    9360:	0f b6 05 b9 7c 00 00 	movzx  eax,BYTE PTR [rip+0x7cb9]        # 11020 <log_parallel@@Base>
    9367:	84 c0                	test   al,al
    9369:	74 76                	je     93e1 <TEST_is_permutation_____3+0xe8e>
    936b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9372:	48 8b 15 af 7c 00 00 	mov    rdx,QWORD PTR [rip+0x7caf]        # 11028 <stdout@GLIBC_2.2.5>
    9379:	48 89 d6             	mov    rsi,rdx
    937c:	48 89 c7             	mov    rdi,rax
    937f:	e8 5c 90 ff ff       	call   23e0 <fputs@plt>
    9384:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    938b:	00 
    938c:	0f 88 30 01 00 00    	js     94c2 <TEST_is_permutation_____3+0xf6f>
    9392:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9399:	48 8b 0d 90 7c 00 00 	mov    rcx,QWORD PTR [rip+0x7c90]        # 11030 <f_ou_th@@Base>
    93a0:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    93a7:	48 c1 e2 03          	shl    rdx,0x3
    93ab:	48 01 ca             	add    rdx,rcx
    93ae:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    93b1:	48 89 d6             	mov    rsi,rdx
    93b4:	48 89 c7             	mov    rdi,rax
    93b7:	e8 24 90 ff ff       	call   23e0 <fputs@plt>
    93bc:	48 8b 15 6d 7c 00 00 	mov    rdx,QWORD PTR [rip+0x7c6d]        # 11030 <f_ou_th@@Base>
    93c3:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    93ca:	48 c1 e0 03          	shl    rax,0x3
    93ce:	48 01 d0             	add    rax,rdx
    93d1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    93d4:	48 89 c7             	mov    rdi,rax
    93d7:	e8 b4 90 ff ff       	call   2490 <fflush@plt>
    93dc:	e9 e1 00 00 00       	jmp    94c2 <TEST_is_permutation_____3+0xf6f>
    93e1:	48 83 bd d0 fe ff ff 	cmp    QWORD PTR [rbp-0x130],0x0
    93e8:	00 
    93e9:	78 4f                	js     943a <TEST_is_permutation_____3+0xee7>
    93eb:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    93f2:	48 8b 0d 37 7c 00 00 	mov    rcx,QWORD PTR [rip+0x7c37]        # 11030 <f_ou_th@@Base>
    93f9:	48 8b 95 d0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x130]
    9400:	48 c1 e2 03          	shl    rdx,0x3
    9404:	48 01 ca             	add    rdx,rcx
    9407:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    940a:	48 89 d6             	mov    rsi,rdx
    940d:	48 89 c7             	mov    rdi,rax
    9410:	e8 cb 8f ff ff       	call   23e0 <fputs@plt>
    9415:	48 8b 15 14 7c 00 00 	mov    rdx,QWORD PTR [rip+0x7c14]        # 11030 <f_ou_th@@Base>
    941c:	48 8b 85 d0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x130]
    9423:	48 c1 e0 03          	shl    rax,0x3
    9427:	48 01 d0             	add    rax,rdx
    942a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    942d:	48 89 c7             	mov    rdi,rax
    9430:	e8 5b 90 ff ff       	call   2490 <fflush@plt>
    9435:	e9 88 00 00 00       	jmp    94c2 <TEST_is_permutation_____3+0xf6f>
    943a:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9441:	48 8b 15 e0 7b 00 00 	mov    rdx,QWORD PTR [rip+0x7be0]        # 11028 <stdout@GLIBC_2.2.5>
    9448:	48 89 d6             	mov    rsi,rdx
    944b:	48 89 c7             	mov    rdi,rax
    944e:	e8 8d 8f ff ff       	call   23e0 <fputs@plt>
    9453:	eb 6d                	jmp    94c2 <TEST_is_permutation_____3+0xf6f>
    9455:	48 8b 05 dc 7b 00 00 	mov    rax,QWORD PTR [rip+0x7bdc]        # 11038 <savelog@@Base>
    945c:	48 85 c0             	test   rax,rax
    945f:	74 48                	je     94a9 <TEST_is_permutation_____3+0xf56>
    9461:	48 8b 05 d0 7b 00 00 	mov    rax,QWORD PTR [rip+0x7bd0]        # 11038 <savelog@@Base>
    9468:	48 8d 15 10 4c 00 00 	lea    rdx,[rip+0x4c10]        # e07f <_IO_stdin_used+0x7f>
    946f:	48 89 d6             	mov    rsi,rdx
    9472:	48 89 c7             	mov    rdi,rax
    9475:	e8 86 90 ff ff       	call   2500 <fopen@plt>
    947a:	48 89 85 c8 fe ff ff 	mov    QWORD PTR [rbp-0x138],rax
    9481:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9488:	48 8b 95 c8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x138]
    948f:	48 89 d6             	mov    rsi,rdx
    9492:	48 89 c7             	mov    rdi,rax
    9495:	e8 46 8f ff ff       	call   23e0 <fputs@plt>
    949a:	48 8b 85 c8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x138]
    94a1:	48 89 c7             	mov    rdi,rax
    94a4:	e8 07 8f ff ff       	call   23b0 <fclose@plt>
    94a9:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    94b0:	48 8b 15 71 7b 00 00 	mov    rdx,QWORD PTR [rip+0x7b71]        # 11028 <stdout@GLIBC_2.2.5>
    94b7:	48 89 d6             	mov    rsi,rdx
    94ba:	48 89 c7             	mov    rdi,rax
    94bd:	e8 1e 8f ff ff       	call   23e0 <fputs@plt>
    94c2:	48 8b 85 c0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x140]
    94c9:	48 89 c7             	mov    rdi,rax
    94cc:	e8 df 8e ff ff       	call   23b0 <fclose@plt>
    94d1:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    94d8:	48 89 c7             	mov    rdi,rax
    94db:	e8 50 8e ff ff       	call   2330 <free@plt>
    94e0:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    94e7:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    94ee:	48 89 d6             	mov    rsi,rdx
    94f1:	48 89 c7             	mov    rdi,rax
    94f4:	e8 57 8e ff ff       	call   2350 <open_memstream@plt>
    94f9:	48 89 85 d8 fe ff ff 	mov    QWORD PTR [rbp-0x128],rax
    9500:	48 83 bd d8 fe ff ff 	cmp    QWORD PTR [rbp-0x128],0x0
    9507:	00 
    9508:	75 38                	jne    9542 <TEST_is_permutation_____3+0xfef>
    950a:	48 8b 05 ef 7b 00 00 	mov    rax,QWORD PTR [rip+0x7bef]        # 11100 <stderr@GLIBC_2.2.5>
    9511:	4c 8d 05 58 4e 00 00 	lea    r8,[rip+0x4e58]        # e370 <__func__.1>
    9518:	b9 5f 00 00 00       	mov    ecx,0x5f
    951d:	48 8d 15 20 4b 00 00 	lea    rdx,[rip+0x4b20]        # e044 <_IO_stdin_used+0x44>
    9524:	48 8d 35 25 4b 00 00 	lea    rsi,[rip+0x4b25]        # e050 <_IO_stdin_used+0x50>
    952b:	48 89 c7             	mov    rdi,rax
    952e:	b8 00 00 00 00       	mov    eax,0x0
    9533:	e8 28 8f ff ff       	call   2460 <fprintf@plt>
    9538:	bf 00 00 00 00       	mov    edi,0x0
    953d:	e8 de 8f ff ff       	call   2520 <exit@plt>
    9542:	8b 05 58 7b 00 00    	mov    eax,DWORD PTR [rip+0x7b58]        # 110a0 <k_DEFAULT@@Base>
    9548:	48 98                	cdqe   
    954a:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9551:	00 
    9552:	48 8d 05 67 7b 00 00 	lea    rax,[rip+0x7b67]        # 110c0 <colors_f@@Base>
    9559:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    955d:	8b 05 1d 7b 00 00    	mov    eax,DWORD PTR [rip+0x7b1d]        # 11080 <hk_TR@@Base>
    9563:	48 98                	cdqe   
    9565:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    956c:	00 
    956d:	48 8d 05 cc 7a 00 00 	lea    rax,[rip+0x7acc]        # 11040 <tab_hk_f@@Base>
    9574:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    9578:	8b 05 06 7b 00 00    	mov    eax,DWORD PTR [rip+0x7b06]        # 11084 <k_RED@@Base>
    957e:	48 98                	cdqe   
    9580:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9587:	00 
    9588:	48 8d 05 31 7b 00 00 	lea    rax,[rip+0x7b31]        # 110c0 <colors_f@@Base>
    958f:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    9593:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    959a:	4c 8d 0d cf 4d 00 00 	lea    r9,[rip+0x4dcf]        # e370 <__func__.1>
    95a1:	49 89 f0             	mov    r8,rsi
    95a4:	48 8d 35 5d 4b 00 00 	lea    rsi,[rip+0x4b5d]        # e108 <_IO_stdin_used+0x108>
    95ab:	48 89 c7             	mov    rdi,rax
    95ae:	b8 00 00 00 00       	mov    eax,0x0
    95b3:	e8 a8 8e ff ff       	call   2460 <fprintf@plt>
    95b8:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    95bf:	48 89 c7             	mov    rdi,rax
    95c2:	e8 c9 8e ff ff       	call   2490 <fflush@plt>
    95c7:	0f b6 05 c2 7a 00 00 	movzx  eax,BYTE PTR [rip+0x7ac2]        # 11090 <is_parallel_nb@@Base>
    95ce:	84 c0                	test   al,al
    95d0:	0f 84 01 01 00 00    	je     96d7 <TEST_is_permutation_____3+0x1184>
    95d6:	e8 75 8e ff ff       	call   2450 <id_of_thread_executed@plt>
    95db:	48 89 85 e8 fe ff ff 	mov    QWORD PTR [rbp-0x118],rax
    95e2:	0f b6 05 37 7a 00 00 	movzx  eax,BYTE PTR [rip+0x7a37]        # 11020 <log_parallel@@Base>
    95e9:	84 c0                	test   al,al
    95eb:	74 76                	je     9663 <TEST_is_permutation_____3+0x1110>
    95ed:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    95f4:	48 8b 15 2d 7a 00 00 	mov    rdx,QWORD PTR [rip+0x7a2d]        # 11028 <stdout@GLIBC_2.2.5>
    95fb:	48 89 d6             	mov    rsi,rdx
    95fe:	48 89 c7             	mov    rdi,rax
    9601:	e8 da 8d ff ff       	call   23e0 <fputs@plt>
    9606:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    960d:	00 
    960e:	0f 88 30 01 00 00    	js     9744 <TEST_is_permutation_____3+0x11f1>
    9614:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    961b:	48 8b 0d 0e 7a 00 00 	mov    rcx,QWORD PTR [rip+0x7a0e]        # 11030 <f_ou_th@@Base>
    9622:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    9629:	48 c1 e2 03          	shl    rdx,0x3
    962d:	48 01 ca             	add    rdx,rcx
    9630:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9633:	48 89 d6             	mov    rsi,rdx
    9636:	48 89 c7             	mov    rdi,rax
    9639:	e8 a2 8d ff ff       	call   23e0 <fputs@plt>
    963e:	48 8b 15 eb 79 00 00 	mov    rdx,QWORD PTR [rip+0x79eb]        # 11030 <f_ou_th@@Base>
    9645:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    964c:	48 c1 e0 03          	shl    rax,0x3
    9650:	48 01 d0             	add    rax,rdx
    9653:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9656:	48 89 c7             	mov    rdi,rax
    9659:	e8 32 8e ff ff       	call   2490 <fflush@plt>
    965e:	e9 e1 00 00 00       	jmp    9744 <TEST_is_permutation_____3+0x11f1>
    9663:	48 83 bd e8 fe ff ff 	cmp    QWORD PTR [rbp-0x118],0x0
    966a:	00 
    966b:	78 4f                	js     96bc <TEST_is_permutation_____3+0x1169>
    966d:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9674:	48 8b 0d b5 79 00 00 	mov    rcx,QWORD PTR [rip+0x79b5]        # 11030 <f_ou_th@@Base>
    967b:	48 8b 95 e8 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x118]
    9682:	48 c1 e2 03          	shl    rdx,0x3
    9686:	48 01 ca             	add    rdx,rcx
    9689:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    968c:	48 89 d6             	mov    rsi,rdx
    968f:	48 89 c7             	mov    rdi,rax
    9692:	e8 49 8d ff ff       	call   23e0 <fputs@plt>
    9697:	48 8b 15 92 79 00 00 	mov    rdx,QWORD PTR [rip+0x7992]        # 11030 <f_ou_th@@Base>
    969e:	48 8b 85 e8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x118]
    96a5:	48 c1 e0 03          	shl    rax,0x3
    96a9:	48 01 d0             	add    rax,rdx
    96ac:	48 8b 00             	mov    rax,QWORD PTR [rax]
    96af:	48 89 c7             	mov    rdi,rax
    96b2:	e8 d9 8d ff ff       	call   2490 <fflush@plt>
    96b7:	e9 88 00 00 00       	jmp    9744 <TEST_is_permutation_____3+0x11f1>
    96bc:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    96c3:	48 8b 15 5e 79 00 00 	mov    rdx,QWORD PTR [rip+0x795e]        # 11028 <stdout@GLIBC_2.2.5>
    96ca:	48 89 d6             	mov    rsi,rdx
    96cd:	48 89 c7             	mov    rdi,rax
    96d0:	e8 0b 8d ff ff       	call   23e0 <fputs@plt>
    96d5:	eb 6d                	jmp    9744 <TEST_is_permutation_____3+0x11f1>
    96d7:	48 8b 05 5a 79 00 00 	mov    rax,QWORD PTR [rip+0x795a]        # 11038 <savelog@@Base>
    96de:	48 85 c0             	test   rax,rax
    96e1:	74 48                	je     972b <TEST_is_permutation_____3+0x11d8>
    96e3:	48 8b 05 4e 79 00 00 	mov    rax,QWORD PTR [rip+0x794e]        # 11038 <savelog@@Base>
    96ea:	48 8d 15 8e 49 00 00 	lea    rdx,[rip+0x498e]        # e07f <_IO_stdin_used+0x7f>
    96f1:	48 89 d6             	mov    rsi,rdx
    96f4:	48 89 c7             	mov    rdi,rax
    96f7:	e8 04 8e ff ff       	call   2500 <fopen@plt>
    96fc:	48 89 85 e0 fe ff ff 	mov    QWORD PTR [rbp-0x120],rax
    9703:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    970a:	48 8b 95 e0 fe ff ff 	mov    rdx,QWORD PTR [rbp-0x120]
    9711:	48 89 d6             	mov    rsi,rdx
    9714:	48 89 c7             	mov    rdi,rax
    9717:	e8 c4 8c ff ff       	call   23e0 <fputs@plt>
    971c:	48 8b 85 e0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x120]
    9723:	48 89 c7             	mov    rdi,rax
    9726:	e8 85 8c ff ff       	call   23b0 <fclose@plt>
    972b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9732:	48 8b 15 ef 78 00 00 	mov    rdx,QWORD PTR [rip+0x78ef]        # 11028 <stdout@GLIBC_2.2.5>
    9739:	48 89 d6             	mov    rsi,rdx
    973c:	48 89 c7             	mov    rdi,rax
    973f:	e8 9c 8c ff ff       	call   23e0 <fputs@plt>
    9744:	48 8b 85 d8 fe ff ff 	mov    rax,QWORD PTR [rbp-0x128]
    974b:	48 89 c7             	mov    rdi,rax
    974e:	e8 5d 8c ff ff       	call   23b0 <fclose@plt>
    9753:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    975a:	48 89 c7             	mov    rdi,rax
    975d:	e8 ce 8b ff ff       	call   2330 <free@plt>
    9762:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    9769:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    976d:	f3 0f 10 05 27 4c 00 	movss  xmm0,DWORD PTR [rip+0x4c27]        # e39c <__func__.0+0xc>
    9774:	00 
    9775:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    9779:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    9780:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    9784:	48 83 c0 04          	add    rax,0x4
    9788:	f3 0f 10 05 10 4c 00 	movss  xmm0,DWORD PTR [rip+0x4c10]        # e3a0 <__func__.0+0x10>
    978f:	00 
    9790:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    9794:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    979b:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    979f:	48 83 c0 08          	add    rax,0x8
    97a3:	f3 0f 10 05 f9 4b 00 	movss  xmm0,DWORD PTR [rip+0x4bf9]        # e3a4 <__func__.0+0x14>
    97aa:	00 
    97ab:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    97af:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    97b6:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    97ba:	48 83 c0 0c          	add    rax,0xc
    97be:	f3 0f 10 05 e2 4b 00 	movss  xmm0,DWORD PTR [rip+0x4be2]        # e3a8 <__func__.0+0x18>
    97c5:	00 
    97c6:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    97ca:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    97d1:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    97d5:	48 83 c0 10          	add    rax,0x10
    97d9:	f3 0f 10 05 cf 4b 00 	movss  xmm0,DWORD PTR [rip+0x4bcf]        # e3b0 <__func__.0+0x20>
    97e0:	00 
    97e1:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    97e5:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    97ec:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    97f0:	48 83 c0 14          	add    rax,0x14
    97f4:	f3 0f 10 05 b0 4b 00 	movss  xmm0,DWORD PTR [rip+0x4bb0]        # e3ac <__func__.0+0x1c>
    97fb:	00 
    97fc:	f3 0f 11 00          	movss  DWORD PTR [rax],xmm0
    9800:	0f b6 05 89 78 00 00 	movzx  eax,BYTE PTR [rip+0x7889]        # 11090 <is_parallel_nb@@Base>
    9807:	83 f0 01             	xor    eax,0x1
    980a:	84 c0                	test   al,al
    980c:	0f 84 f4 06 00 00    	je     9f06 <TEST_is_permutation_____3+0x19b3>
    9812:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    9819:	48 89 c7             	mov    rdi,rax
    981c:	e8 a4 2c 00 00       	call   c4c5 <IS_PERMUTATION_TYPE_FLOAT>
    9821:	0f b6 c0             	movzx  eax,al
    9824:	89 c7                	mov    edi,eax
    9826:	e8 45 8c ff ff       	call   2470 <expected_true_f@plt>
    982b:	84 c0                	test   al,al
    982d:	0f 84 57 02 00 00    	je     9a8a <TEST_is_permutation_____3+0x1537>
    9833:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    983a:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    9841:	48 89 d6             	mov    rsi,rdx
    9844:	48 89 c7             	mov    rdi,rax
    9847:	e8 04 8b ff ff       	call   2350 <open_memstream@plt>
    984c:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
    9850:	48 83 7d d0 00       	cmp    QWORD PTR [rbp-0x30],0x0
    9855:	75 38                	jne    988f <TEST_is_permutation_____3+0x133c>
    9857:	48 8b 05 a2 78 00 00 	mov    rax,QWORD PTR [rip+0x78a2]        # 11100 <stderr@GLIBC_2.2.5>
    985e:	4c 8d 05 0b 4b 00 00 	lea    r8,[rip+0x4b0b]        # e370 <__func__.1>
    9865:	b9 68 00 00 00       	mov    ecx,0x68
    986a:	48 8d 15 d3 47 00 00 	lea    rdx,[rip+0x47d3]        # e044 <_IO_stdin_used+0x44>
    9871:	48 8d 35 d8 47 00 00 	lea    rsi,[rip+0x47d8]        # e050 <_IO_stdin_used+0x50>
    9878:	48 89 c7             	mov    rdi,rax
    987b:	b8 00 00 00 00       	mov    eax,0x0
    9880:	e8 db 8b ff ff       	call   2460 <fprintf@plt>
    9885:	bf 00 00 00 00       	mov    edi,0x0
    988a:	e8 91 8c ff ff       	call   2520 <exit@plt>
    988f:	8b 05 0b 78 00 00    	mov    eax,DWORD PTR [rip+0x780b]        # 110a0 <k_DEFAULT@@Base>
    9895:	48 98                	cdqe   
    9897:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    989e:	00 
    989f:	48 8d 05 1a 78 00 00 	lea    rax,[rip+0x781a]        # 110c0 <colors_f@@Base>
    98a6:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    98aa:	8b 05 d0 77 00 00    	mov    eax,DWORD PTR [rip+0x77d0]        # 11080 <hk_TR@@Base>
    98b0:	48 98                	cdqe   
    98b2:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    98b9:	00 
    98ba:	48 8d 05 7f 77 00 00 	lea    rax,[rip+0x777f]        # 11040 <tab_hk_f@@Base>
    98c1:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    98c5:	8b 05 25 78 00 00    	mov    eax,DWORD PTR [rip+0x7825]        # 110f0 <k_GREEN@@Base>
    98cb:	48 98                	cdqe   
    98cd:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    98d4:	00 
    98d5:	48 8d 05 e4 77 00 00 	lea    rax,[rip+0x77e4]        # 110c0 <colors_f@@Base>
    98dc:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    98e0:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    98e4:	4c 8d 0d 85 4a 00 00 	lea    r9,[rip+0x4a85]        # e370 <__func__.1>
    98eb:	49 89 f0             	mov    r8,rsi
    98ee:	48 8d 35 93 47 00 00 	lea    rsi,[rip+0x4793]        # e088 <_IO_stdin_used+0x88>
    98f5:	48 89 c7             	mov    rdi,rax
    98f8:	b8 00 00 00 00       	mov    eax,0x0
    98fd:	e8 5e 8b ff ff       	call   2460 <fprintf@plt>
    9902:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    9906:	48 89 c7             	mov    rdi,rax
    9909:	e8 82 8b ff ff       	call   2490 <fflush@plt>
    990e:	0f b6 05 7b 77 00 00 	movzx  eax,BYTE PTR [rip+0x777b]        # 11090 <is_parallel_nb@@Base>
    9915:	84 c0                	test   al,al
    9917:	0f 84 e9 00 00 00    	je     9a06 <TEST_is_permutation_____3+0x14b3>
    991d:	e8 2e 8b ff ff       	call   2450 <id_of_thread_executed@plt>
    9922:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    9926:	0f b6 05 f3 76 00 00 	movzx  eax,BYTE PTR [rip+0x76f3]        # 11020 <log_parallel@@Base>
    992d:	84 c0                	test   al,al
    992f:	74 6d                	je     999e <TEST_is_permutation_____3+0x144b>
    9931:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9938:	48 8b 15 e9 76 00 00 	mov    rdx,QWORD PTR [rip+0x76e9]        # 11028 <stdout@GLIBC_2.2.5>
    993f:	48 89 d6             	mov    rsi,rdx
    9942:	48 89 c7             	mov    rdi,rax
    9945:	e8 96 8a ff ff       	call   23e0 <fputs@plt>
    994a:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    994f:	0f 88 15 01 00 00    	js     9a6a <TEST_is_permutation_____3+0x1517>
    9955:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    995c:	48 8b 0d cd 76 00 00 	mov    rcx,QWORD PTR [rip+0x76cd]        # 11030 <f_ou_th@@Base>
    9963:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    9967:	48 c1 e2 03          	shl    rdx,0x3
    996b:	48 01 ca             	add    rdx,rcx
    996e:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9971:	48 89 d6             	mov    rsi,rdx
    9974:	48 89 c7             	mov    rdi,rax
    9977:	e8 64 8a ff ff       	call   23e0 <fputs@plt>
    997c:	48 8b 15 ad 76 00 00 	mov    rdx,QWORD PTR [rip+0x76ad]        # 11030 <f_ou_th@@Base>
    9983:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    9987:	48 c1 e0 03          	shl    rax,0x3
    998b:	48 01 d0             	add    rax,rdx
    998e:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9991:	48 89 c7             	mov    rdi,rax
    9994:	e8 f7 8a ff ff       	call   2490 <fflush@plt>
    9999:	e9 cc 00 00 00       	jmp    9a6a <TEST_is_permutation_____3+0x1517>
    999e:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    99a3:	78 46                	js     99eb <TEST_is_permutation_____3+0x1498>
    99a5:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    99ac:	48 8b 0d 7d 76 00 00 	mov    rcx,QWORD PTR [rip+0x767d]        # 11030 <f_ou_th@@Base>
    99b3:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
    99b7:	48 c1 e2 03          	shl    rdx,0x3
    99bb:	48 01 ca             	add    rdx,rcx
    99be:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    99c1:	48 89 d6             	mov    rsi,rdx
    99c4:	48 89 c7             	mov    rdi,rax
    99c7:	e8 14 8a ff ff       	call   23e0 <fputs@plt>
    99cc:	48 8b 15 5d 76 00 00 	mov    rdx,QWORD PTR [rip+0x765d]        # 11030 <f_ou_th@@Base>
    99d3:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    99d7:	48 c1 e0 03          	shl    rax,0x3
    99db:	48 01 d0             	add    rax,rdx
    99de:	48 8b 00             	mov    rax,QWORD PTR [rax]
    99e1:	48 89 c7             	mov    rdi,rax
    99e4:	e8 a7 8a ff ff       	call   2490 <fflush@plt>
    99e9:	eb 7f                	jmp    9a6a <TEST_is_permutation_____3+0x1517>
    99eb:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    99f2:	48 8b 15 2f 76 00 00 	mov    rdx,QWORD PTR [rip+0x762f]        # 11028 <stdout@GLIBC_2.2.5>
    99f9:	48 89 d6             	mov    rsi,rdx
    99fc:	48 89 c7             	mov    rdi,rax
    99ff:	e8 dc 89 ff ff       	call   23e0 <fputs@plt>
    9a04:	eb 64                	jmp    9a6a <TEST_is_permutation_____3+0x1517>
    9a06:	48 8b 05 2b 76 00 00 	mov    rax,QWORD PTR [rip+0x762b]        # 11038 <savelog@@Base>
    9a0d:	48 85 c0             	test   rax,rax
    9a10:	74 3f                	je     9a51 <TEST_is_permutation_____3+0x14fe>
    9a12:	48 8b 05 1f 76 00 00 	mov    rax,QWORD PTR [rip+0x761f]        # 11038 <savelog@@Base>
    9a19:	48 8d 15 5f 46 00 00 	lea    rdx,[rip+0x465f]        # e07f <_IO_stdin_used+0x7f>
    9a20:	48 89 d6             	mov    rsi,rdx
    9a23:	48 89 c7             	mov    rdi,rax
    9a26:	e8 d5 8a ff ff       	call   2500 <fopen@plt>
    9a2b:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    9a2f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9a36:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    9a3a:	48 89 d6             	mov    rsi,rdx
    9a3d:	48 89 c7             	mov    rdi,rax
    9a40:	e8 9b 89 ff ff       	call   23e0 <fputs@plt>
    9a45:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    9a49:	48 89 c7             	mov    rdi,rax
    9a4c:	e8 5f 89 ff ff       	call   23b0 <fclose@plt>
    9a51:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9a58:	48 8b 15 c9 75 00 00 	mov    rdx,QWORD PTR [rip+0x75c9]        # 11028 <stdout@GLIBC_2.2.5>
    9a5f:	48 89 d6             	mov    rsi,rdx
    9a62:	48 89 c7             	mov    rdi,rax
    9a65:	e8 76 89 ff ff       	call   23e0 <fputs@plt>
    9a6a:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    9a6e:	48 89 c7             	mov    rdi,rax
    9a71:	e8 3a 89 ff ff       	call   23b0 <fclose@plt>
    9a76:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9a7d:	48 89 c7             	mov    rdi,rax
    9a80:	e8 ab 88 ff ff       	call   2330 <free@plt>
    9a85:	e9 e8 0b 00 00       	jmp    a672 <TEST_is_permutation_____3+0x211f>
    9a8a:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    9a91:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    9a98:	48 89 d6             	mov    rsi,rdx
    9a9b:	48 89 c7             	mov    rdi,rax
    9a9e:	e8 ad 88 ff ff       	call   2350 <open_memstream@plt>
    9aa3:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
    9aa7:	48 83 7d a0 00       	cmp    QWORD PTR [rbp-0x60],0x0
    9aac:	75 38                	jne    9ae6 <TEST_is_permutation_____3+0x1593>
    9aae:	48 8b 05 4b 76 00 00 	mov    rax,QWORD PTR [rip+0x764b]        # 11100 <stderr@GLIBC_2.2.5>
    9ab5:	4c 8d 05 b4 48 00 00 	lea    r8,[rip+0x48b4]        # e370 <__func__.1>
    9abc:	b9 68 00 00 00       	mov    ecx,0x68
    9ac1:	48 8d 15 7c 45 00 00 	lea    rdx,[rip+0x457c]        # e044 <_IO_stdin_used+0x44>
    9ac8:	48 8d 35 81 45 00 00 	lea    rsi,[rip+0x4581]        # e050 <_IO_stdin_used+0x50>
    9acf:	48 89 c7             	mov    rdi,rax
    9ad2:	b8 00 00 00 00       	mov    eax,0x0
    9ad7:	e8 84 89 ff ff       	call   2460 <fprintf@plt>
    9adc:	bf 00 00 00 00       	mov    edi,0x0
    9ae1:	e8 3a 8a ff ff       	call   2520 <exit@plt>
    9ae6:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    9aea:	48 8d 15 27 47 00 00 	lea    rdx,[rip+0x4727]        # e218 <_IO_stdin_used+0x218>
    9af1:	52                   	push   rdx
    9af2:	48 8d 15 19 47 00 00 	lea    rdx,[rip+0x4719]        # e212 <_IO_stdin_used+0x212>
    9af9:	52                   	push   rdx
    9afa:	4c 8d 0d b3 46 00 00 	lea    r9,[rip+0x46b3]        # e1b4 <_IO_stdin_used+0x1b4>
    9b01:	4c 8d 05 68 48 00 00 	lea    r8,[rip+0x4868]        # e370 <__func__.1>
    9b08:	b9 68 00 00 00       	mov    ecx,0x68
    9b0d:	48 8d 15 30 45 00 00 	lea    rdx,[rip+0x4530]        # e044 <_IO_stdin_used+0x44>
    9b14:	48 8d 35 bd 46 00 00 	lea    rsi,[rip+0x46bd]        # e1d8 <_IO_stdin_used+0x1d8>
    9b1b:	48 89 c7             	mov    rdi,rax
    9b1e:	b8 00 00 00 00       	mov    eax,0x0
    9b23:	e8 38 89 ff ff       	call   2460 <fprintf@plt>
    9b28:	48 83 c4 10          	add    rsp,0x10
    9b2c:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    9b30:	48 89 c7             	mov    rdi,rax
    9b33:	e8 58 89 ff ff       	call   2490 <fflush@plt>
    9b38:	0f b6 05 51 75 00 00 	movzx  eax,BYTE PTR [rip+0x7551]        # 11090 <is_parallel_nb@@Base>
    9b3f:	84 c0                	test   al,al
    9b41:	0f 84 e9 00 00 00    	je     9c30 <TEST_is_permutation_____3+0x16dd>
    9b47:	e8 04 89 ff ff       	call   2450 <id_of_thread_executed@plt>
    9b4c:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
    9b50:	0f b6 05 c9 74 00 00 	movzx  eax,BYTE PTR [rip+0x74c9]        # 11020 <log_parallel@@Base>
    9b57:	84 c0                	test   al,al
    9b59:	74 6d                	je     9bc8 <TEST_is_permutation_____3+0x1675>
    9b5b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9b62:	48 8b 15 bf 74 00 00 	mov    rdx,QWORD PTR [rip+0x74bf]        # 11028 <stdout@GLIBC_2.2.5>
    9b69:	48 89 d6             	mov    rsi,rdx
    9b6c:	48 89 c7             	mov    rdi,rax
    9b6f:	e8 6c 88 ff ff       	call   23e0 <fputs@plt>
    9b74:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    9b79:	0f 88 15 01 00 00    	js     9c94 <TEST_is_permutation_____3+0x1741>
    9b7f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9b86:	48 8b 0d a3 74 00 00 	mov    rcx,QWORD PTR [rip+0x74a3]        # 11030 <f_ou_th@@Base>
    9b8d:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    9b91:	48 c1 e2 03          	shl    rdx,0x3
    9b95:	48 01 ca             	add    rdx,rcx
    9b98:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9b9b:	48 89 d6             	mov    rsi,rdx
    9b9e:	48 89 c7             	mov    rdi,rax
    9ba1:	e8 3a 88 ff ff       	call   23e0 <fputs@plt>
    9ba6:	48 8b 15 83 74 00 00 	mov    rdx,QWORD PTR [rip+0x7483]        # 11030 <f_ou_th@@Base>
    9bad:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    9bb1:	48 c1 e0 03          	shl    rax,0x3
    9bb5:	48 01 d0             	add    rax,rdx
    9bb8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9bbb:	48 89 c7             	mov    rdi,rax
    9bbe:	e8 cd 88 ff ff       	call   2490 <fflush@plt>
    9bc3:	e9 cc 00 00 00       	jmp    9c94 <TEST_is_permutation_____3+0x1741>
    9bc8:	48 83 7d b0 00       	cmp    QWORD PTR [rbp-0x50],0x0
    9bcd:	78 46                	js     9c15 <TEST_is_permutation_____3+0x16c2>
    9bcf:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9bd6:	48 8b 0d 53 74 00 00 	mov    rcx,QWORD PTR [rip+0x7453]        # 11030 <f_ou_th@@Base>
    9bdd:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
    9be1:	48 c1 e2 03          	shl    rdx,0x3
    9be5:	48 01 ca             	add    rdx,rcx
    9be8:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9beb:	48 89 d6             	mov    rsi,rdx
    9bee:	48 89 c7             	mov    rdi,rax
    9bf1:	e8 ea 87 ff ff       	call   23e0 <fputs@plt>
    9bf6:	48 8b 15 33 74 00 00 	mov    rdx,QWORD PTR [rip+0x7433]        # 11030 <f_ou_th@@Base>
    9bfd:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    9c01:	48 c1 e0 03          	shl    rax,0x3
    9c05:	48 01 d0             	add    rax,rdx
    9c08:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9c0b:	48 89 c7             	mov    rdi,rax
    9c0e:	e8 7d 88 ff ff       	call   2490 <fflush@plt>
    9c13:	eb 7f                	jmp    9c94 <TEST_is_permutation_____3+0x1741>
    9c15:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9c1c:	48 8b 15 05 74 00 00 	mov    rdx,QWORD PTR [rip+0x7405]        # 11028 <stdout@GLIBC_2.2.5>
    9c23:	48 89 d6             	mov    rsi,rdx
    9c26:	48 89 c7             	mov    rdi,rax
    9c29:	e8 b2 87 ff ff       	call   23e0 <fputs@plt>
    9c2e:	eb 64                	jmp    9c94 <TEST_is_permutation_____3+0x1741>
    9c30:	48 8b 05 01 74 00 00 	mov    rax,QWORD PTR [rip+0x7401]        # 11038 <savelog@@Base>
    9c37:	48 85 c0             	test   rax,rax
    9c3a:	74 3f                	je     9c7b <TEST_is_permutation_____3+0x1728>
    9c3c:	48 8b 05 f5 73 00 00 	mov    rax,QWORD PTR [rip+0x73f5]        # 11038 <savelog@@Base>
    9c43:	48 8d 15 35 44 00 00 	lea    rdx,[rip+0x4435]        # e07f <_IO_stdin_used+0x7f>
    9c4a:	48 89 d6             	mov    rsi,rdx
    9c4d:	48 89 c7             	mov    rdi,rax
    9c50:	e8 ab 88 ff ff       	call   2500 <fopen@plt>
    9c55:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    9c59:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9c60:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
    9c64:	48 89 d6             	mov    rsi,rdx
    9c67:	48 89 c7             	mov    rdi,rax
    9c6a:	e8 71 87 ff ff       	call   23e0 <fputs@plt>
    9c6f:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    9c73:	48 89 c7             	mov    rdi,rax
    9c76:	e8 35 87 ff ff       	call   23b0 <fclose@plt>
    9c7b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9c82:	48 8b 15 9f 73 00 00 	mov    rdx,QWORD PTR [rip+0x739f]        # 11028 <stdout@GLIBC_2.2.5>
    9c89:	48 89 d6             	mov    rsi,rdx
    9c8c:	48 89 c7             	mov    rdi,rax
    9c8f:	e8 4c 87 ff ff       	call   23e0 <fputs@plt>
    9c94:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    9c98:	48 89 c7             	mov    rdi,rax
    9c9b:	e8 10 87 ff ff       	call   23b0 <fclose@plt>
    9ca0:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9ca7:	48 89 c7             	mov    rdi,rax
    9caa:	e8 81 86 ff ff       	call   2330 <free@plt>
    9caf:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    9cb6:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    9cbd:	48 89 d6             	mov    rsi,rdx
    9cc0:	48 89 c7             	mov    rdi,rax
    9cc3:	e8 88 86 ff ff       	call   2350 <open_memstream@plt>
    9cc8:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
    9ccc:	48 83 7d b8 00       	cmp    QWORD PTR [rbp-0x48],0x0
    9cd1:	75 38                	jne    9d0b <TEST_is_permutation_____3+0x17b8>
    9cd3:	48 8b 05 26 74 00 00 	mov    rax,QWORD PTR [rip+0x7426]        # 11100 <stderr@GLIBC_2.2.5>
    9cda:	4c 8d 05 8f 46 00 00 	lea    r8,[rip+0x468f]        # e370 <__func__.1>
    9ce1:	b9 68 00 00 00       	mov    ecx,0x68
    9ce6:	48 8d 15 57 43 00 00 	lea    rdx,[rip+0x4357]        # e044 <_IO_stdin_used+0x44>
    9ced:	48 8d 35 5c 43 00 00 	lea    rsi,[rip+0x435c]        # e050 <_IO_stdin_used+0x50>
    9cf4:	48 89 c7             	mov    rdi,rax
    9cf7:	b8 00 00 00 00       	mov    eax,0x0
    9cfc:	e8 5f 87 ff ff       	call   2460 <fprintf@plt>
    9d01:	bf 00 00 00 00       	mov    edi,0x0
    9d06:	e8 15 88 ff ff       	call   2520 <exit@plt>
    9d0b:	8b 05 8f 73 00 00    	mov    eax,DWORD PTR [rip+0x738f]        # 110a0 <k_DEFAULT@@Base>
    9d11:	48 98                	cdqe   
    9d13:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9d1a:	00 
    9d1b:	48 8d 05 9e 73 00 00 	lea    rax,[rip+0x739e]        # 110c0 <colors_f@@Base>
    9d22:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    9d26:	8b 05 54 73 00 00    	mov    eax,DWORD PTR [rip+0x7354]        # 11080 <hk_TR@@Base>
    9d2c:	48 98                	cdqe   
    9d2e:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9d35:	00 
    9d36:	48 8d 05 03 73 00 00 	lea    rax,[rip+0x7303]        # 11040 <tab_hk_f@@Base>
    9d3d:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    9d41:	8b 05 3d 73 00 00    	mov    eax,DWORD PTR [rip+0x733d]        # 11084 <k_RED@@Base>
    9d47:	48 98                	cdqe   
    9d49:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9d50:	00 
    9d51:	48 8d 05 68 73 00 00 	lea    rax,[rip+0x7368]        # 110c0 <colors_f@@Base>
    9d58:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    9d5c:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    9d60:	4c 8d 0d 09 46 00 00 	lea    r9,[rip+0x4609]        # e370 <__func__.1>
    9d67:	49 89 f0             	mov    r8,rsi
    9d6a:	48 8d 35 af 44 00 00 	lea    rsi,[rip+0x44af]        # e220 <_IO_stdin_used+0x220>
    9d71:	48 89 c7             	mov    rdi,rax
    9d74:	b8 00 00 00 00       	mov    eax,0x0
    9d79:	e8 e2 86 ff ff       	call   2460 <fprintf@plt>
    9d7e:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    9d82:	48 89 c7             	mov    rdi,rax
    9d85:	e8 06 87 ff ff       	call   2490 <fflush@plt>
    9d8a:	0f b6 05 ff 72 00 00 	movzx  eax,BYTE PTR [rip+0x72ff]        # 11090 <is_parallel_nb@@Base>
    9d91:	84 c0                	test   al,al
    9d93:	0f 84 e9 00 00 00    	je     9e82 <TEST_is_permutation_____3+0x192f>
    9d99:	e8 b2 86 ff ff       	call   2450 <id_of_thread_executed@plt>
    9d9e:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
    9da2:	0f b6 05 77 72 00 00 	movzx  eax,BYTE PTR [rip+0x7277]        # 11020 <log_parallel@@Base>
    9da9:	84 c0                	test   al,al
    9dab:	74 6d                	je     9e1a <TEST_is_permutation_____3+0x18c7>
    9dad:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9db4:	48 8b 15 6d 72 00 00 	mov    rdx,QWORD PTR [rip+0x726d]        # 11028 <stdout@GLIBC_2.2.5>
    9dbb:	48 89 d6             	mov    rsi,rdx
    9dbe:	48 89 c7             	mov    rdi,rax
    9dc1:	e8 1a 86 ff ff       	call   23e0 <fputs@plt>
    9dc6:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    9dcb:	0f 88 15 01 00 00    	js     9ee6 <TEST_is_permutation_____3+0x1993>
    9dd1:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9dd8:	48 8b 0d 51 72 00 00 	mov    rcx,QWORD PTR [rip+0x7251]        # 11030 <f_ou_th@@Base>
    9ddf:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    9de3:	48 c1 e2 03          	shl    rdx,0x3
    9de7:	48 01 ca             	add    rdx,rcx
    9dea:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9ded:	48 89 d6             	mov    rsi,rdx
    9df0:	48 89 c7             	mov    rdi,rax
    9df3:	e8 e8 85 ff ff       	call   23e0 <fputs@plt>
    9df8:	48 8b 15 31 72 00 00 	mov    rdx,QWORD PTR [rip+0x7231]        # 11030 <f_ou_th@@Base>
    9dff:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    9e03:	48 c1 e0 03          	shl    rax,0x3
    9e07:	48 01 d0             	add    rax,rdx
    9e0a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9e0d:	48 89 c7             	mov    rdi,rax
    9e10:	e8 7b 86 ff ff       	call   2490 <fflush@plt>
    9e15:	e9 cc 00 00 00       	jmp    9ee6 <TEST_is_permutation_____3+0x1993>
    9e1a:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    9e1f:	78 46                	js     9e67 <TEST_is_permutation_____3+0x1914>
    9e21:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9e28:	48 8b 0d 01 72 00 00 	mov    rcx,QWORD PTR [rip+0x7201]        # 11030 <f_ou_th@@Base>
    9e2f:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
    9e33:	48 c1 e2 03          	shl    rdx,0x3
    9e37:	48 01 ca             	add    rdx,rcx
    9e3a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    9e3d:	48 89 d6             	mov    rsi,rdx
    9e40:	48 89 c7             	mov    rdi,rax
    9e43:	e8 98 85 ff ff       	call   23e0 <fputs@plt>
    9e48:	48 8b 15 e1 71 00 00 	mov    rdx,QWORD PTR [rip+0x71e1]        # 11030 <f_ou_th@@Base>
    9e4f:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    9e53:	48 c1 e0 03          	shl    rax,0x3
    9e57:	48 01 d0             	add    rax,rdx
    9e5a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9e5d:	48 89 c7             	mov    rdi,rax
    9e60:	e8 2b 86 ff ff       	call   2490 <fflush@plt>
    9e65:	eb 7f                	jmp    9ee6 <TEST_is_permutation_____3+0x1993>
    9e67:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9e6e:	48 8b 15 b3 71 00 00 	mov    rdx,QWORD PTR [rip+0x71b3]        # 11028 <stdout@GLIBC_2.2.5>
    9e75:	48 89 d6             	mov    rsi,rdx
    9e78:	48 89 c7             	mov    rdi,rax
    9e7b:	e8 60 85 ff ff       	call   23e0 <fputs@plt>
    9e80:	eb 64                	jmp    9ee6 <TEST_is_permutation_____3+0x1993>
    9e82:	48 8b 05 af 71 00 00 	mov    rax,QWORD PTR [rip+0x71af]        # 11038 <savelog@@Base>
    9e89:	48 85 c0             	test   rax,rax
    9e8c:	74 3f                	je     9ecd <TEST_is_permutation_____3+0x197a>
    9e8e:	48 8b 05 a3 71 00 00 	mov    rax,QWORD PTR [rip+0x71a3]        # 11038 <savelog@@Base>
    9e95:	48 8d 15 e3 41 00 00 	lea    rdx,[rip+0x41e3]        # e07f <_IO_stdin_used+0x7f>
    9e9c:	48 89 d6             	mov    rsi,rdx
    9e9f:	48 89 c7             	mov    rdi,rax
    9ea2:	e8 59 86 ff ff       	call   2500 <fopen@plt>
    9ea7:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
    9eab:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9eb2:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
    9eb6:	48 89 d6             	mov    rsi,rdx
    9eb9:	48 89 c7             	mov    rdi,rax
    9ebc:	e8 1f 85 ff ff       	call   23e0 <fputs@plt>
    9ec1:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
    9ec5:	48 89 c7             	mov    rdi,rax
    9ec8:	e8 e3 84 ff ff       	call   23b0 <fclose@plt>
    9ecd:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9ed4:	48 8b 15 4d 71 00 00 	mov    rdx,QWORD PTR [rip+0x714d]        # 11028 <stdout@GLIBC_2.2.5>
    9edb:	48 89 d6             	mov    rsi,rdx
    9ede:	48 89 c7             	mov    rdi,rax
    9ee1:	e8 fa 84 ff ff       	call   23e0 <fputs@plt>
    9ee6:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    9eea:	48 89 c7             	mov    rdi,rax
    9eed:	e8 be 84 ff ff       	call   23b0 <fclose@plt>
    9ef2:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    9ef9:	48 89 c7             	mov    rdi,rax
    9efc:	e8 2f 84 ff ff       	call   2330 <free@plt>
    9f01:	e9 6c 07 00 00       	jmp    a672 <TEST_is_permutation_____3+0x211f>
    9f06:	e8 45 85 ff ff       	call   2450 <id_of_thread_executed@plt>
    9f0b:	48 89 85 50 ff ff ff 	mov    QWORD PTR [rbp-0xb0],rax
    9f12:	48 8b 85 a0 fe ff ff 	mov    rax,QWORD PTR [rbp-0x160]
    9f19:	48 89 c7             	mov    rdi,rax
    9f1c:	e8 a4 25 00 00       	call   c4c5 <IS_PERMUTATION_TYPE_FLOAT>
    9f21:	0f b6 c0             	movzx  eax,al
    9f24:	48 8d 15 45 44 00 00 	lea    rdx,[rip+0x4445]        # e370 <__func__.1>
    9f2b:	48 89 d6             	mov    rsi,rdx
    9f2e:	89 c7                	mov    edi,eax
    9f30:	e8 bb 84 ff ff       	call   23f0 <expected_true_f_name@plt>
    9f35:	84 c0                	test   al,al
    9f37:	0f 84 65 02 00 00    	je     a1a2 <TEST_is_permutation_____3+0x1c4f>
    9f3d:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    9f44:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    9f4b:	48 89 d6             	mov    rsi,rdx
    9f4e:	48 89 c7             	mov    rdi,rax
    9f51:	e8 fa 83 ff ff       	call   2350 <open_memstream@plt>
    9f56:	48 89 45 88          	mov    QWORD PTR [rbp-0x78],rax
    9f5a:	48 83 7d 88 00       	cmp    QWORD PTR [rbp-0x78],0x0
    9f5f:	75 38                	jne    9f99 <TEST_is_permutation_____3+0x1a46>
    9f61:	48 8b 05 98 71 00 00 	mov    rax,QWORD PTR [rip+0x7198]        # 11100 <stderr@GLIBC_2.2.5>
    9f68:	4c 8d 05 01 44 00 00 	lea    r8,[rip+0x4401]        # e370 <__func__.1>
    9f6f:	b9 68 00 00 00       	mov    ecx,0x68
    9f74:	48 8d 15 c9 40 00 00 	lea    rdx,[rip+0x40c9]        # e044 <_IO_stdin_used+0x44>
    9f7b:	48 8d 35 ce 40 00 00 	lea    rsi,[rip+0x40ce]        # e050 <_IO_stdin_used+0x50>
    9f82:	48 89 c7             	mov    rdi,rax
    9f85:	b8 00 00 00 00       	mov    eax,0x0
    9f8a:	e8 d1 84 ff ff       	call   2460 <fprintf@plt>
    9f8f:	bf 00 00 00 00       	mov    edi,0x0
    9f94:	e8 87 85 ff ff       	call   2520 <exit@plt>
    9f99:	8b 05 01 71 00 00    	mov    eax,DWORD PTR [rip+0x7101]        # 110a0 <k_DEFAULT@@Base>
    9f9f:	48 98                	cdqe   
    9fa1:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9fa8:	00 
    9fa9:	48 8d 05 10 71 00 00 	lea    rax,[rip+0x7110]        # 110c0 <colors_f@@Base>
    9fb0:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    9fb4:	8b 05 c6 70 00 00    	mov    eax,DWORD PTR [rip+0x70c6]        # 11080 <hk_TR@@Base>
    9fba:	48 98                	cdqe   
    9fbc:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9fc3:	00 
    9fc4:	48 8d 05 75 70 00 00 	lea    rax,[rip+0x7075]        # 11040 <tab_hk_f@@Base>
    9fcb:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    9fcf:	8b 05 1b 71 00 00    	mov    eax,DWORD PTR [rip+0x711b]        # 110f0 <k_GREEN@@Base>
    9fd5:	48 98                	cdqe   
    9fd7:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    9fde:	00 
    9fdf:	48 8d 05 da 70 00 00 	lea    rax,[rip+0x70da]        # 110c0 <colors_f@@Base>
    9fe6:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    9fea:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    9fee:	48 83 ec 08          	sub    rsp,0x8
    9ff2:	ff b5 50 ff ff ff    	push   QWORD PTR [rbp-0xb0]
    9ff8:	4c 8d 0d 71 43 00 00 	lea    r9,[rip+0x4371]        # e370 <__func__.1>
    9fff:	49 89 f0             	mov    r8,rsi
    a002:	48 8d 35 37 42 00 00 	lea    rsi,[rip+0x4237]        # e240 <_IO_stdin_used+0x240>
    a009:	48 89 c7             	mov    rdi,rax
    a00c:	b8 00 00 00 00       	mov    eax,0x0
    a011:	e8 4a 84 ff ff       	call   2460 <fprintf@plt>
    a016:	48 83 c4 10          	add    rsp,0x10
    a01a:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    a01e:	48 89 c7             	mov    rdi,rax
    a021:	e8 6a 84 ff ff       	call   2490 <fflush@plt>
    a026:	0f b6 05 63 70 00 00 	movzx  eax,BYTE PTR [rip+0x7063]        # 11090 <is_parallel_nb@@Base>
    a02d:	84 c0                	test   al,al
    a02f:	0f 84 e9 00 00 00    	je     a11e <TEST_is_permutation_____3+0x1bcb>
    a035:	e8 16 84 ff ff       	call   2450 <id_of_thread_executed@plt>
    a03a:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
    a03e:	0f b6 05 db 6f 00 00 	movzx  eax,BYTE PTR [rip+0x6fdb]        # 11020 <log_parallel@@Base>
    a045:	84 c0                	test   al,al
    a047:	74 6d                	je     a0b6 <TEST_is_permutation_____3+0x1b63>
    a049:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a050:	48 8b 15 d1 6f 00 00 	mov    rdx,QWORD PTR [rip+0x6fd1]        # 11028 <stdout@GLIBC_2.2.5>
    a057:	48 89 d6             	mov    rsi,rdx
    a05a:	48 89 c7             	mov    rdi,rax
    a05d:	e8 7e 83 ff ff       	call   23e0 <fputs@plt>
    a062:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    a067:	0f 88 15 01 00 00    	js     a182 <TEST_is_permutation_____3+0x1c2f>
    a06d:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a074:	48 8b 0d b5 6f 00 00 	mov    rcx,QWORD PTR [rip+0x6fb5]        # 11030 <f_ou_th@@Base>
    a07b:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    a07f:	48 c1 e2 03          	shl    rdx,0x3
    a083:	48 01 ca             	add    rdx,rcx
    a086:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a089:	48 89 d6             	mov    rsi,rdx
    a08c:	48 89 c7             	mov    rdi,rax
    a08f:	e8 4c 83 ff ff       	call   23e0 <fputs@plt>
    a094:	48 8b 15 95 6f 00 00 	mov    rdx,QWORD PTR [rip+0x6f95]        # 11030 <f_ou_th@@Base>
    a09b:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    a09f:	48 c1 e0 03          	shl    rax,0x3
    a0a3:	48 01 d0             	add    rax,rdx
    a0a6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a0a9:	48 89 c7             	mov    rdi,rax
    a0ac:	e8 df 83 ff ff       	call   2490 <fflush@plt>
    a0b1:	e9 cc 00 00 00       	jmp    a182 <TEST_is_permutation_____3+0x1c2f>
    a0b6:	48 83 7d 98 00       	cmp    QWORD PTR [rbp-0x68],0x0
    a0bb:	78 46                	js     a103 <TEST_is_permutation_____3+0x1bb0>
    a0bd:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a0c4:	48 8b 0d 65 6f 00 00 	mov    rcx,QWORD PTR [rip+0x6f65]        # 11030 <f_ou_th@@Base>
    a0cb:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
    a0cf:	48 c1 e2 03          	shl    rdx,0x3
    a0d3:	48 01 ca             	add    rdx,rcx
    a0d6:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a0d9:	48 89 d6             	mov    rsi,rdx
    a0dc:	48 89 c7             	mov    rdi,rax
    a0df:	e8 fc 82 ff ff       	call   23e0 <fputs@plt>
    a0e4:	48 8b 15 45 6f 00 00 	mov    rdx,QWORD PTR [rip+0x6f45]        # 11030 <f_ou_th@@Base>
    a0eb:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
    a0ef:	48 c1 e0 03          	shl    rax,0x3
    a0f3:	48 01 d0             	add    rax,rdx
    a0f6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a0f9:	48 89 c7             	mov    rdi,rax
    a0fc:	e8 8f 83 ff ff       	call   2490 <fflush@plt>
    a101:	eb 7f                	jmp    a182 <TEST_is_permutation_____3+0x1c2f>
    a103:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a10a:	48 8b 15 17 6f 00 00 	mov    rdx,QWORD PTR [rip+0x6f17]        # 11028 <stdout@GLIBC_2.2.5>
    a111:	48 89 d6             	mov    rsi,rdx
    a114:	48 89 c7             	mov    rdi,rax
    a117:	e8 c4 82 ff ff       	call   23e0 <fputs@plt>
    a11c:	eb 64                	jmp    a182 <TEST_is_permutation_____3+0x1c2f>
    a11e:	48 8b 05 13 6f 00 00 	mov    rax,QWORD PTR [rip+0x6f13]        # 11038 <savelog@@Base>
    a125:	48 85 c0             	test   rax,rax
    a128:	74 3f                	je     a169 <TEST_is_permutation_____3+0x1c16>
    a12a:	48 8b 05 07 6f 00 00 	mov    rax,QWORD PTR [rip+0x6f07]        # 11038 <savelog@@Base>
    a131:	48 8d 15 47 3f 00 00 	lea    rdx,[rip+0x3f47]        # e07f <_IO_stdin_used+0x7f>
    a138:	48 89 d6             	mov    rsi,rdx
    a13b:	48 89 c7             	mov    rdi,rax
    a13e:	e8 bd 83 ff ff       	call   2500 <fopen@plt>
    a143:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
    a147:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a14e:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
    a152:	48 89 d6             	mov    rsi,rdx
    a155:	48 89 c7             	mov    rdi,rax
    a158:	e8 83 82 ff ff       	call   23e0 <fputs@plt>
    a15d:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
    a161:	48 89 c7             	mov    rdi,rax
    a164:	e8 47 82 ff ff       	call   23b0 <fclose@plt>
    a169:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a170:	48 8b 15 b1 6e 00 00 	mov    rdx,QWORD PTR [rip+0x6eb1]        # 11028 <stdout@GLIBC_2.2.5>
    a177:	48 89 d6             	mov    rsi,rdx
    a17a:	48 89 c7             	mov    rdi,rax
    a17d:	e8 5e 82 ff ff       	call   23e0 <fputs@plt>
    a182:	48 8b 45 88          	mov    rax,QWORD PTR [rbp-0x78]
    a186:	48 89 c7             	mov    rdi,rax
    a189:	e8 22 82 ff ff       	call   23b0 <fclose@plt>
    a18e:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a195:	48 89 c7             	mov    rdi,rax
    a198:	e8 93 81 ff ff       	call   2330 <free@plt>
    a19d:	e9 d0 04 00 00       	jmp    a672 <TEST_is_permutation_____3+0x211f>
    a1a2:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    a1a9:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    a1b0:	48 89 d6             	mov    rsi,rdx
    a1b3:	48 89 c7             	mov    rdi,rax
    a1b6:	e8 95 81 ff ff       	call   2350 <open_memstream@plt>
    a1bb:	48 89 85 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rax
    a1c2:	48 83 bd 58 ff ff ff 	cmp    QWORD PTR [rbp-0xa8],0x0
    a1c9:	00 
    a1ca:	75 38                	jne    a204 <TEST_is_permutation_____3+0x1cb1>
    a1cc:	48 8b 05 2d 6f 00 00 	mov    rax,QWORD PTR [rip+0x6f2d]        # 11100 <stderr@GLIBC_2.2.5>
    a1d3:	4c 8d 05 96 41 00 00 	lea    r8,[rip+0x4196]        # e370 <__func__.1>
    a1da:	b9 68 00 00 00       	mov    ecx,0x68
    a1df:	48 8d 15 5e 3e 00 00 	lea    rdx,[rip+0x3e5e]        # e044 <_IO_stdin_used+0x44>
    a1e6:	48 8d 35 63 3e 00 00 	lea    rsi,[rip+0x3e63]        # e050 <_IO_stdin_used+0x50>
    a1ed:	48 89 c7             	mov    rdi,rax
    a1f0:	b8 00 00 00 00       	mov    eax,0x0
    a1f5:	e8 66 82 ff ff       	call   2460 <fprintf@plt>
    a1fa:	bf 00 00 00 00       	mov    edi,0x0
    a1ff:	e8 1c 83 ff ff       	call   2520 <exit@plt>
    a204:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    a20b:	48 8d 15 06 40 00 00 	lea    rdx,[rip+0x4006]        # e218 <_IO_stdin_used+0x218>
    a212:	52                   	push   rdx
    a213:	48 8d 15 f8 3f 00 00 	lea    rdx,[rip+0x3ff8]        # e212 <_IO_stdin_used+0x212>
    a21a:	52                   	push   rdx
    a21b:	4c 8d 0d 92 3f 00 00 	lea    r9,[rip+0x3f92]        # e1b4 <_IO_stdin_used+0x1b4>
    a222:	4c 8d 05 47 41 00 00 	lea    r8,[rip+0x4147]        # e370 <__func__.1>
    a229:	b9 68 00 00 00       	mov    ecx,0x68
    a22e:	48 8d 15 0f 3e 00 00 	lea    rdx,[rip+0x3e0f]        # e044 <_IO_stdin_used+0x44>
    a235:	48 8d 35 9c 3f 00 00 	lea    rsi,[rip+0x3f9c]        # e1d8 <_IO_stdin_used+0x1d8>
    a23c:	48 89 c7             	mov    rdi,rax
    a23f:	b8 00 00 00 00       	mov    eax,0x0
    a244:	e8 17 82 ff ff       	call   2460 <fprintf@plt>
    a249:	48 83 c4 10          	add    rsp,0x10
    a24d:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    a254:	48 89 c7             	mov    rdi,rax
    a257:	e8 34 82 ff ff       	call   2490 <fflush@plt>
    a25c:	0f b6 05 2d 6e 00 00 	movzx  eax,BYTE PTR [rip+0x6e2d]        # 11090 <is_parallel_nb@@Base>
    a263:	84 c0                	test   al,al
    a265:	0f 84 01 01 00 00    	je     a36c <TEST_is_permutation_____3+0x1e19>
    a26b:	e8 e0 81 ff ff       	call   2450 <id_of_thread_executed@plt>
    a270:	48 89 85 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rax
    a277:	0f b6 05 a2 6d 00 00 	movzx  eax,BYTE PTR [rip+0x6da2]        # 11020 <log_parallel@@Base>
    a27e:	84 c0                	test   al,al
    a280:	74 76                	je     a2f8 <TEST_is_permutation_____3+0x1da5>
    a282:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a289:	48 8b 15 98 6d 00 00 	mov    rdx,QWORD PTR [rip+0x6d98]        # 11028 <stdout@GLIBC_2.2.5>
    a290:	48 89 d6             	mov    rsi,rdx
    a293:	48 89 c7             	mov    rdi,rax
    a296:	e8 45 81 ff ff       	call   23e0 <fputs@plt>
    a29b:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    a2a2:	00 
    a2a3:	0f 88 30 01 00 00    	js     a3d9 <TEST_is_permutation_____3+0x1e86>
    a2a9:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a2b0:	48 8b 0d 79 6d 00 00 	mov    rcx,QWORD PTR [rip+0x6d79]        # 11030 <f_ou_th@@Base>
    a2b7:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    a2be:	48 c1 e2 03          	shl    rdx,0x3
    a2c2:	48 01 ca             	add    rdx,rcx
    a2c5:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a2c8:	48 89 d6             	mov    rsi,rdx
    a2cb:	48 89 c7             	mov    rdi,rax
    a2ce:	e8 0d 81 ff ff       	call   23e0 <fputs@plt>
    a2d3:	48 8b 15 56 6d 00 00 	mov    rdx,QWORD PTR [rip+0x6d56]        # 11030 <f_ou_th@@Base>
    a2da:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    a2e1:	48 c1 e0 03          	shl    rax,0x3
    a2e5:	48 01 d0             	add    rax,rdx
    a2e8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a2eb:	48 89 c7             	mov    rdi,rax
    a2ee:	e8 9d 81 ff ff       	call   2490 <fflush@plt>
    a2f3:	e9 e1 00 00 00       	jmp    a3d9 <TEST_is_permutation_____3+0x1e86>
    a2f8:	48 83 bd 68 ff ff ff 	cmp    QWORD PTR [rbp-0x98],0x0
    a2ff:	00 
    a300:	78 4f                	js     a351 <TEST_is_permutation_____3+0x1dfe>
    a302:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a309:	48 8b 0d 20 6d 00 00 	mov    rcx,QWORD PTR [rip+0x6d20]        # 11030 <f_ou_th@@Base>
    a310:	48 8b 95 68 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x98]
    a317:	48 c1 e2 03          	shl    rdx,0x3
    a31b:	48 01 ca             	add    rdx,rcx
    a31e:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a321:	48 89 d6             	mov    rsi,rdx
    a324:	48 89 c7             	mov    rdi,rax
    a327:	e8 b4 80 ff ff       	call   23e0 <fputs@plt>
    a32c:	48 8b 15 fd 6c 00 00 	mov    rdx,QWORD PTR [rip+0x6cfd]        # 11030 <f_ou_th@@Base>
    a333:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    a33a:	48 c1 e0 03          	shl    rax,0x3
    a33e:	48 01 d0             	add    rax,rdx
    a341:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a344:	48 89 c7             	mov    rdi,rax
    a347:	e8 44 81 ff ff       	call   2490 <fflush@plt>
    a34c:	e9 88 00 00 00       	jmp    a3d9 <TEST_is_permutation_____3+0x1e86>
    a351:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a358:	48 8b 15 c9 6c 00 00 	mov    rdx,QWORD PTR [rip+0x6cc9]        # 11028 <stdout@GLIBC_2.2.5>
    a35f:	48 89 d6             	mov    rsi,rdx
    a362:	48 89 c7             	mov    rdi,rax
    a365:	e8 76 80 ff ff       	call   23e0 <fputs@plt>
    a36a:	eb 6d                	jmp    a3d9 <TEST_is_permutation_____3+0x1e86>
    a36c:	48 8b 05 c5 6c 00 00 	mov    rax,QWORD PTR [rip+0x6cc5]        # 11038 <savelog@@Base>
    a373:	48 85 c0             	test   rax,rax
    a376:	74 48                	je     a3c0 <TEST_is_permutation_____3+0x1e6d>
    a378:	48 8b 05 b9 6c 00 00 	mov    rax,QWORD PTR [rip+0x6cb9]        # 11038 <savelog@@Base>
    a37f:	48 8d 15 f9 3c 00 00 	lea    rdx,[rip+0x3cf9]        # e07f <_IO_stdin_used+0x7f>
    a386:	48 89 d6             	mov    rsi,rdx
    a389:	48 89 c7             	mov    rdi,rax
    a38c:	e8 6f 81 ff ff       	call   2500 <fopen@plt>
    a391:	48 89 85 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rax
    a398:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a39f:	48 8b 95 60 ff ff ff 	mov    rdx,QWORD PTR [rbp-0xa0]
    a3a6:	48 89 d6             	mov    rsi,rdx
    a3a9:	48 89 c7             	mov    rdi,rax
    a3ac:	e8 2f 80 ff ff       	call   23e0 <fputs@plt>
    a3b1:	48 8b 85 60 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa0]
    a3b8:	48 89 c7             	mov    rdi,rax
    a3bb:	e8 f0 7f ff ff       	call   23b0 <fclose@plt>
    a3c0:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a3c7:	48 8b 15 5a 6c 00 00 	mov    rdx,QWORD PTR [rip+0x6c5a]        # 11028 <stdout@GLIBC_2.2.5>
    a3ce:	48 89 d6             	mov    rsi,rdx
    a3d1:	48 89 c7             	mov    rdi,rax
    a3d4:	e8 07 80 ff ff       	call   23e0 <fputs@plt>
    a3d9:	48 8b 85 58 ff ff ff 	mov    rax,QWORD PTR [rbp-0xa8]
    a3e0:	48 89 c7             	mov    rdi,rax
    a3e3:	e8 c8 7f ff ff       	call   23b0 <fclose@plt>
    a3e8:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a3ef:	48 89 c7             	mov    rdi,rax
    a3f2:	e8 39 7f ff ff       	call   2330 <free@plt>
    a3f7:	48 8d 95 90 fe ff ff 	lea    rdx,[rbp-0x170]
    a3fe:	48 8d 85 98 fe ff ff 	lea    rax,[rbp-0x168]
    a405:	48 89 d6             	mov    rsi,rdx
    a408:	48 89 c7             	mov    rdi,rax
    a40b:	e8 40 7f ff ff       	call   2350 <open_memstream@plt>
    a410:	48 89 85 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rax
    a417:	48 83 bd 70 ff ff ff 	cmp    QWORD PTR [rbp-0x90],0x0
    a41e:	00 
    a41f:	75 38                	jne    a459 <TEST_is_permutation_____3+0x1f06>
    a421:	48 8b 05 d8 6c 00 00 	mov    rax,QWORD PTR [rip+0x6cd8]        # 11100 <stderr@GLIBC_2.2.5>
    a428:	4c 8d 05 41 3f 00 00 	lea    r8,[rip+0x3f41]        # e370 <__func__.1>
    a42f:	b9 68 00 00 00       	mov    ecx,0x68
    a434:	48 8d 15 09 3c 00 00 	lea    rdx,[rip+0x3c09]        # e044 <_IO_stdin_used+0x44>
    a43b:	48 8d 35 0e 3c 00 00 	lea    rsi,[rip+0x3c0e]        # e050 <_IO_stdin_used+0x50>
    a442:	48 89 c7             	mov    rdi,rax
    a445:	b8 00 00 00 00       	mov    eax,0x0
    a44a:	e8 11 80 ff ff       	call   2460 <fprintf@plt>
    a44f:	bf 00 00 00 00       	mov    edi,0x0
    a454:	e8 c7 80 ff ff       	call   2520 <exit@plt>
    a459:	8b 05 41 6c 00 00    	mov    eax,DWORD PTR [rip+0x6c41]        # 110a0 <k_DEFAULT@@Base>
    a45f:	48 98                	cdqe   
    a461:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    a468:	00 
    a469:	48 8d 05 50 6c 00 00 	lea    rax,[rip+0x6c50]        # 110c0 <colors_f@@Base>
    a470:	48 8b 34 02          	mov    rsi,QWORD PTR [rdx+rax*1]
    a474:	8b 05 06 6c 00 00    	mov    eax,DWORD PTR [rip+0x6c06]        # 11080 <hk_TR@@Base>
    a47a:	48 98                	cdqe   
    a47c:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    a483:	00 
    a484:	48 8d 05 b5 6b 00 00 	lea    rax,[rip+0x6bb5]        # 11040 <tab_hk_f@@Base>
    a48b:	48 8b 0c 02          	mov    rcx,QWORD PTR [rdx+rax*1]
    a48f:	8b 05 ef 6b 00 00    	mov    eax,DWORD PTR [rip+0x6bef]        # 11084 <k_RED@@Base>
    a495:	48 98                	cdqe   
    a497:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    a49e:	00 
    a49f:	48 8d 05 1a 6c 00 00 	lea    rax,[rip+0x6c1a]        # 110c0 <colors_f@@Base>
    a4a6:	48 8b 14 02          	mov    rdx,QWORD PTR [rdx+rax*1]
    a4aa:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    a4b1:	48 83 ec 08          	sub    rsp,0x8
    a4b5:	ff b5 50 ff ff ff    	push   QWORD PTR [rbp-0xb0]
    a4bb:	4c 8d 0d ae 3e 00 00 	lea    r9,[rip+0x3eae]        # e370 <__func__.1>
    a4c2:	49 89 f0             	mov    r8,rsi
    a4c5:	48 8d 35 a4 3d 00 00 	lea    rsi,[rip+0x3da4]        # e270 <_IO_stdin_used+0x270>
    a4cc:	48 89 c7             	mov    rdi,rax
    a4cf:	b8 00 00 00 00       	mov    eax,0x0
    a4d4:	e8 87 7f ff ff       	call   2460 <fprintf@plt>
    a4d9:	48 83 c4 10          	add    rsp,0x10
    a4dd:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    a4e4:	48 89 c7             	mov    rdi,rax
    a4e7:	e8 a4 7f ff ff       	call   2490 <fflush@plt>
    a4ec:	0f b6 05 9d 6b 00 00 	movzx  eax,BYTE PTR [rip+0x6b9d]        # 11090 <is_parallel_nb@@Base>
    a4f3:	84 c0                	test   al,al
    a4f5:	0f 84 ec 00 00 00    	je     a5e7 <TEST_is_permutation_____3+0x2094>
    a4fb:	e8 50 7f ff ff       	call   2450 <id_of_thread_executed@plt>
    a500:	48 89 45 80          	mov    QWORD PTR [rbp-0x80],rax
    a504:	0f b6 05 15 6b 00 00 	movzx  eax,BYTE PTR [rip+0x6b15]        # 11020 <log_parallel@@Base>
    a50b:	84 c0                	test   al,al
    a50d:	74 6d                	je     a57c <TEST_is_permutation_____3+0x2029>
    a50f:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a516:	48 8b 15 0b 6b 00 00 	mov    rdx,QWORD PTR [rip+0x6b0b]        # 11028 <stdout@GLIBC_2.2.5>
    a51d:	48 89 d6             	mov    rsi,rdx
    a520:	48 89 c7             	mov    rdi,rax
    a523:	e8 b8 7e ff ff       	call   23e0 <fputs@plt>
    a528:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    a52d:	0f 88 21 01 00 00    	js     a654 <TEST_is_permutation_____3+0x2101>
    a533:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a53a:	48 8b 0d ef 6a 00 00 	mov    rcx,QWORD PTR [rip+0x6aef]        # 11030 <f_ou_th@@Base>
    a541:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    a545:	48 c1 e2 03          	shl    rdx,0x3
    a549:	48 01 ca             	add    rdx,rcx
    a54c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a54f:	48 89 d6             	mov    rsi,rdx
    a552:	48 89 c7             	mov    rdi,rax
    a555:	e8 86 7e ff ff       	call   23e0 <fputs@plt>
    a55a:	48 8b 15 cf 6a 00 00 	mov    rdx,QWORD PTR [rip+0x6acf]        # 11030 <f_ou_th@@Base>
    a561:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    a565:	48 c1 e0 03          	shl    rax,0x3
    a569:	48 01 d0             	add    rax,rdx
    a56c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a56f:	48 89 c7             	mov    rdi,rax
    a572:	e8 19 7f ff ff       	call   2490 <fflush@plt>
    a577:	e9 d8 00 00 00       	jmp    a654 <TEST_is_permutation_____3+0x2101>
    a57c:	48 83 7d 80 00       	cmp    QWORD PTR [rbp-0x80],0x0
    a581:	78 49                	js     a5cc <TEST_is_permutation_____3+0x2079>
    a583:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a58a:	48 8b 0d 9f 6a 00 00 	mov    rcx,QWORD PTR [rip+0x6a9f]        # 11030 <f_ou_th@@Base>
    a591:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
    a595:	48 c1 e2 03          	shl    rdx,0x3
    a599:	48 01 ca             	add    rdx,rcx
    a59c:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a59f:	48 89 d6             	mov    rsi,rdx
    a5a2:	48 89 c7             	mov    rdi,rax
    a5a5:	e8 36 7e ff ff       	call   23e0 <fputs@plt>
    a5aa:	48 8b 15 7f 6a 00 00 	mov    rdx,QWORD PTR [rip+0x6a7f]        # 11030 <f_ou_th@@Base>
    a5b1:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    a5b5:	48 c1 e0 03          	shl    rax,0x3
    a5b9:	48 01 d0             	add    rax,rdx
    a5bc:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a5bf:	48 89 c7             	mov    rdi,rax
    a5c2:	e8 c9 7e ff ff       	call   2490 <fflush@plt>
    a5c7:	e9 88 00 00 00       	jmp    a654 <TEST_is_permutation_____3+0x2101>
    a5cc:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a5d3:	48 8b 15 4e 6a 00 00 	mov    rdx,QWORD PTR [rip+0x6a4e]        # 11028 <stdout@GLIBC_2.2.5>
    a5da:	48 89 d6             	mov    rsi,rdx
    a5dd:	48 89 c7             	mov    rdi,rax
    a5e0:	e8 fb 7d ff ff       	call   23e0 <fputs@plt>
    a5e5:	eb 6d                	jmp    a654 <TEST_is_permutation_____3+0x2101>
    a5e7:	48 8b 05 4a 6a 00 00 	mov    rax,QWORD PTR [rip+0x6a4a]        # 11038 <savelog@@Base>
    a5ee:	48 85 c0             	test   rax,rax
    a5f1:	74 48                	je     a63b <TEST_is_permutation_____3+0x20e8>
    a5f3:	48 8b 05 3e 6a 00 00 	mov    rax,QWORD PTR [rip+0x6a3e]        # 11038 <savelog@@Base>
    a5fa:	48 8d 15 7e 3a 00 00 	lea    rdx,[rip+0x3a7e]        # e07f <_IO_stdin_used+0x7f>
    a601:	48 89 d6             	mov    rsi,rdx
    a604:	48 89 c7             	mov    rdi,rax
    a607:	e8 f4 7e ff ff       	call   2500 <fopen@plt>
    a60c:	48 89 85 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rax
    a613:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a61a:	48 8b 95 78 ff ff ff 	mov    rdx,QWORD PTR [rbp-0x88]
    a621:	48 89 d6             	mov    rsi,rdx
    a624:	48 89 c7             	mov    rdi,rax
    a627:	e8 b4 7d ff ff       	call   23e0 <fputs@plt>
    a62c:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    a633:	48 89 c7             	mov    rdi,rax
    a636:	e8 75 7d ff ff       	call   23b0 <fclose@plt>
    a63b:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a642:	48 8b 15 df 69 00 00 	mov    rdx,QWORD PTR [rip+0x69df]        # 11028 <stdout@GLIBC_2.2.5>
    a649:	48 89 d6             	mov    rsi,rdx
    a64c:	48 89 c7             	mov    rdi,rax
    a64f:	e8 8c 7d ff ff       	call   23e0 <fputs@plt>
    a654:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    a65b:	48 89 c7             	mov    rdi,rax
    a65e:	e8 4d 7d ff ff       	call   23b0 <fclose@plt>
    a663:	48 8b 85 98 fe ff ff 	mov    rax,QWORD PTR [rbp-0x168]
    a66a:	48 89 c7             	mov    rdi,rax
    a66d:	e8 be 7c ff ff       	call   2330 <free@plt>
    a672:	90                   	nop
    a673:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    a677:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
    a67e:	00 00 
    a680:	74 05                	je     a687 <TEST_is_permutation_____3+0x2134>
    a682:	e8 39 7d ff ff       	call   23c0 <__stack_chk_fail@plt>
    a687:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    a68b:	c9                   	leave  
    a68c:	c3                   	ret    

000000000000a68d <append_test_4>:
    a68d:	f3 0f 1e fa          	endbr64 
    a691:	55                   	push   rbp
    a692:	48 89 e5             	mov    rbp,rsp
    a695:	48 8d 05 27 3c 00 00 	lea    rax,[rip+0x3c27]        # e2c3 <_IO_stdin_used+0x2c3>
    a69c:	48 89 c6             	mov    rsi,rax
    a69f:	48 8d 05 0a 00 00 00 	lea    rax,[rip+0xa]        # a6b0 <TEST_____4>
    a6a6:	48 89 c7             	mov    rdi,rax
    a6a9:	e8 92 7c ff ff       	call   2340 <append_func@plt>
    a6ae:	5d                   	pop    rbp
    a6af:	c3                   	ret    

000000000000a6b0 <TEST_____4>:
    a6b0:	f3 0f 1e fa          	endbr64 
    a6b4:	55                   	push   rbp
    a6b5:	48 89 e5             	mov    rbp,rsp
    a6b8:	48 83 ec 60          	sub    rsp,0x60
    a6bc:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    a6c3:	00 00 
    a6c5:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    a6c9:	31 c0                	xor    eax,eax
    a6cb:	bf 06 00 00 00       	mov    edi,0x6
    a6d0:	e8 9b 09 00 00       	call   b070 <CREATE_PERMUTATION_TYPE_CHAR>
    a6d5:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
    a6d9:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a6dd:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a6e1:	c6 00 42             	mov    BYTE PTR [rax],0x42
    a6e4:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a6e8:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a6ec:	48 83 c0 01          	add    rax,0x1
    a6f0:	c6 00 41             	mov    BYTE PTR [rax],0x41
    a6f3:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a6f7:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a6fb:	48 83 c0 02          	add    rax,0x2
    a6ff:	c6 00 59             	mov    BYTE PTR [rax],0x59
    a702:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a706:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a70a:	48 83 c0 03          	add    rax,0x3
    a70e:	c6 00 43             	mov    BYTE PTR [rax],0x43
    a711:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a715:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a719:	48 83 c0 04          	add    rax,0x4
    a71d:	c6 00 42             	mov    BYTE PTR [rax],0x42
    a720:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a724:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
    a728:	48 83 c0 05          	add    rax,0x5
    a72c:	c6 00 5a             	mov    BYTE PTR [rax],0x5a
    a72f:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a733:	48 89 c7             	mov    rdi,rax
    a736:	e8 89 09 00 00       	call   b0c4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR>
    a73b:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
    a73f:	c7 45 a4 00 00 00 00 	mov    DWORD PTR [rbp-0x5c],0x0
    a746:	e9 fa 01 00 00       	jmp    a945 <TEST_____4+0x295>
    a74b:	48 8d 55 a8          	lea    rdx,[rbp-0x58]
    a74f:	48 8d 45 b0          	lea    rax,[rbp-0x50]
    a753:	48 89 d6             	mov    rsi,rdx
    a756:	48 89 c7             	mov    rdi,rax
    a759:	e8 f2 7b ff ff       	call   2350 <open_memstream@plt>
    a75e:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    a762:	48 83 7d e0 00       	cmp    QWORD PTR [rbp-0x20],0x0
    a767:	75 38                	jne    a7a1 <TEST_____4+0xf1>
    a769:	48 8b 05 90 69 00 00 	mov    rax,QWORD PTR [rip+0x6990]        # 11100 <stderr@GLIBC_2.2.5>
    a770:	4c 8d 05 19 3c 00 00 	lea    r8,[rip+0x3c19]        # e390 <__func__.0>
    a777:	b9 7f 00 00 00       	mov    ecx,0x7f
    a77c:	48 8d 15 c1 38 00 00 	lea    rdx,[rip+0x38c1]        # e044 <_IO_stdin_used+0x44>
    a783:	48 8d 35 c6 38 00 00 	lea    rsi,[rip+0x38c6]        # e050 <_IO_stdin_used+0x50>
    a78a:	48 89 c7             	mov    rdi,rax
    a78d:	b8 00 00 00 00       	mov    eax,0x0
    a792:	e8 c9 7c ff ff       	call   2460 <fprintf@plt>
    a797:	bf 00 00 00 00       	mov    edi,0x0
    a79c:	e8 7f 7d ff ff       	call   2520 <exit@plt>
    a7a1:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
    a7a5:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    a7a9:	8b 45 a4             	mov    eax,DWORD PTR [rbp-0x5c]
    a7ac:	48 98                	cdqe   
    a7ae:	48 c1 e0 03          	shl    rax,0x3
    a7b2:	48 01 d0             	add    rax,rdx
    a7b5:	48 8b 08             	mov    rcx,QWORD PTR [rax]
    a7b8:	8b 55 a4             	mov    edx,DWORD PTR [rbp-0x5c]
    a7bb:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    a7bf:	48 8d 35 11 3b 00 00 	lea    rsi,[rip+0x3b11]        # e2d7 <_IO_stdin_used+0x2d7>
    a7c6:	48 89 c7             	mov    rdi,rax
    a7c9:	b8 00 00 00 00       	mov    eax,0x0
    a7ce:	e8 8d 7c ff ff       	call   2460 <fprintf@plt>
    a7d3:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    a7d7:	48 89 c7             	mov    rdi,rax
    a7da:	e8 b1 7c ff ff       	call   2490 <fflush@plt>
    a7df:	0f b6 05 aa 68 00 00 	movzx  eax,BYTE PTR [rip+0x68aa]        # 11090 <is_parallel_nb@@Base>
    a7e6:	84 c0                	test   al,al
    a7e8:	0f 84 dd 00 00 00    	je     a8cb <TEST_____4+0x21b>
    a7ee:	e8 5d 7c ff ff       	call   2450 <id_of_thread_executed@plt>
    a7f3:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    a7f7:	0f b6 05 22 68 00 00 	movzx  eax,BYTE PTR [rip+0x6822]        # 11020 <log_parallel@@Base>
    a7fe:	84 c0                	test   al,al
    a800:	74 67                	je     a869 <TEST_____4+0x1b9>
    a802:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a806:	48 8b 15 1b 68 00 00 	mov    rdx,QWORD PTR [rip+0x681b]        # 11028 <stdout@GLIBC_2.2.5>
    a80d:	48 89 d6             	mov    rsi,rdx
    a810:	48 89 c7             	mov    rdi,rax
    a813:	e8 c8 7b ff ff       	call   23e0 <fputs@plt>
    a818:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    a81d:	0f 88 06 01 00 00    	js     a929 <TEST_____4+0x279>
    a823:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a827:	48 8b 0d 02 68 00 00 	mov    rcx,QWORD PTR [rip+0x6802]        # 11030 <f_ou_th@@Base>
    a82e:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    a832:	48 c1 e2 03          	shl    rdx,0x3
    a836:	48 01 ca             	add    rdx,rcx
    a839:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a83c:	48 89 d6             	mov    rsi,rdx
    a83f:	48 89 c7             	mov    rdi,rax
    a842:	e8 99 7b ff ff       	call   23e0 <fputs@plt>
    a847:	48 8b 15 e2 67 00 00 	mov    rdx,QWORD PTR [rip+0x67e2]        # 11030 <f_ou_th@@Base>
    a84e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    a852:	48 c1 e0 03          	shl    rax,0x3
    a856:	48 01 d0             	add    rax,rdx
    a859:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a85c:	48 89 c7             	mov    rdi,rax
    a85f:	e8 2c 7c ff ff       	call   2490 <fflush@plt>
    a864:	e9 c0 00 00 00       	jmp    a929 <TEST_____4+0x279>
    a869:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    a86e:	78 43                	js     a8b3 <TEST_____4+0x203>
    a870:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a874:	48 8b 0d b5 67 00 00 	mov    rcx,QWORD PTR [rip+0x67b5]        # 11030 <f_ou_th@@Base>
    a87b:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    a87f:	48 c1 e2 03          	shl    rdx,0x3
    a883:	48 01 ca             	add    rdx,rcx
    a886:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    a889:	48 89 d6             	mov    rsi,rdx
    a88c:	48 89 c7             	mov    rdi,rax
    a88f:	e8 4c 7b ff ff       	call   23e0 <fputs@plt>
    a894:	48 8b 15 95 67 00 00 	mov    rdx,QWORD PTR [rip+0x6795]        # 11030 <f_ou_th@@Base>
    a89b:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    a89f:	48 c1 e0 03          	shl    rax,0x3
    a8a3:	48 01 d0             	add    rax,rdx
    a8a6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a8a9:	48 89 c7             	mov    rdi,rax
    a8ac:	e8 df 7b ff ff       	call   2490 <fflush@plt>
    a8b1:	eb 76                	jmp    a929 <TEST_____4+0x279>
    a8b3:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a8b7:	48 8b 15 6a 67 00 00 	mov    rdx,QWORD PTR [rip+0x676a]        # 11028 <stdout@GLIBC_2.2.5>
    a8be:	48 89 d6             	mov    rsi,rdx
    a8c1:	48 89 c7             	mov    rdi,rax
    a8c4:	e8 17 7b ff ff       	call   23e0 <fputs@plt>
    a8c9:	eb 5e                	jmp    a929 <TEST_____4+0x279>
    a8cb:	48 8b 05 66 67 00 00 	mov    rax,QWORD PTR [rip+0x6766]        # 11038 <savelog@@Base>
    a8d2:	48 85 c0             	test   rax,rax
    a8d5:	74 3c                	je     a913 <TEST_____4+0x263>
    a8d7:	48 8b 05 5a 67 00 00 	mov    rax,QWORD PTR [rip+0x675a]        # 11038 <savelog@@Base>
    a8de:	48 8d 15 9a 37 00 00 	lea    rdx,[rip+0x379a]        # e07f <_IO_stdin_used+0x7f>
    a8e5:	48 89 d6             	mov    rsi,rdx
    a8e8:	48 89 c7             	mov    rdi,rax
    a8eb:	e8 10 7c ff ff       	call   2500 <fopen@plt>
    a8f0:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    a8f4:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a8f8:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    a8fc:	48 89 d6             	mov    rsi,rdx
    a8ff:	48 89 c7             	mov    rdi,rax
    a902:	e8 d9 7a ff ff       	call   23e0 <fputs@plt>
    a907:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    a90b:	48 89 c7             	mov    rdi,rax
    a90e:	e8 9d 7a ff ff       	call   23b0 <fclose@plt>
    a913:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a917:	48 8b 15 0a 67 00 00 	mov    rdx,QWORD PTR [rip+0x670a]        # 11028 <stdout@GLIBC_2.2.5>
    a91e:	48 89 d6             	mov    rsi,rdx
    a921:	48 89 c7             	mov    rdi,rax
    a924:	e8 b7 7a ff ff       	call   23e0 <fputs@plt>
    a929:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    a92d:	48 89 c7             	mov    rdi,rax
    a930:	e8 7b 7a ff ff       	call   23b0 <fclose@plt>
    a935:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    a939:	48 89 c7             	mov    rdi,rax
    a93c:	e8 ef 79 ff ff       	call   2330 <free@plt>
    a941:	83 45 a4 01          	add    DWORD PTR [rbp-0x5c],0x1
    a945:	8b 45 a4             	mov    eax,DWORD PTR [rbp-0x5c]
    a948:	48 63 d0             	movsxd rdx,eax
    a94b:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
    a94f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    a952:	48 39 c2             	cmp    rdx,rax
    a955:	0f 82 f0 fd ff ff    	jb     a74b <TEST_____4+0x9b>
    a95b:	48 8d 55 a8          	lea    rdx,[rbp-0x58]
    a95f:	48 8d 45 b0          	lea    rax,[rbp-0x50]
    a963:	48 89 d6             	mov    rsi,rdx
    a966:	48 89 c7             	mov    rdi,rax
    a969:	e8 e2 79 ff ff       	call   2350 <open_memstream@plt>
    a96e:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
    a972:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    a977:	75 38                	jne    a9b1 <TEST_____4+0x301>
    a979:	48 8b 05 80 67 00 00 	mov    rax,QWORD PTR [rip+0x6780]        # 11100 <stderr@GLIBC_2.2.5>
    a980:	4c 8d 05 09 3a 00 00 	lea    r8,[rip+0x3a09]        # e390 <__func__.0>
    a987:	b9 80 00 00 00       	mov    ecx,0x80
    a98c:	48 8d 15 b1 36 00 00 	lea    rdx,[rip+0x36b1]        # e044 <_IO_stdin_used+0x44>
    a993:	48 8d 35 b6 36 00 00 	lea    rsi,[rip+0x36b6]        # e050 <_IO_stdin_used+0x50>
    a99a:	48 89 c7             	mov    rdi,rax
    a99d:	b8 00 00 00 00       	mov    eax,0x0
    a9a2:	e8 b9 7a ff ff       	call   2460 <fprintf@plt>
    a9a7:	bf 00 00 00 00       	mov    edi,0x0
    a9ac:	e8 6f 7b ff ff       	call   2520 <exit@plt>
    a9b1:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
    a9b5:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    a9b9:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    a9bd:	48 8d 0d 1f 39 00 00 	lea    rcx,[rip+0x391f]        # e2e3 <_IO_stdin_used+0x2e3>
    a9c4:	48 89 ce             	mov    rsi,rcx
    a9c7:	48 89 c7             	mov    rdi,rax
    a9ca:	b8 00 00 00 00       	mov    eax,0x0
    a9cf:	e8 8c 7a ff ff       	call   2460 <fprintf@plt>
    a9d4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    a9d8:	48 89 c7             	mov    rdi,rax
    a9db:	e8 b0 7a ff ff       	call   2490 <fflush@plt>
    a9e0:	0f b6 05 a9 66 00 00 	movzx  eax,BYTE PTR [rip+0x66a9]        # 11090 <is_parallel_nb@@Base>
    a9e7:	84 c0                	test   al,al
    a9e9:	0f 84 dd 00 00 00    	je     aacc <TEST_____4+0x41c>
    a9ef:	e8 5c 7a ff ff       	call   2450 <id_of_thread_executed@plt>
    a9f4:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    a9f8:	0f b6 05 21 66 00 00 	movzx  eax,BYTE PTR [rip+0x6621]        # 11020 <log_parallel@@Base>
    a9ff:	84 c0                	test   al,al
    aa01:	74 67                	je     aa6a <TEST_____4+0x3ba>
    aa03:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    aa07:	48 8b 15 1a 66 00 00 	mov    rdx,QWORD PTR [rip+0x661a]        # 11028 <stdout@GLIBC_2.2.5>
    aa0e:	48 89 d6             	mov    rsi,rdx
    aa11:	48 89 c7             	mov    rdi,rax
    aa14:	e8 c7 79 ff ff       	call   23e0 <fputs@plt>
    aa19:	48 83 7d d8 00       	cmp    QWORD PTR [rbp-0x28],0x0
    aa1e:	0f 88 06 01 00 00    	js     ab2a <TEST_____4+0x47a>
    aa24:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    aa28:	48 8b 0d 01 66 00 00 	mov    rcx,QWORD PTR [rip+0x6601]        # 11030 <f_ou_th@@Base>
    aa2f:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    aa33:	48 c1 e2 03          	shl    rdx,0x3
    aa37:	48 01 ca             	add    rdx,rcx
    aa3a:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    aa3d:	48 89 d6             	mov    rsi,rdx
    aa40:	48 89 c7             	mov    rdi,rax
    aa43:	e8 98 79 ff ff       	call   23e0 <fputs@plt>
    aa48:	48 8b 15 e1 65 00 00 	mov    rdx,QWORD PTR [rip+0x65e1]        # 11030 <f_ou_th@@Base>
    aa4f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    aa53:	48 c1 e0 03          	shl    rax,0x3
    aa57:	48 01 d0             	add    rax,rdx
    aa5a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    aa5d:	48 89 c7             	mov    rdi,rax
    aa60:	e8 2b 7a ff ff       	call   2490 <fflush@plt>
    aa65:	e9 c0 00 00 00       	jmp    ab2a <TEST_____4+0x47a>
    aa6a:	48 83 7d d8 00       	cmp    QWORD PTR [rbp-0x28],0x0
    aa6f:	78 43                	js     aab4 <TEST_____4+0x404>
    aa71:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    aa75:	48 8b 0d b4 65 00 00 	mov    rcx,QWORD PTR [rip+0x65b4]        # 11030 <f_ou_th@@Base>
    aa7c:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    aa80:	48 c1 e2 03          	shl    rdx,0x3
    aa84:	48 01 ca             	add    rdx,rcx
    aa87:	48 8b 12             	mov    rdx,QWORD PTR [rdx]
    aa8a:	48 89 d6             	mov    rsi,rdx
    aa8d:	48 89 c7             	mov    rdi,rax
    aa90:	e8 4b 79 ff ff       	call   23e0 <fputs@plt>
    aa95:	48 8b 15 94 65 00 00 	mov    rdx,QWORD PTR [rip+0x6594]        # 11030 <f_ou_th@@Base>
    aa9c:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    aaa0:	48 c1 e0 03          	shl    rax,0x3
    aaa4:	48 01 d0             	add    rax,rdx
    aaa7:	48 8b 00             	mov    rax,QWORD PTR [rax]
    aaaa:	48 89 c7             	mov    rdi,rax
    aaad:	e8 de 79 ff ff       	call   2490 <fflush@plt>
    aab2:	eb 76                	jmp    ab2a <TEST_____4+0x47a>
    aab4:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    aab8:	48 8b 15 69 65 00 00 	mov    rdx,QWORD PTR [rip+0x6569]        # 11028 <stdout@GLIBC_2.2.5>
    aabf:	48 89 d6             	mov    rsi,rdx
    aac2:	48 89 c7             	mov    rdi,rax
    aac5:	e8 16 79 ff ff       	call   23e0 <fputs@plt>
    aaca:	eb 5e                	jmp    ab2a <TEST_____4+0x47a>
    aacc:	48 8b 05 65 65 00 00 	mov    rax,QWORD PTR [rip+0x6565]        # 11038 <savelog@@Base>
    aad3:	48 85 c0             	test   rax,rax
    aad6:	74 3c                	je     ab14 <TEST_____4+0x464>
    aad8:	48 8b 05 59 65 00 00 	mov    rax,QWORD PTR [rip+0x6559]        # 11038 <savelog@@Base>
    aadf:	48 8d 15 99 35 00 00 	lea    rdx,[rip+0x3599]        # e07f <_IO_stdin_used+0x7f>
    aae6:	48 89 d6             	mov    rsi,rdx
    aae9:	48 89 c7             	mov    rdi,rax
    aaec:	e8 0f 7a ff ff       	call   2500 <fopen@plt>
    aaf1:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
    aaf5:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    aaf9:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
    aafd:	48 89 d6             	mov    rsi,rdx
    ab00:	48 89 c7             	mov    rdi,rax
    ab03:	e8 d8 78 ff ff       	call   23e0 <fputs@plt>
    ab08:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    ab0c:	48 89 c7             	mov    rdi,rax
    ab0f:	e8 9c 78 ff ff       	call   23b0 <fclose@plt>
    ab14:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    ab18:	48 8b 15 09 65 00 00 	mov    rdx,QWORD PTR [rip+0x6509]        # 11028 <stdout@GLIBC_2.2.5>
    ab1f:	48 89 d6             	mov    rsi,rdx
    ab22:	48 89 c7             	mov    rdi,rax
    ab25:	e8 b6 78 ff ff       	call   23e0 <fputs@plt>
    ab2a:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    ab2e:	48 89 c7             	mov    rdi,rax
    ab31:	e8 7a 78 ff ff       	call   23b0 <fclose@plt>
    ab36:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    ab3a:	48 89 c7             	mov    rdi,rax
    ab3d:	e8 ee 77 ff ff       	call   2330 <free@plt>
    ab42:	90                   	nop
    ab43:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ab47:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
    ab4e:	00 00 
    ab50:	74 05                	je     ab57 <TEST_____4+0x4a7>
    ab52:	e8 69 78 ff ff       	call   23c0 <__stack_chk_fail@plt>
    ab57:	c9                   	leave  
    ab58:	c3                   	ret    

000000000000ab59 <main>:
    ab59:	f3 0f 1e fa          	endbr64 
    ab5d:	55                   	push   rbp
    ab5e:	48 89 e5             	mov    rbp,rsp
    ab61:	48 83 ec 10          	sub    rsp,0x10
    ab65:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
    ab68:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    ab6c:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    ab70:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    ab73:	48 89 d6             	mov    rsi,rdx
    ab76:	89 c7                	mov    edi,eax
    ab78:	e8 73 79 ff ff       	call   24f0 <run_all_tests_args@plt>
    ab7d:	b8 00 00 00 00       	mov    eax,0x0
    ab82:	c9                   	leave  
    ab83:	c3                   	ret    

000000000000ab84 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR>:
    ab84:	f3 0f 1e fa          	endbr64 
    ab88:	55                   	push   rbp
    ab89:	48 89 e5             	mov    rbp,rsp
    ab8c:	48 83 ec 40          	sub    rsp,0x40
    ab90:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    ab94:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    ab9b:	00 00 
    ab9d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    aba1:	31 c0                	xor    eax,eax
    aba3:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    aba8:	75 0a                	jne    abb4 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x30>
    abaa:	b8 00 00 00 00       	mov    eax,0x0
    abaf:	e9 ee 00 00 00       	jmp    aca2 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x11e>
    abb4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    abb8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    abbb:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    abbf:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    abc3:	be 08 00 00 00       	mov    esi,0x8
    abc8:	48 89 c7             	mov    rdi,rax
    abcb:	e8 70 78 ff ff       	call   2440 <calloc@plt>
    abd0:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    abd4:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    abd9:	75 19                	jne    abf4 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x70>
    abdb:	48 8d 05 d2 37 00 00 	lea    rax,[rip+0x37d2]        # e3b4 <__func__.0+0x24>
    abe2:	48 89 c7             	mov    rdi,rax
    abe5:	e8 76 77 ff ff       	call   2360 <puts@plt>
    abea:	b8 00 00 00 00       	mov    eax,0x0
    abef:	e9 ae 00 00 00       	jmp    aca2 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x11e>
    abf4:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    abfb:	00 
    abfc:	e9 82 00 00 00       	jmp    ac83 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0xff>
    ac01:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    ac05:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    ac09:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ac0d:	48 01 d0             	add    rax,rdx
    ac10:	0f b6 00             	movzx  eax,BYTE PTR [rax]
    ac13:	88 45 df             	mov    BYTE PTR [rbp-0x21],al
    ac16:	48 8d 55 e0          	lea    rdx,[rbp-0x20]
    ac1a:	48 8d 45 df          	lea    rax,[rbp-0x21]
    ac1e:	48 89 d6             	mov    rsi,rdx
    ac21:	48 89 c7             	mov    rdi,rax
    ac24:	e8 37 76 ff ff       	call   2260 <COMPARE_N_TYPE_U_CHAR@plt>
    ac29:	85 c0                	test   eax,eax
    ac2b:	79 1e                	jns    ac4b <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0xc7>
    ac2d:	0f b6 45 df          	movzx  eax,BYTE PTR [rbp-0x21]
    ac31:	0f b6 c0             	movzx  eax,al
    ac34:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    ac3b:	00 
    ac3c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ac40:	48 01 d0             	add    rax,rdx
    ac43:	48 8b 00             	mov    rax,QWORD PTR [rax]
    ac46:	48 85 c0             	test   rax,rax
    ac49:	74 13                	je     ac5e <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0xda>
    ac4b:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ac4f:	48 89 c7             	mov    rdi,rax
    ac52:	e8 d9 76 ff ff       	call   2330 <free@plt>
    ac57:	b8 00 00 00 00       	mov    eax,0x0
    ac5c:	eb 44                	jmp    aca2 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x11e>
    ac5e:	0f b6 45 df          	movzx  eax,BYTE PTR [rbp-0x21]
    ac62:	0f b6 c0             	movzx  eax,al
    ac65:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    ac6c:	00 
    ac6d:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ac71:	48 01 d0             	add    rax,rdx
    ac74:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    ac77:	48 83 c2 01          	add    rdx,0x1
    ac7b:	48 89 10             	mov    QWORD PTR [rax],rdx
    ac7e:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    ac83:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    ac87:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    ac8b:	0f 82 70 ff ff ff    	jb     ac01 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x7d>
    ac91:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ac95:	48 89 c7             	mov    rdi,rax
    ac98:	e8 93 76 ff ff       	call   2330 <free@plt>
    ac9d:	b8 01 00 00 00       	mov    eax,0x1
    aca2:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    aca6:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
    acad:	00 00 
    acaf:	74 05                	je     acb6 <IS_PERMUTATION_SET_THEORIC_TYPE_U_CHAR+0x132>
    acb1:	e8 0a 77 ff ff       	call   23c0 <__stack_chk_fail@plt>
    acb6:	c9                   	leave  
    acb7:	c3                   	ret    

000000000000acb8 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT>:
    acb8:	f3 0f 1e fa          	endbr64 
    acbc:	55                   	push   rbp
    acbd:	48 89 e5             	mov    rbp,rsp
    acc0:	48 83 ec 40          	sub    rsp,0x40
    acc4:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    acc8:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    accf:	00 00 
    acd1:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    acd5:	31 c0                	xor    eax,eax
    acd7:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    acdc:	75 0a                	jne    ace8 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x30>
    acde:	b8 00 00 00 00       	mov    eax,0x0
    ace3:	e9 ed 00 00 00       	jmp    add5 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x11d>
    ace8:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    acec:	48 8b 00             	mov    rax,QWORD PTR [rax]
    acef:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    acf3:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    acf7:	be 08 00 00 00       	mov    esi,0x8
    acfc:	48 89 c7             	mov    rdi,rax
    acff:	e8 3c 77 ff ff       	call   2440 <calloc@plt>
    ad04:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    ad08:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    ad0d:	75 19                	jne    ad28 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x70>
    ad0f:	48 8d 05 9e 36 00 00 	lea    rax,[rip+0x369e]        # e3b4 <__func__.0+0x24>
    ad16:	48 89 c7             	mov    rdi,rax
    ad19:	e8 42 76 ff ff       	call   2360 <puts@plt>
    ad1e:	b8 00 00 00 00       	mov    eax,0x0
    ad23:	e9 ad 00 00 00       	jmp    add5 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x11d>
    ad28:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    ad2f:	00 
    ad30:	e9 81 00 00 00       	jmp    adb6 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0xfe>
    ad35:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    ad39:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    ad3d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ad41:	48 c1 e0 02          	shl    rax,0x2
    ad45:	48 01 d0             	add    rax,rdx
    ad48:	8b 00                	mov    eax,DWORD PTR [rax]
    ad4a:	89 45 dc             	mov    DWORD PTR [rbp-0x24],eax
    ad4d:	48 8d 55 e0          	lea    rdx,[rbp-0x20]
    ad51:	48 8d 45 dc          	lea    rax,[rbp-0x24]
    ad55:	48 89 d6             	mov    rsi,rdx
    ad58:	48 89 c7             	mov    rdi,rax
    ad5b:	e8 60 75 ff ff       	call   22c0 <COMPARE_N_TYPE_U_INT@plt>
    ad60:	85 c0                	test   eax,eax
    ad62:	79 1c                	jns    ad80 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0xc8>
    ad64:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
    ad67:	89 c0                	mov    eax,eax
    ad69:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    ad70:	00 
    ad71:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ad75:	48 01 d0             	add    rax,rdx
    ad78:	48 8b 00             	mov    rax,QWORD PTR [rax]
    ad7b:	48 85 c0             	test   rax,rax
    ad7e:	74 13                	je     ad93 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0xdb>
    ad80:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ad84:	48 89 c7             	mov    rdi,rax
    ad87:	e8 a4 75 ff ff       	call   2330 <free@plt>
    ad8c:	b8 00 00 00 00       	mov    eax,0x0
    ad91:	eb 42                	jmp    add5 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x11d>
    ad93:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
    ad96:	89 c0                	mov    eax,eax
    ad98:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    ad9f:	00 
    ada0:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    ada4:	48 01 d0             	add    rax,rdx
    ada7:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    adaa:	48 83 c2 01          	add    rdx,0x1
    adae:	48 89 10             	mov    QWORD PTR [rax],rdx
    adb1:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    adb6:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    adba:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    adbe:	0f 82 71 ff ff ff    	jb     ad35 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x7d>
    adc4:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    adc8:	48 89 c7             	mov    rdi,rax
    adcb:	e8 60 75 ff ff       	call   2330 <free@plt>
    add0:	b8 01 00 00 00       	mov    eax,0x1
    add5:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    add9:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
    ade0:	00 00 
    ade2:	74 05                	je     ade9 <IS_PERMUTATION_SET_THEORIC_TYPE_U_INT+0x131>
    ade4:	e8 d7 75 ff ff       	call   23c0 <__stack_chk_fail@plt>
    ade9:	c9                   	leave  
    adea:	c3                   	ret    

000000000000adeb <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT>:
    adeb:	f3 0f 1e fa          	endbr64 
    adef:	55                   	push   rbp
    adf0:	48 89 e5             	mov    rbp,rsp
    adf3:	48 83 ec 40          	sub    rsp,0x40
    adf7:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    adfb:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    ae02:	00 00 
    ae04:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ae08:	31 c0                	xor    eax,eax
    ae0a:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    ae0f:	75 0a                	jne    ae1b <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x30>
    ae11:	b8 00 00 00 00       	mov    eax,0x0
    ae16:	e9 ed 00 00 00       	jmp    af08 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x11d>
    ae1b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    ae1f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    ae22:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    ae26:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    ae2a:	be 08 00 00 00       	mov    esi,0x8
    ae2f:	48 89 c7             	mov    rdi,rax
    ae32:	e8 09 76 ff ff       	call   2440 <calloc@plt>
    ae37:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    ae3b:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    ae40:	75 19                	jne    ae5b <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x70>
    ae42:	48 8d 05 6b 35 00 00 	lea    rax,[rip+0x356b]        # e3b4 <__func__.0+0x24>
    ae49:	48 89 c7             	mov    rdi,rax
    ae4c:	e8 0f 75 ff ff       	call   2360 <puts@plt>
    ae51:	b8 00 00 00 00       	mov    eax,0x0
    ae56:	e9 ad 00 00 00       	jmp    af08 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x11d>
    ae5b:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    ae62:	00 
    ae63:	e9 81 00 00 00       	jmp    aee9 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0xfe>
    ae68:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    ae6c:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    ae70:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ae74:	48 c1 e0 03          	shl    rax,0x3
    ae78:	48 01 d0             	add    rax,rdx
    ae7b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    ae7e:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    ae82:	48 8d 55 d8          	lea    rdx,[rbp-0x28]
    ae86:	48 8d 45 e0          	lea    rax,[rbp-0x20]
    ae8a:	48 89 d6             	mov    rsi,rdx
    ae8d:	48 89 c7             	mov    rdi,rax
    ae90:	e8 4b 74 ff ff       	call   22e0 <COMPARE_N_TYPE_U_L_INT@plt>
    ae95:	85 c0                	test   eax,eax
    ae97:	79 1b                	jns    aeb4 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0xc9>
    ae99:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    ae9d:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    aea4:	00 
    aea5:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    aea9:	48 01 d0             	add    rax,rdx
    aeac:	48 8b 00             	mov    rax,QWORD PTR [rax]
    aeaf:	48 85 c0             	test   rax,rax
    aeb2:	74 13                	je     aec7 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0xdc>
    aeb4:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    aeb8:	48 89 c7             	mov    rdi,rax
    aebb:	e8 70 74 ff ff       	call   2330 <free@plt>
    aec0:	b8 00 00 00 00       	mov    eax,0x0
    aec5:	eb 41                	jmp    af08 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x11d>
    aec7:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    aecb:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    aed2:	00 
    aed3:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    aed7:	48 01 d0             	add    rax,rdx
    aeda:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    aedd:	48 83 c2 01          	add    rdx,0x1
    aee1:	48 89 10             	mov    QWORD PTR [rax],rdx
    aee4:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    aee9:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    aeed:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    aef1:	0f 82 71 ff ff ff    	jb     ae68 <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x7d>
    aef7:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    aefb:	48 89 c7             	mov    rdi,rax
    aefe:	e8 2d 74 ff ff       	call   2330 <free@plt>
    af03:	b8 01 00 00 00       	mov    eax,0x1
    af08:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    af0c:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
    af13:	00 00 
    af15:	74 05                	je     af1c <IS_PERMUTATION_SET_THEORIC_TYPE_U_L_INT+0x131>
    af17:	e8 a4 74 ff ff       	call   23c0 <__stack_chk_fail@plt>
    af1c:	c9                   	leave  
    af1d:	c3                   	ret    

000000000000af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>:
    af1e:	f3 0f 1e fa          	endbr64 
    af22:	55                   	push   rbp
    af23:	48 89 e5             	mov    rbp,rsp
    af26:	48 83 ec 40          	sub    rsp,0x40
    af2a:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    af2e:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    af35:	00 00 
    af37:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    af3b:	31 c0                	xor    eax,eax
    af3d:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    af42:	75 0a                	jne    af4e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x30>
    af44:	b8 00 00 00 00       	mov    eax,0x0
    af49:	e9 ed 00 00 00       	jmp    b03b <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x11d>
    af4e:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    af52:	48 8b 00             	mov    rax,QWORD PTR [rax]
    af55:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
    af59:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    af5d:	be 08 00 00 00       	mov    esi,0x8
    af62:	48 89 c7             	mov    rdi,rax
    af65:	e8 d6 74 ff ff       	call   2440 <calloc@plt>
    af6a:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    af6e:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
    af73:	75 19                	jne    af8e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x70>
    af75:	48 8d 05 38 34 00 00 	lea    rax,[rip+0x3438]        # e3b4 <__func__.0+0x24>
    af7c:	48 89 c7             	mov    rdi,rax
    af7f:	e8 dc 73 ff ff       	call   2360 <puts@plt>
    af84:	b8 00 00 00 00       	mov    eax,0x0
    af89:	e9 ad 00 00 00       	jmp    b03b <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x11d>
    af8e:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    af95:	00 
    af96:	e9 81 00 00 00       	jmp    b01c <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0xfe>
    af9b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    af9f:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    afa3:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    afa7:	48 c1 e0 03          	shl    rax,0x3
    afab:	48 01 d0             	add    rax,rdx
    afae:	48 8b 00             	mov    rax,QWORD PTR [rax]
    afb1:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
    afb5:	48 8d 55 d8          	lea    rdx,[rbp-0x28]
    afb9:	48 8d 45 e0          	lea    rax,[rbp-0x20]
    afbd:	48 89 d6             	mov    rsi,rdx
    afc0:	48 89 c7             	mov    rdi,rax
    afc3:	e8 c8 72 ff ff       	call   2290 <COMPARE_N_TYPE_SIZE_T@plt>
    afc8:	85 c0                	test   eax,eax
    afca:	79 1b                	jns    afe7 <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0xc9>
    afcc:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    afd0:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    afd7:	00 
    afd8:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    afdc:	48 01 d0             	add    rax,rdx
    afdf:	48 8b 00             	mov    rax,QWORD PTR [rax]
    afe2:	48 85 c0             	test   rax,rax
    afe5:	74 13                	je     affa <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0xdc>
    afe7:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    afeb:	48 89 c7             	mov    rdi,rax
    afee:	e8 3d 73 ff ff       	call   2330 <free@plt>
    aff3:	b8 00 00 00 00       	mov    eax,0x0
    aff8:	eb 41                	jmp    b03b <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x11d>
    affa:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    affe:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    b005:	00 
    b006:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b00a:	48 01 d0             	add    rax,rdx
    b00d:	48 8b 10             	mov    rdx,QWORD PTR [rax]
    b010:	48 83 c2 01          	add    rdx,0x1
    b014:	48 89 10             	mov    QWORD PTR [rax],rdx
    b017:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    b01c:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b020:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    b024:	0f 82 71 ff ff ff    	jb     af9b <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x7d>
    b02a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b02e:	48 89 c7             	mov    rdi,rax
    b031:	e8 fa 72 ff ff       	call   2330 <free@plt>
    b036:	b8 01 00 00 00       	mov    eax,0x1
    b03b:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    b03f:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
    b046:	00 00 
    b048:	74 05                	je     b04f <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T+0x131>
    b04a:	e8 71 73 ff ff       	call   23c0 <__stack_chk_fail@plt>
    b04f:	c9                   	leave  
    b050:	c3                   	ret    

000000000000b051 <sign>:
    b051:	f3 0f 1e fa          	endbr64 
    b055:	55                   	push   rbp
    b056:	48 89 e5             	mov    rbp,rsp
    b059:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
    b05c:	83 7d fc 00          	cmp    DWORD PTR [rbp-0x4],0x0
    b060:	79 07                	jns    b069 <sign+0x18>
    b062:	b8 ff ff ff ff       	mov    eax,0xffffffff
    b067:	eb 05                	jmp    b06e <sign+0x1d>
    b069:	b8 01 00 00 00       	mov    eax,0x1
    b06e:	5d                   	pop    rbp
    b06f:	c3                   	ret    

000000000000b070 <CREATE_PERMUTATION_TYPE_CHAR>:
    b070:	f3 0f 1e fa          	endbr64 
    b074:	55                   	push   rbp
    b075:	48 89 e5             	mov    rbp,rsp
    b078:	48 83 ec 20          	sub    rsp,0x20
    b07c:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b080:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b085:	75 07                	jne    b08e <CREATE_PERMUTATION_TYPE_CHAR+0x1e>
    b087:	b8 00 00 00 00       	mov    eax,0x0
    b08c:	eb 34                	jmp    b0c2 <CREATE_PERMUTATION_TYPE_CHAR+0x52>
    b08e:	bf 18 00 00 00       	mov    edi,0x18
    b093:	e8 e8 73 ff ff       	call   2480 <malloc@plt>
    b098:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b09c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b0a0:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    b0a4:	48 89 10             	mov    QWORD PTR [rax],rdx
    b0a7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b0ab:	48 89 c7             	mov    rdi,rax
    b0ae:	e8 cd 73 ff ff       	call   2480 <malloc@plt>
    b0b3:	48 89 c2             	mov    rdx,rax
    b0b6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b0ba:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b0be:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b0c2:	c9                   	leave  
    b0c3:	c3                   	ret    

000000000000b0c4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR>:
    b0c4:	f3 0f 1e fa          	endbr64 
    b0c8:	55                   	push   rbp
    b0c9:	48 89 e5             	mov    rbp,rsp
    b0cc:	48 83 ec 40          	sub    rsp,0x40
    b0d0:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    b0d4:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    b0d9:	75 0a                	jne    b0e5 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x21>
    b0db:	b8 00 00 00 00       	mov    eax,0x0
    b0e0:	e9 29 01 00 00       	jmp    b20e <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x14a>
    b0e5:	bf 18 00 00 00       	mov    edi,0x18
    b0ea:	e8 91 73 ff ff       	call   2480 <malloc@plt>
    b0ef:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    b0f3:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b0f7:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b0fa:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b0fe:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b102:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b106:	48 89 10             	mov    QWORD PTR [rax],rdx
    b109:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b10d:	48 c1 e0 03          	shl    rax,0x3
    b111:	48 89 c7             	mov    rdi,rax
    b114:	e8 67 73 ff ff       	call   2480 <malloc@plt>
    b119:	48 89 c2             	mov    rdx,rax
    b11c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b120:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b124:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b128:	48 89 c7             	mov    rdi,rax
    b12b:	e8 50 73 ff ff       	call   2480 <malloc@plt>
    b130:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b134:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b138:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b13c:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b140:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b144:	48 89 ce             	mov    rsi,rcx
    b147:	48 89 c7             	mov    rdi,rax
    b14a:	e8 81 72 ff ff       	call   23d0 <COPY_ARRAY_TYPE_CHAR@plt>
    b14f:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    b153:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b157:	48 8b 15 3a 5e 00 00 	mov    rdx,QWORD PTR [rip+0x5e3a]        # 10f98 <COMPARE_N_TYPE_CHAR@Base>
    b15e:	48 89 d1             	mov    rcx,rdx
    b161:	ba 01 00 00 00       	mov    edx,0x1
    b166:	48 89 c7             	mov    rdi,rax
    b169:	e8 22 72 ff ff       	call   2390 <qsort@plt>
    b16e:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    b175:	00 
    b176:	eb 05                	jmp    b17d <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0xb9>
    b178:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    b17d:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    b181:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b185:	72 f1                	jb     b178 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0xb4>
    b187:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    b18e:	00 
    b18f:	eb 63                	jmp    b1f4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x130>
    b191:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    b198:	00 
    b199:	eb 4a                	jmp    b1e5 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x121>
    b19b:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    b19f:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b1a3:	48 01 c2             	add    rdx,rax
    b1a6:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b1aa:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b1ae:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b1b2:	48 01 c8             	add    rax,rcx
    b1b5:	48 89 d6             	mov    rsi,rdx
    b1b8:	48 89 c7             	mov    rdi,rax
    b1bb:	e8 b0 70 ff ff       	call   2270 <COMPARE_N_TYPE_CHAR@plt>
    b1c0:	85 c0                	test   eax,eax
    b1c2:	75 1c                	jne    b1e0 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x11c>
    b1c4:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b1c8:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b1cc:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b1d0:	48 c1 e0 03          	shl    rax,0x3
    b1d4:	48 01 c2             	add    rdx,rax
    b1d7:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b1db:	48 89 02             	mov    QWORD PTR [rdx],rax
    b1de:	eb 0f                	jmp    b1ef <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0x12b>
    b1e0:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    b1e5:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b1e9:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b1ed:	72 ac                	jb     b19b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0xd7>
    b1ef:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    b1f4:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b1f8:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b1fc:	72 93                	jb     b191 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR+0xcd>
    b1fe:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b202:	48 89 c7             	mov    rdi,rax
    b205:	e8 26 71 ff ff       	call   2330 <free@plt>
    b20a:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b20e:	c9                   	leave  
    b20f:	c3                   	ret    

000000000000b210 <IS_PERMUTATION_TYPE_CHAR>:
    b210:	f3 0f 1e fa          	endbr64 
    b214:	55                   	push   rbp
    b215:	48 89 e5             	mov    rbp,rsp
    b218:	48 83 ec 20          	sub    rsp,0x20
    b21c:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b220:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b225:	75 07                	jne    b22e <IS_PERMUTATION_TYPE_CHAR+0x1e>
    b227:	b8 00 00 00 00       	mov    eax,0x0
    b22c:	eb 2f                	jmp    b25d <IS_PERMUTATION_TYPE_CHAR+0x4d>
    b22e:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b232:	48 89 c7             	mov    rdi,rax
    b235:	e8 8a fe ff ff       	call   b0c4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR>
    b23a:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b23e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b242:	48 89 c7             	mov    rdi,rax
    b245:	e8 d4 fc ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    b24a:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    b24d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b251:	48 89 c7             	mov    rdi,rax
    b254:	e8 d7 70 ff ff       	call   2330 <free@plt>
    b259:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    b25d:	c9                   	leave  
    b25e:	c3                   	ret    

000000000000b25f <signature_TYPE_CHAR>:
    b25f:	f3 0f 1e fa          	endbr64 
    b263:	55                   	push   rbp
    b264:	48 89 e5             	mov    rbp,rsp
    b267:	48 83 ec 30          	sub    rsp,0x30
    b26b:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    b26f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b273:	48 89 c7             	mov    rdi,rax
    b276:	e8 49 fe ff ff       	call   b0c4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR>
    b27b:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b27f:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    b286:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    b28d:	00 
    b28e:	eb 69                	jmp    b2f9 <signature_TYPE_CHAR+0x9a>
    b290:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b294:	48 83 c0 01          	add    rax,0x1
    b298:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b29c:	eb 49                	jmp    b2e7 <signature_TYPE_CHAR+0x88>
    b29e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b2a2:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b2a6:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b2aa:	48 c1 e0 03          	shl    rax,0x3
    b2ae:	48 01 d0             	add    rax,rdx
    b2b1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b2b4:	89 c1                	mov    ecx,eax
    b2b6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b2ba:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b2be:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b2c2:	48 c1 e0 03          	shl    rax,0x3
    b2c6:	48 01 d0             	add    rax,rdx
    b2c9:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b2cc:	89 c2                	mov    edx,eax
    b2ce:	89 c8                	mov    eax,ecx
    b2d0:	29 d0                	sub    eax,edx
    b2d2:	89 c7                	mov    edi,eax
    b2d4:	e8 78 fd ff ff       	call   b051 <sign>
    b2d9:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    b2dc:	0f af c2             	imul   eax,edx
    b2df:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    b2e2:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    b2e7:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b2eb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b2ee:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    b2f2:	72 aa                	jb     b29e <signature_TYPE_CHAR+0x3f>
    b2f4:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    b2f9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b2fd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b300:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    b304:	72 8a                	jb     b290 <signature_TYPE_CHAR+0x31>
    b306:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    b309:	c9                   	leave  
    b30a:	c3                   	ret    

000000000000b30b <CREATE_PERMUTATION_TYPE_U_CHAR>:
    b30b:	f3 0f 1e fa          	endbr64 
    b30f:	55                   	push   rbp
    b310:	48 89 e5             	mov    rbp,rsp
    b313:	48 83 ec 20          	sub    rsp,0x20
    b317:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b31b:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b320:	75 07                	jne    b329 <CREATE_PERMUTATION_TYPE_U_CHAR+0x1e>
    b322:	b8 00 00 00 00       	mov    eax,0x0
    b327:	eb 34                	jmp    b35d <CREATE_PERMUTATION_TYPE_U_CHAR+0x52>
    b329:	bf 18 00 00 00       	mov    edi,0x18
    b32e:	e8 4d 71 ff ff       	call   2480 <malloc@plt>
    b333:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b337:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b33b:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    b33f:	48 89 10             	mov    QWORD PTR [rax],rdx
    b342:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b346:	48 89 c7             	mov    rdi,rax
    b349:	e8 32 71 ff ff       	call   2480 <malloc@plt>
    b34e:	48 89 c2             	mov    rdx,rax
    b351:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b355:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b359:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b35d:	c9                   	leave  
    b35e:	c3                   	ret    

000000000000b35f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR>:
    b35f:	f3 0f 1e fa          	endbr64 
    b363:	55                   	push   rbp
    b364:	48 89 e5             	mov    rbp,rsp
    b367:	48 83 ec 40          	sub    rsp,0x40
    b36b:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    b36f:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    b374:	75 0a                	jne    b380 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x21>
    b376:	b8 00 00 00 00       	mov    eax,0x0
    b37b:	e9 29 01 00 00       	jmp    b4a9 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x14a>
    b380:	bf 18 00 00 00       	mov    edi,0x18
    b385:	e8 f6 70 ff ff       	call   2480 <malloc@plt>
    b38a:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    b38e:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b392:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b395:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b399:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b39d:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b3a1:	48 89 10             	mov    QWORD PTR [rax],rdx
    b3a4:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b3a8:	48 c1 e0 03          	shl    rax,0x3
    b3ac:	48 89 c7             	mov    rdi,rax
    b3af:	e8 cc 70 ff ff       	call   2480 <malloc@plt>
    b3b4:	48 89 c2             	mov    rdx,rax
    b3b7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b3bb:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b3bf:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b3c3:	48 89 c7             	mov    rdi,rax
    b3c6:	e8 b5 70 ff ff       	call   2480 <malloc@plt>
    b3cb:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b3cf:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b3d3:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b3d7:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b3db:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b3df:	48 89 ce             	mov    rsi,rcx
    b3e2:	48 89 c7             	mov    rdi,rax
    b3e5:	e8 56 71 ff ff       	call   2540 <COPY_ARRAY_TYPE_U_CHAR@plt>
    b3ea:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    b3ee:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b3f2:	48 8b 15 97 5b 00 00 	mov    rdx,QWORD PTR [rip+0x5b97]        # 10f90 <COMPARE_N_TYPE_U_CHAR@Base>
    b3f9:	48 89 d1             	mov    rcx,rdx
    b3fc:	ba 01 00 00 00       	mov    edx,0x1
    b401:	48 89 c7             	mov    rdi,rax
    b404:	e8 87 6f ff ff       	call   2390 <qsort@plt>
    b409:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    b410:	00 
    b411:	eb 05                	jmp    b418 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0xb9>
    b413:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    b418:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    b41c:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b420:	72 f1                	jb     b413 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0xb4>
    b422:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    b429:	00 
    b42a:	eb 63                	jmp    b48f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x130>
    b42c:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    b433:	00 
    b434:	eb 4a                	jmp    b480 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x121>
    b436:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
    b43a:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b43e:	48 01 c2             	add    rdx,rax
    b441:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b445:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b449:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b44d:	48 01 c8             	add    rax,rcx
    b450:	48 89 d6             	mov    rsi,rdx
    b453:	48 89 c7             	mov    rdi,rax
    b456:	e8 05 6e ff ff       	call   2260 <COMPARE_N_TYPE_U_CHAR@plt>
    b45b:	85 c0                	test   eax,eax
    b45d:	75 1c                	jne    b47b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x11c>
    b45f:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b463:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b467:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b46b:	48 c1 e0 03          	shl    rax,0x3
    b46f:	48 01 c2             	add    rdx,rax
    b472:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b476:	48 89 02             	mov    QWORD PTR [rdx],rax
    b479:	eb 0f                	jmp    b48a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0x12b>
    b47b:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    b480:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b484:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b488:	72 ac                	jb     b436 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0xd7>
    b48a:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    b48f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b493:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b497:	72 93                	jb     b42c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR+0xcd>
    b499:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b49d:	48 89 c7             	mov    rdi,rax
    b4a0:	e8 8b 6e ff ff       	call   2330 <free@plt>
    b4a5:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b4a9:	c9                   	leave  
    b4aa:	c3                   	ret    

000000000000b4ab <IS_PERMUTATION_TYPE_U_CHAR>:
    b4ab:	f3 0f 1e fa          	endbr64 
    b4af:	55                   	push   rbp
    b4b0:	48 89 e5             	mov    rbp,rsp
    b4b3:	48 83 ec 20          	sub    rsp,0x20
    b4b7:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b4bb:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b4c0:	75 07                	jne    b4c9 <IS_PERMUTATION_TYPE_U_CHAR+0x1e>
    b4c2:	b8 00 00 00 00       	mov    eax,0x0
    b4c7:	eb 2f                	jmp    b4f8 <IS_PERMUTATION_TYPE_U_CHAR+0x4d>
    b4c9:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b4cd:	48 89 c7             	mov    rdi,rax
    b4d0:	e8 8a fe ff ff       	call   b35f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR>
    b4d5:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b4d9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b4dd:	48 89 c7             	mov    rdi,rax
    b4e0:	e8 39 fa ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    b4e5:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    b4e8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b4ec:	48 89 c7             	mov    rdi,rax
    b4ef:	e8 3c 6e ff ff       	call   2330 <free@plt>
    b4f4:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    b4f8:	c9                   	leave  
    b4f9:	c3                   	ret    

000000000000b4fa <signature_TYPE_U_CHAR>:
    b4fa:	f3 0f 1e fa          	endbr64 
    b4fe:	55                   	push   rbp
    b4ff:	48 89 e5             	mov    rbp,rsp
    b502:	48 83 ec 30          	sub    rsp,0x30
    b506:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    b50a:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b50e:	48 89 c7             	mov    rdi,rax
    b511:	e8 49 fe ff ff       	call   b35f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_CHAR>
    b516:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b51a:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    b521:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    b528:	00 
    b529:	eb 69                	jmp    b594 <signature_TYPE_U_CHAR+0x9a>
    b52b:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b52f:	48 83 c0 01          	add    rax,0x1
    b533:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b537:	eb 49                	jmp    b582 <signature_TYPE_U_CHAR+0x88>
    b539:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b53d:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b541:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b545:	48 c1 e0 03          	shl    rax,0x3
    b549:	48 01 d0             	add    rax,rdx
    b54c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b54f:	89 c1                	mov    ecx,eax
    b551:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b555:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b559:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b55d:	48 c1 e0 03          	shl    rax,0x3
    b561:	48 01 d0             	add    rax,rdx
    b564:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b567:	89 c2                	mov    edx,eax
    b569:	89 c8                	mov    eax,ecx
    b56b:	29 d0                	sub    eax,edx
    b56d:	89 c7                	mov    edi,eax
    b56f:	e8 dd fa ff ff       	call   b051 <sign>
    b574:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    b577:	0f af c2             	imul   eax,edx
    b57a:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    b57d:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    b582:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b586:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b589:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    b58d:	72 aa                	jb     b539 <signature_TYPE_U_CHAR+0x3f>
    b58f:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    b594:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b598:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b59b:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    b59f:	72 8a                	jb     b52b <signature_TYPE_U_CHAR+0x31>
    b5a1:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    b5a4:	c9                   	leave  
    b5a5:	c3                   	ret    

000000000000b5a6 <CREATE_PERMUTATION_TYPE_INT>:
    b5a6:	f3 0f 1e fa          	endbr64 
    b5aa:	55                   	push   rbp
    b5ab:	48 89 e5             	mov    rbp,rsp
    b5ae:	48 83 ec 20          	sub    rsp,0x20
    b5b2:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b5b6:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b5bb:	75 07                	jne    b5c4 <CREATE_PERMUTATION_TYPE_INT+0x1e>
    b5bd:	b8 00 00 00 00       	mov    eax,0x0
    b5c2:	eb 38                	jmp    b5fc <CREATE_PERMUTATION_TYPE_INT+0x56>
    b5c4:	bf 18 00 00 00       	mov    edi,0x18
    b5c9:	e8 b2 6e ff ff       	call   2480 <malloc@plt>
    b5ce:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b5d2:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b5d6:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    b5da:	48 89 10             	mov    QWORD PTR [rax],rdx
    b5dd:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b5e1:	48 c1 e0 02          	shl    rax,0x2
    b5e5:	48 89 c7             	mov    rdi,rax
    b5e8:	e8 93 6e ff ff       	call   2480 <malloc@plt>
    b5ed:	48 89 c2             	mov    rdx,rax
    b5f0:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b5f4:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b5f8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b5fc:	c9                   	leave  
    b5fd:	c3                   	ret    

000000000000b5fe <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT>:
    b5fe:	f3 0f 1e fa          	endbr64 
    b602:	55                   	push   rbp
    b603:	48 89 e5             	mov    rbp,rsp
    b606:	48 83 ec 40          	sub    rsp,0x40
    b60a:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    b60e:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    b613:	75 0a                	jne    b61f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x21>
    b615:	b8 00 00 00 00       	mov    eax,0x0
    b61a:	e9 39 01 00 00       	jmp    b758 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x15a>
    b61f:	bf 18 00 00 00       	mov    edi,0x18
    b624:	e8 57 6e ff ff       	call   2480 <malloc@plt>
    b629:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    b62d:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b631:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b634:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b638:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b63c:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b640:	48 89 10             	mov    QWORD PTR [rax],rdx
    b643:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b647:	48 c1 e0 03          	shl    rax,0x3
    b64b:	48 89 c7             	mov    rdi,rax
    b64e:	e8 2d 6e ff ff       	call   2480 <malloc@plt>
    b653:	48 89 c2             	mov    rdx,rax
    b656:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b65a:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b65e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b662:	48 c1 e0 02          	shl    rax,0x2
    b666:	48 89 c7             	mov    rdi,rax
    b669:	e8 12 6e ff ff       	call   2480 <malloc@plt>
    b66e:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b672:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b676:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b67a:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b67e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b682:	48 89 ce             	mov    rsi,rcx
    b685:	48 89 c7             	mov    rdi,rax
    b688:	e8 93 6c ff ff       	call   2320 <COPY_ARRAY_TYPE_INT@plt>
    b68d:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    b691:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b695:	48 8b 15 44 59 00 00 	mov    rdx,QWORD PTR [rip+0x5944]        # 10fe0 <COMPARE_N_TYPE_INT@Base>
    b69c:	48 89 d1             	mov    rcx,rdx
    b69f:	ba 04 00 00 00       	mov    edx,0x4
    b6a4:	48 89 c7             	mov    rdi,rax
    b6a7:	e8 e4 6c ff ff       	call   2390 <qsort@plt>
    b6ac:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    b6b3:	00 
    b6b4:	eb 05                	jmp    b6bb <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0xbd>
    b6b6:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    b6bb:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    b6bf:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b6c3:	72 f1                	jb     b6b6 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0xb8>
    b6c5:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    b6cc:	00 
    b6cd:	eb 6f                	jmp    b73e <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x140>
    b6cf:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    b6d6:	00 
    b6d7:	eb 56                	jmp    b72f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x131>
    b6d9:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b6dd:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
    b6e4:	00 
    b6e5:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b6e9:	48 01 c2             	add    rdx,rax
    b6ec:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b6f0:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b6f4:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b6f8:	48 c1 e0 02          	shl    rax,0x2
    b6fc:	48 01 c8             	add    rax,rcx
    b6ff:	48 89 d6             	mov    rsi,rdx
    b702:	48 89 c7             	mov    rdi,rax
    b705:	e8 e6 6b ff ff       	call   22f0 <COMPARE_N_TYPE_INT@plt>
    b70a:	85 c0                	test   eax,eax
    b70c:	75 1c                	jne    b72a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x12c>
    b70e:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b712:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b716:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b71a:	48 c1 e0 03          	shl    rax,0x3
    b71e:	48 01 c2             	add    rdx,rax
    b721:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b725:	48 89 02             	mov    QWORD PTR [rdx],rax
    b728:	eb 0f                	jmp    b739 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0x13b>
    b72a:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    b72f:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b733:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b737:	72 a0                	jb     b6d9 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0xdb>
    b739:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    b73e:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b742:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b746:	72 87                	jb     b6cf <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT+0xd1>
    b748:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b74c:	48 89 c7             	mov    rdi,rax
    b74f:	e8 dc 6b ff ff       	call   2330 <free@plt>
    b754:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b758:	c9                   	leave  
    b759:	c3                   	ret    

000000000000b75a <IS_PERMUTATION_TYPE_INT>:
    b75a:	f3 0f 1e fa          	endbr64 
    b75e:	55                   	push   rbp
    b75f:	48 89 e5             	mov    rbp,rsp
    b762:	48 83 ec 20          	sub    rsp,0x20
    b766:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b76a:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b76f:	75 07                	jne    b778 <IS_PERMUTATION_TYPE_INT+0x1e>
    b771:	b8 00 00 00 00       	mov    eax,0x0
    b776:	eb 2f                	jmp    b7a7 <IS_PERMUTATION_TYPE_INT+0x4d>
    b778:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b77c:	48 89 c7             	mov    rdi,rax
    b77f:	e8 7a fe ff ff       	call   b5fe <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT>
    b784:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b788:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b78c:	48 89 c7             	mov    rdi,rax
    b78f:	e8 8a f7 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    b794:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    b797:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b79b:	48 89 c7             	mov    rdi,rax
    b79e:	e8 8d 6b ff ff       	call   2330 <free@plt>
    b7a3:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    b7a7:	c9                   	leave  
    b7a8:	c3                   	ret    

000000000000b7a9 <signature_TYPE_INT>:
    b7a9:	f3 0f 1e fa          	endbr64 
    b7ad:	55                   	push   rbp
    b7ae:	48 89 e5             	mov    rbp,rsp
    b7b1:	48 83 ec 30          	sub    rsp,0x30
    b7b5:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    b7b9:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b7bd:	48 89 c7             	mov    rdi,rax
    b7c0:	e8 39 fe ff ff       	call   b5fe <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_INT>
    b7c5:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b7c9:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    b7d0:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    b7d7:	00 
    b7d8:	eb 69                	jmp    b843 <signature_TYPE_INT+0x9a>
    b7da:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b7de:	48 83 c0 01          	add    rax,0x1
    b7e2:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b7e6:	eb 49                	jmp    b831 <signature_TYPE_INT+0x88>
    b7e8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b7ec:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b7f0:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b7f4:	48 c1 e0 03          	shl    rax,0x3
    b7f8:	48 01 d0             	add    rax,rdx
    b7fb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b7fe:	89 c1                	mov    ecx,eax
    b800:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b804:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b808:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b80c:	48 c1 e0 03          	shl    rax,0x3
    b810:	48 01 d0             	add    rax,rdx
    b813:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b816:	89 c2                	mov    edx,eax
    b818:	89 c8                	mov    eax,ecx
    b81a:	29 d0                	sub    eax,edx
    b81c:	89 c7                	mov    edi,eax
    b81e:	e8 2e f8 ff ff       	call   b051 <sign>
    b823:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    b826:	0f af c2             	imul   eax,edx
    b829:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    b82c:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    b831:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b835:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b838:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    b83c:	72 aa                	jb     b7e8 <signature_TYPE_INT+0x3f>
    b83e:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    b843:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b847:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b84a:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    b84e:	72 8a                	jb     b7da <signature_TYPE_INT+0x31>
    b850:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    b853:	c9                   	leave  
    b854:	c3                   	ret    

000000000000b855 <CREATE_PERMUTATION_TYPE_U_INT>:
    b855:	f3 0f 1e fa          	endbr64 
    b859:	55                   	push   rbp
    b85a:	48 89 e5             	mov    rbp,rsp
    b85d:	48 83 ec 20          	sub    rsp,0x20
    b861:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    b865:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    b86a:	75 07                	jne    b873 <CREATE_PERMUTATION_TYPE_U_INT+0x1e>
    b86c:	b8 00 00 00 00       	mov    eax,0x0
    b871:	eb 38                	jmp    b8ab <CREATE_PERMUTATION_TYPE_U_INT+0x56>
    b873:	bf 18 00 00 00       	mov    edi,0x18
    b878:	e8 03 6c ff ff       	call   2480 <malloc@plt>
    b87d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b881:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b885:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    b889:	48 89 10             	mov    QWORD PTR [rax],rdx
    b88c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b890:	48 c1 e0 02          	shl    rax,0x2
    b894:	48 89 c7             	mov    rdi,rax
    b897:	e8 e4 6b ff ff       	call   2480 <malloc@plt>
    b89c:	48 89 c2             	mov    rdx,rax
    b89f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b8a3:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b8a7:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b8ab:	c9                   	leave  
    b8ac:	c3                   	ret    

000000000000b8ad <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT>:
    b8ad:	f3 0f 1e fa          	endbr64 
    b8b1:	55                   	push   rbp
    b8b2:	48 89 e5             	mov    rbp,rsp
    b8b5:	48 83 ec 40          	sub    rsp,0x40
    b8b9:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    b8bd:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    b8c2:	75 0a                	jne    b8ce <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x21>
    b8c4:	b8 00 00 00 00       	mov    eax,0x0
    b8c9:	e9 39 01 00 00       	jmp    ba07 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x15a>
    b8ce:	bf 18 00 00 00       	mov    edi,0x18
    b8d3:	e8 a8 6b ff ff       	call   2480 <malloc@plt>
    b8d8:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    b8dc:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b8e0:	48 8b 00             	mov    rax,QWORD PTR [rax]
    b8e3:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    b8e7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b8eb:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b8ef:	48 89 10             	mov    QWORD PTR [rax],rdx
    b8f2:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b8f6:	48 c1 e0 03          	shl    rax,0x3
    b8fa:	48 89 c7             	mov    rdi,rax
    b8fd:	e8 7e 6b ff ff       	call   2480 <malloc@plt>
    b902:	48 89 c2             	mov    rdx,rax
    b905:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b909:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    b90d:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    b911:	48 c1 e0 02          	shl    rax,0x2
    b915:	48 89 c7             	mov    rdi,rax
    b918:	e8 63 6b ff ff       	call   2480 <malloc@plt>
    b91d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    b921:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b925:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b929:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    b92d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b931:	48 89 ce             	mov    rsi,rcx
    b934:	48 89 c7             	mov    rdi,rax
    b937:	e8 f4 6a ff ff       	call   2430 <COPY_ARRAY_TYPE_U_INT@plt>
    b93c:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    b940:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b944:	48 8b 15 7d 56 00 00 	mov    rdx,QWORD PTR [rip+0x567d]        # 10fc8 <COMPARE_N_TYPE_U_INT@Base>
    b94b:	48 89 d1             	mov    rcx,rdx
    b94e:	ba 04 00 00 00       	mov    edx,0x4
    b953:	48 89 c7             	mov    rdi,rax
    b956:	e8 35 6a ff ff       	call   2390 <qsort@plt>
    b95b:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    b962:	00 
    b963:	eb 05                	jmp    b96a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0xbd>
    b965:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    b96a:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    b96e:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b972:	72 f1                	jb     b965 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0xb8>
    b974:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    b97b:	00 
    b97c:	eb 6f                	jmp    b9ed <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x140>
    b97e:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    b985:	00 
    b986:	eb 56                	jmp    b9de <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x131>
    b988:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b98c:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
    b993:	00 
    b994:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b998:	48 01 c2             	add    rdx,rax
    b99b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    b99f:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    b9a3:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b9a7:	48 c1 e0 02          	shl    rax,0x2
    b9ab:	48 01 c8             	add    rax,rcx
    b9ae:	48 89 d6             	mov    rsi,rdx
    b9b1:	48 89 c7             	mov    rdi,rax
    b9b4:	e8 07 69 ff ff       	call   22c0 <COMPARE_N_TYPE_U_INT@plt>
    b9b9:	85 c0                	test   eax,eax
    b9bb:	75 1c                	jne    b9d9 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x12c>
    b9bd:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    b9c1:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    b9c5:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b9c9:	48 c1 e0 03          	shl    rax,0x3
    b9cd:	48 01 c2             	add    rdx,rax
    b9d0:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b9d4:	48 89 02             	mov    QWORD PTR [rdx],rax
    b9d7:	eb 0f                	jmp    b9e8 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0x13b>
    b9d9:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    b9de:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    b9e2:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b9e6:	72 a0                	jb     b988 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0xdb>
    b9e8:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    b9ed:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    b9f1:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    b9f5:	72 87                	jb     b97e <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT+0xd1>
    b9f7:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    b9fb:	48 89 c7             	mov    rdi,rax
    b9fe:	e8 2d 69 ff ff       	call   2330 <free@plt>
    ba03:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ba07:	c9                   	leave  
    ba08:	c3                   	ret    

000000000000ba09 <IS_PERMUTATION_TYPE_U_INT>:
    ba09:	f3 0f 1e fa          	endbr64 
    ba0d:	55                   	push   rbp
    ba0e:	48 89 e5             	mov    rbp,rsp
    ba11:	48 83 ec 20          	sub    rsp,0x20
    ba15:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    ba19:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    ba1e:	75 07                	jne    ba27 <IS_PERMUTATION_TYPE_U_INT+0x1e>
    ba20:	b8 00 00 00 00       	mov    eax,0x0
    ba25:	eb 2f                	jmp    ba56 <IS_PERMUTATION_TYPE_U_INT+0x4d>
    ba27:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ba2b:	48 89 c7             	mov    rdi,rax
    ba2e:	e8 7a fe ff ff       	call   b8ad <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT>
    ba33:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ba37:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ba3b:	48 89 c7             	mov    rdi,rax
    ba3e:	e8 db f4 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    ba43:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    ba46:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ba4a:	48 89 c7             	mov    rdi,rax
    ba4d:	e8 de 68 ff ff       	call   2330 <free@plt>
    ba52:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    ba56:	c9                   	leave  
    ba57:	c3                   	ret    

000000000000ba58 <signature_TYPE_U_INT>:
    ba58:	f3 0f 1e fa          	endbr64 
    ba5c:	55                   	push   rbp
    ba5d:	48 89 e5             	mov    rbp,rsp
    ba60:	48 83 ec 30          	sub    rsp,0x30
    ba64:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    ba68:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    ba6c:	48 89 c7             	mov    rdi,rax
    ba6f:	e8 39 fe ff ff       	call   b8ad <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_INT>
    ba74:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ba78:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    ba7f:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    ba86:	00 
    ba87:	eb 69                	jmp    baf2 <signature_TYPE_U_INT+0x9a>
    ba89:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ba8d:	48 83 c0 01          	add    rax,0x1
    ba91:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    ba95:	eb 49                	jmp    bae0 <signature_TYPE_U_INT+0x88>
    ba97:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ba9b:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    ba9f:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    baa3:	48 c1 e0 03          	shl    rax,0x3
    baa7:	48 01 d0             	add    rax,rdx
    baaa:	48 8b 00             	mov    rax,QWORD PTR [rax]
    baad:	89 c1                	mov    ecx,eax
    baaf:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bab3:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bab7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    babb:	48 c1 e0 03          	shl    rax,0x3
    babf:	48 01 d0             	add    rax,rdx
    bac2:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bac5:	89 c2                	mov    edx,eax
    bac7:	89 c8                	mov    eax,ecx
    bac9:	29 d0                	sub    eax,edx
    bacb:	89 c7                	mov    edi,eax
    bacd:	e8 7f f5 ff ff       	call   b051 <sign>
    bad2:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    bad5:	0f af c2             	imul   eax,edx
    bad8:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    badb:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    bae0:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bae4:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bae7:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    baeb:	72 aa                	jb     ba97 <signature_TYPE_U_INT+0x3f>
    baed:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    baf2:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    baf6:	48 8b 00             	mov    rax,QWORD PTR [rax]
    baf9:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    bafd:	72 8a                	jb     ba89 <signature_TYPE_U_INT+0x31>
    baff:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    bb02:	c9                   	leave  
    bb03:	c3                   	ret    

000000000000bb04 <CREATE_PERMUTATION_TYPE_L_INT>:
    bb04:	f3 0f 1e fa          	endbr64 
    bb08:	55                   	push   rbp
    bb09:	48 89 e5             	mov    rbp,rsp
    bb0c:	48 83 ec 20          	sub    rsp,0x20
    bb10:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    bb14:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    bb19:	75 07                	jne    bb22 <CREATE_PERMUTATION_TYPE_L_INT+0x1e>
    bb1b:	b8 00 00 00 00       	mov    eax,0x0
    bb20:	eb 38                	jmp    bb5a <CREATE_PERMUTATION_TYPE_L_INT+0x56>
    bb22:	bf 18 00 00 00       	mov    edi,0x18
    bb27:	e8 54 69 ff ff       	call   2480 <malloc@plt>
    bb2c:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bb30:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bb34:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    bb38:	48 89 10             	mov    QWORD PTR [rax],rdx
    bb3b:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bb3f:	48 c1 e0 03          	shl    rax,0x3
    bb43:	48 89 c7             	mov    rdi,rax
    bb46:	e8 35 69 ff ff       	call   2480 <malloc@plt>
    bb4b:	48 89 c2             	mov    rdx,rax
    bb4e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bb52:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    bb56:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bb5a:	c9                   	leave  
    bb5b:	c3                   	ret    

000000000000bb5c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT>:
    bb5c:	f3 0f 1e fa          	endbr64 
    bb60:	55                   	push   rbp
    bb61:	48 89 e5             	mov    rbp,rsp
    bb64:	48 83 ec 40          	sub    rsp,0x40
    bb68:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    bb6c:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    bb71:	75 0a                	jne    bb7d <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x21>
    bb73:	b8 00 00 00 00       	mov    eax,0x0
    bb78:	e9 39 01 00 00       	jmp    bcb6 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x15a>
    bb7d:	bf 18 00 00 00       	mov    edi,0x18
    bb82:	e8 f9 68 ff ff       	call   2480 <malloc@plt>
    bb87:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    bb8b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    bb8f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bb92:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    bb96:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bb9a:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    bb9e:	48 89 10             	mov    QWORD PTR [rax],rdx
    bba1:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    bba5:	48 c1 e0 03          	shl    rax,0x3
    bba9:	48 89 c7             	mov    rdi,rax
    bbac:	e8 cf 68 ff ff       	call   2480 <malloc@plt>
    bbb1:	48 89 c2             	mov    rdx,rax
    bbb4:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bbb8:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    bbbc:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    bbc0:	48 c1 e0 03          	shl    rax,0x3
    bbc4:	48 89 c7             	mov    rdi,rax
    bbc7:	e8 b4 68 ff ff       	call   2480 <malloc@plt>
    bbcc:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bbd0:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    bbd4:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    bbd8:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    bbdc:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bbe0:	48 89 ce             	mov    rsi,rcx
    bbe3:	48 89 c7             	mov    rdi,rax
    bbe6:	e8 85 67 ff ff       	call   2370 <COPY_ARRAY_TYPE_L_INT@plt>
    bbeb:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    bbef:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bbf3:	48 8b 15 be 53 00 00 	mov    rdx,QWORD PTR [rip+0x53be]        # 10fb8 <COMPARE_N_TYPE_L_INT@Base>
    bbfa:	48 89 d1             	mov    rcx,rdx
    bbfd:	ba 08 00 00 00       	mov    edx,0x8
    bc02:	48 89 c7             	mov    rdi,rax
    bc05:	e8 86 67 ff ff       	call   2390 <qsort@plt>
    bc0a:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    bc11:	00 
    bc12:	eb 05                	jmp    bc19 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0xbd>
    bc14:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    bc19:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    bc1d:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bc21:	72 f1                	jb     bc14 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0xb8>
    bc23:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    bc2a:	00 
    bc2b:	eb 6f                	jmp    bc9c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x140>
    bc2d:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    bc34:	00 
    bc35:	eb 56                	jmp    bc8d <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x131>
    bc37:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    bc3b:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    bc42:	00 
    bc43:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bc47:	48 01 c2             	add    rdx,rax
    bc4a:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    bc4e:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    bc52:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bc56:	48 c1 e0 03          	shl    rax,0x3
    bc5a:	48 01 c8             	add    rax,rcx
    bc5d:	48 89 d6             	mov    rsi,rdx
    bc60:	48 89 c7             	mov    rdi,rax
    bc63:	e8 38 66 ff ff       	call   22a0 <COMPARE_N_TYPE_L_INT@plt>
    bc68:	85 c0                	test   eax,eax
    bc6a:	75 1c                	jne    bc88 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x12c>
    bc6c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bc70:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bc74:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bc78:	48 c1 e0 03          	shl    rax,0x3
    bc7c:	48 01 c2             	add    rdx,rax
    bc7f:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    bc83:	48 89 02             	mov    QWORD PTR [rdx],rax
    bc86:	eb 0f                	jmp    bc97 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0x13b>
    bc88:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    bc8d:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    bc91:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bc95:	72 a0                	jb     bc37 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0xdb>
    bc97:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    bc9c:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bca0:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bca4:	72 87                	jb     bc2d <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT+0xd1>
    bca6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bcaa:	48 89 c7             	mov    rdi,rax
    bcad:	e8 7e 66 ff ff       	call   2330 <free@plt>
    bcb2:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bcb6:	c9                   	leave  
    bcb7:	c3                   	ret    

000000000000bcb8 <IS_PERMUTATION_TYPE_L_INT>:
    bcb8:	f3 0f 1e fa          	endbr64 
    bcbc:	55                   	push   rbp
    bcbd:	48 89 e5             	mov    rbp,rsp
    bcc0:	48 83 ec 20          	sub    rsp,0x20
    bcc4:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    bcc8:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    bccd:	75 07                	jne    bcd6 <IS_PERMUTATION_TYPE_L_INT+0x1e>
    bccf:	b8 00 00 00 00       	mov    eax,0x0
    bcd4:	eb 2f                	jmp    bd05 <IS_PERMUTATION_TYPE_L_INT+0x4d>
    bcd6:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bcda:	48 89 c7             	mov    rdi,rax
    bcdd:	e8 7a fe ff ff       	call   bb5c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT>
    bce2:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bce6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bcea:	48 89 c7             	mov    rdi,rax
    bced:	e8 2c f2 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    bcf2:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    bcf5:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bcf9:	48 89 c7             	mov    rdi,rax
    bcfc:	e8 2f 66 ff ff       	call   2330 <free@plt>
    bd01:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    bd05:	c9                   	leave  
    bd06:	c3                   	ret    

000000000000bd07 <signature_TYPE_L_INT>:
    bd07:	f3 0f 1e fa          	endbr64 
    bd0b:	55                   	push   rbp
    bd0c:	48 89 e5             	mov    rbp,rsp
    bd0f:	48 83 ec 30          	sub    rsp,0x30
    bd13:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    bd17:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bd1b:	48 89 c7             	mov    rdi,rax
    bd1e:	e8 39 fe ff ff       	call   bb5c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_INT>
    bd23:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bd27:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    bd2e:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    bd35:	00 
    bd36:	eb 69                	jmp    bda1 <signature_TYPE_L_INT+0x9a>
    bd38:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bd3c:	48 83 c0 01          	add    rax,0x1
    bd40:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    bd44:	eb 49                	jmp    bd8f <signature_TYPE_L_INT+0x88>
    bd46:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bd4a:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bd4e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    bd52:	48 c1 e0 03          	shl    rax,0x3
    bd56:	48 01 d0             	add    rax,rdx
    bd59:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bd5c:	89 c1                	mov    ecx,eax
    bd5e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bd62:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bd66:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bd6a:	48 c1 e0 03          	shl    rax,0x3
    bd6e:	48 01 d0             	add    rax,rdx
    bd71:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bd74:	89 c2                	mov    edx,eax
    bd76:	89 c8                	mov    eax,ecx
    bd78:	29 d0                	sub    eax,edx
    bd7a:	89 c7                	mov    edi,eax
    bd7c:	e8 d0 f2 ff ff       	call   b051 <sign>
    bd81:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    bd84:	0f af c2             	imul   eax,edx
    bd87:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    bd8a:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    bd8f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bd93:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bd96:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    bd9a:	72 aa                	jb     bd46 <signature_TYPE_L_INT+0x3f>
    bd9c:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    bda1:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bda5:	48 8b 00             	mov    rax,QWORD PTR [rax]
    bda8:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    bdac:	72 8a                	jb     bd38 <signature_TYPE_L_INT+0x31>
    bdae:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    bdb1:	c9                   	leave  
    bdb2:	c3                   	ret    

000000000000bdb3 <CREATE_PERMUTATION_TYPE_U_L_INT>:
    bdb3:	f3 0f 1e fa          	endbr64 
    bdb7:	55                   	push   rbp
    bdb8:	48 89 e5             	mov    rbp,rsp
    bdbb:	48 83 ec 20          	sub    rsp,0x20
    bdbf:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    bdc3:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    bdc8:	75 07                	jne    bdd1 <CREATE_PERMUTATION_TYPE_U_L_INT+0x1e>
    bdca:	b8 00 00 00 00       	mov    eax,0x0
    bdcf:	eb 38                	jmp    be09 <CREATE_PERMUTATION_TYPE_U_L_INT+0x56>
    bdd1:	bf 18 00 00 00       	mov    edi,0x18
    bdd6:	e8 a5 66 ff ff       	call   2480 <malloc@plt>
    bddb:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bddf:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bde3:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    bde7:	48 89 10             	mov    QWORD PTR [rax],rdx
    bdea:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bdee:	48 c1 e0 03          	shl    rax,0x3
    bdf2:	48 89 c7             	mov    rdi,rax
    bdf5:	e8 86 66 ff ff       	call   2480 <malloc@plt>
    bdfa:	48 89 c2             	mov    rdx,rax
    bdfd:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    be01:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    be05:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    be09:	c9                   	leave  
    be0a:	c3                   	ret    

000000000000be0b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT>:
    be0b:	f3 0f 1e fa          	endbr64 
    be0f:	55                   	push   rbp
    be10:	48 89 e5             	mov    rbp,rsp
    be13:	48 83 ec 40          	sub    rsp,0x40
    be17:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    be1b:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    be20:	75 0a                	jne    be2c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x21>
    be22:	b8 00 00 00 00       	mov    eax,0x0
    be27:	e9 39 01 00 00       	jmp    bf65 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x15a>
    be2c:	bf 18 00 00 00       	mov    edi,0x18
    be31:	e8 4a 66 ff ff       	call   2480 <malloc@plt>
    be36:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    be3a:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    be3e:	48 8b 00             	mov    rax,QWORD PTR [rax]
    be41:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    be45:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    be49:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    be4d:	48 89 10             	mov    QWORD PTR [rax],rdx
    be50:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    be54:	48 c1 e0 03          	shl    rax,0x3
    be58:	48 89 c7             	mov    rdi,rax
    be5b:	e8 20 66 ff ff       	call   2480 <malloc@plt>
    be60:	48 89 c2             	mov    rdx,rax
    be63:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    be67:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    be6b:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    be6f:	48 c1 e0 03          	shl    rax,0x3
    be73:	48 89 c7             	mov    rdi,rax
    be76:	e8 05 66 ff ff       	call   2480 <malloc@plt>
    be7b:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    be7f:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    be83:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    be87:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    be8b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    be8f:	48 89 ce             	mov    rsi,rcx
    be92:	48 89 c7             	mov    rdi,rax
    be95:	e8 76 65 ff ff       	call   2410 <COPY_ARRAY_TYPE_U_L_INT@plt>
    be9a:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    be9e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bea2:	48 8b 15 2f 51 00 00 	mov    rdx,QWORD PTR [rip+0x512f]        # 10fd8 <COMPARE_N_TYPE_U_L_INT@Base>
    bea9:	48 89 d1             	mov    rcx,rdx
    beac:	ba 08 00 00 00       	mov    edx,0x8
    beb1:	48 89 c7             	mov    rdi,rax
    beb4:	e8 d7 64 ff ff       	call   2390 <qsort@plt>
    beb9:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    bec0:	00 
    bec1:	eb 05                	jmp    bec8 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0xbd>
    bec3:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    bec8:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    becc:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bed0:	72 f1                	jb     bec3 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0xb8>
    bed2:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    bed9:	00 
    beda:	eb 6f                	jmp    bf4b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x140>
    bedc:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    bee3:	00 
    bee4:	eb 56                	jmp    bf3c <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x131>
    bee6:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    beea:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    bef1:	00 
    bef2:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bef6:	48 01 c2             	add    rdx,rax
    bef9:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    befd:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    bf01:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bf05:	48 c1 e0 03          	shl    rax,0x3
    bf09:	48 01 c8             	add    rax,rcx
    bf0c:	48 89 d6             	mov    rsi,rdx
    bf0f:	48 89 c7             	mov    rdi,rax
    bf12:	e8 c9 63 ff ff       	call   22e0 <COMPARE_N_TYPE_U_L_INT@plt>
    bf17:	85 c0                	test   eax,eax
    bf19:	75 1c                	jne    bf37 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x12c>
    bf1b:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bf1f:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bf23:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bf27:	48 c1 e0 03          	shl    rax,0x3
    bf2b:	48 01 c2             	add    rdx,rax
    bf2e:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    bf32:	48 89 02             	mov    QWORD PTR [rdx],rax
    bf35:	eb 0f                	jmp    bf46 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0x13b>
    bf37:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    bf3c:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    bf40:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bf44:	72 a0                	jb     bee6 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0xdb>
    bf46:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    bf4b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bf4f:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    bf53:	72 87                	jb     bedc <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT+0xd1>
    bf55:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bf59:	48 89 c7             	mov    rdi,rax
    bf5c:	e8 cf 63 ff ff       	call   2330 <free@plt>
    bf61:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bf65:	c9                   	leave  
    bf66:	c3                   	ret    

000000000000bf67 <IS_PERMUTATION_TYPE_U_L_INT>:
    bf67:	f3 0f 1e fa          	endbr64 
    bf6b:	55                   	push   rbp
    bf6c:	48 89 e5             	mov    rbp,rsp
    bf6f:	48 83 ec 20          	sub    rsp,0x20
    bf73:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    bf77:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    bf7c:	75 07                	jne    bf85 <IS_PERMUTATION_TYPE_U_L_INT+0x1e>
    bf7e:	b8 00 00 00 00       	mov    eax,0x0
    bf83:	eb 2f                	jmp    bfb4 <IS_PERMUTATION_TYPE_U_L_INT+0x4d>
    bf85:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bf89:	48 89 c7             	mov    rdi,rax
    bf8c:	e8 7a fe ff ff       	call   be0b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT>
    bf91:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bf95:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bf99:	48 89 c7             	mov    rdi,rax
    bf9c:	e8 7d ef ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    bfa1:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    bfa4:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bfa8:	48 89 c7             	mov    rdi,rax
    bfab:	e8 80 63 ff ff       	call   2330 <free@plt>
    bfb0:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    bfb4:	c9                   	leave  
    bfb5:	c3                   	ret    

000000000000bfb6 <signature_TYPE_U_L_INT>:
    bfb6:	f3 0f 1e fa          	endbr64 
    bfba:	55                   	push   rbp
    bfbb:	48 89 e5             	mov    rbp,rsp
    bfbe:	48 83 ec 30          	sub    rsp,0x30
    bfc2:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    bfc6:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    bfca:	48 89 c7             	mov    rdi,rax
    bfcd:	e8 39 fe ff ff       	call   be0b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_U_L_INT>
    bfd2:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    bfd6:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    bfdd:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    bfe4:	00 
    bfe5:	eb 69                	jmp    c050 <signature_TYPE_U_L_INT+0x9a>
    bfe7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    bfeb:	48 83 c0 01          	add    rax,0x1
    bfef:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    bff3:	eb 49                	jmp    c03e <signature_TYPE_U_L_INT+0x88>
    bff5:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    bff9:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    bffd:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c001:	48 c1 e0 03          	shl    rax,0x3
    c005:	48 01 d0             	add    rax,rdx
    c008:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c00b:	89 c1                	mov    ecx,eax
    c00d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c011:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c015:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c019:	48 c1 e0 03          	shl    rax,0x3
    c01d:	48 01 d0             	add    rax,rdx
    c020:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c023:	89 c2                	mov    edx,eax
    c025:	89 c8                	mov    eax,ecx
    c027:	29 d0                	sub    eax,edx
    c029:	89 c7                	mov    edi,eax
    c02b:	e8 21 f0 ff ff       	call   b051 <sign>
    c030:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    c033:	0f af c2             	imul   eax,edx
    c036:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    c039:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    c03e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c042:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c045:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    c049:	72 aa                	jb     bff5 <signature_TYPE_U_L_INT+0x3f>
    c04b:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    c050:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c054:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c057:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    c05b:	72 8a                	jb     bfe7 <signature_TYPE_U_L_INT+0x31>
    c05d:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    c060:	c9                   	leave  
    c061:	c3                   	ret    

000000000000c062 <CREATE_PERMUTATION_TYPE_SIZE_T>:
    c062:	f3 0f 1e fa          	endbr64 
    c066:	55                   	push   rbp
    c067:	48 89 e5             	mov    rbp,rsp
    c06a:	48 83 ec 20          	sub    rsp,0x20
    c06e:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c072:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c077:	75 07                	jne    c080 <CREATE_PERMUTATION_TYPE_SIZE_T+0x1e>
    c079:	b8 00 00 00 00       	mov    eax,0x0
    c07e:	eb 38                	jmp    c0b8 <CREATE_PERMUTATION_TYPE_SIZE_T+0x56>
    c080:	bf 18 00 00 00       	mov    edi,0x18
    c085:	e8 f6 63 ff ff       	call   2480 <malloc@plt>
    c08a:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c08e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c092:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    c096:	48 89 10             	mov    QWORD PTR [rax],rdx
    c099:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c09d:	48 c1 e0 03          	shl    rax,0x3
    c0a1:	48 89 c7             	mov    rdi,rax
    c0a4:	e8 d7 63 ff ff       	call   2480 <malloc@plt>
    c0a9:	48 89 c2             	mov    rdx,rax
    c0ac:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c0b0:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c0b4:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c0b8:	c9                   	leave  
    c0b9:	c3                   	ret    

000000000000c0ba <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T>:
    c0ba:	f3 0f 1e fa          	endbr64 
    c0be:	55                   	push   rbp
    c0bf:	48 89 e5             	mov    rbp,rsp
    c0c2:	48 83 ec 40          	sub    rsp,0x40
    c0c6:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    c0ca:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    c0cf:	75 0a                	jne    c0db <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x21>
    c0d1:	b8 00 00 00 00       	mov    eax,0x0
    c0d6:	e9 39 01 00 00       	jmp    c214 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x15a>
    c0db:	bf 18 00 00 00       	mov    edi,0x18
    c0e0:	e8 9b 63 ff ff       	call   2480 <malloc@plt>
    c0e5:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    c0e9:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c0ed:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c0f0:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c0f4:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c0f8:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c0fc:	48 89 10             	mov    QWORD PTR [rax],rdx
    c0ff:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c103:	48 c1 e0 03          	shl    rax,0x3
    c107:	48 89 c7             	mov    rdi,rax
    c10a:	e8 71 63 ff ff       	call   2480 <malloc@plt>
    c10f:	48 89 c2             	mov    rdx,rax
    c112:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c116:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c11a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c11e:	48 c1 e0 03          	shl    rax,0x3
    c122:	48 89 c7             	mov    rdi,rax
    c125:	e8 56 63 ff ff       	call   2480 <malloc@plt>
    c12a:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c12e:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c132:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c136:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c13a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c13e:	48 89 ce             	mov    rsi,rcx
    c141:	48 89 c7             	mov    rdi,rax
    c144:	e8 87 63 ff ff       	call   24d0 <COPY_ARRAY_TYPE_SIZE_T@plt>
    c149:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    c14d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c151:	48 8b 15 58 4e 00 00 	mov    rdx,QWORD PTR [rip+0x4e58]        # 10fb0 <COMPARE_N_TYPE_SIZE_T@Base>
    c158:	48 89 d1             	mov    rcx,rdx
    c15b:	ba 08 00 00 00       	mov    edx,0x8
    c160:	48 89 c7             	mov    rdi,rax
    c163:	e8 28 62 ff ff       	call   2390 <qsort@plt>
    c168:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    c16f:	00 
    c170:	eb 05                	jmp    c177 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0xbd>
    c172:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    c177:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    c17b:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c17f:	72 f1                	jb     c172 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0xb8>
    c181:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    c188:	00 
    c189:	eb 6f                	jmp    c1fa <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x140>
    c18b:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    c192:	00 
    c193:	eb 56                	jmp    c1eb <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x131>
    c195:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c199:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    c1a0:	00 
    c1a1:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c1a5:	48 01 c2             	add    rdx,rax
    c1a8:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c1ac:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c1b0:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c1b4:	48 c1 e0 03          	shl    rax,0x3
    c1b8:	48 01 c8             	add    rax,rcx
    c1bb:	48 89 d6             	mov    rsi,rdx
    c1be:	48 89 c7             	mov    rdi,rax
    c1c1:	e8 ca 60 ff ff       	call   2290 <COMPARE_N_TYPE_SIZE_T@plt>
    c1c6:	85 c0                	test   eax,eax
    c1c8:	75 1c                	jne    c1e6 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x12c>
    c1ca:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c1ce:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c1d2:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c1d6:	48 c1 e0 03          	shl    rax,0x3
    c1da:	48 01 c2             	add    rdx,rax
    c1dd:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c1e1:	48 89 02             	mov    QWORD PTR [rdx],rax
    c1e4:	eb 0f                	jmp    c1f5 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0x13b>
    c1e6:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    c1eb:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c1ef:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c1f3:	72 a0                	jb     c195 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0xdb>
    c1f5:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    c1fa:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c1fe:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c202:	72 87                	jb     c18b <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T+0xd1>
    c204:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c208:	48 89 c7             	mov    rdi,rax
    c20b:	e8 20 61 ff ff       	call   2330 <free@plt>
    c210:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c214:	c9                   	leave  
    c215:	c3                   	ret    

000000000000c216 <IS_PERMUTATION_TYPE_SIZE_T>:
    c216:	f3 0f 1e fa          	endbr64 
    c21a:	55                   	push   rbp
    c21b:	48 89 e5             	mov    rbp,rsp
    c21e:	48 83 ec 20          	sub    rsp,0x20
    c222:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c226:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c22b:	75 07                	jne    c234 <IS_PERMUTATION_TYPE_SIZE_T+0x1e>
    c22d:	b8 00 00 00 00       	mov    eax,0x0
    c232:	eb 2f                	jmp    c263 <IS_PERMUTATION_TYPE_SIZE_T+0x4d>
    c234:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c238:	48 89 c7             	mov    rdi,rax
    c23b:	e8 7a fe ff ff       	call   c0ba <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T>
    c240:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c244:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c248:	48 89 c7             	mov    rdi,rax
    c24b:	e8 ce ec ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    c250:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    c253:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c257:	48 89 c7             	mov    rdi,rax
    c25a:	e8 d1 60 ff ff       	call   2330 <free@plt>
    c25f:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    c263:	c9                   	leave  
    c264:	c3                   	ret    

000000000000c265 <signature_TYPE_SIZE_T>:
    c265:	f3 0f 1e fa          	endbr64 
    c269:	55                   	push   rbp
    c26a:	48 89 e5             	mov    rbp,rsp
    c26d:	48 83 ec 30          	sub    rsp,0x30
    c271:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    c275:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c279:	48 89 c7             	mov    rdi,rax
    c27c:	e8 39 fe ff ff       	call   c0ba <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_SIZE_T>
    c281:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c285:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    c28c:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    c293:	00 
    c294:	eb 69                	jmp    c2ff <signature_TYPE_SIZE_T+0x9a>
    c296:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c29a:	48 83 c0 01          	add    rax,0x1
    c29e:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c2a2:	eb 49                	jmp    c2ed <signature_TYPE_SIZE_T+0x88>
    c2a4:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c2a8:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c2ac:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c2b0:	48 c1 e0 03          	shl    rax,0x3
    c2b4:	48 01 d0             	add    rax,rdx
    c2b7:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c2ba:	89 c1                	mov    ecx,eax
    c2bc:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c2c0:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c2c4:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c2c8:	48 c1 e0 03          	shl    rax,0x3
    c2cc:	48 01 d0             	add    rax,rdx
    c2cf:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c2d2:	89 c2                	mov    edx,eax
    c2d4:	89 c8                	mov    eax,ecx
    c2d6:	29 d0                	sub    eax,edx
    c2d8:	89 c7                	mov    edi,eax
    c2da:	e8 72 ed ff ff       	call   b051 <sign>
    c2df:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    c2e2:	0f af c2             	imul   eax,edx
    c2e5:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    c2e8:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    c2ed:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c2f1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c2f4:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    c2f8:	72 aa                	jb     c2a4 <signature_TYPE_SIZE_T+0x3f>
    c2fa:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    c2ff:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c303:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c306:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    c30a:	72 8a                	jb     c296 <signature_TYPE_SIZE_T+0x31>
    c30c:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    c30f:	c9                   	leave  
    c310:	c3                   	ret    

000000000000c311 <CREATE_PERMUTATION_TYPE_FLOAT>:
    c311:	f3 0f 1e fa          	endbr64 
    c315:	55                   	push   rbp
    c316:	48 89 e5             	mov    rbp,rsp
    c319:	48 83 ec 20          	sub    rsp,0x20
    c31d:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c321:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c326:	75 07                	jne    c32f <CREATE_PERMUTATION_TYPE_FLOAT+0x1e>
    c328:	b8 00 00 00 00       	mov    eax,0x0
    c32d:	eb 38                	jmp    c367 <CREATE_PERMUTATION_TYPE_FLOAT+0x56>
    c32f:	bf 18 00 00 00       	mov    edi,0x18
    c334:	e8 47 61 ff ff       	call   2480 <malloc@plt>
    c339:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c33d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c341:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    c345:	48 89 10             	mov    QWORD PTR [rax],rdx
    c348:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c34c:	48 c1 e0 02          	shl    rax,0x2
    c350:	48 89 c7             	mov    rdi,rax
    c353:	e8 28 61 ff ff       	call   2480 <malloc@plt>
    c358:	48 89 c2             	mov    rdx,rax
    c35b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c35f:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c363:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c367:	c9                   	leave  
    c368:	c3                   	ret    

000000000000c369 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT>:
    c369:	f3 0f 1e fa          	endbr64 
    c36d:	55                   	push   rbp
    c36e:	48 89 e5             	mov    rbp,rsp
    c371:	48 83 ec 40          	sub    rsp,0x40
    c375:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    c379:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    c37e:	75 0a                	jne    c38a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x21>
    c380:	b8 00 00 00 00       	mov    eax,0x0
    c385:	e9 39 01 00 00       	jmp    c4c3 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x15a>
    c38a:	bf 18 00 00 00       	mov    edi,0x18
    c38f:	e8 ec 60 ff ff       	call   2480 <malloc@plt>
    c394:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    c398:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c39c:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c39f:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c3a3:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c3a7:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c3ab:	48 89 10             	mov    QWORD PTR [rax],rdx
    c3ae:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c3b2:	48 c1 e0 03          	shl    rax,0x3
    c3b6:	48 89 c7             	mov    rdi,rax
    c3b9:	e8 c2 60 ff ff       	call   2480 <malloc@plt>
    c3be:	48 89 c2             	mov    rdx,rax
    c3c1:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c3c5:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c3c9:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c3cd:	48 c1 e0 02          	shl    rax,0x2
    c3d1:	48 89 c7             	mov    rdi,rax
    c3d4:	e8 a7 60 ff ff       	call   2480 <malloc@plt>
    c3d9:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c3dd:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c3e1:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c3e5:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c3e9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c3ed:	48 89 ce             	mov    rsi,rcx
    c3f0:	48 89 c7             	mov    rdi,rax
    c3f3:	e8 b8 60 ff ff       	call   24b0 <COPY_ARRAY_TYPE_FLOAT@plt>
    c3f8:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    c3fc:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c400:	48 8b 15 b9 4b 00 00 	mov    rdx,QWORD PTR [rip+0x4bb9]        # 10fc0 <COMPARE_N_TYPE_FLOAT@Base>
    c407:	48 89 d1             	mov    rcx,rdx
    c40a:	ba 04 00 00 00       	mov    edx,0x4
    c40f:	48 89 c7             	mov    rdi,rax
    c412:	e8 79 5f ff ff       	call   2390 <qsort@plt>
    c417:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    c41e:	00 
    c41f:	eb 05                	jmp    c426 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0xbd>
    c421:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    c426:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    c42a:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c42e:	72 f1                	jb     c421 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0xb8>
    c430:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    c437:	00 
    c438:	eb 6f                	jmp    c4a9 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x140>
    c43a:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    c441:	00 
    c442:	eb 56                	jmp    c49a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x131>
    c444:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c448:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
    c44f:	00 
    c450:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c454:	48 01 c2             	add    rdx,rax
    c457:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c45b:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c45f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c463:	48 c1 e0 02          	shl    rax,0x2
    c467:	48 01 c8             	add    rax,rcx
    c46a:	48 89 d6             	mov    rsi,rdx
    c46d:	48 89 c7             	mov    rdi,rax
    c470:	e8 3b 5e ff ff       	call   22b0 <COMPARE_N_TYPE_FLOAT@plt>
    c475:	85 c0                	test   eax,eax
    c477:	75 1c                	jne    c495 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x12c>
    c479:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c47d:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c481:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c485:	48 c1 e0 03          	shl    rax,0x3
    c489:	48 01 c2             	add    rdx,rax
    c48c:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c490:	48 89 02             	mov    QWORD PTR [rdx],rax
    c493:	eb 0f                	jmp    c4a4 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0x13b>
    c495:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    c49a:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c49e:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c4a2:	72 a0                	jb     c444 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0xdb>
    c4a4:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    c4a9:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c4ad:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c4b1:	72 87                	jb     c43a <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT+0xd1>
    c4b3:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c4b7:	48 89 c7             	mov    rdi,rax
    c4ba:	e8 71 5e ff ff       	call   2330 <free@plt>
    c4bf:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c4c3:	c9                   	leave  
    c4c4:	c3                   	ret    

000000000000c4c5 <IS_PERMUTATION_TYPE_FLOAT>:
    c4c5:	f3 0f 1e fa          	endbr64 
    c4c9:	55                   	push   rbp
    c4ca:	48 89 e5             	mov    rbp,rsp
    c4cd:	48 83 ec 20          	sub    rsp,0x20
    c4d1:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c4d5:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c4da:	75 07                	jne    c4e3 <IS_PERMUTATION_TYPE_FLOAT+0x1e>
    c4dc:	b8 00 00 00 00       	mov    eax,0x0
    c4e1:	eb 2f                	jmp    c512 <IS_PERMUTATION_TYPE_FLOAT+0x4d>
    c4e3:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c4e7:	48 89 c7             	mov    rdi,rax
    c4ea:	e8 7a fe ff ff       	call   c369 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT>
    c4ef:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c4f3:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c4f7:	48 89 c7             	mov    rdi,rax
    c4fa:	e8 1f ea ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    c4ff:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    c502:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c506:	48 89 c7             	mov    rdi,rax
    c509:	e8 22 5e ff ff       	call   2330 <free@plt>
    c50e:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    c512:	c9                   	leave  
    c513:	c3                   	ret    

000000000000c514 <signature_TYPE_FLOAT>:
    c514:	f3 0f 1e fa          	endbr64 
    c518:	55                   	push   rbp
    c519:	48 89 e5             	mov    rbp,rsp
    c51c:	48 83 ec 30          	sub    rsp,0x30
    c520:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    c524:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c528:	48 89 c7             	mov    rdi,rax
    c52b:	e8 39 fe ff ff       	call   c369 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT>
    c530:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c534:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    c53b:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    c542:	00 
    c543:	eb 69                	jmp    c5ae <signature_TYPE_FLOAT+0x9a>
    c545:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c549:	48 83 c0 01          	add    rax,0x1
    c54d:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c551:	eb 49                	jmp    c59c <signature_TYPE_FLOAT+0x88>
    c553:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c557:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c55b:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c55f:	48 c1 e0 03          	shl    rax,0x3
    c563:	48 01 d0             	add    rax,rdx
    c566:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c569:	89 c1                	mov    ecx,eax
    c56b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c56f:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c573:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c577:	48 c1 e0 03          	shl    rax,0x3
    c57b:	48 01 d0             	add    rax,rdx
    c57e:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c581:	89 c2                	mov    edx,eax
    c583:	89 c8                	mov    eax,ecx
    c585:	29 d0                	sub    eax,edx
    c587:	89 c7                	mov    edi,eax
    c589:	e8 c3 ea ff ff       	call   b051 <sign>
    c58e:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    c591:	0f af c2             	imul   eax,edx
    c594:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    c597:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    c59c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c5a0:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c5a3:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    c5a7:	72 aa                	jb     c553 <signature_TYPE_FLOAT+0x3f>
    c5a9:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    c5ae:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c5b2:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c5b5:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    c5b9:	72 8a                	jb     c545 <signature_TYPE_FLOAT+0x31>
    c5bb:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    c5be:	c9                   	leave  
    c5bf:	c3                   	ret    

000000000000c5c0 <CREATE_PERMUTATION_TYPE_DOUBLE>:
    c5c0:	f3 0f 1e fa          	endbr64 
    c5c4:	55                   	push   rbp
    c5c5:	48 89 e5             	mov    rbp,rsp
    c5c8:	48 83 ec 20          	sub    rsp,0x20
    c5cc:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c5d0:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c5d5:	75 07                	jne    c5de <CREATE_PERMUTATION_TYPE_DOUBLE+0x1e>
    c5d7:	b8 00 00 00 00       	mov    eax,0x0
    c5dc:	eb 38                	jmp    c616 <CREATE_PERMUTATION_TYPE_DOUBLE+0x56>
    c5de:	bf 18 00 00 00       	mov    edi,0x18
    c5e3:	e8 98 5e ff ff       	call   2480 <malloc@plt>
    c5e8:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c5ec:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c5f0:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    c5f4:	48 89 10             	mov    QWORD PTR [rax],rdx
    c5f7:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c5fb:	48 c1 e0 03          	shl    rax,0x3
    c5ff:	48 89 c7             	mov    rdi,rax
    c602:	e8 79 5e ff ff       	call   2480 <malloc@plt>
    c607:	48 89 c2             	mov    rdx,rax
    c60a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c60e:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c612:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c616:	c9                   	leave  
    c617:	c3                   	ret    

000000000000c618 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE>:
    c618:	f3 0f 1e fa          	endbr64 
    c61c:	55                   	push   rbp
    c61d:	48 89 e5             	mov    rbp,rsp
    c620:	48 83 ec 40          	sub    rsp,0x40
    c624:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    c628:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    c62d:	75 0a                	jne    c639 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x21>
    c62f:	b8 00 00 00 00       	mov    eax,0x0
    c634:	e9 39 01 00 00       	jmp    c772 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x15a>
    c639:	bf 18 00 00 00       	mov    edi,0x18
    c63e:	e8 3d 5e ff ff       	call   2480 <malloc@plt>
    c643:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    c647:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c64b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c64e:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c652:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c656:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c65a:	48 89 10             	mov    QWORD PTR [rax],rdx
    c65d:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c661:	48 c1 e0 03          	shl    rax,0x3
    c665:	48 89 c7             	mov    rdi,rax
    c668:	e8 13 5e ff ff       	call   2480 <malloc@plt>
    c66d:	48 89 c2             	mov    rdx,rax
    c670:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c674:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c678:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c67c:	48 c1 e0 03          	shl    rax,0x3
    c680:	48 89 c7             	mov    rdi,rax
    c683:	e8 f8 5d ff ff       	call   2480 <malloc@plt>
    c688:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c68c:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c690:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c694:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c698:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c69c:	48 89 ce             	mov    rsi,rcx
    c69f:	48 89 c7             	mov    rdi,rax
    c6a2:	e8 f9 5c ff ff       	call   23a0 <COPY_ARRAY_TYPE_DOUBLE@plt>
    c6a7:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    c6ab:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c6af:	48 8b 15 32 49 00 00 	mov    rdx,QWORD PTR [rip+0x4932]        # 10fe8 <COMPARE_N_TYPE_DOUBLE@Base>
    c6b6:	48 89 d1             	mov    rcx,rdx
    c6b9:	ba 08 00 00 00       	mov    edx,0x8
    c6be:	48 89 c7             	mov    rdi,rax
    c6c1:	e8 ca 5c ff ff       	call   2390 <qsort@plt>
    c6c6:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    c6cd:	00 
    c6ce:	eb 05                	jmp    c6d5 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0xbd>
    c6d0:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    c6d5:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    c6d9:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c6dd:	72 f1                	jb     c6d0 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0xb8>
    c6df:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    c6e6:	00 
    c6e7:	eb 6f                	jmp    c758 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x140>
    c6e9:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    c6f0:	00 
    c6f1:	eb 56                	jmp    c749 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x131>
    c6f3:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c6f7:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    c6fe:	00 
    c6ff:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c703:	48 01 c2             	add    rdx,rax
    c706:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c70a:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c70e:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c712:	48 c1 e0 03          	shl    rax,0x3
    c716:	48 01 c8             	add    rax,rcx
    c719:	48 89 d6             	mov    rsi,rdx
    c71c:	48 89 c7             	mov    rdi,rax
    c71f:	e8 dc 5b ff ff       	call   2300 <COMPARE_N_TYPE_DOUBLE@plt>
    c724:	85 c0                	test   eax,eax
    c726:	75 1c                	jne    c744 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x12c>
    c728:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c72c:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c730:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c734:	48 c1 e0 03          	shl    rax,0x3
    c738:	48 01 c2             	add    rdx,rax
    c73b:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c73f:	48 89 02             	mov    QWORD PTR [rdx],rax
    c742:	eb 0f                	jmp    c753 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0x13b>
    c744:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    c749:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c74d:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c751:	72 a0                	jb     c6f3 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0xdb>
    c753:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    c758:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c75c:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c760:	72 87                	jb     c6e9 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE+0xd1>
    c762:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c766:	48 89 c7             	mov    rdi,rax
    c769:	e8 c2 5b ff ff       	call   2330 <free@plt>
    c76e:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c772:	c9                   	leave  
    c773:	c3                   	ret    

000000000000c774 <IS_PERMUTATION_TYPE_DOUBLE>:
    c774:	f3 0f 1e fa          	endbr64 
    c778:	55                   	push   rbp
    c779:	48 89 e5             	mov    rbp,rsp
    c77c:	48 83 ec 20          	sub    rsp,0x20
    c780:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c784:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c789:	75 07                	jne    c792 <IS_PERMUTATION_TYPE_DOUBLE+0x1e>
    c78b:	b8 00 00 00 00       	mov    eax,0x0
    c790:	eb 2f                	jmp    c7c1 <IS_PERMUTATION_TYPE_DOUBLE+0x4d>
    c792:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c796:	48 89 c7             	mov    rdi,rax
    c799:	e8 7a fe ff ff       	call   c618 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE>
    c79e:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c7a2:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c7a6:	48 89 c7             	mov    rdi,rax
    c7a9:	e8 70 e7 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    c7ae:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    c7b1:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c7b5:	48 89 c7             	mov    rdi,rax
    c7b8:	e8 73 5b ff ff       	call   2330 <free@plt>
    c7bd:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    c7c1:	c9                   	leave  
    c7c2:	c3                   	ret    

000000000000c7c3 <signature_TYPE_DOUBLE>:
    c7c3:	f3 0f 1e fa          	endbr64 
    c7c7:	55                   	push   rbp
    c7c8:	48 89 e5             	mov    rbp,rsp
    c7cb:	48 83 ec 30          	sub    rsp,0x30
    c7cf:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    c7d3:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c7d7:	48 89 c7             	mov    rdi,rax
    c7da:	e8 39 fe ff ff       	call   c618 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_DOUBLE>
    c7df:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c7e3:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    c7ea:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    c7f1:	00 
    c7f2:	eb 69                	jmp    c85d <signature_TYPE_DOUBLE+0x9a>
    c7f4:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c7f8:	48 83 c0 01          	add    rax,0x1
    c7fc:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c800:	eb 49                	jmp    c84b <signature_TYPE_DOUBLE+0x88>
    c802:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c806:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c80a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c80e:	48 c1 e0 03          	shl    rax,0x3
    c812:	48 01 d0             	add    rax,rdx
    c815:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c818:	89 c1                	mov    ecx,eax
    c81a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c81e:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c822:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c826:	48 c1 e0 03          	shl    rax,0x3
    c82a:	48 01 d0             	add    rax,rdx
    c82d:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c830:	89 c2                	mov    edx,eax
    c832:	89 c8                	mov    eax,ecx
    c834:	29 d0                	sub    eax,edx
    c836:	89 c7                	mov    edi,eax
    c838:	e8 14 e8 ff ff       	call   b051 <sign>
    c83d:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    c840:	0f af c2             	imul   eax,edx
    c843:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    c846:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    c84b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c84f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c852:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    c856:	72 aa                	jb     c802 <signature_TYPE_DOUBLE+0x3f>
    c858:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    c85d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c861:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c864:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    c868:	72 8a                	jb     c7f4 <signature_TYPE_DOUBLE+0x31>
    c86a:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    c86d:	c9                   	leave  
    c86e:	c3                   	ret    

000000000000c86f <CREATE_PERMUTATION_TYPE_L_DOUBLE>:
    c86f:	f3 0f 1e fa          	endbr64 
    c873:	55                   	push   rbp
    c874:	48 89 e5             	mov    rbp,rsp
    c877:	48 83 ec 20          	sub    rsp,0x20
    c87b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    c87f:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    c884:	75 07                	jne    c88d <CREATE_PERMUTATION_TYPE_L_DOUBLE+0x1e>
    c886:	b8 00 00 00 00       	mov    eax,0x0
    c88b:	eb 38                	jmp    c8c5 <CREATE_PERMUTATION_TYPE_L_DOUBLE+0x56>
    c88d:	bf 18 00 00 00       	mov    edi,0x18
    c892:	e8 e9 5b ff ff       	call   2480 <malloc@plt>
    c897:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c89b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c89f:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    c8a3:	48 89 10             	mov    QWORD PTR [rax],rdx
    c8a6:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c8aa:	48 c1 e0 04          	shl    rax,0x4
    c8ae:	48 89 c7             	mov    rdi,rax
    c8b1:	e8 ca 5b ff ff       	call   2480 <malloc@plt>
    c8b6:	48 89 c2             	mov    rdx,rax
    c8b9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c8bd:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c8c1:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c8c5:	c9                   	leave  
    c8c6:	c3                   	ret    

000000000000c8c7 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE>:
    c8c7:	f3 0f 1e fa          	endbr64 
    c8cb:	55                   	push   rbp
    c8cc:	48 89 e5             	mov    rbp,rsp
    c8cf:	48 83 ec 40          	sub    rsp,0x40
    c8d3:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    c8d7:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    c8dc:	75 0a                	jne    c8e8 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x21>
    c8de:	b8 00 00 00 00       	mov    eax,0x0
    c8e3:	e9 38 01 00 00       	jmp    ca20 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x159>
    c8e8:	bf 18 00 00 00       	mov    edi,0x18
    c8ed:	e8 8e 5b ff ff       	call   2480 <malloc@plt>
    c8f2:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    c8f6:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c8fa:	48 8b 00             	mov    rax,QWORD PTR [rax]
    c8fd:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    c901:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c905:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c909:	48 89 10             	mov    QWORD PTR [rax],rdx
    c90c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c910:	48 c1 e0 03          	shl    rax,0x3
    c914:	48 89 c7             	mov    rdi,rax
    c917:	e8 64 5b ff ff       	call   2480 <malloc@plt>
    c91c:	48 89 c2             	mov    rdx,rax
    c91f:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c923:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    c927:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    c92b:	48 c1 e0 04          	shl    rax,0x4
    c92f:	48 89 c7             	mov    rdi,rax
    c932:	e8 49 5b ff ff       	call   2480 <malloc@plt>
    c937:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    c93b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c93f:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c943:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    c947:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c94b:	48 89 ce             	mov    rsi,rcx
    c94e:	48 89 c7             	mov    rdi,rax
    c951:	e8 ba 5b ff ff       	call   2510 <COPY_ARRAY_TYPE_L_DOUBLE@plt>
    c956:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    c95a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c95e:	48 8b 15 3b 46 00 00 	mov    rdx,QWORD PTR [rip+0x463b]        # 10fa0 <COMPARE_N_TYPE_L_DOUBLE@Base>
    c965:	48 89 d1             	mov    rcx,rdx
    c968:	ba 10 00 00 00       	mov    edx,0x10
    c96d:	48 89 c7             	mov    rdi,rax
    c970:	e8 1b 5a ff ff       	call   2390 <qsort@plt>
    c975:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    c97c:	00 
    c97d:	eb 05                	jmp    c984 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0xbd>
    c97f:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    c984:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    c988:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c98c:	72 f1                	jb     c97f <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0xb8>
    c98e:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    c995:	00 
    c996:	eb 6e                	jmp    ca06 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x13f>
    c998:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    c99f:	00 
    c9a0:	eb 55                	jmp    c9f7 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x130>
    c9a2:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c9a6:	48 c1 e0 04          	shl    rax,0x4
    c9aa:	48 89 c2             	mov    rdx,rax
    c9ad:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    c9b1:	48 01 c2             	add    rdx,rax
    c9b4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    c9b8:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    c9bc:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c9c0:	48 c1 e0 04          	shl    rax,0x4
    c9c4:	48 01 c8             	add    rax,rcx
    c9c7:	48 89 d6             	mov    rsi,rdx
    c9ca:	48 89 c7             	mov    rdi,rax
    c9cd:	e8 ae 58 ff ff       	call   2280 <COMPARE_N_TYPE_L_DOUBLE@plt>
    c9d2:	85 c0                	test   eax,eax
    c9d4:	75 1c                	jne    c9f2 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x12b>
    c9d6:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    c9da:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    c9de:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    c9e2:	48 c1 e0 03          	shl    rax,0x3
    c9e6:	48 01 c2             	add    rdx,rax
    c9e9:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c9ed:	48 89 02             	mov    QWORD PTR [rdx],rax
    c9f0:	eb 0f                	jmp    ca01 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0x13a>
    c9f2:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    c9f7:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    c9fb:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    c9ff:	72 a1                	jb     c9a2 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0xdb>
    ca01:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    ca06:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    ca0a:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    ca0e:	72 88                	jb     c998 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE+0xd1>
    ca10:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ca14:	48 89 c7             	mov    rdi,rax
    ca17:	e8 14 59 ff ff       	call   2330 <free@plt>
    ca1c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ca20:	c9                   	leave  
    ca21:	c3                   	ret    

000000000000ca22 <IS_PERMUTATION_TYPE_L_DOUBLE>:
    ca22:	f3 0f 1e fa          	endbr64 
    ca26:	55                   	push   rbp
    ca27:	48 89 e5             	mov    rbp,rsp
    ca2a:	48 83 ec 20          	sub    rsp,0x20
    ca2e:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    ca32:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    ca37:	75 07                	jne    ca40 <IS_PERMUTATION_TYPE_L_DOUBLE+0x1e>
    ca39:	b8 00 00 00 00       	mov    eax,0x0
    ca3e:	eb 2f                	jmp    ca6f <IS_PERMUTATION_TYPE_L_DOUBLE+0x4d>
    ca40:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ca44:	48 89 c7             	mov    rdi,rax
    ca47:	e8 7b fe ff ff       	call   c8c7 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE>
    ca4c:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ca50:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ca54:	48 89 c7             	mov    rdi,rax
    ca57:	e8 c2 e4 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    ca5c:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    ca5f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ca63:	48 89 c7             	mov    rdi,rax
    ca66:	e8 c5 58 ff ff       	call   2330 <free@plt>
    ca6b:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    ca6f:	c9                   	leave  
    ca70:	c3                   	ret    

000000000000ca71 <signature_TYPE_L_DOUBLE>:
    ca71:	f3 0f 1e fa          	endbr64 
    ca75:	55                   	push   rbp
    ca76:	48 89 e5             	mov    rbp,rsp
    ca79:	48 83 ec 30          	sub    rsp,0x30
    ca7d:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    ca81:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    ca85:	48 89 c7             	mov    rdi,rax
    ca88:	e8 3a fe ff ff       	call   c8c7 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_L_DOUBLE>
    ca8d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ca91:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    ca98:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    ca9f:	00 
    caa0:	eb 69                	jmp    cb0b <signature_TYPE_L_DOUBLE+0x9a>
    caa2:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    caa6:	48 83 c0 01          	add    rax,0x1
    caaa:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    caae:	eb 49                	jmp    caf9 <signature_TYPE_L_DOUBLE+0x88>
    cab0:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cab4:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    cab8:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cabc:	48 c1 e0 03          	shl    rax,0x3
    cac0:	48 01 d0             	add    rax,rdx
    cac3:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cac6:	89 c1                	mov    ecx,eax
    cac8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cacc:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    cad0:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cad4:	48 c1 e0 03          	shl    rax,0x3
    cad8:	48 01 d0             	add    rax,rdx
    cadb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cade:	89 c2                	mov    edx,eax
    cae0:	89 c8                	mov    eax,ecx
    cae2:	29 d0                	sub    eax,edx
    cae4:	89 c7                	mov    edi,eax
    cae6:	e8 66 e5 ff ff       	call   b051 <sign>
    caeb:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    caee:	0f af c2             	imul   eax,edx
    caf1:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    caf4:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    caf9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cafd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cb00:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    cb04:	72 aa                	jb     cab0 <signature_TYPE_L_DOUBLE+0x3f>
    cb06:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    cb0b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cb0f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cb12:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    cb16:	72 8a                	jb     caa2 <signature_TYPE_L_DOUBLE+0x31>
    cb18:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    cb1b:	c9                   	leave  
    cb1c:	c3                   	ret    

000000000000cb1d <CREATE_PERMUTATION_TYPE_STRING>:
    cb1d:	f3 0f 1e fa          	endbr64 
    cb21:	55                   	push   rbp
    cb22:	48 89 e5             	mov    rbp,rsp
    cb25:	48 83 ec 20          	sub    rsp,0x20
    cb29:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cb2d:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    cb32:	75 07                	jne    cb3b <CREATE_PERMUTATION_TYPE_STRING+0x1e>
    cb34:	b8 00 00 00 00       	mov    eax,0x0
    cb39:	eb 38                	jmp    cb73 <CREATE_PERMUTATION_TYPE_STRING+0x56>
    cb3b:	bf 18 00 00 00       	mov    edi,0x18
    cb40:	e8 3b 59 ff ff       	call   2480 <malloc@plt>
    cb45:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    cb49:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cb4d:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    cb51:	48 89 10             	mov    QWORD PTR [rax],rdx
    cb54:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cb58:	48 c1 e0 03          	shl    rax,0x3
    cb5c:	48 89 c7             	mov    rdi,rax
    cb5f:	e8 1c 59 ff ff       	call   2480 <malloc@plt>
    cb64:	48 89 c2             	mov    rdx,rax
    cb67:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cb6b:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    cb6f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cb73:	c9                   	leave  
    cb74:	c3                   	ret    

000000000000cb75 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING>:
    cb75:	f3 0f 1e fa          	endbr64 
    cb79:	55                   	push   rbp
    cb7a:	48 89 e5             	mov    rbp,rsp
    cb7d:	48 83 ec 40          	sub    rsp,0x40
    cb81:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
    cb85:	48 83 7d c8 00       	cmp    QWORD PTR [rbp-0x38],0x0
    cb8a:	75 0a                	jne    cb96 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x21>
    cb8c:	b8 00 00 00 00       	mov    eax,0x0
    cb91:	e9 39 01 00 00       	jmp    cccf <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x15a>
    cb96:	bf 18 00 00 00       	mov    edi,0x18
    cb9b:	e8 e0 58 ff ff       	call   2480 <malloc@plt>
    cba0:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
    cba4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    cba8:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cbab:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    cbaf:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cbb3:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    cbb7:	48 89 10             	mov    QWORD PTR [rax],rdx
    cbba:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cbbe:	48 c1 e0 03          	shl    rax,0x3
    cbc2:	48 89 c7             	mov    rdi,rax
    cbc5:	e8 b6 58 ff ff       	call   2480 <malloc@plt>
    cbca:	48 89 c2             	mov    rdx,rax
    cbcd:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cbd1:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    cbd5:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cbd9:	48 c1 e0 03          	shl    rax,0x3
    cbdd:	48 89 c7             	mov    rdi,rax
    cbe0:	e8 9b 58 ff ff       	call   2480 <malloc@plt>
    cbe5:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    cbe9:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    cbed:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    cbf1:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
    cbf5:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cbf9:	48 89 ce             	mov    rsi,rcx
    cbfc:	48 89 c7             	mov    rdi,rax
    cbff:	e8 9c 58 ff ff       	call   24a0 <COPY_ARRAY_TYPE_STRING@plt>
    cc04:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    cc08:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cc0c:	48 8b 15 bd 43 00 00 	mov    rdx,QWORD PTR [rip+0x43bd]        # 10fd0 <COMPARE_N_TYPE_STRING@Base>
    cc13:	48 89 d1             	mov    rcx,rdx
    cc16:	ba 08 00 00 00       	mov    edx,0x8
    cc1b:	48 89 c7             	mov    rdi,rax
    cc1e:	e8 6d 57 ff ff       	call   2390 <qsort@plt>
    cc23:	48 c7 45 d0 00 00 00 	mov    QWORD PTR [rbp-0x30],0x0
    cc2a:	00 
    cc2b:	eb 05                	jmp    cc32 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0xbd>
    cc2d:	48 83 45 d0 01       	add    QWORD PTR [rbp-0x30],0x1
    cc32:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
    cc36:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    cc3a:	72 f1                	jb     cc2d <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0xb8>
    cc3c:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
    cc43:	00 
    cc44:	eb 6f                	jmp    ccb5 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x140>
    cc46:	48 c7 45 e0 00 00 00 	mov    QWORD PTR [rbp-0x20],0x0
    cc4d:	00 
    cc4e:	eb 56                	jmp    cca6 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x131>
    cc50:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    cc54:	48 8d 14 c5 00 00 00 	lea    rdx,[rax*8+0x0]
    cc5b:	00 
    cc5c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cc60:	48 01 c2             	add    rdx,rax
    cc63:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
    cc67:	48 8b 48 10          	mov    rcx,QWORD PTR [rax+0x10]
    cc6b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    cc6f:	48 c1 e0 03          	shl    rax,0x3
    cc73:	48 01 c8             	add    rax,rcx
    cc76:	48 89 d6             	mov    rsi,rdx
    cc79:	48 89 c7             	mov    rdi,rax
    cc7c:	e8 4f 56 ff ff       	call   22d0 <COMPARE_N_TYPE_STRING@plt>
    cc81:	85 c0                	test   eax,eax
    cc83:	75 1c                	jne    cca1 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x12c>
    cc85:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cc89:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    cc8d:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    cc91:	48 c1 e0 03          	shl    rax,0x3
    cc95:	48 01 c2             	add    rdx,rax
    cc98:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    cc9c:	48 89 02             	mov    QWORD PTR [rdx],rax
    cc9f:	eb 0f                	jmp    ccb0 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0x13b>
    cca1:	48 83 45 e0 01       	add    QWORD PTR [rbp-0x20],0x1
    cca6:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    ccaa:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    ccae:	72 a0                	jb     cc50 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0xdb>
    ccb0:	48 83 45 d8 01       	add    QWORD PTR [rbp-0x28],0x1
    ccb5:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    ccb9:	48 3b 45 f0          	cmp    rax,QWORD PTR [rbp-0x10]
    ccbd:	72 87                	jb     cc46 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING+0xd1>
    ccbf:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ccc3:	48 89 c7             	mov    rdi,rax
    ccc6:	e8 65 56 ff ff       	call   2330 <free@plt>
    cccb:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cccf:	c9                   	leave  
    ccd0:	c3                   	ret    

000000000000ccd1 <IS_PERMUTATION_TYPE_STRING>:
    ccd1:	f3 0f 1e fa          	endbr64 
    ccd5:	55                   	push   rbp
    ccd6:	48 89 e5             	mov    rbp,rsp
    ccd9:	48 83 ec 20          	sub    rsp,0x20
    ccdd:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cce1:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    cce6:	75 07                	jne    ccef <IS_PERMUTATION_TYPE_STRING+0x1e>
    cce8:	b8 00 00 00 00       	mov    eax,0x0
    cced:	eb 2f                	jmp    cd1e <IS_PERMUTATION_TYPE_STRING+0x4d>
    ccef:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ccf3:	48 89 c7             	mov    rdi,rax
    ccf6:	e8 7a fe ff ff       	call   cb75 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING>
    ccfb:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ccff:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cd03:	48 89 c7             	mov    rdi,rax
    cd06:	e8 13 e2 ff ff       	call   af1e <IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T>
    cd0b:	88 45 f7             	mov    BYTE PTR [rbp-0x9],al
    cd0e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cd12:	48 89 c7             	mov    rdi,rax
    cd15:	e8 16 56 ff ff       	call   2330 <free@plt>
    cd1a:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    cd1e:	c9                   	leave  
    cd1f:	c3                   	ret    

000000000000cd20 <signature_TYPE_STRING>:
    cd20:	f3 0f 1e fa          	endbr64 
    cd24:	55                   	push   rbp
    cd25:	48 89 e5             	mov    rbp,rsp
    cd28:	48 83 ec 30          	sub    rsp,0x30
    cd2c:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
    cd30:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
    cd34:	48 89 c7             	mov    rdi,rax
    cd37:	e8 39 fe ff ff       	call   cb75 <TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_STRING>
    cd3c:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    cd40:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x1
    cd47:	48 c7 45 e8 00 00 00 	mov    QWORD PTR [rbp-0x18],0x0
    cd4e:	00 
    cd4f:	eb 69                	jmp    cdba <signature_TYPE_STRING+0x9a>
    cd51:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cd55:	48 83 c0 01          	add    rax,0x1
    cd59:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    cd5d:	eb 49                	jmp    cda8 <signature_TYPE_STRING+0x88>
    cd5f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cd63:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    cd67:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cd6b:	48 c1 e0 03          	shl    rax,0x3
    cd6f:	48 01 d0             	add    rax,rdx
    cd72:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cd75:	89 c1                	mov    ecx,eax
    cd77:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cd7b:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
    cd7f:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cd83:	48 c1 e0 03          	shl    rax,0x3
    cd87:	48 01 d0             	add    rax,rdx
    cd8a:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cd8d:	89 c2                	mov    edx,eax
    cd8f:	89 c8                	mov    eax,ecx
    cd91:	29 d0                	sub    eax,edx
    cd93:	89 c7                	mov    edi,eax
    cd95:	e8 b7 e2 ff ff       	call   b051 <sign>
    cd9a:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
    cd9d:	0f af c2             	imul   eax,edx
    cda0:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
    cda3:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    cda8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cdac:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cdaf:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
    cdb3:	72 aa                	jb     cd5f <signature_TYPE_STRING+0x3f>
    cdb5:	48 83 45 e8 01       	add    QWORD PTR [rbp-0x18],0x1
    cdba:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cdbe:	48 8b 00             	mov    rax,QWORD PTR [rax]
    cdc1:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    cdc5:	72 8a                	jb     cd51 <signature_TYPE_STRING+0x31>
    cdc7:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
    cdca:	c9                   	leave  
    cdcb:	c3                   	ret    

000000000000cdcc <CREATE_SET_THEORIC_TYPE_U_CHAR>:
    cdcc:	f3 0f 1e fa          	endbr64 
    cdd0:	55                   	push   rbp
    cdd1:	48 89 e5             	mov    rbp,rsp
    cdd4:	48 83 ec 20          	sub    rsp,0x20
    cdd8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cddc:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    cde1:	75 07                	jne    cdea <CREATE_SET_THEORIC_TYPE_U_CHAR+0x1e>
    cde3:	b8 00 00 00 00       	mov    eax,0x0
    cde8:	eb 5e                	jmp    ce48 <CREATE_SET_THEORIC_TYPE_U_CHAR+0x7c>
    cdea:	bf 10 00 00 00       	mov    edi,0x10
    cdef:	e8 8c 56 ff ff       	call   2480 <malloc@plt>
    cdf4:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    cdf8:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cdfc:	89 c2                	mov    edx,eax
    cdfe:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ce02:	88 10                	mov    BYTE PTR [rax],dl
    ce04:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ce08:	48 89 c7             	mov    rdi,rax
    ce0b:	e8 70 56 ff ff       	call   2480 <malloc@plt>
    ce10:	48 89 c2             	mov    rdx,rax
    ce13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ce17:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
    ce1b:	c6 45 f7 00          	mov    BYTE PTR [rbp-0x9],0x0
    ce1f:	eb 19                	jmp    ce3a <CREATE_SET_THEORIC_TYPE_U_CHAR+0x6e>
    ce21:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ce25:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    ce29:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    ce2d:	48 01 c2             	add    rdx,rax
    ce30:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    ce34:	88 02                	mov    BYTE PTR [rdx],al
    ce36:	80 45 f7 01          	add    BYTE PTR [rbp-0x9],0x1
    ce3a:	0f b6 45 f7          	movzx  eax,BYTE PTR [rbp-0x9]
    ce3e:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    ce42:	77 dd                	ja     ce21 <CREATE_SET_THEORIC_TYPE_U_CHAR+0x55>
    ce44:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ce48:	c9                   	leave  
    ce49:	c3                   	ret    

000000000000ce4a <IS_SET_THEORIC_TYPE_U_CHAR>:
    ce4a:	f3 0f 1e fa          	endbr64 
    ce4e:	55                   	push   rbp
    ce4f:	48 89 e5             	mov    rbp,rsp
    ce52:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    ce56:	c6 45 ff 00          	mov    BYTE PTR [rbp-0x1],0x0
    ce5a:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ce5e:	0f b6 00             	movzx  eax,BYTE PTR [rax]
    ce61:	38 45 ff             	cmp    BYTE PTR [rbp-0x1],al
    ce64:	73 25                	jae    ce8b <IS_SET_THEORIC_TYPE_U_CHAR+0x41>
    ce66:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    ce6a:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    ce6e:	0f b6 45 ff          	movzx  eax,BYTE PTR [rbp-0x1]
    ce72:	48 01 d0             	add    rax,rdx
    ce75:	0f b6 00             	movzx  eax,BYTE PTR [rax]
    ce78:	38 45 ff             	cmp    BYTE PTR [rbp-0x1],al
    ce7b:	74 07                	je     ce84 <IS_SET_THEORIC_TYPE_U_CHAR+0x3a>
    ce7d:	b8 00 00 00 00       	mov    eax,0x0
    ce82:	eb 07                	jmp    ce8b <IS_SET_THEORIC_TYPE_U_CHAR+0x41>
    ce84:	b8 01 00 00 00       	mov    eax,0x1
    ce89:	eb 00                	jmp    ce8b <IS_SET_THEORIC_TYPE_U_CHAR+0x41>
    ce8b:	5d                   	pop    rbp
    ce8c:	c3                   	ret    

000000000000ce8d <CREATE_SET_THEORIC_TYPE_U_INT>:
    ce8d:	f3 0f 1e fa          	endbr64 
    ce91:	55                   	push   rbp
    ce92:	48 89 e5             	mov    rbp,rsp
    ce95:	48 83 ec 20          	sub    rsp,0x20
    ce99:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    ce9d:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    cea2:	75 07                	jne    ceab <CREATE_SET_THEORIC_TYPE_U_INT+0x1e>
    cea4:	b8 00 00 00 00       	mov    eax,0x0
    cea9:	eb 66                	jmp    cf11 <CREATE_SET_THEORIC_TYPE_U_INT+0x84>
    ceab:	bf 10 00 00 00       	mov    edi,0x10
    ceb0:	e8 cb 55 ff ff       	call   2480 <malloc@plt>
    ceb5:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    ceb9:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cebd:	89 c2                	mov    edx,eax
    cebf:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cec3:	89 10                	mov    DWORD PTR [rax],edx
    cec5:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cec9:	48 c1 e0 02          	shl    rax,0x2
    cecd:	48 89 c7             	mov    rdi,rax
    ced0:	e8 ab 55 ff ff       	call   2480 <malloc@plt>
    ced5:	48 89 c2             	mov    rdx,rax
    ced8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cedc:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
    cee0:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [rbp-0xc],0x0
    cee7:	eb 1b                	jmp    cf04 <CREATE_SET_THEORIC_TYPE_U_INT+0x77>
    cee9:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    ceed:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    cef1:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
    cef4:	48 c1 e0 02          	shl    rax,0x2
    cef8:	48 01 c2             	add    rdx,rax
    cefb:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
    cefe:	89 02                	mov    DWORD PTR [rdx],eax
    cf00:	83 45 f4 01          	add    DWORD PTR [rbp-0xc],0x1
    cf04:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
    cf07:	48 39 45 e8          	cmp    QWORD PTR [rbp-0x18],rax
    cf0b:	77 dc                	ja     cee9 <CREATE_SET_THEORIC_TYPE_U_INT+0x5c>
    cf0d:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cf11:	c9                   	leave  
    cf12:	c3                   	ret    

000000000000cf13 <IS_SET_THEORIC_TYPE_U_INT>:
    cf13:	f3 0f 1e fa          	endbr64 
    cf17:	55                   	push   rbp
    cf18:	48 89 e5             	mov    rbp,rsp
    cf1b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cf1f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [rbp-0x4],0x0
    cf26:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cf2a:	8b 00                	mov    eax,DWORD PTR [rax]
    cf2c:	39 45 fc             	cmp    DWORD PTR [rbp-0x4],eax
    cf2f:	73 27                	jae    cf58 <IS_SET_THEORIC_TYPE_U_INT+0x45>
    cf31:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cf35:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    cf39:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
    cf3c:	48 c1 e0 02          	shl    rax,0x2
    cf40:	48 01 d0             	add    rax,rdx
    cf43:	8b 00                	mov    eax,DWORD PTR [rax]
    cf45:	39 45 fc             	cmp    DWORD PTR [rbp-0x4],eax
    cf48:	74 07                	je     cf51 <IS_SET_THEORIC_TYPE_U_INT+0x3e>
    cf4a:	b8 00 00 00 00       	mov    eax,0x0
    cf4f:	eb 07                	jmp    cf58 <IS_SET_THEORIC_TYPE_U_INT+0x45>
    cf51:	b8 01 00 00 00       	mov    eax,0x1
    cf56:	eb 00                	jmp    cf58 <IS_SET_THEORIC_TYPE_U_INT+0x45>
    cf58:	5d                   	pop    rbp
    cf59:	c3                   	ret    

000000000000cf5a <CREATE_SET_THEORIC_TYPE_U_L_INT>:
    cf5a:	f3 0f 1e fa          	endbr64 
    cf5e:	55                   	push   rbp
    cf5f:	48 89 e5             	mov    rbp,rsp
    cf62:	48 83 ec 20          	sub    rsp,0x20
    cf66:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cf6a:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    cf6f:	75 07                	jne    cf78 <CREATE_SET_THEORIC_TYPE_U_L_INT+0x1e>
    cf71:	b8 00 00 00 00       	mov    eax,0x0
    cf76:	eb 6b                	jmp    cfe3 <CREATE_SET_THEORIC_TYPE_U_L_INT+0x89>
    cf78:	bf 10 00 00 00       	mov    edi,0x10
    cf7d:	e8 fe 54 ff ff       	call   2480 <malloc@plt>
    cf82:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    cf86:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cf8a:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    cf8e:	48 89 10             	mov    QWORD PTR [rax],rdx
    cf91:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cf95:	48 c1 e0 03          	shl    rax,0x3
    cf99:	48 89 c7             	mov    rdi,rax
    cf9c:	e8 df 54 ff ff       	call   2480 <malloc@plt>
    cfa1:	48 89 c2             	mov    rdx,rax
    cfa4:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cfa8:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
    cfac:	48 c7 45 f0 00 00 00 	mov    QWORD PTR [rbp-0x10],0x0
    cfb3:	00 
    cfb4:	eb 1f                	jmp    cfd5 <CREATE_SET_THEORIC_TYPE_U_L_INT+0x7b>
    cfb6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cfba:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    cfbe:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cfc2:	48 c1 e0 03          	shl    rax,0x3
    cfc6:	48 01 c2             	add    rdx,rax
    cfc9:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cfcd:	48 89 02             	mov    QWORD PTR [rdx],rax
    cfd0:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    cfd5:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    cfd9:	48 3b 45 e8          	cmp    rax,QWORD PTR [rbp-0x18]
    cfdd:	72 d7                	jb     cfb6 <CREATE_SET_THEORIC_TYPE_U_L_INT+0x5c>
    cfdf:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    cfe3:	c9                   	leave  
    cfe4:	c3                   	ret    

000000000000cfe5 <IS_SET_THEORIC_TYPE_U_L_INT>:
    cfe5:	f3 0f 1e fa          	endbr64 
    cfe9:	55                   	push   rbp
    cfea:	48 89 e5             	mov    rbp,rsp
    cfed:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    cff1:	48 c7 45 f8 00 00 00 	mov    QWORD PTR [rbp-0x8],0x0
    cff8:	00 
    cff9:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    cffd:	48 8b 00             	mov    rax,QWORD PTR [rax]
    d000:	48 39 45 f8          	cmp    QWORD PTR [rbp-0x8],rax
    d004:	73 2a                	jae    d030 <IS_SET_THEORIC_TYPE_U_L_INT+0x4b>
    d006:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    d00a:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    d00e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d012:	48 c1 e0 03          	shl    rax,0x3
    d016:	48 01 d0             	add    rax,rdx
    d019:	48 8b 00             	mov    rax,QWORD PTR [rax]
    d01c:	48 39 45 f8          	cmp    QWORD PTR [rbp-0x8],rax
    d020:	74 07                	je     d029 <IS_SET_THEORIC_TYPE_U_L_INT+0x44>
    d022:	b8 00 00 00 00       	mov    eax,0x0
    d027:	eb 07                	jmp    d030 <IS_SET_THEORIC_TYPE_U_L_INT+0x4b>
    d029:	b8 01 00 00 00       	mov    eax,0x1
    d02e:	eb 00                	jmp    d030 <IS_SET_THEORIC_TYPE_U_L_INT+0x4b>
    d030:	5d                   	pop    rbp
    d031:	c3                   	ret    

000000000000d032 <CREATE_SET_THEORIC_TYPE_SIZE_T>:
    d032:	f3 0f 1e fa          	endbr64 
    d036:	55                   	push   rbp
    d037:	48 89 e5             	mov    rbp,rsp
    d03a:	48 83 ec 20          	sub    rsp,0x20
    d03e:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    d042:	48 83 7d e8 00       	cmp    QWORD PTR [rbp-0x18],0x0
    d047:	75 07                	jne    d050 <CREATE_SET_THEORIC_TYPE_SIZE_T+0x1e>
    d049:	b8 00 00 00 00       	mov    eax,0x0
    d04e:	eb 6b                	jmp    d0bb <CREATE_SET_THEORIC_TYPE_SIZE_T+0x89>
    d050:	bf 10 00 00 00       	mov    edi,0x10
    d055:	e8 26 54 ff ff       	call   2480 <malloc@plt>
    d05a:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    d05e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d062:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
    d066:	48 89 10             	mov    QWORD PTR [rax],rdx
    d069:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    d06d:	48 c1 e0 03          	shl    rax,0x3
    d071:	48 89 c7             	mov    rdi,rax
    d074:	e8 07 54 ff ff       	call   2480 <malloc@plt>
    d079:	48 89 c2             	mov    rdx,rax
    d07c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d080:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
    d084:	48 c7 45 f0 00 00 00 	mov    QWORD PTR [rbp-0x10],0x0
    d08b:	00 
    d08c:	eb 1f                	jmp    d0ad <CREATE_SET_THEORIC_TYPE_SIZE_T+0x7b>
    d08e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d092:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    d096:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    d09a:	48 c1 e0 03          	shl    rax,0x3
    d09e:	48 01 c2             	add    rdx,rax
    d0a1:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    d0a5:	48 89 02             	mov    QWORD PTR [rdx],rax
    d0a8:	48 83 45 f0 01       	add    QWORD PTR [rbp-0x10],0x1
    d0ad:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
    d0b1:	48 3b 45 e8          	cmp    rax,QWORD PTR [rbp-0x18]
    d0b5:	72 d7                	jb     d08e <CREATE_SET_THEORIC_TYPE_SIZE_T+0x5c>
    d0b7:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d0bb:	c9                   	leave  
    d0bc:	c3                   	ret    

000000000000d0bd <IS_SET_THEORIC_TYPE_SIZE_T>:
    d0bd:	f3 0f 1e fa          	endbr64 
    d0c1:	55                   	push   rbp
    d0c2:	48 89 e5             	mov    rbp,rsp
    d0c5:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
    d0c9:	48 c7 45 f8 00 00 00 	mov    QWORD PTR [rbp-0x8],0x0
    d0d0:	00 
    d0d1:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    d0d5:	48 8b 00             	mov    rax,QWORD PTR [rax]
    d0d8:	48 39 45 f8          	cmp    QWORD PTR [rbp-0x8],rax
    d0dc:	73 2a                	jae    d108 <IS_SET_THEORIC_TYPE_SIZE_T+0x4b>
    d0de:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    d0e2:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
    d0e6:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    d0ea:	48 c1 e0 03          	shl    rax,0x3
    d0ee:	48 01 d0             	add    rax,rdx
    d0f1:	48 8b 00             	mov    rax,QWORD PTR [rax]
    d0f4:	48 39 45 f8          	cmp    QWORD PTR [rbp-0x8],rax
    d0f8:	74 07                	je     d101 <IS_SET_THEORIC_TYPE_SIZE_T+0x44>
    d0fa:	b8 00 00 00 00       	mov    eax,0x0
    d0ff:	eb 07                	jmp    d108 <IS_SET_THEORIC_TYPE_SIZE_T+0x4b>
    d101:	b8 01 00 00 00       	mov    eax,0x1
    d106:	eb 00                	jmp    d108 <IS_SET_THEORIC_TYPE_SIZE_T+0x4b>
    d108:	5d                   	pop    rbp
    d109:	c3                   	ret    

Déassemblage de la section .fini :

000000000000d10c <_fini>:
    d10c:	f3 0f 1e fa          	endbr64 
    d110:	48 83 ec 08          	sub    rsp,0x8
    d114:	48 83 c4 08          	add    rsp,0x8
    d118:	c3                   	ret    
