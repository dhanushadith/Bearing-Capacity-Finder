#include<stdio.h>
#include<math.h>

int main()
{
	int n,Nr[10000],y,sum=0,f,i;
	float Df,Dw,B,b,Gw,r1,r2,r3,r4,s,s0,u,G,Gs,qnp1,qnp2,rd;
	float Onr[10000],Dc[10000],Na,l,v,z,x,wg,wq,o,h,qnu,qns,qnp,qna;
	int ch;
	printf("Number of values to be used n: ");
	scanf("%d",&n);
	int d[n];
	printf("\nEnter the depth of foundation Df:");
	scanf("%f",&Df);
	printf("\nEnter the depth of watertable below Ground surface Dw:");
	scanf("%f",&Dw);
	printf("\nEnter the width of footing B:");
	scanf("%f",&B);
	printf("\nEnter the depth watertable below foundation b:");
	scanf("%f",&b);
	printf("\nEnter the Bulk Density of soil (Gamma):");
	scanf("%f",&G);
	printf("\nEnter the Saturated Density of soil(Gamma Saturated):");
	scanf("%f",&Gs);
	printf("\nEnter the unit weight of water(gamma w) :");
	scanf("%f",&Gw);
	printf("\nEnter the depth value: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("\nEnter the Recorded N-Values ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Nr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(d[i]>Dw)
		{
			s=((G*Dw)+(Gs*(d[i]-Dw)));
			u=(Gw*(d[i]-Dw));
			s0=s-u;
			z=log10 (2000/s0);
			Onr[i]=(0.77*Nr[i]*z);
			if(Onr[i]>15)
			{
				x=(Onr[i]-15);
				Dc[i]=(15+(0.5*x));
			}
			else
			{
			    Dc[i]=Onr[i];	
			}
		}
		else
		{
			s=(G*d[i]);
			u=0;
			s0=s-u;
			z=log10 (2000/s0);
			Onr[i]=(0.77*Nr[i],z);
			if(Onr[i>15])
			{
				x=(Onr[i]-15);
				Dc[i]=(15+(0.5*x));
			}
			else
			{
			    Dc[i]=Onr[i];	
			}
		}
	}
	y=2*B;
	for(i=1;i<=y;i++)
	{
		sum= sum+Dc[i];
	}
	Na=(sum/y);
	if(b<=B)
		{
			l=(0.5*(b/B));
			wg=0.5+l;
		}
	else
	{
		wg=0.5;
	}
	if(Dw<=Df)
	{
		v=(0.5*(Dw/Df));
		wq=0.5+v;
	}
	else
	{
		wq=0.5;
		
	}
	printf("NET SAFE BEARING CAPACITY qns");
	printf("Enter whether it is Strip (1)  or Circular(2) or Square Footing(3)");
	printf("Enter type of footing:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			r1=(3*Na*Na*B*wg);
			r2=(100+(Na*Na));
			r3=(5*r2*Df*wq);
			r4=r1+r3;
			
			qnu=((1/6.0)*r4);
			printf("Enter Factor of Safety :");
			scanf("%d",&f);
			qns=(qnu/f);
			printf("Net safe Bearing capacity is :%.2f",qns);
			break;
		}
		case 2:
		{
			r1=(Na*Na*B*wg);
			r2=(100+(Na*Na));
			r3=(3*r2*Df*wq);
			r4=r1+r3;
			qnu=((1/3.0)*r4);
			printf("Enter Factor of Safety :");
			scanf("%d",&f);
			qns=(qnu/f);
			printf("Net safe Bearing capacity is :%.2f",qns);
			break;
		}
		case 3:
		{
			r1=(Na*Na*B*wg);
			r2=(100+(Na*Na));
			r3=(3*r2*Df*wq);
			r4=r1+r3;
			qnu=((1/3.0)*r4);
			printf("Enter Factor of Safety :");
			scanf("%d",&f);
			qns=(qnu/f);
			printf("Net safe Bearing capacity is :%.2f",qns);
			break;
		}
	}
	h=((B+0.3)/(2*B));
	o=h*h;
	qnp1= (55.4*(Na-3)*o*wg);
	rd=(1+(Df/B));
	if(rd>2.0)
	{
		rd=2.0;
	}
	else
	{
		rd=rd;
	}
	qnp2=(56.0*(Na-3)*o*wg*rd);
	if(qnp1<qnp2)
	{
		qnp=qnp1;
	}
	else
	{
		qnp=qnp2;
	}
	printf("\nNet settlement pressure (qnp)%.2f",qnp);
	if(qns<qnp)
	{
		qna=qns;
		printf("\n Net Allowable Bearing Capacity (qna):%.3f",qna);
	}
	else
	{
		qna=qnp;
		printf("\n Net Allowable Bearing Capacity (qna):%.3f",qna);
	}
	return 0;
}
