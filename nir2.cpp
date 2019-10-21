#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class NIR
{
private:
    NIR *p=NULL,*u=NULL,*next,*prev;
    char numar[200],semn;
    int x,nrc;
public:
    friend ostream &operator<<(ostream &ceva,NIR &nr)
    {
        if(nr.semn=='-')
        ceva<<endl<<nr.semn;
        NIR *c;
        c=nr.p;
        while(c!=NULL)
        {
            ceva<<c->x;
            c=c->next;
        }
        return ceva;

    }
    friend istream &operator>>(istream &ceva,NIR &nr)
    {
        ceva>>nr.numar;
        return ceva;
    }

    NIR operator+(NIR nr)
    {

       NIR v,*v1,*v2;
       int c=0,elem=0;
       v.u=new NIR;
       v1=v.u;
       v1->next=NULL;
       v1->prev=NULL;
       if (this->semn==nr.semn)
       {
           NIR *d1=this->u,*d2=nr.u;
           v.semn=this->semn;
           c=(d1->x+d2->x)/10;
           v1->x=(d1->x+d2->x)%10;
           d1=d1->prev;
           d2=d2->prev;
           elem++;
           while(d1!=NULL && d2!=NULL)
           {
            v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d1->x+d2->x+c)%10;
            c=(d1->x+d2->x)/10;
            d1=d1->prev;
            d2=d2->prev;
            elem++;
            }
            while (d1!=NULL)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d1->x+c)%10;
            c=(d1->x)/10;
            d1=d1->prev;
            elem++;
            }
            while (d2!=NULL)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d2->x+c)%10;
            c=(d2->x)/10;
            d2=d2->prev;
            elem++;
            }
            v.p=v1;
            if (c==1)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=c;
            v.p=v2;
            elem++;
            }

        }
        else
        {
         NIR *d1,*d2,g1,g2,*c1,*c2,*wanderer1,*wanderer2;
         d1=this->p;
         d2=nr.p;
         g1.nrc=this->nrc;
         g2.nrc=nr.nrc;
         g1.p=new NIR;
         g2.p=new NIR;
         g1.p->prev=NULL;
         g2.p->prev=NULL;
         g1.p->next=NULL;
         g2.p->next=NULL;
         g1.p->x=this->p->x;
         g2.p->x=nr.p->x;
         c1=g1.p;
         d1=d1->next;
         d2=d2->next;
         while(d1!=NULL)
         {
             c2=new NIR;
             c2->x=d1->x;
             c2->prev=c1;
             c1->next=c2;
             c2->next=NULL;
             c1=c2;
             d1=d1->next;
        }
        g1.u=c1;
        c1=g2.p;
         while(d2!=NULL)
         {
             c2=new NIR;
             c2->x=d2->x;
             c2->prev=c1;
             c1->next=c2;
             c2->next=NULL;
             c1=c2;
             d2=d2->next;
        }
g2.u=c1;
if (g1.absmaxim1(g1,g2)==1)
{
    d1=g1.u;
    d2=g2.u;
    v.semn=this->semn;
}
else
{
d1=g2.u;
d2=g1.u;
v.semn=nr.semn;
}
c1=NULL;
c2=NULL;
while(d1!=NULL && d2!=NULL)
{
if(d1->x >= d2->x)
{
    if(c1==NULL)
    {
        c1=new NIR;
        v.u=c1;
        c1->x=d1->x-d2->x;
        c2=c1;
        c1->next=NULL;
        c1->prev=NULL;
        v.p=c1;
        elem++;
    }
    else
    {
    c2=new NIR;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    c2->x=d1->x-d2->x;
    c1=c2;
    v.p=c2;
    elem++;
    }
}
else
{

    wanderer1=d1->prev;
    wanderer2=d2->prev;
    while(wanderer2!=NULL && (wanderer1->x < wanderer2->x))
    {

        wanderer1=wanderer1->prev;
        wanderer2=wanderer2->prev;
    }
    while(wanderer1->x==0)
        wanderer1=wanderer1->prev;
    wanderer1->x=wanderer1->x-1;
    wanderer1->next->x=wanderer1->next->x+10;
    if(wanderer1->prev==NULL && wanderer1->x==0)
    {
      v1=wanderer1;
      wanderer1=wanderer1->next;
      v1->next=NULL;
      wanderer1->prev=NULL;
      delete v1;
    }
    else
        wanderer1=wanderer1->next;
    while(wanderer1!=d1)
    {
    wanderer1->x=wanderer1->x-1;
    wanderer1->next->x=wanderer1->next->x+10;
    wanderer1=wanderer1->next;
    }
    if(c1==NULL)
    {
        c1=new NIR;
        v.u=c1;
        c1->x=d1->x-d2->x;
        c2=c1;
        c1->next=NULL;
        c1->prev=NULL;
        v.p=c1;
        elem++;
    }
    else
    {
    c2=new NIR;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    c2->x=d1->x-d2->x;
    c1=c2;
    v.p=c2;
    elem++;
    }
}
d1=d1->prev;
d2=d2->prev;
}
while(d1!=NULL)
{
    c2=new NIR;
    c2->x=d1->x;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    v.p=c2;
    c1=c2;
    d1=d1->prev;
}
c1=v.p;
c2=c1->next;
while(c2!=NULL && c1->x==0)
{
c1->next=NULL;
c2->prev=NULL;
v.p=c2;
delete c1;
c1=c2;
c2=c2->next;
elem--;
}
if(v.p->prev==NULL && v.p->next==NULL && v.p->x==0)
    v.semn='+';
        }
