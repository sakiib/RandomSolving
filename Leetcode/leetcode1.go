func twoSum(nums []int, target int) []int {
    for i, x := range nums {
        for j, y := range nums {
            if i != j && x + y == target {
                return []int{i, j}
            }
        }
    }
    return []int{}
}
