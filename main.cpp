#include"loop.h"
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>
inline int GetMinSet(std::set<int> &a); 
int main(){
  loop **loops;
  int VaLoops, ValElemLoops;//кол-во циклов и элементов в цикле (в каждом)
  int min =0,firstmin=0;
  bool menu=true;

  std::cout<<"\nВведите кол-во циклов: ";
  std::cin>>VaLoops;
  loops=new loop*[VaLoops];//массив циклов
  std::vector <int> ind;//вектр значений эл-тов в каждом цикле
  for(int j=0;j<VaLoops;j++){
    std::cout<<"Цикл"<<j+1<<"\nВведите кол-во эл-тов: ";
    std::cin>>ValElemLoops;
    ind.push_back(ValElemLoops);
    loops[j] = new loop[ValElemLoops];//массив эл-тов цикла
    for(int i=0;i<ValElemLoops;i++){
    
      if(i==ValElemLoops-1){
		
	std::cout<<"\nВведите эл-т "<<i+1<<": ";
	std::cin>>loops[j][i].value;
	loops[j][i].next=&loops[j][0]; 
	break;
      }
    
    switch(i){
      case 0:{
	loops[j][i].next=&loops[j][i+1];};break;
      default:{
	loops[j][i].next=&loops[j][i+1];};break;
    }
    std::cout<<"\nВведите эл-т "<<i+1<<": ";
    std::cin>>loops[j][i].value;
  }
  }
  std::set <int> values;//множество различных эл-тов в циклах

  std::cout<<"\n=";
  for(int i=0;i<VaLoops;i++){
    std::cout<<"( ";
    for(int j=0;j<ind.at(i);j++){
      values.insert(loops[i][j].value);
      std::cout<<loops[i][j].value<<" ";
    }
    std::cout<<") ";
  }
  std::cout<<"=";

  //Процедура умножения и вывода данных
  while(values.size()!=0){
   if(min==0) {
      min=GetMinSet(values);
      std::cout<<"( "<<min<<" ";
        firstmin=min;
    values.erase(min);
  }
  for(int i=VaLoops-1;i>=0;i--){
    for(int j=0;j<ind[i];j++){
	if (min==loops[i][j].value){
	   min=loops[i][j].next->value;
	break;
	}
	}
    if(i==0){
         if(min==firstmin){
	 std::cout<<")";
	 min=0;
	 break;
	 }else{
       std::cout<<min<<" ";
	   values.erase(min);
       }
    }
  }
}
std::cout<<")\n";
 //конец

 for(int i=0;i<VaLoops;i++){
    delete[] loops[i];
  }
  delete[] loops;
  return 0;
}

int GetMinSet(std::set<int> &a){
  return *std::min_element(a.begin(), a.end());
}
