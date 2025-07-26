#include <iostream>
using namespace std;
int main(){
    float num1,num2;
    int operation;
    cout<<"\n\nEnter the first number: "<<endl;
    cin>>num1;
    cout<<"Enter the second number: "<<endl;
    cin>>num2;
    cout<<"\nEnter the operation to perform \n1 -----> Addition\n2 -----> Substraction\n3 -----> Multiplication\n4 -----> Division\n\nEnter your choice: "<<endl;
    cin>>operation;
    switch (operation)
    {
    case 1:
        cout<<num1+num2<<endl;
        break;
    case 2:
        cout<<num1-num2<<endl;
        break;
    case 3:
        cout<<num1*num2<<endl;
        break;
    case 4:
        cout<<(float)(num1/num2)<<endl;
        break;
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
    return 0;
}
