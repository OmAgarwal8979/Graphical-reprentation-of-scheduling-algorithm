#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int gd,gm,n,init,k,g,cnt,j,i,ind,l,r,x;
char c[20];
vector<int> a(100),b(101,inf);

void itoa(int n,char *c){
    vector<char> ans;
    while(n){
        ans.push_back((char)(n%10+'0'));
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        c[i]=ans[i];
    }
    // c[ans.size()]='/0';
    c[ans.size()]=NULL;
}
int sign(int a){
    if(a>0)
        return 1;
    else if(a<0)
        return -1;
    else return 0;
}
void bresenham(int x1,int y1,int x2,int y2,int col){
    int d,inc1,inc2,i,dx,dy,x,y,flag,s1,s2;
    dx=abs(x2-x1);
     dy=abs(y2-y1);
     x=x1;
     y=y1;
     s1 = sign(x2-x1);
     s2 = sign(y2-y1);
     if(dy>dx){
        swap(dx,dy);
        flag=1;
     }else flag=0;

     d = 2*dy-dx;
     inc1 = 2*dy;
     inc2 = 2*(dy-dx);
     putpixel(x,y,5);
     for(i=1;i<=dx;i++){
        if(d<0){
            if(flag==1)
                y=y+s2;
            else x = x+s1;
            d=d+inc1;
        }else{
            y=y+s2;
            x=x+s1;
            d=d+inc2;
        }
        col = 10;
        putpixel(x,y,col);
        delay(3);
     }
}
void lifo(){
    cnt=0;
    settextstyle(10,0,3);
    outtextxy(320,370,"Last In First Out");
    settextstyle(0,0,1);
    line(0,50,1000,50);
    for(k=0;k<=1000;k+=50){
        line(k,48,k,52);
        g = k/5;
        itoa(g,c);
        outtextxy(k,37,c);
    }
    bresenham(5*init,50,5*a[n-1],100,10);
    itoa(init,c);
    outtextxy((5*init),55,c);
    cnt = 100;
    for(j=n-1;j>=0;j--){
        for(i=0;i<=200;i++){
            if(a[j]==i){
                setcolor(15);
                itoa(i,c);
                fillellipse(5*i,cnt,5,5);
                if(a[j]>a[j+1]){
                    outtextxy(5*i+25,cnt,c);}
                else
                    outtextxy(5*i-30,cnt,c);
                if(j>0)
                    bresenham(5*i,cnt,5*a[j-1],cnt+50,15);
                cnt+=50;
                break;
            }
        }
    }
}
void clook()
{
    settextstyle(1,0,3);
    outtextxy(310,370,"CLOOK");
    settextstyle(0,0,1);
    cnt=50;
    b[0]=init;
    sort(b.begin(),b.end());
    for(i=0;i<n+1;i++){
        if(b[i]==init){
            ind=i;
            break;
        }
    }
    line(0,50,1000,50);
    for(k=0;k<=1000;k+=50){
       line(k,48,k,52);
       g=k/5;
       itoa(g,c);
       outtextxy(k,37,c);
    }
    for(i=ind;i<n;i++){
        bresenham(5*b[i],cnt,5*b[i+1],cnt+50,15);
        itoa(b[i],c);
        outtextxy(5*b[i]+5,cnt+20,c);
        fillellipse(5*b[i], cnt, 5,5);
        cnt+=50;
    }
    itoa(b[i],c);
    outtextxy(5*b[i]+5,cnt-20,c);
    bresenham(5*b[n+1-1],cnt,5*b[0],cnt+50,15);
    fillellipse(5*b[i], cnt, 5, 5);
    cnt+=50;
    for(j=0;j<ind-1;j++){
        bresenham(5*b[j],cnt,5*b[j+1],cnt+50,15);
        itoa(b[j],c);
        fillellipse(5*b[j], cnt, 5,5);
        outtextxy(5*b[j]-7,cnt-20,c);
        cnt+=50;
    }
    itoa(b[j],c);
    outtextxy(5*b[j]-10,cnt-20,c);
    fillellipse(5*b[j], cnt, 5,5);
}