v.nrc=elem;
return v;
    }
    NIR operator-(NIR nr)
    {
       NIR v,*v1,*v2;
       int c=0,elem=0;
       v.u=new NIR;
       v1=v.u;
       v1->next=NULL;
       v1->prev=NULL;
       if (this->semn!=nr.semn)
       {
           NIR *d1=this->u,*d2=nr.u;
           v.semn=this->semn;
           c=(d1->x+d2->x)/10;
           v1->x=(d1->x+d2->x)%10;
           d1=d1->prev;
           d2=d2->prev;
           elem++;
           while(d1!=NULL && d2!=NULL)
           {
            v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d1->x+d2->x+c)%10;
            c=(d1->x+d2->x)/10;
            d1=d1->prev;
            d2=d2->prev;
            elem++;
            }
            while (d1!=NULL)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d1->x+c)%10;
            c=(d1->x)/10;
            d1=d1->prev;
            elem++;
            }
            while (d2!=NULL)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=(d2->x+c)%10;
            c=(d2->x)/10;
            d2=d2->prev;
            elem++;
            }
            v.p=v1;
            if (c==1)
            {
                v2=new NIR;
            v2->next=v1;
            v1->prev=v2;
            v2->prev=NULL;
            v1=v2;
            v1->x=c;
            v.p=v2;
            elem++;
            }

        }
        else
        {
         NIR *d1,*d2,g1,g2,*c1,*c2,*wanderer1,*wanderer2;
         d1=this->p;
         d2=nr.p;
         g1.nrc=this->nrc;
         g2.nrc=nr.nrc;
         g1.p=new NIR;
         g2.p=new NIR;
         g1.p->prev=NULL;
         g2.p->prev=NULL;
         g1.p->next=NULL;
         g2.p->next=NULL;
         g1.p->x=this->p->x;
         g2.p->x=nr.p->x;
         c1=g1.p;
         d1=d1->next;
         d2=d2->next;
         while(d1!=NULL)
         {
             c2=new NIR;
             c2->x=d1->x;
             c2->prev=c1;
             c1->next=c2;
             c2->next=NULL;
             c1=c2;
             d1=d1->next;
        }
        g1.u=c1;
        c1=g2.p;
         while(d2!=NULL)
         {
             c2=new NIR;
             c2->x=d2->x;
             c2->prev=c1;
             c1->next=c2;
             c2->next=NULL;
             c1=c2;
             d2=d2->next;
        }
g2.u=c1;
if (g1.absmaxim1(g1,g2)==1)
{
    d1=g1.u;
    d2=g2.u;
    v.semn=this->semn;
}
else
{
d1=g2.u;
d2=g1.u;
if (this->semn=='+')
v.semn='-';
else
v.semn='+';
}
c1=NULL;
c2=NULL;
while(d1!=NULL && d2!=NULL)
{
if(d1->x >= d2->x)
{
    if(c1==NULL)
    {
        c1=new NIR;
        v.u=c1;
        c1->x=d1->x-d2->x;
        c2=c1;
        c1->next=NULL;
        c1->prev=NULL;
        v.p=c1;
        elem++;
    }
    else
    {
    c2=new NIR;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    c2->x=d1->x-d2->x;
    c1=c2;
    v.p=c2;
    elem++;
    }
}
else
{

    wanderer1=d1->prev;
    wanderer2=d2->prev;
    while(wanderer2!=NULL && (wanderer1->x < wanderer2->x))
    {

        wanderer1=wanderer1->prev;
        wanderer2=wanderer2->prev;
    }
    while(wanderer1->x==0)
        wanderer1=wanderer1->prev;
    wanderer1->x=wanderer1->x-1;
    wanderer1->next->x=wanderer1->next->x+10;
    if(wanderer1->prev==NULL && wanderer1->x==0)
    {
      v1=wanderer1;
      wanderer1=wanderer1->next;
      v1->next=NULL;
      wanderer1->prev=NULL;
      delete v1;
    }
    else
        wanderer1=wanderer1->next;
    while(wanderer1!=d1)
    {
    wanderer1->x=wanderer1->x-1;
    wanderer1->next->x=wanderer1->next->x+10;
    wanderer1=wanderer1->next;
    }
    if(c1==NULL)
    {
        c1=new NIR;
        v.u=c1;
        c1->x=d1->x-d2->x;
        c2=c1;
        c1->next=NULL;
        c1->prev=NULL;
        v.p=c1;
        elem++;
    }
    else
    {
    c2=new NIR;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    c2->x=d1->x-d2->x;
    c1=c2;
    v.p=c2;
    elem++;
    }
}
d1=d1->prev;
d2=d2->prev;
}
while(d1!=NULL)
{
    c2=new NIR;
    c2->x=d1->x;
    c2->next=c1;
    c1->prev=c2;
    c2->prev=NULL;
    v.p=c2;
    c1=c2;
    d1=d1->prev;
}
c1=v.p;
c2=c1->next;
while(c2!=NULL && c1->x==0)
{
c1->next=NULL;
c2->prev=NULL;
v.p=c2;
delete c1;
c1=c2;
c2=c2->next;
elem--;
}
if(v.p->prev==NULL && v.p->next==NULL && v.p->x==0)
    v.semn='+';
        }
