#include "obs.h"

void obs(const Gauge_Field &U, const Twist_Fermion &F,double &act_s, double &mass, Complex &d, double &act_F,
double eigenvals[SITES][NUMLINK][NCOLOR]){
Lattice_Vector x,e_mu,e_nu;
int mu,nu,site,i,j,s;
Gauge_Field Udag;
<<<<<<< HEAD
Umatrix av,plaq,Fmunu,DmuUmu;
Twist_Fermion sol[DEGREE],psol[DEGREE]; 

double b[2*NCOLOR],dummy[2],dummy2[2*NCOLOR*NCOLOR],work[4*NCOLOR];
double at[2*NCOLOR*NCOLOR];
double re,im;
Umatrix diag, sim, prod, unitary;

act_F=act_s=mass=0.0;
  
Udag=Adj(U);
  
// gauge action

// SIMON: beta term modification

Complex trace;
site=0;
while(loop_over_lattice(x,site)){
DmuUmu=Umatrix();
for(mu=0;mu<NUMLINK;mu++){
e_mu=Lattice_Vector(mu);
DmuUmu=DmuUmu+(1.0+C1)*U.get(x,mu)*Udag.get(x,mu)-Udag.get(x-e_mu,mu)*U.get(x-e_mu,mu);
trace=Tr(U.get(x,mu)*Udag.get(x,mu));
DmuUmu=DmuUmu-(C1/NCOLOR)*trace*Umatrix(1);
}


act_s=act_s+0.5*C2*Tr(DmuUmu*DmuUmu).real();

}
=======
Umatrix av,plaq,Fmunu;
Twist_Fermion sol[DEGREE],psol[DEGREE]; 
USite_Field DmuUmu;
UPlaq_Field P;
double b[2*NCOLOR],dummy[2],dummy2[2*NCOLOR*NCOLOR],work[4*NCOLOR];
double at[2*NCOLOR*NCOLOR];
double re,im;
Umatrix diag, sim, prod, unitary,dd;
Complex dum;

act_F=act_s=mass=0.0;

// susy mass term

Udag=Adj(U);
                 

// susy det term modification

P=Plaq(U);
site=0;
d=Complex();
while(loop_over_lattice(x,site)){
dum=Complex();
for(mu=0;mu<NUMLINK;mu++){
for(nu=0;nu<NUMLINK;nu++){
if(mu==nu) continue;
if(mu>nu){
d=d+det(P.get(x,mu,nu));}
dum=dum+(det(P.get(x,mu,nu))-Complex(1.0,0.0));}}
DmuUmu.set(x,G*dum*Umatrix(1));
}
d=(2.0/(SITES*NUMLINK*(NUMLINK-1)))*d;
// usual piece
>>>>>>> f33135b5861f274b44c622ee0ce6ebc81e898eb0

site=0;
while(loop_over_lattice(x,site)){
for(mu=0;mu<NUMLINK;mu++){
e_mu=Lattice_Vector(mu);
<<<<<<< HEAD
for(nu=mu+1;nu<NUMLINK;nu++){
e_nu=Lattice_Vector(nu);
Fmunu=U.get(x,mu)*U.get(x+e_mu,nu)-U.get(x,nu)*U.get(x+e_nu,mu);
act_s=act_s+2.0*Tr(Fmunu*Adj(Fmunu)).real();

}
}
}

/* mass term for U(1) mode*/
double dum;
//double mass=0.0;

site=0;
while(loop_over_lattice(x,site)){
for(mu=0;mu<NUMLINK;mu++){
dum=(1.0/NCOLOR)*Tr(Udag.get(x,mu)*U.get(x,mu)).real()-1.0;
//dum=det(U.get(x,mu)*Udag.get(x,mu)).real();
act_s=act_s+BMASS*BMASS*dum*dum;
//mass=mass+dum;
}}


// det term

site=0;
d=Complex();
=======
DmuUmu.set(x,DmuUmu.get(x)+U.get(x,mu)*Udag.get(x,mu)-
                           Udag.get(x-e_mu,mu)*U.get(x-e_mu,mu));}
                     
act_s=act_s+0.5*C2*Tr(DmuUmu.get(x)*DmuUmu.get(x)).real();
}


// Konishi mass term
site=0;
dum=Complex();
while(loop_over_lattice(x,site)){
for(mu=0;mu<NUMLINK;mu++){
dd=U.get(x,mu)*Udag.get(x,mu)-Umatrix(1);
dum=dum+Tr(dd*dd);
}}

act_s=act_s+(BMASS*BMASS)*dum.real();
site=0;
>>>>>>> f33135b5861f274b44c622ee0ce6ebc81e898eb0
while(loop_over_lattice(x,site)){
for(mu=0;mu<NUMLINK;mu++){
e_mu=Lattice_Vector(mu);
for(nu=mu+1;nu<NUMLINK;nu++){
e_nu=Lattice_Vector(nu);
<<<<<<< HEAD
plaq=U.get(x,mu)*U.get(x+e_mu,nu)*Udag.get(x+e_nu,mu)*Udag.get(x,nu);
d=d+det(plaq);
}}}

d=(1.0/(10*SITES))*d;
=======
Fmunu=U.get(x,mu)*U.get(x+e_mu,nu)-U.get(x,nu)*U.get(x+e_nu,mu);
act_s=act_s+2.0*Tr(Fmunu*Adj(Fmunu)).real();

}
}
}


>>>>>>> f33135b5861f274b44c622ee0ce6ebc81e898eb0
act_s=KAPPA*act_s;

act_s/=(SITES*4.5*NUMGEN);

// pseudofermion contribution

if(FERMIONS){

act_F=act_F+ampdeg*(Cjg(F)*F).real();


MCG_solver(U,F,shift,sol,psol);

for(int n=0;n<DEGREE;n++){
act_F=act_F+amp[n]*(Cjg(F)*sol[n]).real();
}

<<<<<<< HEAD

act_F/=(SITES*16*NUMGEN);
=======
act_F/=(SITES*NUMGEN*16);

>>>>>>> f33135b5861f274b44c622ee0ce6ebc81e898eb0

}

if(SMALLEIG){

site=0;
while(loop_over_lattice(x,site)){
for(mu=0;mu<NUMLINK;mu++){

av=U.get(x,mu)*Adj(U.get(x,mu));

int i,j,ok,c1,c2,c3,c6;
char c4,c5;
double temp[NCOLOR+1];

for(i=0;i<NCOLOR;i++){
for(j=0;j<NCOLOR;j++){
at[2*(j+NCOLOR*i)]=av.get(j,i).real();
at[2*(j+NCOLOR*i)+1]=av.get(j,i).imag();
}
}

c1=NCOLOR;
c2=2*NCOLOR;
c3=1;
c4='N';
c5='V';
c6=NCOLOR;

zgeev_(&c4,&c5,&c1,at,&c1,b,dummy,&c3,dummy2,&c6,work,&c2,work,&ok);

for(j=0;j<2*NCOLOR;j=j+2){
temp[j/2+1]=b[j];}

eigsrt(temp,NCOLOR);
for(j=0;j<NCOLOR;j++){
eigenvals[site-1][mu][j]=temp[j+1];}


}
}
}

return;
}
