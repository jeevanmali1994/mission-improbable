#include<iostream>
using namespace std;
int main()
{
   int warehouse[100][100],newwarehouse[100][100],row,column,i,j,maxrow[100],maxcolumn[100],compare=0,totalBox=0,totalCells=0,zeroCount=0,boxedCells=0,value=0,totalBoxfinal=0;
   //taking rows and column
   cin>>row>>column;

   //calculating total number of box
   totalCells=row*column;

   //taking box numbers
    for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           cin>>warehouse[i][j];
       }
   }
   //calculating total number of boxes

   for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           totalBox=totalBox+warehouse[i][j];

       }
   }
    //storing total box in another variable

    totalBoxfinal=totalBox;

   //calculating number of zeros
   for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           if(warehouse[i][j]==0)
           {
                zeroCount++;
           }
       }
   }


   //finding the max value in row
   for(i=0;i<row;i++)
   {
       compare=0;
       for(j=0;j<column;j++)
       {
           if(warehouse[i][j]>=compare)
           {
               compare=warehouse[i][j];
           }
       }
       maxrow[i]=compare;
   }

   //finding max value in column
   for(j=0;j<column;j++)
   {
       compare=0;
       for(i=0;i<row;i++)
       {
           if(warehouse[i][j]>=compare)
           {
               compare=warehouse[i][j];
           }
       }
       maxcolumn[j]=compare;
   }

   //temporary printing max values

 /*  for(i=0;i<row;i++)
   {
       printf("\nMax value at %dth row=%d",i,maxrow[i]);
   }

   for(j=0;j<column;j++)
   {
       printf("\nMax value at %dth column=%d",j,maxcolumn[j]);
   }
*/
   //sorting and deleting double max values of same row n column index

   for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           if(maxrow[i]==maxcolumn[j] && warehouse[i][j]!=0)
           {
               totalCells=totalCells-1;
               value=value+maxrow[i];

               maxrow[i]=0;
               maxcolumn[j]=0;
               j=column;
           }

       }
   }

   //calculating number of 1 box cell
   totalCells=totalCells-zeroCount;

   //calculating box values
   for(i=0;i<row;i++)
   {
       value=value+maxrow[i];
   }

   for(j=0;j<column;j++)
   {
       value=value+maxcolumn[j];
   }





    //number of 1 box cells
    for(i=0;i<row;i++)
   {
       if(maxrow[i]!=0)
       {
           totalCells=totalCells-1;
       }
   }

   for(j=0;j<column;j++)
   {
        if(maxcolumn[j]!=0)
       {
           totalCells=totalCells-1;
       }
   }



   //stolen boxes
   totalBoxfinal=totalBoxfinal-totalCells-value;

   //printing stolen boxes
   cout<<totalBoxfinal;

}

