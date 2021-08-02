#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int OptiSeekTime(int nT,int tracks[], int intitial){
    int FCFS=0,STL=0, LTS=0;    //firstComeFirstServe, SmallestToBigger, BiggestToSmallest
    int inorder[nT];
    for(int i=0;i<nT;i++){
        inorder[i]=tracks[i];
    }
    for(int i=0; i<nT; i++){
        int sum=0;
        if(i==0){
            sum=abs(inorder[i]-intitial);
        }
        else
            sum=abs(inorder[i]-inorder[i-1]);
        FCFS+=sum;
    }
    for(int i=0; i<nT; i++){
        sort(tracks,tracks+nT); //ascending order
        int sum=0;
        if(i==0){
            sum= abs(tracks[i]-intitial);
        }
        else{
            sum=abs(tracks[i]-tracks[i-1]);
        }
        STL+=sum;
    }
    for(int i=0; i<nT; i++){
        sort(tracks,tracks+nT,greater<int>());  //descending order
        int sum=0;
        if(i==0){
            sum= abs(tracks[i]-intitial);  //for first time I need to subtract from the initial track
        }
        else{
            sum=abs(tracks[i]-tracks[i-1]);     //the rest I will need to subtract from the new track that's being pointed to
        }
        LTS+=sum;
    }
    if(FCFS<=STL&&FCFS<=LTS) //to find the least seek time achieved
        return FCFS;
    else if(STL<=FCFS&& STL<=LTS)
        return STL;
    else
        return LTS;
}

int main()
{
    int NTracks=0, IniTrack=0;
    cout<<"Enter number of Tracks"<<endl;
    cin>>NTracks;
    int Tracks[NTracks];
    cout << "Enter Tracks Values" << endl;
    for(int i=0; i<NTracks;i++){
        Tracks[i]=0;
    }
    for(int i=0; i<NTracks;i++){
        cin>>Tracks[i];
    }
    cout<<"Enter Initial Track Value"<<endl;
    cin>>IniTrack;
    cout<<"Seek time: "<<OptiSeekTime(NTracks,Tracks,IniTrack);
    return 0;
}
/*TestCase1(190)
3
100 50 190
140

TestCase2(300)
5
200 60 150 320 260
100

TestCase3(350)
4
300 50 240 180
200

TestCase4(1990)
5
2000 20 30 50 1000
30
*/
