def solve(s, start, char):
    current = char

    for i in range(start, len(s), 2):

        if s[i] != '?' and s[i] != current:
            return 0

        if current == 'a':
            current = 'b'
        else:
            current = 'a'

    return 1


s = input()

even_1 = solve(s, 0, 'a')
even_2 = solve(s, 0, 'b')

even = even_1 + even_2

odd_1 = solve(s, 1, 'b')
odd_2 = solve(s, 1, 'a')

odd = odd_1 + odd_2

print(odd * even)