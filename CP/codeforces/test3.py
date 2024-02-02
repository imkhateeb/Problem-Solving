def int_to_binary(a):
    b = []
    while a != 0:
        bit = a % 2
        b.append(bit)
        a //= 2

    n = len(b)
    for i in range(n // 2):
        b[i], b[n - i - 1] = b[n - i - 1], b[i]

    return b

def get_power(k):
    ans = 1
    for _ in range(k):
        ans *= 2
    return ans

def main():
    t = int(input())
    for _ in range(t):
        a, b, r = map(int, input().split())
        arr = int_to_binary(a)
        brr = int_to_binary(b)

        p, q = len(arr), len(brr)

        if p > q:
            brr = [0] * (p - q) + brr
        elif q > p:
            arr = [0] * (q - p) + arr

        ans = 0

        n = len(arr)
        first1a = 0
        first1b = 0

        for i in range(n):
            if a > b and arr[i] == 1 and brr[i] == 0 and first1a == 1:
                power = get_power(n - i - 1)
                if r >= power + ans:
                    ans = power + ans
            elif a < b and arr[i] == 0 and brr[i] == 1 and first1b == 1:
                power = get_power(n - i - 1)
                if r >= power + ans:
                    ans = power + ans

            if arr[i] == 1:
                first1a = 1
            if brr[i] == 1:
                first1b = 1

        final = abs((a ^ ans) - (b ^ ans))
        print(final)

if __name__ == "__main__":
    main()