v.nrc=elem;
return v;
    }
    void citire(NIR &nr)
    {
        NIR *c,*d;
        int poz;
        cin>>nr;
        nr.nrc=strlen(nr.numar);
        if(nr.numar[0]=='-')
        {
            nr.semn='-';
            nr.nrc--;
            poz=1;
        }
        else
        {
         nr.semn='+';
         poz=0;
        }
        if(nr.p!=NULL)
        {
          c=nr.p;
          while(c->next!=NULL)
          {
              d=c->next;
              d->prev=NULL;
              c->next=NULL;
              delete c;
              c=d;
          }
          delete c;
        }

        for (int i=poz;i<strlen(nr.numar);i++)
        {
              d=new NIR;
              if(i==poz)
              {
                nr.p=d;
                d->next=NULL;
                d->prev=NULL;
                d->x=nr.numar[i]-48;
                c=d;
              }
              else
              {
              d->prev=c;
              d->next=NULL;
              c->next=d;
              d->x=nr.numar[i]-48;
              c=d;
              }
          }
          u=c;

        }

    void afisare(NIR &nr)
    {
        cout<<nr;
        cout<<endl;
    }
     NIR absmaxim(NIR c1,NIR c2)
     {
         if(c1.nrc>c2.nrc)
            return c1;
         else
            if(c2.nrc>c1.nrc)
            return c2;
         else
         {
          NIR *d1,*d2;
          d1=c1.p;
          d2=c2.p;
          while(d1!=NULL)
          {
              if (d1->x>d2->x)
                return c1;
              else
                if (d2->x>d1->x)
                return c2;
              else
              {
                  d1=d1->next;
                  d2=d2->next;
              }
          }
          return c1;
         }
     }
     int absmaxim1(NIR c1,NIR c2)
     {
         if(c1.nrc>c2.nrc)
            return 1;
         else
            if(c2.nrc>c1.nrc)
            return 2;
         else
         {
          NIR *d1,*d2;
          d1=c1.p;
          d2=c2.p;
          while(d1!=NULL)
          {
              if (d1->x>d2->x)
                return 1;
              else
                if (d2->x>d1->x)
                return 2;
              else
              {
                  d1=d1->next;
                  d2=d2->next;
              }
          }
          return 1;
         }
     }

     NIR operator*(NIR nr)
     {

         NIR v,*d1,*d2,*c,*c1,*c2;
         int rem=0,elem=0,k=0;
         if (this->semn==nr.semn)
            v.semn=this->semn;
         else
            v.semn='-';
            v.u=new NIR;
            c=v.u;
            c1=v.u;
            c->x=(nr.u->x*this->u->x)%10;
            c->next=NULL;
            c->prev=NULL;
            v.p=c;
            rem=(nr.u->x*this->u->x)/10;
            elem++;
         for(d2=nr.nrc>this->nrc ? this->u:nr.u;d2!=NULL;d2=d2->prev)
         {
             c=c1;
            for(d1=nr.nrc>this->nrc ? nr.u:this->u;d1!=NULL;d1=d1->prev)
            {    if(d2->next==NULL && d1->next==NULL)
            {
                   d1=d1->prev;
                   if(d1==NULL)
                    k=1;
            }
            if(k==1)
                break;

                if(d2->next==NULL)
                {
                    c2=new NIR;
                    c2->next=c;
                    c->prev=c2;
                    c2->prev=NULL;
                    c2->x=(d2->x*d1->x+rem)%10;
                    rem=(d2->x*d1->x+rem)/10;
                    c=c2;
                    v.p=c2;
                    elem++;
                }
                else
                {
                 if(c!=NULL)
                 {

                     c->x=c->x+d2->x*d1->x+rem;
                     rem=(c->x)/10;
                     c->x=(c->x)%10;
                     c2=c;
                     c=c->prev;
                 }
                 else
                 {
                     c=new NIR;
                     c->next=c2;
                     c2->prev=c;
                     c->prev=NULL;
                     c->x=d2->x*d1->x+rem;
                     rem=(c->x)/10;
                     c->x=(c->x)%10;
                     v.p=c;
                     elem++;

                 }
                }




            }
            k=0;
                if(rem!=0)
                {
                    if(c!=NULL)
                    {
                  c2=new NIR;
                    c2->next=c;
                    c->prev=c2;
                    c2->prev=NULL;
                    c2->x=rem;
                    rem=0;
                    v.p=c2;
                    elem++;
                    }
                    else
                    {
                      c=new NIR;
                    c->next=c2;
                    c2->prev=c;
                    c->prev=NULL;
                    c->x=rem;
                    rem=0;
                    v.p=c;
                    elem++;
                    }
                }
                c1=c1->prev;

            }
            v.nrc=elem;
            return v;
         }
      void operator=(NIR nr)
      {
          NIR *c1,*c2,*c3;
          nrc=nr.nrc;
          semn=nr.semn;
          c3=nr.p;
          p=new NIR;
          p->prev=NULL;
          p->next=NULL;
          p->x=c3->x;
          c1=p;
          c3=c3->next;
          while(c3!=NULL)
          {
             c2=new NIR;
             c2->next=NULL;
             c2->prev=c1;
             c1->next=c2;
             c2->x=c3->x;
             c1=c2;
             c3=c3->next;
          }
          u=c1;

      }
