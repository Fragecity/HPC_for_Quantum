use ndarray::prelude::*;
use ndarray::linalg::Dot;
use std::time::Instant;

fn main() {
    println!("注意：请确保使用 cargo run --release 来运行此程序");
    
    // 测试从2^8到2^12的矩阵大小
    for i in 8..=12 {
        let n = 2usize.pow(i);
        
        println!("测试 N = {n} (2^{i}) 的矩阵乘法:");
        
        // 初始化两个 n×n 的矩阵（填充 1.0 和 2.0）
        let a = Array2::from_elem((n, n), 1.0);
        let b = Array2::from_elem((n, n), 2.0);
        
        // 预热运行（避免第一次运行的额外开销）
        if i == 8 {
            let _warmup = a.dot(&b);
        }

        // 开始计时
        let start = Instant::now();

        // 矩阵乘法（使用ndarray-linalg的BLAS后端）
        let _result = a.dot(&b);

        // 结束计时
        let duration = start.elapsed();

        println!("矩阵大小: {n}x{n}, 运行时间: {:?}\n", duration);
    }
}
