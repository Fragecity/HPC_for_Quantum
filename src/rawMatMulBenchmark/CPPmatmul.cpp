#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cblas.h>
#include <cmath>

int main() {
    // 初始化随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    std::cout << "开始矩阵乘法基准测试（从N=2^8到2^12）..." << std::endl;
    
    // 对不同大小的矩阵进行基准测试
    for (int power = 8; power <= 12; power++) {
        const int N = std::pow(2, power);
        
        // 创建并初始化两个随机矩阵 (以行主序存储用于BLAS)
        std::cout << "矩阵大小: " << N << "x" << N << std::endl;
        std::vector<double> A(N * N);
        std::vector<double> B(N * N);
        std::vector<double> C(N * N, 0.0);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i*N + j] = dis(gen);
                B[i*N + j] = dis(gen);
            }
        }
        
        // 执行矩阵乘法并计时
        auto start = std::chrono::high_resolution_clock::now();
        
        // 使用BLAS的矩阵乘法 (dgemm)
        // C = alpha*A*B + beta*C，这里 alpha=1.0, beta=0.0
        const double alpha = 1.0;
        const double beta = 0.0;
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                    N, N, N, alpha, A.data(), N, B.data(), N, beta, C.data(), N);
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        
        std::cout << "N = 2^" << power << " (" << N << "x" << N << ") 计算时间: " << 
                  duration.count()*1000 << " 毫秒" << std::endl;
        
        // 仅对最小的矩阵输出部分结果以验证计算
        if (power == 8) {
            std::cout << "结果矩阵C的左上角4x4元素:" << std::endl;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    std::cout << C[i*N + j] << "\t";
                }
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}