friend class VNIR;
};

class VNIR
{
private:
    int nrelem;
    NIR val[200];
public:
    friend ostream &operator<<(ostream &ceva,VNIR &nr)
    {
        for(int i=1;i<=nr.nrelem;i++)
            ceva<<nr.val[i]<<" ";
          return ceva;
    }
    friend istream &operator>>(istream &ceva,VNIR &nr)
    {
        ceva>>nr.nrelem;
        for(int i=1;i<=nr.nrelem;i++)
            nr.val[i].citire(nr.val[i]);
        return ceva;
    }
     void citire(VNIR &nr)
    {
        cin>>nr;

   }
     void afisare(VNIR &nr)
    {
    cout<<nr;
}

NIR operator*(VNIR nr)
{

    NIR ps=nr.val[1]*this->val[1];
    for(int i=2;i<=min(nr.nrelem,this->nrelem);i++)
        ps=ps+nr.val[i]*(this->val[i]);

return ps;
}
NIR absmaxim(VNIR nr)
{
    NIR maxi=nr.val[1];
    for(int i=1;i<=nr.nrelem;i++)
    maxi=maxi.absmaxim(maxi,nr.val[i]);
return maxi;
}
void operator=(VNIR nr)
{
    nrelem=nr.nrelem;
    for(int i=1;i<=nr.nrelem;i++)
        val[i]=nr.val[i];
}
NIR &operator[](int nr)
{
    return val[nr];
}
int get_nr()
{
    return this->nrelem;
}

};
int main()
{

}
