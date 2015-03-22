main(i,s){
    for(;~scanf("%8s",s);) --i&&printf(i%4?"%d.":"%d\n",strtol(s,0,2));
}

