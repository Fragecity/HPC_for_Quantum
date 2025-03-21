languages = ["C++(BLAS)", "Rust(ndarray)", "Python(numpy)", "Julia"]

x = [2**i for i in range(8, 13)]
runTimes = {
    "C++(BLAS)": [
        0.445872,  # N=256
        1.27933,  # N=512
        5.57074,  # N=1024
        38.1389,  # N=2048
        201.271,  # N=4096
    ],
    "Rust(ndarray)": [35.133137, 271.708976, 2142.342975, 17426.273183, 141277.545308],
    "Python(numpy)": [
        1.3468265533447266,
        6.800413131713867,
        8.34202766418457,
        37.16731071472168,
        151.26490592956543,
    ],
    "Julia": [0.0197116, 1.043, 4.551, 33.272, 217.693],
}

import matplotlib.pyplot as plt

# 创建对数坐标图
plt.figure(figsize=(10, 6))

# 为每种语言绘制折线
for language in languages:
    plt.loglog(x, runTimes[language], marker="o", label=language)

# 添加标题和标签
plt.title("Matrix multiplication benchmark")
plt.xlabel("Matrix size (N)")
plt.ylabel("Running time (ms)")
plt.grid(True, which="both", ls="-", alpha=0.2)
plt.legend()

# 调整布局并显示
plt.tight_layout()
plt.savefig("src/rawMatMulBenchmark/matmul_benchmark.png")
