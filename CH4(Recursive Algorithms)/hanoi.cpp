#include <iostream>
using namespace std;
int cnt=1;
void hanoi(char from , char to , char help , int n){
    if(n==1){
        cout<< cnt++ <<' '<<from <<' '<< to<<endl;
        return;
    }

    hanoi (from , help , to , n-1);

    cout<< cnt++ <<' '<<from <<' '<< to<<endl;

    hanoi(help , to , from , n-1);
}
int main(){
    int n;
    cin>>n;
    hanoi('A' , 'B' , 'C', n);
    

}