use ndarray::prelude::*;
use ndarray_linalg::Dot;
use rayon::prelude::*;
use std::time::Instant;

fn main() {
    const N: usize = 1024;

    // 初始化两个 1024x1024 的矩阵（填充 1.0 和 2.0）
    let a = Array2::from_elem((N, N), 1.0);
    let b = Array2::from_elem((N, N), 2.0);

    // 开始计时
    let start = Instant::now();

    // 并行矩阵乘法（利用 BLAS 加速）
    let result = a.dot(&b);

    // 结束计时
    let duration = start.elapsed();

    println!("Time elapsed: {:?}", duration);
}