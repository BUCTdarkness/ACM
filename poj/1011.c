main(t,x,y,tmp){
    while(~scanf("%d",&t)){
        while(t--){
            double mi=0,ma=0;scanf("%d%d",&x,&y);
            for(mi=2.0*y,tmp=(x-85)*y,x=(x-69)*y;x>0;){
                if(x>15){mi+=2.0;x-=31;}
                else if(x>10){mi+=1.5;x-=15;}
                else if(x>7){mi+=1.0;x-=10;}
                else if(x>0){mi+=0.5;x-=5;}
            }
            for(ma=4.0*y;tmp<0;){
                if(tmp<-15){ma-=2.0;tmp+=25;}
                else if(tmp<-10){ma-=1.5;tmp+=15;}
                else if(tmp<-5){ma-=1.0;tmp+=10;}
                else if(tmp<0){ma-=0.5;tmp+=5;}
            }
            printf("%.4lf %.4lf\n",mi/y,ma/y);
        }
    }
    return 0;
}