void sstf(){
    settextstyle(1,0,3);
    outtextxy(230,370,"Shortest Seek Time First");
    settextstyle(0,0,1);
    cnt=50;
    sort(b.begin(),b.end());
    for(int i=0;i<=n;i++){
        if(b[i]==init){
            ind=i;
            break;
        }
    }
    l = ind-1;
    r=ind+1;
    /// making of the X axis.
    line(0,50,1000,50);
    for(k=0;k<=1000;k+=50){
        line(k,48,k,52);
        g=k/5;
        itoa(g,c);
        outtextxy(k,37,c);
    }

    x = ind;
    while(l!=-1 && r!= n+1){
        if((b[r]-b[x])<(b[x]-b[l])){
            bresenham(5*b[x],cnt,5*b[r],cnt+50,15);
            itoa(b[x],c);
            outtextxy(5*b[x]-5,cnt+10,c);
            fillellipse(5*b[x],cnt,5,5);
            x=r;
            r++;
            cnt+=50;
            if(r==n+1){
                bresenham(5*b[x],cnt,5*b[l],cnt+50,15);
                itoa(b[x],c);
                outtextxy(5*b[x]-4,cnt-10,c);
                fillellipse(5*b[x],cnt,5,5);
                cnt+=50;
            }
        }else{
            bresenham(5*b[x],cnt,5*b[l],cnt+50,15);
            itoa(b[x],c);
            outtextxy(5*b[x]-5,cnt-10,c);
            fillellipse(5*b[x],cnt,5,5);
            x=l;
            l--;
            cnt+=50;
            if(l==-1){
                bresenham(5*b[x],cnt,5*b[r],cnt+50,15);
                itoa(b[x],c);
                outtextxy(5*b[x]-5,cnt-10,c);
                fillellipse(5*b[x],cnt,5,5);
                cnt+=50;
                for(i=r;i<n;i++){
                    bresenham(5*b[i],cnt,5*b[i+1],cnt+50,15);
                    itoa(b[i],c);
                    outtextxy(3*b[i]-5,cnt-10,c);
                    fillellipse(5*b[i],cnt,5,5);
                    cnt+=50;
                }
                itoa(b[n],c);
                outtextxy(5*b[n]-5,cnt-10,c);
                fillellipse(5*b[n],cnt,5,5);
            }
        }
    }
    for(i=ind;i<n;i++){
        bresenham(5*b[i],cnt,5*b[i+1],cnt+50,15);
        itoa(b[i],c);
        outtextxy(5*b[i]+5,cnt+50,c);
        fillellipse(5*b[i],cnt,5,5);
        cnt+=50;
    }
    itoa(b[i],c);
    outtextxy(5*b[i]+5,cnt-13,c);
    bresenham(5*b[i],cnt,5*b[0],cnt+50,15);
    fillellipse(5*b[i],cnt,5,5);
    cnt+=50;
    for(j=0;j<ind-1;j++){
        bresenham(5*b[j],cnt,5*b[j+1],cnt+50,15);
        itoa(b[j],c);
        fillellipse(5*b[j],cnt,5,5);
        outtextxy(5*b[j]-7,cnt-15,c);
        cnt+=50;
    }
    itoa(b[j],c);
    outtextxy(5*b[j]-10,cnt-15,c);
    fillellipse(5*b[j],cnt,5,5);
}
void fcfs(){
    cnt=0;
    settextstyle(10,0,3);
    outtextxy(320,370,"First Come First Served");
    settextstyle(0,0,1);
    line(0,50,1000,50);
    for(k=0;k<=1000;k+=50){
        line(k,48,k,52);
        g = k/5;
        itoa(g,c);
        outtextxy(k,37,c);
    }
    bresenham(5*init,50,5*a[0],100,10);
    itoa(init,c);
    outtextxy((5*init),55,c);
    cnt = 100;
    for(j=0;j<n;j++){
        for(i=0;i<=200;i++){
            if(a[j]==i){
                setcolor(15);
                itoa(i,c);
                fillellipse(5*i,cnt,5,5);
                if(a[j]>a[j+1]){
                    outtextxy(5*i+25,cnt,c);cout<<c;}
                else
                    outtextxy(5*i-30,cnt,c);
                if(j<n-1)
                    bresenham(5*i,cnt,5*a[j+1],cnt+50,15);
                cnt+=50;
                break;
            }
        }
    }
}
main()
{
    system("cls");
    gd = DETECT;
    initgraph(&gd,&gm, "");
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<' ';
        cin>>a[i];
    }
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i] = a[i-1];
    }
    cout<<"Enter initial point:";
    cin>>init;

    fcfs();
    getch();
    cleardevice();
    sstf();
    getch();
    cleardevice();
    clook();
    getch();
    cleardevice();
    lifo();
    getch();
    cleardevice();
    closegraph();
}