#include <iostream>
#include <complex>
#include <vector>

/**
 * 
 * Example of page 7 of the cerny2006 paper: (6), (7) and (8)
 * 
 */ 

using complex_vector = std::vector<std::complex<double>>;

complex_vector rev(complex_vector &a)
{
    const unsigned int n = a.size(); 
    if(n == 0) return a; 
    
    complex_vector rev(n); 
    rev[0] = a[0]; 
    for(int i = 1; i < n; ++i)
        rev[i] = a[n - i]; 

    return rev; 
}

void print_vector(complex_vector &a)
{
    const unsigned int n = a.size(); 
    for(int i = 0; i < n; ++i)
        std::cout << a[i] << std::endl; 
}

int main(int, char* [])
{
    const std::complex<double> i(0.0, 1.0);
    const unsigned int N = 5; 
    const int k = 1; 
    const double exponent = 2.0 * M_PI / N; 
    double sum_real = 0.0; 
    double sum_img = 0.0;  

    complex_vector a(N); 
    complex_vector b(N); 
    
    for(int j = 0; j < N; ++j)
    {   
        const auto base = std::pow(std::exp(i * exponent), k); // {z_n}^k
        const auto current = std::pow(base, j); // (7)
        sum_real += current.real(); 
        sum_img += current.imag(); 
        
        a[j] = current; 
        // std::cout << current << std::endl; 
    }

    for(int j = 0; j < N; ++j)
    {   
        const auto base = std::pow(std::exp(i * exponent), -k); // {z_n}^(-k)
        const auto current = std::pow(base, j); // (10)
        
        b[j] = current; 
        // std::cout << current << std::endl; 
    }

    std::cout << sum_real << std::endl;
    std::cout << sum_img << std::endl;

    std::cout << "=== Anticlockwise rotation ===" << std::endl; 
    print_vector(a); 
    std::cout << std::endl; 

    complex_vector rev_b = rev(b); 
    std::cout << "=== Equivalence (10) ===" << std::endl; 
    print_vector(rev_b); 
    std::cout << std::endl; 

    complex_vector rev_a = rev(a); 
    std::cout << "=== Clockwise rotation ===" << std::endl; 
    print_vector(rev_a); 
    std::cout << std::endl; 


    return 0; 
}