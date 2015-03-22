char *p;r;
main(b,M,P){
    for(;~scanf("%d%s%s",&b,p=P,M)&&b;r=puts(itoa(r,P,b)))
        for(;*p;r%=strtol(M,0,b)) r=r*b+*p++%48;
}
