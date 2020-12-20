func kthFactor(n int, k int) int {
    factors := make([]int, 0)
    for i := 1; i * i <= n; i++ {
        if n % i == 0 {
            factors = append(factors, i)
            if n / i != i {
                factors = append(factors, n / i)
            }
        }
    }
    sort.Ints(factors)
    if len(factors) < k {
        return -1
    }
    return factors[k - 1]
}
