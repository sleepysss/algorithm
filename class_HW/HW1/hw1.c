#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    double x,y;
}point;

int mycmp1(const void* a, const void* b)
{
    const point* c=(point*)a;
    const point* d=(point*)b;

    return c->x>d->x;
}
int mycmp2(const void* a, const void* b)
{
    const point* c=(point*)a;
    const point* d=(point*)b;

    return c->y>d->y;
}

double min(double a,double b)
{
    return a>b?b:a;
}

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


double bruteforce(point store[],int n)
{
    double shortest=999999;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            double distance=dist(store[i],store[j]);
            if(distance<shortest)
                shortest=distance;
        }
    }
    return shortest;
}

double closest(point store[],int n) //find the smallest distance in given array
{
    if(n<=3)
        return bruteforce(store,n);

    int mid=n/2;

    point midpoint=store[mid];

    double dl=closest(store,mid); //Divide the given array in two halves, we let the shortest distance found on left side dl
    double dr=closest(store+mid,n-mid); //Divide the given array in two halves, we let the shortest distance found on right side dr
    double d=min(dl,dr); //upper bound of smallest distances

    //consider the pairs such that one point in pair is from the left half and the other is from the right half
    //define vertical line: a line passing through store[n/2]
    //find all points whose x coordinate is closer than d to the middle vertical line. Build an array temp[] of all such points

    point temp[n];

    int j=0; //size of temp
    for(int i=0;i<n;++i)
    {
        if(abs(store[i].x-midpoint.x)<d)
        {
            temp[j++]=store[i];
        }
    }
    qsort(temp,j,sizeof(point),mycmp2); //Sort the array temp[] according to y coordinates

    //find the smallest distance in temp[]
    for(int i=0;i<j;++i) //Pick all points one by one
    {
        for(int k=i+1;k<j&&(temp[k].y-temp[i].y<d);++k)  //difference between y coordinates is smaller than d
        {
            double distance=dist(temp[i],temp[k]);
            if(distance<d)  //smaller than smallest
                d=distance;
        }
    }
    return d;
}

int main()
{
    int num1,num2;
    scanf("%d",&num1);
    for(int i=0;i<num1;++i)
    {
        scanf("%d",&num2);
        point store[100000];
        for(int j=0;j<num2;++j)
            scanf("%lf %lf",&store[j].x,&store[j].y);
        qsort(store,num2,sizeof(point),mycmp1);  //the input array is sorted according to x coordinates(because we need to find mid point)
        printf("%f\n",closest(store,num2));
    }

    return 0;
}
