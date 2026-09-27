q = int(input())

st = [""]

for _ in range(q):
    command = input().split()

    if command[0] == "insert":
        i = int(command[1])
        x = command[2]

        s = st[-1]
        s = s[:i-1] + x + s[i-1:]
        st.append(s)

    elif command[0] == "delete":
        i = int(command[1])

        s = st[-1]
        s = s[:i-1] + s[i:]
        st.append(s)

    elif command[0] == "undo":
        st.pop()

print(st[-1])