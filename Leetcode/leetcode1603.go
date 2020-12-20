type ParkingSystem struct {
    Big int
    Medium int
    Small int
}


func Constructor(big int, medium int, small int) ParkingSystem {
    return ParkingSystem{big, medium, small}
}


func (this *ParkingSystem) AddCar(carType int) bool {
    if carType == 1 {
        if this.Big > 0 {
            this.Big --
            return true
        } else {
            return false;
        }
    } else if carType == 2 {
        if this.Medium > 0 {
            this.Medium --
            return true
        } else {
            return false;
        }
    } else {
        if this.Small > 0 {
            this.Small --
            return true
        } else {
            return false;
        }
    }
    return true
}


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
