func canPlaceFlowers(flowerbed []int, n int) bool {
    for i, val := range flowerbed {
        if n == 0 {
            return true
        }
        if val == 0 {
            if i - 1 >= 0 && flowerbed[i - 1] == 0 || i - 1 < 0 {
                if i + 1 < len(flowerbed) && flowerbed[i + 1] == 0 || i + 1 >= len(flowerbed) {
                    flowerbed[i] = 1
                    n --
                }
            }
        }
    }
    if n == 0 {
        return true
    }
    return false
}
