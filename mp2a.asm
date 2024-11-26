section .text
bits 64
default rel
global asmsaxpy

;RCX 1st param - n (int)
;RDX xmm1 2nd param - vector x address
;R8  xmm2 3rd param - vector y address
;R9  xmm3 4th param - vector z address(RESULT)
;stack 5th param - scalar a (float)
;Z[i] = (A)(X[i]) + Y[i]
asmsaxpy:
    sub rsp, 8*5        ;broke ?
    movss xmm4, [rsp+80];broke ?
    L1: 
        
        movss xmm1, [rdx]
        movss xmm2, [r8];works
        mulss xmm1, xmm4;broke ?
        addss xmm1, xmm2;works
        movss [r9], xmm1;works
        add rdx, 4
        add r8, 4       ;works
        add r9, 4       ;works
        
        loop L1
    add rsp, 8*5        ;broke ?
    
    ret