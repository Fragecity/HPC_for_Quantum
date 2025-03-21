using BenchmarkTools
As = [rand(2^i, 2^i) for i in 8:12]
Bs = [rand(2^i, 2^i) for i in 8:12]

@btime As[1] * Bs[1]
@btime As[2] * Bs[2]
@btime As[3] * Bs[3]
@btime As[4] * Bs[4]
@btime As[5] * Bs[5]
