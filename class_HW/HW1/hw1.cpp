#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool mycmp1(double *x,double *y)
{
    return x[0]<y[0];
}
bool mycmp2(double *x,double *y)
{
    return x[1]<y[1];
}


double bruteforce(double **store,int n)
{
    double shortest=sqrt((store[0][0]-store[1][0])*(store[0][0]-store[1][0])+(store[0][1]-store[1][1])*(store[0][1]-store[1][1]));
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            //double distance=dist(store[i],store[j]);
            double distance=sqrt((store[i][0]-store[j][0])*(store[i][0]-store[j][0])+(store[i][1]-store[j][1])*(store[i][1]-store[j][1]));
            if(distance<shortest)
                shortest=distance;
        }
    }
    return shortest;
}

double closest(double **store,int n) //find the smallest distance in given array
{
    if(n<=3)
        return bruteforce(store,n);
    
    int mid=n/2;
    double midpoint[2]; //middle point of input array
    midpoint[0]=store[mid][0];
    midpoint[1]=store[mid][1];
    
    double dl=closest(store,mid); //Divide the given array in two halves, we let the shortest distance found on left side dl 
    double dr=closest(store+mid,n-mid); //Divide the given array in two halves, we let the shortest distance found on right side dr 
    double d=min(dl,dr); //upper bound of smallest distances 

    //consider the pairs such that one point in pair is from the left half and the other is from the right half
    //define vertical line: a line passing through store[n/2]
    //find all points whose x coordinate is closer than d to the middle vertical line. Build an array temp[] of all such points
    double **temp=new double *[n];
    for(int j=0;j<n;++j)
        temp[j]=new double[2];
    
    int j=0; //size of temp
    for(int i=0;i<n;++i)
    {
        if(abs(store[i][0]-midpoint[0])<d)
        {
            temp[j][0]=store[i][0];
            temp[j][1]=store[i][1];
            ++j;
        }
    }
    sort(temp,temp+j,mycmp2); //Sort the array temp[] according to y coordinates
    
    //find the smallest distance in temp[]
    for(int i=0;i<j;++i) //Pick all points one by one
    {
        for(int k=i+1;k<j&&(temp[k][1]-temp[i][1]<d);++k)  //temp[i][1]-temp[k][1]<d : difference between y coordinates is smaller than d
        {
            double distance=sqrt((temp[i][0]-temp[k][0])*(temp[i][0]-temp[k][0])+(temp[i][1]-temp[k][1])*(temp[i][1]-temp[k][1]));
            if(distance<d)  //smaller than smallest
                d=distance;
        }
    }
    
    for(int j=0;j<n;++j)
        delete[] temp[j];
    delete[] temp; 
    
    return d;
}

int main()
{
    int num1,num2;
    double x,y;
    cin>>num1;
    for(int i=0;i<num1;++i)
    {
        cin>>num2;
        double **store=new double *[num2]; //input array
        for(int j=0;j<num2;++j)
            store[j]=new double[2];
        for(int j=0;j<num2;++j)
        {
            cin>>x>>y;
            store[j][0]=x;
            store[j][1]=y;
        }
        sort(store,store+num2,mycmp1);  //the input array is sorted according to x coordinates(because we need to find mid point)
        cout<<closest(store,num2)<<endl;
        for(int j=0;j<num2;++j)
            delete[] store[j];
        delete[] store; 
    }

    return 0;
}
