#include <iostream>

#include <cstring>

#include <string>

#include <vector>

#include <algorithm>



using namespace std;



#define max 100



int n,m;



struct way

{

     int road[max];

};

vector<way> vec;   //\u5b58\u50a8\u6392\u5217\u7ec4\u5408\u7684\u65b9\u5f0f



int ans[max];

int value_road;

int value_node[max];

int Map[max][max];



bool visit[max];



void dfs(int v,int num)   //\u6df1\u641c\u679a\u4e3e\u6392\u5217\u7ec4\u5408\u7684\u6240\u6709\u65b9\u5f0f

{

   if(num==m)  //\u82e5\u5df2\u8fbe\u5230\u70b9\u7684\u6570\u76ee\u7684\u8981\u6c42

   {

            way w;



            for(int i=0;i<num;i++)

                {

                    w.road[i]=ans[i];

            }



         vec.push_back(w);



         return ;

      }



         for(int i=1;i<=n;i++)

         {

            if(num>0 && i<ans[num-1])   //\u4fdd\u8bc1\u5b57\u5178\u5e8f\u7684\u6392\u5217\u7ec4\u5408

                      continue;



                 if(!visit[i])

                {

                    ans[num]=i;

                  visit[i]=1;



                       dfs(i,num+1);



                     visit[i]=0;

          }

    }

}



void prim(int r[])    //\u666e\u91cc\u59c6\u6700\u5c0f\u751f\u6210\u6811\u7b97\u6cd5

{

     int v=r[0];

  int low[max];

        int min;

     int closest[max],i,j,k;



   for(i=0;i<m;i++)

      {

            low[r[i]]=Map[v][r[i]];

              closest[r[i]]=v;

     }



 for(i=1;i<m;i++)

      {

            min=99999;



                for(j=0;j<m;j++)

                      if(low[r[j]]!=0 && low[r[j]]<min)

                     {

                            min=low[r[j]];

                               k=r[j];

                      }



         value_road+=min;

             low[k]=0;



         for(j=0;j<m;j++)

                      if(Map[k][r[j]]!=0 && Map[k][r[j]]<low[r[j]])

                 {

                            low[r[j]]=Map[k][r[j]];

                              closest[r[j]]=r[k];

                  }

    }

}



int main()

{

        while(cin>>n>>m && n)

    {

            vec.clear();



              memset(value_node,0,sizeof(value_node));

             memset(visit,0,sizeof(visit));

               memset(Map,0,sizeof(Map));



                for(int i=1;i<=n;i++)

                 cin>>value_node[i];



         for(int i=1;i<=n;i++)

                 for(int j=1;j<=n;j++)

                         cin>>Map[i][j];



             for(int i=1;i<=n;i++)

         {

                    visit[i]=1;

                  ans[0]=i;

                    dfs(i,1);

            }



         //\u53ea\u8981\u6df1\u641c\u5b8c\u6bd5\uff0c\u6bcf\u6b21\u4ece\u50a8\u5b58\u7684\u6392\u5217\u7ec4\u5408\u65b9\u5f0f\u4e2d\u9009\u51fa\u4e00\u4e2d\uff0c\u5219\u70b9\u7684\u6743\u503c\u5df2\u786e\u5b9a\uff0c\u5219\u9898\u76ee\u8f6c\u5316\u4e3a\u6c42\u6700\u5c0f\u751f\u6210\u6811



          vector<double> temp;

           for(int i=0;i<vec.size();i++)

         {

                    value_road=0;

                        int t_va_node=0;



                  for(int j=0;j<m;j++)

                          t_va_node+=value_node[vec[i].road[j]];



                    prim(vec[i].road);



                        double tt=(double)value_road/(double)t_va_node;



                   temp.push_back(tt);

          }



         double MMax=99999.0;

         int index;

           for(int i=0;i<temp.size();i++)

                {

                    if(temp[i]<MMax)   //\u9009\u51fa\u6700\u5c0f\u503c

                   {

                            MMax=temp[i];

                                index=i;

                     }

            }



         for(int i=0;i<m;i++)

                  cout<<vec[index].road[i]<<" ";   //\u8f93\u51fa\u8def\u5f84

         cout<<endl;

    }



 return 0;

}
