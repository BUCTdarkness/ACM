void Manacher(int n)
{
    int mx=0;
    int id;
    p[0]=0;
    for(int i=1;i<n;i++)
    {
        p[i]=1;
        if(mx>i)
        {
            p[i]=min(p[2*id-i],mx-i);
        }
        while(str[i-p[i]]==str[i+p[i]]) p[i]++;
        if(i+p[i]>mx)
        {
            id=i;
            mx=i+p[i];
        }
    }
}
int init()
{
    int len=0;
    strcpy(stemp,str);
    str[0]='$';
    len++;
    for(int i=0;stmp[i];i++)
    {
        str[len++]='#';
        str[len++]=stemp[i];
    }
    str[len++]='#';
    str[len]='\0';
    return len;
}

