// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

int main(){
    int nums[5] = {1,2,3,2,3};
    float result; 

    // Write your code here
    result = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4]) / 5.0f;
    
    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
