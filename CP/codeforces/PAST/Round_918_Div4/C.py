def isPerfectSquare(num):
    if num < 0:
        return False
    if num <= 1:
        return True

    left, right = 0, num

    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid
        if square == num:
            return True
        elif square < num:
            left = mid + 1
        else:
            right = mid - 1

    return False

def fVec(n):
    return list(map(int, input().split()))

def pVec(v):
    print(*v)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        a = fVec(n)
        _sum = sum(a)
        if isPerfectSquare(_sum):
            print("YES")
        else:
            print("NO")
