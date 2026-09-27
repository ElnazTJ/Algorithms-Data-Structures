s = input()

st = []
matches = []

for i in range(len(s)):
    if s[i] == '(':
        st.append(i + 1)
    else:
        if not st:
            print(-1)
            exit()

        open_index = st.pop()
        matches.append((open_index, i + 1))

if st:
    print(-1)
    exit()

for match in matches:
    print(match[0], match[1])