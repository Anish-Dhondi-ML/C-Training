int a,b,i;
   cout<<"enter two numbers to find range 1st number should to be less than second"<<endl;
   cin>>a>>b;
    if(a==b || a>b)
       cout<<"There is no range between these numbers";
    if(a>=0 && b>=0)
    {
   for(i=a+1;i<b;i++)
     {
       cout<<i<<" ";
     }
   cout<<endl;
   i=a+1;
   while(i<b)
   {
       cout<<i<<" ";
       i++;
   }
    }
    else
    cout<<"enter positive number";
}
   
