#include<iostream>

using namespace std;

constexpr int fact(int x)
{
    if( x == 0 ) return 1;
    return x * fact(x-1);
}

constexpr int sq(int x)
{
    return x*x;
}

int main()
{
    cout<<fact(5)<<endl;

    constexpr int p = fact(5);

    cout<<p<<endl;

    const int d = sq(10);
    cout<<d<<endl;
    return 0;
}

//Assembly code generated for main function
// Do you see call to sq(10)?
/*
2 main:
43 .LFB1460:
44         .cfi_startproc
45         pushq   %rbp
46         .cfi_def_cfa_offset 16
47         .cfi_offset 6, -16
48         movq    %rsp, %rbp
49         .cfi_def_cfa_register 6
50         subq    $16, %rsp
51         movl    $5, %edi
52         call    _Z4facti
53         movl    %eax, %esi
54         movl    $_ZSt4cout, %edi
55         call    _ZNSolsEi
56         movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
57         movq    %rax, %rdi
58         call    _ZNSolsEPFRSoS_E
59         movl    $120, -8(%rbp)
60         movl    $120, %esi
61         movl    $_ZSt4cout, %edi
62         call    _ZNSolsEi
63         movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
64         movq    %rax, %rdi
65         call    _ZNSolsEPFRSoS_E
66         movl    $100, -4(%rbp)
67         movl    $100, %esi
68         movl    $_ZSt4cout, %edi
69         call    _ZNSolsEi
70         movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
71         movq    %rax, %rdi
72         call    _ZNSolsEPFRSoS_E
73         movl    $0, %eax
74         leave
75         .cfi_def_cfa 7, 8
76         ret
77         .cfi_endproc
*/
