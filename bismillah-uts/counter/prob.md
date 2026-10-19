# Counter Operations

## Description

Develop a program that processes the following operations:

- **`0 n`**: Create a new counter with an initial value *n*.
- **`1`**: Increment the counter by one.
- **`-1`**: Decrement the counter by one (the counter must never become negative).
- **`9`**: Display the current counter value.
- **`-9`**: End of input.

## Input Format

Multiple lines of commands, each containing one of the operations described above, ending with **`-9`**.

Each command may have one of the following formats:

```text
0 n
1
-1
9
-9
```

## Constraints

- The initial counter value *n* is ≥ 0.
- Operations adhere strictly to the specifications.
- The counter value must never become negative.

## Output Format

Output the result of each **`9`** command on a new line.

## Sample Input 0

```text
0 5
1
1
9
-1
9
0 0
-1
1
9
-9
```

## Sample Output 0

```text
7
6
1
```

## Explanation 0

The operations are processed sequentially:

1. **`0 5`**: Create a new counter with an initial value of 5.
2. **`1`**: Increment the counter to 6.
3. **`1`**: Increment the counter to 7.
4. **`9`**: Display the current counter value, `7`.
5. **`-1`**: Decrement the counter to 6.
6. **`9`**: Display the current counter value, `6`.
7. **`0 0`**: Create a new counter with an initial value of 0.
8. **`-1`**: The counter remains at 0 because it cannot become negative.
9. **`1`**: Increment the counter to 1.
10. **`9`**: Display the current counter value, `1`.
11. **`-9`**: End of input.

Therefore, the output is:

```text
7
6
1
```